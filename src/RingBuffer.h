//
// Created by Tom Milner on 22/05/2020.
//

#ifndef ULTRASERIAL_RINGBUFFER_H
#define ULTRASERIAL_RINGBUFFER_H

#include <iostream>

template<typename T>
class RingBuffer {
public:
    explicit RingBuffer(int size);

    ~RingBuffer();

    int read(T *data);

    int put(T data);

    int getItemCount();

private:
    T *bufferPointer;
    unsigned int readIndex;
    unsigned int writeIndex;
    int bufferSize;
    int itemCount;
};


#include <cstdlib>
#include <cstring>

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

template<typename T>
int RingBuffer<T>::read(T *data) {
    if (itemCount == 0) return 1;
    *data = bufferPointer[readIndex];
    readIndex = (readIndex + 1) % bufferSize;
    itemCount--;
    return 0;
}

template<typename T>
int RingBuffer<T>::put(T data) {
    if (itemCount == bufferSize) return 1;
    bufferPointer[writeIndex] = data;
    writeIndex = (writeIndex + 1) % bufferSize;
    itemCount++;
    return 0;
}

template<typename T>
int RingBuffer<T>::getItemCount() {
    return itemCount;
}


#endif //ULTRASERIAL_RINGBUFFER_H
