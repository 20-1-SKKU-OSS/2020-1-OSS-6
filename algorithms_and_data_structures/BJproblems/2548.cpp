#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(){
    unsigned int N;
    cin >> N;
    unsigned int arr[N];
    for(int i =0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr,arr+N);
    cout << arr[(N-1)/2];

}

