#include<stdio.h>
#include<vector>
using namespace std;
struct E {
	int next;
	int cost;
};
vector <E> edge[101];//�ڽ�����
int dis[101]; //��ʾ��Դ�㵽�õ�����·��
bool mark[101];//��Ǹõ��Ƿ񱻼���K����

int main() {
	int n;
	int m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			dis[i] = -1; //-1��ʾ����
			mark[i] = false;
			edge[i].clear();
		}

		//��ʼ���ڽ�����
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
				if (mark[t] == true) continue;//�ڽӵ��Ѿ��ڼ����У��������
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