#include <iostream>
#include <cstdio>
// #include <vector>
#include <ctime>
using namespace std;
// vector<int> t;
int rand(int n)
{
    return (long long)rand() * rand() % n;
}
int main()
{
    freopen("vector10.in", "w", stdout);
    srand((unsigned)time(0));
    int n = 100, sx = 0, sy = 0, cnt = 0;
    int tss = 100;
    cout << tss << endl;
    for(int i = 1; i <= tss; ++i)
    {
        int rx = rand(5000) - 2500;
        int ry = rand(5000) - 2500;
        cout << rx << " " << ry<<endl;
        if(rand(2) && cnt < 15) cnt++, sx += rx, sy += ry, t.push_back(i);
    }
    cout<<sx<<" " <<sy<<endl;
    cout << t.size() << endl;
}