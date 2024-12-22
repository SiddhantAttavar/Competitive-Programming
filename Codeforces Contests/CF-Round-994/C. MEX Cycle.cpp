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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

bool check(vector<int> &a, int x, int y) {
    cout.flush();
    int n = a.size();
    vector<vector<int>> graph(n);
    range(i, 0, n) {
        graph[i].push_back((i + n - 1) % n);
        graph[i].push_back((i + 1) % n);
    }
    graph[x].push_back(y);
    graph[y].push_back(x);
    range(i, 0, n) {
        set<int> s;
        for (int j : graph[i]) {
            s.insert(a[j]);
        }
        int c = 0;
        while (s.count(c)) {
            c++;
        }
        if (a[i] != c) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, x, y;
        input(n, x, y);
        x--;
        y--;

        if (x > y) {
            swap(x, y);
        }

        vector<int> a(n);
        if (n % 2 == 0) {
            range(i, 0, n) {
                a[i] = i % 2;
            }
            if (a[x] == a[y]) {
                a[x] = 2;
            }
            arrPrint(a);
            assert(check(a, x, y));
            continue;
        }

        a[x] = 2;
        range(i, x + 1, n) {
            a[i] = (i - x) % 2;
        }
        range(i, 0, x) {
            a[i] = (x - i + 1) % 2;
        }
        arrPrint(a);
        assert(check(a, x, y));
    }
}
