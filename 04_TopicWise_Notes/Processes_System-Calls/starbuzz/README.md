# Be Careful!
  
```c
execl("./coffee","./coffee", "donuts", NULL);
```

* fonksiyonunda ilk parametre ile program açılır, NULL'dan önceki parametreler programa arguman olarak gönderilir, NULL gönderilmez NULL'i görünce gönderme işlemi durur.
