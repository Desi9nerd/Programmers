#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool Compare(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> myMap;
    map<string, vector<pair<int, int>>> playlistMap;

    for (int i = 0; i < genres.size(); i++) {
        myMap[genres[i]] += plays[i];
        playlistMap[genres[i]].push_back({ plays[i], i });
    }

    vector<pair<string, int>> v(myMap.begin(), myMap.end());
    sort(v.begin(), v.end(), Compare);


    for (int i = 0; i < v.size(); i++)
    {
        string genre = v[i].first;
        if (playlistMap.find(genre) != playlistMap.end())
        {
            sort(playlistMap[genre].begin(), playlistMap[genre].end(), [](pair<int,int> a, pair<int,int> b) {
                if (a.first == b.first) return a.second < b.second;
                return a.first > b.first;
                });

            answer.push_back(playlistMap[genre][0].second);
            if (playlistMap[genre].size() >= 2) answer.push_back(playlistMap[genre][1].second);
        }
    }

    return answer;
}