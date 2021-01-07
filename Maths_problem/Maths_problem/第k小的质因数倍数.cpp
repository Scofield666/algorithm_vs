#include<bits/stdc++.h>
using namespace std;
const int maxns = 100;
int prime[maxns]; //给定素数集合
priority_queue<int, vector<int>, greater<int>>q; //小根堆
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
			if (last == now) continue;//这次取出的和上次的一样 不再操作 直接下一个

			//判断完毕的后续操作 计数 更新状态 状态转移
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