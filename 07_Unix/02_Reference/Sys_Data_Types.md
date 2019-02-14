# SYSTEM DATA TYPES

## off_t
    
* Used for file sizes and offset
* long int

```c
 off_t           st_size;    /* size in bytes, for regular files */
```

## blkcnt_t

* %d

```c
  blkcnt_t        st_blocks;  /* number of disk blocks allocated */
```

## nlink_t 

* long unsigned int

```c
  nlink_t         st_nlink;   /* number of links */
```

## ino_t

* long unsigned int 

```c
 ino_t           st_ino;     /* i-node number (serial number) */
```
