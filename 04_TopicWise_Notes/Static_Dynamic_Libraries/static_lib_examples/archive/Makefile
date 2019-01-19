archiveMaking/encrypt.o:  archiveMaking/encrypt.c
	gcc -c archiveMaking/encrypt.c -o  archiveMaking/encrypt.o
archiveMaking/checksum.o: archiveMaking/checksum.c 	
	gcc -c archiveMaking/checksum.c -o  archiveMaking/checksum.o
libhfsecurity.a: archiveMaking/encrypt.o archiveMaking/checksum.o
	ar -rcs archiveMaking/libhfsecurity.a archiveMaking/encrypt.o archiveMaking/checksum.o
main: main.c libhfsecurity.a
	gcc main.c -L archiveMaking -lhfsecurity -o main
