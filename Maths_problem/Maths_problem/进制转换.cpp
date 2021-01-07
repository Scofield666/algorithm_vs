#include<bits/stdc++.h>
using namespace std;
const int maxns = 101, inf = 0x3f3f3f3f;
char num[maxns];
char ans[maxns];
int a, b;
int main() {
	while (scanf("%d%s%d", &a, num, &b) != EOF) {
		memset(ans, 0, sizeof(ans));
		int len = strlen(num);
		int n = 0;
		int weight = 1;
		int cur = 0;
		//转换为十进制
		for (int i = len - 1; i >= 0; i--) {
			if (num[i] <= '9' && num[i] >= '0') {
				cur = num[i] - '0';
			}
			else if (num[i] <= 'Z' && num[i] >= 'A') {
				cur = num[i] - 'A' + 10;
			}
			else if (num[i] <= 'z' && num[i] >= 'a') {
				cur = num[i] - 'a' + 10;
			}
			n += weight * cur;
			weight *= a;
		}

		int cnt = 0;
		if (n == 0) {
			printf("0\n");
			continue;
		}
		while (n != 0) {
			if (n % b >= 10) {
				ans[cnt++] = n % b - 10 + 'A';
			}
			else ans[cnt++] = n % b + '0';
			n = n / b;
		}

		for (int i = cnt - 1; i >= 0; i--) {
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	return 0;
}