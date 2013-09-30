# A Brief Hands-On with a few System Debugging Tools

What tools today?

* strace - trace system calls
* ltrace - trace library calls
* gdb - your friend, the debugger

How to understand their output?

* Need to know what the calls mean and how they map to code execution.
     * What are (Linux) system and library calls?
     * What are their inputs and return values?
     * How does this map to your favorite language?

# Exercises

## strace/ltrace of common utilities

For each of the following, compare the outputs of strace and ltrace.

    ls -l
    ls filedoesnotexist

    python -m SimpleHTTPServer
        curl -I http://localhost:8000/

For example:

* What library call(s)s allocate memory? What system call(s)?
* What calls deal with I/O? What do their return values mean?
* How do they denote errors?

## Exploring strace/ltrace flags

Play with the following strace/ltrace flags:

    -p
    -o
    -f
    -t -tt -ttt
    -T
    -e
    -c

How do you just trace file I/O? How do you see the full contents of buffers?

## Puzzles

Checkout an appropriate branch with binaries. (Do not look at the source branch!)

How can you make `./ex0` exit with status 0? Why does this work?

How can you make `./ex1` exit with status 0? Why does this work?

What does `./ex2` do?

## Mapping code to system calls

Write some simple Python code and see how it maps to library calls.

What does `hfab ec2.provision:name=$USER-test,nodes=2,instance_type=t1.micro,os=centos` do?
Use `strace` to find out.

## Miscellaneous wrap-up questions

Read the comments for INFRA-53. Do you understand the debugging notes? What questions do you have?

Can you think of a problem you have had to debug where you could apply these techniques?
