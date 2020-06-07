
/*
아래와 같이 n의 입력에 따라 밖에서 안으로 순차적으로 N*N Matrix 를 출력하는 함수를 만드시오

입력 : 3

출력 :

| 1 | 2 | 3 |

| 8 | 9 | 4 |

| 7 | 6 | 5 |

입력 : 4

출력 :

| 1 | 2 | 3 | 4 |

| 12 | 13 | 14 | 5 |

| 11 | 16 | 15 | 6 |

| 10 | 9 | 8 | 7 |
*/

n=int(input('행렬크기:'))

lis = [[ -1 for i in range(n)] for j in range(n)]
x = 0
y = 0
dY = 0
dX = 1
count = 1
while lis[y][x] == -1:
    lis[y][x] = count
    if dX != 0 and count!=1:
        if x == n-1 or x == 0 or lis[y][x+dX] != -1:
            dY = dX
            dX = 0
    else :
        if dY != 0 :
            if y == n-1 or y==0 or lis[y+dY][x] != -1:
                    dX = dY*(-1)
                    dY = 0
    x += dX
    y += dY
    count+=1

for y in range(n):
    for x in range(n):
        print ('%5d'%lis[y][x],end='')
    print()
