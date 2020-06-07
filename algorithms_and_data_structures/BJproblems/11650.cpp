#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

int n;
pair<int, int> arr[100005];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)  cin >> arr[i].first >> arr[i].second;
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++)
		 cout << arr[i].first << " " << arr[i].second << endl;
	return 0;
}
