# Line Directive

`# It tells the compiler where the following line actually came from. It's usually only the C preprocessor that adds these, for example, when including a file, it tells the compiler (which is basically only seeing one stream of data) that we're looking at a different file.

This may sound strange, but the preprocessor simply inserts the header files where you specify your includes, and the compiler works on the whole thing (all header files concatenated along with your source code), you can check the result of the preprocessor stage if using gcc with gcc -E myfile.c. In there you'll notice it adds a #line directive whenever you include files, and also whenever it reduces the amount of text fed to the compiler (such as large amounts of comments may be reduced to a single #line directive, skipping ahead)

It is also used by other programs, such as bison/yacc to tell you that the problem (if there's a compile problem) is related to your rules-file at a specific line, which the compiler would otherwise be unable to do, as the bison/yacc generates c-files.

[Kaynak](https://stackoverflow.com/questions/2216540/whats-the-meaning-of-line-in-c-language)


