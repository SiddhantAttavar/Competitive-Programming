#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, c, s, m;
		input(n, c, s, m);

		vector<int> w(n);
		arrPut(w);

		int x = 0;
		for (int i : w) {
			x += i;
		}

		if (x <= m) {
			print(n * c);
			continue;
		}

		multiset<int> a, b, p, q;
		for (int i : w) {
			p.insert(i);
		}

		x = 0;
		int res = n * c;
		range(i, 0, n) {
			if (p.count(w[i])) {
				p.erase(p.find(w[i]));
			}
			else {
				x -= w[i];
				q.erase(q.find(w[i]));

				x += *b.rbegin();
				a.insert(*b.rbegin());
				b.erase(b.find(*b.rbegin()));
			}

			if (b.size() and w[i] < *b.rbegin()) {
				x += *b.rbegin();
				a.insert(*b.rbegin());
				b.erase(b.find(*b.rbegin()));
				b.insert(w[i]);
			}
			else {
				x += w[i];
				a.insert(w[i]);
			}

			while (a.size() and p.size() and x <= m) {
				x -= *a.begin();
				b.insert(*a.begin());
				a.erase(a.begin());

				x += *p.rbegin();
				q.insert(*p.rbegin());
				p.erase(p.find(*p.rbegin()));
			}

			while (q.size() and (x + *b.rbegin() - *q.begin() > m or *b.rbegin() >= *q.begin())) {
				x += *b.rbegin();
				a.insert(*b.rbegin());
				b.erase(b.find(*b.rbegin()));

				x -= *q.begin();
				p.insert(*q.begin());
				q.erase(q.begin());
			}

			if (x > m) {
				res = min(res, ((int) i) * c + ((int) b.size()) * s);
			}
		}

		print(res);
	}
}
