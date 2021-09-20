<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int countRecursive = 0;
int solveRecurvsively(int a[], int i, int j) {
    if ((j - i) == 1) {
        return 0;
    }

    int res = INT_MAX;
    range(k, i + 1, j) {
        int x = solveRecurvsively(a, i, k) + solveRecurvsively(a, k, j) + a[i] * a[k] * a[j];
        res = min(res, x);
        countRecursive++;
    }

    return res;
}

int countMemoized = 0;
map<pair<int, int>, int> memoTable;
int solveMemoized(int a[], int i, int j) {
    if ((j - i) == 1) {
        return 0;
    }

    if (memoTable.find(make_pair(i, j)) != memoTable.end()) {
        return memoTable.at(make_pair(i, j));
    }

    int res = INT_MAX;
    range(k, i + 1, j) {
        int x = solveMemoized(a, i, k) + solveMemoized(a, k, j) + a[i] * a[k] * a[j];
        res = min(res, x);
        countMemoized++;
    }

    memoTable.insert(make_pair(make_pair(i, j), res));
    return res;

}

int countDynamicProgramming = 0;
int solveDynamicProgramming(int a[], int n) {
    int dp[n][n];
    range(i, 0, n - 1) {
        dp[i][i + 1] = 0;
    }
    range(size, 2, n) {
        range(i, 0, n - size) {
            int j = i + size;
            dp[i][j] = INT_MAX;
            range(k, i + 1, j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
                countDynamicProgramming++;
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    input(int, n);
    arrput(int, a, n);
    
    println("\nRecursive Solution: ");
    println("Ans: %d", solveRecurvsively(a, 0, n - 1));
    println("Steps: %d", countRecursive);
    
    println("\nRecursive Memoized Solution: ");
    println("Ans: %d", solveMemoized(a, 0, n - 1));
    println("Steps: %d", countMemoized);

    println("\nDynamic Programming Solution: ");
    println("Ans: %d", solveDynamicProgramming(a, n));
    println("Steps: %d", countDynamicProgramming);
=======
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int countRecursive = 0;
int solveRecurvsively(int a[], int i, int j) {
    if ((j - i) == 1) {
        return 0;
    }

    int res = INT_MAX;
    range(k, i + 1, j) {
        int x = solveRecurvsively(a, i, k) + solveRecurvsively(a, k, j) + a[i] * a[k] * a[j];
        res = min(res, x);
        countRecursive++;
    }

    return res;
}

int countMemoized = 0;
map<pair<int, int>, int> memoTable;
int solveMemoized(int a[], int i, int j) {
    if ((j - i) == 1) {
        return 0;
    }

    if (memoTable.find(make_pair(i, j)) != memoTable.end()) {
        return memoTable.at(make_pair(i, j));
    }

    int res = INT_MAX;
    range(k, i + 1, j) {
        int x = solveMemoized(a, i, k) + solveMemoized(a, k, j) + a[i] * a[k] * a[j];
        res = min(res, x);
        countMemoized++;
    }

    memoTable.insert(make_pair(make_pair(i, j), res));
    return res;

}

int countDynamicProgramming = 0;
int solveDynamicProgramming(int a[], int n) {
    int dp[n][n];
    range(i, 0, n - 1) {
        dp[i][i + 1] = 0;
    }
    range(size, 2, n) {
        range(i, 0, n - size) {
            int j = i + size;
            dp[i][j] = INT_MAX;
            range(k, i + 1, j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
                countDynamicProgramming++;
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    input(int, n);
    arrput(int, a, n);
    
    println("\nRecursive Solution: ");
    println("Ans: %d", solveRecurvsively(a, 0, n - 1));
    println("Steps: %d", countRecursive);
    
    println("\nRecursive Memoized Solution: ");
    println("Ans: %d", solveMemoized(a, 0, n - 1));
    println("Steps: %d", countMemoized);

    println("\nDynamic Programming Solution: ");
    println("Ans: %d", solveDynamicProgramming(a, n));
    println("Steps: %d", countDynamicProgramming);
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}