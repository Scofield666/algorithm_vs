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
	�������� ��̶����䳤������������к�
	ʹ��ǰ׺�� �̶��Ҹ� ��ǰ����������С��ǰ׺��
	ע��ѹջ˳�� ����ѹsum[0] ѭ���������㵱ǰ�Ľ�� �ٰѵ�ǰֵѹ��ȥ
*/
using namespace std;
const int maxns = 1e5 + 10, inf = 0x3f3f3f3f;
int a[maxns];
int sum[maxns * 2];
int t, n, k;
deque<int>dq;
int main() {
	scanf("%d", &t);
	while (t--) {
		dq.clear();
		scanf("%d%d", &n, &k);
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <=  2 * n; i++) {
			if (i == n || i == 2 * n) sum[i] = sum[i - 1] + a[n];
			else sum[i] = sum[i - 1] + a[i%n];
		}
		int maxnn = -inf;
		int maxl = 0;
		int maxr = 0;

		dq.push_back(0); //����ѹ��ȥ
		for (int i = 1; i <= n + k; i++) {
			//��ȡ��� �ٰѵ�ǰֵѹ��ȥ
			while (!dq.empty() && dq.front() <= i - k - 1) dq.pop_front();
			int c = sum[i] - sum[dq.front()];
			if (maxnn < c) {
				maxnn = c;
				maxl = dq.front() + 1;
				maxr = i;
				if (maxl > n) maxl = maxl - n;
				if (maxr > n) maxr = maxr - n;
			}
			while (!dq.empty() && sum[dq.back()] >= sum[i]) dq.pop_back(); //ά����������
			dq.push_back(i);
		}
		printf("%d %d %d\n", maxnn, maxl, maxr);
	}
	return 0;
}