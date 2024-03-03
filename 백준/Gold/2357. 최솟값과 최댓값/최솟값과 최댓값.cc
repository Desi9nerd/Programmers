#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define INF 1000000001

struct Value{
	long long minNum, maxNum;
};

int n, m;
vector<int> v;
vector<Value> sTree;

Value SegmentTree(int node, int start, int end)
{
	if (start == end) { // node가 leaf node인 경우
		sTree[node].minNum = v[start];
		sTree[node].maxNum = v[start];
		return sTree[node];
	}

	int mid = (start + end) / 2;

	Value left = SegmentTree(node * 2, start, mid);
	Value right = SegmentTree(node * 2 + 1, mid + 1, end);

	sTree[node].minNum = min(left.minNum, right.minNum);
	sTree[node].maxNum = max(left.maxNum, right.maxNum);

	return sTree[node];
}

Value FindMinMax(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) {
		return Value{ INF, 0 };
	}

	if (left <= start && end <= right){
		return sTree[node];
	}

	int mid = (start + end) / 2;

	Value tempLeft = FindMinMax(node * 2, start, mid, left, right);
	Value tempRight = FindMinMax(node * 2 + 1, mid + 1, end, left, right);

	Value result;
	result.minNum = min(tempLeft.minNum, tempRight.minNum);
	result.maxNum = max(tempLeft.maxNum, tempRight.maxNum);

	return result;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	int treeHeight = (int)ceil(log2(n));
	int treeSize = (1 << (treeHeight + 1));
	sTree.resize(treeSize);

	SegmentTree(1, 0, n - 1);
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;

		Value tmp = FindMinMax(1, 0, n - 1, a-1, b-1);
		cout << tmp.minNum << " " << tmp.maxNum << "\n";
	}

	return 0;
}
