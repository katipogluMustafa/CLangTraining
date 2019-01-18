# Compiling more than one file

![](img/1.png)

### Compile all the source files
![](img/2.png)

### Then Link Them Together
![](img/3.png)

### If you can one of the files
![](img/4.png)

## Makefile

Every file that make compiles is called a target.Strictly speaking, make isn’t limited to compiling files. A target is any file that is generated from some other files. So a target might be a zip archive  that is generated from the set of files that need to be compressed.

![](img/5.png)

Together, the dependencies and the recipe form a rule. A rule tells
make all it needs to know to create the target file.

### Makefile Example 1
![](img/6.png)

![](img/7.png)

![](img/8.png)

![](img/9.png)

### Makefile Example 2

![](img/10.png)

![](img/11.png)