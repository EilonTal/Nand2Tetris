// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

// 0 if one of them is zero
@R2
M = 0
@R0
D = M
@END
D;JEQ
@R1
D = M
@END
D;JEQ

// init res as R0
@R0
D = M
@res
M = D 

// init n as R1-1
@R1
D = M
@n
M = D-1

@MULTIPLY_LOOP
D-1;JGT // if n > 0 start adding
@PUT_RES_TO_R2
D-1;JEQ

(MULTIPLY_LOOP)
    @R0
    D = M
    @res
    M = D + M
    @n
    M = M - 1
    D = M
    @MULTIPLY_LOOP
    D;JGT // while n > 0 keep adding

(PUT_RES_TO_R2)
    @res
    D = M
    @R2
    M = D

@END
0;JMP

(END)
    @END
    0; JMP
