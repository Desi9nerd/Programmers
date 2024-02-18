#include <algorithm>

int answer;

void DFS(tree* node, int currLength)
{
    if(node == nullptr) return;

    answer = max(answer, currLength);

    if(node->l != nullptr){
        DFS(node->l, currLength + 1);
    }
    if(node->r != nullptr){
        DFS(node->r, currLength + 1);
    }
}

int solution(tree* T) {

    DFS(T, 0);

    return answer;
}
