#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string convert(string m) {
    string ret = "";
    for (int i = 0; i < m.size(); i++) {
        if (m[i + 1] == '#') {
            ret += tolower(m[i]);
            i++;
        }
        else {
            ret += m[i];
        }
    }
    return ret;
}

string solution(string m, vector<string> mu) {
    m = convert(m);
    string answer = "(None)";
    int max_length = 0;

    for (string str : mu) 
    {
        int playTime = (stoi(str.substr(6, 2)) - stoi(str.substr(0, 2))) * 60 + stoi(str.substr(9, 2)) - stoi(str.substr(3, 2));
        string title = str.substr(12, str.find(',', 12) - 12);
        string notes = convert(str.substr(str.find(',', 12) + 1));

        string note = "";
        for (int i = 0; i < playTime; i++) {
            note += notes[i % notes.size()];
        }

        if (note.find(m) != string::npos)
        {
            if (playTime > max_length) {
                max_length = playTime;
                answer = title;
            }
        }
    }

    return answer;
}