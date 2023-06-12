#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;
vector<char> v;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, input, num=0;
    cin >> n;

    st.push(num++);
    
    for(int i=0; i<n; i++){
        cin >> input;

        while(true){
            if (st.top() == input) break;

            if(st.top()>input){
                cout << "NO";
                return 0;
            }
            st.push(num++);
            v.push_back('+');
        }
        st.pop();
        v.push_back('-');    
    }

	for(const auto& i : v)
	{
        cout << i << "\n";
	}
    
    return 0;
}