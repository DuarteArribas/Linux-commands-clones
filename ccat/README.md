# ccat

**ccat** is a clone of the popular linux program _cat_.
* **Language**:
  * English
* **Latest version**: 1.7.0

## How to execute?

* Compile:

  * Debug:
  ```
  make dbg
  ```
  * Release:
  ```
  make rls
  ```
* Execute:
```
ccat [__OPTIONS__] [__FILE__...]
```
---
The program can be executed by giving it one or more *files* (which will be concatenated), which will be displayed to the **standard output** If no, file is given, or the `-` option is provided, the program will read input from the **standard input** instead of from a file, outputting the contents to the **standard output** too.

It's based on the [Unix cat](https://man7.org/linux/man-pages/man1/cat.1.html "cat man page") program available on unix based systems, with some slight differences.
### Options
```
NAME DESC
---------
-A   equivalent to -ET
-b   print numbers before lines, but not on empty lines. Cannot be used when the `-n` option is being used.
-E   print a $ at the end of every line.
-n   print numbers before every line. Cannot be used when the `-b` option is being used.
-T   display tab characters as ^I
-h   show the help guide
-v   show the version of the software
```