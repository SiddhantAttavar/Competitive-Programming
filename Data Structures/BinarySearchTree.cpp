#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

class Node {
	int val;
	Node left, right;
};

void inorderTreeWalk(Node currNode) {
	if (currNode) {
		inorderTreeWalk(currNode.left);
		print(currNode.val);
		inorderTreeWalk(currNode.right);
	}
}