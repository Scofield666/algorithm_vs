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
int l[maxns], r[maxns];//����/������չ������Զλ���±�
stack<int>s; //��ΪҪ�ҵ���/�ұߵ�һ��С�ڸ�����λ�� �����ǵ�������ջ
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

		//1.���������չ�������λ�� ������ߵ�һ��С�ڸ�����λ��
		for (int i = 0; i < n; i++) {
			while (!s.empty() && h[s.top()] >= h[i]) s.pop();
			if (s.empty()) l[i] = 0;
			else l[i] = s.top() + 1;
			s.push(i);
		}
		while (!s.empty()) s.pop();
		//2.���ұ�����չ�������λ�� �����ұߵ�һ��С�ڸ�����λ��
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