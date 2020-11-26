(Class1.set)
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
@SP
AM = M - 1
D = M
@Class1.0
M = D
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
@Class1.1
M = D
@0
D = A
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
(Class1.get)
@0
D = A
@var2
M = D
(LOOP3)
@SP
AM = M + 1
A = A - 1
M = 0
@var2
MD = M - 1
@LOOP3
D;JGT
@Class1.0
D = M
@SP
M = M + 1
A = M - 1
M = D
@Class1.1
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
