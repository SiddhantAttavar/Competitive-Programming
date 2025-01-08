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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        map<int, pair<int, int>> m;
        range(i, 0, n) {
            if (!m.count(a[i])) {
                m[a[i]] = {i, i};
            }
            else {
                m[a[i]].second = i;
            }
        }

        vector<pair<int, int>> v;
        for (pair<int, pair<int, int>> p : m) {
            if (p.second.first != p.second.second) {
                v.push_back(p.second);
            }
        }

        if (v.empty()) {
            print(0);
            continue;
        }

        sort(v.begin(), v.end());
        vector<pair<int, int>> w = {v[0]};
        range(i, 1, v.size()) {
            if (v[i].first <= w.back().second) {
                w.back().second = max(w.back().second, v[i].second);
            }
            else {
                w.push_back(v[i]);
            }
        }

        int res = 0;
        for (pair<int, int> p : w) {
            set<int> b;
            range(i, p.first, p.second + 1) {
                b.insert(a[i]);
            }
            res += b.size();
        }
        print(res);
    }
}
