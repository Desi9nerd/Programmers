#include <string>
#include <vector>
#include <set>
using namespace std;

set<set<string>> result;
vector<bool> visited;

bool isMatch(const string& user, const string& banned)
{
    if (user.size() != banned.size()) return false;

    for (int i = 0; i < user.size(); i++){
        if (banned[i] != '*' && user[i] != banned[i]) return false;
    }

    return true;
}

void FindCombination(const vector<string>& user, const vector<string>& banned, int idx, set<string> currentSet)
{
    if (idx == banned.size()) {
        result.insert(currentSet);
        return;
    }

    for (int i = 0; i < user.size(); i++)
    {
	    if (false == visited[i] && isMatch(user[i], banned[idx]))
	    {
            visited[i] = true;
            currentSet.insert(user[i]);
            FindCombination(user, banned, idx + 1, currentSet);
            visited[i] = false;
            currentSet.erase(user[i]);
	    }
    }
}

int solution(vector<string> user, vector<string> banned) {

    visited.resize(user.size(), false);
    set<string> emptySet;

    FindCombination(user, banned, 0, emptySet);

    return result.size();
}