set term qt noraise;
set xlabel 'Frequency';
set ylabel 'Amplitude (Real)';
set xrange [0:25000];
#set yrange [0:3500];
plot "< tail -n1000 ../cmake-build-debug/data.dat";
#pause 1;
#reread;

#set pm3d map;




#set cblabel 'Energy';


#splot "../cmake-build-debug/data.dat" ;
pause 0.25;
reread;