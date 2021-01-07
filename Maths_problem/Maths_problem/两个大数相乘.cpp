#include<stdio.h>
#include<string.h>
struct biginteger {
	int digit[1001];
	int size;

	void init() {
		for (int i = 0; i <= 1000; i++) {
			digit[i] = 0;
		}
		size = 0;
	}

	void set_c(char str[]) {
		int weight = 1;
		int cnt = 0;
		int tmp = 0;
		int l = strlen(str);
		for (int i = l - 1; i >= 0; i--) {
			tmp += (str[i] - '0')*weight;
			weight *= 10;
			cnt ++ ;
			if (cnt == 4 || i == 0) {
				digit[size] = tmp;
				size++;
				weight = 1;
				tmp = 0;
				cnt = 0;
			}
		}
	}

	void set(int x) {
		init();
		do {
			digit[size] = x % 10000;
			x = x / 10000;
			size++;
		} while (x != 0);
	}

	void output() {
		for (int i = size - 1; i >= 0; i--) {
			if (i != size - 1) printf("%04d", digit[i]);
			else  printf("%d", digit[i]);
		}
		printf("\n");
	}

	biginteger operator * (int x) {//大整数和小整数相乘
		biginteger res;
		res.init();
		int carry = 0;
		int tmp = 0;
		for (int i = 0; i < size; i++) {
			tmp = digit[i] * x + carry;
			carry = tmp / 10000;
			res.digit[res.size] = tmp % 10000;
			res.size++;
		}
		if (carry != 0) {
			res.digit[res.size] = carry;
			res.size++;
		}
		return res;
	}

	biginteger operator + (const biginteger &A) {
		biginteger ret;
		ret.init();
		int carry = 0;
		int tmp = 0;
		for (int i = 0; i < size || i<A.size; i++) {
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
};

//两个大整数相乘
biginteger multi(biginteger A, biginteger B) {
	biginteger mulres;
	mulres.init();
	biginteger tmp;
	biginteger carry;
	carry.set(0);
	for (int i = 0; i < B.size; i++) {
		tmp.init();
		tmp = A * B.digit[i] + carry;
		mulres.digit[mulres.size] = tmp.digit[0];
		mulres.size++;
		carry.init();//加完之后carry清空
		for (int i = 1; i < tmp.size; i++) {
			carry.digit[carry.size] = tmp.digit[i];
			carry.size++;
		}
	}
	for (int i = 0; i < carry.size; i++) {
		mulres.digit[mulres.size] = carry.digit[i];
		mulres.size++;
	}
	return mulres;
}

int main() {
	biginteger a, b,c;
	char str1[1001], str2[1001];
	while (scanf("%s%s", str1,str2) != EOF) {
		a.init(); b.init();
		a.set_c(str1);
		b.set_c(str2);
		c = multi(a, b);
		c.output();
	}
	return 0;
}