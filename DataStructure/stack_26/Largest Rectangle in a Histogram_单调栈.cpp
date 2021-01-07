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
typedef long long ll;
using namespace std;
const int maxns = 1e5 + 10, inf = 0x3f3f3f3f;
int l[maxns], r[maxns];//往左/右能扩展到的最远位置下标
stack<int>s; //因为要找到左/右边第一个小于该数的位置 所以是单调递增栈
int h[maxns];
int n;
int main() {
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &h[i]);
		}

		while (!s.empty()) s.pop();
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));

		//1.找左边能扩展到的最大位置 即找左边第一个小于该数的位置
		for (int i = 0; i < n; i++) {
			while (!s.empty() && h[s.top()] >= h[i]) s.pop();
			if (s.empty()) l[i] = 0;
			else l[i] = s.top() + 1;
			s.push(i);
		}
		while (!s.empty()) s.pop();
		//2.找右边能扩展到的最大位置 即找右边第一个小于该数的位置
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() && h[s.top()] >= h[i]) s.pop();
			if (s.empty()) r[i] = n - 1;
			else r[i] = s.top() - 1;
			s.push(i);
		}

		ll maxnn = 0;
		for (int i = 0; i < n; i++) {
			ll len = r[i] - l[i] + 1;
			maxnn = max(len*h[i], maxnn);
		}
		printf("%lld\n", maxnn);
	}
	return 0;
}