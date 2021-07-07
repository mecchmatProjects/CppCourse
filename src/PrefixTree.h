#ifndef TREE_MOSKANOVA_PREFIXTREE_H
#define TREE_MOSKANOVA_PREFIXTREE_H


#include"TreeError.h"
#include<string>
#include<typeinfo>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<string.h>
#define STR_LEN 50
#define OUTPUT_STR "           "
#define WIDTH 6


typedef float ftype;
typedef unsigned int ntype;

template<typename nodeType>
class PrefixTreeNode{
private:
    nodeType data;
    PrefixTreeNode **children;
    ftype  weight;
    PrefixTreeNode *parent;
    ntype number_of_children;

    ntype recursive_get_depth(ntype cur);
    PrefixTreeNode<nodeType>* recursive_copy_subtree(PrefixTreeNode<nodeType> *copy_of_parent_node);
    static char output_str[STR_LEN];

    PrefixTreeNode<nodeType>* create_recursive_random_tree(ntype depth, ntype max_num_of_children);

    bool is_the_same(PrefixTreeNode<nodeType> *other);
    bool is_in_tree(PrefixTreeNode<nodeType> *other);
protected:
    // this is hidden recursion
    void show_adjacency_list(bool root);
    void show_adjacency_list(bool root, const char* filename);
public:
    explicit PrefixTreeNode(nodeType node_data);
    PrefixTreeNode();
    PrefixTreeNode(nodeType node_data, ftype  weight);
    ~PrefixTreeNode();
    explicit PrefixTreeNode(PrefixTreeNode<nodeType> *node, bool child_free=false, bool save_parent=false);

    PrefixTreeNode<nodeType>* copy_subtree();
    PrefixTreeNode<nodeType> *copy();

    //weight
    ftype  get_weight();
    void set_weight(ftype  new_weight);

    //data
    nodeType get_data();
    void set_data(nodeType new_data);

    //PARENTS
    PrefixTreeNode* get_parent();
    void set_parent(const PrefixTreeNode<nodeType> &new_parent);
    PrefixTreeNode** get_parents(); // full list of parents
    nodeType get_parent_data();
    nodeType* get_parents_data();
    ntype get_number_of_parents();

    //children
    void add_child(const PrefixTreeNode<nodeType> &child);
    void add_child(PrefixTreeNode<nodeType> *child);
    ntype get_number_of_children();
    nodeType* get_children_data();
    void remove_child(PrefixTreeNode<nodeType> *child);
    PrefixTreeNode<nodeType>** get_children();
    ntype get_number_of_all_children();
    PrefixTreeNode<nodeType>** get_all_children_and_this();

    //depth
    ntype get_depth();
    ntype get_tree_depth();

    //root
    PrefixTreeNode<nodeType>* get_root();

    // random prefix tree create
    PrefixTreeNode<nodeType>* create_random_tree(ntype max_depth=4, ntype max_num_children=5);

    //OUTPUT
    void output();
    void show_adjacency_matrix();
    void show_adjacency_matrix(const char *filename);
    void show_adjacency_list(); // console
    void show_adjacency_list(const char *filename);
    // for node only
    template <typename NodeType>
    friend std::ostream &operator<<(std::ostream &cout, PrefixTreeNode<NodeType> *node);

    //other
    void delete_this_node();
};


template<typename nodeType>
char PrefixTreeNode<nodeType>::output_str[STR_LEN]="";

// ======================PREFIX_TREE_NODE CONSTRUCTORS ====================
template<typename nodeType>
PrefixTreeNode<nodeType>::PrefixTreeNode()
{
    if (typeid(nodeType).name() == typeid(std::string).name())
    {
        data = '\0';
    }
    else
    {
        data = (nodeType) 0;
    }
    children = nullptr;
    weight = 0;
    parent = nullptr;
    number_of_children = 0;
}

template<typename nodeType>
PrefixTreeNode<nodeType>::PrefixTreeNode(nodeType node_data)
{
    data = node_data;
    children = nullptr;
    weight = 0;
    parent = nullptr;
    number_of_children = 0;
}

template<typename nodeType>
PrefixTreeNode<nodeType>::PrefixTreeNode(nodeType node_data, ftype  node_weight)
{
    data=node_data;
    children=nullptr;
    weight=node_weight;
    parent=nullptr;
    number_of_children=0;
}

// ======================== DESTRUCTOR ======================
template<typename nodeType>
PrefixTreeNode<nodeType>::~PrefixTreeNode()
{
    if (number_of_children > 0)
    {
        for (ntype i = 0; i < number_of_children; ++i) {
            delete children[i];
        }
        delete [] children;
        number_of_children = 0;
    }
    parent = nullptr;
}

// ======================== COPY ============================
template<typename nodeType>
PrefixTreeNode<nodeType>::PrefixTreeNode(PrefixTreeNode<nodeType> *node, bool child_free, bool save_parent)
{
    data = node->data;
    if (child_free || node->number_of_children==0)
    {
        children=nullptr;
        number_of_children = 0;
    } else {
        number_of_children = node->number_of_children;
        children = new PrefixTreeNode<nodeType> *[number_of_children];
        for (ntype i = 0; i < number_of_children; i++) {
            children[i] = new PrefixTreeNode<nodeType>(node->children[i]);
            children[i]->set_weight(node->children[i]->get_weight());
        }
    }
    if (save_parent)
    {
        node->parent->add_child(this);
        weight = node->get_weight();
    } else{
        parent=nullptr;
    }
}

template<typename nodeType>
PrefixTreeNode<nodeType>* PrefixTreeNode<nodeType>::recursive_copy_subtree(PrefixTreeNode<nodeType> *copy_of_parent_node)
{
    auto *node_copy = new PrefixTreeNode<nodeType>;
    node_copy->data = this->data;
    node_copy->weight = this->weight;
    node_copy->parent = copy_of_parent_node;
    node_copy->number_of_children = this->number_of_children;
    if (number_of_children>0)
    {
        node_copy->children = new PrefixTreeNode<nodeType>* [number_of_children];
        for (ntype i=0; i<number_of_children; i++)
        {
            node_copy->children[i] = this->children[i]->recursive_copy_subtree(node_copy);
        }
    }
    else
    {
        node_copy->number_of_children = 0;
        node_copy->children = nullptr;
    }
    return node_copy;
}

template<typename nodeType>
PrefixTreeNode<nodeType>* PrefixTreeNode<nodeType>::copy_subtree()
{

    auto *new_node = new PrefixTreeNode<nodeType>;
    new_node->data = data;
    new_node->parent = NULL;
    new_node->weight=0;
    new_node->number_of_children = number_of_children;
    if (number_of_children>0)
    {
        new_node->children = new PrefixTreeNode<nodeType>* [number_of_children];
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

template<typename nodeType>
PrefixTreeNode<nodeType>* PrefixTreeNode<nodeType>::copy()
{
    PrefixTreeNode<nodeType> new_node = new PrefixTreeNode<nodeType>;
    new_node->set_data(this->data);
    new_node->set_weight(this->weight);
    return new_node;
}

// ====================== WEIGHT OPS =========================
template<typename nodeType>
ftype  PrefixTreeNode<nodeType>::get_weight()
{
    return weight;
}

template<typename nodeType>
void PrefixTreeNode<nodeType>::set_weight(ftype new_weight)
{
    weight = new_weight;
}

// ===================== DATA OPS ==============================
template<typename nodeType>
void PrefixTreeNode<nodeType>::set_data(nodeType new_data)
{
    data=new_data;
}

template<typename nodeType>
nodeType PrefixTreeNode<nodeType>::get_data()
{
    return data;
}

// ==================== CHILDREN OPS ============================
template <typename nodeType>
void PrefixTreeNode<nodeType>::add_child(const PrefixTreeNode<nodeType> &child) {
    if (!(is_in_tree(child)))
    {
        if (child->parent!=nullptr)
        {
            child->parent->remove_child(child);
        }
        if (number_of_children > 0) {
            auto new_children = new PrefixTreeNode<nodeType> *[number_of_children + 1];
            for (ntype i = 0; i < number_of_children; ++i) {
                new_children[i] = children[i];
            }
            new_children[number_of_children] = *child;//&child
            number_of_children++;
        } else {
            number_of_children++;
            children = new PrefixTreeNode [number_of_children];
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
void PrefixTreeNode<nodeType>::add_child(PrefixTreeNode<nodeType> *child){
    if (!(this->is_in_tree(child)))
    {
        if (child->parent!=nullptr)
        {
            child->parent->remove_child(child);
        }
        if (number_of_children>0)
        {
            auto new_children = new PrefixTreeNode<nodeType>*[number_of_children+1];
            for (ntype i=0; i<number_of_children; ++i){
                new_children[i] = children[i];
            }
            new_children[number_of_children] = child;
            number_of_children++;
            delete[] children;
            children = new_children;
        } else{
            number_of_children++;
            children = new PrefixTreeNode*[number_of_children];
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
ntype PrefixTreeNode<nodeType>::get_number_of_children() {
    return number_of_children;
}

template <typename nodeType>
nodeType* PrefixTreeNode<nodeType>::get_children_data() {
    if (children==nullptr) {return nullptr;}
    auto children_data = new nodeType[number_of_children]; // a pointer :)
    for (ntype i = 0; i < number_of_children; i++) {
        children_data[i] = children[i]->data;
    }
    return children_data;
}

template<typename nodeType>
void PrefixTreeNode<nodeType>::remove_child(PrefixTreeNode<nodeType> *child)
{
    if (number_of_children>=2)
    {
        auto new_children = new PrefixTreeNode<nodeType>*[number_of_children-1];
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

template<typename nodeType>
PrefixTreeNode<nodeType>** PrefixTreeNode<nodeType>::get_children()
{
    return children;
}

// ========================= DEPTH ==========================
template<typename nodeType>
ntype PrefixTreeNode<nodeType>::get_depth()
{
    ntype cur=0;
    return recursive_get_depth(cur);
}

ntype my_max(unsigned* ar, ntype len)
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
ntype PrefixTreeNode<nodeType>::recursive_get_depth(ntype cur)
{
    if (number_of_children)
    {
        auto *depths = new unsigned[number_of_children];
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
ntype PrefixTreeNode<nodeType>::get_tree_depth()
{
    return this->get_root()->get_depth();
}

// ======================= PARENT FUNCS ===================
template<typename nodeType>
PrefixTreeNode<nodeType>* PrefixTreeNode<nodeType>::get_parent()
{
    return this->parent;
}

template<typename nodeType>
void PrefixTreeNode<nodeType>::set_parent(const PrefixTreeNode<nodeType> &new_parent)
{
    if (this->parent!=nullptr)
    {
        this->parent->remove_child(this);
    }
    new_parent.add_child(this);
}

template<typename nodeType>
PrefixTreeNode<nodeType>** PrefixTreeNode<nodeType>::get_parents()
{
    ntype num = get_number_of_parents();
    auto **rez_parents = new PrefixTreeNode<nodeType>* [num];
    PrefixTreeNode<nodeType> *cur=this;
    for (ntype i=0; i<num; i++)
    {
        rez_parents[i]=cur;
        cur = cur->get_parent();
    }
    return rez_parents;
}

template<typename nodeType>
nodeType PrefixTreeNode<nodeType>::get_parent_data()
{
    return this->parent->data;
}

template<typename nodeType>
nodeType* PrefixTreeNode<nodeType>::get_parents_data()
{
    ntype num = get_number_of_parents();
    auto *par_data = new nodeType[num];
    PrefixTreeNode<nodeType>* cur=this;
    for (ntype i=0; i<num; i++)
    {
        par_data = cur->get_data();
        cur = cur->get_parent();
    }
    return par_data;
}

template<typename nodeType>
ntype PrefixTreeNode<nodeType>::get_number_of_parents()
{
    if (this->parent==nullptr) {return 0;}
    else
    {
        return 1+this->parent->get_number_of_parents();
    }
}

// =======================OTHER FUNCS =======================
template<typename nodeType>
PrefixTreeNode<nodeType>* PrefixTreeNode<nodeType>::get_root()
{
    if (this->parent==nullptr) {return this;}
    else {return this->parent->get_root();}
}

template<typename nodeType>
void PrefixTreeNode<nodeType>::delete_this_node()
{
    PrefixTreeNode<nodeType>* p=parent;
    this->parent->remove_child(this);
    if (number_of_children>0)
    {
        for (ntype i=0; i<number_of_children; i++)
        {
            p->add_child(children[i]);
        }
    }
}

// ========================= RANDOM PREFIX TREE CREATE ==============
template<typename nodeType>
PrefixTreeNode<nodeType>* PrefixTreeNode<nodeType>::create_random_tree(ntype max_depth, ntype max_num_children)
{
    ntype the_depth = rand() % max_depth;
    //std::cout<<"the_depth = "<<the_depth<<std::endl;
    auto *rand_root = new PrefixTreeNode<nodeType>;
    rand_root->data = (nodeType)rand();
    rand_root->weight=0;
    rand_root->parent=nullptr;
    if (the_depth)
    {
        ntype num_of_ch = rand() % max_num_children;
        std::cout<<"num_children = "<<num_of_ch<<std::endl;
        if (num_of_ch)
        {
            for (ntype i=0; i<num_of_ch; i++)
            {
                rand_root->add_child(create_recursive_random_tree(the_depth-1, max_num_children));
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
PrefixTreeNode<nodeType>* PrefixTreeNode<nodeType>::create_recursive_random_tree(ntype depth, ntype max_num_of_children)
{
    auto *rand_node = new PrefixTreeNode<nodeType>;
    rand_node->data = (nodeType)rand();
    rand_node->weight = rand()/100;
    if (depth)
    {
        ntype num_of_ch = rand() % max_num_of_children;
        //std::cout<<"num_children = "<<num_of_ch<<std::endl;
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

// ======================= OUTPUT ===========================
template <typename NodeType>
std::ostream &operator<<(std::ostream &cout, PrefixTreeNode<NodeType> *node) {

    cout << "node " << node->data <<";  weight "<<node->weight<< "\n"<< "parent node: ";
    if (node->parent == nullptr){
        cout << "does not exist";
    } else  {
        cout << node->parent->data;
    }
    cout << "\n" << "children nodes: ";
    if (node->number_of_children == 0) {
        cout << "do not exist";
    }
    else {
        cout << '\n';
        for (ntype i = 0; i < node->number_of_children; ++i) {
            cout << node->children[i]->get_data() <<" (weight: "<<node->children[i]->get_weight()<< "), ";
        }
    }
    return cout;
}

template<typename nodeType>
void PrefixTreeNode<nodeType>::output()
{
    if (this->parent==nullptr) {output_str[0]='\0';}
    if (output_str[strlen(output_str)-1]=='|')
    {
        ntype l = strlen(output_str);
        if (output_str[l-2]=='|'){output_str[l-1]='\0';}
        std::cout<<this->output_str << "---("<<this->weight<<")---<" << this->data << '>' << std::endl;
    }
    else {std::cout<<this->output_str << "|---("<<this->weight<<")---<" << this->data << '>' << std::endl;}
    if (output_str[strlen(output_str)-1]==' '){strcat(output_str, "|");}
    if (number_of_children) {
        strcat(output_str, OUTPUT_STR);
        children[0]->output();
        strcat(output_str, "|");
        for (ntype i = 1; i < number_of_children; ++i) {
            children[i]->output();
        }
        ntype l = strlen(output_str);
        output_str[l - 13] = '\0';
    }
}

template<typename nodeType>
ntype PrefixTreeNode<nodeType>::get_number_of_all_children()
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
PrefixTreeNode<nodeType>** PrefixTreeNode<nodeType>::get_all_children_and_this()
{
    ntype number=get_number_of_all_children()+1;
    auto **the_list = new PrefixTreeNode<nodeType>* [number];
    auto **next_1 = new PrefixTreeNode<nodeType>* [number];
    auto **next_2 = new PrefixTreeNode<nodeType>* [number];
    ntype i, j, k, counter=1;
    for (i=0; i<number; i++)
    {
        the_list[i] = nullptr;
        next_1[i] = nullptr;
        next_2[i] = nullptr;
    }
    PrefixTreeNode<nodeType> *test_node=this->copy_subtree();
    the_list[0]=test_node;
    ntype next_1_cur_num = test_node->get_number_of_children(), next_2_cur_num=0;
    next_1 = test_node->get_children();
    while (counter<number)
    {
        ntype f=0;
        j=0;
        while (j<next_1_cur_num && counter<number)
        {
            the_list[counter]=next_1[j];
            counter++;
            for (k=0; k<next_1[j]->get_number_of_children(); k++)
            {
                next_2[f]=next_1[j]->get_children()[k];
                f++;
            }
            next_2_cur_num+=next_1[j]->get_number_of_children();
            j++;
        }
        f=0;
        next_1_cur_num=0;
        j=0;
        while (j<next_2_cur_num && counter<number)
        {
            the_list[counter] = next_2[j];
            counter++;
            for (k=0; k<next_2[j]->get_number_of_children(); k++)
            {
                next_1[f]=next_2[j]->get_children()[k];
                f++;
            }
            next_1_cur_num+=next_2[j]->get_number_of_children();
            j++;
        }
    }
    delete [] next_1;
    delete [] next_2;
    return the_list;
}

template<typename nodeType>
void PrefixTreeNode<nodeType>::show_adjacency_matrix()
{
    ntype num = get_number_of_all_children()+1;
    PrefixTreeNode<nodeType> **pointers = get_all_children_and_this();
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
                std::cout<<std::setw(WIDTH)<<std::setfill(' ')<<pointers[i]->get_weight();}
            else{
                std::cout<<std::setw(WIDTH)<<std::setfill(' ')<<'-';}
        }
        std::cout<<std::endl;
    }
}

template<typename nodeType>
void PrefixTreeNode<nodeType>::show_adjacency_matrix(const char *filename)
{
    try {
        std::fstream fstream(filename, std::ios::out | std::ios::app);
        if (!fstream) throw TreeError(1);
        fstream<<"Prefix Tree Adjucency matrix: "<<std::endl;
        ntype num = get_number_of_all_children()+1;
        PrefixTreeNode<nodeType> **pointers = get_all_children_and_this();
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
                    fstream<<std::setw(WIDTH)<<std::setfill(' ')<<pointers[i]->get_weight();}
                else{
                    fstream<<std::setw(WIDTH)<<std::setfill(' ')<<'-';}
            }
            fstream<<std::endl;
        }
        fstream.close();
    } catch (TreeError &treeError) {
//        treeError.Message();
        std::cout << "oops";
    }
}

template <typename nodeType>
void PrefixTreeNode<nodeType>::show_adjacency_list() {
    show_adjacency_list(true);
}

template <typename nodeType>
void PrefixTreeNode<nodeType>::show_adjacency_list(bool root) {
    // for this node
    if (root) {
        std::cout << data << ": (";
    } else {
        std::cout << data << ": ("
                  << parent->data << ", ";
    }
    for (ntype i = 0; i < number_of_children; ++i) {
        std::cout << children[i]->data << "<"<<children[i]->get_weight()<< ">, ";
    }
    std::cout << ")" << std::endl;

    // for children
    for (ntype i = 0; i < number_of_children; ++i) {
        children[i]->show_adjacency_list(false);
    }
}

template <typename nodeType>
void PrefixTreeNode<nodeType>::show_adjacency_list(const char *filename) {
    show_adjacency_list(true, filename);
}

template <typename nodeType>
void PrefixTreeNode<nodeType>::show_adjacency_list(bool root, const char *filename) {
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
        for (ntype i = 0; i < number_of_children; ++i) {
            fstream << children[i]->data <<"<"<<children[i]->get_weight()<< ">, ";
        }
        fstream << ")" << std::endl;
        fstream.close();

        // for children
        for (ntype i = 0; i < number_of_children; ++i) {
            children[i]->show_adjacency_list(false, filename);
        }
    } catch (TreeError &treeError) {
//        treeError.Message();
        std::cout << "oops";
    }

}

// ========================== SOME PRIVATE FUNCTIONS ====================
template<typename nodeType>
bool PrefixTreeNode<nodeType>::is_the_same(PrefixTreeNode<nodeType> *other)
{
    return (this==other);
}

template<typename nodeType>
bool PrefixTreeNode<nodeType>::is_in_tree(PrefixTreeNode<nodeType> *other)
{
    return (this->get_root()->is_the_same(other->get_root()));
}


#endif //TREE_MOSKANOVA_PREFIXTREE_H