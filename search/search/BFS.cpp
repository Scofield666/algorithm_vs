#include<bits/stdc++.h>
using namespace std;
const int maxns = 51, inf = 0x3f3f3f3f;
int mat[maxns][maxns][maxns];
bool vis[maxns][maxns][maxns];
struct Node {
	int x, y, z;
	int t;
};
queue<Node>q;
int go[][3] = {
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
int a, b, c;
int T;
int bfs() {
	int ret = -1;
	while (!q.empty()) {
		Node now = q.front();
		if (now.x == a - 1 && now.y == b - 1 && now.z == c - 1) return now.t;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nz = now.z + go[i][2];
			int nt = now.t + 1;

			if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || ny >= c) continue;
			if (vis[nx][ny][nz] == true) continue;
			if (mat[nx][ny][nz] == 1) continue;

			vis[nx][ny][nz] = true;
			q.push(Node{ nx,ny,nz,nt });
		}
	}
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &a, &b, &c, &T);
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {
					scanf("%d", &mat[i][j][k]);
				}
			}
		}
		memset(vis, false, sizeof(vis));
		while (!q.empty()) q.pop();
		q.push(Node{ 0,0,0,0 });
		vis[0][0][0] = true;
		int ret = bfs();
		if (ret <= T && ret != -1) printf("%d\n", ret);
		else printf("-1\n");
	}
	return 0;
}