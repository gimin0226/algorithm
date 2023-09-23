#include<bits/stdc++.h>
using namespace std;

string str;

void f(string str2) {
    if (str == str2) {
        cout << "1";
        exit(0);
    }
    if (str.length() >= str2.length()) {
        return;
    }
    if (str2.back() == 'A') {
        str2.pop_back();
    //    cout <<"afs"    << str2 << endl;
        f(str2);
        str2=str2 + "A";
    }
     if (str2.front() == 'B') {
        
        reverse(str2.begin(), str2.end());
        str2.pop_back();
     //   cout <<"aaa"<< str2 << endl;
        f(str2);

    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str2;
    cin >> str;
    cin >> str2;
    f(str2);
    cout << "0";
}
