#include<bits/stdc++.h>
const int maxns = 101, inf = 0x3f3f3f3f;
bool mark[maxns][maxns];
char mat[maxns][maxns];
int go[][2] = {
	-1,0,
	1,0,
	0,1,
	0,-1,
	1,1,
	1,-1,
	-1,1,
	-1,-1
};
int n, m;
//递归遍历图
void DFS(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];

		if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
		if (mark[nx][ny] == true) continue;
		if (mat[nx][ny] == '*') continue;

		mark[nx][ny] = true; //相当于找到一个@就标记
		DFS(nx, ny);
	}
	return; //所有状态转移完了之后return
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", mat[i]);
		}
		memset(mark, false, sizeof(mark));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mark[i][j] == true) continue;
				if (mark[i][j] == '@') {
					DFS(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}