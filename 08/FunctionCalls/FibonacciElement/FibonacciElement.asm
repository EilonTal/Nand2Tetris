(Main.fibonacci)
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
@Label0
D;JLT
@SP
A = M - 1
M = 0
@Label1
0;JMP
(Label0)
@SP
A = M - 1
M = -1
(Label1)
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
D = A
@endFrame
M = D
@5
D = A
@endFrame
D = A - D
A = D
D = M
@retAddress
M = D
@SP
AM = M - 1
D = M
@ARG
A = M
M = D
@ARG
D = A + 1
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
@ARG
M = D
@retAddress
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
@Label2
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@5
D = A
@SP
D = M - D
@tempVar
M = D
@1
D = A
@tempVar
D = D - M
@ARG
M = D
@SP
D = M
@LCL
M = D
@Main.fibonacci
0;JMP
(Label2)
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
@Label3
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@ARG
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@5
D = A
@SP
D = M - D
@tempVar
M = D
@1
D = A
@tempVar
D = D - M
@ARG
M = D
@SP
D = M
@LCL
M = D
@Main.fibonacci
0;JMP
(Label3)
@SP
AM = M - 1
D = M
A = A - 1
M = D + M
@LCL
D = A
@endFrame
M = D
@5
D = A
@endFrame
D = A - D
A = D
D = M
@retAddress
M = D
@SP
AM = M - 1
D = M
@ARG
A = M
M = D
@ARG
D = A + 1
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
@ARG
M = D
@retAddress
0;JMP
