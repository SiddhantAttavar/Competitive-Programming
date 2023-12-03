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

#define MAXN 1000000

struct Node
{
	// store start and end indexes of current
	// Node inclusively
	int start, end;

	// stores length of substring
	int length;

	// stores insertion Node for all characters a-z
	int insertEdg[26];

	// stores the Maximum Palindromic Suffix Node for
	// the current Node
	int suffixEdg;
};

// two special dummy Nodes as explained above
Node root1, root2;

// stores Node information for constant time access
Node tree[MAXN];

// Keeps track the current Node while insertion
int currNode;
string s;
int ptr;

void insert(int idx)
{
//STEP 1//

	/* search for Node X such that s[idx] X S[idx]
	is maximum palindrome ending at position idx
	iterate down the suffix link of currNode to
	find X */
	int tmp = currNode;
	while (true)
	{
		int curLength = tree[tmp].length;
		if (idx - curLength >= 1 and s[idx] == s[idx-curLength-1])
			break;
		tmp = tree[tmp].suffixEdg;
	}

	/* Now we have found X ....
	* X = string at Node tmp
	* Check : if s[idx] X s[idx] already exists or not*/
	if(tree[tmp].insertEdg[s[idx]-'a'] != 0)
	{
		// s[idx] X s[idx] already exists in the tree
		currNode = tree[tmp].insertEdg[s[idx]-'a'];
		return;
	}

	// creating new Node
	ptr++;

	// making new Node as child of X with
	// weight as s[idx]
	tree[tmp].insertEdg[s[idx]-'a'] = ptr;

	// calculating length of new Node
	tree[ptr].length = tree[tmp].length + 2;

	// updating end point for new Node
	tree[ptr].end = idx;

	// updating the start for new Node
	tree[ptr].start = idx - tree[ptr].length + 1;


//STEP 2//

	/* Setting the suffix edge for the newly created
	Node tree[ptr]. Finding some String Y such that
	s[idx] + Y + s[idx] is longest possible
	palindromic suffix for newly created Node.*/

	tmp = tree[tmp].suffixEdg;

	// making new Node as current Node
	currNode = ptr;
	if (tree[currNode].length == 1)
	{
		// if new palindrome's length is 1
		// making its suffix link to be null string
		tree[currNode].suffixEdg = 2;
		return;
	}
	while (true)
	{
		int curLength = tree[tmp].length;
		if (idx-curLength >= 1 and s[idx] == s[idx-curLength-1])
			break;
		tmp = tree[tmp].suffixEdg;
	}

	// Now we have found string Y
	// linking current Nodes suffix link with s[idx]+Y+s[idx]
	tree[currNode].suffixEdg = tree[tmp].insertEdg[s[idx]-'a'];
}

// driver program
/* int main()
 {
	// initializing the tree
	root1.length = -1;
	root1.suffixEdg = 1;
	root2.length = 0;
	root2.suffixEdg = 1;

	tree[1] = root1;
	tree[2] = root2;
	ptr = 2;
	currNode = 1;

	// given string
	s = "abcbab";
	int l = s.length();

	for (int i=0; i<l; i++)
		insert(i);

	// printing all of its distinct palindromic
	// substring
	cout << "All distinct palindromic substring for "
		<< s << " : \n";
	for (int i=3; i<=ptr; i++)
	{
		cout << i-2 << ") ";
		for (int j=tree[i].start; j<=tree[i].end; j++)
			cout << s[j];
		cout << endl;
	}

	return 0;
} */

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	input(s);

	// initializing the tree
	root1.length = -1;
	root1.suffixEdg = 1;
	root2.length = 0;
	root2.suffixEdg = 1;

	tree[1] = root1;
	tree[2] = root2;
	ptr = 2;
	currNode = 1;
	range(i, 0, n) {
		insert(i);
	}

	vector<int> a(n);
	range(i, 0, n) {
		a[i] = i;
	}

	while (q--) {
		int o;
		input(o);

		if (o == 2) {
			int x, y;
			input(x, y);
			x--;
			y--;

			if (y >= tree[x].start and y <= tree[x].end) {
				print("Yes");
			}
			else {
				print("No");
			}
		}
		else {
			int i;
			char c;
			input(i, c);
			i--;
			s[i] = c;
			insert(i);
		}
	}
}
