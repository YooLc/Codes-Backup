#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
// nullptr 为 C11 关键字， 不支持该标准的应替换成 NULL
struct Node
{
    int value;
    Node *l, *r;
    Node(int val) { value = val; l = nullptr; r = nullptr; }
};
class binarySearchTree // 指针模拟二叉搜索树 hdu 3791
{
public:
    Node *root;
    void init() { root = nullptr; }
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
            if (val < rt->value)
            {
                if (rt->l == nullptr) rt->l = new Node(val);
                else insert(val, rt->l);
            }
            else
            {   if (rt->r == nullptr) rt->r = new Node(val);
                else insert(val, rt->r);
            }
        }
        else rt = new Node(val);
    }
} ori, comp;
bool check(Node *ort, Node *crt)
{
    if (ort == nullptr && crt == nullptr) return true;
    if (ort == nullptr || crt == nullptr) return false;
    if (ort->value != crt->value) return false;
    return (check(ort->l, crt->l) && check(ort->r, crt->r));
}
int main() 
{
    int n; char ch;
    while(~scanf("%d", &n) && n)
    {
        getchar();
        ori.init();
        do 
        { 
            ch = getchar(); 
            if (isdigit(ch)) 
                ori.insert(ch, ori.root);
        } while (ch != '\n');
        for (int i = 1; i <= n; ++i)
        {
            comp.init();
            do 
            { 
                ch = getchar(); 
                if (isdigit(ch)) 
                    comp.insert(ch, comp.root);
            } while (ch != '\n');
            puts(check(ori.root, comp.root) ? "YES" : "NO");
            comp.clear(comp.root);
        }
        ori.clear(ori.root);
    }
    return 0;
}