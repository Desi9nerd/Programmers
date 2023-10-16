#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n; // nxn 격자 크기
vector<vector<int>> v; // v: 원본 격자
int maxBlock; // 게임판에 존재하는 가장 큰 블록의 값

void Move(vector<vector<int>> &v) // 해당 방향으로 블록을 이동시키고 합치는 함수
{
	for(int y=0; y<n; y++)
	{
		deque<int> dq;
		bool chMerge = false;

		for(int x = 0; x < n; x++) // 한 줄씩 블록을 확인하면서 같은 값의 블록을 합침
		{
			if(v[y][x] != 0) // 0이 아닌 경우만 고려함 (블록이 있는 경우)
			{
				// 이전에 합친적 없고, 현재 블록과 같은 값을 가진 블록이 dq에 있으면
				if(chMerge == false && !dq.empty() && dq.back() == v[y][x])
				{
					dq.pop_back();
					dq.push_back(v[y][x] * 2); // 블록 합치기
					chMerge = true;
				}
				else
				{
					dq.push_back(v[y][x]);
					chMerge = false;
				}

				v[y][x] = 0;
			}
		}

		// 이동 및 병합 후 결과를 map에 반영함.
		int idx = 0;
		while(!dq.empty())
		{
			v[y][idx++] = dq.front();
			dq.pop_front();
		}
	}
}

void Rotate(vector<vector<int>>& arr) // 시계 방향으로 회전하는 함수
{
	vector<vector<int>> temp(n, vector<int>(n)); // temp의 크기를 nxn으로 초기화
	for(int y=0; y<n; y++){
		for (int x = 0; x < n; x++) {
			temp[x][n - 1 - y] = arr[y][x];
		}
	}

	arr = temp;
}

void DFS(int cnt) // 모든 가능한 상태를 탐색하는 함수. cnt는 현재까지 몇 번 움직였는지 카운트.
{
	if (cnt >= 5)
	{
		for(int y=0; y<n; y++){
			for (int x = 0; x < n; x++) {
				if (v[y][x] > maxBlock) maxBlock = v[y][x]; // 최대 블록 값을 갱신
			}
		}
		return;
	}

	vector<vector<int>> tmp(n, vector<int>(n)); // tmp: 임시 저장소로 사용되는 격자
	for(int i=0; i<4; i++) // 4방향 탐색
	{
		tmp = v;
		Move(v); 
		DFS(cnt + 1); // 재귀적으로 다음 상태를 탐색
		v = tmp; // 원상 복구
		Rotate(v); // 회전
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n, vector<int>(n));
	for(int y=0; y<n; y++){
		for (int x = 0; x < n; x++) {
			cin >> v[y][x];
		}
	}

	DFS(0);

	cout << maxBlock;

	return 0;
}