# Function Prototypes

```c
#include <sys/stat.h>

int stat(const char *restrict pathname, struct stat *restrict buf);

int fstat(int fd, struct stat *buf );

int lstat(const char *restrict pathname, struct stat *restrict buf);

int fstatat(int fd, const char *restrict pathname, struct stat *restrict buf, int flag);

// All four return: 0 if OK, –1 on error
```

```c
#include <unistd.h>

int access(const char *pathname, int mode);

int faccessat(int fd, const char *pathname, int mode, int flag);

// Both return: 0 if OK, –1 on error
```

```c
#include <sys/stat.h>

mode_t umask(mode_t cmask);

// Returns: previous file mode creation mask
```

```c
#include <sys/stat.h>

int chmod(const char *pathname, mode_t mode);

int fchmod(int fd, mode_t mode);

int fchmodat(int fd, const char *pathname, mode_t mode, int flag);

// All three return: 0 if OK, –1 on error
```

```c
#include <unistd.h>

int chown(const char *pathname, uid_t owner, gid_t group);

int fchown(int fd, uid_t owner, gid_t group);

int fchownat(int fd, const char *pathname, uid_t owner, gid_t group, int flag);

int lchown(const char *pathname, uid_t owner, gid_t group);

// All four return: 0 if OK, –1 on error
```

```c
#include <unistd.h>

int truncate(const char *pathname, off_t length);

int ftruncate(int fd, off_t length);

//Both return: 0 if OK, –1 on error
```

```c
#include <unistd.h>

int link(const char *existingpath, const char *newpath);

int linkat(int efd, const char *existingpath, int nfd, const char *newpath, int flag);

// Both return: 0 if OK, –1 on error
```

```c
#include <unistd.h>

int unlink(const char *pathname);

int unlinkat(int fd, const char *pathname, int flag);

// Both return: 0 if OK, –1 on error
```

```c
#include <stdio.h>

int remove(const char *pathname);

// Returns: 0 if OK, –1 on error
```

```c
#include <stdio.h>

int rename(const char *oldname, const char *newname);

int renameat(int oldfd, const char *oldname, int newfd, const char *newname);
           
// Both return: 0 if OK, –1 on error           
```

```c
#include <unistd.h>

int symlink(const char *actualpath, const char *sympath);

int symlinkat(const char *actualpath, int fd, const char *sympath);

// Both return: 0 if OK, –1 on error

```

```c
#include <unistd.h>

ssize_t readlink(const char* restrict pathname, char *restrict buf, size_t bufsize);
ssize_t readlinkat(int fd, const char* restrict pathname, char *restrict buf, size_t bufsize);

// Both return: number of bytes read if OK, –1 on error
```

```c
#include <sys/stat.h>

int futimens(int fd, const struct timespec times[2]);

int utimensat(int fd, const char *path, const struct timespec times[2],
              int flag);
              
// Both return: 0 if OK, –1 on error              
```

```c
#include <sys/time.h>

int utimes(const char *pathname, const struct timeval times[2]);

// Returns: 0 if OK, –1 on error
```

```c
#include <sys/stat.h>

int mkdir(const char *pathname, mode_t mode);
int mkdirat(int fd, const char *pathname, mode_t mode);

// Both return: 0 if OK, –1 on error
```

```c
#include <unistd.h>

int rmdir(const char *pathname);

// Returns: 0 if OK, –1 on error
```

```c
#include <dirent.h>

DIR *opendir(const char *pathname);
DIR *fdopendir(int fd);
// Both return: pointer if OK, NULL on error

struct dirent *readdir(DIR *dp);
// Returns: pointer if OK, NULL at end of directory or error

void rewinddir(DIR *dp);
int closedir(DIR *dp);
// Returns: 0 if OK, –1 on error

long telldir(DIR *dp);
// Returns: current location in directory associated with dp

void seekdir(DIR *dp, long loc);
```

```c
#include <unistd.h>

int chdir(const char *pathname);
int fchdir(int fd);

// Both return: 0 if OK, –1 on error
```

```c
#include <unistd.h>

char *getcwd(char *buf, size_t size);
// Returns: buf if OK, NULL on error
```