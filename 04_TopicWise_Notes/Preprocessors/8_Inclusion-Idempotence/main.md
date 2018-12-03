# Inclusion And Idempotence

* Any text file can be included using `#include`

* Included file may have one or more include directives.

* Include file are normal way of making sure that programs shares the same definitions.

* When a header file is changed the header files that are included must be recompiled. 

---

```c
#include "filename"
```

* Search for 'filename' start where the source file found.
	* If it is not in the same directory as the others, seach continues in one or more implementation defined directories.

---

```c
#include <filename>

```

* Search for `filename` does not start at the place where the source file found but rather starts searching in the implementation defined directories.

---

* You can use defined names in include directive.

```c

#define MAX "max.h"
#include MAX

```

---

* You can not name the file two or more consequtive strings.
	* Concatenation comes to late for that.

```c
#include "st" "orm.h" // Error
```

* You should avoid using these characters when naming include directive.
	* Includeing Any one of these characters undefined.
		* `"`
		* `'`
		* `>`
		* `\`
		* `//`
		* `/*`

---

* You can use conditional macro to include some file.

```c
#ifdef NEED_LIMITS
#include <limits.h>
#endif
```

---

* C standard header files can be included in any order and you can include any standard header, any number of times without any effect after the first time it is included.
	* This is known as Idempotence

```c
#include<stdio.h>
#include<stdio.h>		// no error
```

* You'll need to use conditional to provide idemtence feature to non-standard include directives.
```c
#include"test.h"

#define MYTEST "test.h"

#ifndef MYTEST
#include "test.h"	
#endif

```