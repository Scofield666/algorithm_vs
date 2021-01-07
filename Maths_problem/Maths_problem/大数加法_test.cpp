#include<stdio.h>
#include<string.h>
struct biginteger {
	int digit[1000]; //4个一组，从低位到高位存放
	int size;//存放已经利用的digit的数组长度

	//初始化 所有digit为0，size为0表示没有利用
	void init() {
		for (int i = 0; i < 1000; i++) {
			digit[i] = 0;	
		}
		size = 0;
	}

	void set(char str[]) {
		int l = strlen(str);
		int weight = 1; //累加的权重
		int cnt = 0; //控制四位计数，从0开始加到4刚好4个操作
		int tmp = 0;//存放累加的中间值
		for (int i = l - 1; i >= 0; i--) {
			tmp += (str[i] - '0') * weight;
			cnt++;
			weight *= 10;
			if (cnt % 4 == 0 || i==0) {
				digit[size] = tmp;
				cnt = 0;
				weight = 1;
				tmp = 0;
				size++;
			}
		}
	}

	void output() {
		for (int i = size - 1; i >= 0; i--) {
			if (i != size - 1) {//不是首位
				printf("%04d", digit[i]);
			}
			else printf("%d", digit[i]);
		}
		printf("\n");
	}

	biginteger operator + (const biginteger &A) const{
		biginteger res;
		res.init();
		int carry = 0;
		int tmp = 0;
		for (int i = 0; i < A.size || i< size; i++) {
			tmp = A.digit[i] + digit[i] + carry;
			res.digit[res.size] = tmp % 10000;
			carry = tmp / 10000;
			res.size++;
		}
		if (carry != 0) {
			res.digit[res.size] = carry;
			res.size++;
		}
		return res;
	}
};
char str1[1001], str2[1001];
int main() {

	biginteger a, b, c;
	while (scanf("%s%s", str1, str2) != EOF) {
		a.init(); b.init(); c.init();
		a.set(str1); b.set(str2);
		c = a + b;
		c.output();
	}
	return 0;
}