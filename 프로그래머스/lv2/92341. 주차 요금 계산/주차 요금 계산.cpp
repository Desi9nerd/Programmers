#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> inTime;
    map<string, int> totalTime;
    
    for (string record : records) {
        string number = record.substr(6, 4);
        int time = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
        string status = record.substr(11);
        
        if (status == "IN") {
            inTime[number] = time;
        } else { // OUT
            totalTime[number] += time - inTime[number];
            inTime.erase(number);
        }
    }
    
    // 아직 주차장에 있는 차량 처리
    for (auto it : inTime) {
        totalTime[it.first] += 1439 - it.second; // 마지막 시간을 23:59로 계산
    }
    
    vector<pair<string,int>> feePerCar; 
   
     for(auto & car:totalTime){
          int totalFee=0;

          if(car.second <=fees[0]) 
              totalFee=fees[1];
          else 
              totalFee= fees[1]+((car.second-fees[0]-1)/fees[2]+1)*fees[3];

          feePerCar.push_back({car.first,totalFee});
      }

      sort(feePerCar.begin(),feePerCar.end()); 

      vector<int> answer;

      for(auto & car:feePerCar){
          answer.push_back(car.second);
      }

   return answer;
}
