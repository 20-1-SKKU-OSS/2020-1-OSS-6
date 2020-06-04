/*
정수 S와 K가 주어졌을 때, 합이 S인 K개의 양의 정수를 찾으려고 한다. 만약 여러개일 경우 그 곱을 가능한 최대로 하려고 한다.

가능한 최대의 곱을 출력한다.

만약 S=10, K=3이면, 3,3,4는 곱이 36으로 최대이다.

입력

첫째 줄에 두 수 S와 K가 주어진다. K는 20보다 작거나 같고, S는 100보다 작거나 같으며 K보다 크거나 같다.

출력

첫째 줄에 정답을 출력한다. 답은 9223372036854775807보다 작다.
*/

#include <iostream>
using namespace std;

long long S, K;

//곱하는 숫자들의 차가 적을수록 결과가 커진다
long long maxMultiple(void)
{
        long long result = 1;
        long long multiplier = S / K;
        long long cnt = S - (multiplier * K); //multiplier+1을 곱하는 횟수

        //multiplier 곱하는 횟수 = K - cnt
        for (int i = 0; i < K - cnt; i++)
                 result *= multiplier;
        //나머지는 multiplier+1 을 곱한다
        for (int i = 0; i < cnt; i++)
                 result *= (multiplier + 1);

        return result;
}

int main(void)
{
        cin >> S >> K;
        cout << maxMultiple() << endl;
        return 0;
}
