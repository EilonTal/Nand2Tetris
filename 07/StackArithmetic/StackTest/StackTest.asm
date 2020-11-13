@17
D = A
@SP
A = M
M = D
@SP
M = M + 1
@17
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label0
D;JEQ
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
@17
D = A
@SP
A = M
M = D
@SP
M = M + 1
@16
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label2
D;JEQ
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
@16
D = A
@SP
A = M
M = D
@SP
M = M + 1
@17
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label4
D;JEQ
@SP
A = M - 1
M = 0
@Label5
0;JMP
(Label4)
@SP
A = M - 1
M = -1
(Label5)
@892
D = A
@SP
A = M
M = D
@SP
M = M + 1
@891
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label6
D;JLT
@SP
A = M - 1
M = 0
@Label7
0;JMP
(Label6)
@SP
A = M - 1
M = -1
(Label7)
@891
D = A
@SP
A = M
M = D
@SP
M = M + 1
@892
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label8
D;JLT
@SP
A = M - 1
M = 0
@Label9
0;JMP
(Label8)
@SP
A = M - 1
M = -1
(Label9)
@891
D = A
@SP
A = M
M = D
@SP
M = M + 1
@891
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label10
D;JLT
@SP
A = M - 1
M = 0
@Label11
0;JMP
(Label10)
@SP
A = M - 1
M = -1
(Label11)
@32767
D = A
@SP
A = M
M = D
@SP
M = M + 1
@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label12
D;JGT
@SP
A = M - 1
M = 0
@Label13
0;JMP
(Label12)
@SP
A = M - 1
M = -1
(Label13)
@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1
@32767
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label14
D;JGT
@SP
A = M - 1
M = 0
@Label15
0;JMP
(Label14)
@SP
A = M - 1
M = -1
(Label15)
@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1
@32766
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
D = M-D
@Label16
D;JGT
@SP
A = M - 1
M = 0
@Label17
0;JMP
(Label16)
@SP
A = M - 1
M = -1
(Label17)
@57
D = A
@SP
A = M
M = D
@SP
M = M + 1
@31
D = A
@SP
A = M
M = D
@SP
M = M + 1
@53
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
M = M - 1
A = M
D = M
A = A - 1
M = D + M
@112
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
M = M - 1
A = M
D = M
A = A - 1
M = D - M
M = -M
@SP
A = M - 1
M = -M
@SP
AM = M - 1
D = M
A = A - 1
M = D&M
@82
D = A
@SP
A = M
M = D
@SP
M = M + 1
@SP
AM = M - 1
D = M
A = A - 1
M = D|M
@SP
A = M - 1
M = !M
