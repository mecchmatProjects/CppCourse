//
// Created by olga on 26.03.19.
// nullptr, auto, foreach are not forbidden
// C++11 is ok
//

#ifndef TREE_MOSKANOVA_TREE_H
#define TREE_MOSKANOVA_TREE_H

#define MAX_TREE_DEPTH 50

template<typename nodeType>
class TreeNode{
    nodeType data;
    TreeNode *parent;
    TreeNode** children;
    unsigned number_of_children;

public:
    explicit TreeNode(nodeType node_data);
    TreeNode();
    ~TreeNode();

    // Node data ops
    nodeType get_data();
    void set_data(nodeType new_data);

    // Parent ops
    TreeNode* get_parent();
    void set_parent(const TreeNode<nodeType> &new_parent);
    TreeNode** get_parents(); // full list of parents
    nodeType get_parent_data();
    nodeType* get_parents_data();

    // Children ops
    void add_child(const TreeNode<nodeType> &child);
    void add_child(TreeNode<nodeType> *child);
    nodeType *get_children_data();
    unsigned get_number_of_children();

    // Show section

//    void show(); // shows node data & stuff
};


//============== NODE CONSTRUCTORS ===============

template <typename nodeType>
TreeNode<nodeType>::TreeNode(nodeType node_data) {
    data = node_data;
    parent = nullptr;
    children = nullptr;
    number_of_children = 0;
}

template <typename nodeType>
TreeNode<nodeType>::TreeNode() {
    data = (nodeType) 0;
    children = nullptr;
    parent = nullptr;
    number_of_children = 0;
}

//============== NODE DESTRUCTOR ===============

template <typename nodeType>
TreeNode<nodeType>::~TreeNode() {
    if (number_of_children > 0) {
        for (int i = 0; i < number_of_children; i++) {
            delete children[i];
        }
        delete []children;
    }

    parent = nullptr;
}

//================== DATA OPS ==================

template <typename nodeType>
nodeType TreeNode<nodeType>::get_data() {
    return data;
}

template <typename nodeType>
void TreeNode<nodeType>::set_data(nodeType new_data) {
    data = new_data;
}

//================= PARENT OPS =================

template <typename nodeType>
TreeNode<nodeType>* TreeNode<nodeType>::get_parent() {
    return parent;
}

template <typename nodeType>
void TreeNode<nodeType>::set_parent(const TreeNode<nodeType> &new_parent) {
    parent = *new_parent;
}

template <typename nodeType>
TreeNode<nodeType>** TreeNode<nodeType>::get_parents() {
    if (this->parent == nullptr) {
        return nullptr;
    }

    TreeNode<nodeType>** parents;
    parents = new TreeNode<nodeType>*[MAX_TREE_DEPTH];

    unsigned parents_len = 0;
    TreeNode<nodeType>* currentNode = this;
    while (currentNode->parent != nullptr) {
        parents_len++;
        currentNode = this->parent;

        parents[parents_len - 1] = currentNode;
    }

    TreeNode<nodeType> **parents1 = new TreeNode<nodeType>[parents_len];
    for (int i = 0; i < parents_len; ++i) {
        parents1[i] = parents[i]; //todo hope this works
    }
    delete[] parents;

    return parents1;
}

template <typename nodeType>
nodeType TreeNode<nodeType>::get_parent_data() {
    return parent->data;
}

template <typename nodeType>
nodeType* TreeNode<nodeType>::get_parents_data() {
    if (this->parent == nullptr) {
        return nullptr;
    }

    nodeType* parents_data;
    parents_data = new nodeType[MAX_TREE_DEPTH];

    unsigned parents_len = 0;
    TreeNode<nodeType>* currentNode = this;
    while (currentNode->parent != nullptr) {
        parents_len++;
        currentNode = this->parent;

        parents_data[parents_len - 1] = currentNode->data;
    }

    auto parents_data1 = new nodeType[parents_len];
    for (int i = 0; i < parents_len; ++i) {
        parents_data1[i] = parents_data[i]; //todo hope this works
    }
    delete[] parents_data;

    return parents_data1;
}

//================ CHILDREN OPS ================

template <typename nodeType>
void TreeNode<nodeType>::add_child(const TreeNode<nodeType> &child) {
    if (number_of_children > 0) {
        auto new_children = new TreeNode<nodeType>*[number_of_children + 1];
        for (int i = 0; i < number_of_children; ++i) {
            new_children[i] = children[i];
        }
        new_children[number_of_children] = *child;
        number_of_children++;

        delete[] children;
        children = new_children;
    } else {
        number_of_children++;
        children = new TreeNode[number_of_children];
        children[0] = *child;
    }

    child.parent = this;
}

template <typename nodeType>
void TreeNode<nodeType>::add_child(TreeNode<nodeType> *child) {
    if (number_of_children > 0) {
        auto new_children = new TreeNode<nodeType> *[number_of_children + 1];
        for (int i = 0; i < number_of_children; ++i) {
            new_children[i] = children[i];
        }
        new_children[number_of_children] = child; // hope this is pointer
        number_of_children++;

        delete[] children;
        children = new_children;
    } else {
        number_of_children++;
        children = new TreeNode *[number_of_children];
        children[0] = child;
    }

    child->parent = this;
}

template <typename nodeType>
unsigned TreeNode<nodeType>::get_number_of_children() {
    return number_of_children;
}

template <typename nodeType>
nodeType* TreeNode<nodeType>::get_children_data() {
    auto children_data = new nodeType[number_of_children]; // a pointer :)
    for (int i = 0; i < number_of_children; i++) {
        children_data[i] = children[i]->data;
    }
    return children_data;
}

#endif //TREE_MOSKANOVA_TREE_H
