#include<stdio.h>
#include<string.h>
struct biginteger{
	int digit[1001];
	int size;

	void init() {
		for (int i = 0; i < size; i++) {
			digit[i] = 0;
		}
		size = 0;
	}

	void set(int x) {
		init();
		do {
			digit[size] = x % 10000;
			size++;
			x = x / 10000;
		} while (x != 0);
	}

	void output() {
		for (int i = size - 1; i >= 0; i--) {
			if (i != size - 1) {
				printf("%04d", digit[i]);
			}
			else
				printf("%d", digit[i]);
		}
		printf("\n");
	}

	biginteger operator + (const biginteger &A) {
		biginteger ret;
		ret.init();
		int tmp = 0;
		int carry = 0;
		for (int i = 0; i < A.size || i < size; i++) {
			tmp = A.digit[i] + digit[i] + carry;
			carry = tmp / 10000;
			ret.digit[ret.size] = tmp % 10000;
			ret.size++;
		}
		if (carry != 0) {
			ret.digit[ret.size] = carry;
			ret.size++;
		}
		return ret;
	}

	biginteger operator * (int x) {
		biginteger ret;
		ret.init();
		int tmp = 0;
		int carry = 0;
		for (int i = 0; i < size; i++) {
			tmp = digit[i] * x + carry;
			carry = tmp / 10000;
			ret.digit[ret.size++] = tmp % 10000;
		}

		if (carry != 0) {
			ret.digit[ret.size++] = carry;
		}
		return ret;
	}

	biginteger operator / (int x) {
		biginteger ret;
		ret.init();
		int remainder = 0;
		for (int i = size - 1; i >= 0; i--) {
			int tmp = remainder * 10000 + digit[i];
			ret.digit[i] = tmp / x;
			remainder = tmp % x;
		}

		for (int i = 0; i < size; i++) {
			if (ret.digit[i] != 0) {
				ret.size = i;
			}
		}
		ret.size++;

		return ret;
	}

	int operator % (int x) {
		int remainder=0;
		for (int i = size - 1; i >= 0; i--) {
			int tmp = remainder * 10000 + digit[i];
			remainder = tmp % x;
		}
		return remainder;
	}
};

char str1[10000];
char str2[10000];
char ans[10000];
int main() {
	biginteger a, b, c;//a用来算转换成十进制的数，b用来计算当前的权重
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		a.set(0);
		b.set(1);
		scanf("%s",str1);
		int l = strlen(str1);
		for (int i = l - 1; i >= 0; i--) {
			int t;
			if (str1[i] >= '0'&&str1[i] <= '9') {
				t = str1[i] - '0';
			}
			else
				t = str1[i] - 'A' + 10;

			a = a + b * t;
			b = b * m;
		}

		int size = 0;
		do {
			int t = a % n;
			if (t >= 10 ) {
				ans[size] = 'A' + t-10;
			}
			else ans[size] = '0' + t;
			size++;
			a = a / n;
		} while (a.size != 1 || a.digit[0] != 0);

		for (int i = size - 1; i >= 0; i--) {
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	return 0;
}