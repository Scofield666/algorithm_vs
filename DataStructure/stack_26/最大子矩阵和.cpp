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
	求不给定维度的和最大的子矩阵
	思路：先压缩到一维上，即求一个连续子序列 使得其和最大 这个可以用dp做
	扩展到二维 一半就会变成n次一维的操作 枚举行区间 固定两行 两行之间每个列的元素和可以用前缀和计算
*/
using namespace std;
const int maxns = 101;
int mat[maxns][maxns];
int sum[maxns][maxns];
int n;
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		//计算列的前缀和
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = sum[i - 1][j] + mat[i][j];
			}
		}

		int maxn = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++) { //选取两行
				int tmp = sum[j][1] - sum[i][1];
				int tmpmax = tmp; //记录当前行的子序列和的最大值
				for (int k = 2; k <= n; k++) {
					tmp = max(tmp + sum[j][k] - sum[i][k], sum[j][k] - sum[i][k]);
					tmpmax = max(tmp, tmpmax);
				}
				maxn = max(maxn, tmpmax);
			}
		}
		printf("%d\n", maxn);
	}
	return 0;
}