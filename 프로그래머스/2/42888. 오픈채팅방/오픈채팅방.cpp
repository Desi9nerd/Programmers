#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, string> idNname;
vector<pair<string, string>> index;

vector<string> solution(vector<string> record) {
    vector<string> answer;
        
    for(int i=0; i<record.size(); i++)
    {
        stringstream ss(record[i]);
        string command, id, name;
        ss >> command >> id >> name;

        if(command == "Enter")
        {
            if(id != "") // 이전에 들어갔다 나간 후 다시 들어온 경우
                idNname[id] = name;
            else // 처음 들어온 경우
                idNname.insert({id, name });

            index.push_back({ command, id });
        }
        else if (command == "Leave") 
        {
            index.push_back({ command, id });
        }
        else if (command == "Change") 
        {
            idNname[id] = name;
        }	           
    }

    for (int i =0; i<index.size(); i++)
    {
        if (index[i].first == "Enter"){
            answer.push_back(idNname[index[i].second] + "님이 들어왔습니다.");
        }
        else if (index[i].first == "Leave"){
            answer.push_back(idNname[index[i].second] + "님이 나갔습니다.");
        }        
    }

    return answer;
}
