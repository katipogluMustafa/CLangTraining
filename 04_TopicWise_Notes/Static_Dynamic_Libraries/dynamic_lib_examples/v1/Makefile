obj/hfcal.o: libs/hfcal.c
	gcc -c libs/hfcal.c -o obj/hfcal.o
libhfcal.a: obj/hfcal.o
	ar -rcs libs/libhfcal.a obj/hfcal.o
elliptical: elliptical.c libhfcal.a
	gcc elliptical.c -I includes -L libs -lhfcal -o elliptical
