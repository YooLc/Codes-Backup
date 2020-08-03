#include <iostream>
#include <cstdio>
#include <ctime>
class Treap // 左边小右边大的树堆
{
private:
    struct Node
    {
        int val, rank, size;
        Node *l, *r;
        Node(int v, int rk) { val = v; rank = rk; l = nullptr; r = nullptr; size = 1; }
        void update()  
        { 
            size = 1; 
            if (l != nullptr) size += l->size; 
            if (r != nullptr) size += r->size;
        }
    };
public:
    Node *root;
    void init() { root = nullptr; }
    void clear(Node *&rt)
    {
        if (rt == nullptr) return;
        clear(rt->l); clear(rt->r);
        delete rt;
    }
    // 树的旋转 Reference: https://www.bilibili.com/video/BV1wt411u7xL
    void rrotate(Node *&rt) // 右旋拎左右挂左
    {
        Node *son = rt->l;
        rt->l = son->r;
        son->r = rt;
        rt->update();
        son->update();
        rt = son;
    }
    void lrotate(Node *&rt) // 左旋拎右左挂右
    {
        Node *son = rt->r;
        rt->r = son->l;
        son->l = rt;
        rt->update();
        son->update();
        rt = son;
    }
    void insert(int value, Node *&rt)
    {
        if (rt != nullptr)
        {
            if (value < rt->val) insert(value, rt->l); // 插至左子树
            else insert(value, rt->r); // 插至右子树
            rt->update(); // 更新当前节点子树的大小
            if (rt->l != nullptr && rt->rank < rt->l->rank) rrotate(rt); // 左子树优先级更大，根进行右旋，左子树成为新根
            if (rt->r != nullptr && rt->rank < rt->r->rank) lrotate(rt); // 右子树优先级更大，根进行左旋，右子树成为新根
        }
        else rt = new Node(value, rand());
    }
    int kth(int k, Node *rt) // 排名为 k 的元素
    {
        if (rt == nullptr || k <= 0 || k > rt->size) return -1; // 查无此树，k 过小，k 过大
        int leftSize = (rt->l == nullptr) ? 0 : rt->l->size;
        if (k == leftSize + 1) return rt->val;  // 恰好就是根
        else if (k <= leftSize) return kth(k, rt->l); // 去左子树找
        else return kth(k - (leftSize + 1), rt->r); // 去右子树找
    }
    int find(int value, Node *rt) // 值为 value 的排名
    {
        if (rt == nullptr) return -1; // 没找到
        int leftSize = (rt->l == nullptr) ? 0 : rt->l->size;
        if (value == rt->val) return leftSize + 1; // 左子树的大小 + 1
        else if (value < rt->val) return find(value, rt->l); // 去左子树找
        else { int t = find(value, rt->r); return (~t) ? leftSize + 1 + t : -1; }
    }
} t;
const int MAXN = 5e6 + 50;
int id[MAXN];
int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        srand(time(NULL));
        t.init();
        for (int i = 1; i <= n; ++i)
        {
            int d, lvl;
            scanf("%d %d", &d, &lvl);
            id[lvl] = d;
            t.insert(lvl, t.root);
            if (i == 1) { printf("%d %d\n", d, 1); continue; }
            int currk = t.find(lvl, t.root); // 此时是对应的 rank
            int pre, nxt, ans;
            pre = t.kth(currk - 1, t.root);  // 此时是对应的 lvl
            nxt = t.kth(currk + 1, t.root);
            if (~pre && ~nxt) ans = lvl - pre > nxt - lvl ? nxt : pre;
            else if (pre == -1) ans = nxt;
            else ans = pre;
            printf("%d %d\n", d, id[ans]);
        }
        t.clear(t.root);
    }
    return 0;
}