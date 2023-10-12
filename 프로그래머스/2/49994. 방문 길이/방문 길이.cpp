#include <string>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    int x = 5;
    int y = 5;

    for(char dir : dirs){
        int idx;
        switch(dir){
            case 'U':
                idx=0;
                break;
            case 'D':
                idx=1;
                break;            
            case 'R':
                idx=2; 
                break;            
            case 'L':
                idx=3; 
                break;  
        }

        int nx=x+dx[idx];
        int ny=y+dy[idx];

        if(nx>=0 && nx<=10 && ny>=0 && ny<=10){
            if(!visited[x][y][nx][ny]){
               visited[x][y][nx][ny]=true;
               visited[nx][ny][x][y]=true; //반대 방향도 체크
               answer++;
            }
            
            x=nx;
            y=ny;
        }
        
    }

    return answer;
}