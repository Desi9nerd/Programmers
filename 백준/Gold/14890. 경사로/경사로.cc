#include <iostream>
#include <vector>
using namespace std;

int n, l;
int answer;
vector<vector<int>> v;

bool RoadCheckY(int y)
{
    vector<vector<bool>> ch(n, vector<bool>(n, false));

    for (int i = 0; i < n - 1; i++)
    {
        if (v[y][i] == v[y][i + 1]) continue;
        else if (v[y][i] < v[y][i + 1]) {
            if (v[y][i + 1] - v[y][i] != 1) return false; 
            int tmp = i;
            int cnt = l; 
            while (tmp >= 0 && cnt) {
                if (v[y][tmp] == v[y][i] && ch[y][tmp] == false) {
                    ch[y][tmp] = true;
                    cnt--;
                }
                else return false;

                tmp--;
            }
            if (cnt > 0) return false;
        }
        else if (v[y][i] > v[y][i + 1]) {
            if (v[y][i] - v[y][i + 1] != 1) return false; 
            int tmp = i + 1;
            int cnt = l; 
            while (tmp < n && cnt) {
                if (v[y][i + 1] == v[y][tmp] && ch[y][tmp] == false) {
                    ch[y][tmp] = true;
                    cnt--;
                }
                else return false;

                tmp++;
            }
            if (cnt > 0) return false;
        }
    }

    return true;
}

bool RoadCheckX(int x)
{
    vector<vector<bool>> ch(n, vector<bool>(n, false));

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i][x] == v[i + 1][x]) continue;
        else if (v[i][x] < v[i + 1][x]) {
            if (v[i + 1][x] - v[i][x] != 1) return false; // 수정된 부분
            int tmp = i;
            int cnt = l; // 수정된 부분
            while (tmp >= 0 && cnt) {
                if (v[tmp][x] == v[i][x] && ch[tmp][x] == false) {
                    ch[tmp][x] = true;
                    cnt--;
                }
                else return false;

                tmp--;
            }
            if (cnt > 0) return false;
        }
        else if (v[i][x] > v[i + 1][x]) {
            if (v[i][x] - v[i + 1][x] != 1) return false; 
            int tmp = i + 1;
            int cnt = l; 
            while (tmp < n && cnt) {
                if (v[i + 1][x] == v[tmp][x] && ch[tmp][x] == false) {
                    ch[tmp][x] = true;
                    cnt--;
                }
                else return false;

                tmp++;
            }
            if (cnt > 0) return false;
        }
    }

    return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;
	v.resize(n, vector<int>(n));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> v[y][x];
		}
	}

    for (int i = 0; i < n; i++) {
        if (RoadCheckY(i)) answer++; // 행 검사
        if (RoadCheckX(i)) answer++; // 열 검사
    }

	cout << answer;

	return 0;
}