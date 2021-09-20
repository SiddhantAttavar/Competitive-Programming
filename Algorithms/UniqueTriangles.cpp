<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
	int n;
	cin >> n;
	unordered_set<string> s;
	range(i, n) {
		int t[3];
		cin >> t[0] >> t[1] >> t[2];
		sort(t, t + 3);
		stringstream ss;
		ss << setw(9) << setfill('0') << t[0];
		ss << setw(9) << setfill('0') << t[1];
		ss << setw(9) << setfill('0') << t[2];
		s.insert(ss.str());
	}

	println("The triangles are: ");
	for (string i: s) {
		int a = stoi(i.substr(0, 9));
		int b = stoi(i.substr(9, 9));
		int c = stoi(i.substr(18, 9));
		println("%d, %d, %d", a, b, c);
	}
=======
#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
	int n;
	cin >> n;
	unordered_set<string> s;
	range(i, n) {
		int t[3];
		cin >> t[0] >> t[1] >> t[2];
		sort(t, t + 3);
		stringstream ss;
		ss << setw(9) << setfill('0') << t[0];
		ss << setw(9) << setfill('0') << t[1];
		ss << setw(9) << setfill('0') << t[2];
		s.insert(ss.str());
	}

	println("The triangles are: ");
	for (string i: s) {
		int a = stoi(i.substr(0, 9));
		int b = stoi(i.substr(9, 9));
		int c = stoi(i.substr(18, 9));
		println("%d, %d, %d", a, b, c);
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}