#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>


/* int stat(const char *restrict pathname, struct stat *restrict buf); */
// Return : on error -1, if OK 0



int main(int argc, char* argv[]){
    
    if(argc != 2){
        fprintf(stderr, "You need to give one parameter to the program\n");
        return 1;
    }
    struct stat fileStat;
    if(stat(argv[1], &fileStat) < 0){
        fprintf(stderr,"can not get stats...\n");
        return 1;
    }
    
    printf("Information for %s\n", argv[1]);
    printf("--------------------\n");    
    printf("File Size: \t\t%li bytes\n", fileStat.st_size);
    printf("Number of Links: \t%lu\n",   fileStat.st_nlink);
    printf("File ino: \t\t %lu\n",       fileStat.st_ino);
    
    printf("File Permissions: \t");
    printf( ( S_ISDIR(fileStat.st_mode ) ) ? "d" : "-"  );
    printf( ( fileStat.st_mode & S_IRUSR ) ? "r" : "-"  );
    printf( ( fileStat.st_mode & S_IWUSR ) ? "w" : "-"  );
    printf( ( fileStat.st_mode & S_IXUSR ) ? "x" : "-"  );
    printf( ( fileStat.st_mode & S_IRGRP ) ? "r" : "-"  );
    printf( ( fileStat.st_mode & S_IWGRP ) ? "w" : "-"  );
    printf( ( fileStat.st_mode & S_IXGRP ) ? "x" : "-"  );
    printf( ( fileStat.st_mode & S_IROTH ) ? "r" : "-"  );
    printf( ( fileStat.st_mode & S_IWOTH ) ? "w" : "-"  );
    printf( ( fileStat.st_mode & S_IXOTH ) ? "x" : "-"  );
    printf("\n\n");

    printf("The file %s a symbolic link \n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not" );
    printf("The File %s a character special file\n", (S_ISCHR(fileStat.st_mode)) ? "is" : "is not"  );
    printf("The File %s a block special file\n", (S_ISBLK(fileStat.st_mode))  ? "is" : "is not"  );
    printf("The File %s a reguler file\n", (S_ISREG(fileStat.st_mode))  ? "is" : "is not"  );
    printf("The File %s a FIFO special file\n", (S_ISFIFO(fileStat.st_mode))  ? "is" : "is not"  );
    printf("The File %s a Socket special file\n", (S_ISSOCK(fileStat.st_mode))  ? "is" : "is not"  );
   
return 0;
}

    

