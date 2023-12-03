#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int t;
string p; // 수행할 함수
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> p;
		cin >> n;
		string input;
		cin >> input;
		deque<int> num;
		int tmp = 0;
		bool blank = true;
		for(int i=0; i<input.size(); i++){
			if ('0' <= input[i] && input[i] <= '9'){
				tmp = tmp * 10 + (input[i] - '0');  // 숫자를 읽어들일 때 마다 10을 곱하고 새로운 숫자를 더함
				blank = false;
			}
			else if (input[i] == ',' || input[i] == ']'){  // ',' 또는 ']'를 만나면 지금까지 읽어들인 숫자를 덱에 삽입
				if (blank == true) continue;
				num.push_back(tmp);
				tmp = 0;  // 임시 변수 초기화
			}
		}
		
		int Rcnt = 0;
		vector<bool> fOb;
		bool fb = true;
		for(int i=0; i<p.size(); i++)
		{
			if(p[i] == 'R'){
				Rcnt++;
				fb = fb ? false : true;
			}
			else if(p[i] == 'D'){
				if (fb) fOb.push_back(true);
				else fOb.push_back(false);
			}
		}

		if(Rcnt % 2 == 1) // R 홀수
		{
			deque<int> temp;
			for (int i = num.size() - 1; i >= 0; i--) {
				temp.push_back(num[i]);
			}

			bool error = false;
			for (int i = 0; i < fOb.size(); i++)
			{
				if (temp.size() == 0) {
					cout << "error\n";
					error = true;
					break;
				}
				if (fOb[i] == true) temp.pop_back();
				else temp.pop_front();
			}

			if (error) continue;
			else{ // 출력				
				cout << "[";
				for (int i = 0; i < temp.size(); i++) {
					cout << temp[i];
					if (i == temp.size() - 1) break;
					cout << ",";
				}
				cout << "]\n";				
			}			
		}
		else // R 짝수
		{
			bool error = false;
			for (int i = 0; i < fOb.size(); i++)
			{
				if (num.size() == 0) {
					cout << "error\n";
					error = true;
					break;
				}

				if (fOb[i] == true) num.pop_front();
				else num.pop_back();
			}

			if (error) continue;
			else { // 출력
				cout << "[";
				for (int i = 0; i < num.size(); i++) {
					cout << num[i];
					if (i == num.size() - 1) break;
					cout << ",";
				}
				cout << "]\n";
			}		
		}		
	}

	return 0;
}