#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int tree[101];
int findroot(int x) {
	int root;
	int tmp = x;
	while (tree[x] != -1) {
		x = tree[x];
	}
	root = x;
	x = tmp;
	while (tree[x] != -1) {
		int t = tree[x];
		tree[x] = root;
		x = t;
	}
	return root;
}

struct point {
	int num;
	float x;
	float y;
}P[101];

struct edge {
	int a;
	int b; //µãµÄÐòºÅ
	float dis;
}E[5000];

bool cmp(edge A, edge B) {
	return A.dis < B.dis;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			tree[i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%f%f", &P[i].x, &P[i].y);
			P[i].num = i;
		}

		int edgenum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				edgenum++;
				E[edgenum].a = i;
				E[edgenum].b = j;
				E[edgenum].dis = sqrt((P[i].x - P[j].x)*(P[i].x - P[j].x) + (P[i].y - P[j].y)*(P[i].y - P[j].y));		
			}
		}

		sort(E+1, E + edgenum+1, cmp);

		float ans = 0;
		for (int i = 1; i <= edgenum; i++) {
			int roota = findroot(E[i].a);
			int rootb = findroot(E[i].b);
			if (roota != rootb) {
				tree[roota] = rootb;
				ans += E[i].dis;
			}
		}
		printf("%f\n", ans);
	}
	return 0;
}
