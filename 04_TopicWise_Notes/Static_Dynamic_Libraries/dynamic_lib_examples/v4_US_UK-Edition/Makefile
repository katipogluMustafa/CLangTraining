# Shared

elliptical.o:
	gcc -I ./includes -c elliptical.c -o bin/elliptical.o

# US  Editon APP's Make	

hfcal.o:
	gcc -fPIC -c hfcal.c -o bin/hfcal.o
libhfcal.so: hfcal.o
	gcc -shared bin/hfcal.o -o ./libs/libhfcal.so
elliptical: libhfcal.so elliptical.o
	gcc bin/elliptical.o -L ./libs -lhfcal -o elliptical

# UK Edition APP's Make

hfcal_UK.o:
	gcc -fPIC -c hfcal_UK.c -o bin/hfcal.o
libhfcal_UK.so: hfcal_UK.o
	gcc -shared bin/hfcal.o -o ./libs/libhfcal.so
elliptical_UK: libhfcal_UK.so elliptical.o
	gcc bin/elliptical.o -L ./libs -lhfcal -o elliptical


