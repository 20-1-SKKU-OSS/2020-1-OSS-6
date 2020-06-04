#include <iostream>
#include <algorithm>


using namespace std;

int main(){
int N, arr[100005], eat = 0;
cin >> N;
for(int i = 0 ; i <N; i++)
    cin >> arr[i];
sort(arr,arr+N);

for(int i = 0; i < N; i++){
    if (arr[i] <= eat+1)
        eat += arr[i];
    else
        break;
}
cout << eat +1;

}


