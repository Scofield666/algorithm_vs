#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
const int maxns = 1e6 + 10, inf = 0x3f3f3f3f;
//筛选出1e6内所有素数
int prime[maxns];
int pcnt = 0;
bool mark[maxns];
void sushai() {
	memset(mark, true, sizeof(mark));
	for (int i = 2; i < maxns; i++) {
		if (mark[i] == false) continue;
		prime[pcnt++] = i;
		for (int j = i + i; j < maxns; j += i) {
			mark[j] = false;
		}
	}
	mark[0] = mark[1] = false;
}

int a[maxns]; //存放区间值
bool isprime[maxns]; //区间值是否为素数 和a对应
int finalprime[maxns];
int fcnt = 0;
int main() {
	int l, r;
	sushai();
	while (scanf("%d%d", &l, &r) != EOF) {
		for (int i = l; i <= r; i++) {
			a[i - l] = i;
		}
		memset(isprime, true, sizeof(isprime));
		for (int i = 0; i < pcnt; i++) {
			if (prime[i] > r) break;
			int currentp = prime[i];
			int start = l / currentp * currentp; //找到第一个在区间内的倍数的位置
			start = max(start,currentp);
			//倍数做标记
			for (int j = start; j <= r; j += currentp) {
				if (j < l || j == currentp) continue;
				isprime[j - l] = false; //对应位置做上标记
			}
		}

		fcnt = 0;
		for (int i = l; i <= r; i++) {
			if (isprime[i - l] == true) finalprime[fcnt++] = i;
		}

		int minn = inf;
		int maxn = 0;
		int minl, minr;
		int maxl, maxr;
		for (int i = 0; i < fcnt - 1; i++) {
			if (finalprime[i + 1] - finalprime[i] < minn) {
				minl = finalprime[i];
				minr = finalprime[i + 1];
				minn = finalprime[i + 1] - finalprime[i];
			}
			if (finalprime[i + 1] - finalprime[i] > maxn) {
				maxl = finalprime[i];
				maxr = finalprime[i + 1];
				maxn = finalprime[i + 1] - finalprime[i];
			}
		}
		if(fcnt > 1) printf("%d,%d are closest, %d,%d are most distant.\n", minl, minr, maxl, maxr);
		else printf("There are no adjacent primes.\n");
	}
	return 0;
	
}