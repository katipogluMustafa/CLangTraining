# Creating Small Tools


* Tools that read data line by line, process
it, and write it out again are called
**filters**.

```bash
echo $?  # this outputs the return of the program
```
* redirect gps_device.data into stdin and redirect the output of the program to output.json
```bash
./JSON < gps_device.data > output.json
./JSON < err_gps_device.data > output.json 2> errorBoard.txt  # you can output the error into another file by using 2>
```

#### Normally, when program runs
![](img/1.png)
#### When we redirect
![](img/2.png)

![](img/3.png)

![](img/bullet.png)
---

![](img/4.png)

![](img/5.png)

![](img/6.png)

![](img/7.png)

![](img/8.png)

![](img/9.png)

![](img/10.png)

![](img/11.png)

![](img/12.png)

![](img/13.png)

![](img/14.png)

![](img/15.png)

![](img/16.png)
