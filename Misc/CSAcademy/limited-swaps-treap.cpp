#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <ctime>

using namespace std;

int N;
int A[100001];

struct node {
    int p, cnt;
    int val, ans, ind; // val = max-val in sub-treap, ind = location of max-val in sub-treap (0-indexed)
    node *left, *right;

    node(int, int, node*, node*);
    void upd();
};

inline int get_cnt(node *N) {
    if(N == NULL) return 0;
    return N->cnt;
}

node::node(int _val, int _p, node *_left = NULL, node *_right = NULL) {
    val = _val;
    p = _p;
    left = _left;
    right = _right;

    upd();
}

void node::upd() {
    cnt = 1;
    cnt += get_cnt(left);
    cnt += get_cnt(right);

    ans = val; ind = get_cnt(left);
    if(left != NULL && left->ans >= ans) {
        ans = left->ans;
        ind = left->ind;
    }
    if(right != NULL && right->ans > ans) {
        ans = right->ans;
        ind = get_cnt(left) + 1 + right->ind;
    }
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

void insert(node*& root, int X, int val, int p, int pre = 0) {
    if(root == NULL) {
        root = new node(val, p);
        return;
    }

    int key = pre + get_cnt(root->left) + 1;

    if(X < key) {
        insert(root->left, X, val, p, pre);
        if(root->left->p < root->p) rotate_right(root);
    }
    else {
        insert(root->right, X, val, p, key);
        if(root->right->p < root->p) rotate_left(root);
    }

    root->upd();
}

void merge(node*& root, node* L, node* R) {
    if(L == NULL) {
        root = R;
        return;
    }

    if(R == NULL) {
        root = L;
        return;
    }

    if(L->p <= R->p) {
        root = L;
        merge(root->right, root->right, R);
    }
    else {
        root = R;
        merge(root->left, L, root->left);
    }

    root->upd();
}

void delete_node(node*& root, int X, int pre = 0) {
    if(root == NULL) return;

    int key = pre + get_cnt(root->left) + 1;

    if(X < key) {
        delete_node(root->left, X, pre);
    }
    else if(X > key) {
        delete_node(root->right, X, key);
    }
    else {
        merge(root, root->left, root->right);
    }

    if(root != NULL) {
        root->upd();
    }
}

void split(node*& root, int X, int p = -1) {
    insert(root, X, INT_MIN/2, p);
}

#include <iostream>
void _print_treap(node* root) {
  if(root == NULL) return;

  _print_treap(root->left);
  cout << root->val << " ";
  _print_treap(root->right);
}
void print_treap(node* root) {
  _print_treap(root);
  cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    srand(time(NULL));

    int N; long long K; cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> A[i];

    node* root = new node(A[1], rand());
    for(int i = 2; i <= N; i++) {
        merge(root, root, new node(A[i], rand()));
    }

    for(int i = 1; i <= N; i++) {
        int L = i, R = min(i + K, (long long)N);
        split(root, R, -2);
        split(root->left, L - 1, -1);

        int max_val = root->left->right->ans;
        int max_ind = root->left->right->ind + i;

        merge(root->left, root->left->left, root->left->right);
        merge(root, root->left, root->right);
        delete_node(root, max_ind);
        merge(root, new node(max_val, rand()), root);

        cout << max_val << " ";
        K -= max_ind - i;
    }

    cout << endl;
}
