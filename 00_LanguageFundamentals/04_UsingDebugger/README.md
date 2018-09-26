
# Using Debugger

* Debugger is the thing that let you set break points and look at values , variables...

* When debugger crashes it stops and give you backtraces and tell you where things blew up

* on OSX **lldb** or on linux **GDB** is a shell. 
	* lldb and GDB are shell for running your programs under debuggers.
	* Debugger observes your program's executing and let you make stops and do things.  
	* lldb and GDB has different set of commands.


## GDB	

```bash
	
	$ CFLAGS="-Wall -g" make exc4 # by giving -g parameter we say compile with debugging symbols.

	$ gdb ./exc4 # open debugging tool for exc4

	(gdb) run 	 # start the exc4
	(dgb) bt  	 # see back trace

	(gdb) break main # Make a break point so that it breaks before main starts.
	(gdb) run # run again, as you can see breaks when reach main
	# as you can see from the output of run command, you see the debugger what line on the code.
	# -g parameter that we gave when we compile exc4 gives the ability to show what line the debugger is on.
	(gdb) list
	(gdb) step # run the following line
```

### GDB TRICKS
Here’s a list of simple tricks you can do with GNU Debugger (GDB):

* gdb --args Normally, gdb takes arguments you give it and assumes they are for itself. Using --args passes them to the program.

* thread apply all bt Dump a backtrace for all threads. It’s very useful.

* gdb --batch --ex r --ex bt --ex q --args Run the program so that if it bombs, you get a backtrace.

### GDB QUICK REFERENCE


* **run [args]** Start your program with [args].


* **break [file:]function** Set a break point at [file:]function. You can also use b.


* **backtrace** Dump a backtrace of the current calling stack. Shorthand is bt.


* **print expr** Print the value of expr. Shorthand is p.


* **continue** Continue running the program. Shorthand is c.


* **next** Next line, but step over function calls. Shorthand is n.


* **step** Next line, but step into function calls. Shorthand is s.


* **quit** Exit GDB.


* **help** List the types of commands. You can then get help on the class of command as well as the command.

* **cd**, **pwd**, make This is just like running these commands in your shell.


* **shell** Quickly start a shell so you can do other things.


* **clear** Clear a breakpoint.


* **info break**, **info watch** Show information about breakpoints and watchpoints.


* **attach pid** Attach to a running process so you can debug it.


* **detach** Detach from the process.

* **list** List out the next ten source lines. Add a - to list the previous ten lines.


## LLDB

### LLDB QUICK REFERENCE


In OS X, you no longer have GDB and instead must use a similar program called LLDB Debugger (LLDB). The commands are almost the same, but here’s a quick reference for LLDB:


* **run [args]** Start your program with [args].


* **breakpoint set - -name [file:]function** Set a break point at [file:]function. You can also use b, which is way easier.


* **thread backtrace** Dump a backtrace of the current calling stack. Shorthand is bt.


* **print expr** Print the value of expr. Shorthand is p.


* **continue** Continue running the program. Shorthand is c.


* **next** Next line, but step over function calls. Shorthand is n.


* **step** Next line, but step into function calls. Shorthand is s.


* **quit** Exit LLDB.


* **help** List the types of commands. You can then get help on the class of command as well as the command itself.


* **cd**, **pwd**, make just like running these commands in your shell.


* **shell** Quickly start a shell so you can do other things.


* **clear** Clear a breakpoint.


* **info break**, **info watch** Show information about breakpoints and watchpoints.


* **attach -p pid** Attach to a running process so you can debug it.

* **detach** Detach from the process.

* **list** List out the next ten source lines. Add a - to list the previous ten sources.