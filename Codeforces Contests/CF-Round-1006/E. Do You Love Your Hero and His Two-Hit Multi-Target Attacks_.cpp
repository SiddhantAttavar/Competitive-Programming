#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int check(vector<pair<int, int>> &a) {
    assert(a.size() <= 500);
    set<pair<int, int>> s(a.begin(), a.end());
    map<int, int> x, y;
    for (pair<int, int> p : a) {
        x[p.first]++;
        y[p.second]++;
    }
    int res = 0;
    for (pair<int, int> p : x) {
        res += p.second * (p.second - 1) / 2;
    }
    for (pair<int, int> p : y) {
        res += p.second * (p.second - 1) / 2;
    }
    return res;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int k;
        input(k);

        vector<int> v;
        int o = k;
        for (int i = 450; i > 1; i--) {
            while (o >= i * (i - 1) / 2) {
                v.push_back(i);
                o -= i * (i - 1) / 2;
            }
        }
        // arrprint(v);

        vector<pair<int, int>> res;
        int t = 0;
        for (int x : v) {
            rep(i, t, t + x) {
                res.push_back({i, t});
            }
            t += x;
        }

        print(res.size());
        for (pair<int, int> p : res) {
            cout << p.first << ' ' << p.second << endl;
        }
        // print(check(res), k);
        // cout.flush();
        assert(check(res) == k);
    }
}
