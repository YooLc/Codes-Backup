#include <string>
#include <iostream>
using namespace std;

int main() {
    string ans =
        "ABBBC"
        "BAACB"
        "CBAAD"
        "TTTTAD"
        "FTFTAA"
        "FFTTBA"
        "ABCDA"
        "BCDAB";
    int no;
    cin >> no;
    cout << ans[no - 1];
    return 0;
}