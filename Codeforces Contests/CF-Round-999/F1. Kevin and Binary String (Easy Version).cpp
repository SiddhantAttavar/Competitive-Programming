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
        string s, t;
        input(s, t);

        int n = s.size();

        vector<int> p(n + 1, 0), q(n + 1, 0);
        range(i, 0, n) {
            p[i + 1] = p[i] + s[i] == '0';
            q[i + 1] = q[i] + s[i] == '1';
        }

        vector<int> a(n + 1, 0);
        range(i, 1, n) {
            a[i + 1] = a[i] + (s[i] != s[i - 1]);
        }

        int res = 0;
        range(i, 0, n) {
            if (s[i] == t[i]) {
                continue;
            }

            if (i and s[i] == s[i - 1]) {
                res = -1;
                break;
            }

            int j = i;
            while (j < n and t[j] == t[i]) {
                j++;
            }
            j--;

            int k = i, x = 0;
            while (k < n and x < j - i + 1) {
                x += s[k] == t[i];
                k++;
            }
            k--;
            if (x != j - i + 1) {
                res = -1;
                break;
            }
            if (k < n - 1 and s[k] == s[k + 1]) {
                res = -1;
                break;
            }

            res += (a[k + 1] - a[i] + 1) / 2;
            range(l, i, j + 1) {
                s[l] = t[i];
            }
            range(l, j + 1, k + 1) {
                s[l] = t[j + 1];
            }

            i = j;
        }
        print(res);
    }
}
