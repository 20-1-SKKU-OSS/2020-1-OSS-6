/*
자연수 N을 입력받아서 다음과 같은 NxN 매트릭스를 출력하는 프로그램을 작성하라.

<입력예1>

자연수 N을 입력하시오(0<N) : 3

<출력예1>

1 3 4
2 5 8
6 7 9

*/

n = int(input())
C = sorted(((x, y) for x in range(n) for y in range(n)),
           key=lambda z:(z[0]+z[1], z[1] if (z[0]+z[1])%2 else z[0]))
L = [[0] * n for _ in range(n)]
for i, (x, y) in enumerate(C, 1): L[x][y] = i
for line in L: print(*line)
