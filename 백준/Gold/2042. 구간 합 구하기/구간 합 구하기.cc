#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
vector<long long> v;  

long long segTree[4000004];

long long init(int start, int end, int nodeNum)  //start : 시작 인덱스, end : 끝 인덱스
{
    if (start == end)
        return segTree[nodeNum] = v[start]; //리프 노드

    int mid = (start + end) / 2;

    return segTree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

long long subSum(int start, int end, int nodeNum, int left, int right) //start, end : 해당 노드의 시작, 끝 인덱스, left, right : 구간 합 구하고자 하는 범위
{
    if (left > end || right < start)
        return 0;

    if (left <= start && end <= right)
        return segTree[nodeNum]; //완전히 포함 (6~11 구하고 싶은데 해당 노드가 6~8일 때)
    
    int mid = (start + end) / 2;

    return subSum(start, mid, nodeNum * 2, left, right) + subSum(mid + 1, end, nodeNum * 2 + 1, left, right);
}

void update(int start, int end, int nodeNum, int targetIdx, long long val)
{
    if (targetIdx < start || end < targetIdx)
        return;

    segTree[nodeNum] += val;
    
    if (start == end)
        return;
    
    int mid = (start + end) / 2;
    update(start, mid, nodeNum * 2, targetIdx, val);
    update(mid + 1, end, nodeNum * 2 + 1, targetIdx, val);
}

int main(){
    cin >> n >> m >> k;
    v.resize(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    init(0, n - 1, 1);  // 세그먼트트리 만들기 (트리 인덱스는 1부터 ~ )

    long long a, b, c;
    for (int i = 0; i < m + k; i++)
    {
        cin >> a >> b >> c;
        if (a == 1) // b번째 인덱스를 c로 바꾸기. 바뀐 차이 만큼 트리 각 노드에 더해줘야함.
        { 
            long long tmp = c - v[b - 1];	// v 값 바꾸기 전에 값 저장해놓아야 파라미터로 넘길 수 있음
            v[b - 1] = c;
            update(0, n - 1, 1, b - 1, tmp);
        }
        else //b~c 합(b=3, c = 7이면 v[2]~v[6] 구해야 함)
        { 
            cout << subSum(0, n - 1, 1, b - 1, c - 1) << "\n";
        }
    }

    return 0;
}