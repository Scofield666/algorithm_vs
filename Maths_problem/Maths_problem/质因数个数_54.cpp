#include<stdio.h>
#define MAXSIZE 100001 // 10的九次方开根号
int prime[MAXSIZE];
int primesize=0;
int flags[MAXSIZE];
//素数筛法
void init() {
	for (int i = 1; i < MAXSIZE; i++) {
		flags[i] = 0;//初始化为0 0代表为素数
	}
	for (int j = 2; j < MAXSIZE; j++) {
		if (flags[j] == 0) {//如果是素数，那么加入素数数组
			prime[primesize] = j;
			primesize++;
			if (j >= 1000) continue; //不加的话会导致k太大 溢出！！！
			for (int k = j * j; k < MAXSIZE; k += j) {//把素数的倍数筛出去
				flags[k] = 1;
			}
		}
		else continue; //如果不是素数
	}
}
int main() {
	init();
	int n; //待分解的数
	while (scanf("%d", &n) != EOF) {
		int j=0;//素数数组索引
		int ans_prime_size[30] = { 0 }; // 保存每个素因数的次数
		int ans_prime[30]; // 素因数数组
		int ans_idx = 0;
		for (j = 0; j < MAXSIZE; j++) {
			if (n % prime[j] == 0) {
				ans_prime[ans_idx] = prime[j];//如果是素因子，加入ans_prime数组
				ans_prime_size[ans_idx]++;
				n = n / prime[j]; //除掉这个素因数
				while (n%prime[j] == 0) {//如果还能整除这个素因子
					ans_prime_size[ans_idx]++;
					n = n / prime[j];
				}				
				ans_idx++;
				if (n == 1) break; //n为1 分解成了1
			}
		}
		if (n != 1) { //如果还没被分解成1， 说明2-100000之间的素数没有满足条件的 只存在一个大于100000的素数
			ans_prime[ans_idx] = n;
			ans_prime_size[ans_idx] = 1;
		}

		int ans = 0;
		for (int m = 0; m <= ans_idx; m++) {
			ans += ans_prime_size[m];
		}
		printf("%d\n", ans);
	}
	return 0;
}