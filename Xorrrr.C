#include <stdio.h>
#include <stdlib.h>
#define MAX 200000
typedef struct node {
	int id;
	int n;
	struct node *next;
} nd;
static nd* tree[MAX];
static short visited[MAX];
int result = 0;
int dfs(nd *head)
{
	nd *temp = head;
	int total = 1;
 
	while (temp != NULL) {
		if (visited[temp -> id] == 0) {
			visited[temp -> id] = 1;
			if (temp -> n == -1) {
				temp -> n = dfs(tree[temp -> id]);
			}
			total += temp -> n;
			visited[temp -> id] = 0;
		}
		temp = temp -> next;
	}
	return total;
}
 
void main()
{
	int n, edges[MAX][2], l, result, x, y;
	unsigned long times;
	nd* tail[MAX];
 
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf("%d%d", &x, &y);
		if (tree[x] == NULL) {
			tree[x] = malloc(sizeof(nd));
			tree[x] -> id = y;
			tree[x] -> n = -1;
			tree[x] -> next = NULL;
			tail[x] = tree[x]; 
		}
		else {
			tail[x] -> next = malloc(sizeof(nd));
			tail[x] = tail[x] -> next;
			tail[x] -> n = -1;
			tail[x] -> id = y;
			tail[x] -> next = NULL;
		}
		if (tree[y] == NULL) {
			tree[y] = malloc(sizeof(nd));
			tree[y] -> id = x;
			tree[y] -> n = -1;
			tree[y] -> next = NULL;
			tail[y] = tree[y]; 
		}
		else {
			tail[y] -> next = malloc(sizeof(nd));
			tail[y] = tail[y] -> next;
			tail[y] -> id = x;
			tail[y] -> n = -1;
			tail[y] -> next = NULL;
		}
		edges[i][0] = x;
		edges[i][1] = y;
	}
	result = 0;
	for (int i = 0; i < n-1; i++) {
		visited[edges[i][0]] = 1;
		visited[edges[i][1]] = 1;
		l = dfs(tree[edges[i][0]]);
		times = l*(n - l);
		if (times % 2 == 1)
			result ^= (edges[i][0]+edges[i][1]);
		visited[edges[i][0]] = 0;
        visited[edges[i][1]] = 0;
	}
	printf("%d", result);
}
Language: C
