#include<stdio.h>
#include<math.h>
#define MAXSIZE 10
int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		int buf1[MAXSIZE], buf2[MAXSIZE]; //��Ų������������
		int i, j; // i,j��ʾ������������
		i = j = 0;
		int ans = 0;
		while (m != 0) { 
			buf1[i] = m % 10; //�������
			m = m / 10; //�۳�
			i++;
		}
		while (n != 0) {
			buf2[j] = n % 10;
			n = n / 10;
			j++;
		} //�õ���������

		for (int k = 0; k < i; k++) {
			for (int t = 0; t < j; t++) {
				ans += buf1[k] * buf2[t];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}