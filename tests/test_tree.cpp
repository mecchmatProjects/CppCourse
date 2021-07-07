#include <iostream>
#include "Tree.h"
#include<cstring>
#define file_path "/C++ code/23_horrible_project/file.txt"

using namespace std;
void create_projects_tree()
{
    TreeNode<std::string> str_root("project");
    TreeNode<std::string> str_child_11("project_C");
    TreeNode<std::string> str_child_12("project_C++");

    TreeNode<std::string> str_child_21("GeomND");
    TreeNode<std::string> str_child_22("Spline");
    TreeNode<std::string> str_child_23("BigNumber");
    TreeNode<std::string> str_child_24("Interpolation");

    TreeNode<std::string> str_child_31("Tenzor");
    TreeNode<std::string> str_child_32("Tree");
    TreeNode<std::string> str_child_33("Graph");
    TreeNode<std::string> str_child_34("Bank");

    TreeNode<std::string> str_child_41("Moskanova");
    TreeNode<std::string> str_child_42("Melekestseva");
    TreeNode<std::string> str_child_43("Horbunov");
    TreeNode<std::string> str_child_44("Kovaltchuk");
    TreeNode<std::string> str_child_45("Stoychik");
    TreeNode<std::string> str_child_46("Prygodiuk");

    str_child_21.add_child(&str_child_45);
    str_child_21.add_child(&str_child_42);
    str_child_22.add_child(&str_child_43);
    str_child_22.add_child(&str_child_44);
    str_child_24.add_child(&str_child_41);
    str_child_31.add_child(&str_child_46);

    str_root.add_child(&str_child_11);
    str_root.add_child(&str_child_12);
    str_child_11.add_child(&str_child_21);
    str_child_11.add_child(&str_child_22);
    str_child_11.add_child(&str_child_23);
    str_child_11.add_child(&str_child_24);
    str_child_12.add_child(&str_child_31);
    str_child_12.add_child(&str_child_32);
    str_child_12.add_child(&str_child_33);
    str_child_12.add_child(&str_child_34);
    str_root.output();
    std::cout<<"depth of the projects tree: "<<str_root.get_depth()<<std::endl;
    std::cout<<std::endl;

    str_root.show_adjacency_matrix();
    str_root.show_adjacency_matrix("/C++ code/23_horrible_project/file.txt");

    auto *copy_projects = str_child_11.copy_subtree();
    copy_projects->output();
    std::cout<<"depth of the projects_C tree: "<<copy_projects->get_depth()<<std::endl;


}

int main()
{
    srand(time(0));
    auto *root = new TreeNode<float>(9.99);
    TreeNode<float> ch(1);
    root->add_child(&ch);
    TreeNode<float> ch_1(22);
    std::cout<<"======";
    std::cout<<root;
    //std::cout<<ch_1;
    ch.add_child(&ch_1);
    TreeNode<float> ch_3(44);
    TreeNode<float> ch_5(55);
    ch.add_child(&ch_3);
    ch.add_child(&ch_5);

    TreeNode<float>* new_tree = new TreeNode<float>;
    new_tree->add_child(root);
    TreeNode<float> left_1(8);
    new_tree->add_child(&left_1);
    TreeNode<float> middle(33);
    new_tree->add_child(&middle);
    middle.add_child(new_tree);
    new_tree->output();

    std::cout<<"\n\n";
    create_projects_tree();
    auto *test_node = new TreeNode<float>(4567);
    test_node = root->copy();

    new_tree->output();
    std::cout<<std::endl;
    test_node = root->copy_subtree();
    test_node->output();
    std:cout<<"depth of root"<<root->get_depth()<<std::endl;
    middle.add_child(new_tree);
    create_projects_tree();
    new_tree->output();
    std::cout<<"\n====================================================================\n";
    new_tree->show_adjacency_matrix();
    new_tree->output();
    new_tree->show_adjacency_list();

    TreeNode<float> *f, *g;
    f = g->create_random_tree(7, 5);
    f->output();
    std::cout<<"\n\n=============================================================\n";

    f->show_adjacency_list(file_path);
    f->show_adjacency_matrix(file_path);
}