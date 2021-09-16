#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, height;
vector<vi> graph;
vi h;
vector<vi> nextStep;
vi nextLeft, nextRight;

void init(int N, vi H) {
    n = N;
    h = H;
    
    height = ceil(log2(n));

    nextLeft.clear();
    nextLeft.resize(n, -1);
    stack<int> s;
    range(i, 0, n) {
        while (!s.empty()) {
            if (h[s.top()] > h[i]) {
                nextLeft[i] = s.top();
                break;
            }
            s.pop();
        }
        s.push(i);
    }

    nextRight.clear();
    nextRight.resize(n, -1);
    s = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty()) {
            if (h[s.top()] > h[i]) {
                nextRight[i] = s.top();
                break;
            }
            s.pop();
        }
        s.push(i);
    }

    nextStep.clear();
    nextStep.resize(n, vi(height + 1, -1));
    range(i, 0, n) {
        if (nextLeft[i] == -1) {
            nextStep[i][0] = nextRight[i];
        }
        else if (nextRight[i] == -1) {
            nextStep[i][0] = nextLeft[i];
        }
        else {
            nextStep[i][0] = h[nextLeft[i]] > h[nextRight[i]] ? nextLeft[i] : nextRight[i];
        }
    }
    range(j, 1, height + 1) {
        range(i, 0, n) {
            if (nextStep[i][j - 1] != -1) {
                nextStep[i][j] = nextStep[nextStep[i][j - 1]][j - 1];
            }
        }
    }
}

int minimum_jumps(int a, int b, int c, int d) {
    if (a == c) {
        return 0;
    }
    if (h[a] >= h[c]) {
        return -1;
    }

    int res = 0;
    for (int curr = height; curr >= 0; curr--) {
        if (nextStep[a][curr] != -1 and (h[nextStep[a][curr]] < h[c] or nextStep[a][curr] == c) and ((a < c and nextStep[a][curr] <= c) or (a > c and nextStep[a][curr] >= c))) {
            a = nextStep[a][curr];
            res += (1 << curr);
        }
    }
    if (a == c) {
        return res;
    }
    if (nextLeft[a] == c or nextRight[a] == c) {
        return res + 1;
    }
    return -1;
}


int main() {
  int N, Q;
  assert(2 == scanf("%d %d", &N, &Q));
  std::vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    assert(1 == scanf("%d", &H[i]));
  }
  init(N, H);

  for (int i = 0; i < Q; ++i) {
    int A, B, C, D;
    assert(4 == scanf("%d %d %d %d", &A, &B, &C, &D));
    printf("%d\n", minimum_jumps(A, B, C, D));
  }
  return 0;
}
