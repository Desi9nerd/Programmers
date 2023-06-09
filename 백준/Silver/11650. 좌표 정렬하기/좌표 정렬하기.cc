#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;

int main() {
    int n, a, b;
    cin >> n;

    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i].resize(2);
        v[i][0] = a;
        v[i][1] = b;
    }

    sort(v.begin(), v.end());

    for (const auto& i : v) {
        cout << i[0] << " " << i[1] << "\n";
    }

    return 0;
}