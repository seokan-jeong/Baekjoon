
// 21.7.12
// dfs로 풂
// dfs 구현 후가 오히려 좀 헷갈렸음. 단지 수를 세는 건 괜찮은데, 집 개수를 세는 방법이 고민됐음.
// 나는 그냥 map 배열의 1 들을 cnt로 바꿔서 마지막에 반복문으로 1, 2, ..., cnt까지 각각의 수가
// 몇 개인지 세는 방법을 사용함.

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, cnt;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int map[25][25];
bool visit[25][25];

void dfs(int y, int x) {
	map[y][x] = cnt;
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
			if (map[ny][nx] && !visit[ny][nx]) {
				dfs(ny, nx);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visit[i][j]) {
				cnt++;
				dfs(i, j);
			}
		}
	}

	cout << cnt << endl;

	int* CntOfHouses = new int[cnt + 1];

	for (int i = 0; i <= cnt; i++) {
		CntOfHouses[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			CntOfHouses[map[i][j]]++;
		}
	}
	CntOfHouses[0] = 1000000;
	sort(CntOfHouses, CntOfHouses + cnt + 1);

	for (int i = 0; i < cnt; i++) {
		cout << CntOfHouses[i] << endl;
	}

	delete[] CntOfHouses;
}
