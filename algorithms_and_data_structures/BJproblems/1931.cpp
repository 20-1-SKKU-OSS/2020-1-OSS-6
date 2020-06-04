#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int x;
    int y;
}List;
bool comp(const List& a, const List& b);

int main(){
int N, time =0,result = 0,n = 0;
List arr[100005];
scanf("%d",&N);

for (int i = 0; i<N ; i++){
scanf("%d %d",&arr[i].x,&arr[i].y);
}
sort(arr,arr+N,comp);
while(N > n){
    if(time <= arr[n].x){
        time = arr[n].y;
        result++;

    }
    n++;
}
printf("%d",result);
}

bool comp(const List& a, const List& b){
    if(a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
};

