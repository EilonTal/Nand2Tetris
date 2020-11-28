@256
D = A
@SP
M = D
@retAddress0
D = A
@SP
AM = M + 1
A = A - 1
M = D
@LCL
D = M
@SP
AM = M + 1
A = A - 1
M = D
@ARG
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THIS
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THAT
D = M
@SP
AM = M + 1
A = A - 1
M = D
@5
D = A
@SP
D = M - D
@0
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Sys.init
0;JMP
(retAddress0)
(Main.fibonacci)
@0
D = A
@NOLOCALS2
D;JEQ
@var0
M = D
(LOOP1)
@SP
AM = M + 1
A = A - 1
M = 0
@var0
MD = M - 1
@LOOP1
D;JGT
(NOLOCALS2)
@ARG
D = M
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@2
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label3
D;JLT
@SP
A = M - 1
M = 0
@Label4
0;JMP
(Label3)
@SP
A = M - 1
M = -1
(Label4)
@SP
AM = M - 1
D = M
@IF_TRUE
D;JNE
@IF_FALSE
0;JMP
(IF_TRUE)
@ARG
D = M
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@LCL
D = M
@endFrame5
M = D
@5
D = A
@endFrame5
A = M - D
D = M
@retAddress6
M = D
@SP
AM = M - 1
D = M
@ARG
A = M
M = D
@ARG
D = M + 1
@SP
M = D
@endFrame5
A = M - 1
D = M
@THAT
M = D
@endFrame5
A = M - 1
A = A - 1
D = M
@THIS
M = D
@endFrame5
A = M - 1
A = A - 1
A = A - 1
D = M
@ARG
M = D
@4
D = A
@endFrame5
A = M - D
D = M
@LCL
M = D
@retAddress6
A = M
0;JMP
(IF_FALSE)
@ARG
D = M
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@2
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = D - M
M = -M
@retAddress7
D = A
@SP
AM = M + 1
A = A - 1
M = D
@LCL
D = M
@SP
AM = M + 1
A = A - 1
M = D
@ARG
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THIS
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THAT
D = M
@SP
AM = M + 1
A = A - 1
M = D
@5
D = A
@SP
D = M - D
@1
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Main.fibonacci
0;JMP
(retAddress7)
@ARG
D = M
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@1
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = D - M
M = -M
@retAddress8
D = A
@SP
AM = M + 1
A = A - 1
M = D
@LCL
D = M
@SP
AM = M + 1
A = A - 1
M = D
@ARG
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THIS
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THAT
D = M
@SP
AM = M + 1
A = A - 1
M = D
@5
D = A
@SP
D = M - D
@1
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Main.fibonacci
0;JMP
(retAddress8)
@SP
AM = M - 1
D = M
A = A - 1
M = D + M
@LCL
D = M
@endFrame9
M = D
@5
D = A
@endFrame9
A = M - D
D = M
@retAddress10
M = D
@SP
AM = M - 1
D = M
@ARG
A = M
M = D
@ARG
D = M + 1
@SP
M = D
@endFrame9
A = M - 1
D = M
@THAT
M = D
@endFrame9
A = M - 1
A = A - 1
D = M
@THIS
M = D
@endFrame9
A = M - 1
A = A - 1
A = A - 1
D = M
@ARG
M = D
@4
D = A
@endFrame9
A = M - D
D = M
@LCL
M = D
@retAddress10
A = M
0;JMP
(Sys.init)
@0
D = A
@NOLOCALS13
D;JEQ
@var11
M = D
(LOOP12)
@SP
AM = M + 1
A = A - 1
M = 0
@var11
MD = M - 1
@LOOP12
D;JGT
(NOLOCALS13)
@4
D = A
@SP
M = M + 1
A = M - 1
M = D
@retAddress14
D = A
@SP
AM = M + 1
A = A - 1
M = D
@LCL
D = M
@SP
AM = M + 1
A = A - 1
M = D
@ARG
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THIS
D = M
@SP
AM = M + 1
A = A - 1
M = D
@THAT
D = M
@SP
AM = M + 1
A = A - 1
M = D
@5
D = A
@SP
D = M - D
@1
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Main.fibonacci
0;JMP
(retAddress14)
(WHILE)
@WHILE
0;JMP
