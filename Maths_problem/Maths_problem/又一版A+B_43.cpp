#include<stdio.h>
#define MAX_SIZE 50
int main() {
	int m; //scale
	long long a, b; // 64 bit 8 bytes ��ֹ���
	long long sum;
	int ans[MAX_SIZE]; // result
	int i = 0; // len of ans
	while (scanf("%d", &m) != EOF) { // ����ע��һ�� ��Ϊm�Ƿ�Ϊ0�����Ƿ��˳������Խ�����Ϊ�ж����� ����һ��
		if (m != 0) {
			scanf("%lld%lld", &a, &b);
		}
		else break;
		sum = a + b;
		do { // ������dowhile��Ŀ���Ǳ�֤ѭ��������ִ��һ�Σ� ���Ե�sum��0��ʱ��Ҳ����ִ��
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