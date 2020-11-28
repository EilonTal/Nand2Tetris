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
(Class1.set)
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
(Class1.get)
@0
D = A
@NOLOCALS7
D;JEQ
@var5
M = D
(LOOP6)
@SP
AM = M + 1
A = A - 1
M = 0
@var5
MD = M - 1
@LOOP6
D;JGT
(NOLOCALS7)
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
@endFrame8
M = D
@5
D = A
@endFrame8
A = M - D
D = M
@retAddress9
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
@endFrame8
A = M - 1
D = M
@THAT
M = D
@endFrame8
A = M - 1
A = A - 1
D = M
@THIS
M = D
@endFrame8
A = M - 1
A = A - 1
A = A - 1
D = M
@ARG
M = D
@4
D = A
@endFrame8
A = M - D
D = M
@LCL
M = D
@retAddress9
A = M
0;JMP
(Class2.set)
@0
D = A
@NOLOCALS12
D;JEQ
@var10
M = D
(LOOP11)
@SP
AM = M + 1
A = A - 1
M = 0
@var10
MD = M - 1
@LOOP11
D;JGT
(NOLOCALS12)
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
@Class2.0
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
@Class2.1
M = D
@0
D = A
@SP
M = M + 1
A = M - 1
M = D
@LCL
D = M
@endFrame13
M = D
@5
D = A
@endFrame13
A = M - D
D = M
@retAddress14
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
@endFrame13
A = M - 1
D = M
@THAT
M = D
@endFrame13
A = M - 1
A = A - 1
D = M
@THIS
M = D
@endFrame13
A = M - 1
A = A - 1
A = A - 1
D = M
@ARG
M = D
@4
D = A
@endFrame13
A = M - D
D = M
@LCL
M = D
@retAddress14
A = M
0;JMP
(Class2.get)
@0
D = A
@NOLOCALS17
D;JEQ
@var15
M = D
(LOOP16)
@SP
AM = M + 1
A = A - 1
M = 0
@var15
MD = M - 1
@LOOP16
D;JGT
(NOLOCALS17)
@Class2.0
D = M
@SP
M = M + 1
A = M - 1
M = D
@Class2.1
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
@endFrame18
M = D
@5
D = A
@endFrame18
A = M - D
D = M
@retAddress19
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
@endFrame18
A = M - 1
D = M
@THAT
M = D
@endFrame18
A = M - 1
A = A - 1
D = M
@THIS
M = D
@endFrame18
A = M - 1
A = A - 1
A = A - 1
D = M
@ARG
M = D
@4
D = A
@endFrame18
A = M - D
D = M
@LCL
M = D
@retAddress19
A = M
0;JMP
(Sys.init)
@0
D = A
@NOLOCALS22
D;JEQ
@var20
M = D
(LOOP21)
@SP
AM = M + 1
A = A - 1
M = 0
@var20
MD = M - 1
@LOOP21
D;JGT
(NOLOCALS22)
@6
D = A
@SP
M = M + 1
A = M - 1
M = D
@8
D = A
@SP
M = M + 1
A = M - 1
M = D
@retAddress23
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
@2
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Class1.set
0;JMP
(retAddress23)
@SP
AM = M - 1
D = M
@5
M = D
@23
D = A
@SP
M = M + 1
A = M - 1
M = D
@15
D = A
@SP
M = M + 1
A = M - 1
M = D
@retAddress24
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
@2
D = D - A
@ARG
M = D
@SP
D = M
@LCL
M = D
@Class2.set
0;JMP
(retAddress24)
@SP
AM = M - 1
D = M
@5
M = D
@retAddress25
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
@Class1.get
0;JMP
(retAddress25)
@retAddress26
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
@Class2.get
0;JMP
(retAddress26)
(WHILE)
@WHILE
0;JMP
