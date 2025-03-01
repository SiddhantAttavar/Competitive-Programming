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
const int MOD = (int) 1e9 + 7; //998244353

struct RollbackUF {
	vector<int> e; vector<pair<int, int>> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return st.size(); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, m, k;
        input(n, m, k);

        vector<int> c(n);
        arrput(c);

        rep(i, 0, n) {
            c[i]--;
        }

        RollbackUF d(n);
        vector<bool> a(k, false);
        map<pair<int, int>, vector<pair<int, int>>> l;
        while (m--) {
            int u, v;
            input(u, v);

            u--;
            v--;

            if (c[u] == c[v]) {
                if (!d.join(u, v)) {
                    a[c[u]] = true;
                }
            }
            else {
                if (c[u] > c[v]) {
                    swap(u, v);
                }
                l[{c[u], c[v]}].push_back({u, v});
            }
        }

        int x = accumulate(a.begin(), a.end(), 0);
        int t = d.time();
        int res = x * (k - 1) - x * (x - 1) / 2;
        for (pair<pair<int, int>, vector<pair<int, int>>> p : l) {
            if (a[p.first.first] or a[p.first.second]) {
                continue;
            }

            bool flag = false;
            for (pair<int, int> q : p.second) {
                if (!d.join(q.first, q.second)) {
                    flag = true;
                    break;
                }
            }

            res += flag;
            d.rollback(t);
        }
        print(res);
    }
}
