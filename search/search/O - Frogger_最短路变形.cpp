#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxns = 2001, inf = 0x3f3f3f3f;
int e[maxns][maxns];
int dis[maxns]; //源点到该点路径中步长的最小最大值
bool vis[maxns];
struct Node {
	int x, y;
}entry[maxns];
int n;
int main() {
	int cnt = 1;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &entry[i].x, &entry[i].y);
		}
		memset(e, inf, sizeof(e));
		memset(dis, inf, sizeof(dis));
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int d = (entry[i].x - entry[j].x) * (entry[i].x - entry[j].x) +
					(entry[i].y - entry[j].y) * (entry[i].y - entry[j].y);
				e[i][j] = e[j][i] = d;
			}
		}

		dis[1] = 0;
		for (int i = 1; i <= n; i++) {
			int u = -1; int minn = inf;
			for (int j = 1; j <= n; j++) {
				if (vis[j] == false && dis[j] < minn) {
					u = j;
					minn = dis[j];
				}
			}
			if (u == -1) break;
			vis[u] = true;
			for (int v = 1; v <= n; v++) {
				if (vis[v] == false && e[u][v] != inf) {
					if (dis[v] > max(dis[u], e[u][v])) {
						dis[v] = max(dis[u], e[u][v]);
					}
				}
			}
		}
		printf("Scenario #%d\n", cnt);
		printf("Frog Distance = %.3f\n", sqrt((double)dis[2]));
		printf("\n");
		cnt++;
	}
	return 0;
}