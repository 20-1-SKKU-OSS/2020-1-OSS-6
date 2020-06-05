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

