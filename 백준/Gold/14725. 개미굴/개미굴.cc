#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int n; // 먹이의 정보 개수
int k;

struct Node{
private:
	map<string, Node*> child;

public:
	void Insert(vector<string>& v, int idx)
	{
		if (idx == v.size()) return;

		if (child.find(v[idx]) == child.end()){
			child[v[idx]] = new Node();
		}
		child[v[idx]]->Insert(v, idx + 1);
	}

	void PrintTree(int depth)
	{
		for(auto& iter : child){
			for (int i = 0; i < depth; i++) {
				cout << "--";
			}
			cout << iter.first << "\n";
			iter.second->PrintTree(depth + 1);
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Node* root = new Node;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> k;
		vector<string> v(k, "");

		for(int j = 0; j < k; j++){
			cin >> v[j];
		}

		root->Insert(v, 0);
	}

	root->PrintTree(0);

	return 0;
}