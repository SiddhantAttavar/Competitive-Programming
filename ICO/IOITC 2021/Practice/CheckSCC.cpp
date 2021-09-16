#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

/* Note: this function is already implemented for you */
bool query (const vector<int> &A, const vector<int> &B);

/* You can add global variables and functions here */

vector<vector<int>> connected;
vector<int> notVisited;
vector<int> adj;
bool rev = false;

void findAdj(int u, int l, int h) {
	vector<int> temp(notVisited.begin() + l, notVisited.begin() + h + 1);
	if ((!rev && !query({u}, temp)) || (rev && !query(temp, {u}))) {
		return;
	}

	if (l == h) {
		adj.push_back(l);
		return;
	}

	int m = (l + h) / 2;
	findAdj(u, l, m);
	findAdj(u, m + 1, h);
}

void dfs(int u) {
	adj.clear();
    findAdj(u, 0, notVisited.size() - 1);
	vector<int> next;
	for (int i : adj) {
		next.push_back(notVisited[i]);
	}
	int curr = 0;
	for (int i : adj) {
		notVisited.erase(notVisited.begin() + i - curr);
		curr++;
	}
	for (int v : next) {
		dfs(v);
	}
}

bool solve(int n) {
	connected.resize(n, vector<int>(n, -1));

	vector<int> temp(n);
	range(i, 0, n) {
		temp[i] = i;
	}
	ll seed = time(NULL); srand(seed);
    random_shuffle(temp.begin(), temp.end());

	notVisited.insert(notVisited.end(), temp.begin() + 1, temp.end());
	dfs(temp[0]);

	if (notVisited.size() > 0) {
		return false;
	}

	notVisited.insert(notVisited.end(), temp.begin() + 1, temp.end());
	rev = true;
	dfs(temp[0]);

	return notVisited.size() == 0;
}

int main() {
    int n;
    cin >> n;

    bool t = solve(n);
    cout << "A" << endl;
    cout << (t ? "YES" : "NO") << endl;
}

bool query (const vector<int> &A, const vector<int> &B) {
	if (A.size() == 0 || B.size() == 0) {
		return false;
	}
	bool flag = true;
	for (int u : A) {
		for (int v : B) {
			if (connected[u][v] == 1) {
				return true;
			}
			if (connected[u][v] == -1) {
				flag = false;
			}
		}
	}
	if (flag) {
		return false;
	}
    cout << "Q\n";
    cout << A.size() << endl;
    for (auto &x : A) {
        cout << x + 1 << ' ';
    }
    cout << endl;

    cout << B.size() << endl;
    for (auto &x : B) {
        cout << x + 1 << ' ';
    }
    cout << endl;

    int edge;
    cin >> edge;

    if (edge == -1) {
        exit(0);
    }

	if (A.size() == 1 && B.size() == 1) {
		connected[A[0]][B[0]] = edge;
	}

    return edge;
}

/*
vector<vector<int>> ADJ; int USED = 0;

bool query(const vector<int> &a, const vector<int> &b){
    for(auto u : a){
        for(auto v : b){
            if(v == u){
                cerr << "INVALID QUERY (1)" << endl;
                exit(1);
            }
            if(ADJ[u][v]) return 1;
        }
    }
    USED++;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream CURR_TEST;

    int N, M; cin >> N >> M;
    CURR_TEST << N << " " << M << endl;

    ADJ.resize(N, vector<int>(N));
    while(M--){
        int u, v; cin >> u >> v;
        CURR_TEST << u << " " << v << endl;

        u--, v--;
        ADJ[u][v] = 1;
    }

    for(int x = 0; x < N; x++)
        ADJ[x][x] = 1;

    auto ret_ans = solve(N);

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                ADJ[i][j] |= ADJ[i][k]&ADJ[k][j];

    bool ANS = true;
    for(int u = 0; u < N; u++)
        for(int v = 0; v < N; v++)
            if(!ADJ[u][v]) ANS = false;

    if(ret_ans != ANS){
        cout << "WRONG ANSWER" << endl;
        exit(1);
    }
    cout << "OK, USED QUERIES: " << USED << endl;

    return 0;
}*/