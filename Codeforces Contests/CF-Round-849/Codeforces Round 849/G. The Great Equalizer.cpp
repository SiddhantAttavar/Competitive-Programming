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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		multiset<int> s, m(a.begin(), a.end());
		int p = *m.begin();
		for (int i : m) {
			s.insert(i - p);
			p = i;
		}

		int q;
		input(q);
		while (q--) {
			int i, x;
			input(i, x);
			i--;
			
			multiset<int>::iterator j = m.find(a[i]);
			multiset<int>::iterator l = j, r = j;
			l--;
			r++;
			if (j != --m.end()) {
				s.erase(s.find(*r - a[i]));
			}
			if (j != m.begin()) {
				s.erase(s.find(a[i] - *l));
				if (j != --m.end()) {
					s.insert(*r - *l);
				}
			}

			m.erase(m.find(a[i]));
			a[i] = x;
			m.insert(a[i]);

			j = m.find(a[i]);
			l = j;
			r = j;
			l--;
			r++;
			if (j != m.begin()) {
				s.insert(a[i] - *l);
				if (j != --m.end()) {
					s.erase(s.find((*r - *l)));
				}
			}
			if (j != --m.end()) {
				s.insert(*r - a[i]);
			}

			cout << (*s.rbegin() + *m.rbegin()) << ' ';
		}
		cout << endl;
	}
}
