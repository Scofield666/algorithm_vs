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
	�󲻸���ά�ȵĺ������Ӿ���
	˼·����ѹ����һά�ϣ�����һ������������ ʹ�������� ���������dp��
	��չ����ά һ��ͻ���n��һά�Ĳ��� ö�������� �̶����� ����֮��ÿ���е�Ԫ�غͿ�����ǰ׺�ͼ���
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
		//�����е�ǰ׺��
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = sum[i - 1][j] + mat[i][j];
			}
		}

		int maxn = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++) { //ѡȡ����
				int tmp = sum[j][1] - sum[i][1];
				int tmpmax = tmp; //��¼��ǰ�е������к͵����ֵ
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