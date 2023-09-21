#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int is = 0, un = 0; //is: 교집합, un: 합집합

    //둘 다 공집합인 경우
    if (str1.size() == 0 && str2.size() == 0){
        return 65536;
    }

	for(int i=0; i<str1.size(); i++){
		if(isupper(str1[i])){
            str1[i] = tolower(str1[i]);
		}
	}
    for (int i = 0; i < str2.size(); i++) {
        if (isupper(str2[i])) {
            str2[i] = tolower(str2[i]);
        }
    }

    vector<string> s1;
    int x = 0;
    for(int i=0; i<str1.size()-1; i++){
        if('a' <= str1[i] && str1[i] <= 'z' &&
            'a' <= str1[i+1] && str1[i+1] <= 'z')
        {
            string tmp = str1.substr(i, 2); // 두 글자를 추출
            s1.push_back(tmp);
        }
    }
    vector<string> s2;
    x = 0;
    for (int i = 0; i < str2.size()-1; i++) {
        if ('a' <= str2[i] && str2[i] <= 'z' &&
            'a' <= str2[i + 1] && str2[i + 1] <= 'z')
        {
            string tmp = str2.substr(i, 2); // 두 글자를 추출
            s2.push_back(tmp);
        }
    }

    sort(s1.begin(), s1.end()); // 벡터를 정렬
    sort(s2.begin(), s2.end());

    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            is++;
            i++;
            j++;
        } else if (s1[i] < s2[j]) {
            i++;
        } else {
            j++;
        }
    }

    un = s1.size() + s2.size() - is;

    if (un == 0) 
        answer = 65536;
    else
        answer = is * 65536 / un;
    
    return answer;
}