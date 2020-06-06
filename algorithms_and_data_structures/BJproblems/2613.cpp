/*
문제
N개의 숫자 구슬이 <예시 1>과 같이 막대에 꿰어져 일자로 놓여 있다.
이들 구슬은 막대에서 빼낼 수 없고, 바꿀 수 없다.

예시 1 : 5 4 2 6 9 3 8 7

이 숫자 구슬을 M개의 그룹으로 나누었을 때 각각의 그룹의 합 중 최댓값이 최소가 되도록 하려 하다.
예를 들어 세 그룹으로 나눈다고 할 때 <예시 2>와 같이 그룹을 나누면 그룹의 합은 각각 11, 15, 18이 되어 그 중 최댓값은 18이 되고,
<예시 3>과 같이 나누면 각 그룹의 합은 각각 17, 12, 15가 되어 그 중 최댓값은 17이 된다.
숫자 구슬의 배열이 위와 같을 때는 그룹의 합 중 최댓값이 17보다 작게 만들 수는 없다.
그룹에 포함된 숫자 구슬의 개수는 0보다 커야 한다.

예시 2 : 5 4 2 - 6 9 - 3 8 7
예시 3 : 5 4 2 6 - 9 3 - 8 7

각 그룹의 합 중 최댓값이 최소가 되도록 M개의 그룹으로 나누었을 때,
그 최댓값과 각 그룹을 구성하는 구슬의 개수를 찾아 출력하는 프로그램을 작성하시오.

인풋
첫째 줄에 구슬의 개수 N과 그룹의 수 M이 주어진다.
둘째 줄에는 각 구슬이 적혀진 숫자가 왼쪽부터 차례로 주어진다.
N은 300 이하의 자연수, M은 N이하의 자연수이며, 구슬에 적혀진 숫자는 100 이하의 자연수이다.

아웃풋
각 그룹의 합 중 최댓값이 최소가 되도록 M개의 그룹으로 나누었을 때 그 최댓값을 첫째 줄에 출력하고,
둘째 줄에는 각 그룹을 구성하는 구슬의 개수를 왼쪽부터 순서대로 출력한다.
구슬의 개수를 출력할 때는 사이에 한 칸의 공백을 둔다.
만약 그룹의 합의 최댓값이 최소가 되도록 하는 경우가 둘 이상이라면 그 중 하나만을 출력한다.

*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(){
    int N,M; cin >> N >> M;
    int arr[N];
    for (int i = 0; i <N; i++) scanf("%d",&arr[i]);

    int left = 0, right = 300*100 + 1;
    while(left <= right){
        int middle = (left+right)/2;
        //check
        int part_sum = 0, part_count = 0;
        for(int i =0; i <N; i++){
            if ( arr[i] > middle){
                part_count = M + 1;
                break;
            }

            part_sum += arr[i];
            if (part_sum > middle){
                part_count++;
                part_sum = arr[i];
            }
            // when last element is added in pocket, increase part_count although the pocket didn't overflow middle.
            if(i >= N-1) part_count++;
            // to prevent a big element making error and wasting time
            if(part_count > M) break;
        }

        if (part_count > M) // fail
            left = middle+1; // left side on the middle don't satisfy rule.
        else
            right = middle-1; //오른쪽 값은 쓸 데 없이 큼.
        //cout << " sum: " << part_sum << " cout: "<< part_count << "left: " <<left << " right: " << right << "middle: " <<middle<<endl;
    }
    int a = right +1;
    //print
    cout << a <<endl;
    int part_sum = 0, part_count = 0, already_print_count = 0;
    for(int i =0; i < N; i++){
       /* if(M - (already_print_count +1) == N - i ){ // 이미 처리한 박스 + 지금 처리할 박스 ==  이미 처리한 구슬 개수
            part_sum = a + 1;
        } */
        if( part_sum + arr[i] <= a ){
            part_sum += arr[i];
            part_count++;
        }
        else{ // when part_sum overflow right, print part_count.
            cout << part_count << " " ;
            part_sum = arr[i];
            part_count = 1;
            already_print_count++;
        }
        if(M - already_print_count  == N - i ){
            part_sum = a + 1;
        }

    }
    cout << part_count; // print last part_count.
}

