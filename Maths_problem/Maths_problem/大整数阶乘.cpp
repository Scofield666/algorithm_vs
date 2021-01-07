#include<stdio.h>
struct bigInteger {
	int digit[1000];
	int size;
	
	void init() {
		for (int i = 0; i < 1000; i++) {
			digit[i] = 0;
			size = 0;
		}
	}

	//用小整数 初始化该大整数
	void set(int x) {
		init();
		do {
			digit[size] = x % 10000;
			x = x / 10000;
			size++;
		} while (x != 0);
	}

	void output() {
		for (int i = size-1; i >= 0; i--) {
			if (i != size - 1) printf("%04d", digit[i]);// 不是最高位要补0
			else printf("%d", digit[i]); //是最高位就不需要补
		}
		printf("\n");
	}

	//定义大整数和小整数的乘法运算！
	bigInteger operator * (int x) const {
		bigInteger ret;
		ret.init();
		int tmp;
		int carry = 0;
		for (int i = 0; i < this->size; i++) {
			tmp = carry + digit[i] * x;
			ret.digit[ret.size] = tmp % 10000;
			carry = tmp / 10000;
			ret.size++;
		}
		if (carry != 0) {
			ret.digit[ret.size] = carry;
			ret.size++;
		}
		return ret;
	}
};

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		a.init();
		a.set(1); //用1初始化大整数a
		for (int i = 2; i <= n; i++) {
			a = a * i;
		}
		a.output();
	}
	return 0;
}