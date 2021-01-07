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
using namespace std;
const int maxns = 1e6 + 10;
/*
	找给定区间长度下的最值
	最小：单调递增
	最大：单调递减
*/
deque<int>dq1; //找最小
deque<int>dq2;//找最大
int n, k;
int a[maxns];
int main() {
	while (scanf("%d%d", &n, &k) != EOF) {
		dq1.clear();
		dq2.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		//找区间内最小值
		for (int i = 0; i < n; i++) {
			while (!dq1.empty() && a[dq1.back()] >= a[i]) dq1.pop_back(); //维护递增队列
			dq1.push_back(i);
			if (i >= k - 1) { //当大于区间长度时就需要判断当前头是否还在区间内
				while (!dq1.empty() && dq1.front() <= i - k) dq1.pop_front();
				if(i != n - 1) printf("%d ", a[dq1.front()]);
				else printf("%d\n", a[dq1.front()]);
			}
		}
		//找区间内最大值
		for (int i = 0; i < n; i++) {
			while (!dq2.empty() && a[dq2.back()] <= a[i]) dq2.pop_back(); //维护递减队列
			dq2.push_back(i);
			if (i >= k - 1) { //当大于区间长度时就需要判断当前头是否还在区间内
				while (!dq2.empty() && dq2.front() <= i - k) dq2.pop_front();
				if (i != n - 1) printf("%d ", a[dq2.front()]);
				else printf("%d\n", a[dq2.front()]);
			}
		}
	}
	return 0;
}