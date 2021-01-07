#include<stdio.h>
#include<math.h>
#define MAXSIZE 10000
int primenum = 0;
int prime[MAXSIZE]; //存放素数
int flags[MAXSIZE + 1]; 
// 0代表为素数 1代表不为素数 
// 注意这里初始化的长度 是为了比较方便的存储 例如flags[1]就代表了1是否为素数
//一定要是全局变量
void init() {
	for (int i = 1; i < MAXSIZE + 1; i++) {
		flags[i] = 0; //首先初始化为0 先认为1-10000都是素数
	}

	for (int j = 2; j < MAXSIZE + 1; j++) { // 素数筛法 从2开始
		if (flags[j] == 1) // 如果该数是某数的倍数 说明不是素数 则筛选下一个数
			continue;
		else {
			prime[primenum] = j;
			primenum++; 
			for (int k = j * j; k < MAXSIZE + 1; k+=j) {
				flags[k] = 1;//倍数不是素数
			}
		}
	}
}
int main() {
	init();
	int bound; 

	while (scanf("%d", &bound) != EOF) {
		bool firstout = true; //当前输出是第一个输出 注意一定要放到循环里面！！
		int m = 0; //局部变量！！ 每个数都要从头开始！！
		while (prime[m] < bound ) {
			if (prime[m] % 10 == 1 ) {//末尾为1
				if (firstout == true) {
					printf("%d", prime[m]);
					firstout = false;
				}
				else {
					printf(" %d", prime[m]);
				}
			}
			m++;
		}

		if (firstout == true) {//如果还为true的话说明没改过 也就是没有进入循环找到满足条件的
			printf("-1\n");
		}
		else printf("\n");
	}
	return 0;
}