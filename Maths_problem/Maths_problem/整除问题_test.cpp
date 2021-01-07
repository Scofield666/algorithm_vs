#include<stdio.h>
#include<math.h>
int min(int x, int y) {
	return x < y ? x : y;
}
int primesize;
int prime[1001];
int mark[1001];
int ansnum1[1001];
int ansnum2[1001];
void init() {//找1000以内所有的素数
	for (int i = 1; i <= 1000; i++) {
		mark[i] = 0;
	}
	primesize = 0;
	for (int i = 2; i <= 1000; i++) {
		if (mark[i] == 1)
			continue;
		primesize++;
		prime[primesize] = i;
		for (int j = i * i; j <= 1000; j += i) {
			mark[j] = 1;
		}
	}
}

int main() {
	int n;
	int a;
	init();
	while (scanf("%d%d", &n, &a) != EOF) {
		for (int i = 1; i <= primesize; i++) {
			ansnum1[i] = ansnum2[i] = 0; //所有素数的次数都存放为0
		}

		for (int i = 1; i <= primesize; i++) { //对a分解素因数
			if (a%prime[i] == 0) {
				while (a%prime[i] == 0) {
					ansnum1[i]++;
					a = a / prime[i];
				}
			}
		}

		for (int i = 1; i <= primesize; i++) {
			int time = 1;
			while (n / pow(prime[i], time) != 0) {
				ansnum2[i] += n / pow(prime[i], time);
				time++;
			}
		}

		int k=1000;
		for (int i = 1; i <= primesize; i++) {
			if (ansnum1[i] == 0)
				continue;
			else {
				k = min(k, ansnum2[i] / ansnum1[i]);
			}
		}

		printf("%d\n", k);
	}
	


}