#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int t, n; //t: 테스트 케이스 수, n: 체스판 한 변의 길이
int c, d; //도착 위치

int ch[301][301];
queue<pair<int,int>> Q;

int dirY[8] = { -1, -2, -1, -2, 1, 2, 1, 2 };
int dirX[8] = { -2, -1, 2, 1, -2, -1, 2, 1 };

void BFS(int a, int b)
{
	memset(ch, -1, sizeof(ch));
	

	Q.push(make_pair(a, b));//현재 있는 칸
	ch[a][b] = 0;

	while(!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		if(y==c && x==d){
			cout << ch[c][d] << "\n";
			return;
		}
		
		for(int i = 0; i < 8; i++)//8방향 이동
		{
			if (ch[y + dirY[i]][x + dirX[i]] == -1 
				&& 0 <= y + dirY[i] && 0 <= x + dirX[i]
				&& y + dirY[i] < n && x + dirX[i] < n)
			{
				Q.push(make_pair(y + dirY[i], x + dirX[i]));
				ch[y + dirY[i]][x + dirX[i]] = ch[y][x] + 1;
			}
		}		
	}

	return;
}

int main(){
	ios::sync_with_stdio(false);

	cin >> t;

	while(t--)
	{
		cin >> n;
		
		//현재 있는 칸: (a, b), 이동하려는 칸: (y, x)
		int a, b;
		cin >> a >> b;
		cin >> c >> d;

		BFS(a, b);

		while(!Q.empty())
		{
			Q.pop();//다음 테스트 케이스를 위해 큐 초기화
		}
	}

	return 0;
}