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
using namespace std;
/* ����ջӦ��3����һ�������У�������е���Сֵ���������������ĺ͵ĳ˻���� 
	���г��Ȳ��������������������ֵ
	���赱ǰ������Сֵ ��ô��ȥ���������---���������� Ҳ����ȥ�����ֵ��������չ������Զλ��
*/
typedef long long ll;
const int maxns = 1e5 + 10;
int a[maxns];
ll sum[maxns];
int l[maxns], r[maxns];
stack<int>s;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}

		while (!s.empty()) s.pop();
		for (int i = 1; i <= n; i++) {
			while (!s.empty() && a[s.top()] >= a[i]) s.pop();
			if (s.empty()) l[i] = 1;
			else l[i] = s.top() + 1;
			s.push(i);
		}
		while (!s.empty()) s.pop();
		for (int i = n; i >= 1; i--) {
			while (!s.empty() && a[s.top()] >= a[i]) s.pop();
			if (s.empty()) r[i] = n;
			else r[i] = s.top() - 1;
			s.push(i);
		}

		ll maxnn = 0;
		int maxl, maxr;
		maxl = maxr = 1;
		for (int i = 1; i <= n; i++) {
			ll s = sum[r[i]] - sum[l[i] - 1];
			if (maxnn < a[i] * s) { //a[i]��Ϊ��ǰ�������Сֵ
				maxnn = a[i] * s;
				maxl = l[i];
				maxr = r[i];
			}
		}
		printf("%lld\n", maxnn);
		printf("%d %d\n", maxl, maxr);
	}
	return 0;
}