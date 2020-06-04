#include<iostream>
/*This program can calculate big size of integer's addition and multiplication   */
using namespace std;

int main() {
	int a[101], b[101];
	int ans[300] = { 0 };
	char c[101], d[101];
	char operand;

	cin >> operand >> c >> d;
	int e = 0;
	int f = 0;
	int temp;
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

