(Sys.init)
@4000
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
@THIS
M = D
@5000
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
@THAT
M = D
@Label0
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
@0
D = A
@tempVar
D = D - M
@ARG
M = D
@SP
D = M
@LCL
M = D
@Sys.main
0;JMP
(Label0)
@SP
AM = M - 1
D = M
@5
A = A + 1
M = D