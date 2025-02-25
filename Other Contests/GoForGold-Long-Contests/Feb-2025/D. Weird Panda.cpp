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
    setup();
    int n;
    input(n);

    vector<int> a(n);
    arrput(a);

    int q;
    input(q);
    vector<pair<pair<int, int>, int>> v(q);
    range(i, 0, q) {
        input(v[i].first.second, v[i].first.first);
        v[i].first.second--;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    vector<int> res(q, 0);
    int k = sqrt(n) + 1, l = 0;
    range(i, 1, k) {
        vector<int> x(n);
        range(j, 0, i) {
            x[j] = a[j];
        }
        range(j, i, n) {
            x[j] = a[j] + x[j - i];
        }
        while (l < v.size() and v[l].first.first == i) {
            int a = v[l].first.second, b = v[l].first.first;
            int r = n - n % b + a % b;
            if (r >= n) {
                r -= b;
            }
            if (a < b) {
                res[v[l].second] = x[r];
            }
            else {
                res[v[l].second] = x[r] - x[a - b];
            }
            l++;
        }
    }
    range(i, l, q) {
        for (int j = v[i].first.second; j < n; j += v[i].first.first) {
            res[v[i].second] += a[j];
        }
    }
    arrprint(res);
}
