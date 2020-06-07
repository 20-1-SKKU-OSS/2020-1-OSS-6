#include <iostream>
#include<algorithm>


using namespace std;

int main(){
int arr[10005], N, result = 0;
scanf("%d",&N);
for(int i = 0 ; i <N;i++)
    scanf("%d",&arr[i]);
sort(arr,arr+N);
for(int i = 0; i < N; i++)
    result += arr[i]*(N-i);
printf("%d",result);
}


