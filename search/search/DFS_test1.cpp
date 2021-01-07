#include<bits/stdc++.h>
using namespace std;
char mat[8][8];
int n, m, t;
bool mark[8][8];
int go[][2] = {
	-1,0,
	1,0,
	0,1,
	0,-1
};
bool success;
//递归搜索
void DFS(int x, int y, int time) {
	for (int i = 0; i < 4; i++) {
		int newx = x + go[i][0];
		int newy = y + go[i][1];

		if (newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
		if (mark[newx][newy] == true) continue;
		if (mat[newx][newy] == 'X') continue;
		
		if (mat[newx][newy] == 'D') {
			if (time + 1 == t) {
				success = true;
				return; //递归出口
			}
			else continue; //到过D点，做了mark不能再次到达
		}
		mark[newx][newy] = true; //该点是.，可以到达，则先标记
		DFS(newx, newy, time + 1);//递归返回后会有一个success搜索结果
		mark[newx][newy] = false; //return之后回溯,继续从上一个状态进行状态转移
		if (success) return;//判断本次状态转移递归搜索的结果
	}
}
int main() {
	int sx, sy;
	int dx, dy;
	while (scanf("%d%d%d", &n, &m, &t) != EOF) {
		if (n == 0 && m == 0 && t == 0) break;
		//因为每行字符之后有个回车，所以用scanf按行读入字符串，遇到最后一个换行就停止
		//如果要按字符读入的话，每行读完需要getchar
		getchar();//清除掉上一行缓冲区中的回车
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%c", &mat[i][j]);
				mark[i][j] = false;
			}
			getchar(); //清除缓冲区中上一行遗留的回车
		}
		//memset(mark, false, sizeof(mark));
		//找起始点和目标点
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'S') {
					sx = i;
					sy = j;
					continue;
				}
				if (mat[i][j] == 'D') {
					dx = i;
					dy = j;
				}
			}
		}
		mark[sx][sy] = true;
		//根据T和起终点坐标和的奇偶性进行剪枝
		int sxy = sx + sy;
		int dxy = dx + dy;
		if ((t % 2 == 0 && (dxy - sxy) % 2 != 0) || (t % 2 != 0 && (dxy - sxy) % 2 == 0)) {
			success = false;
		}
		else DFS(sx, sy, 0);
		
		if (success) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}