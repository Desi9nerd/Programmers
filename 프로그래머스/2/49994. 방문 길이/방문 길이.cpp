#include <string>
using namespace std;

int answer = 0;  // 방문 길이
int chPath[11][11][11][11]; 
int y = 0, x = 0; // 시작 위치

// 방문 체크 후 방문한 적이 없으면 길이 늘리기
void checkPath(int prevY, int prevX, int y, int x) 
{
	if(chPath[prevY + 5][prevX + 5][y + 5][x + 5] == 0
        && chPath[y + 5][x + 5][prevY + 5][prevX + 5] == 0)
	{
        chPath[prevY + 5][prevX + 5][y + 5][x + 5] = 1;
        answer++;
        chPath[y + 5][x + 5][prevY + 5][prevX + 5] = 1;
	}

    return;
}

void Move(char d, int& y, int& x)
{
    int prevY = y;
    int prevX = x;

    // 이동
    if (d == 'U' && y < 5){
        y = y + 1;
        checkPath(prevY, prevX, y, x);
    }
    else if (d == 'D' && -5 < y) {
        y = y - 1;
        checkPath(prevY, prevX, y, x);
    }
    else if (d == 'R' && x < 5) {
        x = x + 1;
        checkPath(prevY, prevX, y, x);
    }
    else if (d == 'L' && -5 < x) {
        x = x - 1;
        checkPath(prevY, prevX, y, x);
    }    
}

int solution(string dirs) {
    
    for(int i=0; i<dirs.size(); i++)
    {
        Move(dirs[i], y, x);
    }

    return answer;
}