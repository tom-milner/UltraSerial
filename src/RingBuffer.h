//
// Created by Tom Milner on 22/05/2020.
//

#ifndef ULTRASERIAL_RINGBUFFER_H
#define ULTRASERIAL_RINGBUFFER_H

#include <iostream>
#include <cstdlib>
#include <cstring>

template<typename T>
class RingBuffer {
public:
    explicit RingBuffer(int size);

    ~RingBuffer();

    int read(T *data);

    int put(T data);

private:
    T *bufferPointer;
    unsigned int readIndex;
    unsigned int writeIndex;
    int bufferSize;
    int itemCount;
};


// Create the ring buffer.
template<typename T>
RingBuffer<T>::RingBuffer(int size) {
    bufferSize = size;
    itemCount = readIndex = writeIndex = 0;
    bufferPointer = (T *) malloc(sizeof(T) * size);
}

template<typename T>
RingBuffer<T>::~RingBuffer() {
    free(bufferPointer);
}

/// This could be done more efficiently not keeping a count!
template<typename T>
int RingBuffer<T>::read(T *data) {
    if (itemCount == 0) return 0;
    *data = bufferPointer[readIndex];
    readIndex = (readIndex + 1) % bufferSize; /// Performance can be increased by using an unsigned int as the read index the same size as the ring buffer - it will then overflow or underflow and 'wrap around' without having to use %.
    itemCount--;
    return 1;
}

template<typename T>
int RingBuffer<T>::put(T data) {
    if (itemCount == bufferSize) return 0;
    bufferPointer[writeIndex] = data;
    writeIndex = (writeIndex + 1) % bufferSize;
    itemCount++;
    return 1;
}

#endif //ULTRASERIAL_RINGBUFFER_H
