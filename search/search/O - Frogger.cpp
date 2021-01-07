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
const int maxns = 201, inf = 0x3f3f3f3f;
struct Node {
	int x, y;
}entry[maxns];
int n;
int e[maxns][maxns];
bool vis[maxns];
vector<int>temppath, path;
int ans = inf;
int src = 1;
int dst = 2;
void dfs(int v) {
	vis[v] = true;
	if (v == dst) {
		temppath.push_back(v);
		int maxstep = 0;
		for (int i = 0; i < temppath.size() - 1; i++) {
			int id = temppath[i];
			int nxt = temppath[i + 1];
			maxstep = max(maxstep, e[id][nxt]);
		}
		if (maxstep < ans) ans = maxstep;
		vis[v] = false;
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for (int i = 1; i <= n; i++) {
		if (vis[i] == true) continue;
		if (e[v][i] == inf) continue;
		dfs(i);
	}
	vis[v] = false;
	temppath.pop_back();
	return;
}
int main() {
	int cnt = 1;
	while (scanf("%d", &n) != EOF) {
		ans = inf;
		if (n == 0) break;
		memset(e, inf, sizeof(e));
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &entry[i].x, &entry[i].y);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int dis = (entry[i].x - entry[j].x) * (entry[i].x - entry[j].x) + 
					(entry[i].y - entry[j].y)* (entry[i].y - entry[j].y);
				e[i][j] = e[j][i] = dis;
			}
		}

		dfs(1);

		printf("Scenario #%d\n", cnt);
		printf("Frog Distance = %.3f\n", sqrt((double)ans));
		cnt++;
	}
	return 0;
}