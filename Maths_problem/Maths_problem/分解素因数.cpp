#include<bits/stdc++.h>
using namespace std;
const int maxns = 1e5 + 1;
int prime[maxns];
int primesize = 0;
bool mark[maxns];
void init() {
	memset(mark, true, sizeof(mark));
	for (int i = 2; i < maxns; i++) {
		if (mark[i] == false) continue;
		prime[primesize++] = i;
		if (i >= 1000) continue; //超出索引范围了，而且这么后面已经被标记过了
		for (int j = i * i; j < maxns; j += i) {
			mark[j] = false;
		}
	}
}
int n;
int ansprime[maxns]; //n的素因数
int ansize = 0;
int ansnum[maxns]; //素因数的次数
int main() {
	init();
	while (scanf("%d", &n) != EOF) {
		memset(ansnum, 0, sizeof(ansnum));
		memset(ansprime, 0, sizeof(ansprime));
		for (int i = 0; i < primesize; i++) {
			if (n%prime[i] == 0) {
				ansprime[ansize] = prime[i];
				while (n%prime[i] == 0) {
					ansnum[ansize]++;
					n /= prime[i];
				}
				ansize++;
			}
			if (n == 1) break; //提前分解完
		}
		//没有分解完的 是大于100000的素数是本身
		if (n != 1) {
			ansprime[ansize] = n;
			ansnum[ansize] = 1;
			ansize++;
		}
		int ans = 0;
		for (int i = 0; i < ansize; i++) {
			ans += ansnum[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}