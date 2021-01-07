#include<stdio.h>
int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		int ans = 1;
		if (a == 0 && b == 0) break;
		while (b != 0) {// 一边计算b的二进制值，一边计算a的2^k次，并将需要的部分累乘到变量ans上
			if (b % 2 != 0) {//当前二进制位为1
				ans = ans * a;
				ans = ans % 1000; // 每次只取最后三位数进行运算即可
			}
			a = a * a; //每次二进制移位，都要权重更新
			a = a % 1000;
			b = b / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}