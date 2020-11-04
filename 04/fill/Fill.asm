// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
(MAIN) // called after finished coloring screen, or uncoloring it
    @KBD
    D = M
    @COLOR_SCREEN
    D;JNE
    @UNCOLOR_SCREEN
    D;JEQ

(WHILE_KEYBOARD_UNTOUCHED)
    @KBD
    D = M
    @WHILE_KEYBOARD_UNTOUCHED
    D; JEQ
    @MAIN
    0; JMP

(WHILE_KEYBOARD_TOUCHED)
    @KBD
    D = M
    @WHILE_KEYBOARD_TOUCHED
    D;JNE
    @MAIN
    0; JMP


(COLOR_SCREEN)
    @8192
    D = A
    @i
    M = D
    @SCREEN
    D = A
    @previous_adr
    M = D
    (LOOP_SCREEN_COLOR) // color screen
        @previous_adr
        D = M 
        @adr
        A = D
        M = -1
        @previous_adr
        M = M + 1
        @i
        M = M - 1
        D = M
        @LOOP_SCREEN_COLOR
        D;JGT
    @WHILE_KEYBOARD_TOUCHED
    0; JMP

(UNCOLOR_SCREEN)
    @8192
    D = A
    @i
    M = D
    @SCREEN
    D = A
    @previous_adr
    M = D
    (LOOP_SCREEN_UNCOLOR) // uncolor screen
        @previous_adr
        D = M 
        @adr
        A = D
        M = 0
        @previous_adr
        M = M + 1
        @i
        M = M - 1
        D = M
        @LOOP_SCREEN_UNCOLOR
        D;JGT
    @WHILE_KEYBOARD_UNTOUCHED
    0; JMP