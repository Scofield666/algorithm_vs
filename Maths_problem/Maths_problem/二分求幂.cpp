#include<stdio.h>
int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		int ans=1;
		while (b != 0) {//a^10 = 0*(a^1) * 1*(a^2) * 0*(a^4) * 1*(a^8)
			if (b % 2 == 1) {//�����ӿ�֪����ǰ������λΪ1����ϵ����Ϊ0����Ҫ���������
				ans = ans * a; //aΪ��ǰ��Ȩ�� a a^2 a^4...
				ans = ans % 1000;
			}
			b = b / 2;
			a = a * a;
			a = a % 1000;
		}
		printf("%d\n", ans);
	}
	return 0;
}