#include<bits/stdc++.h>
using namespace std;
 
int N, K;
int cnt;
 
int main()
{
    string s;
    cin >> N >> K;
    cin >> s;
    stack<char> st;
    stack<char> st2;
    for (int i = 0; i < s.size(); i++)
    {
        while (!st.empty() && cnt < K && s[i] > st.top())
        {
            cnt++;
            st.pop();
        }
        st.push(s[i]);
    }
    while (cnt < K)
    {
        cnt++;
        st.pop();
    }
    while (!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }
    while (!st2.empty())
    {
        cout << st2.top();
        st2.pop();
    }
    return 0;
}
