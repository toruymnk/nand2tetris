// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

    @SCREEN  // R0 holds the terminal address of the screen
    D=A
    @8192
    D=D+A
    @R0
    M=D
(LOOP)
    @KBD
    D=M
    @FILL
    D;JGT
    @CLEAR
    0;JMP
(FILL)
    @SCREEN
    D=A
(FILL_LOOP)
    A=D
    M=-1
    @R1  // R1 points to the next address
    M=D+1
    D=M
    @R0
    D=M-D
    @LOOP
    D;JLE
    @R1
    D=M
    @FILL_LOOP
    0;JMP
(CLEAR)
    @SCREEN
    D=A
(CLEAR_LOOP)
    A=D
    M=0
    @R1  // R1 points to the next address
    M=D+1
    D=M
    @R0
    D=M-D
    @LOOP
    D;JLE
    @R1
    D=M
    @CLEAR_LOOP
    0;JMP
