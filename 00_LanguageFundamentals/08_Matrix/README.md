# Matrix in C


## Passing Matrix into a function

### If the matrix is dynamic
```c
void ins(int **matrix, int row, int col);
```

### If the matrix is static

```
void ins (int matrix[][100], int row, int column);
// or
void ins(int (*matrix)[100], int row, int col);
// or
void ins(int (*matrix)[SIZE], int row, int col);
// or
void ins (int matrix[SIZE][SIZE], int row, int column);

```