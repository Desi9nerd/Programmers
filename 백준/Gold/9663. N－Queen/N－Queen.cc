#include <iostream>
using namespace std;

int n;
int col[15];
int answer = 0;

bool isPossible(int level) {
    for (int i = 0; i < level; i++) {
        // 같은 열에 있는 경우
        if (col[i] == col[level])
            return false;
        
        // 대각선 상에 있는 경우
        if (level - i == abs(col[level] - col[i]))
            return false;
    }
    return true;
}

void nQueen(int level) {
    if (level == n) {
        answer++;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        col[level] = i; // 현재 level 행에서 i열에 퀸을 놓음
        
        if (isPossible(level)) // 유망한지 검사
            nQueen(level + 1); // 다음 행으로 넘어감
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    nQueen(0);
    
    cout << answer << endl;
    
    return 0;
}
