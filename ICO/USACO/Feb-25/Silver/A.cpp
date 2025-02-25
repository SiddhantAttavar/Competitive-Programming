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

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        vector<pair<int, int>> v(n);
        rep(i, 0, n) {
            v[i] = {-a[i], i};
        }
        sort(v.begin(), v.end());

        vector<int> s(n);
        s[n - 1] = v[n - 1].second;
        for (int i = n - 2; i >= 0; i--) {
            s[i] = min(s[i + 1], v[i].second);
        }

        vector<pair<int, int>> res;
        bool flag = true;
        rep(i, 0, n) {
            if (res.empty() or res.back().second < v[i].second) {
                res.push_back(v[i]);
            }
            else if (flag and (res.size() == 1 or res[res.size() - 2].second < v[i].second)) {
                res.push_back(v[i]);
                flag = false;
            }
        }
        
        rep(i, 0, res.size() - 1) {
            cout << -res[i].first << " ";
        }
        cout << -res.back().first << endl;
    }
}
