#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;


int main(){
    int N, M;
    cin >> N >>M;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr,arr+N);

    int low = 0, hi = 1000000000;
    while(low+1 < hi){
        int middle = (low+hi)/2;
        long long sum =0;
        for (int i = 0; i <N; i++)
            if( arr[i] > middle ) sum = sum += arr[i]-middle;
        if (sum >= M ) low = middle;
        else hi = middle;
    }
    cout << low;

}

