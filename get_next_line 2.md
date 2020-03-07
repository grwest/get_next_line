# get_next_line

## Reading a line on a fd is way too tedious

### Summary: The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

# Introduction

> You are now starting to understand that it will get tricky to read data from a file descriptor if you don’t know its size beforehand. What size should your buffer be? How many times do you need to read the file descriptor to retrieve the data? It is perfectly normal and natural that, as a programmer, you would want to read a “line” that ends with a line break from a file descriptor. For example each command that you type in your shell or each line read from a flat file. Thanks to the project get_next_line, you will finally be able to write a function that will allow you to read a line ending with a newline character from a file descriptor. You’ll be able to add this function to your libft if you feel like it and most importantly, use it in all the future projects that will require it.

# Goals

> This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables. You will also gain a deeper understanding of allocations, whether they happen on the stack memory or in the heap memory, the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables. Your respect of the Norm will improve the rigor of your programming. We also suspect that your approach to coding will change when you will discover that the initial state of a variable in a function can vary depending on the call of that very function.

# General Instructions

- [ ]  You must only submit two files : get_next_line.c and get_next_line.h
- [ ]  If you are clever, you will use your libft. If so, submit your folder libft at the root
of your repository
- [ ]  There cannot be a main function in your program.
- [ ]  Do not push a Makefile.
- [ ]  Your project must be written in accordance with the Norm.
- [ ]  You have to handle errors carefully. In no way can your program, or in this particular case your function, quit in an unexpected manner (Segmentation fault, bus
error, double free, etc).
- [ ]  All heap allocated memory space must be properly freed when necessary
- [ ]  Your project cannot have memory leaks
- [ ]  You must submit a file called author containing your username followed by a ’\n’
at the root of your repository:
`$>cat -e author
xlogin$`
- [ ]  If you choose to submit this project using your library libft, it is strictly FORBIDDEN
to bypass the limitation of the Norm by adding some specific functions from your
get_next_line. That would be considered cheating during your defence. Your
get_next_line must hold in 5 functions of 25 lines max. The respect of this
instruction will be carefully checked during your defence. There is no need for you
ask permission to the staff to add a function to your library. Use your head instead
and ask yourself if your function respects this instruction. If you do everything right,
you will of course be encouraged to expand your library with generic functions.
You’ll discover their usage as you complete this project.
- [ ]  The libc functions allowed on this project are read, malloc and free.

# Mandatory part

- Write a function that returns a line read from a file descriptor.
- What we call a “line” is a succession of characters that end with ’\n’ (ascii code
0x0a) or with End Of File (EOF).

[https://latedev.wordpress.com/2012/12/04/all-about-eof/](https://latedev.wordpress.com/2012/12/04/all-about-eof/) : 
that article can prove useful for someone who can read.

- Your function must be prototyped as follows:

    int get_next_line(const int fd, char **line);

- The first parameter is the file descriptor that will be used to read.
- The second parameter is the address of a pointer to a character that will be used
to save the line read from the file descriptor.