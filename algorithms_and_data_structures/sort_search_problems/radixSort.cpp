void Radix_Sort()                // 기수정렬 함수 !
{
    int Radix = 1;                // 최대 자릿수까지 계산을 하기 위한 변수
    while (1)                    // 최대 자릿수가 몇 자리인지 알아내기 위한 반복문 !
    {
        if (Radix >= Max_Value) break;    // Max_Value는 입력과 동시에 구해놓은 배열에서의 최댓값 !
        Radix = Radix * 10;        
    }
    for (int i = 1; i < Radix; i = i * 10)    // 1의 자리부터 10씩 곱하면서 최대자릿수 까지 반복 !
    {
        for (int j = 0; j < MAX; j++)    // 모든 배열을 다 탐색하면서
        {
            int K;
            if (Arr[j] < i) K = 0;        // 만약 현재 배열의 값이 현재 찾는 자릿수보다 작으면 0 !
            else K = (Arr[j] / i) % 10;    // 그게 아니라면 위에서 말한 공식 적용 !
            Q[K].push(Arr[j]);        // Queue배열에 해당 값을 순차적으로 저장 !
        }

        int Idx = 0;
        for (int j = 0; j < 10; j++)    // 0부터 9까지 Queue에 저장된 값들을 순차적으로 빼내기 위한 반복문.
        {
            while (Q[j].empty() == 0)    // 해당 Index번호의 Queue가 빌 때 까지 반복
            {
                Arr[Idx] = Q[j].front();    // 하나씩 빼면서 배열에 다시 저장.
                Q[j].pop();        
                Idx++;
            }
        }
    }
}
