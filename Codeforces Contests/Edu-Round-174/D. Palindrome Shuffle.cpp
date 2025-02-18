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

bool check(int k, string s) {
    vector<int> f(26, 0);
    range(i, 0, k) {
        f[s[i] - 'a']++;
    }

    range(i, k, s.size()) {
        if (i < s.size() - i - 1) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        else if (s.size() - i - 1 < k) {
            if (f[s[i] - 'a'] == 0) {
                return false;
            }
            f[s[i] - 'a']--;
        }
    }

    int x = 0;
    range(i, 0, 26) {
        x += f[i] % 2;
    }
    return x <= 1;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        string s;
        input(s);

        deque<char> d(s.begin(), s.end());
        while (d.size() > 1 and d.front() == d.back()) {
            d.pop_front();
            d.pop_back();
        }

        string x(d.begin(), d.end());
        string y(d.begin(), d.end());
        reverse(y.begin(), y.end());
        int l = 0, r = x.size(), res = x.size();
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(m, x) or check(m, y)) {
                res = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        print(res);
    }
}
