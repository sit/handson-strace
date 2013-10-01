# A Brief Hands-On with a few System Debugging Tools

## Introduction

This hands-on explores how to observe the behavior of programs on
a Linux system using:

* strace - trace system calls
* ltrace - trace library calls
* gdb - your friend, the debugger

What are system calls? System calls are requests made by a program to the
underlying operating system, or kernel. The role of the operating system is to
mediate access to hardware and facilitate sharing of hardware between user
programs; hence all input-output interactions (such as network, file, screen),
go through the kernel and require a system call. `strace` lets us observe
this interaction.

What are library calls? Programs often use code and functionality provided by
other developers. These are often provided by (shared) libraries, or `.so`
files, which are dynamically brought into a program's address space by a
dynamic linker.  The Windows analogue would be a DLL; both are similar in
spirit to a Java class-loader loading a class from a `.jar` file at runtime.
The `ltrace` command allows us to observe what calls are made to those libraries,
including the core "C" library.

A debugger of course allows you to step through the execution of a program
directly. At its most basic, it lets you observe the call stack and step
through program execution. More advanced usage allows you to inspect memory
(both the heap and the stack), deal with threads, etc. We will use just
the simple capabilities here.

In order to make effective use of these tools, you must learn what
system/library calls are common and what they do. You must understand
something about program execution. And then you must eventually learn
how to filter out the noise and map this down to the relevant parts
of your own code. This can be made complex by modern high-level languages
such as Python and Java that have interpreters, virtual machines,
and lots of libraries.

Today, you will build up some basic understanding of these tools by doing
some hands-on exercises.

## Exercises

### strace/ltrace

Compare the outputs of strace and ltrace.

    ls -l
    ls filedoesnotexist

For example:

    strace ls -l
    ltrace ls -l

You don't need to understand everything, just try to get a rough handle
on what is happening as it relates to what you see.

Consider the following questions as you try to understand the output:

* What library call(s) allocate memory? What system call(s)?
* What calls deal with I/O? What do their return values mean?
* What calls deal with the filesystem? What do their return values mean?
* How do system calls denote errors?

Consider using the `-o` flag to `strace` to manage its output.
You can also run `man foo` for almost any `foo` that appears at the start
of `strace` or `ltrace` output to find out more about how to use
the function.

Next run the following two commands, one in a separate terminal/shell:

    python -m SimpleHTTPServer
    curl -I http://localhost:8000/

You may use `-p` to attach to a running process or run the process
directly under `strace`. (You may need to use `sudo` to attach to
a running process.)

* What new library/system calls do Python and curl use?
* How is this similar to the `ls` command? How is it different?

### Exploring strace/ltrace flags

Play with the following strace/ltrace flags:

    -f
    -t -tt -ttt
    -T
    -e
    -c

How do you just trace file I/O? How do you see the full contents of buffers?

### Playing with gdb
 
Run the SimpleHTTPServer from the example above. Find its process id (using `ps`)
and then run:

    sudo gdb python
    attach $pid
    bt

This will give you a backtrace of the current stack. It will be a little bit 
abbreviated but it may give you an idea of what is going on. You may also
examine commands like `continue`, `finish`, `step` and `next`. Gdb has
basic `help` functionality built-in.

### Puzzles

At this point, you should be ready to solve some problems.

Checkout an appropriate branch with binaries, such as `ubuntu-x86_64`.

    git checkout ubuntu-x86_64

You should now have a few more binaries in the directory.

Each of these programs appears to hang without doing anything at the console.
(`ex0` and `ex1` behave deterministically, `ex2` may sometimes exit.) Run
each one.

What is each program doing when it appears to hang?

How can you make `./ex0` exit with status 0?

How can you make `./ex1` exit with status 0?

What does `./ex2` do?

## Further reading

These commands allow you to get a sense of what any process on the system is doing.
Some additional reading:

* [Self Service Linux](http://www.informit.com/store/self-service-linux-mastering-the-art-of-problem-determination-9780131477513), by Mark Wilding and Dan Behman. (Free [PDF download](http://ptgmedia.pearsoncmg.com/images/013147751X/downloads/013147751X_book.pdf), 4.4MB): This is a must read book.
* A quick blog post on [How does strace work?](http://blog.nelhage.com/2010/08/write-yourself-an-strace-in-70-lines-of-code/)
* The insides of a Unix kernel: [The Design and Implementation of the 4.4BSD Operating System](http://www.freebsd.org/doc/en/books/design-44bsd/). A classic.
* [Operating Systems Engineering](http://pdos.csail.mit.edu/6.828/2012/reference.html) course at MIT. The ultimate in-depth hands-on exploration.

If doing this in a group setting, take the time to do a brief wrap-up with your colleagues
and reflect on the experience.
