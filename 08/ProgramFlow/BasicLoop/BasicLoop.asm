@0
D = A
@SP
M = M + 1
A = M - 1
M = D
@SP
AM = M - 1
D = M
@LCL
A = M
M = D
@LOOP_START
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
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
@SP
M = M - 1
A = M
D = M
A = A - 1
M = D + M
@SP
AM = M - 1
D = M
@LCL
A = M
M = D
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
M = M - 1
A = M
D = M
A = A - 1
M = D - M
M = -M
@SP
AM = M - 1
D = M
@ARG
A = M
M = D
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
A = M - 1
D = M
@LOOP_START
D;JNE
@LCL
D = M
@0
A = D + A
D = M
@SP
M = M + 1
A = M - 1
M = D
