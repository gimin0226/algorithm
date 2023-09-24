#include<bits/stdc++.h>

using namespace std;
long long num = 0;
unordered_map<string, long long> um;

long long f(string str2) {
    //cout << str2 << endl;
    if (um.find(str2) != um.end()) {
        num += um[str2];
        return um[str2];
    }
    if (str2.length() == 2) {
        long long count = 0;
        int a = str2[0] - '0'; int b = str2[1] - '0';
        if (a != 0) {
            if (10 * a + b <= 26)count++;
            if (b != 0) {
                count++;
            }

        }
        num = (num + count) % 1000000;
        um[str2] = count;
        return count;
    }
    if (str2.length() == 3) {
        long long count = 0;
        int a = str2[0] - '0'; int b = str2[1] - '0'; int c = str2[2] - '0';
        if (a != 0) {
            if (b == 0) {
                if (c != 0) {
                    if (10 * a + b <= 26)count++;
                }
            }
            else {
                if (c == 0) {
                    if (10 * b + c <= 26) {
                        count++;
                    }
                }
                else {
                    if (10 * b + c <= 26)count++;
                    if (10 * a + b <= 26)count++;
                    count++;
                }
            }
            num = (num + count) % 1000000;
            um[str2] = count;
            return count;
        }
    }
    string s1 = str2.substr(0, 1);
    string s2 = str2.substr(0, 2);
    // cout << s1 << " " << s2 << '\n';
    long long count = 0;
    if (s1 == "0")return 0;
    count =(count+ f(str2.substr(1, str2.length() - 1))% 1000000);

    int n = stoi(s2);
    if (n <= 26) {
        count =(count+ f(str2.substr(2, str2.length() - 2))%1000000);
    }
    um[str2] = count;
    return count;
}



int main(void) {
	
    string str;
    cin >> str;
    if (str == "0") {
        cout << 0;
        return 0;
    }
    if (str.length() == 1) {
        cout << 1;
        return 0;
    }
    f(str);
    cout << num% 1000000;

   

    return 0;

}
