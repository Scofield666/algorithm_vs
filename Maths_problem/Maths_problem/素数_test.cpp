#include<bits/stdc++.h>
using namespace std;
const int maxns = 10001;
bool num[maxns]; //true为素数，false不为素数
int prime[maxns];
int cnt = 0;
int n;
void shai() {
	memset(num, true, sizeof(num));
	for (int i = 2; i < maxns; i++) {
		if (num[i] == false) continue;
		prime[cnt++] = i;	
		for (int j = i * i; j < maxns; j += i) {
			num[j] = false;
		}
	}
}
int main() {
	shai();
	while (scanf("%d", &n) != EOF) {
		for (int i = 2; i <= n; i++) {
			if (num[i] == true && i % 10 == 1) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}