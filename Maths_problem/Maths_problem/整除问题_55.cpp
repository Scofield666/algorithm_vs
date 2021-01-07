#include<stdio.h>
#include<math.h>
int prime[1000];//1-1000内所有的素数
int primesize=0;// 1-1000内所有的素数个数
int flags[1001];

void init() { // 筛选出1000以内所有的素数，为什么是1000以内?因为n阶乘的素因数一定小于n
	for (int i = 1; i < 1001; i++) {
		flags[i] = 0;
	}
	for (int i = 2; i < 1001; i++) {
		if (flags[i] == 1)
			continue;
		else {
			prime[primesize] = i;
			primesize++;
			for (int j = i * i; j < 1001; j+=i) {
				flags[j] = 1;
			}
		}
	}
}

int main() {
	init();
	int a, n;
	while (scanf("%d%d", &n, &a) != EOF) {
		int a_prime_size[1001]; //小于n的素数在a中的次数，可能为0
		int n_prime_size[1001]; //小于n的素数在n阶乘中的次数，可能为0

		for (int i = 0; i < primesize; i++) {
			a_prime_size[i] = n_prime_size[i] = 0;//先把次数都置为0
		}
		//先求所有素数在a中的次数
		//int size = 0;
		for (int i = 0; i < primesize; i++) {
			if (a%prime[i] == 0) { // 如果能被该素数整除，说明为一个素因数
				a_prime_size[i]++;
				a = a / prime[i];
				while (a%prime[i] == 0) {
					a_prime_size[i]++;
					a = a / prime[i];
				}
				if (a == 1) break;
			}
			else continue;
		}

		//再求所有素数在n阶乘中的次数
		for (int i = 0; i < primesize; i++) {
			int j = 1;
			int m = pow(prime[i], j);
			while (n / m != 0) {
				n_prime_size[i] += n / pow(prime[i], j);
				j++;
				m = pow(prime[i], j);
			}
		}
		//计算每个素数对应次数的除数
		int k=123123132;//随便取一个大整数，为取最小值做准备
		int tmp;
		for (int i = 0; i < primesize; i++) {
			if (a_prime_size[i] == 0) {
				//k = n_prime_size[i];
				continue;
			}
			tmp = n_prime_size[i] / a_prime_size[i];
			if (tmp <= k) {
				k = tmp;
			}
		}
		printf("%d\n", k);
	}
	return 0;
}