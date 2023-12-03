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
//#define int long long

vector<pair<map<int, int>, int>> make_trie(vector<string> &s) {
	vector<pair<map<int, int>, int>> trie;
	trie.push_back({map<int, int>(), 0});
	for (string i : s) {
		int u = 0;
		trie[0].second++;
		range(j, 0, (int) i.size()) {
			// print(u, j, i[j]);
			if (!trie[u].first.count(i[j] - 'a')) {
				trie[u].first[i[j] - 'a'] = trie.size();
				u = trie.size();
				trie.push_back({map<int,int>(), 0});
			}
			else {
				u = trie[u].first[i[j] - 'a'];
			}
			trie[u].second++;
		}
	}
	return trie;
}

void dfs(int u, int p, vector<pair<map<int, int>, int>> &trie, vector<long long> &size) {
	size[u] = trie[u].second;
	// print(u, size[u]);
	for (pair<int, int> v : trie[u].first) {
		if (v.second != p) {
			dfs(v.second, u, trie, size);
			size[u] += size[v.second];
		}
	}
	// print(u, size[u]);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<string> s(n);
	arrPut(s);

	vector<pair<map<int, int>, int>> trie = make_trie(s);

	// range(i, 0, n) {
	// 	reverse(s[i].begin(), s[i].end());
	// }
	// vector<pair<map<int, int>, int>> rev_trie = make_trie(s);
	// range(i, 0, n) {
	// 	reverse(s[i].begin(), s[i].end());
	// }

	// for (pair<vector<int>, int> p : trie) {
	// 	arrPrint(p.first);
	// 	print(p.second);
	// }
	// for (pair<vector<int>, int> p : rev_trie) {
	// 	arrPrint(p.first);
	// 	print(p.second);
	// }

	vector<long long> size(trie.size());
	// arrPrint(size);
	dfs(0, -1, trie, size);
	// arrPrint(size);

	long long res = 0;
	for (string i : s) {
		// print(res);
		int a = 0;
		for (int j = i.size() - 1; j >= 0; j--) {
			if (!trie[a].first.count(i[j] - 'a')) {
				res += (j + 1) * trie[a].second;
				res += size[a] - trie[a].second;
				a = -1;
				break;
			}

			int b = trie[a].first[i[j] - 'a'];
			res += (j + 1) * (trie[a].second - trie[b].second);
			res += size[a] - size[b] - trie[a].second;
			// print(res);
			a = b;
		}

		if (a != -1) {
			// print(a);
			for (pair<int, int> j : trie[a].first) {
				res += size[j.second];
			}
		}
	}
	print(res);
}
