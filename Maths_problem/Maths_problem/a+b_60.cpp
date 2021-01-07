#include<stdio.h>
#include<string.h>
struct bigInteger {
	int digit[1000]; //每一项保存一个四位数,以4位为一个单位保存
	int size; //下一个可以使用的数组单元，即当前使用的项数

	//初始化
	void init() {
		for (int i = 0; i < 1000; i++) {
			digit[i] = 0;
			size = 0; //没有一个单位被使用
		}
	}

	//以字符串形式输入，处理这个字符串填充到结构体中
	void set(char str[]) {
		init();
		int len = strlen(str);
		int j = 0; //判断到没到4
		int weight = 1; //四位数当前位的权重，分别为1 10 100 1000 
		int t=0; //四位数的数值
		for (int i = len-1; i>=0 ; i--) {
			t += (str[i] - '0') * weight;
			weight = weight * 10;
			j++;
			if (j % 4 == 0 || i==0) {
				digit[size] = t;
				size++;
				j = 0;
				weight = 1;
				t = 0;
			}
		}
	}

	void output() {
		for (int i = size - 1; i >= 0; i--) {
			if (i != size - 1) {//如果不是最后一项，是中间的四位数，那么要填充0进去，因为中间的四位数不一定都是四位的
				printf("%04d", digit[i]);
			}
			else printf("%d", digit[i]);
		}
		printf("\n");
	}

	bigInteger operator + (const bigInteger &A){
		bigInteger ret;
		ret.init();
		int carry = 0;
		int tmp;
		int maxsize = A.size > this->size ? A.size : this->size;
		for (int i = 0; i < maxsize; i++) {
			tmp = A.digit[i] + this->digit[i] + carry;
			carry = tmp / 10000;
			tmp = tmp % 10000;
			ret.digit[ret.size] = tmp;
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
	bigInteger a, b, c;
	char buf1[1002];
	char buf2[1002];
	while (scanf("%s%s", buf1, buf2)!=EOF) {
		a.set(buf1);
		b.set(buf2);
		c = a + b;
		c.output();
	}
	return 0;
}