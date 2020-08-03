#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int N = 30007, SIZE = 1e6 + 10;
int n;
struct node{
    int x, y, g, h;
    bool operator < (const node &a)const{
        return g + h == a.g + a.h ? h > a.h : g + h > a.g + a.h;
    }
};
struct Node{
    int to, next, w;
};
struct hash_map{
    int head[N], now;
    Node a[SIZE];
    bool insert(int sta, int w){
        int x = sta % N;
        for(int i = head[x]; i; i = a[i].next){
            if(a[i].to == sta){
                if(a[i].w <= w) return 0;
                a[i].w = w; return 1;
            }
        }
        a[++now] = {sta, head[x], w};
        head[x] = now;
        return 1;
    }
}dict;
priority_queue<node> heap;
node now;
int gcd(int a, int b){ return b ? gcd(b, a % b) : a;}
void che(int x, int y){
    if(x < y) swap(x, y);
    if(x > 2 * n) return ;
    if(x > n && y == 0) return ;
    if(x == y) return ;
    if(n % gcd(x, y)) return;
    if(!dict.insert(x * 50000 + y, now.g + 1)) return;
    int h = 0, tx = x;
    while(tx < n) h++, tx <<= 1;
    heap.push({x, y, now.g + 1, h});
}
void A_star(){
    heap.push({1, 0, 0, 0});
    while(!heap.empty()){
        now = heap.top(); heap.pop();
        if(now.x == n || now.y == n){
            printf("%d\n", now.g); break;
        }
        int a[2] = {now.x, now.y};
        for(int i = 0; i < 2; i++)
          for(int j = i; j < 2; j++)
            for(int k = 0; k < 2; k++){
                int b[2] = {a[0], a[1]};
                b[k] = a[i] + a[j];
                che(b[0], b[1]);
            }
        che(now.x - now.y, now.y);
        che(now.x, now.x - now.y);
    }
}
int main(){
    for(int i = 1; i <= 20000; ++i)
    {
        heap.clear();
        dict.now = 0;
        n = i;
        A_star();
    }
    
    return 0;
}