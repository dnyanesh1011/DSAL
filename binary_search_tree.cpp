#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
};

class bst {
public:
    node *root;
    bst() {
        root = NULL;
    }
    void create();
    void insert();
    void postorder(node*);
    void inorder(node*);
    void preorder(node*);
    void search(int key);
    void minimum();
    int height(node*);
};

void bst::minimum() {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    node *temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }

    cout << "Minimum number is: " << temp->data << endl;
}

int bst::height(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}

void bst::create() {
    node *curr, *temp;
    int ans = 1;
    cout << "Enter data: ";
    do {
        curr = new node;
        cin >> curr->data;
        curr->left = curr->right = NULL;

        if (root == NULL) {
            root = curr;
        } else {
            temp = root;
            while (true) {
                if (curr->data <= temp->data) {
                    if (temp->left == NULL) {
                        temp->left = curr;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == NULL) {
                        temp->right = curr;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }

        cout << "Want to continue? (1 for Yes / 0 for No): ";
        cin >> ans;
    } while (ans == 1);
}

void bst::inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << " " << root->data;
        inorder(root->right);
    }
}

void bst::preorder(node *root) {
    if (root != NULL) {
        cout << " " << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void bst::postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << " " << root->data;
    }
}

void bst::insert() {
    node *curr = new node;
    node *temp;
    cout << "Enter data: ";
    cin >> curr->data;
    curr->left = curr->right = NULL;

    if (root == NULL) {
        root = curr;
    } else {
        temp = root;
        while (true) {
            if (curr->data <= temp->data) {
                if (temp->left == NULL) {
                    temp->left = curr;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = curr;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
}

void bst::search(int key) {
    node *curr = root;
    while (curr != NULL) {
        if (curr->data == key) {
            cout << "Found" << endl;
            return;
        } else if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    cout << "Not found" << endl;
}

int main() {
    bst b;
    int key, ch;
    do {
        cout << endl;
        cout << "1. Create" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Inorder" << endl;
        cout << "4. Preorder" << endl;
        cout << "5. Postorder" << endl;
        cout << "6. Search" << endl;
        cout << "7. Minimum" << endl;
        cout << "8. Height" << endl;
        cout << "Press 0 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            b.create();
            break;
        case 2:
            b.insert();
            break;
        case 3:
            cout << "Inorder traversal is: ";
            b.inorder(b.root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder traversal is: ";
            b.preorder(b.root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder traversal is: ";
            b.postorder(b.root);
            cout << endl;
            break;
        case 6:
            cout << "Enter key to search: ";
            cin >> key;
            b.search(key);
            break;
        case 7:
            b.minimum();
            break;
        case 8:
            cout << "Height of tree: " << b.height(b.root) << endl;
            break;
        }
    } while (ch != 0);

    return 0;
}
