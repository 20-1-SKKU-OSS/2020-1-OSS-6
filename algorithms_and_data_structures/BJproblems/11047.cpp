#include <iostream>

using namespace std;

int main()
{
    int n,k, cnt = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i<n; i++)
        cin >> a[i];
    for (int i = n-1; i>=0 ; i--){
        cnt += k / a[i];
        k -= (k/a[i])*a[i];
    }

    cout << cnt;
    return 0;
}

