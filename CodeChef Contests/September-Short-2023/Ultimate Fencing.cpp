#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n);
		arrPut(a);

		set<int> v;
		v.insert(0);
		v.insert(m);

		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
		for (int i : a) {
			set<int>::iterator r = v.lower_bound(i);
			set<int>::iterator l = r;
			l--;

			pq.push({i - (*l), *l});
			pq.push({(*r) - i, i});
			v.insert(i);

			while (!pq.empty()) {
				int d, x;
				tie(d, x) = pq.top();
				pq.pop();

				set<int>::iterator k = v.find(x);
				k++;
				// cout << endl;
				// print('d', x, d, *k);
				if ((*k) == x + d) {
					cout << d << ' ';
					pq.push({d, x});
					break;
				}
			}
		}

		cout << endl;
	}
}
