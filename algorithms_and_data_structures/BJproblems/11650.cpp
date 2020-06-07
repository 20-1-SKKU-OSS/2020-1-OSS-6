#include<stdio.h>
#include<algorithm>
#include<utility>

using namespace std;

int n;
pair<int,int> arr[100005];

int main()
{
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++) scanf("%d %d",&arr[i].first,&arr[i].second);
    sort(arr+1,arr+1+n);
    for(int i=1 ; i<=n ; i++)
        printf("%d %d\n",arr[i].first,arr[i].second);
    return 0;
}
