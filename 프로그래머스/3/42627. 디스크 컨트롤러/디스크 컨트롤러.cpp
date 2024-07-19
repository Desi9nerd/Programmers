#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), Compare);
    
    int time = 0, start = 0;

    while (!jobs.empty())
    {
	    for (int i = 0; i < jobs.size(); i++)
	    {
		    if (jobs[i][0] <= start){
                time += start + (jobs[i][1] - jobs[i][0]);
                start += jobs[i][1];
                jobs.erase(jobs.begin() + i);
                break;
		    }

            if (i == jobs.size() - 1) start++;
	    }
    }

    return time / n;
}