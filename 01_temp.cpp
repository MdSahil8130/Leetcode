#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
string to_string(char s) { return "'" + string(1, s) + "'"; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "1" : "0"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename T>
string to_string(const std::vector<T> &vec)
{
    bool first = true;
    string result = "{";
    for (const auto &elem : vec)
    {
        if (!first)
            result += ", ";
        first = false;
        result += to_string(elem);
    }
    result += "}";
    return result;
}
template <typename T, typename Container, typename Compare>
string to_string(const std::priority_queue<T, Container, Compare> &pq)
{
    auto temp = pq;
    bool first = true;
    string result = "{";
    while (!temp.empty())
    {
        if (!first)
            result += ", ";
        first = false;
        result += to_string(temp.top());
        temp.pop();
    }
    result += "}";
    return result;
}
// for queue
template <typename T, typename Container>
string to_string(const std::queue<T, Container> &q)
{
    auto temp = q;
    bool first = true;
    string result = "{";
    while (!temp.empty())
    {
        if (!first)
            result += ", ";
        first = false;
        result += to_string(temp.front());
        temp.pop();
    }
    result += "}";
    return result;
}
// for stack
template <typename T, typename Container>
string to_string(const std::stack<T, Container> &s)
{
    auto temp = s;
    bool first = true;
    string result = "{";
    while (!temp.empty())
    {
        if (!first)
            result += ", ";
        first = false;
        result += to_string(temp.top());
        temp.pop();
    }
    result += "}";
    return result;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
            res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

typedef long long ll;
// #define int ll
#define endl '\n'

const ll mod = 1000000007;
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> mpp;
        for(auto it : word)
        mpp[it]++;

        int ans = 1e9;
        for(auto i : mpp)
        {
            int res = 0;
            int bound = i.second;

            debug(bound,i.first);
            for(auto i : mpp)
            {
                debug(i.first,i.second);
                if(i.second<bound)res+=i.second;
                else if(i.second>bound+k) res+=i.second-(bound+k);
            }
            if(ans==0)
            break;
            ans = min(ans,res);
            debug(ans);
        }

        return ans==INT_MAX?0 : ans;
    }
};



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // word = "dabdcbdcdcd", k = 2 test case

    string word = "dabdcbdcdcd";
    int k = 2;

    Solution sol;
    cout << sol.minimumDeletions(word, k) << endl;


    return 0;
}