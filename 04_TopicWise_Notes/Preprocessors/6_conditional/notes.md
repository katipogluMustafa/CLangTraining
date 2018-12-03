# Conditional Inclusion

* If the result of the expression is non-zero it is true and code is included 
* If the expression is result zero it is considered false, and everything to the endif is omitted
---

* In the expression you can't use variables, sizeof operator, emums, and you can't use casting.
  * But you can use addition, subtraction, modulus, division, and, or , and any of the boolean operators.
  * You can also use previously defined macros as long as they are defined as constant values.

* You can check whether a macro has been defined. See examples for details...

```c

#define defined LIMIT

```
