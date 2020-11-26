(Main.fibonacci)
@0
D = A
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
@Label2
D;JLT
@SP
A = M - 1
M = 0
@Label3
0;JMP
(Label2)
@SP
A = M - 1
M = -1
(Label3)
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
@endFrame
M = D
@5
D = A
@endFrame
D = M - D
@retAddress
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
@endFrame
A = M - 1
D = M
@THAT
M = D
@endFrame
A = M - 1
A = A - 1
D = M
@THIS
M = D
@endFrame
A = M - 1
A = A - 1
A = A - 1
D = M
@ARG
M = D
@4
D = A
@endFrame
A = M - D
D = M
@LCL
M = D
@retAddress
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
@Label4
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
(Label4)
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
@Label5
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
(Label5)
@SP
AM = M - 1
D = M
A = A - 1
M = D + M
@LCL
D = M
@endFrame
M = D
@5
D = A
@endFrame
D = M - D
@retAddress
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
@endFrame
A = M - 1
D = M
@THAT
M = D
@endFrame
A = M - 1
A = A - 1
D = M
@THIS
M = D
@endFrame
A = M - 1
A = A - 1
A = A - 1
D = M
@ARG
M = D
@4
D = A
@endFrame
A = M - D
D = M
@LCL
M = D
@retAddress
A = M
0;JMP
