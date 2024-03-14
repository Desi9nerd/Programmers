#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Info {
    string subject; int time, duration;

    Info(string a, int b, int c) {
        subject = a;
        time = b;
        duration = c;
    }
    
    bool operator<(const Info& oper) const{
        return time < oper.time;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    int n = plans.size();
    vector<string> answer;
    vector<Info> v;
    stack<Info> st;

    for (int i = 0; i < n; i++)
    {
        string subject = plans[i][0];
        string time = plans[i][1];
        string duration = plans[i][2];
        int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 5)); // 분 단위
        int dur = stoi(plans[i][2]);

        v.push_back({ subject, t, dur });
    }
    sort(v.begin(), v.end());

    for (int i = 1; i < n; i++)
    {
        if (v[i - 1].time + v[i - 1].duration <= v[i].time) {
            answer.push_back(v[i - 1].subject);

            int leftTime = v[i].time - (v[i - 1].time + v[i - 1].duration);
            
            while (leftTime && !st.empty())
            {
                if (leftTime >= st.top().duration) {
                    leftTime -= st.top().duration;
                    answer.push_back(st.top().subject);
                    st.pop();
                }
                else { // leftTime < Q.front().duration
                    st.top().duration -= leftTime;
                    leftTime = 0;
                }
            }
        }
        else {
            v[i - 1].duration -= (v[i].time - v[i - 1].time);
            st.push({ v[i - 1].subject, v[i - 1].time, v[i - 1].duration });
        }

        if (i == n - 1) { // 맨 마지막 과제 소요 시간과 상관없이 끝낸다
            answer.push_back(v[i].subject);
        }
    }

    while (!st.empty()) // 아직 끝내지 못한 과제 순차적으로 끝냄
    {
        answer.push_back(st.top().subject);
        st.pop();
    }

    return answer;
}
