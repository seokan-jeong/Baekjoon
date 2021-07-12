
// 21.7.12
// 분할정복, 재귀
// '쿼드트리'와 완전 비슷한 문제

#include <iostream>
using namespace std;

int N;
int paper[128][128];
int white = 0, blue = 0;

void recursiveFunc(int n, int y, int x) {
	if (n == 1) {
		if (paper[y][x]) {
			blue++;
		}
		else {
			white++;
		}
		return;
	}

	bool checkWhite = true, checkBlue = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (paper[i][j]) {
				checkWhite = false;
			}
			else {
				checkBlue = false;
			}
		}
	}

	if (checkWhite) {
		white++;
	}
	else if (checkBlue) {
		blue++;
	}
	else {
		recursiveFunc(n / 2, y, x);
		recursiveFunc(n / 2, y + n / 2, x);
		recursiveFunc(n / 2, y, x + n / 2);
		recursiveFunc(n / 2, y + n / 2, x + n / 2);
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	recursiveFunc(N, 0, 0);
	cout << white << ' ' << blue << endl;
}
