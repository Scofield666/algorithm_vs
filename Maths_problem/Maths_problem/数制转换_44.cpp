#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 40
int main() {
	int a, b;
	char n[MAXSIZE];
	while (scanf("%d %s %d", &a, n, &b) != EOF) {
		int tmp = 0; //转换成的十进制数
		int n_len;
		int weight = 0;
		n_len = strlen(n); // 待转整数的位数

		// 转换成十进制
		for (int i = n_len - 1; i >= 0; i--) {//从最低位开始算 
			if (n[i] >= '0' && n[i] <= '9') { //该位为数字
				tmp += (n[i] - '0') * pow(a, weight); // 注意这里要加上'0' 因为是把数字也当成字符处理了	
			}
			else if (n[i] >= 'A' && n[i] <= 'F') { //该位是从A到F
				tmp += (n[i] - 'A' + 10) * pow(a, weight);
			}
			else {
				tmp += (n[i] - 'a' + 10) * pow(a, weight);
			}
			weight++;
		}

		char res[MAXSIZE];
		int k = 0;
		// 十进制转换成成指定进制
		do {
			if(tmp % b >= 10){
				res[k] = tmp % b - 10 + 'A';
			}
			else {
				res[k] = tmp % b + '0'; // 注意这里要加上'0' 因为是把数字也当成字符处理了			
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