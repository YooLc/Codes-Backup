#include <iostream>
using namespace std;
int main()
{
    freopen("magic.in", "w", stdout);
    cout << 20 << " " << 19 << " " << 1000 << endl;
    for (int i = 1; i <= 20; i++) cout << i * 1077990 % 99061 << " ";
    cout << endl;
    for (int i = 1; i < 20; ++i) cout << i << " " << i + 1 << endl;
    for (int i = 1; i <= 1000; ++i) cout << i << endl;
    return 0;
}