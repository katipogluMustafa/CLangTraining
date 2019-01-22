# Problems of this program

* The problem of this program is that when we call exec function from main process, it'll be replaced by the rssgossip.py and never return back to call other exec functions inside the loop.
* So we need  a way to copy the main process and make main process continue while child process is being replaced by rssgossip.py
* For this version, see V2
