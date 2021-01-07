#include<stdio.h>
int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		if (a == 0 && b == 0) break;
		a = a % 1000;
		int ans = 1;
		for (int i = 0; i < b; i++) {
			ans = ans * a;
			ans = ans % 1000; //都只保留后三位进行运算
		}
		printf("%d\n", ans);
	}
	return 0;
}