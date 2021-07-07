#ifndef TREE_MOSKANOVA_BINARYTREE_H
#define TREE_MOSKANOVA_BINARYTREE_H

#include<iostream>
#include<cstring>
#include<string.h>
#include<typeinfo>
#include<cmath>
#include<iomanip>
#include<random>

#define WIDTH 9
#define TEN "          "

typedef unsigned int ntype;
typedef int inttype;


template<typename nodeType>
class BinaryTreeNode{
private:
    nodeType data;
    BinaryTreeNode *parent;
    BinaryTreeNode *right;
    BinaryTreeNode *left;

    ntype get_width();
    ntype recursive_get_depth(ntype cur);
    bool is_in_tree(BinaryTreeNode<nodeType> *other);
    bool is_the_same(BinaryTreeNode<nodeType> *other);
    void output_level(ntype total_depth, ntype cur_level, BinaryTreeNode<nodeType> **the_children);
    BinaryTreeNode<nodeType>* recursive_copy_left_subtree(BinaryTreeNode<nodeType>* copy_of_parent);
    BinaryTreeNode<nodeType>* recursive_copy_right_subtree(BinaryTreeNode<nodeType>* copy_of_parent);
protected:
    // this is hidden recursion
    void show_adjacency_list(bool root);
    void show_adjacency_list(bool root, const char* filename);
public:
    explicit BinaryTreeNode(nodeType node_data);
    BinaryTreeNode();
    explicit BinaryTreeNode(BinaryTreeNode<nodeType> *node, bool child_free=false, bool save_parent=false);

    // Children ops
    void add_right_child(const BinaryTreeNode<nodeType> &child);
    void add_left_child(const BinaryTreeNode<nodeType> &child);
    void add_right_child(BinaryTreeNode<nodeType> *child);
    void add_left_child(BinaryTreeNode<nodeType> *child);
    BinaryTreeNode<nodeType>* get_left_child();
    BinaryTreeNode<nodeType>* get_right_child();
    BinaryTreeNode<nodeType>** get_children();
    ntype get_number_of_all_children();
    BinaryTreeNode<nodeType>** get_all_children_and_this();
    void remove_child(BinaryTreeNode<nodeType>* child);
    void remove_right_child(BinaryTreeNode<nodeType>* child);
    void remove_left_child(BinaryTreeNode<nodeType>* child);

    // DATA ops
    void set_data(nodeType new_data);
    nodeType get_data();
    nodeType *get_children_data();

    //PARENT ops
    BinaryTreeNode* get_parent();
    void set_parent(BinaryTreeNode<nodeType> &new_parent);
    BinaryTreeNode* get_root();
    BinaryTreeNode** get_parents();
    nodeType get_parent_data();
    nodeType* get_parents_data();
    ntype get_number_of_parents();

    //DEPTH
    ntype get_depth();                      // how many nodes are under this node
    ntype get_tree_depth();                 // depth of the whole tree

    //OUTPUT
    void output();
    void show_adjacency_matrix(ntype w=WIDTH);
    void show_adjacency_list(); // console
    void show_adjacency_list(const char* filename);
    // for node only
    template <typename NodeType>
    friend std::ostream &operator<<(std::ostream &cout, BinaryTreeNode<NodeType> *node);

    BinaryTreeNode<nodeType> *copy();
    BinaryTreeNode<nodeType> *copy_subtree();

    // CREATE RANDOM BINARY TREE
    BinaryTreeNode<nodeType>* create_recursive_random_tree(ntype depth);
    BinaryTreeNode<nodeType> *create_random_tree(ntype max_depth=10);
};

//====================== NODE CONSTRUCTORS ======================
template<typename nodeType>
BinaryTreeNode<nodeType>::BinaryTreeNode(nodeType node_data)
{
    data = node_data;
    parent = nullptr;
    right = nullptr;
    left = nullptr;
}

template <typename nodeType>
BinaryTreeNode<nodeType>::BinaryTreeNode()
{
    if (typeid(nodeType).name() == typeid(std::string).name())
    {
        data = '\0';
    }
    else
    {
        data = (nodeType) 0;
    }
    parent = nullptr;
    right = nullptr;
    left = nullptr;
}

//========================= NODE COPY =====================
template<typename nodeType>
BinaryTreeNode<nodeType>::BinaryTreeNode(BinaryTreeNode<nodeType> *node, bool child_free, bool save_parent)
{
    if (child_free)
    {
        left = nullptr;
        right = nullptr;
    } else{
        this = node->copy_subtree();
    }
    data = node->data;
    if (save_parent)
    {
        node->parent->add_child(this);
    }
    else
    {
        this->parent = nullptr;
    }
}

//======================= CHILDREN OPS ===========================
template<typename nodeType>
void BinaryTreeNode<nodeType>::add_right_child(const BinaryTreeNode<nodeType> &child)
{
    if (!(this->is_in_tree(child)))
    {
        if (right!=nullptr) {right->parent = nullptr;}
        *right = child;
        child.parent = this;
    }
    else
    {
        std::cout<<"Cannot add child, sorry)"<<std::endl;
    }
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::add_left_child(const BinaryTreeNode<nodeType> &child)
{
    if (!(this->is_in_tree(child)))
    {
        if (left!= nullptr) {left->parent = nullptr;}
        *left = child;
        child.parent = this;
    }
    else
    {
        std::cout<<"Cannot add child, sorry"<<std::endl;
    }
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::add_right_child(BinaryTreeNode<nodeType> *child)
{
    if (!(this->is_in_tree(child))) {
        if (right != nullptr) { right->parent = nullptr; }
        right = child;
        child->parent = this;
    }
    else
    {
        std::cout<<"Cannot add child, sorry)"<<std::endl;
    }
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::add_left_child(BinaryTreeNode<nodeType> *child)
{
    if (!(this->is_in_tree(child)))
    {
        if (left!= nullptr) {left->parent = nullptr;}
        left = child;
        child->parent = this;
    }
    else
    {
        std::cout<<"Cannot add child, sorry)"<<std::endl;
    }
}

template<typename nodeType>
nodeType *BinaryTreeNode<nodeType>::get_children_data()
{
    auto *children_data = new nodeType[2];
    if (left==nullptr && right==nullptr)
    {
        if (typeid(nodeType).name() == typeid(std::string).name())
        {
            children_data[0] = '\0';
            children_data[1] = '\0';
        }
        else
        {
            children_data[0] = (nodeType)0;
            children_data[1] = (nodeType)0;
        }
    }
    else if (left!=nullptr && right!=nullptr)
    {
        children_data[0] = right->data;
        children_data[1] = left->data;
    }
    else
    {
        if (right!=nullptr)
        {
            children_data[1] = right->data;
            if (typeid(nodeType).name() == typeid(std::string).name())
            {children_data[0] = '\0';}
            else
            {children_data[0] = (nodeType)0;}
        }
        else
        {
            children_data[0] = left->data;
            if (typeid(nodeType).name() == typeid(std::string).name())
            {children_data[1] = '\0';}
            else
            {children_data[1] = (nodeType)0;}
        }
    }
    return children_data;
}

template<typename nodeType>
BinaryTreeNode<nodeType>* BinaryTreeNode<nodeType>::get_left_child()
{
    return left;
}

template<typename nodeType>
BinaryTreeNode<nodeType>* BinaryTreeNode<nodeType>::get_right_child()
{
    return right;
}

template<typename nodeType>
BinaryTreeNode<nodeType>** BinaryTreeNode<nodeType>::get_children()
{
    BinaryTreeNode<nodeType> chldrn = new BinaryTreeNode<nodeType>[2];
    chldrn[0]=left;
    chldrn[1]=right;
    return chldrn;
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::remove_child(BinaryTreeNode<nodeType>* child)
{
    if (this->right->is_the_same(child))
    {
        child->parent=nullptr;
        this->right=nullptr;
    }
    else if (this->left->is_the_same(child))
    {
        child->parent=nullptr;
        this->left=nullptr;
    }
    else
    {
        std::cout<<"Couldn't remove child: the node doesn't have such a child";
    }
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::remove_right_child(BinaryTreeNode<nodeType>* child)
{
    if (this->right->is_the_same(child))
    {
        child->parent=nullptr;
        this->right=nullptr;
    }
    else
    {
        std::cout<<"Couldn't remove child: the node doesn't have such a child";
    }
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::remove_left_child(BinaryTreeNode<nodeType>* child)
{
    if (this->left->is_the_same(child))
    {
        child->parent=nullptr;
        this->left=nullptr;
    }
    else
    {
        std::cout<<"Couldn't remove child: the node doesn't have such a child";
    }
}

// ======================= DATA OPS ==============================
template<typename nodeType>
nodeType BinaryTreeNode<nodeType>::get_data()
{
    return data;
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::set_data(nodeType new_data)
{
    data = new_data;
}

//========================= PARENT OPS ===========================
template<typename nodeType>
void BinaryTreeNode<nodeType>::set_parent(BinaryTreeNode<nodeType> &new_parent)
{
    if (parent!=nullptr)
    {
        if (parent->left==this) {parent->left = nullptr;}
        else {parent->right = nullptr;}
    }
    parent = new_parent;
}

template<typename nodeType>
BinaryTreeNode<nodeType>* BinaryTreeNode<nodeType>::get_parent()
{
    return this->parent;
}

template<typename nodeType>
nodeType BinaryTreeNode<nodeType>::get_parent_data()
{
    if (parent==nullptr)
    {
        if (typeid(nodeType).name() == typeid(std::string).name()) {return '\0';}
        else {return (nodeType)0;}
    }
    else
    {
        return parent->data;
    }
}

template<typename nodeType>
ntype BinaryTreeNode<nodeType>::get_number_of_parents()
{
    if (parent==nullptr)
    {
        return 0;
    }
    else
    {
        return 1+parent->get_number_of_parents();
    }
}

template<typename nodeType>
BinaryTreeNode<nodeType>** BinaryTreeNode<nodeType>::get_parents()
{
    ntype num = get_number_of_parents();
    if (num==0) {return nullptr;}
    auto **parents = new BinaryTreeNode<nodeType>* [num];
    parents[0] = parent;
    for (ntype i=1; i<num; i++)
    {
        parents[i] = parents[i-1]->parent;
    }
    return parents;
}

template<typename nodeType>
nodeType* BinaryTreeNode<nodeType>::get_parents_data()
{
    ntype num = get_number_of_parents();
    if (num==0) {return nullptr;}
    auto *parents_data = new nodeType[num];
    auto **parents = new BinaryTreeNode<nodeType>* [num];
    parents[0] = parent;
    parents_data[0] = parent->data;
    for (ntype i=0; i<num; i++)
    {
        parents[i]=parents[i-1]->parent;
        parents_data[i] = parents[i]->data;
    }
    delete [] parents;
    return parents_data;
}

// ======================== DEPTH ==================================
template<typename nodeType>
ntype BinaryTreeNode<nodeType>::get_depth()
{
    ntype depth=0;
    ntype cur_depth_l=0, cur_depth_r = 0;
    if (left==nullptr && right==nullptr)
    {
        return depth;
    }
    else
    {
        if (left!=nullptr)
        {
            cur_depth_l++;
            return left->recursive_get_depth(cur_depth_l);
        }
        if (right!=nullptr)
        {
            cur_depth_r++;
            return right->recursive_get_depth(cur_depth_r);
        }
        if (cur_depth_l>cur_depth_r) {return cur_depth_l;}
        else {return cur_depth_r;}
    }
}

template<typename nodeType>
ntype BinaryTreeNode<nodeType>::recursive_get_depth(ntype cur)
{
    if (left==nullptr && right==nullptr){return cur;}
    else
    {
        ntype cur_l = cur, cur_r=cur;
        if (left!=nullptr)
        {
            cur_l =  left->recursive_get_depth(cur+1);
        }
        if (right!=nullptr)
        {
            cur_r = right->recursive_get_depth(cur+1);
        }
        if (cur_l>cur_r){return cur_l;}
        else {return cur_r;}
    }
}

template<typename nodeType>
ntype BinaryTreeNode<nodeType>::get_tree_depth()
{
    return (this->get_root()->get_depth());
}

//========================= OUTPUT =================================
template <typename NodeType>
std::ostream &operator<<(std::ostream &cout, BinaryTreeNode<NodeType> *node)
{
    cout << "node " << node->data << "\n"<< "parent node ";
    if (node->parent == nullptr){
        cout << "does not exist";
    } else  {
        cout << node->parent->data;
    }
    cout << "\n" << "left child: ";
    if (node->left == nullptr) {
        cout << "does not exist";
    } else {
        cout << node->left->data;
    }
    cout << "\n" << "right child: ";
    if (node->right == nullptr) {
        cout << "does not exist";
    } else {
        cout << node->right->data;
    }
    return cout;
}

template<typename nodeType>
ntype BinaryTreeNode<nodeType>::get_width()
{
    ntype rezult=-1;
    if (typeid(nodeType).name() == typeid(std::string).name()) {
        rezult = data.length();
    }
    return rezult;
}

std::string my_string(ntype n, char symbol)
{
    std::string rez="";
    for (ntype l=0; l<n; l++)
    {
        rez.push_back(symbol);
    }
    return rez;
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::output_level(ntype total_depth, ntype cur_level, BinaryTreeNode<nodeType> **the_children)
{
    ntype my_num, p, p_long, n2, kil, current_number;
    if (total_depth-cur_level==0)
    {
        my_num=0;
        p=0;
        p_long=2;
        n2=0;
        kil=0;
    }
    else if (total_depth-cur_level==1)
    {
        my_num=0;
        p=7;
        p_long=14;
        n2=10;
        kil=0;
    }
    else
    {
        if (total_depth-cur_level==2){my_num=12;}
        else {my_num = 12*pow(2, (total_depth-cur_level-2));}
        p=my_num+(total_depth-cur_level);
        p_long = 2*my_num+2;
        n2 = p_long-4;
        kil=my_num-6;
    }

    current_number = pow(2, cur_level);

    std::cout<<my_string(p, ' ');
    for (ntype i=0; i<current_number; i++)
    {
        std::cout<<my_string(kil, '_');
        if (the_children[i]!=nullptr)
        {
            if (typeid(nodeType).name() == typeid(std::string).name())
            {
                std::string my_data;
                my_data = the_children[i]->data;
                std::string the_data="";
                ntype l = my_data.length();
                if (l==0)
                {
                    the_data=my_string(10, '_');
                }
                else if (l<=10)
                {
                    for (ntype z=0; z<l; z++)
                    {
                        the_data.push_back(my_data[z]);
                    }

                    for (ntype z=0; z<(10-l); z++)
                    {the_data.push_back('_');}
                }
                else
                {
                    for (ntype z=0; z<10; z++)
                    {
                        the_data.push_back(my_data[z]);
                    }
                }
                std::cout<<the_data;
            }
            else
            {
                std::cout<<std::setw(10)<<std::setfill('_')<<std::setprecision(3)<<the_children[i]->data;
            }
        }
        else {std::cout<<TEN;}
        std::cout<<my_string(kil, '_')<<my_string(p_long, ' ');
    }

    std::cout<<std::endl;
    if (total_depth!=cur_level)
    {
        std::cout<<my_string(p-1, ' ');
        char c1='/', c2='\\';
        for (ntype i=0; i<current_number; i++)
        {
            if (the_children[i]==nullptr || the_children[i]->left==nullptr){c1=' ';} else {c1='/';}
            if (the_children[i]==nullptr || the_children[i]->right==nullptr){c2=' ';} else {c2='\\';}
            std::cout<<c1<<my_string(n2, ' ')<<c2<<my_string(p_long-2, ' ');
        }
    }
    std::cout<<std::endl;
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::output()
{
    ntype d = get_depth(), i;
    ntype total_num=1;
    for (ntype j=0; j<d; j++)
    {
        total_num*=2;
    }
    auto **the_children = new BinaryTreeNode<nodeType>* [total_num+1];
    for (i=0; i<total_num; i++)
    {
        the_children[i] = nullptr;
    }
    the_children[0]=this;
    for (i=0; i<=d; i++)
    {
        output_level(d, i, the_children);

        if (i<d)
        {
            ntype cur_num=1;
            for (ntype j=0; j<i; j++)
            {
                cur_num*=2;
            }
            for (inttype k=cur_num; k>=0; k--)
            {
                if (the_children[k]!=nullptr)
                {
                    the_children[2*k+1]=the_children[k]->right;
                    the_children[2*k] = the_children[k]->left;
                }
                else
                {
                    the_children[2*k+1] = nullptr;
                    the_children[2*k] = nullptr;
                }
            }
        }
    }
}

template<typename nodeType>
ntype BinaryTreeNode<nodeType>::get_number_of_all_children()
{
    ntype n1=0;
    if (left!=nullptr && right!=nullptr) {return 2+left->get_number_of_all_children()+right->get_number_of_all_children();}
    else if (right!=nullptr){return 1+right->get_number_of_all_children();}
    else if (left!=nullptr){return 1+left->get_number_of_all_children();}
    else {return 0;}
}

template<typename nodeType>
BinaryTreeNode<nodeType>** BinaryTreeNode<nodeType>::get_all_children_and_this()
{
    ntype num = get_number_of_all_children();
    auto **all_children = new BinaryTreeNode<nodeType>* [num+1];
    auto **next_1 = new BinaryTreeNode<nodeType>* [num+1];
    auto **next_2 = new BinaryTreeNode<nodeType>* [num+1];
    BinaryTreeNode* root = this->copy_subtree();
    all_children[0]=root;
    ntype f=0, counter=1, k, l, n1=0, n2=0;
    if (root->left!=nullptr)
    {
        next_1[n1]=root->left;
        n1++;
    }
    if (root->right!=nullptr)
    {
        next_1[n1]=right;
        n1++;
    }
    while (counter<num+1)
    {
        n2=0;
        for (k=0; k<n1; k++)
        {
            all_children[counter]=next_1[k];
            counter++;
            if (next_1[k]->left!=nullptr) {next_2[n2]=next_1[k]->left; n2++;}
            if (next_1[k]->right!=nullptr) {next_2[n2]=next_1[k]->right; n2++;}
        }
        n1=0;
        for (k=0; k<n2; k++)
        {
            all_children[counter]=next_2[k];
            counter++;
            if (next_2[k]->left!=nullptr) {next_1[n1]=next_2[k]->left; n1++;}
            if (next_2[k]->right!=nullptr) {next_1[n1]=next_2[k]->right; n1++;}
        }
    }
    return all_children;
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::show_adjacency_matrix(ntype w)
{
    ntype num = get_number_of_all_children()+1;
    auto **pointers = new BinaryTreeNode<nodeType>*[num];
    pointers = get_all_children_and_this();
    std::cout<<std::setw(w)<<std::setfill(' ')<<"";
    if (typeid(nodeType).name() == typeid(std::string).name())
    {
        std::string great_data;
        for (ntype k=0; k<num; k++){
            great_data = pointers[k]->get_data();
            if (great_data.length()>w-1)
            {
                std::cout<<' ';
                for (ntype q=0; q<w-1; q++) {std::cout<<great_data[q];}
            }
            else
            {
                for (ntype q=great_data.length(); q<w; q++)
                {std::cout<<' ';}
                std::cout<<great_data;
            }
        }
    }
    else
    {
        for (ntype k=0; k<num; k++){
            std::cout<<std::setw(w)<<std::setfill(' ')<<pointers[k]->get_data();}
    }

    std::cout<<'\n';
    for (ntype i=0; i<num; i++)
    {
        if (typeid(nodeType).name() == typeid(std::string).name())
        {
            std::string great_data;
            great_data = pointers[i]->get_data();
            ntype l = great_data.length();
            if (l>w-1)
            {
                std::cout<<' ';
                for (ntype q=0; q<w-1; q++) {std::cout<<great_data[q];}

            }
            else
            {
                for (ntype q=l; q<w; q++)
                {std::cout<<' ';}
                std::cout<<great_data;
            }
        }
        else
        {
            std::cout<<std::setw(w)<<std::setfill(' ')<<pointers[i]->data;
        }
        for (ntype j=0; j<num; j++)
        {
            if (pointers[i]->parent==pointers[j]){
                std::cout<<std::setw(w)<<std::setfill(' ')<<1;}
            else{
                std::cout<<std::setw(w)<<std::setfill(' ')<<0;}
        }
        std::cout<<std::endl;
    }
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::show_adjacency_list(bool root)
{
    // for this node
    if (root) {
        std::cout << data << ": (";
    } else {
        std::cout << data << ": ("
                  << parent->data << ", ";
    }
    if (left!=nullptr)
    {
        std::cout<<left->get_data()<<", ";
    }
    if (right!=nullptr)
    {
        std::cout<<right->get_data()<<", ";
    }
    std::cout << ")" << std::endl;
    // for children
    if (left!=nullptr)
    {
        left->show_adjacency_list(false);
    }
    if (right!=nullptr)
    {
        right->show_adjacency_list(false);
    }
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::show_adjacency_list(bool root, const char* filename)
{

}

template<typename nodeType>
void BinaryTreeNode<nodeType>::show_adjacency_list()
{
    show_adjacency_list(true);
}

template<typename nodeType>
void BinaryTreeNode<nodeType>::show_adjacency_list(const char* filename)
{
    show_adjacency_list(true, filename);
}

//=========================== COPY ==============================
template<typename nodeType>
BinaryTreeNode<nodeType> *BinaryTreeNode<nodeType>::copy()
{
    auto *new_node = new BinaryTreeNode<nodeType>(this->data);
    return new_node;
}

template<typename nodeType>
BinaryTreeNode<nodeType>* BinaryTreeNode<nodeType>::recursive_copy_left_subtree(BinaryTreeNode<nodeType>* copy_of_parent)
{
    auto *the_copy = new BinaryTreeNode<nodeType>;
    the_copy = this->copy();
    copy_of_parent->add_left_child(the_copy);
    if (this->left!=nullptr)
    {
        the_copy->left = this->left->recursive_copy_left_subtree(the_copy);
    }
    if (this->right!=nullptr)
    {
        the_copy->right = this->right->recursive_copy_right_subtree(the_copy);
    }
    return the_copy;
}

template<typename nodeType>
BinaryTreeNode<nodeType>* BinaryTreeNode<nodeType>::recursive_copy_right_subtree(BinaryTreeNode<nodeType>* copy_of_parent)
{
    auto *the_copy = new BinaryTreeNode<nodeType>;
    the_copy = this->copy();
    copy_of_parent->add_right_child(the_copy);
    if (this->left!=nullptr)
    {
        the_copy->left = this->left->recursive_copy_left_subtree(the_copy);
    }
    if (this->right!=nullptr)
    {
        the_copy->right = this->right->recursive_copy_right_subtree(the_copy);
    }
    return the_copy;
}

template<typename nodeType>
BinaryTreeNode<nodeType> *BinaryTreeNode<nodeType>::copy_subtree()
{
    auto *new_root = new BinaryTreeNode<nodeType>;
    new_root = this->copy();
    if (left!=nullptr)
    {
        new_root->left = left->recursive_copy_left_subtree(new_root);
    }
    if (right!=nullptr)
    {
        new_root->right = right->recursive_copy_right_subtree(new_root);
    }
    return new_root;
}

// =========================== OTHER ===============================
template<typename nodeType>
BinaryTreeNode<nodeType>* BinaryTreeNode<nodeType>::get_root()
{
    if (this->parent==nullptr) {return this;}
    else
    {
        return (this->parent->get_root());
    }
}

template<typename nodeType>
bool BinaryTreeNode<nodeType>::is_the_same(BinaryTreeNode<nodeType> *other)
{
    return this==other;
}

template<typename nodeType>
bool BinaryTreeNode<nodeType>::is_in_tree(BinaryTreeNode<nodeType> *other)
{

    return (this->get_root()->is_the_same(other->get_root()));
}

// ====================== CREATE RANDOM TREE ====================
template<typename nodeType>
BinaryTreeNode<nodeType>* BinaryTreeNode<nodeType>::create_recursive_random_tree(ntype depth)
{
    auto *rand_node = new BinaryTreeNode<nodeType>;

    rand_node->data = (nodeType)rand();
    if (depth)
    {
        ntype has_left_child = rand() % 2;
        ntype has_right_child = rand() % 2;
        if (has_left_child)
        {
            rand_node->add_left_child(create_recursive_random_tree(depth-1));
        }
        if (has_right_child)
        {
            rand_node->add_right_child(create_recursive_random_tree(depth-1));
        }
    }
    return rand_node;
}

template<typename nodeType>
BinaryTreeNode<nodeType>* BinaryTreeNode<nodeType>::create_random_tree(ntype max_depth)
{
    ntype the_depth = rand() % max_depth;
    std::cout<<"the_depth = "<<the_depth<<std::endl;
    auto *rand_root = new BinaryTreeNode<nodeType>;
    rand_root->data = (nodeType)rand();
    rand_root->parent=nullptr;
    if (the_depth)
    {
        ntype has_left_child = rand() % 2;
        ntype has_right_child = rand() % 2;
        if (has_left_child)
        {
            rand_root->add_left_child(create_recursive_random_tree(the_depth-1));
        }
        if (has_right_child)
        {
            rand_root->add_right_child(create_recursive_random_tree(the_depth-1));
        }
    }
    return rand_root;
}


#endif //TREE_MOSKANOVA_BINARYTREE_H