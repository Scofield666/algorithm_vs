#include<stdio.h>
#include<stack>
using namespace std;
stack<int> S; //定义一个堆栈
int main() {
	char buf[100]; // 输入字符串
	char ans[100]="0"; // 输出字符串,初始化防止出现未定义的内存 在windows平台下，ms的编译器（也就是vc带的那个）在 Debug 模式下，会把未初始化的栈内存全部填成 0xcc，用字符串来看就是”烫烫烫烫烫烫烫”，未初始化的堆内存全部填成0xcd，字符串看就是“屯屯屯屯屯屯屯屯”。
	while (scanf("%s", buf) != EOF) {//这里注意输入的字符串s 而非c
		int i;
		for (i = 0; buf[i] != '\0'; i++) { // 遍历输入字符串
			if (buf[i] == '(') {
				S.push(i); // 这里注意是把左括号的序号压栈，而不是压左括号
				ans[i] = ' '; //暂时把左括号对应的位置都置为空格
			}
			else if (buf[i] == ')') {
				if (S.empty() == false) {//右括号 此时如果栈不空
					S.pop(); // 将最上面的左括号出栈
					ans[i] = ' ';
				}
				else { //右括号 栈为空
					ans[i] = '?';
				}
			}
			else ans[i] = ' ';
		}
		ans[i] = '\0'; //结尾元素
		int k;
		while (!S.empty()) {
			k = S.top(); //取栈顶元素
			ans[k] = '$';
			S.pop();
		}
		puts(buf);
		puts(ans);
	}
	return 0;
}