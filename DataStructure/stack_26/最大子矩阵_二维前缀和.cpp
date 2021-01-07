#include<bits/stdc++.h>
using namespace std;
const int maxns = 1001;
int a[maxns][maxns];
int sum[maxns][maxns];
int t, m, n;
int x, y;
int func(int p, int q) {
	return sum[p + x - 1][q + y - 1] - sum[p + x - 1][q - 1] - sum[p - 1][q + y - 1] + sum[p - 1][q - 1];
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &m, &n, &x, &y);
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		//求二维前缀和
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}

		int maxnn = 0;
		for (int i = 1; i + x - 1 <= m; i++) {
			for (int j = 1; j + y - 1 <= n; j++) {
				maxnn = max(maxnn, func(i, j));
			}
		}
		printf("%d\n", maxnn);
	}
	return 0;
}