#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define TIII tuple<int, int, int>

struct Node
{
    Node(int x, int y, int idx)
        : x(x), y(y), idx(idx)
    {};
    
    int x;
    int y;
    int idx;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinaryTree
{
public:
    BinaryTree() {};
    
    void AddNode(int x, int y, int idx)
    {
        Node* newNode = new Node(x, y, idx);
        if(root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node* current = root;
            while(true)
            {
                if(current->x > newNode->x)
                {
                    if(current->left == nullptr)
                    {
                        current->left = newNode;
                        newNode->parent = current;
                        return;
                    }
                    else
                        current = current->left;
                }
                else
                {
                    if(current->right == nullptr)
                    {
                        current->right = newNode;
                        newNode->parent = current;
                        return;
                    }
                    else
                        current = current->right;
                }
            }
        }
    }
    
    void PreOrder(Node* node, vector<int>& v)
    {
        v.emplace_back(node->idx);
        
        if(node->left != nullptr)
            PreOrder(node->left, v);
        
        if(node->right != nullptr)
            PreOrder(node->right, v);
    }
    
    void PostOrder(Node* node, vector<int>& v)
    {
        if(node->left != nullptr)
            PostOrder(node->left, v);
        
        if(node->right != nullptr)
            PostOrder(node->right, v);
        
        v.emplace_back(node->idx);
    }
    
    Node* GetRoot()
    {
        return root;
    }
    
private:
    Node* root = nullptr;
};

struct cmp
{
    bool operator()(TIII a, TIII b)
    {
        return get<1>(a) < get<1>(b);
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    priority_queue<TIII, vector<TIII>, cmp> pq;
    
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        pq.push(TIII(nodeinfo[i][0], nodeinfo[i][1], i+1));
    }
    
    BinaryTree bt;
    
    while(!pq.empty())
    {
        TIII node = pq.top();
        pq.pop();
        
        bt.AddNode(get<0>(node), get<1>(node), get<2>(node));
    }
    
    vector<int> v1;
    bt.PreOrder(bt.GetRoot(), v1);
    answer.push_back(v1);
    
    vector<int> v2;
    bt.PostOrder(bt.GetRoot(), v2);
    answer.push_back(v2);
    
    return answer;
}