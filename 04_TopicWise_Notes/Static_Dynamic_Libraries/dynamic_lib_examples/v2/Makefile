obj/hfcal.o: libs/hfcal.c
	gcc -fPIC -c libs/hfcal.c -o obj/hfcal.o
libhfcal.so: obj/hfcal.o
	gcc -shared obj/hfcal.o -o /libs/libhfcal.so
elliptical.o: elliptical.c
	gcc -I includes -c elliptical.c -o obj/elliptical.o 
elliptical: elliptical.o libhfcal.so
	gcc elliptical.o -L libs -lhfcal -o elliptical
