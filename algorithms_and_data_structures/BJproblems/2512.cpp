#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
    int N; cin >> N;
    int arr[N]; for(int i = 0; i < N; i++) cin >> arr[i]; sort(arr,arr+N);
    int total; cin >> total;
    long long sum=0; for (int i =0; i < N; i++) sum += arr[i];

    if ( sum <= total) cout << arr[N-1];
    else{
        int low = 0, hi = 1000000000;
        while (low+1 < hi){
            int middle = (low+hi)/2;
            sum =0;
            for(int i = 0; i <N; i++){
                if (arr[i] > middle ) sum += middle;
                else sum+=arr[i];
            }
            if (sum > total) hi = middle;
            else low = middle;
        }
        cout << low;
    }
}

