#include<iostream>
/*This program can calculate big size of integer's addition and multiplication
Test Case: 
1.
*
9999999999999999999999999999999999999999999999999999
9999999999999999999999999999999999999999999999999999
output:99999999999999999999999999999999999999999999999999980000000000000000000000000000000000000000000000000001
2.
+
4710637465407808605559599045078603407603565880156808685390043655505436239531067048265313289258495667
8218239859441959740593636784950608190521685630529833437667620214365037957069989065364879777459931129
output:12928877324849768346153235830029211598125251510686642123057663869870474196601056113630193066718426796*/
using namespace std;

int main() {
	int a[101], b[101];
	int ans[300] = { 0 };
	char c[101], d[101];
	char operand;
	/* operand와 문자열로 된 숫자 입력 */
	cin >> operand >> c >> d;
	/*100자리수를 초과하는 숫자 입력시 프로그램 종료 */
	if (strlen(c) > 100 || strlen(d) > 100){
		cout << "100자리를 넘어가서 프로그램을 종료합니다.";
		return 0;
	}
	int e = 0;
	int f = 0;
	int temp;
	/* 문자열로 받은 숫자를 정수 데이터 타입으로 변환 */
	for (int i = strlen(c) - 1; i >= 0; i--) {

		a[e] = c[i] - 48;
		e = e + 1;
	}

	for (int i = strlen(d) - 1; i >= 0; i--) {
		b[f] = d[i] - 48;
		f = f + 1;
	}

	if (operand == '+') {
		if (strlen(c) > strlen(d)) {
			for (int i = 0; i < strlen(d); i++) {
				ans[i] = a[i] + b[i];
			}
			for (int i = strlen(d); i < strlen(c); i++) {
				ans[i] = a[i];
			}

			for (int i = 0; i < strlen(c); i++) {
				if (ans[i] >= 10) {
					temp = ans[i] / 10;
					ans[i] = ans[i] % 10;
					ans[i + 1] = ans[i + 1] + temp;
				}
			}

			if (ans[strlen(c)] != 0) {
				for (int i = strlen(c); i >= 0; i--) {
					cout << ans[i];
				}
			}
			else {
				for (int i = strlen(c) - 1; i >= 0; i--) {
					cout << ans[i];
				}
			}

		}
		else {
			for (int i = 0; i < strlen(c); i++) {
				ans[i] = a[i] + b[i];
			}
			for (int i = strlen(c); i < strlen(d); i++) {
				ans[i] = a[i];
			}

			for (int i = 0; i < strlen(d); i++) {
				if (ans[i] >= 10) {
					temp = ans[i] / 10;
					ans[i] = ans[i] % 10;
					ans[i + 1] = ans[i + 1] + temp;
				}
			}

			if (ans[strlen(d)] != 0) {
				for (int i = strlen(d); i >= 0; i--) {
					cout << ans[i];
				}
			}
			else {
				for (int i = strlen(d) - 1; i >= 0; i--) {
					cout << ans[i];
				}
			}
		}
	}
	else {
		int temp = 0;
		for (int i = 0; i < strlen(c); i++) {
			for (int j = 0; j < strlen(d); j++) {
				ans[i + j] = (a[i] * b[j]) + ans[i + j];
			}
		}

		for (int i = 0; i < strlen(c) + strlen(d); i++) {
			if (ans[i] >= 10) {
				temp = ans[i] / 10;
				ans[i] = ans[i] % 10;
				ans[i + 1] = ans[i + 1] + temp;
			}
		}
		if (ans[strlen(c) + strlen(d) - 1] != 0) {
			for (int i = strlen(c) + strlen(d) - 1; i >= 0; i--) {

				cout << ans[i];
			}
		}
		else {
			for (int i = strlen(c) + strlen(d) - 2; i >= 0; i--) {

				cout << ans[i];
			}
		}

	}
	return 0;
}

