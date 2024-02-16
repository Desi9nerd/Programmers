#include<iostream>
using namespace std;

const int MAX = 100000;
int a[MAX + 1];
int tree[MAX * 4 + 1];

int MinIndex(int x, int y) // 더 작은 값의 인덱스를 반환하는 함수
{
	// 유효하지 않은 경우
	if (x == -1) return y;
	if (y == -1) return x;
	// 같은 경우 더 작은 인덱스 리턴
	if (a[x] == a[y]) return x < y ? x : y;

	return a[x] <= a[y] ? x : y;
}

int Init(int start, int end, int node)
{
	if (start == end) return tree[node] = start;

	int mid = (start + end) / 2;

	return tree[node] = MinIndex(Init(start, mid, node * 2), Init(mid + 1, end, node * 2 + 1));
}

int Update(int start, int end, int node, int index)
{	// index를 찾았거나 범위를 벗어난 경우 현재 노드 리턴
	if (start > index || end < index) return tree[node];
	if (start == end) return tree[node];

	int mid = (start + end) / 2;
	// 더 작은 값을 가지는 인덱스로 update
	return tree[node] = MinIndex(Update(start, mid, node * 2, index), Update(mid + 1, end, node * 2 + 1, index));
}

int Query(int start, int end, int node, int left, int right)
{
	// 구간을 벗어나는 경우
	if (start > right || end < left) return -1;
	// 완전히 구간 안에 들어온 경우
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	// 더 작은 값을 가지는 인덱스 리턴
	return MinIndex(Query(start, mid, node * 2, left, right), Query(mid + 1, end, node * 2 + 1, left, right));
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;

	Init(1, n, 1);

	while (m--)
	{
		int q, index, v, left, right;
		cin >> q;
		if (q == 1)
		{
			cin >> index >> v;
			a[index] = v;
			Update(1, n, 1, index);
		}
		if (q == 2)
		{
			cin >> left >> right;
			cout << Query(1, n, 1, left, right) << '\n';
		}
	}

	return 0;
}