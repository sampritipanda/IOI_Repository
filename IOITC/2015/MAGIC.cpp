#include <cstdio>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

struct node {
	node *left, *right;
	int p, cnt;
	int id, val;
	
	node(int _id, int _val, int _p, node *_left = NULL, node *_right = NULL) {
		id = _id;
		val = _val;
		p = _p;
		left = _left;
		right = _right;
		
		upd();
	}
	
	void upd() {
		cnt = 1;
		if(left != NULL) cnt += left->cnt;
		if(right != NULL) cnt += right->cnt;
	}
};

int cnt(node* root) {
	if(root == NULL) return 0;
	return root->cnt;
}

void rotate_right(node*& root) {
	node* temp = root;
	root = root->left;
	temp->left = root->right;
	root->right = temp;
	
	temp->upd();
}

void rotate_left(node*& root) {
	node* temp = root;
	root = root->right;
	temp->right = root->left;
	root->left = temp;
	
	temp->upd();
}

void insert(node*& root, int X, int p, int id, int val, int pre) {
	if(root == NULL) {
		root = new node(id, val, p);
		return;
	}
	
	int key = pre + cnt(root->left) + 1;
	
	if(X < key) {
		insert(root->left, X, p, id, val, pre);
		if(root->left->p < root->p) rotate_right(root);
	}	
	else {
		insert(root->right, X, p, id, val, pre + cnt(root->left) + 1);
		if(root->right->p < root->p) rotate_left(root);
	}
	
	root->upd();
}

void split(node* root, int X, int p = -1) {
	insert(root, X, p, 0, 0, 0);
}

void merge(node*& root, node*& L, node*& R) {
	if(L == NULL) {
		root = R;
		return;
	}
	if(R == NULL) {
		root = L;
		return;
	}
	
	if(L->p <= R->p) {
		merge(L->right, L->right, R);
		root = L;
	}
	else {
		merge(R->left, L, R->left);
		root = R;
	}
	
	root->upd();
}

void delete_node(node*& root, int X, int pre) {
	if(root == NULL) return;
	
	int key = pre + cnt(root->left) + 1;
	
	if(X < key) {
		delete_node(root->left, X, pre);
	}
	else if(X > key) {
		delete_node(root->right, X, pre + cnt(root->left) + 1);
	}
	else {
		merge(root, root->left, root->right);
	}
	
	if(root != NULL) root->upd();
}

node* find_node(node*& root, int X, int pre) {
	int key = pre + cnt(root->left) + 1;
	
	if(X < key) {
		return find_node(root->left, X, pre);
	}
	else if(X > key) {
		return find_node(root->right, X, pre + cnt(root->left) + 1);
	}		
	else {
		return root;
	}
}

int pos[1000001];
node* root = NULL;

void move_front(int x, int y) {
	delete_node(root, y, 0);
	node* new_node = new node(pos[x], x, rand());
	merge(root, new_node, root);
}

queue<int> unused;
int ans[1000001];

int main() {
	srand(0);
	int N, M; scanf("%d %d", &N, &M);
	
	for(int i = 1; i <= N; i++) {
		insert(root, i, rand(), i, 0, 0);
	}
	
	while(M--) {
		int x, y; scanf("%d %d", &x, &y);
		node* req = find_node(root, y, 0);
		
		if(pos[x] != 0) {
			if(req->val != x) {
				printf("-1\n");
				return 0;
			}
			else {
				move_front(x, y);
			}
		}
		else {
			pos[x] = req->id;
			move_front(x, y);
		}
	}
	
	for(int i = 1; i <= N; i++) {
		if(pos[i] == 0) unused.push(i);
		else {
			ans[pos[i]] = i;
		}
	}
	
	for(int i = 1; i <= N; i++) {
		if(!ans[i]) {
			ans[i] = unused.front(); unused.pop();
		}
		printf("%d ", ans[i]);
	}
	printf("\n");
}
