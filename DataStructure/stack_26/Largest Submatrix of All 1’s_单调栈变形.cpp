#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<string.h>
#include<math.h>
/* 单调栈应用2：求最大的全1矩阵的面积 */
using namespace std;
const int maxns = 2001;
int mat[maxns][maxns];
int m, n;
int l[maxns], r[maxns]; //固定一行，该数往左/右能扩展到的最远位置
stack<int>s;
int main() {
	while (scanf("%d%d", &m, &n) != EOF) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 1) mat[i][j] = mat[i - 1][j] + 1;
			}
		}

		int ans = 0;
		for (int i = 0; i < m; i++) {
			//对每一行都计算出最大直方图面积
			while (!s.empty()) s.pop();
			memset(l, 0, sizeof(l));
			memset(r, 0, sizeof(r));

			for (int j = 0; j < n; j++) {
				while (!s.empty() && mat[i][j] <= mat[i][s.top()]) s.pop();
				if (s.empty()) l[j] = 0;
				else l[j] = s.top() + 1;
				s.push(j);
			}
			while (!s.empty()) s.pop();
			for (int j = n - 1; j >= 0; j--) {
				while (!s.empty() && mat[i][j] <= mat[i][s.top()]) s.pop();
				if (s.empty()) r[j] = n - 1;
				else r[j] = s.top() - 1;
				s.push(j);
			}

			int maxnn = 0;
			for (int j = 0; j < n; j++) {
				int len = r[j] - l[j] + 1;
				maxnn = max(maxnn, len*mat[i][j]);
			}
			ans = max(ans, maxnn);
		}
		printf("%d\n", ans);
	}
	return 0;
}