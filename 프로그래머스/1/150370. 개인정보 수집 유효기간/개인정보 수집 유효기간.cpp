#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> myMap;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int tYear = stoi(today.substr(0,4));
    int tMonth = stoi(today.substr(5,2));
    int tDay = stoi(today.substr(8,2));
    //cout << tyear << ", " << tmonth << ", " << tday << "\n";
    
    for(int i = 0; i < terms.size(); i++){
        string alpha = terms[i].substr(0,1);
        int beta = stoi(terms[i].substr(2));
        //cout << alpha << ", " << beta << "\n";
        myMap[alpha] = beta;
    }
    
    
    for(int i = 0; i < privacies.size(); i++)
    {        
        int year = stoi(privacies[i].substr(0,4));
        int month = stoi(privacies[i].substr(5,2));
        int day = stoi(privacies[i].substr(8,2));
        string term = privacies[i].substr(11,1);
        //cout << year << ", " << month << ", " << day << ", " << term << "\n";
        
        int newYear = year;
        int newMonth = month;
        int newDay = day;
        
        if(myMap.find(term) != myMap.end())
        {
            if(myMap[term] == 0) continue;
            
            newMonth += myMap[term];
            
            if(newDay == 1){
                newDay = 28;
                newMonth--;
            }
            else{
                newDay--;
            }
            
            if (newMonth > 12)
            {
                newYear += (newMonth - 1) / 12;
                newMonth = (newMonth - 1) % 12 + 1;
            }
            
        }
        
        if(newYear < tYear) answer.emplace_back(i+1);
        else if(newYear == tYear && newMonth < tMonth) answer.emplace_back(i+1);
        else if(newYear == tYear && newMonth == tMonth && newDay < tDay) answer.emplace_back(i+1);
    }
    
    
    return answer;
}