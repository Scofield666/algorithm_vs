#include<stdio.h>
#include<string.h>
struct bigInteger {
	int digit[1000]; //ÿһ���һ����λ��,��4λΪһ����λ����
	int size; //��һ������ʹ�õ����鵥Ԫ������ǰʹ�õ�����

	//��ʼ��
	void init() {
		for (int i = 0; i < 1000; i++) {
			digit[i] = 0;
			size = 0; //û��һ����λ��ʹ��
		}
	}

	//���ַ�����ʽ���룬��������ַ�����䵽�ṹ����
	void set(char str[]) {
		init();
		int len = strlen(str);
		int j = 0; //�жϵ�û��4
		int weight = 1; //��λ����ǰλ��Ȩ�أ��ֱ�Ϊ1 10 100 1000 
		int t=0; //��λ������ֵ
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
			if (i != size - 1) {//����������һ����м����λ������ôҪ���0��ȥ����Ϊ�м����λ����һ��������λ��
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