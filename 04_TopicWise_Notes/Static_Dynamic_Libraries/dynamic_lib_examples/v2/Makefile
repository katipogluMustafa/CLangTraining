hfcal.o:
	gcc -fPIC -c source/hfcal.c -o bin/hfcal.o
elliptical.o:
	gcc -I ./includes -c source/elliptical.c -o bin/elliptical.o
libhfcal.so: hfcal.o
	gcc -shared bin/hfcal.o -o ./libs/libhfcal.so
elliptical: libhfcal.so elliptical.o
	gcc bin/elliptical.o -L ./libs -lhfcal -o elliptical
