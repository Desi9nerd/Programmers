#include <vector>
using namespace std;

int zero, one; // 0 개수, 1 개수

bool Check(vector<vector<int>>& v, int ny, int nx, int size)
{
	int firstbox = v[ny][nx];

	for(int y = ny; y < ny + size; y++){
		for(int x = nx; x < nx + size; x++){
			if (v[y][x] != firstbox) return false;
		}
	}

	return true;
}

void Quad(vector<vector<int>>& v, int y, int x, int size)
{
	if (Check(v, y, x, size))
	{
		if(v[y][x] == 0) zero -= (size * size - 1);
		else if (v[y][x] == 1) one -= (size * size - 1);
	}
	else{
		int newSize = size / 2;

		Quad(v, y, x, newSize);
		Quad(v, y + newSize, x, newSize);
		Quad(v, y, x + newSize, newSize);
		Quad(v, y + newSize, x + newSize, newSize);
	}
}

vector<int> solution(vector<vector<int>> arr) {

    int n = arr.size();
	for(int y = 0; y < n; y++){
		for (int x = 0; x < n; x++) {
			if (arr[y][x] == 0) zero++;
			else one++;
		}
	}

	Quad(arr, 0, 0, n);

	vector<int> answer;
	answer.push_back(zero);
	answer.push_back(one);
    
    return answer;
}
