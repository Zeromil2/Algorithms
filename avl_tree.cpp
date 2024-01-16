#include <iostream>
using namespace std;

typedef struct BSTNode{
    int key;
    int element;
    int height;
    BSTNode* left;
    BSTNode* right;
}BSTNode;

BSTNode* create_bstnode(int k, int e){
    BSTNode* n = (BSTNode*) malloc(sizeof(BSTNode));
    n -> key = k;
    n -> element = e;
    n -> left = n -> right = NULL;
    return n;
}

typedef struct {
    BSTNode* root;
    int nodecount;
}BST;

BST* create_bst(){
    BST* bst = (BST*) malloc(sizeof(BST));
    bst -> root = NULL;
    bst -> nodecount = 0;
    return bst;
}

int findhelp(BSTNode* rt, int k){
    if (rt == NULL) return -1;
    if (rt -> key > k){
        return findhelp(rt -> left, k);
    } else if (rt -> key == k) {
        return rt -> element;
    } else {
        return findhelp(rt -> right, k);
    }
}

int find(BST* bst, int k){
    return findhelp(bst -> root, k);
}

int h(BSTNode* rt){
    if (rt == NULL) return -1;
    return rt -> height;
}

int getBalance(BSTNode* rt){
    if (rt == NULL) return 0;
    return h(rt -> left) - h(rt -> right);
}

BSTNode* rightRotate(BSTNode* rt){
    BSTNode* l = rt -> left;
    BSTNode* lr = l -> right;
    l -> right = rt;
    rt -> left = lr;
    rt -> height = max(h(rt -> left), h(rt -> right)) + 1;
    l -> height = max(h(l -> left), h(l -> right)) + 1;
    return l;
}

BSTNode* leftRotate(BSTNode* rt){
    BSTNode* r = rt -> right;
    BSTNode* rl = r -> left;
    r -> left = rt;
    rt -> right = rl;
    rt -> height = max(h(rt -> left), h(rt -> right)) + 1;
    r -> height = max(h(r -> left), h(r -> right)) + 1;
    return r;
}

BSTNode* inserthelp(BSTNode* rt, int k, int e){
    if (rt == NULL) return create_bstnode(k, e);
    if (rt -> key > k) {
        rt -> left = inserthelp(rt -> left, k, e);
    } else {
        rt -> right = inserthelp(rt -> right, k, e);
    }
    rt -> height = 1 + max(h(rt -> left), h(rt -> right));
    int balance = getBalance(rt);
    if (balance < -1  and k >= rt -> right -> key) return leftRotate(rt);
    if (balance > 1 and k < rt -> left -> key) return rightRotate(rt);
    if (balance > 1 and k >= rt -> left -> key){
        rt -> left = leftRotate(rt -> left);
        return rightRotate(rt);
    }
    if (balance < -1 and k < rt -> right -> key){
        rt -> right = rightRotate(rt -> right);
        return leftRotate(rt);
    }
    return rt;
}


void insert(BST* bst, int k, int e){
    bst -> root = inserthelp(bst -> root, k, e);
    bst -> nodecount++;
}

void preorder(BSTNode* rt){
    if (rt != NULL) {
        cout << rt -> element << "\n";
        preorder(rt -> left);
        preorder(rt -> right);
    }
}

int main() {

    int c, n, elemento;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n;
        BST* bst = create_bst();
        for (int j = 0; j < n; j++) {
            cin >> elemento;
            insert(bst, elemento, elemento);
        }
        preorder(bst -> root);
        cout << "END\n";
    }
    return 0;
}
