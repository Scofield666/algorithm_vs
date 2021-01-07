#include<stdio.h>
#include<vector>
using namespace std;
struct E {
	int next;
	int cost;
};
vector <E> edge[101];//邻接链表
int dis[101]; //表示从源点到该点的最短路径
bool mark[101];//标记该点是否被加入K集合

int main() {
	int n;
	int m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			dis[i] = -1; //-1表示无穷
			mark[i] = false;
			edge[i].clear();
		}

		//初始化邻接链表
		for (int i = 1; i <= m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			E tmp;
			tmp.next = b;
			tmp.cost = c;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}

		mark[1] = true;
		dis[1] = 0;
		int newp = 1;
		for (int i = 1; i < n; i++) {
			for (int i = 0; i < edge[newp].size(); i++) {
				int t = edge[newp][i].next;
				int c = edge[newp][i].cost;
				if (mark[t] == true) continue;//邻接点已经在集合中，无需更新
				if (dis[t] == -1 || dis[newp] + c < dis[t]) {
					dis[t] = dis[newp] + c;
				}
			}
			int mintmp = 123456;
			for (int i = 1; i <= n; i++) {
				if (mark[i] == false && dis[i]!=-1) {
					if (dis[i] < mintmp) {
						mintmp = dis[i];
						newp = i;
					}
				}
			}
			mark[newp] = true;
		}

		printf("%d\n", dis[n]);
	}
	return 0;
}