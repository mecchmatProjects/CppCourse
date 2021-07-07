#ifndef TREE_MOSKANOVA_TREEERROR_H
#define TREE_MOSKANOVA_TREEERROR_H


class TreeError {
    int code;
public:
    explicit TreeError(int err_code) : code(err_code){};
    void Message();
    void Message(char *log_file);
};

class BinaryTreeError: public TreeError{};
class PrefixTreeError: public TreeError{};


#endif //TREE_MOSKANOVA_TREEERROR_H