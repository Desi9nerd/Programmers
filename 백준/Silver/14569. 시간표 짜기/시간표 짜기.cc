#include <iostream>
#include <vector>
using namespace std;

int n; // 총 과목의 수
int m; // 학생의 수
vector<unsigned long long> lectures;

unsigned long long ConvertToBinary(const vector<int>& times)
{
    unsigned long long binary = 0;

    for (int i = 0; i < times.size(); i++){
        binary |= (1ULL << times[i]);
    }

    return binary;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    lectures.resize(n);
    for (int i = 0; i < n; i++)
    {
        int k; // 각 과목의 수업시간의 수
        cin >> k;
        vector<int> times(k);
        for (int j = 0; j < k; j++){
            cin >> times[j];
        }
        lectures[i] = ConvertToBinary(times);
    }

    cin >> m; // 학생 수
    for (int i = 0; i < m; i++)
    {
        int p; // (각 학생 당) 비어 있는 교시 개수
        cin >> p;
        vector<int> students(p);
        for (int j = 0; j < p; j++){
            cin >> students[j];
        }

        unsigned long long studentBitmask = ConvertToBinary(students);

        int cnt = 0;
        for (int j = 0; j < lectures.size(); j++)
        {
            if ((studentBitmask & lectures[j]) == lectures[j]) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}