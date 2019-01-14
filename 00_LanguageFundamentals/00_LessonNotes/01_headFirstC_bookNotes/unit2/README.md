# Pointers

* A variable declared inside a
function is usually stored in the
stack .

* A variable declared outside a
function is stored in globals .

![](img/memoryInC.png)

```c

int doses[] = {1, 3, 2, 1000};

printf("Issue dose %i", 3[doses]); // returns 1000

// doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]
```

![](img/be_careful.png)

![](img/use_fgets_to_take_string.png)
![](img/use_fgets_to_take_string2.png)
![](img/use_fgets_to_take_string3.png)

![](img/pointerDecay.png)
![](img/bulletPoints.png)
![](img/bulletPoints2.png)
![](img/bullet3.png)
![](img/bullet4.png)
![](img/keyPoints.png)
