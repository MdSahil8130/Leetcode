#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
string to_string(char s) { return "'" + string(1,s) + "'"; }
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
    if (!first) res += ", ";
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
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long area = 0;

        for(int i=0;i<bottomLeft.size();i++)
        {
            for(int j=i+1;j<topRight.size();j++)
            {
                long long min_x = max(bottomLeft[i][0],bottomLeft[j][0]);
                long long max_x = min(topRight[i][0],topRight[j][0]);
                long long min_y = max(bottomLeft[i][1],bottomLeft[j][1]);
                long long max_y = min(topRight[i][1],topRight[j][1]);
                
                // debug(min_x,max_x,min_y,max_y);
                if(min_x < max_x && min_y < max_y)
                {
                    long long s = min(max_x-min_x, max_y-min_y);
                    area = max(area,s*s);
                }
            }
        }

        return area;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> bottomLeft = {{1,1},{2,2},{3,1}};
    vector<vector<int>> topRight = {{3,3},{4,4},{6,6}};
    Solution sol;
    cout<<sol.largestSquareArea(bottomLeft,topRight)<<endl;

    return 0;
}