#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(){
    int arr[5], output= 0;
    for (int i = 0; i < 5; i++){
        cin >> arr[i];
        output += arr[i]*arr[i];
    }
    cout <<  output%10;

}

