(SimpleFunction.test)
@SP
A = M
M = 0
@SP
M = M + 1
@SP
A = M
M = 0
@SP
M = M + 1
@LCL
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
@1
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = D + M
@SP
A = M - 1
M = !M
@ARG
D = M
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@SP
AM = M - 1
D = M
A = A - 1
M = D + M
@ARG
D = M
@1
A = D + A
D = M
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
