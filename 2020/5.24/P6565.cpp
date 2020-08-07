#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
inline int getSubstringNum(string str, string sub)
{
    int ans = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        for (int j = 0; j < sub.length(); ++j)
        {
            if (str[i + j] != sub[j]) break;
            else if (j == sub.length() - 1) ans++;
        }
    }
    return ans;
}
int main()
{
    int T, mx = 0;
    vector<string> names;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        string name, message;
        cin >> name >> message;
        int t = getSubstringNum(message, "sos");
        if (t > mx) mx = t, names.clear(), names.push_back(name);
        else if (t == mx) names.push_back(name);
    }
    for (int i = 0; i < names.size(); ++i) cout << names[i] << " ";
    cout << endl << mx;
    return 0;
}