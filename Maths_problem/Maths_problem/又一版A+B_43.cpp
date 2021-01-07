#include<stdio.h>
#define MAX_SIZE 50
int main() {
	int m; //scale
	long long a, b; // 64 bit 8 bytes 防止溢出
	long long sum;
	int ans[MAX_SIZE]; // result
	int i = 0; // len of ans
	while (scanf("%d", &m) != EOF) { // 这里注意一下 因为m是否为0决定是否退出，所以将其作为判断条件 而非一行
		if (m != 0) {
			scanf("%lld%lld", &a, &b);
		}
		else break;
		sum = a + b;
		do { // 这里用dowhile的目的是保证循环体至少执行一次， 所以当sum是0的时候也可以执行
			ans[i] = sum % m;
			sum = sum / m;
			i++;
		} while (sum != 0);

		for (int j = i - 1; j >= 0; j--) {
			printf("%d", ans[j]);
		}
		printf("\n");
	}

	return 0;
}