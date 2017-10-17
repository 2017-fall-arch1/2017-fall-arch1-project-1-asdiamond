# Aleksandr Diamond Personnel Management System

This directory contains:
* code that implements a Binary Search Tree of Nodes containing Strings


This directory contains the following files:
 bst.h: header file of bst operations
 bst.c: implementation of bst
 bstdemo.c: a demonstration program that uses the bst for a personnel management system
 bstdemo.h: contains function declarations for the demo, and one that is used elsewhere in the program
 

To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ ./bstdemo.exe
~~~

To delete binaries and .bst files:
~~~
$ make clean
~~~

# Things to figure do #

1. Add employees
  - add as many as you like, as long as their name isnt over 100 characters long
  - enter a q to quit adding
  - be sure to pretty print the btree when you have finished adding employees
2. Pretty print the bst
  - right children are towards the top, and left children towards the bottom
3. Remove some employees
  - Sometimes people just dont work out, enter the employees name to remove them from the bst
  - be sure to print out the bst so you can see how it changes when someone is removed
4. Serialize the bst to a file
  - specify a filename (preferably with the .bst extension so you can clean it later. But any extension will do)
  - the bst is then serialized to a file.
  - Don't believe me? stop the program and tell it to read the bst from that file
5. Read a bst from a file
  - specify a file name and watch as its contents are magically assembled into a bst
  - be sure to print the bst before and after the reading
  - reading a bst from a file doesnt delete your current bst, it adds the contents of the file into it

Notes
  - There are some functions implemented in the bst that are not used. This is because they weren't specified to be used in the program,     I implemented them anyways. 
  - I did not implement and equivalent to lldocheck, this is because it would be more difficult to implement for a bst, and in my opinion not as useful. I debugged using my pprint functions, as well as some assertions (these arent there, I removed them).

