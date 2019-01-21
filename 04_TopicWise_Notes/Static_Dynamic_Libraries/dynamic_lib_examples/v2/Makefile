hfcal.o:
	gcc -fPIC -c hfcal.c -o hfcal.o
elliptical.o:
	gcc -I ./includes -c elliptical.c -o elliptical.o
libhfcal.so: hfcal.o
	gcc -shared hfcal.o -o ./libs/libhfcal.so
elliptical: libhfcal.so elliptical.o
	gcc elliptical.o -L ./libs -lhfcal -o elliptical
