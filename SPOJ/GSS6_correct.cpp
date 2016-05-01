#include "bits/stdc++.h"
using namespace std;
struct node{
    int val;
    int pre;
    int suf;
    int sum;
    int ans;
    int siz;
    int pri;
    node* left;
    node* right;
    node(int key = 0){
        val = key;
        pre = key;
        suf = key;
        sum = key;
        ans = key;
        siz = 1;
        pri = rand();
        left = NULL;
        right = NULL;
    }
};
int size(node* tree){
    if(tree){
        return tree -> siz;
    }
    return 0;
}
int value(node* tree){
    if(tree){
        return tree -> val;
    }
    return 0;
}
int prefix(node* tree){
    if(tree){
        return tree -> pre;
    }
    return 0;
}
int suffix(node* tree){
    if(tree){
        return tree -> suf;
    }
    return 0;
}
int sum(node* tree){
    if(tree){
        return tree -> sum;
    }
    return 0;
}
int answer(node* tree){
    if(tree){
        return tree -> ans;
    }
    return -99999;
}
void upd(node* &tree){
    if(tree){
        tree -> siz = size(tree -> left) + 1 + size(tree -> right);
        tree -> sum = value(tree) + sum(tree -> left) + sum(tree -> right);
        tree -> ans = max(max(answer(tree -> left) , answer(tree -> right)) , max(0 , suffix(tree -> left)) + value(tree) + max(0 , prefix(tree -> right)));
        tree -> pre = max(prefix(tree -> left) , sum(tree -> left) + value(tree) + max(0 , prefix(tree -> right)));
        tree -> suf = max(suffix(tree -> right) , max(0 , suffix(tree -> left)) + value(tree) + sum(tree -> right));
    }
}
void split(node* tree , node* &l , node* &r , int idx , int lcount){
    if(!tree){
        l = NULL;
        r = NULL;
        return;
    }
    int newidx = 1 + lcount + size(tree -> left);
    if(newidx <= idx){
        split(tree -> right , tree -> right , r , idx , newidx);
        l = tree;
    }
    else{
        split(tree -> left , l , tree -> left , idx , lcount);
        r = tree;
    }
    upd(tree);
}
void merge(node* &tree , node* l , node* r){
    if(!l || !r){
        tree = l ? l : r;
    }
    else if(l -> pri > r -> pri){
        merge(l -> right , l -> right , r);
        tree = l;
    }
    else{
        merge(r -> left , l , r -> left);
        tree = r;
    }
    upd(tree);
}
void update(node* &tree , int pos , int newval , int lcount){
    int idx = 1 + lcount + size(tree -> left);
    if(idx == pos){
        tree -> val = newval;
    }
    else if(pos < idx){
        update(tree -> left , pos , newval , lcount);
    }
    else{
        update(tree -> right , pos , newval , idx);
    }
    upd(tree);
}
node* root = NULL;
void insert(int pos , int key){
    node* temp1 = NULL;
    node* temp2 = NULL;
    node* temp3 = new node(key);
    split(root , temp1 , temp2 , pos - 1 , 0);
    merge(temp1 , temp1 , temp3);
    merge(root , temp1 , temp2);
}
void erase(int pos){
    node* temp1 = NULL;
    node* temp2 = NULL;
    node* temp3 = NULL;
    split(root , temp1 , temp2 , pos - 1 , 0);
    split(temp2 , temp3 , temp2 , 1 , 0);
    merge(root , temp1 , temp2);
    delete temp3;
    temp3 = NULL;
}
void replace(int pos , int newval){
    update(root , pos , newval , 0);
}
int query(int l , int r){
    node* temp1 = NULL;
    node* temp2 = NULL;
    node* temp3 = NULL;
    node* temp4 = NULL;
    split(root , temp1 , temp2 , l - 1 , 0);
    split(temp2 , temp3 , temp4 , r - l + 1 , 0);
    int ans = answer(temp3);
    merge(temp2 , temp3 , temp4);
    merge(root , temp1 , temp2);
    return ans;
}
int n;
char type[2];
int x , y;
int q;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &x);
        insert(i , x);
    }
    scanf("%d" , &q);
    while(q--){
        scanf("%s" , type);
        if(type[0] == 'I'){
            scanf("%d %d" , &x , &y);
            insert(x , y);
        }
        else if(type[0] == 'D'){
            scanf("%d" , &x);
            erase(x);
        }
        else if(type[0] == 'R'){
            scanf("%d %d" , &x , &y);
            replace(x , y);
        }
        else{
            scanf("%d %d" , &x , &y);
            printf("%d\n" , query(x , y));
        }
    }

}
