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


const int N = 1e6;
int nex[N][10], sz[N], num = 0; // num is last node in trie
struct TrieAlpha {
	// change 2 to 26 for lowercase letters
	TrieAlpha() { memset(nex,0,sizeof nex); memset(sz,0,sizeof sz); }
	void ins(string x) { // insert or delete
		int cur = 0; sz[cur]++;
		range(i,0,size(x)) {
			int t = x[i]-'0';
			if (!nex[cur][t]) nex[cur][t] = ++num;
			sz[cur = nex[cur][t]]++;
		}
	}
	int query(string x) {
		int cur = 0;
		range(i, 0, size(x)) {
			int t = x[i] - '0';
			if (!nex[cur][t]) return 0;
			cur = nex[cur][t];
		}
		return sz[cur];
	}
};

int32_t main() {
	setup();

	vector<string> a = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	map<char, char> b;
	range(i, 0, a.size()) {
		for (char c : a[i]) {
			b[c] = i + '0';
		}
	}

	int n, m;
	input(n, m);

	vector<string> s(n);
	arrPut(s);

	TrieAlpha trie;
	for (string i : s) {
		string c;
		for (char j : i) {
			c += b[j];
		}
		trie.ins(c);
	}

	while (m--) {
		string t;
		input(t);
		print(trie.query(t));
	}
}
