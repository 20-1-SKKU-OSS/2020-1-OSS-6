#include <iostream>
#include <algorithm>
using namespace std;

bool binary_search(int arr[], int len, int target){
    int s = 0, e = len -1, m;
    while (s <= e){
        m = (s+e)/2;
        if (arr[m] == target) return 1;
        else if (arr[m] > target ) e = m -1;
        else s = m +1;
    }
    return 0;
}

int main()
{
    int N; cin >> N; int A[100000];
    for(int i = 0; i < N; i++)  scanf("%d",&A[i]);
    int M; cin >> M; int B[100000];
    for(int i = 0; i < M; i++)  scanf("%d",&B[i]);
    sort(A,A+N);

    for( int i = 0; i < M ; i ++)
        printf("%d\n", binary_search(A, N, B[i]) );


}

