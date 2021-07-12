
// 21.7.12
// bfs

#include <iostream>
#include <queue>
using namespace std;

bool map[101][101], visit[101];
int NumOfComputers, cnt = 0;

void bfs(int start) {
	visit[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 1; i <= NumOfComputers; i++) {
			if (!visit[i] && map[current][i]) {
				visit[i] = 1;
				q.push(i);
				cnt++;
			}
		}
	}
}

int main() {
	cin >> NumOfComputers;
	int testCases;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = map[y][x] = true;
	}

	bfs(1);
	cout << cnt << endl;
}
