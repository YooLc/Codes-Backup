#include <iostream>
using namespace std;
int main()
{
    freopen("test.in", "w", stdout);
    cout << 100 << " " << 50 << endl;
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 1; j <= 50; ++j) cout << j << " ";
        cout << endl;
    }
    return 0;
}