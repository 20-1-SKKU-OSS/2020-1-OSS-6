#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
int N,K;
cin >> N >> K;
int* InputArr = new int[N];
int* RollBackArr = new int[K];
for (int i = 0; i <K ; i++)
    RollBackArr[i] = N+1;
for(int i = 0; i < N; i++)
    cin >> InputArr[i];


bool BigSuccess = 1;
for (int i = N-1; i >=0; i --){
    int MinDefference = N+2, MinPosition = K;
    for(int j = 0; j < K ; j ++){
        if (InputArr[i] < RollBackArr[j] && RollBackArr[j] - InputArr[i] < MinDefference){
            MinPosition = j;
            MinDefference = RollBackArr[j] - InputArr[i];
        }

    }

    if (MinPosition == K){
        BigSuccess = 0;
        break;
    }
    RollBackArr[MinPosition] = InputArr[i];
}

if (BigSuccess == 0)
    cout << "NO";
else
    cout << "YES";
    
    
delete InputArr[];
delete RollBackArr[];

}


