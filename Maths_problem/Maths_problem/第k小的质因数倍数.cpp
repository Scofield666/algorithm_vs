#include<bits/stdc++.h>
using namespace std;
const int maxns = 100;
int prime[maxns]; //������������
priority_queue<int, vector<int>, greater<int>>q; //С����
int n;
int main() {
	int k;
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &prime[i]);
		}

		while (!q.empty()) q.pop();
		for (int i = 0; i < n; i++) {
			q.push(prime[i]);
		}
		
		int last = -1;
		int cnt = 0;
		int now = -1;
		while (!q.empty()) {
			now = q.top();
			q.pop();
			if (last == now) continue;//���ȡ���ĺ��ϴε�һ�� ���ٲ��� ֱ����һ��

			//�ж���ϵĺ������� ���� ����״̬ ״̬ת��
			cnt++; 
			last = now;
			if (cnt == k) break;
			for (int i = 0; i < n; i++) {
				q.push(now*prime[i]);
			}
		}
		printf("%d\n", now);
	}
}