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
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int n;
	input(n);

	string s, t;
	input(s, t);

	s += "..";
	t += "..";

	map<string, int> m;
	queue<string> q;
	m[s] = 0;
	q.push({s, 0});
	while (!q.empty()) {
		string u = q.front();
		q.pop();

		if (u == t) {
			break;
		}

		int j = u.find('.');
		range(i, 0, n + 1) {
			if (u[i] == '.' or u[i + 1] == '.') {
				continue;
			}

			string v = u;
			swap(v[i], v[j]);
			swap(v[i + 1], v[j + 1]);
			if (!m.count(v)) {
				m[v] = m[u] + 1;
				q.push(v);
			}
		}
	}

	if (m.count(t)) {
		print(m[t]);
	}
	else {
		print(-1);
	}
}
