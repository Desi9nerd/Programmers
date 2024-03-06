#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<pair<int, double>> v;
	vector<double> answer;

    int n = 0;
    while (k > 1)
    {
        v.push_back({ n, k });

        if (k % 2 == 0){
            k /= 2;
        }
        else {
            k = k * 3 + 1;
        }
        n++;
    }
    v.push_back({ n, k });

    for(int i = 0; i < ranges.size(); i++)
    {
        double temp = 0.0f;

        if(ranges[i][0] > n + ranges[i][1]){
            temp = -1.0f;
        }

	    for(int j = ranges[i][0]; j < n + ranges[i][1]; j++){
            temp += (v[j].second + v[j + 1].second) / 2;
	    }
        
        answer.push_back(temp);
    }

    return answer;
}