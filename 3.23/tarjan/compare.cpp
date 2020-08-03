#include <cstdlib>
#include <cstdio>
#include <ctime>
int main()
{
    for(int T = 1; T <= 10000; T++)
    {
        system("python script.py");
        double st = clock();
        system("wrong.exe <input.in > test.out");
        double ed = clock();
        if(system("fc input.out test.out > 1.txt"))
        {
            puts("WA");
            return 0;
        }
        else printf("Test #%d passed, Time: %.0lf ms\n", T, ed - st);
    }
}