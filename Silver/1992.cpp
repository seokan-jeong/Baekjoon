
// 21.7.12
// 분할정복, 재귀를 통한 규칙만 찾으면 됨

#include <iostream>
#include <string>
using namespace std; 

int arr[64][64];

void recursiveFunc(int n, int y, int x) {
	if (n == 1) {
		cout << arr[y][x];
		return;
	}

	bool checkZero = true, checkOne = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j]) {
				checkZero = false;
			}
			else {
				checkOne = false;
			}
		}
	}

	if (checkZero) {
		cout << 0;
	}
	else if (checkOne) {
		cout << 1;
	}
	else {
		cout << "(";
		recursiveFunc(n / 2, y, x);
		recursiveFunc(n / 2, y, x + n / 2);
		recursiveFunc(n / 2, y + n / 2, x);
		recursiveFunc(n / 2, y + n / 2, x + n / 2);
		cout << ")";
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	recursiveFunc(N, 0, 0);
	cout << "\n";
	return 0;
}
