#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define N 1000
using namespace std;
int cmp(const void *a, const void *b) {//注意这第四个参数的返回值是int
	char *c = (char *)a;//强制类型转换，使a指向字符串
	char *d = (char *)b;
	int l1 = strlen(c);
	int l2 = strlen(d);
	if (l1 != l2) {//如果字符串不一样长，则直接返回，长度长的为大，返回值为正
		return l1 - l2;
	}
	else {
		return (strcmp(c, d));
	}
}
char str[N][10001];//二维数组定义 一行是一个str[i]代表了一个字符串
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s", str[i]);
	}
	qsort(str, n, sizeof(str[0]),cmp); //注意第三个参数为各元素的占用空间大小 这里各元素指的是一个字符串
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << endl;
	}
	return 0;
}