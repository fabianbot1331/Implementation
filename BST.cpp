#include <bits/stdc++.h>
using namespace std;

template<typename data_type>
struct BST {

    struct TreeNode {
        data_type data;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;

        TreeNode(
            data_type data = data_type(),
            TreeNode* left = nullptr,
            TreeNode* right = nullptr,
            TreeNode* parent = nullptr
        ) :
            data(data),
            left(left),
            right(right),
            parent(parent) {}
    };

    TreeNode* root;
    int sz;

    BST() {
        root = nullptr;
        sz = 0;
    }

    bool empty() const {
        return root == nullptr;
    }

    int size() const {
        return sz;
    }

    TreeNode* find(data_type key) const {
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->data == key)
                return current;

            if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }

        return nullptr;
    }

    bool search(data_type key) const {
        return find(key) != nullptr;
    }

    bool insert(data_type value) {
        if (root == nullptr) {
            root = new TreeNode(value);
            sz++;
            return true;
        }

        TreeNode* current = root;
        TreeNode* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (value == current->data)
                return false;

            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        TreeNode* new_node =
            new TreeNode(value, nullptr, nullptr, parent);

        if (value < parent->data)
            parent->left = new_node;
        else
            parent->right = new_node;

        sz++;

        return true;
    }

    TreeNode* min_element(TreeNode* u) const {
        if (u == nullptr)
            return nullptr;

        while (u->left != nullptr)
            u = u->left;

        return u;
    }

    TreeNode* max_element(TreeNode* u) const {
        if (u == nullptr)
            return nullptr;

        while (u->right != nullptr)
            u = u->right;

        return u;
    }

    TreeNode* min_element() const {
        return min_element(root);
    }

    TreeNode* max_element() const {
        return max_element(root);
    }

    TreeNode* successor(TreeNode* x) const {
        if (x == nullptr)
            return nullptr;

        if (x->right != nullptr)
            return min_element(x->right);

        TreeNode* y = x->parent;

        while (y != nullptr && x == y->right) {
            x = y;
            y = y->parent;
        }

        return y;
    }

    TreeNode* predecessor(TreeNode* x) const {
        if (x == nullptr)
            return nullptr;

        if (x->left != nullptr)
            return max_element(x->left);

        TreeNode* y = x->parent;

        while (y != nullptr && x == y->left) {
            x = y;
            y = y->parent;
        }

        return y;
    }

    TreeNode* lower_bound(data_type value) const {
        TreeNode* current = root;
        TreeNode* answer = nullptr;

        while (current != nullptr) {
            if (current->data >= value) {
                answer = current;
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        return answer;
    }

    TreeNode* upper_bound(data_type value) const {
        TreeNode* current = root;
        TreeNode* answer = nullptr;

        while (current != nullptr) {
            if (current->data > value) {
                answer = current;
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        return answer;
    }

    TreeNode* floor(data_type value) const {
        TreeNode* current = root;
        TreeNode* answer = nullptr;

        while (current != nullptr) {
            if (current->data == value)
                return current;

            if (current->data < value) {
                answer = current;
                current = current->right;
            }
            else {
                current = current->left;
            }
        }

        return answer;
    }

    TreeNode* ceil(data_type value) const {
        return lower_bound(value);
    }

    void transplant(TreeNode* u, TreeNode* v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }

        if (v != nullptr)
            v->parent = u->parent;
    }

    void erase(TreeNode* u) {
        if (u == nullptr)
            return;

        if (u->left == nullptr) {
            transplant(u, u->right);
            delete u;
        }
        else if (u->right == nullptr) {
            transplant(u, u->left);
            delete u;
        }
        else {
            TreeNode* succ = min_element(u->right);

            if (succ->parent != u) {

                transplant(succ, succ->right);

                succ->right = u->right;
                succ->right->parent = succ;
            }

            transplant(u, succ);

            succ->left = u->left;
            succ->left->parent = succ;

            delete u;
        }

        sz--;
    }

    bool erase(data_type value) {
        TreeNode* node = find(value);

        if (node == nullptr)
            return false;

        erase(node);

        return true;
    }

    int height(TreeNode* u) const {
        if (u == nullptr)
            return -1;

        return 1 + max(
            height(u->left),
            height(u->right)
        );
    }

    int height() const {
        return height(root);
    }

    void print_subtree_inorder(TreeNode* u) const {
        if (u == nullptr)
            return;

        print_subtree_inorder(u->left);

        cout << u->data << " ";

        print_subtree_inorder(u->right);
    }

    void print_inorder() const {
        print_subtree_inorder(root);
        cout << '\n';
    }

    void print_subtree_preorder(TreeNode* u) const {
        if (u == nullptr)
            return;

        cout << u->data << " ";

        print_subtree_preorder(u->left);
        print_subtree_preorder(u->right);
    }

    void print_preorder() const {
        print_subtree_preorder(root);
        cout << '\n';
    }

    void print_subtree_postorder(TreeNode* u) const {
        if (u == nullptr)
            return;

        print_subtree_postorder(u->left);
        print_subtree_postorder(u->right);

        cout << u->data << " ";
    }

    void print_postorder() const {
        print_subtree_postorder(root);
        cout << '\n';
    }

    void clear(TreeNode* u) {
        if (u == nullptr)
            return;

        clear(u->left);
        clear(u->right);

        delete u;
    }

    void clear() {
        clear(root);

        root = nullptr;
        sz = 0;
    }

    ~BST() {
        clear();
    }
};


int main() {

    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(35);
    tree.insert(45);
    tree.insert(65);

    cout << "INORDER\n";
    tree.print_inorder();

    cout << "\nPREORDER\n";
    tree.print_preorder();

    cout << "\nPOSTORDER\n";
    tree.print_postorder();


    cout << "\nSIZE\n";
    cout << tree.size() << '\n';


    cout << "\nHEIGHT\n";
    cout << tree.height() << '\n';


    cout << "\nSEARCH\n";

    cout << "Existe 40: "
         << tree.search(40) << '\n';

    cout << "Existe 100: "
         << tree.search(100) << '\n';


    cout << "\nMIN / MAX\n";

    auto mn = tree.min_element();
    auto mx = tree.max_element();

    if (mn)
        cout << "Minimo: " << mn->data << '\n';

    if (mx)
        cout << "Maximo: " << mx->data << '\n';


    cout << "\nSUCCESSOR / PREDECESSOR\n";

    auto node = tree.find(40);

    if (node != nullptr) {

        auto succ = tree.successor(node);
        auto pred = tree.predecessor(node);

        if (succ)
            cout << "Sucesor de 40: "
                 << succ->data << '\n';

        if (pred)
            cout << "Predecesor de 40: "
                 << pred->data << '\n';
    }


    cout << "\nLOWER BOUND\n";

    auto lb = tree.lower_bound(42);

    if (lb)
        cout << "lower_bound(42): "
             << lb->data << '\n';
    else
        cout << "No existe\n";


    cout << "\nUPPER BOUND\n";

    auto ub = tree.upper_bound(40);

    if (ub)
        cout << "upper_bound(40): "
             << ub->data << '\n';


    cout << "\nFLOOR / CEIL\n";

    auto fl = tree.floor(42);
    auto ce = tree.ceil(42);

    if (fl)
        cout << "floor(42): "
             << fl->data << '\n';

    if (ce)
        cout << "ceil(42): "
             << ce->data << '\n';


    cout << "\nERASE HOJA: 20\n";

    tree.erase(20);
    tree.print_inorder();


    cout << "\nERASE NODO CON UN HIJO: 60\n";

    tree.erase(60);
    tree.print_inorder();


    cout << "\nERASE NODO CON DOS HIJOS: 70\n";

    tree.erase(70);
    tree.print_inorder();


    cout << "\nERASE ROOT: 50\n";

    tree.erase(50);
    tree.print_inorder();


    cout << "\nSIZE FINAL\n";
    cout << tree.size() << '\n';


    cout << "\nCLEAR\n";

    tree.clear();

    cout << "Empty: "
         << tree.empty() << '\n';

    cout << "Size: "
         << tree.size() << '\n';

    return 0;
}
