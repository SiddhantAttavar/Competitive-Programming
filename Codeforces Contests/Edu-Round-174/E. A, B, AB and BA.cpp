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

bool solve(int x, int y, int z, int a, int c, int d) {
    if (y <= c) {
        c -= y;
    }
    else {
        y -= c;
        a -= y;
        c = 0;
        if (a < 0) {
            return false;
        }
    }

    if (z <= d) {
        d -= z;
    }
    else {
        z -= d;
        a -= z;
        d = 0;
        if (a < 0) {
            return false;
        }
    }

    return a + c + d >= x;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        string s;
        input(s);

        int a, b, c, d;
        input(a, b, c, d);

        vector<pair<char, int>> v = {{s[0], 1}};
        range(i, 1, s.size()) {
            if (s[i] == s[i - 1]) {
                v.push_back({s[i], 1});
            }
            else {
                v.back().second++;
            }
        }

        vector<int> p, q;
        int x = 0, y = 0, z = 0;
        for (pair<char, int> i : v) {
            if (i.second % 2 == 1) {
                if (i.first == 'A') {
                    a--;
                }
                else {
                    b--;
                }
                x += (i.second - 1) / 2;
            }
            else {
                if (i.first == 'A') {
                    p.push_back(i.second / 2);
                    y += i.second / 2;
                }
                else {
                    q.push_back(i.second / 2);
                    z += i.second / 2;
                }
            }
        }
        a = min(a, b);

        if (a < 0) {
            print("NO");
            continue;
        }

        bool res = solve(x, y, z, a, c, d);
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        sort(q.begin(), q.end());
        reverse(q.begin(), q.end());

        int t = 0;
        range(i, 0, min({a, b, (int) p.size()})) {
            t += p[i];
            res |= solve(x + t - i - 1, y - t, z, a - i - 1, c, d);
        }

        t = 0;
        range(i, 0, min({a, b, (int) q.size()})) {
            t += q[i];
            res |= solve(x + t - i - 1, y, z - t, a - i - 1, c, d);
        }

        if (res) {
            print("YES");
        }
        else {
            print("NO");
        }
    }
}
