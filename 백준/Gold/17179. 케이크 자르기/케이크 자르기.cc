#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l;
vector<int> v;

bool isValid(int givenCnt, int piecelength)
{
    int cnt = 0;
    int cuttingLocation = 0;

    for(int i = 0; i < m && cnt < givenCnt; i++)
    {
        if (v[i] - cuttingLocation >= piecelength)
        {
            cnt++;
            cuttingLocation = v[i];
        }
    }

    if(cnt == givenCnt && l - cuttingLocation >= piecelength)
        return true;

    return false;
}

int Cut(int givenCnt, int length)
{
    int left = 1;
    int right = length;
    int mid;
    int result = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if(isValid(givenCnt, mid))
        {
            result = mid;
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> l;

    v.resize(m);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        int givenCnt;
        cin >> givenCnt;
        
        cout << Cut(givenCnt, l) << '\n';
    }
    
    return 0;
}
