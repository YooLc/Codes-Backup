#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 1e5 + 50, MOD = 1e4 + 7;
char expr[MAXN], fin[MAXN << 1];
typedef long long LL;
typedef struct Node
{
    LL f[2], type;
    char data;
    struct Node *l, *r;
}* nodePtr;
/*
    Referecence: https://www.geeksforgeeks.org/program-to-convert-infix-notation-to-expression-tree/
    Implemented By: YooLc
*/
nodePtr newNode(char c)
{
    nodePtr t = new Node;
    if (isdigit(c)) t->type = t->f[0] = t->f[1] = 1LL;
    else t->type = t->f[0] = t-> f[1] = 0LL;
    t->data = c;
    t->l = t->r = nullptr;
    return t;
}
inline Node* buildTree(string str)
{
    stack<Node*> stN;
    stack<char> stC;
    int priority[255] = { 0 }; // ASCII
    priority['+'] = 1;
    priority['*'] = 2;
    Node* root;
    for (unsigned i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(') { stC.push(str[i]); }
        else if (isdigit(str[i]))  // It's an operand.
        {
            Node* t = newNode(str[i]);
            stN.push(t);
        }
        else if (priority[(int)str[i]])
        {
            // An operator with lower or same associativity appears.
            while (!stC.empty() && stC.top() != '(' && priority[(int)stC.top()] >= priority[(int)str[i]])
            {
                Node* t = newNode(stC.top()); stC.pop();
                Node* r = stN.top(); stN.pop();
                Node *l = stN.top(); stN.pop();
                t->l = l;
                t->r = r;
                stN.push(t);
            }
            stC.push(str[i]);
        } 
        else if (str[i] == ')')
        {
            while (!stC.empty() &&  stC.top() != '(')
            {
                Node* t = newNode(stC.top()); stC.pop();
                Node* r = stN.top(); stN.pop();
                Node* l = stN.top(); stN.pop();
                t->l = l;
                t->r = r;
                stN.push(t);
            }
            stC.pop(); // Pop '('
        }
    }
    root = stN.top();
    return root;
}
inline void preOrder(Node* rt)
{
    if (rt == nullptr) return;
    if (true) 
    {
        cout <<"Node of:" << rt->data;
        if (rt->l) cout << " l:" << rt->l->data;
        if (rt->r) cout << " r:" << rt->r->data;
        cout << endl;
        cout << "f[0]: " << rt->f[0] << " f[1]:"  << rt->f[1] << endl;
    }
    preOrder(rt->l);
    preOrder(rt->r);
}
inline void calcSum(Node* rt)
{
    if (rt == nullptr || rt->type) return;
    calcSum(rt->l); calcSum(rt->r);
    if (rt->data == '+')
    {
        rt->f[0] = (rt->l->f[0] * rt->r->f[0]) % MOD;
        rt->f[1] = ((rt->l->f[0] * rt->r->f[1]) % MOD +
                    (rt->l->f[1] * rt->r->f[0]) % MOD +
                    (rt->l->f[1] * rt->r->f[1]) % MOD) % MOD;
    }
    else
    {
        rt->f[1] = (rt->l->f[1] * rt->r->f[1]) % MOD;
        rt->f[0] = ((rt->l->f[0] * rt->r->f[0]) % MOD +
                    (rt->l->f[0] * rt->r->f[1]) % MOD +
                    (rt->l->f[1] * rt->r->f[0]) % MOD) % MOD;
    }
    
}
inline void removeTree(Node* &root)
{
    if (root == nullptr) return;
    removeTree(root -> l);
    removeTree(root -> r);
    delete root;
}
int main() 
{
#ifndef ONLINE_JUDGE
    freopen("P1310_2.in", "r", stdin);
    freopen("P1310.out", "w", stdout);
#endif
    string fin, expr;
    int l;
    cin >> l >> expr;
    fin = "(";
    for (unsigned i = 0; i < expr.size(); ++i)
    {
        if (expr[i] == '*' ||  expr[i] == '+')
        {
            if ((fin.size() && fin[fin.size() - 1] == '(') || !expr.size())
                fin += '0';
            fin += expr[i];
            if (expr[i + 1] != '(') fin += '0';
        }
        else fin += expr[i];
    }
    fin += ')';
    // cout << fin << endl;
    Node* rt = buildTree(fin);
    calcSum(rt);
    cout << rt->f[0] % MOD<< endl;
    // preOrder(rt);
    removeTree(rt);
    return 0;
}