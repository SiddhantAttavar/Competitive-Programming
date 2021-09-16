#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<bool>> graph;

void findpath(int n)
{
    vector<int> numofadj;
 
    // Find out number of edges each vertex has
    for (int i = 0; i < n; i++)
        numofadj.push_back(accumulate(graph[i].begin(), graph[i].end(), 0));
 
    // Find out how many vertex has odd number edges
    int startpoint = 0, numofodd = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (numofadj[i] % 2 == 1)
        {
            numofodd++;
            startpoint = i;
        }
    }
 
    // If number of vertex with odd number of edges
    // is greater than two return "No Solution".
    if (numofodd > 2) 
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
    // If there is a path find the path
    // Initialize empty stack and path
    // take the starting current as discussed
    stack<int> stack;
    vector<int> path;
    int cur = startpoint;
 
    // Loop will run until there is element in the stack
    // or current edge has some neighbour.
    while (!stack.empty() or 
            accumulate(graph[cur].begin(), 
                       graph[cur].end(), 0) != 0)
    {
        // If current node has not any neighbour
        // add it to path and pop stack
        // set new current to the popped element
        if (accumulate(graph[cur].begin(),
                       graph[cur].end(), 0) == 0)
        {
            path.push_back(cur);
            cur = stack.top();
            stack.pop();
        }
 
        // If the current vertex has at least one
        // neighbour add the current vertex to stack,
        // remove the edge between them and set the
        // current to its neighbour.
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (graph[cur][i] == 1) 
                {
                    stack.push(cur);
                    graph[cur][i] = 0;
                    graph[i][cur] = 0;
                    cur = i;
                    break;
                }
            }
        }
    }
 
    // print the path
    for (auto ele : path) cout << ele + 1 << " ";
    cout << cur << endl;
}

int main() {
	setup();
	
	//Input basic variables
	input(n);
	input(m);

	//Input Graph
	graph = vector<vector<bool>>(n, vector<bool>(n, false));
	range(i, 0, m) {
		int u, v;
		input(u);
		input(v);

		u--;
		v--;

		graph[u][v] = true;
		graph[v][u] = true;
	}

	findpath(n);
}