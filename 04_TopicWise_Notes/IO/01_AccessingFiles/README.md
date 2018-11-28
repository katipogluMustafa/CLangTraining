# Accessing Files

![](img/1.png)


![](img/2.png)

## File Modes

![](img/3.png)

### Write mode

```c
FILE *pfile = NULL;
char* filename = "myfile.txt";

pfile = fopen(filename, "w"); 
if(pfile != NULL){
    printf("Failed to open %s\n", filename);
}

```

![](img/4.png)

### Append Mode

![](img/5.png)

### Read Mode

![](img/6.png)

## Renaming a file

Here you don't have to use file pointer because you don't actually want the file open.

![](img/7.png)

```c
#include<stdio.h>

int main(){

if( rename("test.deneme", "test.c") ){

    printf("Failed to rename the file");

}else{

    printf("File named successfully");
}


return 0;
}
```

## Closing a file

![](img/8.png)

```c
fclose(pfile);
pfile = NULL;
```

![](img/9.png)

* You must also close a file before attempting to rename it or remove it.

## Deleting A File

Here you don't have to use file pointer because you don't actually want the file open.

![](img/10.png)