#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Info {
  int y, x, feed, sharkSize, time;
};

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int n;
vector<vector<int>> v;
vector<vector<bool>> visited;
int answer = 0;

bool isInside(int y, int x) {
  return y >= 0 && y < n && x >= 0 && x < n;
}

void BFS(int startY, int startX) {
  queue<Info> Q;
  Q.push({ startY, startX, 0, 2, 0 });
  visited[startY][startX] = true;
  
  while (!Q.empty()) {
    int size = Q.size();
    vector<Info> fish;
    
    for (int i = 0; i < size; ++i) {
      int y = Q.front().y;
      int x = Q.front().x;
      int feed = Q.front().feed;
      int sharkSize = Q.front().sharkSize;
      int time = Q.front().time;
      Q.pop();

      if (v[y][x] != 0 && v[y][x] < sharkSize) { // 먹을 수 있는 물고기 발견
        fish.push_back({ y, x, feed, sharkSize, time });
        continue;
      }

      for (int j = 0; j < 4; ++j) {
        int ny = y + dirY[j];
        int nx = x + dirX[j];

        if (!isInside(ny, nx) || visited[ny][nx] || v[ny][nx] > sharkSize) continue;

        visited[ny][nx] = true;
        Q.push({ ny, nx, feed, sharkSize, time + 1 });
      }
    }
    
    if (!fish.empty()) {
      sort(fish.begin(), fish.end(), [](const Info& a, const Info& b) {
        if (a.time == b.time) {
          if (a.y == b.y) return a.x < b.x;
          return a.y < b.y;
        }
        return a.time < b.time;
      });
      
      int newY = fish[0].y;
      int newX = fish[0].x;
      int newFeed = fish[0].feed + 1;
      int newSize = fish[0].sharkSize;
      int newTime = fish[0].time;
      
      if (newFeed == newSize) {
        newFeed = 0;
        newSize++;
      }
      
      v[newY][newX] = 0; // 먹은 물고기 제거
      answer = newTime; // 시간 업데이트
      visited.assign(n, vector<bool>(n, false)); // 방문 배열 초기화
      Q = queue<Info>(); // 큐 초기화
      Q.push({ newY, newX, newFeed, newSize, newTime });
      visited[newY][newX] = true;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  v.resize(n, vector<int>(n));
  visited.assign(n, vector<bool>(n, false));

  int startY, startX;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cin >> v[y][x];
      if (v[y][x] == 9) {
        startY = y;
        startX = x;
        v[y][x] = 0; // 상어가 처음 위치한 칸을 빈칸으로 설정
      }
    }
  }

  BFS(startY, startX);

  cout << answer << "\n";

  return 0;
}
