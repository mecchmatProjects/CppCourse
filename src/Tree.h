#ifndef _TREE_H
#define _TREE_H

#include"TreeError.h"
#include<fstream>
#include<ostream>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string.h>
#include<typeinfo>

#define STR_LEN 50
#define OUTPUT_STR "        "  //for the graphic representation of tree (output function)
#define WIDTH 6                // for adjacency matrix output

typedef unsigned int ntype;


template<typename nodeType>
class TreeNode{
private:
    nodeType data;
    TreeNode *parent;
    TreeNode** children;
    ntype number_of_children;

    static char output_str[STR_LEN];

    TreeNode<nodeType>* recursive_copy_subtree(TreeNode<nodeType> *copy_of_parent_node); //alisa func
    ntype recursive_get_depth(ntype cur);
    bool is_in_tree(TreeNode<nodeType> *other);
    bool is_the_same(TreeNode<nodeType> *other);
    TreeNode<nodeType>* create_recursive_random_tree(ntype depth, ntype max_num_of_children);
protected:
    // this is hidden recursion
    void show_adjacency_list(bool root);
    void show_adjacency_list(bool root, const char* filename);
public:
    //NODE CONSTRUCTORS, COPY, DESTRUCTOR
    explicit TreeNode(nodeType node_data);
    explicit TreeNode(TreeNode<nodeType> *node, bool child_free = false, bool save_parent = false);
    TreeNode();
    ~TreeNode();

    //CREATE RANDOM TREE
    TreeNode<nodeType>* create_random_tree(ntype max_depth=10, ntype max_num_of_children=10);

    // COPY
    TreeNode<nodeType> *copy();
    TreeNode<nodeType> *copy_subtree();

    // Node DATA ops
    nodeType get_data();
    void set_data(nodeType new_data);

    // PARENT ops
    TreeNode* get_parent();
    void set_parent(const TreeNode<nodeType> &new_parent);
    TreeNode** get_parents(); // full list of parents
    nodeType get_parent_data();
    nodeType* get_parents_data();
    ntype get_number_of_parents();

    // ROOT
    TreeNode* get_root();

    // DEPTH
    ntype get_depth();
    ntype get_tree_depth();

    // CHILDREN
    ntype get_number_of_all_children();
    void add_child(const TreeNode<nodeType> &child);
    void add_child(TreeNode<nodeType> *child);
    nodeType *get_children_data();
    ntype get_number_of_children();
    TreeNode<nodeType>** get_children();
    TreeNode<nodeType>** get_all_children_and_this();
    void remove_child(TreeNode<nodeType> *child);            //doesn't delete the child

    //OUTPUT SECTION
    // for (sub)tree
    void show_adjacency_matrix(); // console
    void show_adjacency_matrix(const char* filename);
    void show_adjacency_list(); // console
    void show_adjacency_list(const char* filename);
    void output();
    // for node only
    template <typename NodeType>
    friend std::ostream &operator<<(std::ostream &cout, TreeNode<NodeType> *node);

    void delete_this_node(); //this node's children will become it's parent's children
};

template<typename nodeType>
char TreeNode<nodeType>::output_str[STR_LEN]="";

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
    if (typeid(nodeType).name() == typeid(std::string).name())
    {
        data = '\0';
    }
    else
    {
        data = (nodeType) 0;
    }
    children = nullptr;
    parent = nullptr;
    number_of_children = 0;
}

//================== NODE COPY =================
template<typename nodeType>
TreeNode<nodeType>::TreeNode(TreeNode<nodeType> *node, bool child_free, bool save_parent)
{
    this->data = node->data;

    if (save_parent)
    {
        node->parent->add_child(this);
    }
    else
    {
        parent=nullptr;
    }

    if (child_free || node->number_of_children == 0)
    {
        number_of_children = 0;
        children = nullptr;
    }
    else
    {
        number_of_children = node->number_of_children;
        children = new TreeNode<nodeType> *[number_of_children];
        for (ntype i=0; i<number_of_children; i++)
        {
            children[i] = new TreeNode<nodeType>(node->children[i]);
        }
    }
}

template<typename nodeType>
TreeNode<nodeType> *TreeNode<nodeType>::copy()
{
    auto* new_node = new TreeNode<nodeType>;
    new_node->data = data;
    if (parent==nullptr) {new_node->parent = nullptr;}
    else
    {new_node->parent = parent;
        parent->add_child(new_node);
    };
    new_node->number_of_children = 0;
    new_node->children = nullptr;
    return new_node;
}

template<typename nodeType>
TreeNode<nodeType>* TreeNode<nodeType>::recursive_copy_subtree(TreeNode<nodeType> *copy_of_parent_node)
{
    auto *node_copy = new TreeNode<nodeType>;
    node_copy->data = this->data;
    node_copy->parent = copy_of_parent_node;
    node_copy->number_of_children = this->number_of_children;
    if (number_of_children)
    {
        node_copy->children = new TreeNode<nodeType>* [number_of_children];
        for (ntype i=0; i<number_of_children; i++)
        {
            node_copy->children[i] = this->children[i]->recursive_copy_subtree(node_copy);
        }
    }
    return node_copy;
}

template<typename nodeType>
TreeNode<nodeType> *TreeNode<nodeType>::copy_subtree()
{
    auto *new_node = new TreeNode<nodeType>;
    new_node->data = data;
    new_node->parent = NULL;
    new_node->number_of_children = number_of_children;
    if (number_of_children>0)
    {
        new_node->children = new TreeNode<nodeType>* [number_of_children];
        for (ntype i=0; i<number_of_children; ++i)
        {
            new_node->children[i] = children[i]->recursive_copy_subtree(new_node);
        }
    }
    else
    {
        new_node->children = nullptr;
    }
    return new_node;
}

//============== NODE DESTRUCTOR ===============
template <typename nodeType>
TreeNode<nodeType>::~TreeNode()
{
    if (number_of_children > 0)
    {
        for (ntype i = 0; i < number_of_children; ++i) {
            delete children[i];
        }
        delete [] children;
        number_of_children = 0; //without this i had segmentation fault
    }
    parent = nullptr;
}

// ========================= CREATE RANDOM TREE ===========================
template<typename nodeType>
TreeNode<nodeType>* TreeNode<nodeType>::create_random_tree(ntype max_depth, ntype max_num_of_children)
{
    ntype the_depth = rand() % max_depth;
    auto *rand_root = new TreeNode<nodeType>;
    rand_root->data = (nodeType)rand();
    rand_root->parent=nullptr;
    if (the_depth)
    {
        ntype num_of_ch = rand() % max_num_of_children;
        std::cout<<"num_children = "<<num_of_ch<<std::endl;
        if (num_of_ch)
        {
            for (ntype i=0; i<num_of_ch; i++)
            {
                rand_root->add_child(create_recursive_random_tree(the_depth-1, max_num_of_children));
            }
        }
        else
        {
            rand_root->children = nullptr;
        }
    }
    return rand_root;
}

template<typename nodeType>
TreeNode<nodeType>* TreeNode<nodeType>::create_recursive_random_tree(ntype depth, ntype max_num_of_children)
{
    auto *rand_node = new TreeNode<nodeType>;
    rand_node->data = (nodeType)rand();
    if (depth)
    {
        ntype num_of_ch = rand() % max_num_of_children;
        if (num_of_ch)
        {
            for (ntype i=0; i<num_of_ch; i++)
            {
                rand_node->add_child(create_recursive_random_tree(depth-1, max_num_of_children));
            }
        }
        else
        {
            rand_node->children = nullptr;
        }
    }
    return rand_node;
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
template<typename nodeType>
ntype TreeNode<nodeType>::get_number_of_parents()
{
    if (parent==nullptr) {return 0;}
    else
    {
        return 1+parent->get_number_of_parents;
    }
}

template <typename nodeType>
TreeNode<nodeType>* TreeNode<nodeType>::get_parent() {
    return parent;
}

template <typename nodeType>
void TreeNode<nodeType>::set_parent(const TreeNode<nodeType> &new_parent) {
    if (parent!=NULL){
        parent->remove_child(*this);
    }
    parent = *new_parent;
}

template <typename nodeType>
TreeNode<nodeType>** TreeNode<nodeType>::get_parents() {
    if (this->parent == nullptr) {
        return nullptr;
    }

    TreeNode<nodeType>** parents;
    ntype number = get_number_of_parents();
    parents = new TreeNode<nodeType>*[number];

    TreeNode<nodeType>* currentNode = this;
    for (ntype i=0; i<number; ++i)
    {
        currentNode = currentNode->parent;
        parents[i] = currentNode;
    }
    return parents;
}

template <typename nodeType>
nodeType TreeNode<nodeType>::get_parent_data() {
    if (parent==nullptr)
    {
        if (typeid(nodeType).name() == typeid(std::string).name()) {return '\0';}
        else {return (nodeType)0;}
    }
    else {return parent->data;}
}

template <typename nodeType>
nodeType* TreeNode<nodeType>::get_parents_data() {
    if (this->parent == nullptr) {
        return nullptr;
    }

    nodeType* parents_data;
    ntype number_of_parents = get_number_of_parents();
    parents_data = new nodeType[number_of_parents];

    TreeNode<nodeType>* currentNode = this;
    for (ntype i=0; i<number_of_parents; i++)
    {
        currentNode = currentNode->parent;
        parents_data[i] = currentNode->data;
    }
    return parents_data;
}

//================ CHILDREN OPS ================
template <typename nodeType>
void TreeNode<nodeType>::add_child(const TreeNode<nodeType> &child) {
    if (!(is_in_tree(child)))
    {
        if (child->parent!=nullptr)
        {
            child->parent->remove_child(child);
        }
        if (number_of_children > 0) {
            auto new_children = new TreeNode<nodeType> *[number_of_children + 1];
            for (ntype i = 0; i < number_of_children; ++i) {
                new_children[i] = children[i];
            }
            new_children[number_of_children] = *child;//&child
            number_of_children++;
        } else {
            number_of_children++;
            children = new TreeNode [number_of_children];
            children[0] = *child;
        }
        child.parent = this;
    }
    else
    {
        std::cout<<"cannot add child_node: this node is already in this tree"<<std::endl;
    }
}

template<typename nodeType>
void TreeNode<nodeType>::add_child(TreeNode<nodeType>*child){
    if (!(this->is_in_tree(child)))
    {
        if (child->parent!=nullptr)
        {
            child->parent->remove_child(child);
        }
        if (number_of_children>0)
        {
            auto new_children = new TreeNode<nodeType>*[number_of_children+1];
            for (ntype i=0; i<number_of_children; ++i){
                new_children[i] = children[i];
            }
            new_children[number_of_children] = child;
            number_of_children++;
            delete[] children;
            children = new_children;
        } else{
            number_of_children++;
            children = new TreeNode*[number_of_children];
            children[0] = child;
        }
        child->parent = this;
    }
    else
    {
        std::cout<<"cannot add child_node: this node is already in this tree"<<std::endl;
    }
}

template <typename nodeType>
ntype TreeNode<nodeType>::get_number_of_children() {
    return number_of_children;
}

template <typename nodeType>
nodeType* TreeNode<nodeType>::get_children_data() {
    if (children==nullptr) {return nullptr;}
    auto children_data = new nodeType[number_of_children]; // a pointer :)
    for (ntype i = 0; i < number_of_children; i++) {
        children_data[i] = children[i]->data;
    }
    return children_data;
}

template<typename nodeType>
TreeNode<nodeType>** TreeNode<nodeType>::get_children()
{
    return children;
}

template<typename nodeType>
ntype TreeNode<nodeType>::get_number_of_all_children()
{
    if (number_of_children==0) {return 0;}
    ntype rez=number_of_children;
    for (ntype k=0; k<number_of_children;k++)
    {
        rez+=children[k]->get_number_of_all_children();
    }
    return rez;
}

template<typename nodeType>
TreeNode<nodeType>** TreeNode<nodeType>::get_all_children_and_this()
{
    ntype number=get_number_of_all_children();
    TreeNode<nodeType> **the_list = new TreeNode<nodeType>* [number+1];
    TreeNode<nodeType> **next_1 = new TreeNode<nodeType>* [number+1];
    TreeNode<nodeType> **next_2 = new TreeNode<nodeType>* [number+1];
    ntype i, j, k, counter=1;
    for (i=0; i<number; i++)
    {
        the_list[i] = nullptr;
        next_1[i] = nullptr;
        next_2[i] = nullptr;
    }
    TreeNode<nodeType> *test_node=this->copy_subtree();
    the_list[0]=test_node;
    ntype next_1_cur_num = test_node->get_number_of_children(), next_2_cur_num=0;
    next_1 = test_node->get_children();
    while (counter<number)
    {
        ntype f=0;

        for (j=0; j<next_1_cur_num; j++)
        {
            the_list[counter]=next_1[j];
            counter++;
            for (k=0; k<next_1[j]->get_number_of_children(); k++)
            {
                next_2[f]=next_1[j]->get_children()[k];
                f++;
            }
            next_2_cur_num+=next_1[j]->get_number_of_children();
            std::cout<<"next_2_cur_num = "<<next_2_cur_num<<std::endl;
        }
        f=0;
        next_1_cur_num=0;
        for (j=0; j<next_2_cur_num; j++)
        {
            the_list[counter] = next_2[j];
            counter++;
            for (k=0; k<next_2[j]->get_number_of_children(); k++)
            {
                next_1[f]=next_2[j]->get_children()[k];
                f++;
            }
            next_1_cur_num+=next_2[j]->get_number_of_children();

            std::cout<<"  ===next_1_cur_num = "<<next_1_cur_num<<std::endl;
        }
    }
    delete [] next_1;
    delete [] next_2;
    return the_list;
}

template<typename nodeType>
void TreeNode<nodeType>::remove_child(TreeNode<nodeType> *child)
{
    if (number_of_children>=2)
    {
        auto new_children = new TreeNode<nodeType>*[number_of_children-1];
        ntype j=0, num = number_of_children;
        for (ntype i=0; i<number_of_children; i++)
        {
            if (!(children[i]->is_the_same(child)))
            {
                if (j!=number_of_children-1)
                {
                    new_children[j] = children[i];
                    j++;
                }
                else
                {
                    delete [] new_children;
                    new_children = nullptr;
                }
            }
        }
        if (new_children!=nullptr)
        {
            delete [] children;
            children = new_children;
            number_of_children--;
        }
    }
    else if (number_of_children==1)
    {
        if (children[0]->is_the_same(child))
        {
            child->parent = nullptr;
            children = nullptr;
            number_of_children--;
        }
    }
}

//================== OTHER FUNCTIONS ==============
template<typename nodeType>
bool TreeNode<nodeType>::is_the_same(TreeNode<nodeType> *other)
{
    return (this == other);
}

template<typename nodeType>
TreeNode<nodeType>* TreeNode<nodeType>::get_root()
{
    if (this->parent==nullptr)
    {
        return this;
    }
    else
    {
        return parent->get_root();
    }
}

template<typename nodeType>
bool TreeNode<nodeType>::is_in_tree(TreeNode<nodeType> *other)
{
    return (this->get_root()->is_the_same(other->get_root()));
}

ntype my_max(ntype* ar, ntype len)
{
    ntype maxi=0;
    for (ntype i=0; i<len; i++)
    {
        if (ar[i]>maxi)
        {maxi = ar[i];}
    }
    return maxi;
}

template<typename nodeType>
void TreeNode<nodeType>::delete_this_node()
{
    TreeNode<nodeType>* p=parent;
    this->parent->remove_child(this);
    if (number_of_children>0)
    {
        for (ntype i=0; i<number_of_children; i++)
        {
            p->add_child(children[i]);
        }
    }
}

// ====================== DEPTH ====================
template<typename nodeType>
ntype TreeNode<nodeType>::recursive_get_depth(ntype cur)
{
    if (number_of_children)
    {
        auto *depths = new ntype[number_of_children];
        for (ntype i=0; i<number_of_children; i++)
        {
            depths[i] = children[i]->recursive_get_depth(cur+1);
        }
        return my_max(depths, number_of_children);
    }
    else
    {
        return cur;
    }
}

template<typename nodeType>
ntype TreeNode<nodeType>::get_tree_depth()
{
    return (this->get_root()->get_depth());
}

template<typename nodeType>
ntype TreeNode<nodeType>::get_depth()
{
    ntype cur=0;
    return recursive_get_depth(cur);
}

//================ OUTPUT SECTION ================
template<typename nodeType>
void TreeNode<nodeType>::output()
{
    if (this->parent==nullptr) {output_str[0]='\0';}
    if (output_str[strlen(output_str)-1]=='|')
    {
        ntype l = strlen(output_str);
        if (output_str[l-2]=='|'){output_str[l-1]='\0';}
        std::cout<<this->output_str << "---<" << this->data << '>' << std::endl;
    }
    else {std::cout<<this->output_str << "|---<" << this->data << '>' << std::endl;}
    if (output_str[strlen(output_str)-1]==' '){strcat(output_str, "|");}
    if (number_of_children) {
        strcat(output_str, OUTPUT_STR);
        children[0]->output();
        strcat(output_str, "|");
        for (ntype i = 1; i < number_of_children; ++i) {
            children[i]->output();
        }
        ntype l = strlen(output_str);
        output_str[l - 10] = '\0';
    }
}

template <typename nodeType>
void TreeNode<nodeType>::show_adjacency_list() {
    show_adjacency_list(true);
}

template <typename nodeType>
void TreeNode<nodeType>::show_adjacency_list(bool root) {
    // for this node
    if (root) {
        std::cout << data << ": (";
    } else {
        std::cout << data << ": ("
                  << parent->data << ", ";
    }
    for (ntype i = 0; i < number_of_children; ++i) {
        std::cout << children[i]->data << ", ";
    }
    std::cout << ")" << std::endl;

    // for children
    for (ntype i = 0; i < number_of_children; ++i) {
        children[i]->show_adjacency_list(false);
    }
}

template <typename nodeType>
void TreeNode<nodeType>::show_adjacency_list(const char* filename) {
    show_adjacency_list(true, filename);
}

template <typename nodeType>
void TreeNode<nodeType>::show_adjacency_list(bool root, const char* filename) {
    try {
        std::fstream fstream(filename, std::ios::out | std::ios::app);

        if (!fstream) throw TreeError(1);

        // for this node
        if (root) {
//            std::fstream fstream(filename, std::ios::out);

//            if (!fstream) throw TreeError(1);

            fstream << data << ": (";
            fstream.seekg(std::ios_base::beg);
        } else {
//            std::fstream fstream(filename, std::ios::app);

//            if (!fstream) throw TreeError(1);

            fstream.seekg(std::ios_base::end);
            fstream << data << ": ("
                    << parent->data << ", ";
        }
        for (int i = 0; i < number_of_children; ++i) {
            fstream << children[i]->data << ", ";
        }
        fstream << ")" << std::endl;
        fstream.close();

        // for children
        for (int i = 0; i < number_of_children; ++i) {
            children[i]->show_adjacency_list(false, filename);
        }
    } catch (TreeError &treeError) {
//        treeError.Message();
        std::cout << "oops";
    }
}

template <typename NodeType>
std::ostream &operator<<(std::ostream &cout, TreeNode<NodeType> *node) {

    cout << "node " << node->data << "\n"<< "parent node ";
    if (node->parent == nullptr){
        cout << "does not exist";
    } else  {
        cout << node->parent->data;
    }
    cout << "\n" << "children nodes: ";
    if (node->number_of_children == 0) {
        cout << "do not exist";
    } else {
        cout << "\n";
        for (ntype i = 0; i < node->number_of_children; ++i) {
            cout << node->children[i]->data << ", ";
        }
    }
    return cout;
}

template <typename nodeType>
void TreeNode<nodeType>::show_adjacency_matrix() {
    ntype num = get_number_of_all_children()+1;
    TreeNode<nodeType> **pointers = get_all_children_and_this();
    std::cout<<std::setw(WIDTH)<<std::setfill(' ')<<"";
    if (typeid(nodeType).name() == typeid(std::string).name())
    {
        std::string great_data;
        for (ntype k=0; k<num; k++){
            great_data = pointers[k]->get_data();
            if (great_data.length()>WIDTH-1)
            {
                std::cout<<' ';
                for (ntype q=0; q<WIDTH-1; q++) {std::cout<<great_data[q];}
            }
            else
            {
                for (ntype q=great_data.length(); q<WIDTH; q++)
                {std::cout<<' ';}
                std::cout<<great_data;
            }
        }
    }
    else
    {
        for (ntype k=0; k<num; k++){
            std::cout<<std::setw(WIDTH)<<std::setfill(' ')<<pointers[k]->get_data();}
    }

    std::cout<<'\n';
    for (ntype i=0; i<num; i++)
    {
        if (typeid(nodeType).name() == typeid(std::string).name())
        {
            std::string great_data;
            great_data = pointers[i]->get_data();
            ntype l = great_data.length();
            if (l>WIDTH-1)
            {
                std::cout<<' ';
                for (ntype q=0; q<WIDTH-1; q++) {std::cout<<great_data[q];}

            }
            else
            {
                for (ntype q=l; q<WIDTH; q++)
                {std::cout<<' ';}
                std::cout<<great_data;
            }
        }
        else
        {
            std::cout<<std::setw(WIDTH)<<std::setfill(' ')<<pointers[i]->data;
        }
        for (ntype j=0; j<num; j++)
        {
            if (pointers[i]->parent==pointers[j]){
                std::cout<<std::setw(WIDTH)<<std::setfill(' ')<<1;}
            else{
                std::cout<<std::setw(WIDTH)<<std::setfill(' ')<<0;}
        }
        std::cout<<std::endl;
    }
}

template <typename nodeType>
void TreeNode<nodeType>::show_adjacency_matrix(const char* filename) {
    try {
        std::fstream fstream(filename, std::ios::out | std::ios::app);

        if (!fstream) throw TreeError(1);
        fstream<<"matrix"<<std::endl;
        ntype num = get_number_of_all_children()+1;
        TreeNode<nodeType> **pointers = get_all_children_and_this();
        fstream<<std::setw(WIDTH)<<std::setfill(' ')<<"";
        if (typeid(nodeType).name() == typeid(std::string).name())
        {
            std::string great_data;
            for (ntype k=0; k<num; k++){
                great_data = pointers[k]->get_data();
                if (great_data.length()>WIDTH-1)
                {
                    fstream<<' ';
                    for (ntype q=0; q<WIDTH-1; q++) {fstream<<great_data[q];}
                }
                else
                {
                    for (ntype q=great_data.length(); q<WIDTH; q++)
                    {fstream<<' ';}
                    fstream<<great_data;
                }
            }
        }
        else
        {
            for (ntype k=0; k<num; k++){
                fstream<<std::setw(WIDTH)<<std::setfill(' ')<<pointers[k]->get_data();}
        }

        fstream<<'\n';
        for (ntype i=0; i<num; i++)
        {
            if (typeid(nodeType).name() == typeid(std::string).name())
            {
                std::string great_data;
                great_data = pointers[i]->get_data();
                ntype l = great_data.length();
                if (l>WIDTH-1)
                {
                    fstream<<' ';
                    for (ntype q=0; q<WIDTH-1; q++) {fstream<<great_data[q];}
                }
                else
                {
                    for (ntype q=l; q<WIDTH; q++)
                    {fstream<<' ';}
                    fstream<<great_data;
                }
            }
            else
            {
                fstream<<std::setw(WIDTH)<<std::setfill(' ')<<pointers[i]->data;
            }
            for (ntype j=0; j<num; j++)
            {
                if (pointers[i]->parent==pointers[j]){
                    fstream<<std::setw(WIDTH)<<std::setfill(' ')<<1;}
                else{
                    fstream<<std::setw(WIDTH)<<std::setfill(' ')<<0;}
            }
            fstream<<std::endl;
        }
        fstream.close();
    } catch (TreeError &treeError) {
        std::cout << "oops";
    }
}


#endif //TREE_MOSKANOVA_TREE_H