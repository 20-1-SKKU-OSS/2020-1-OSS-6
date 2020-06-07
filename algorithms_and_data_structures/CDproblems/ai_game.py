/*
위 게임의 인공지능 플레이어를 구현하시오.

입력

없음

출력

시행횟수, 인공지능이 입력한 값, bulls&cows 를 출력한다.

마지막 줄에는 정답과 성공/실패 여부를 출력하거나(최대 10회 시도),  
또는 횟수제한 없이 몇 회만에 성공했는지 출력한다.

예시:

1th guess = 0123, result = 1B1C
2th guess = 1023, result = 0B2C
3th guess = 0432, result = 2B0C
4th guess = 0536, result = 1B0C
5th guess = 0783, result = 2B0C
6th guess = 0983, result = 3B0C
7th guess = 0183, result = 2B0C
8th guess = 0982, result = 4B0C
success: answer = 0982, 8 tries

*/

import random

def getAnswer():
    number = [str(a) for a in range(0,10)]
    random.shuffle(number)
    return "".join(number[0:4])

def getCowBull(answer, guess):#input (list, list) format
    bull, cow = 0, 0

    for index,num in enumerate(guess):
        if answer[index]==guess[index]: cow+=1
        elif num in answer: bull+=1

    return cow, bull

while True:
    count = 1
    maxCount = (10)
    answer = getAnswer()
    print(answer) #Show Answer to code check

    while count <= maxCount:

        digits4 = input('Enter 4 digits :')

        if len(set(list(digits4))) != 4:
            print('Wrong input please enter again')
        else:
            cow, bull = getCowBull(list(answer), list(digits4))
            print('{}th guess={}, result={}B{}C'.format(count, digits4, bull,cow))
            if cow==4:
                print('success: answer={}, {} tries'.format(digits4, count))
                break
            else:
                count+=1
                if count>maxCount: print('Game over! the answer is {}'.format(answer))


    if input('Try Again? 1 or 0:')=='1': pass
    else: break
