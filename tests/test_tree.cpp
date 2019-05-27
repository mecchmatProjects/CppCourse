//
// Created by olga on 26.03.19.
//

#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
    TreeNode<int> root;
    root.set_data(17);

    cout << root.get_data();

//    auto *root = new TreeNode<int>(17);

//    auto *first_child = new TreeNode<int>(11);

//    root.add_child(&first_child);

//    delete first_child;

    return 0;
}