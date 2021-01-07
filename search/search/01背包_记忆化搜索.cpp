#include<bits/stdc++.h>
using namespace std;
const int maxns = 100, inf = 0x3f3f3f3f, wmax = 1010;
int w[maxns], v[maxns];
int dp[maxns][wmax]; // 前i个物品重量不大于j时的最大价值
int t, n;
//记忆化深搜，将搜索到的结果存放到dp数组中
int dfs(int i, int j) {
	if (dp[i][j]) return dp[i][j];
	if (i == 0 || j == 0) return 0;
	if (j < w[i]) {
		dp[i][j] = dfs(i - 1, j); //无法加入背包
	}
	else dp[i][j] = max(dfs(i - 1, j), dfs(i - 1, j - w[i]) + v[i]);
	return dp[i][j];
}
int main() {
	while (scanf("%d%d", &t,&n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &w[i], &v[i]);
		}
		printf("%d\n", dfs(n, t));
	}
	return 0;
}