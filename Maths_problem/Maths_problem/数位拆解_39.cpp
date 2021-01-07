#include<stdio.h>
#include<math.h>
#define MAXSIZE 10
int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		int buf1[MAXSIZE], buf2[MAXSIZE]; //存放拆解后的数字数组
		int i, j; // i,j表示数字数组索引
		i = j = 0;
		int ans = 0;
		while (m != 0) { 
			buf1[i] = m % 10; //余数存放
			m = m / 10; //累除
			i++;
		}
		while (n != 0) {
			buf2[j] = n % 10;
			n = n / 10;
			j++;
		} //得到两个数组

		for (int k = 0; k < i; k++) {
			for (int t = 0; t < j; t++) {
				ans += buf1[k] * buf2[t];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}