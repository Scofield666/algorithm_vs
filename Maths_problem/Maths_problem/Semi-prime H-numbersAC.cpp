#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
const int maxns = 1e6 + 10;
int hprime[maxns];
bool mark[maxns];
int pcnt = 0;
//筛1e6+1内所有满足条件的hprime
void init() {
	memset(mark, true, sizeof(mark));
	for (int i = 5; i < maxns; i += 4) {
		if (mark[i] == false) continue;
		hprime[pcnt++] = i;
		for (int j = 2 * i; j < maxns; j += i) {
			mark[j] = false;
		}
	}
}
//得到hprime之后，筛选出 两个hprime相乘的semi-prime
bool vis[maxns];
int ans = 0;
void shai() {
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < pcnt ; i++) {
		for (int j = 0; j < pcnt; j++) {
			if (hprime[i] * hprime[j] > maxns) break;
			int s = hprime[i] * hprime[j];
			vis[s] = true;
		}
	}
}

int main() {
	int h;
	init();
	shai();
	while (scanf("%d", &h) != EOF) {
		if (h == 0) break;
		int ans = 0;
		for (int i = 5; i < maxns; i += 4) {
			if (i > h) break;
			if (vis[i] == true) ans++;
		}
		printf("%d %d\n", h, ans);
	}
	return 0;
}
