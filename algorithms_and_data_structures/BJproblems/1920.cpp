/*
문제
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

인풋
첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다.
다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 주어진다.
다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다.
모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

아웃풋
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

*/

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
    for(int i = 0; i < N; i++)  cin >> A[i];
    int M; cin >> M; int B[100000];
    for(int i = 0; i < M; i++)  cin >> B[i];
    sort(A,A+N);

    for( int i = 0; i < M ; i ++)
        
        cout << binary_search(A, N, B[i]) << endl;

}

