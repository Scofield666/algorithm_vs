#include<stdio.h>
#include<stack>
using namespace std;
stack<int> S; //����һ����ջ
int main() {
	char buf[100]; // �����ַ���
	char ans[100]="0"; // ����ַ���,��ʼ����ֹ����δ������ڴ� ��windowsƽ̨�£�ms�ı�������Ҳ����vc�����Ǹ����� Debug ģʽ�£����δ��ʼ����ջ�ڴ�ȫ����� 0xcc�����ַ����������ǡ��������������̡���δ��ʼ���Ķ��ڴ�ȫ�����0xcd���ַ��������ǡ����������������͡���
	while (scanf("%s", buf) != EOF) {//����ע��������ַ���s ����c
		int i;
		for (i = 0; buf[i] != '\0'; i++) { // ���������ַ���
			if (buf[i] == '(') {
				S.push(i); // ����ע���ǰ������ŵ����ѹջ��������ѹ������
				ans[i] = ' '; //��ʱ�������Ŷ�Ӧ��λ�ö���Ϊ�ո�
			}
			else if (buf[i] == ')') {
				if (S.empty() == false) {//������ ��ʱ���ջ����
					S.pop(); // ��������������ų�ջ
					ans[i] = ' ';
				}
				else { //������ ջΪ��
					ans[i] = '?';
				}
			}
			else ans[i] = ' ';
		}
		ans[i] = '\0'; //��βԪ��
		int k;
		while (!S.empty()) {
			k = S.top(); //ȡջ��Ԫ��
			ans[k] = '$';
			S.pop();
		}
		puts(buf);
		puts(ans);
	}
	return 0;
}