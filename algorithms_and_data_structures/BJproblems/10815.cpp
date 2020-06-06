#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void check(int Narr[], int& M_number, int& C_number, int& N){
    int low = 0, hi = N-1;
    while(low <= hi){
        int middle = (low+hi)/2;
        if ( Narr[middle] == M_number){ C_number = 1; return;}
        else if ( Narr[middle] < M_number){ low = middle +1;}
        else { hi = middle -1;}
    }
    return;
}

int main(){
    int N, M;
    cin >> N; int Narr[N];
    for (int i = 0; i < N; i++) cin >> Narr[i];
    cin >> M; int Marr[M], Carr[M]={0};
    for (int i = 0; i < M; i++) cin >> Marr[i];

    sort(Narr,Narr+N);

    for(int i = 0; i < M; i++){
        check(Narr, Marr[i],Carr[i],N);
    }

    for (int i = 0; i < M; i++){
        cout << Carr[i]<< " ";
    }
}

