# Function Pointers

![](img/1.png)

### Func Pointer Example from Standard Library
* The qsort() function compares pairs of values over and over again, and if they are in the wrong order, the computer will switch them.
  ![](img/qsort.jpg)

### Comparator Function
![](img/comparator.jpg)

### SORTING INTS UP CLOSE

```c
int scores[] = {543,323,32,554,11,3,112};

int compare_scores(const void* score_a, const void* score_b)

{
  
...

}

```

* Values are always passed to the function as pointers, so the first thing you need to do is get the integer values from the pointers:
  ![](img/1.jpg)
  
* Then you need to return a positive, negative, or zero value, depending on whether a is greater than, less than, or equal to b.
  ![](img/2.jpg)
  
* And this is how you ask qsort() to sort the array:
```c
qsort(scores, 7, sizeof(int), compare_scores);
```