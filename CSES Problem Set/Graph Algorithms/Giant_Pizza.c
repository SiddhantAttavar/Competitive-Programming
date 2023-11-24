#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Vec {
	int n,l;
	int *a;
};

void append(struct Vec *self, int x) {
	// printf("a%d %d %d\n", x, self->n, self->l);
	// fflush(stdout);
	if (self->l == self->n) {
		// printf("d%d\n", self->n);
		// fflush(stdout);
		int *b = malloc(self->n * sizeof(int));
		memcpy(b, self->a, self->n * sizeof(int));
		self->a = malloc(self->n * sizeof(int) << 1);
		memcpy(self->a, b, self->n * sizeof(int));
		self->n <<= 1;
	}
	// printf("%d %d %d\n", x, self->n, self->l);
	// fflush(stdout);

	self->a[self->l] = x;
	self->l++;
}

int flip(int x, int m) {
	return 2 * m - x - 1;
}

void topo_sort(int u, struct Vec graph[], bool vis[], int topo[], int *x) {
	vis[u] = true;
	for (int i = 0; i < graph[u].l; i++) {
		if (!vis[graph[u].a[i]]) {
			topo_sort(graph[u].a[i], graph, vis, topo, x);
		}
	}
	topo[*x] = u;
	(*x)++;
}

void dfs(int u, struct Vec graph[], int comp[], int x) {
	comp[u] = x;
	for (int i = 0; i < graph[u].l; i++) {
		if (comp[graph[u].a[i]] == -1) {
			dfs(graph[u].a[i], graph, comp, x);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);

	struct Vec graph[2 * m], rev_graph[2 * m];
	for (int i = 0; i < 2 * m; i++) {
		graph[i].n = 1;
		graph[i].l = 0;
		graph[i].a = malloc(sizeof(int));
		rev_graph[i].n = 1;
		rev_graph[i].l = 0;
		rev_graph[i].a = malloc(sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		char p, q;
		int x, y;
		// printf("debug\n");
		// fflush(stdout);
		scanf("%c %d %c %d\n", &p, &x, &q, &y);

		// printf("%c %d %c %d\n", p, x, q, y);
		// fflush(stdout);
		// printf("debug\n");
		// fflush(stdout);

		x--;
		y--;

		if (p == '-') {
			x = flip(x, m);
		}
		if (q == '-') {
			y = flip(y, m);
		}

		append(&graph[flip(x, m)], y);
		append(&graph[flip(y, m)], x);
		append(&rev_graph[y], flip(x, m));
		append(&rev_graph[x], flip(y, m));
	}

	// for (int i = 0; i < 2 * m; i++) {
	// 	for (int j = 0; j < graph[i].l; j++) {
	// 		printf("%d ", graph[i].a[j]);
	// 	}
	// 	printf("\n");
	// }
	// for (int i = 0; i < 2 * m; i++) {
	// 	for (int j = 0; j < rev_graph[i].l; j++) {
	// 		printf("%d ", rev_graph[i].a[j]);
	// 	}
	// 	printf("\n");
	// }

	// printf("debug\n");
	// fflush(stdout);

	bool vis[2 * m];
	for (int i = 0; i < 2 * m; i++) {
		vis[i] = false;
	}

	int topo[2 * m];
	int x = 0;
	for (int i = 0; i < 2 * m; i++) {
		if (!vis[i]) {
			topo_sort(i, graph, vis, topo, &x);
		}
	}

	for (int i = 0; i < m; i++) {
		int temp = topo[i];
		topo[i] = topo[flip(i, m)];
		topo[flip(i, m)] = temp;
	}
	
	// for (int i = 0; i < x; i++) {
	// 	printf("%d ", topo[i]);
	// }
	// printf("\n");

	int comp[2 * m];
	for (int i = 0; i < 2 * m; i++) {
		comp[i] = -1;
	}

	int y = 0;
	for (int i = 0; i < 2 * m; i++) {
		if (comp[topo[i]] == -1) {
			dfs(topo[i], rev_graph, comp, y);
			y++;
		}
	}

	// for (int i = 0; i < 2 * m; i++) {
	// 	printf("%d ", comp[i]);
	// }
	// printf("\n");

	char res[m];
	for (int i = 0; i < m; i++) {
		if (comp[i] == comp[flip(i, m)]) {
			printf("IMPOSSIBLE\n");
			return 0;
		}

		if (comp[i] > comp[flip(i, m)]) {
			res[i] = '+';
		}
		else {
			res[i] = '-';
		}
	}

	for (int i = 0; i < m; i++) {
		printf("%c ", res[i]);
	}
}
