#include<bits/stdc++.h>
using namespace std;
const int maxns = 100, inf = 0x3f3f3f3f, wmax = 1010;
int w[maxns], v[maxns];
int dp[maxns][wmax]; // ǰi����Ʒ����������jʱ������ֵ
int t, n;
//���仯���ѣ����������Ľ����ŵ�dp������
int dfs(int i, int j) {
	if (dp[i][j]) return dp[i][j];
	if (i == 0 || j == 0) return 0;
	if (j < w[i]) {
		dp[i][j] = dfs(i - 1, j); //�޷����뱳��
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