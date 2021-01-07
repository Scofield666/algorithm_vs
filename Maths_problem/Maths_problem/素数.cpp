#include<bits/stdc++.h>
using namespace std;
const int maxns = 1e5;
//�ж��Ƿ�Ϊ����
bool judge(int x) {
	for (int i = 2; i < sqrt(x) + 1; i++) {
		if (x%i == 0) return false; //�ҵ�һ��
	}
	return true;
}

//����ɸ�� ɸѡ��1e5�������е����� ������prime������
bool mark[maxns]; //true���������� falseΪ���� ��ʼΪtrue
int prime[maxns];
int primesize = 0;
void shai() {
	memset(mark, true, sizeof(mark));
	for (int i = 2; i <= maxns; i++) {
		if (mark[i] == false) continue;
		prime[primesize++] = i;
		for (int j = 2 * i; j <= maxns; j += i) {
			mark[j] = false;
		}
	}
	mark[0] = mark[1] = false;
}

//�����Ӹ���
int facnum(int x) {
	int ret = 0;
	for (int i = 1; i < sqrt(x) + 1; i++) {
		if (x%i == 0) {
			if (i == x / i) ret = ret + 2;
			else ret++;
		}
	}
	return ret;
}

//�������ӵĸ��� ��ͬ�����ظ�����������Ұ�������
int primefac[maxns];
int psize = 0;
int primeFacNum(int x) {
	int ret = 0;
	for (int i = 2; i < sqrt(x) + 1; i++) {
		if (x%i == 0) {
			primefac[psize++] = i;
			while (x%i == 0) {
				ret++;
				x /= i;
			}
		}
		if (x == 1) break;
	}
	if (x != 1) { //��û�ֽ��� ���ʣ�µ��Ǵ���sqrt(x)������
		primefac[psize++] = x;
		ret++;
	}
	return ret;
}

//������ɸ 1<l<r<1e9 ��Χ��1e6���ҵĶ�̬����[l,r]�ڵ�����/ÿ�����������ĸ��� 
const int maxns2 = 1e6 + 1;
int a[maxns2]; // ���ƫ�� ��l-r������ֵ�����1e6��������
int primefactor[maxns2]; //1e9�ڵ�������������1e5�� ����ɸ�ҳ���Щ
int pcnt = 0;
int num[maxns2]; //l-r��ÿ���������������� �� a�����Ӧ
int l, r;
bool mark2[maxns2];
void shai2() {
	memset(mark2, true, sizeof(mark2));
	for (int i = 2; i <= 1e5; i++) {
		if (mark2[i] == false) continue;
		primefactor[pcnt++] = i;
		for (int j = 2 * i; j <= 1e5; j += i) {
			mark2[j] = false;
		}
	}
	mark2[0] = mark2[1] = false;
}
void qujiansushai() {
	for (int i = l; i <= r; i++) {
		a[i - l] = i; //ƫ�ƴ浽a������
	}

	shai2(); //ɸ��1e5���ڵ�����

	//��������Щ����ȥɸ������a�е�����ֵl-r ����������ǲ��ǵ�ǰ��������
	for (int i = 0; i < pcnt; i++) {
		//ȡ��ǰ����ȥɸָ�������ڵ��� ������Ҫ��λ����ǰ�����ı����������ڵĿ�ʼλ��
		int currentp = primefactor[i];
		int start = l / currentp * currentp; 
		for (int j = start; j <= r; j+=currentp) {
			if (j < l) continue;
			if (a[j - l] % currentp == 0) {
				while (a[j - l] % currentp == 0) {
					num[j - l]++;
					a[j - l] /= currentp;
				}
			}
		}
	}
	//�����ǰ����Ϊ1 ʣ������������
	for (int i = 0; i <= r - l; i++) {
		if (a[i] != 1) num[i]++;
	}

	//num������-> markΪtrue
	int ans = 0;
	for (int i = 0; i <= r - l; i++) {
		if (mark[num[i]] == true) ans++;
	}
}





