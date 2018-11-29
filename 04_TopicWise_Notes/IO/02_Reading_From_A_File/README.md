# Reading From A File

* Remember always have to open the file before we perform file operations on it unless the operation is deleting or renaming.)

![](img/1.png)

![](img/2.png)

```c
int mchar = fgetc(pfile);   // Reads a character into mchar with pfile a File pointer.
```

![](img/3.png)

![](img/4.png)
```c
rewind(pfile);
```
