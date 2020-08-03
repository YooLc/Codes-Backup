#include <iostream>
#include <ctime>
using namespace std;
const int MAXN = 5e8;
int main()
{
    clock_t startTime, endTime;
    startTime = clock(); 
    int ans = 0;
    for (int i = 1; i <= MAXN; ++i) ans++;
    endTime = clock();
    cout << "Runtime is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}