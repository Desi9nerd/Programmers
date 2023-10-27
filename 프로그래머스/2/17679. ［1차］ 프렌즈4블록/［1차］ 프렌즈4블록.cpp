#include <string>
#include <vector>
using namespace std;

vector<string> v;

int solution(int m, int n, vector<string> board) {

    int answer = 0; // 제거된 블록의 개수를 저장할 변수
    v = board;

    while (true)
    {
        vector<pair<int, int>> coor; // 2x2 블록의 좌측 상단 좌표를 저장할 벡터
        vector<vector<int>> ch(m, vector<int>(n, 0)); // 각 블록의 제거 여부를 저장할 2차원 벡터

         // 모든 블록을 순회하며 2x2 블록을 찾음
        for (int y = 0; y < m - 1; y++) {
            for (int x = 0; x < n - 1; x++) {
                if (v[y][x] == ' ') continue; // 빈 블록은 건너뜀
                // 2x2 블록을 찾으면 좌표를 저장하고, 제거 표시를 함
                if (v[y][x] == v[y][x + 1] && v[y + 1][x] == v[y + 1][x + 1] && v[y][x] == v[y + 1][x]) {
                    coor.push_back({ y, x });
                    ch[y][x] = ch[y][x + 1] = ch[y + 1][x] = ch[y + 1][x + 1] = 1; 
                }
            }
        }

        if (coor.size() == 0) break; // 더 이상 제거할 블록이 없으면 반복을 종료

        // 모든 블록을 순회하며 제거 표시된 블록을 제거하고, 그 위의 블록을 아래로 내림
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++)
            {
                if (ch[y][x] == 1)
                {
                    answer++; // 제거된 블록 개수를 증가
                    if (y == 0) continue; // 맨 위 블록은 건너뜀

                    // 현재 블록 위의 모든 블록을 한 칸씩 아래로 내림
                    for (int k = y - 1; k >= 0; k--) {
                        v[k + 1][x] = v[k][x];
                        v[k][x] = ' ';
                    }
                }
            }
        }
    } 


    return answer; // 제거된 블록의 개수를 반환
}
