#include <iostream>
#include <vector>
using namespace std;

int answer = 1e9; // 색종이 최소 개수
vector<int> paper(5, 5); // 1x1부터 5x5까지 색종이 5장씩

vector<vector<int>> v(10, vector<int>(10)); // 10x10 종이

bool isSquare(int y, int x, int size) {
    if (y + size > 10 || x + size > 10) return false; 

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (v[i][j] == 0) return false; 
        }
    }
    return true;
}

void Attach(int y, int x, int size, int flip) {
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            v[i][j] = flip; // 영역을 flip 값으로 채움
        }
    }
}

void Cal(int y, int x, int cnt) {
    if (x >= 10) {
        Cal(y + 1, 0, cnt);
        return;
    }
    if (y >= 10) {
        answer = min(answer, cnt);
        return;
    }

    if (v[y][x] == 1) {
        for (int k = 0; k < 5; k++) {
            if (paper[k] > 0 && isSquare(y, x, k + 1)) // 색종이 크기 k+1로 수정
            { 
                Attach(y, x, k + 1, 0); // k+1 크기로 색종이 붙임
                paper[k]--;

                Cal(y, x + 1, cnt + 1);

                Attach(y, x, k + 1, 1); // 색종이 제거
                paper[k]++;
            }
        }
    }
    else {
        Cal(y, x + 1, cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            cin >> v[y][x];
        }
    }

    Cal(0, 0, 0);

    if (answer == 1e9) cout << "-1";
    else cout << answer;

    return 0;
}