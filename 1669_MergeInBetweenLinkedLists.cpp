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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    class Solution {
    public:
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode* prev = NULL, *right = NULL;
            auto head = list1;

            int id = 0;
            while(head)
            {
                if(id==a-1)
                prev = head;
                if(id==b+1)
                right = head;

                head = head->next;
                id++;
            }

            ListNode* endList = list2;
            while(endList->next)
            {
                endList = endList->next; 
            }

            prev->next = list2;
            endList->next = right;

            return list1;    
        }
    };


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002] test cases

    ListNode *list1 = new ListNode(10);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(13);
    list1->next->next->next = new ListNode(6);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(5);
    
    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    Solution sol;
    auto res = sol.mergeInBetween(list1, 3, 4, list2);
    while(res)
    {
        cout << res->val << " ";
        res = res->next;
    }



    return 0;
}