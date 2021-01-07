#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<string.h>
#include<math.h>
/*
	求给定维度的子矩阵的最大和 用前缀和
*/
using namespace std;
const int maxns = 1001;
int a[maxns][maxns];
int sa[maxns][maxns]; //前缀和
int b[maxns][maxns];
int sb[maxns][maxns];
int c[maxns][maxns];
int t;
int m, n, x, y;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &m, &n, &x, &y);
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		memset(sa, 0, sizeof(sa));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				sa[i][j] = sa[i][j - 1] + a[i][j];
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j + y - 1 <= n; j++) {
				b[i][j] = sa[i][j + y - 1] - sa[i][j - 1];
			}
		}

		memset(sb, 0, sizeof(sb));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j + y - 1 <= n; j++) {
				sb[i][j] = sb[i - 1][j] + b[i][j];
			}
		}

		for (int j = 1; j + y - 1 <= n; j++) {
			for (int i = 1; i + x - 1 <= m; i++) {
				c[i][j] = sb[i + x - 1][j] - sb[i - 1][j];
			}
		}

		int maxnn = 0;
		for (int i = 1; i + x - 1 <= m; i++) {
			for (int j = 1; j + y - 1 <= n; j++) {
				maxnn = max(c[i][j], maxnn);
			}
		}
		printf("%d\n", maxnn);
	}
	return 0;
}