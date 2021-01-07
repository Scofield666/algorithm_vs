#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
const int maxns = 1e6 + 10;
int prime[maxns];
int cnt = 0;
bool mark[maxns];
void shai() {
	memset(mark, true, sizeof(mark));
	for (int i = 2; i <= 1e6; i++) {
		if (mark[i] == false) continue;
		prime[cnt++] = i;
		for (int j = 2 * i; j <= 1e6; j += i) {
			mark[j] = false;
		}
	}
	mark[0] = mark[1] = false;
}
int digit[30];//每位都是四位数
int dsize = 0;
void set(char a[]) {
	int len = strlen(a);
	int cnt = 0;
	int tmp = 0;
	int weight = 1;
	for (int i = len - 1; i >= 0; i--) {
		tmp = tmp + (a[i] - '0') * weight;
		weight *= 10;
		cnt++;
		if (cnt == 4) {
			digit[dsize++] = tmp;
			tmp = 0;
			weight = 1;
			cnt = 0;
		}
	}
	if (cnt) digit[dsize++] = tmp;
}
long long mod2(int d[], int x, int len) {
	long long ret = 0;
	for (int i = len - 1; i >= 0; i--) {
		ret = (ret * 10000 + d[i]) % x; //用longlong 防止超精度
	}
	return ret;
}
int mod(char a[], int x, int len) {
	int ret = 0;
	for (int i = 0; i < len; i++) {
		ret = (ret * 10 + a[i] - '0') % x;
	}
	return ret;
}
char s[105];
int l;
int main() {
	shai();
	while (scanf("%s %d",s,&l)!=EOF) {
		if (strcmp(s,"0") == 0 && l == 0) break;
		memset(digit, 0, sizeof(digit));
		dsize = 0;
		set(s);
		bool flag = false;
		int p = 0;
		for (int i = 0; i < cnt; i++) {
			if (prime[i] >= l) break;
			if (mod2(digit, prime[i], dsize) == 0) {
				flag = true;
				p = prime[i];
				break;
			}
		}
		if (flag) printf("BAD %d\n", p);
		else printf("GOOD\n");
	}
	return 0;
}

