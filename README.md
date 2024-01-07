# USF COP 4600 Operating Systems: Project 4 Description

This project contains four different programs based on various UNIX utilities. These utilities include: <br>
1. mystat-kamryn.c - stat() system call on a given file or directory. Prints out file size, number of blocks allocated, reference count, file permissions, and file inode.
2. myls-kamryn.c - Lists files in the given directory. Prints out information of each file (permissions, group, owner, and information frmo stat() call).
3. mytail-kamryn.c - Prints out last few lines of a file.
4. mysearch-kamryn.c - Prints out names of each file and directory in file system tree, starting at a given point in the tree.

### How to run

Run make, to compile all the files.
This includes:<br>
<sup>
all: mysearch mytail myls mystat<br>	
<br>
mysearch: mysearch-kamryn.c<br>
	gcc	-o	mysearch	mysearch-kamryn.c<br><br>
mytail:	mytail-kamryn.c<br>
	gcc	-o	mytail	mytail-kamryn.c<br><br>
myls:	myls-kamryn.c<br>
	gcc	-o	myls	myls-kamryn.c<br><br>
mystat:	mystat-kamryn.c<br>
	gcc	-o	mystat	mystat-kamryn.c</sup>
