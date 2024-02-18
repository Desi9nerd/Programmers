#include <algorithm>
using namespace std;

int answer;

int Merge(vector<int>& v, int left, int mid, int right) 
{
  int i = left;
  int j = mid;
  int k = 0;

  int invCount = 0;
  int temp[(right - left + 1)];
 
  while ((i < mid) && (j <= right)) 
  {
    if (v[i] <= v[j]) {
      temp[k] = v[i];
      ++k;
      ++i;
    } 
    else {
      temp[k] = v[j];
      invCount += (mid - i);
      ++k;
      ++j;
    }
  }
 
  while (i < mid) {
    temp[k] = v[i];
    ++k;
    ++i;
  }
 
  while (j <= right) {
    temp[k] = v[j];
    ++k;
    ++j;
  }
 
  for (i = left, k = 0; i <= right; i++, k++) {
    v[i] = temp[k];
  }
 
  return invCount;
}

int MergeSort(vector<int>& v, int left, int right) 
{
  int cnt = 0;
 
  if (left < right) 
  {
    int mid = (right + left) / 2;

    cnt = MergeSort(v, left, mid);
    cnt += MergeSort(v, mid + 1, right);
    cnt += Merge(v, left, mid + 1, right);
  }

  return cnt > 1000000000 ? -1 : cnt; // 문제조건: 100000000초과일 때 -1 리턴
}

int solution(vector<int> &A) {
    
    return MergeSort(A, 0, A.size()-1);
}
