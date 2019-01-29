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



```

