#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m; // n: 기차의 수, m: 명령의 수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<int> v(n, 0);

    for (int i = 0; i < m; i++)
    {
        int orderIdx, train, x;
        cin >> orderIdx >> train;
        train--; // 0-based index로 변환

        if (orderIdx == 1 || orderIdx == 2) { cin >> x; }

        if (orderIdx == 1){
            v[train] |= (1 << (x - 1));
        }
        else if (orderIdx == 2) {
            v[train] &= ~(1 << (x - 1));
        }
        else if (orderIdx == 3) {
            v[train] = (v[train] << 1);
            v[train] &= ((1 << 20) - 1); // 상위 20번째 비트를 넘지 않도록 제한
        }
        else if (orderIdx == 4) {
            v[train] >>= 1;
        }
    }

    set<int> mySet;
    for (int i = 0; i < v.size(); i++){
        mySet.insert(v[i]);
    }

    cout << mySet.size() << "\n";

    return 0;
}
