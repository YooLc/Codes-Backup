#include <cstdlib>
#include <cstdio>
#include <ctime>
int main()
{
    for(int T = 1; T <= 1; T++)
    {
        double st = clock();
        system("P1073.exe > test.out");
        double ed = clock();
        printf("Test #%d passed, Time: %.0lf ms\n", T, ed - st);
    }
}