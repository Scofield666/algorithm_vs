#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxns = 1000; 
int prime[maxns];
int cnt = 0;
int num[maxns];//ad质因数的对应次数
void calfac(int a) {
	for (int i = 2; i < sqrt(a)+1; i++) {
		if (a%i == 0) {
			prime[cnt] = i;
			while (a%i == 0) {
				num[cnt]++;
				a /= i;
			}
			cnt++;
			if (a == 1) break;
		}
	}
	if (a != 1) {
		prime[cnt] = a;
		num[cnt] = 1;
		cnt++;
	}
}
int main() {
	int a, b;
	cin >> a >> b;
	calfac(a);
	ll ans = 1;
	for (int i = 0; i < cnt; i++) {
		ans = ans * (num[i] * b + 1);
	}
	printf("%lld\n", ans);
	return 0;
}