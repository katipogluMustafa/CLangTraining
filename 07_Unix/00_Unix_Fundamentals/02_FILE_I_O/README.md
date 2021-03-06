# Unbuffered I/O

## FILE DESCRIPTORS

* To the kernel, all open files are referred to by file descriptors. 

* A file descriptor is a non-negative integer. 

* When we open an existing file or create a new file, the kernel returns a file descriptor to the process.

```c
#include<unistd.h>
STDIN_FILENO  	// 0
STDOUT_FILENO 	// 1
STDERR_FILENO   // 2
```

* File descriptors range from 0 through **OPEN_MAX**–1.

* With FreeBSD 8.0, Linux 3.2.0, Mac OS X 10.6.8, and Solaris 10, the limit is essentially infinite, bounded by the amount of memory on the system, the size of an integer, and any hard and soft limits configured by the system administrator.

## OPEN AND OPENAT FUNCTIONS

A file is opened or created by calling either the open function or the openat function.

```c
#include<fcntl.h>

int open(const char* path, int oflag, .../* mode_t mode */);
int openat(int fd, const char* path, int oflag, .../* mode_t mode */);

// Both return: file descriptor if OK, –1 on error
```

* We show the last argument as ..., which is the ISO C way to specify that the number and types of the remaining arguments may vary. 

* For these functions, the last argument is used only when a new file is being created

* The path parameter is the name of the file to open or create.

* This function has a multitude of options, which are specified by the oflag argument.

---

## oflag argument

* This argument is formed by ORing together one or more of the following constants from the `<fcntl.h>` header:

```c
#include<fcntl.h>

O_RDONLY   // Open for reading only. By Convention 0
O_WRONLY   // Open for writing only. By Convention 1
O_RDWR 	   // Open for reading and writing. By Convention 2
O_EXEC     // Open for execute only.
   
/* One and only one of the previous four constants must be specified.  */

```

### Optional oflag arguments

```c
#include<fcntl.h>

O_APPEND	// Append to the end of the file on each write
O_CLOEXEC 	// Set the FD_CLOEXEC file descriptor flag.

O_CREAT		// Create the file if it doesn’t exist. 
// O_CREAT requires a third argument to the open function (a fourth argument to the openat function) — the mode, which specifies the access permission bits of the new file.

O_DIRECTORY 	// Generate an error if path doesn't refer to a directory.

O_EXECL		// Generate an error if O_CREAT is also specified and the file already exists.
// P_EXECL test for whether the file already exists and the creation of the file if it doesn’t exist is an atomic operation.

O_NOCTTY	// If path refers to a terminal device, do not allocate the device as the controlling terminal for this process.
O_NOFOLLOW	// Generate an error if path refers to a symbolic link. 

O_NONBLOCK	// If path refers to a FIFO, a block special file, or a character special file, O_NONBLOCK option sets the nonblocking mode for both the opening of the file and subsequent I/O. 

O_SYNC		// Have each write wait for physical I/O to complete, including I/O necessary to update file attributes modified as a result of the write. 

O_TRUNC		// If the file exists and if it is successfully opened for either write-only or read–write, truncate its length to 0.

O_TTY_INIT	// When opening a terminal device that is not already open, set the nonstandard termios parameters to values that result in behavior that conforms to the SUS.

/* The following two flags are also optional. 
 * They are part of the synchronized input and output option of the SUS (and thus POSIX.1). 
 */

O_DSYNC		// Have each write wait for physical I/O to complete, but don’t wait for file attributes to be updated if they don’t affect the ability to read the data just written.

O_RSYNC 	// Have each read operation on the file descriptor wait until any pending writes for the same portion of the file are complete.
// Linux 3.2.0 supports the O_DSYNC flag, but treats the O_RSYNC flag the same as O_SYNC.

```

* The O_DSYNC and O_SYNC flags are similar, but subtly different. 
  * The O_DSYNC flag affects a file’s attributes only when they need to be updated to reflect a change in the file’s data (for example, update the file’s size to reflect more data). 
  * With the O_SYNC flag, data and attributes are always updated synchronously. 
  * When overwriting an existing part of a file opened with the O_DSYNC flag, the file times wouldn’t be updated synchronously. 
  * In contrast, if we had opened the file with the O_SYNC flag, every write to the file would update the file’s times before the write returns, regardless of whether we were writing over existing bytes or appending to the file.

---


* The file descriptor returned by open and openat is guaranteed to be the lowest-numbered unused descriptor.

* The fd parameter distinguishes the openat function from the open function. There are three possibilities:

1. The path parameter specifies an absolute pathname. 
  * In this case, the fd parameter is ignored and the openat function behaves like the open function.

2. The path parameter specifies a relative pathname and the fd parameter is a file descriptor that specifies the starting location in the file system where the relative pathname is to be evaluated.
  * The fd parameter is obtained by opening the directory where the relative pathname is to be evaluated.

3. The path parameter specifies a relative pathname and the fd parameter has the special value AT_FDCWD.
  * In this case, the pathname is evaluated starting in the current working directory and the openat function behaves like the open function.

---

The openat function is one of a class of functions added to the latest version of POSIX.1 to address two problems.

1. It gives threads a way to use relative pathnames to open files in directories other than the current working directory.

2. It provides a way to avoid time-of-check-to-time-of-use (TOCTTOU) errors.

* The basic idea behind **TOCTTOU** errors is that a program is vulnerable if it makes two file-based function calls where the second call depends on the results of the first call. Because the two calls are not atomic, the file can change between the two calls, thereby invalidating the results of the first call, leading to a program error. 

--- 

### Filename and Pathname Truncation

* With POSIX.1, the constant _POSIX_NO_TRUNC determines whether long filenames and long components of pathnames are truncated or an error is returned.
  * We can use **fpathconf** or **pathconf** to query a directory to see which behavior is supported.

If _POSIX_NO_TRUNC is in effect, errno is set to ENAMETOOLONG, and an error status is returned if any filename component of the pathname exceeds NAME_MAX.


* Most modern file systems support a maximum of 255 characters for filenames. 

## CREAT Function

A new file can also be created by calling the creat function.

```c
#include<fcntl.h>

int creat(const char* path, mode_t mode);

// Returns: file descriptor opened for write-only if OK, –1 on error
```

* This function equivalent to

```c
open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
```

* One deficiency with creat is that the file is opened only for writing.

* Before the new version of open was provided, if we were creating a temporary file that we wanted to write and then read back, we had to call creat, close, and then open. 

* A better way is to use the open function, as in

```c
open(path, O_RDRW | O_CREAT | O_TRUNC, mode);
```

## CLOSE Function

```c
#include<unistd.h>
int close(int fd);

// Returns 0 if OK, -1 on error
```

* Closing a file also releases any record locks that the process may have on the file.

* When a process terminates, all of its open files are closed automatically by the kernel. 
  * Many programs take advantage of this fact and don’t explicitly close open files.

## LSEEK Function

* Every open file has an associated “current file offset,” normally a non-negative integer that measures the number of bytes from the beginning of the file.

* Read and write operations normally start at the current file offset and cause the offset to be incremented by the number of bytes read or written. 

* By default, this offset is initialized to 0 when a file is opened, unless the O_APPEND option is specified.


```c
#include<unistd.h>

off_t lseek(int fd, off_t offset, int whence);

// Returns: new file offset if OK, -1 on error
```

* The interpretation of the offset depends on the value of the whence argument.
  * If whence is SEEK_SET, the file’s offset is set to offset bytes from the beginning of the file.
  * If whence is SEEK_CUR, the file’s offset is set to its current value plus the offset. The offset can be positive or negative.
  * If whence is SEEK_END, the file’s offset is set to the size of the file plus the offset. The offset can be positive or negative.

* Because a successful call to lseek returns the new file offset, we can seek zero bytes from the current position to determine the current offset:

```c
off_t currPosition;
currPosition = lseek(fd, 0, SEEK_CUR);
```

* This technique can also be used to determine if a file is capable of seeking. 
  * If the file descriptor refers to a **pipe**, **FIFO**, or **socket**, lseek sets errno to **ESPIPE** and returns –1.

* The character l in the name lseek means “long integer.”

* Normally, a file’s current offset must be a non-negative integer. 
  * It is possible, however, that certain devices could allow negative offsets. 
  * But for regular files, the offset must be non-negative. 
  * Because negative offsets are possible, we should be careful to compare the return value from lseek as being equal to or not equal to –1, rather than testing whether it is less than 0.

* Because the offset (off_t) is a signed data type we lose a factor of 2 in the maximum file size. 
  * If off_t is a 32-bit integer, the maximum file size is 2<sup>31</sup>–1 bytes.

* lseek only records the current file offset within the kernel—it does not cause any I/O to take place. This offset is then used by the next read or write operation.

* The file’s offset can be greater than the file’s current size, in which case the next write to the file will extend the file. 
  * This is referred to as **creating a hole in a file** and is allowed. 
  * Any bytes in a file that have not been written are read back as 0.

* A hole in a file isn’t required to have storage backing it on disk. 
  * Depending on the file system implementation, when you write after seeking past the end of a file, new disk blocks might be allocated to store the data, 
  * but there is no need to allocate disk blocks for the data between the old end of file and the location where you start writing.

```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";

int
main(void)
{
    int     fd;

    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("creat error");

    if (write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    /* offset now = 10 */

    if (lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");
    /* offset now = 16384 */

    if (write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    /* offset now = 16394 */

    exit(0);
}
```

![](img/2.png)

* We use the **od command** to look at the contents of the file. The -c flag tells it to print the contents as characters.

![](img/3.png)

* Although both files are the same size, the file without holes consumes 20 disk blocks, whereas the file with holes consumes only 8 blocks.


* Because the offset address that lseek uses is represented by an off_t, implementations are allowed to support whatever size is appropriate on their particular platform.
  * Most platforms today provide two sets of interfaces to manipulate file offsets: one set that uses 32-bit file offsets and another set that uses 64-bit file offsets.

* The SUS provides a way for applications to determine which environments are supported through the sysconf function. Image summarizes the sysconf constants that are defined.
  ![](img/1.jpg)

* Figure summarizes the size in bytes of the off_t data type for the platforms covered in this book when an application doesn’t define _FILE_OFFSET_BITS, as well as the size when an application defines _FILE_OFFSET_BITS to have a value of either 32 or 64.

![](img/3.jpg)

* Note that even though you might enable 64-bit file offsets, your ability to create a file larger than 2 GB (2<sup>31</sup>–1 bytes) depends on the underlying file system type.

## READ Function

Data is read from an open file with the read function.

```c
#include<unistd.h>

ssize_t read(int fd, void* buf, size_t nbytes);  // ssize_t = signed size_t

// Returns: number of bytes read, 0 if end of file, –1 on error
```

If the read is successful, the number of bytes read is returned. If the end of file is encountered, 0 is returned.


* There are several cases in which the number of bytes actually read is less than the amount requested:

  * When reading from a regular file, if the end of file is reached before the requested number of bytes has been read. 
    * For example, if 30 bytes remain until the end of file and we try to read 100 bytes, read returns 30. The next time we call read, it will return 0  

  * When reading from a terminal device. Normally, up to one line is read at a time.

  * When reading from a network. Buffering within the network may cause less than the requested amount to be returned.

  * When reading from a pipe or FIFO. If the pipe contains fewer bytes than requested, read will return only what is available.

  * When reading from a record-oriented device. Some record-oriented devices, such as magnetic tape, can return up to a single record at a time. 
  
  * When interrupted by a signal and a partial amount of data has already been read. 

* The read operation starts at the file’s current offset. 
  * Before a successful return, the offset is incremented by the number of bytes actually read. 

* POSIX.1 changed the prototype for this function in several ways. The classic definition is
  ```c
    int read(int fd, char* buf, unsigned nbytes);
  ```
  
  * First, the second argument was changed from char * to void * to be consistent with ISO C: the type void * is used for generic pointers.

  * Next, the return value was required to be a signed integer (ssize_t) to return a positive byte count, 0 (for end of file), or –1 (for an error).

  * Finally, the third argument historically has been an unsigned integer, to allow a 16-bit implementation to read or write up to 65,534 bytes at a time. 
    *  With the 1990 POSIX.1 standard, the primitive system data type **ssize_t** was introduced to provide the signed return value, and the unsigned size_t was used for the third argument.  


## WRITE Function

```c
#include<unistd.h>

ssize_t write(int fd, const void* buf, size_t nbytes);

// returns number of bytes if OK, -1 on error
```

* The return value is usually equal to the nbytes argument; otherwise, an error has occurred. 
  * A common cause for a write error is either filling up a disk or exceeding the file size limit for a given process

* For a regular file, the write operation starts at the file’s current offset. 
  * If the **O_APPEND** option was specified when the file was opened, the file’s offset is set to the current end of file before each write operation. 

* After a successful write, the file’s offset is incremented by the number of bytes actually written.



## I/O Efficiency 

* Copy standard input to standard output

```c
#include "apue.h"

#define BUFFSIZE    4096

int
main(void)
{
    int     n;
    char    buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if (n < 0)
        err_sys("read error");

    exit(0);
}
```

* The following caveats apply to this program.

*  It reads from standard input and writes to standard output, assuming that these have been set up by the shell before this program is executed. 
  * Indeed, all normal UNIX system shells provide a way to open a file for reading on standard input and to create (or rewrite) a file on standard output. 
  * This prevents the program from having to open the input and output files, and allows the user to take advantage of the shell’s I/O redirection facilities.

* The program doesn’t close the input file or output file. 
  * Instead, the program uses the feature of the UNIX kernel that closes all open file descriptors in a process when that process terminates.

* This example works for both text files and binary files, since there is no difference between the two to the UNIX kernel.

* One question we haven’t answered, however, is **how we chose the BUFFSIZE value**.
  
  * Timing results for reading with different buffer sizes on Linux
  
  ![](img/4.jpg)

* The file was read using the program shown in Figure, with standard output redirected to /dev/null. 
  * The file system used for this test was the Linux ext4 file system with 4,096-byte blocks ( The **st_blksize** value is 4,096.)
  * This accounts for the minimum in the system time occurring at the few timing measurements starting around a BUFFSIZE of 4,096. 
  * Increasing the buffer size beyond this limit has little positive effect.

> Beware when trying to measure the performance of programs that read and write files. The operating system will try to cache the file incore, so if you measure the performance of the program repeatedly, the successive timings will likely be better than the first. This improvement occurs because the first run causes the file to be entered into the system’s cache, and successive runs access the file from the system’s cache instead of from the disk. 

## FILE SHARING

* The UNIX System supports the sharing of open files among different processes.

* The kernel uses three data structures to represent an open file, and the relationships among them determine the effect one process has on another with regard to file sharing.

  * **Every process** has an entry in the process table. Within each process table entry is a table of open file descriptors, which we can think of as a vector, with one entry per descriptor. Associated with each file descriptor are

    * (a) The file descriptor flags
      
 	* Kernel data structures for open files
          
 	  ![Kernel data structures for open files](img/5.jpg) 
   
    * A pointer to a file table entry
  
  * The kernel maintains a file table for all open files. Each file table entry contains
  
    * a) The file status flags for the file, such as read, write, append, sync, and nonblocking

    * (b) The current file offset

    * (c) A pointer to the v-node table entry for the file

  * Each open file (or device) has a v-node structure that contains information about the type of file and pointers to functions that operate on the file. 
    
    * For most files, the v-node also contains the i-node for the file. 
    
    * This information is read from disk when the file is opened, so that all the pertinent information about the file is readily available. 
       
      * For example, the i-node contains the owner of the file, the size of the file, pointers to where the actual data blocks for the file are located on disk, and so on.
  * Linux has no v-node. 
    
    * Instead, a generic i-node structure is used. 
    
    * Although the implementations differ, the v-node is conceptually the same as a generic i-node. Both point to an i-node structure specific to the file system.

  * Instead of splitting the data structures into a v-node and an i-node, Linux uses a file system–independent i-node and a file system–dependent i-node.
  
  * Two independent processes with the same file open
  
    ![](img/6.jpg)
  * Given these data structures, we now need to be more specific about what happens with certain operations that we’ve already described.
    
    * After each write is complete, the current file offset in the file table entry is incremented by the number of bytes written. If this causes the current file offset to exceed the current file size, the current file size in the i-node table entry is set to the current file offset (for example, the file is extended).
    
    *  If a file is opened with the **O_APPEND** flag, a corresponding flag is set in the file status flags of the file table entry. Each time a write is performed for a file with this append flag set, the current file offset in the file table entry is first set to the current file size from the i-node table entry. This forces every write to be appended to the current end of file.
    
    * If a file is positioned to its current end of file using lseek, all that happens is the current file offset in the file table entry is set to the current file size from the i-node table entry. (Note that this is not the same as if the file was opened with the O_APPEND flag, as we will see...
    
    * The lseek function modifies only the current file offset in the file table entry. No I/O takes place.
    
    * It is possible for more than one file descriptor entry to point to the same file table entry(dup function).
        * This also happens after a fork when the parent and the child share the same file table entry for each open descriptor
    
    * Note the difference in scope between the file descriptor flags and the file status flags. The former apply only to a single descriptor in a single process, whereas the latter apply to all descriptors in any process that point to the given file table entry.

* Everything that we’ve described so far in this section works fine for **multiple processes** that are **reading the same file**. 
    * Each process has its own file table entry with its own current file offset. 
    * Unexpected results can arise, however, when **multiple processes write to the same file**. 
    * To see how to avoid some surprises, we need to understand the concept of **atomic operations**.    
    
## ATOMIC OPERATIONS    
   
* Assume that two independent processes, A and B, are appending to the same file. 
    * Each has opened the file but without the O_APPEND flag. 
    * Each process has its own file table entry, but they share a single v-node table entry. 
    * Assume that process A does the lseek and that this sets the current offset for the file for process A to byte offset 1,500 (the current end of file). 
    * Then the kernel switches processes, and B continues running. Process B then does the lseek, which sets the current offset for the file for process B to byte offset 1,500 also (the current end of file). 
    * Then B calls write, which increments B’s current file offset for the file to 1,600. 
    * Because the file’s size has been extended, the kernel also updates the current file size in the v-node to 1,600. 
    * Then the kernel switches processes and A resumes. When A calls write, the data is written starting at the current file offset for A, which is byte offset 1,500. 
    * **This overwrites the data that B wrote to the file.**

* The problem here is that our logical operation of “**position to the end of file and write**” requires two separate function calls     
    * The solution is to have the positioning to the current end of file and the write be an atomic operation with regard to other processes.

> <i>**Any operation that requires more than one function call cannot be atomic, as there is always the possibility that the kernel might temporarily suspend the process between the two function calls**</i>

* The UNIX System provides an atomic way to do this operation if we set the **O_APPEND** flag when a file is opened.
    * This causes the kernel to position the file to its current end of file **before each write**. 
    * We no longer have to call lseek before each write.

### pread and pwrite Functions

The Single UNIX Specification includes two functions that allow applications to seek and perform I/O atomically: pread and pwrite.

```c
#include<unistd.h>

ssize_t pread(int fd, void* buf, size_t nbytes, off_t offset);
// Returns: number of bytes read, 0 if end of file, –1 on error

ssize_t pwrite(int fd, const void* buf, size_t nbytes, off_t offset);
// Returns: number of bytes written if OK, –1 on error
```

* Calling pread is equivalent to calling lseek followed by a call to read, with the following exceptions.
    
    * There is no way to interrupt the two operations that occur when we call pread.
    
    * The current file offset is not updated.

* Calling pwrite is equivalent to calling lseek followed by a call to write, with similar exceptions.


### Creating a File

* We saw another example of an atomic operation when we described the **O_CREAT** and **O_EXCL** options for the open function. 
    * When both of these options are specified, the open will fail if the file already exists. 
    * We also said that the check for the existence of the file and the creation of the file was performed as an atomic operation. 
    * If we didn’t have this atomic operation, we might try

```c
if ((fd = open(path, O_WRONLY)) < 0) {
    if (errno == ENOENT) {
        if ((fd = creat(path, mode)) < 0)
            err_sys("creat error");
    } else {
        err_sys("open error");
    }
}
```

* The problem occurs if the file is created by another process between the open and the creat. 
    * If the file is created by another process between these two function calls, and if that other process writes something to the file, that data is erased when this creat is executed. 
    * Combining the test for existence and the creation into a single atomic operation avoids this problem.

> <i>In general, the term atomic operation refers to an operation that might be composed of multiple steps. </i>

* If the operation is performed atomically, either all the steps are performed (on success) or none are performed (on failure). 
    * It must not be possible for only a subset of the steps to be performed. 
    * We’ll return to the topic of atomic operations when we describe the link function and record locking
    * See unit 04 and 14.
    
## DUP AND DUP2 FUNCTIONS

An existing file descriptor is duplicated by either of the following functions:

```c
#include<unistd.h>

int dup(int fd);

int dup2(int fd, int fd2);              
int dup2(int fd_Dest, int fd_Source);       // same but easy to remmeber, assembly style

// Both return: new file descriptor if OK, –1 on error
```

* The new file descriptor returned by dup is guaranteed to be the lowest-numbered available file descriptor.

* With dup2, we specify the value of the new descriptor with the fd2 argument. 
    * If fd2 is already open, it is first closed. 
    * If fd equals fd2, then dup2 returns fd2 without closing it. 
    * Otherwise, the **FD_CLOEXEC** file descriptor flag is cleared for fd2, so that fd2 is left open if the process calls exec.

---

```c
newfd = dup(1);
```

![](img/7.jpg)
* The new file descriptor that is returned as the value of the functions shares the same file table entry as the fd argument.
*  Because both descriptors point to the same file table entry, they share the same file status flags—read, write, append, and so on—and the same current file offset.

---

* Each descriptor has its own set of file descriptor flags. 
    * The close-on-exec file descriptor flag for the new descriptor is always cleared by the dup functions.(see fcntl section)

* Another way to duplicate a descriptor is with the fcntl function

```c
// Indeed, the call
dup(fd);

//is equivalent to
fcntl(fd, F_DUPFD, 0);

// Similarly, the call
dup2(fd, fd2);

// is equivalent to
close(fd2);
fcntl(fd, F_DUPFD,fd2);
```    

* In this last case, the dup2 is not exactly the same as a close followed by an fcntl. The differences are as follows:

1. dup2 is an atomic operation, whereas the alternate form involves two function calls. 
    
    * It is possible in the latter case to have a signal catcher called between the close and the fcntl that could modify the file descriptors.
    * The same problem could occur if a different thread changes the file descriptors.
    
2. There are some errno differences between dup2 and fcntl.

    * POSIX.1 requires both dup2 and the F_DUPFD feature of fcntl.
    
## SYNC, FSYNC, AND FDATASYNC FUNCTIONS

* Traditional implementations of the UNIX System have a buffer cache or page cache in the kernel through which most disk I/O passes.
    * When we write data to a file, the data is normally copied by the kernel into one of its buffers and queued for writing to disk at some later time. 
    * This is called **delayed write**.

* The kernel eventually writes all the delayed-write blocks to disk, normally when it needs to reuse the buffer for some other disk block. 
    * **To ensure consistency** of the file system on disk with the contents of the buffer cache, the sync, fsync, and fdatasync functions are provided.

```c
#include<unistd.h>

int fsync(int fd);
int fdatasync(int fd);

// Returns: 0 if OK, –1 on error

void sync(void);
```

* The sync function simply queues all the modified block buffers for writing and returns; it does not wait for the disk writes to take place.

* The function sync is normally called periodically (usually every 30 seconds) from a system daemon, often called update. 
    * This guarantees regular flushing of the kernel’s block buffers. 

* The command sync also calls the sync function.

* The function fsync refers only to a single file, specified by the file descriptor fd, and **waits for the disk writes to complete** before returning. 
    * This function is used when an application, such as a database, needs to be sure that the modified blocks have been written to the disk.

* The fdatasync function is similar to fsync, but it affects only the data portions of a file. With fsync, the file’s attributes are also updated synchronously.

## FCNTL FUNCTION

The fcntl function can change the properties of a file that is already open.

```c
#include<fcntl.h>

int fcntl(int fd, int cmd,  .../* int arg*/);

// Returns: depends on cmd if OK (see following), –1 on error
```
    
* The fcntl function is used for five different purposes.

1. Duplicate an existing descriptor (cmd = F_DUPFD or F_DUPFD_CLOEXEC)
2. Get/set file descriptor flags (cmd = F_GETFD or F_SETFD)
3. Get/set file status flags (cmd = F_GETFL or F_SETFL) 
4. Get/set asynchronous I/O ownership (cmd = F_GETOWN or F_SETOWN)
5. Get/set record locks (cmd = F_GETLK, F_SETLK, or F_SETLKW)

---

--> F_DUPFD

 * Duplicate the file descriptor fd. 
 * The new file descriptor is returned as the value of the function. 
 * It is the lowest-numbered descriptor that is not already open, and that is greater than or equal to the third argument (taken as an integer).The new descriptor shares the same file table entry as fd.
 *  But the new descriptor has its own set of file descriptor flags, and its FD_CLOEXEC(close on exec) file descriptor flag is cleared.
 

--> F_DUPFD_CLOEXEC

 * Duplicate the file descriptor and set the FD_CLOEXEC file descriptor flag associated with the new descriptor. 
 * Returns the new file descriptor.
 

-->  F_GETFD
 * Return the file descriptor flags for fd as the value of the function.
    * Currently, only one file descriptor flag is defined: the FD_CLOEXEC flag.

--> F_SETFD
* Set the file descriptor flags for fd. The new flag value is set from the third argument (taken as an integer).
* Be aware that some existing programs that deal with the file descriptor flags don’t use the constant FD_CLOEXEC. 
    * Instead, these programs set the flag to either 0 (don’t close-on-exec, the default) or 1 (do close-on-exec). 

--> F_GETFL
* Return the file status flags for fd as the value of the function.

* File status flags for fcntl
    
    ![](img/8.jpg)

* Unfortunately, the five access-mode flags—O_RDONLY, O_WRONLY, O_RDWR, O_EXEC, and O_SEARCH—are not separate bits that can be tested. 
    * We must first use the O_ACCMODE mask to obtain the access-mode bits and then compare the result against any of the five values.

--> F_SETFL
* Set the file status flags to the value of the third argument (taken as an integer). 
* The only flags that can be changed are 
    * O_APPEND 
    * O_NONBLOCK 
    * O_SYNC
    * O_DSYNC 
    * O_RSYNC 
    * O_FSYNC 
    * O_ASYNC

--> F_GETOWN
* Get the process ID or process group ID currently receiving the SIGIO and SIGURG signals.

--> F_SETOWN
* Set the process ID or process group ID to receive the SIGIO and SIGURG signals. 
* A positive arg specifies a process ID. A negative arg implies a process group ID equal to the absolute value of arg.

---


* The return value from fcntl depends on the command.
    * All commands return **–1 on an error** or **some other value if OK**.

* The following four commands have special return values: 
    * F_DUPFD, returns the new file descriptor
    * F_GETFD, F_GETFL return the corresponding flags
    * F_GETOWN returns a positive process ID or a negative process group ID.

* When we modify either the file descriptor flags or the file status flags, we must be careful to fetch the existing flag value, modify it as desired, and then set the new flag value. 
    * We can’t simply issue an F_SETFD or an F_SETFL command, as this could turn off flag bits that were previously set.

```c
/* Turn on one or more of the file status flags for a descriptor */

#include "apue.h"
#include <fcntl.h>

void
set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
    int     val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");

    val |= flags;       /* turn on flags */

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}
```

* If we change the middle statement to
```c
val &= ~flags;  /* turn flags off */
```
---

```c
set_fl(STDOUT_FILENO, O_SYNC);  // This causes each write to wait for the data to be written to disk before returning. 
```

* We expect the O_SYNC flag to increase the system and clock times when the program runs. 
    
    * Linux ext4 timing results using various synchronization mechanisms
        * The six rows in Figure were all measured with a BUFFSIZE of 4,096 bytes.
        
        ![Linux ext4 timing results using various synchronization mechanisms](img/9.jpg)

* The results in Figure 3.6 were measured while reading a disk file and writing to /dev/null, so there was no disk output. 
    * The second row in Figure 3.13 corresponds to reading a disk file and writing to another disk file. 
    * When we enable synchronous writes, the system and clock times should increase significantly. 
        * As the third row shows, the system time for writing synchronously is not much more expensive than when we used delayed writes. 
        * This implies that the Linux operating system is doing the same amount of work for delayed and synchronous writes (which is unlikely), or else the O_SYNC flag isn’t having the desired effect. 
        * In this case, the Linux operating system isn’t allowing us to set the O_SYNC flag using fcntl, instead failing without returning an error (but it would have honored the flag if we were able to specify it when the file was opened).
    * The clock time in the last three rows reflects the extra time needed to wait for all of the writes to be committed to disk. 
        * After writing a file synchronously, we expect that a call to fsync will have no effect. 
        * This case is supposed to be represented by the last row in Figure 3.13, but since the O_SYNC flag isn’t having the intended effect, the last row behaves the same way as the fifth row.

* With this example, we see the need for fcntl. 
    * Our program operates on a descriptor (standard output), never knowing the name of the file that was opened on that descriptor. 
    * We can’t set the **O_SYNC** flag when the file is opened, since the shell opened the file. 
    * With fcntl, we can modify the properties of a descriptor, knowing only the descriptor for the open file.
 
## IOCTL FUNCTION

```c
#include<sys/ioctl.h>

int ioctl(int fd, int request, ...);

// Returns: –1 on error, something else if OK
```

* In this prototype, we show only the headers required for the function itself. 
    * Normally, additional device-specific headers are required. 
    * For example, the ioctl commands for terminal I/O, beyond the basic operations specified by POSIX.1, all require the <termios.h> header.

* Each device driver can define its own set of ioctl commands. 
    * The system, however, provides generic ioctl commands for different classes of devices. 

* Common FreeBSD ioctl operations
    
    ![](img/10.jpg)
    
* The mag tape operations allow us to write end-of-file marks on a tape, rewind a tape, space forward over a specified number of files or records, and the like. 
* e. None of these operations is easily expressed in terms of the other functions in the chapter (read, write, lseek, and so on), so the easiest way to handle these devices has always been to access their operations using ioctl.

* We use the ioctl function in Section 18 to fetch and set the size of a terminal’s window, and in Section 19 when we access the advanced features of pseudo terminals.

## /dev/fd

Newer systems provide a directory named /dev/fd whose entries are files named0, 1,2, and so on.Opening the file /dev/fd/n is equivalent to duplicating descriptor n, assuming that descriptor n is open.

```c
fd = open("/dev/fd/0", mode); // most systems ignore the specified mode, whereas others require that it be a subset of the mode used when the referenced file (standard input, in this case) was originally opened. 
// is equivalent to
fd = dup(0); 
```

* Because the previous open is equivalent to `fd = dup(0)` the descriptors 0 and fd share the same file table entry.
* For example, if descriptor 0 was opened read-only, we can only read on fd. Even if the system ignores the open mode and the call succeeds, we still can’t write to fd.
    ```c
    fd = open("/dev/fd/0", O_RDWR);
    ```

* The Linux implementation of /dev/fd is an exception. 
    * It maps file descriptors into symbolic links pointing to the underlying physical files. 
    * When you open /dev/fd/0, for example, you are really opening the file associated with your standard input. 
    * Thus the mode of the new file descriptor returned is unrelated to the mode of the /dev/fd file descriptor.

* We can also call creat with a /dev/fd pathname argument as well as specify O_CREAT in a call to open. This allows a program that calls creat to still work if the pathname argument is /dev/fd/1, for example.
    * Beware of doing this on Linux. 
    * Because the Linux implementation uses symbolic links to the real files, using creat on a /dev/fd file will result in the underlying file being truncated.
    
* Some systems provide the pathnames /dev/stdin, /dev/stdout, and /dev/stderr. These pathnames are equivalent to /dev/fd/0, /dev/fd/1, and /dev/fd/2, respectively.

* The main use of the /dev/fd files is from the shell. It allows programs that use pathname arguments to handle standard input and standard output in the same manner as other pathnames. 
    ```bash
    filter file2 | cat file1 - file3 | lpr
    ```
    * First, cat reads file1, then its standard input (the output of the filter program on file2), and then file3. If /dev/fd is supported, the special handling of - can be removed from cat, and we can enter
    
    ```bash
    filter file2 | cat file1 /dev/fd/0 file3 | lpr
    ```
    * The special meaning of - as a command-line argument to refer to the standard input or the standard output is a kludge that has crept into many programs. 
    * There are also problems if we specify - as the first file, as it looks like the start of another command-line option. 
    * Using /dev/fd is a step toward uniformity and cleanliness.