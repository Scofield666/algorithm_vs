#include<bits/stdc++.h>
using namespace std;
const int maxns = 8, inf = 0x3f3f3f3f;
char mat[maxns][maxns];
bool vis[maxns][maxns];
bool success = false;
struct Node {
	int x, y;
};
vector<Node>temppath, path;
int go[][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1
};
int m, n, t;
void dfs(int x, int y, int ct) {
	temppath.push_back(Node{ x,y });
	vis[x][y] = true;

	if (mat[x][y] == 'D' && ct == t) {
		path = temppath;
		success = true;
		return;
	}
	if (ct > t) return; //一定要添上
	for (int i = 0; i < 4; i++) {
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if (nx > m || nx <= 0 || ny > n || ny <= 0) continue;
		if (mat[nx][ny] == 'X') continue;
		if (vis[nx][ny] == true) continue;
		dfs(nx, ny, ct + 1);
		if (success) return;
	}
	vis[x][y] = false;
	temppath.pop_back();
	return;
}
int main() {
	while (scanf("%d%d%d", &m, &n, &t) != EOF) {
		for (int i = 1; i <= m; i++) {
			scanf("%s", mat[i] + 1);
		}
		int sx, sy;
		int dx, dy;
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (mat[i][j] == 'S') {
					sx = i; sy = j;
				}
				if (mat[i][j] == 'D') {
					dx = i; dy = j;
				}
			}
		}

		dfs(sx, sy, 0);

		if (success) printf("YES\n");
		else printf("NO\n");

		for (int i = 0; i < path.size(); i++) {
			if (i != path.size() - 1) {
				printf("(%d,%d)->", path[i].x, path[i].y);
			}
			else printf("(%d,%d)\n", path[i].x, path[i].y);
			
		}

	}
	return 0;
}