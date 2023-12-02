#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
set<int> broken;

bool isPossible(int num) {
    if (num == 0) {
        return broken.find(0) == broken.end();
    }
    while (num) {
        if (broken.find(num % 10) != broken.end()) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int getLength(int num) {
    if (num == 0) {
        return 1;
    }
    int len = 0;
    while (num) {
        len++;
        num /= 10;
    }
    return len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int input;
    for (int i = 0; i < m; i++) {
        cin >> input;
        broken.insert(input);
    }

    int answer = abs(n - 100);
    for (int i = 0; i <= 1000000; i++) {
        if (isPossible(i)) {
            int len = getLength(i);
            answer = min(answer, abs(n - i) + len);
        }
    }

    cout << answer << "\n";

    return 0;
}
