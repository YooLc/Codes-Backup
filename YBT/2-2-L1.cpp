#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/*
    Function: Get Prefix Function of a String
    Reference Link: https://cp-algorithms.com/string/prefix-function.html
    1.  Compute the prefix values pref[i] in a loop by iterating from 1 ... len - 1
    2.  To calculate the current value pref[i], we set the caribale j denoting the length of the best
        suffix for i - 1. Initially j = pref[i - 1]
    3.  Test if the suffix of length j + 1 is also a prefix by comparing s[j] and s[i].
        If they are equal, then we assign pref[i] = j + 1, 
        otherwise we reduce j to pref[j - 1] and repeat this step.
    4.  If we have reached the length j = 0 and still don't have a match,
        then we assign pref[i] = 0 and go to the next index i + 1.
*/
inline vector<int> getPrefix(string s)
{
    unsigned int len = s.size();
    vector<int> pref(len);
    for (int i = 1; i < len; ++i)
    {
        int j = pref[i - 1]; 
        while (j > 0 && s[i] != s[j]) j = pref[j - 1];
        if (s[i] == s[j]) ++j;
        pref[i] = j;
    }
    return pref;
}
int main() 
{ 
    int len; string str;
    cin >> len >> str;
    long long ans = 0; vector<int> pref = getPrefix(str);
    for (auto i: pref) cout << i << " ";
    cout << endl;
    for (int i = 0; i < len; ++i) ans += pref[i];
    cout << ans;
    return 0;
}