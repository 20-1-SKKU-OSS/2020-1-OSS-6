/*
문제

NlogNsglow에서 알고리즘 게임의 그랜드 오프닝을 위해,
그랜드 리뉴얼을 위해 줄에있는타워 블럭들을 제거해야합니다.
원래 계획은 제어된 폭발로 타워 블럭을 하나씩 제거하는 것이었지만,
시간 제약이 있어 빠른 솔루션이 필요 합니다.
블록을 더 빨리 제거할 수 있도록 돕기 위해 유니버설 키네틱/백열 에너지 입자 캐넌(UMIEPC)을 사용하게 되었습니다.
이 최첨단 기구는 단 한 번의 충전으로 단일 타워 블록의 모든 층을 제거할 수 있습니다.
사용자가 바닥 번호 x를 선택할 수 있도록 모든 블록의 모든 x-th 층을 동시에 선택하십시오.
후자의 경우, x층 이하의 블록은 그대로 두고 x층 이상의 블록은 그대로 둡니다.
제거된 x번째 층 위의 모든 층이 한 층 아래로 떨어집니다.
모든 타워의 층수를 고려하여 모든 블록의 모든 층을 제거하는 데 필요한 최소로 충전의 수를 출력합니다.

인풋
입력한 첫번째 줄 블록 n에는 2≤ n≤ 100 000 수가 포함되어 있습니다.
두번째 줄 블록은 n만큼 연속된 블록 hi가 i=1,2,... , n 이며, 1≤ hi ≤ 100 0000입니다.

아웃풋
출력된 한 줄은 한 정수르 포함하고 있습니다: 모든 블록을 없애기 위해서 필요한 최소한의 충전이 필요합니다.
*/

#include <iostream>
#include<algorithm>
bool check();
void remove_horizontal();
void remove_vertical();
void reposition();

using namespace std;
int arr[100005], N, n = 0, result = 0;
int main(){
cin >> N; scanf("%d",&N);
for(int i = 0 ; i <N;i++)
    cin >> arr[i];
sort(arr,arr+N);

while(N>=n){
    if (check()){
        remove_horizontal();
        reposition();
    }
    else{
        remove_vertical();
        reposition();
    }
}

cout << result;
}

bool check(){
if (arr[N-1]<N-n)
    return true;
else
    return false;
}
void remove_horizontal(){
for(int i = n;i<N;i++)
    arr[i] -=1;
result++;
}
void remove_vertical(){
arr[N-1] = 0;
N--;
result++;
}
void reposition(){
while(N>=n && arr[n]<=0){
    n++;
}
}

