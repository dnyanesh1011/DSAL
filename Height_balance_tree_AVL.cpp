#include <iostream>
using namespace std;

class node {
public:
    int data;
    int bal;
    node *left;
    node *right;
};

class Tree {
public:
    node *insert(node *, node *);
    node *rotateRight(node *);
    node *rotateLeft(node *);
    void disp(node *, int);
};

void Tree::disp(node* root, int k) {
    int i;
    if (root) {
        disp(root->right, k + 1);
        cout << endl;
        for (i = 0; i < k; i++)
            cout << ' ';
        cout << root->data;
        disp(root->left, k + 1);
    }
}

node *Tree::insert(node *root, node *s) {
    if (s->data > root->data) {
        if (root->right == NULL)
            root->right = s;
        else
            root->right = insert(root->right, s);
    }

    if (s->data <= root->data) {
        if (root->left == NULL)
            root->left = s;
        else
            root->left = insert(root->left, s);
    }

    if (root->left == NULL && root->right != NULL)
        root->bal = -1;
    else if (root->left != NULL && root->right == NULL)
        root->bal = 1;
    else
        root->bal = 0;

    // Case 1: Left of Left
    if (root->bal == 1 && root->left->bal == 1)
        root = rotateRight(root);
    // Case 2: Right of Right
    if (root->bal == -1 && root->right->bal == -1)
        root = rotateLeft(root);
    // Case 3: Right of Left
    if (root->bal == 1 && root->left->bal == -1) {
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }
    // Case 4: Left of Right
    if (root->bal == -1 && root->right->bal == 1) {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }

    return root;
}

node *Tree::rotateRight(node *root) {
    node *temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

node *Tree::rotateLeft(node *root) {
    node *temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

int main() {
    int ch, c;
    char temp;
    node *root, *s;
    Tree t;
    root = NULL;

    do {
        s = new node;
        s->bal = 0;
        s->left = NULL;
        s->right = NULL;
        cout << endl << "Enter node of tree::";
        cin >> s->data;

        if (root == NULL)
            root = s;
        else
            root = t.insert(root, s);

        cout << endl << endl << "Tree is :" << endl << endl;
        t.disp(root, 1);
        cout << endl;

        cout << endl << "WANT TO ENTER MORE ELEMENTS(y/n)::";
        cin >> temp;

    } while (temp == 'y' || temp == 'Y');

    cout << endl;
    return 0;
}
