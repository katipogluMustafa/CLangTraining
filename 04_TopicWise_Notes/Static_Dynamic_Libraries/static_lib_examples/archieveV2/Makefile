obj/encrypt.o:  libhfsecurity/encrypt.c
	gcc -c libhfsecurity/encrypt.c -o  obj/encrypt.o
obj/checksum.o: libhfsecurity/checksum.c 	
	gcc -c libhfsecurity/checksum.c -o  obj/checksum.o
libhfsecurity.a: obj/encrypt.o obj/checksum.o
	ar -rcs libhfsecurity/libhfsecurity.a obj/encrypt.o obj/checksum.o
main: main.c libhfsecurity.a
	gcc main.c -I ./include/ -L ./libhfsecurity/ -lhfsecurity -o main
