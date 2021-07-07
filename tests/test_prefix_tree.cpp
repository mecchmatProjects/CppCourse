#include"PrefixTree.h"
#include<iostream>
#define file_path "/C++ code/23_horrible_project/file.txt"

void create_projects_prefix_tree() {

}


int main()
{
    srand(time(nullptr));
    PrefixTreeNode<int> my_root, ch2(22, 4), ch3(90, 56), ch5(7,5);
    auto *child_1 = new PrefixTreeNode<int>(999, 77);
    my_root.add_child(child_1);
    my_root.add_child(&ch2);
    my_root.add_child(&ch3);
    child_1->add_child(&ch5);

    my_root.output();
    my_root.remove_child(child_1);
    my_root.output();
    std::cout<<&my_root;

    PrefixTreeNode<float> * root, *r1;
    root = r1->create_random_tree();
    root->output();
    root->show_adjacency_list(file_path);

    create_projects_prefix_tree();

    PrefixTreeNode <std::string> str_root("project", 89);
    PrefixTreeNode <std::string> str_child_11("project_C", 3);
    PrefixTreeNode <std::string> str_child_12("project_C++", 90);

    PrefixTreeNode <std::string> str_child_21("GeomND");
    PrefixTreeNode <std::string> str_child_22("Spline");
    PrefixTreeNode <std::string> str_child_23("BigNumber", 56.34);
    PrefixTreeNode <std::string> str_child_24("Interpolation");

    PrefixTreeNode <std::string> str_child_31("Tenzor", 34);
    PrefixTreeNode <std::string> str_child_32("Tree");
    PrefixTreeNode <std::string> str_child_33("Graph");
    PrefixTreeNode <std::string> str_child_34("Bank");

    PrefixTreeNode <std::string> str_child_41("Moskanova");
    PrefixTreeNode <std::string> str_child_42("Melekestseva");
    PrefixTreeNode <std::string> str_child_43("Horbunov", 343);
    PrefixTreeNode <std::string> str_child_44("Kovaltchuk", 4567);
    PrefixTreeNode <std::string> str_child_45("Stoychik");
    PrefixTreeNode <std::string> str_child_46("Prygodiuk");

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
    std::cout << "depth of the projects tree: " << str_root.get_depth() << std::endl;
    std::cout << std::endl;

    str_root.show_adjacency_matrix();

    auto *copy_projects = str_child_11.copy_subtree();
    std::cout<<"copy_projects: "<<std::endl;
    copy_projects->output();
    std::cout << "depth of the projects_C tree: " << copy_projects->get_depth() << std::endl;

    str_root.show_adjacency_matrix();
    str_root.show_adjacency_list();

    str_root.show_adjacency_matrix(file_path);
    str_root.show_adjacency_list(file_path);
}