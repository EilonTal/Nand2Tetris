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
(SimpleFunction.test)
@2
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
D = M
@endFrame3
M = D
@5
D = A
@endFrame3
A = M - D
D = M
@retAddress4
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
@endFrame3
A = M - 1
D = M
@THAT
M = D
@endFrame3
A = M - 1
A = A - 1
D = M
@THIS
M = D
@endFrame3
A = M - 1
A = A - 1
A = A - 1
D = M
@ARG
M = D
@4
D = A
@endFrame3
A = M - D
D = M
@LCL
M = D
@retAddress4
A = M
0;JMP
