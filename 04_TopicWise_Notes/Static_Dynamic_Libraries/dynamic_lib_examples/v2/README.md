# After Compilation

* You'll need to add /libs to your linker's path.
	
	```bash
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/libs
	```
	
	* Be careful the pwd is inside backquotes

* Check whether it is added or not
	
	```bash
		echo $LD_LIBRARY_PATH
	```
