#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int answer;
vector<int> words;

// DFS를 사용하여 알파벳의 조합을 찾는 함수
void DFS(int len, int alpha, int hash)
{
	if (len == k) // 알파벳 k개 선택 완료
	{		
		int result = 0;

		// 현재 hash값으로 읽을 수 있는 word 개수 카운팅
		for (int i = 0; i < n; i++)
		{
			if ((hash & words[i]) == words[i]) { // 현재 선택된 알파벳이 단어에 포함되어 있는지 확인
				result++;
			}
		}

		answer = max(answer, result);
		return;
	}

	// 26개 알파벳 중 아직 선택되지 않은 알파벳을 선택. 26개 알파벳 중 k - 5개 알파벳 선택.
	for (int i = alpha; i < 26; i++)
	{
		if (hash & (1 << i)) continue; // 이미 선택된 알파벳은 건너뛰기

		DFS(len + 1, i + 1, hash | (1 << i));	// 다음 알파벳 선택
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	words.resize(n);

	string input;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		
		for (int j = 0; j < input.size(); ++j) { // 입력 단어에 대한 hash값 계산 후 저장.
			words[i] |= (1 << (input[j] - 'a'));
		}
	}
	
	
	int hash = 0;
	string essentialAlphabet = "acint";
	for (int i = 0; i < essentialAlphabet.size(); i++)
	{
		hash |= (1 << (essentialAlphabet[i] - 'a')); // 필수 알파벳 'a', 'c', 'i', 'n', 't'를 hash에 추가.
	}


	if (k < 5) { // k가 5보다 작은 경우는 필수 알파벳만으로는 단어를 읽을 수 없으므로 0 출력
		cout << "0";
	}
	else if (k >= 26){ // k가 26인 경우는 모든 알파벳을 배울 수 있으므로 모든 단어를 읽을 수 있음
		cout << n;
	}
	else
	{
		DFS(5, 0, hash); // 5는 필수 알파벳을 이미 선택했으므로 DFS를 5에서 시작

		cout << answer;
	}

	return 0;
}