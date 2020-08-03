#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> pre, in;
class binarySearchTree // 指针模拟二叉搜索树 hdu 3999
{
private:
    const static int MAXN = 1e5 + 50;
    struct Node
    {
        int value;
        Node *l, *r;
        Node(int val) { value = val; l = nullptr; r = nullptr; }
    };
public:
    Node *root = nullptr;
    void clear(Node *&rt)
    {
        if (rt == nullptr) return;
        clear(rt->l); clear(rt->r);
        delete rt;
    }
    void insert(int val, Node *&rt)
    {
        if (rt != nullptr) 
        {
            if (val < rt->value) // 比根节点小，往左子树插入
            {
                if (rt->l == nullptr) rt->l = new Node(val);
                else insert(val, rt->l);
            }
            else                   // 比根节点大，往右子树插入
            {   if (rt->r == nullptr) rt->r = new Node(val);
                else insert(val, rt->r);
            }
        }
        else rt = new Node(val);
    }
    int getMin(Node *rt) { return (rt->l == nullptr) ? rt->value : getMax(rt->l); }
    int getMax(Node *rt) { return (rt->r == nullptr) ? rt->value : getMax(rt->r); }
    void preOrder(Node *rt) // 建立相同树的字典序最小的建树顺序
    {
        if (rt != nullptr)
        {
            pre.push_back(rt->value);
            preOrder(rt->l);
            preOrder(rt->r);
        }
    }
    void inOrder(Node *rt)  // 从小到大排序
    {
        if (rt != nullptr)
        {
            inOrder(rt->l);
            in.push_back(rt->value);
            inOrder(rt->r);
        }
    }
};
int main() 
{
    int n, u;
    while(~scanf("%d", &n))
    {
        binarySearchTree bst;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &u);
            bst.insert(u, bst.root);
        }
        pre.clear();
        bst.preOrder(bst.root);
        printf("%d", pre[0]);
        for (unsigned int i = 1; i < pre.size(); ++i) printf(" %d", pre[i]);
        printf("\n");
    }
    return 0;
}