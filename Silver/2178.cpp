
// 21.7.12
// dfs로 풀었다가 시간초과 당하고 bfs로 바꿔서 품
// dfs, bfs 좀 더 숙련해서 상황에 맞게 다룰 줄 알아야 할 듯,,

#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 2147483647;
int minValue = MAX;
int N, M;
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
int arr[101][101], check[101][101];
bool visit[101][101];

// dfs 알고리즘은 최단거리를 찾기 위해 완전탐색을 하므로 시간복잡도가 큼
// 그래서 시간초과 걸림 ㅜ
void dfs(int n, int m, int length) {
	int newLength = length + 1;
	if (n == N && m == M) {
		if (newLength < minValue) {
			minValue = newLength;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = m + dx[i], ny = n + dy[i];
		if (ny <= N && ny >= 1 && nx <= M && nx >= 1 && arr[ny][nx] && !visit[ny][nx]) {
			visit[n][m] = true;
			dfs(ny, nx, newLength);
			visit[n][m] = false;
		}
	}
}

void bfs(int n, int m) {
	visit[n][m] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(n, m));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= N && ny >= 1 && nx <= M && nx >= 1 && arr[ny][nx] && !visit[ny][nx]) {
				check[ny][nx] = check[y][x] + 1;
				visit[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}

	// dfs(1, 1, 0);
	// cout << minValue << endl;
	check[1][1] = 1;
	bfs(1, 1);
	cout << check[N][M] << endl;
}
