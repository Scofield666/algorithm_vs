#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int mod = 9901, maxns = 1e4+10;
int x, y;
int p[maxns];
int pcnt = 0;
int c[maxns];
//分解质因数 并且把次数存放在c中
void calcfac(int n) {
	pcnt = 0;
	memset(p, 0, sizeof(p));
	memset(c, 0, sizeof(c));
	for (int i = 2; i < sqrt(n) + 1; i++) {
		if (n%i == 0) {
			p[pcnt] = i;
			while (n%i == 0) {
				c[pcnt]++;
				n /= i;
			}
			pcnt++;
			if (n == 1) break;
		}
	}
	if (n != 1) {
		p[pcnt] = n;
		c[pcnt]++;
		pcnt++;
	}
}
ll quickpow(ll a, ll b) {
	ll ret = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			ret = ret * a;
			ret = ret % mod;
		}
		b /= 2;
		a = a * a;
		a = a % mod;
	}
	return ret;

}
//求公比为p 项数为c+1的等比数列的和
ll sum(ll p, ll c) {
	if (p == 0) return 0;
	if (c == 0) return 1;
	if (c % 2 == 1) { //1---p^c共有c+1项
		return ((1 + quickpow(p, (c + 1) / 2) % mod) * (sum(p, (c - 1) / 2) % mod))%mod;
	}
	else return ((1 + quickpow(p, c / 2) % mod) * (sum(p, (c - 2) / 2)) % mod + quickpow(p, c) % mod)%mod;
}
int main() {
	while (scanf("%d%d", &x, &y) != EOF) {
		calcfac(x);
		int ans = 1;
		for (int i = 0; i < pcnt; i++) {
			ans = ans * (sum(p[i], c[i] * y) % mod);
			ans = ans % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
