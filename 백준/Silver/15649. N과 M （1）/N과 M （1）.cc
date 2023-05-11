#include<iostream>
using namespace std;

int n, m;
int arr[9], ch[9]={0,}; //순열을 담는 배열, 방문 체크

void DFS(int x)
{
	if (x == m)
	{
		for (int i = 0; i < m; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=1; i<=n; i++)
	{
		if (ch[i] == 0)
		{
			ch[i] = 1;
			arr[x] = i;
			DFS(x + 1);

			ch[i] = 0;			
		}		
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	DFS(0);
		
	return 0;
}