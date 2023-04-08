#include <iostream>
#include <string>
 
using namespace std;
 
int main() 
{
    string str;
    cin>>str;
 
    int len = str.length();
 
    int cnt=0;
 
    for(int i=0; i<len/2; i++)
    {
        if(str[i]!=str[str.length()-1-i])
        {
            cout<<"0"<<"\n";
            // 첫글자와 마지막 글자가 같지 않으면 바로 끝냄.
            return 0;
        }
    }
    cout<<"1"<<"\n";
}