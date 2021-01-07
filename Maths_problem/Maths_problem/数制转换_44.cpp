#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 40
int main() {
	int a, b;
	char n[MAXSIZE];
	while (scanf("%d %s %d", &a, n, &b) != EOF) {
		int tmp = 0; //ת���ɵ�ʮ������
		int n_len;
		int weight = 0;
		n_len = strlen(n); // ��ת������λ��

		// ת����ʮ����
		for (int i = n_len - 1; i >= 0; i--) {//�����λ��ʼ�� 
			if (n[i] >= '0' && n[i] <= '9') { //��λΪ����
				tmp += (n[i] - '0') * pow(a, weight); // ע������Ҫ����'0' ��Ϊ�ǰ�����Ҳ�����ַ�������	
			}
			else if (n[i] >= 'A' && n[i] <= 'F') { //��λ�Ǵ�A��F
				tmp += (n[i] - 'A' + 10) * pow(a, weight);
			}
			else {
				tmp += (n[i] - 'a' + 10) * pow(a, weight);
			}
			weight++;
		}

		char res[MAXSIZE];
		int k = 0;
		// ʮ����ת���ɳ�ָ������
		do {
			if(tmp % b >= 10){
				res[k] = tmp % b - 10 + 'A';
			}
			else {
				res[k] = tmp % b + '0'; // ע������Ҫ����'0' ��Ϊ�ǰ�����Ҳ�����ַ�������			
			}
			tmp = tmp / b;
			k++;
		} while (tmp != 0);

		for (int p = k - 1; p >= 0; p--) {
			printf("%c", res[p]);
		}
		printf("\n");
	}
	return 0;
}