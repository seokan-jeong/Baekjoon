
// 1012. 유기농 배추

#include <iostream>
using namespace std;

int n, m, k;
int farm[50][50];
bool check[50][50];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int cnt;

void find(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if(farm[nx][ny] == 1 && !check[nx][ny]){
                check[nx][ny] = true;
                find(nx, ny);
            }
        }
    }
}

int main() {
    int testCase;
    scanf("%d", &testCase);
    
    while(testCase-- > 0){
        // 초기화
        cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                farm[i][j] = 0;
                check[i][j] = false;
            }
        }
        
        // 입력 받기
        scanf("%d %d %d", &m, &n, &k);
        while(k-- > 0){
            int x, y;
            scanf("%d %d", &x, &y);
            farm[y][x] = 1;
        }
        
        // find recursion 돌리기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(farm[i][j] == 1 && check[i][j] == false){
                    cnt++;
                    find(i, j);
                }
            }
        }
        
        // 출력
        printf("%d\n", cnt);
    }
        
    
}
