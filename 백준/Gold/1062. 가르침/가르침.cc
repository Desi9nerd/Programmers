#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>
#include <set>
using namespace std;

int n, k;
int answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    vector<string> words(n);
    for (int i = 0; i < n; i++){
        cin >> words[i];
    }

    if (k < 5) {
        cout << "0\n";
        return 0;
    }

    bitset<26> alphabet;
    alphabet['a' - 'a'] = alphabet['n' - 'a'] = alphabet['t' - 'a'] = alphabet['i' - 'a'] = alphabet['c' - 'a'] = true;

    set<char> allCandidates;
    for (int i = 0; i < n; i++)
    {
	    for (int j = 4; j < words[i].size() - 4; j++)
	    {
	        if (false == alphabet[ words[i][j] - 'a' ]) {
                allCandidates.insert(words[i][j]);
	        }
	    }
    }

    vector<char> can(allCandidates.begin(), allCandidates.end());
    int canSize = can.size();

    // 조합을 이용한 가능한 모든 경우의 수를 확인
    vector<bool> comb(canSize, false);
    fill(comb.begin() + canSize - min(canSize, k - 5), comb.end(), true); // k - 5를 고려

    do {
        bitset<26> learned = alphabet;

        for (int i = 0; i < canSize; i++) 
        {
            if (comb[i]) {
                learned[can[i] - 'a'] = true;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) 
        {
            bool canRead = true;

            for (int j = 0; j < words[i].size(); j++) 
            {
                if (false == learned[ words[i][j] - 'a' ]) {
                    canRead = false;
                    break;
                }
            }

            if (canRead) {
                cnt++;
            }
        }

        answer = max(answer, cnt);

    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer << "\n";
    

    return 0;
}
