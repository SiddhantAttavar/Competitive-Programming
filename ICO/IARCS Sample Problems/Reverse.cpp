#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();	
	input(int, n);
	vector<string> a[n];
	range(i, 0, n) {
		string line, word;
		input(char, c);
		getline(cin, line);
		line = c + line;
		stringstream ss(line);
		while (getline(ss, word, ' ')) {
			if (word.size() == 0) {
				continue;
			}
			string s;
			for (char c : word) {
				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
					s += c;
				}
			}
			a[i].push_back(s);
		}
	}

	reverse(a, a + n);
	for (vector<string> v : a) {
		reverse(v.begin(), v.end());
		for (string s : v) {
			cout << s << " ";
		}
		print("");
	}
}