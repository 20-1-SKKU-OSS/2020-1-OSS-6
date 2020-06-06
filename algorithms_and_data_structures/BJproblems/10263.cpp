#include <iostream>
#include<algorithm>
bool check();
void remove_horizontal();
void remove_vertical();
void reposition();

using namespace std;
int arr[100005], N, n = 0, result = 0;
int main(){
scanf("%d",&N);
for(int i = 0 ; i <N;i++)
    scanf("%d",&arr[i]);
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

printf("%d",result);
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

