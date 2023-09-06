#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ch[1001];

bool Comp(pair<int, int>&a, pair<int, int>&b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

int solution(vector<vector<string>> book_time) {

    vector<pair<int, int>> clean(book_time.size());

    for (int i = 0; i < book_time.size(); i++)
    {   
        string temp1 = book_time[i][0];
        int hour1 = (temp1[0] - '0') * 10 + (temp1[1] - '0');
        int min1 = (temp1[3] - '0') * 10 + (temp1[4] - '0');
        string temp2 = book_time[i][1];
        int hour2 = (temp2[0] - '0') * 10 + (temp2[1] - '0');
        int min2 = (temp2[3] - '0') * 10 + (temp2[4] - '0');
        
        clean[i].first = hour1 * 60 + min1;
        clean[i].second = hour2 * 60 + min2 + 10;
        //cout << clean[i].first << " " << clean[i].second << "\n";
    }
    
    sort(clean.begin(), clean.end(), Comp);

    //cout << "\n";
    //for (int i = 0; i < book_time.size(); i++)
    //    cout << clean[i].first << " " << clean[i].second << "\n";

    int answer = 0;
    vector<int> last_end(book_time.size(), -1);
  
    for (int x = 0; x < book_time.size(); x++)
    {
        if (ch[x] == 0)
        {
            for (int i = 0; i < book_time.size(); i++)
            {
                if (clean[i].first >= last_end[x] && ch[i] == 0) {
                    last_end[x] = clean[i].second;
                    ch[i] = 1;
                }
            }

            answer++;
        }
    }
    

    //cout << "answer: " << answer;

    return answer;
}