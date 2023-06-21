#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting {
    int start, end;
};

bool comp(const Meeting& a, const Meeting& b) {
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Meeting> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].start >> v[i].end;
    }

    sort(v.begin(), v.end(), comp);

    int cnt = 0;
    int last_end = -1;
    for (const auto& mt : v) {
        if (mt.start >= last_end) {
            cnt++;
            last_end = mt.end;
        }
    }

    cout << cnt << '\n';

    return 0;
}
