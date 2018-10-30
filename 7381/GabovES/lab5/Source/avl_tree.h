#ifndef AVL_TREE_H // for include only one time
#define AVL_TREE_H

void make_deep(int, int);
void make_hight(int);

template <class Type>
class Head_AVL_Tree;

template <class Type>
class Node_AVL_Tree{
public:
    friend class Head_AVL_Tree<Type>;
    bool is_contain(Type);
    int set_height();
    int get_balance();
    void print_tree();
    void print_tree(int);
    class Node_AVL_Tree<Type>* insert(Type);
    class Node_AVL_Tree<Type>* left_rotate();
    class Node_AVL_Tree<Type>* right_rotate();
    class Node_AVL_Tree<Type>* make_balance();
    Node_AVL_Tree();
    ~Node_AVL_Tree();
private:
    int height;
    int balance;
    Type data;
    class Node_AVL_Tree<Type>* left;
    class Node_AVL_Tree<Type>* right;
};

template <class Type>
class Head_AVL_Tree{
public:
    friend class Node_AVL_Tree<Type>;
    Head_AVL_Tree();
    ~Head_AVL_Tree();
    void insert(Type);
    void print_tree();
    bool is_contain(Type);
private:
    class Node_AVL_Tree<Type>* head;
};

template <class Type>
Node_AVL_Tree<Type>::Node_AVL_Tree(){
    left = nullptr;
    right = nullptr;
}

template <class Type>
Node_AVL_Tree<Type>::~Node_AVL_Tree(){
    if(left)
        delete left;
    if(right)
        delete right;
}


template <class Type>
bool Node_AVL_Tree<Type>::is_contain(Type desired){
    if(data == desired)
        return true;
    if(left && right && (left->is_contain(desired) || right->is_contain(desired)))
        return true;
    if(left && left->is_contain(desired))
        return true;
    if(right && right->is_contain(desired))
        return true;
    return false;
}

template <class Type>
int Node_AVL_Tree<Type>::set_height(){
    if(!left && !right) // if sheet
         return 1;
    if(!left)
        return (right->height + 1);
    if(!right)
        return (left->height + 1);
    if(left->height >= right->height)
        return (1 + left->height);
    if(left->height < right->height)
        return (1 + right->height);
}

template <class Type>
int Node_AVL_Tree<Type>::get_balance(){
    if(!left && !right) // if sheet
         return 0;
    if(!left)
        return right->height;
    if(!right)
        return (left->height * (-1));
    return (right->height - left->height);
}

template <class Type>
void Node_AVL_Tree<Type>::print_tree(){
    std::cout << data << " ";
    std::cout << height << " ";
    std::cout << balance << std::endl;
    if(left)
        left->print_tree();
    if(right)
        right->print_tree();
}

template <class Type>
void Node_AVL_Tree<Type>::print_tree(int deep){ // beautiful print tree
    make_hight(deep);
    std::cout << data << std::endl;
    if(right){
        right->print_tree(deep+1);
    }
    if(left){
        left->print_tree(deep+1);
    }
}

template <class Type>
class Node_AVL_Tree<Type>* Node_AVL_Tree<Type>::insert(Type value){
    if(value >= data){
        if(!right){
            right = new Node_AVL_Tree<Type>;
            right->data = value;
            right->height = 1;
        }
        else
            right = right->insert(value);
    }
    if(value < data){
        if(!left){
            left = new Node_AVL_Tree<Type>;
            left->data = value;
            left->height = 1;
        }
        else
            left = left->insert(value);
        }
    height = set_height();
    balance = get_balance();
    return make_balance();
}

template <class Type>
class Node_AVL_Tree<Type>* Node_AVL_Tree<Type>::right_rotate(){
    std::cout << "right rotate around element: " << this->data << std::endl;
    Node_AVL_Tree<Type>* temp;
    temp = left;
    left = temp->right;
    temp->right = this;
    this->height = set_height();  //set height because it have changed
    temp->height = set_height();
    return temp;
}

template <class Type>
class Node_AVL_Tree<Type>* Node_AVL_Tree<Type>::left_rotate(){
    std::cout << "left rotate around element: " << this->data << std::endl;
    Node_AVL_Tree<Type>* temp;
    temp = right;
    right = temp->left;
    temp->left = this;
    this->height = set_height();
    temp->height = set_height();
    return temp;
}

template <class Type>
class Node_AVL_Tree<Type>* Node_AVL_Tree<Type>::make_balance(){
    Node_AVL_Tree<Type>* temp;
    temp = this;
    if(balance == 2){
        if(right->balance == -1)
            temp->right = right->right_rotate();
        temp = left_rotate();
    }
    if(balance == -2){
        if(left->balance == 1)
            temp->left = left->left_rotate();
        temp = right_rotate();
    }
    return temp;
}

template <class Type>
Head_AVL_Tree<Type>::Head_AVL_Tree(){
    head = nullptr;
}

template <class Type>
Head_AVL_Tree<Type>::~Head_AVL_Tree(){
    delete head;
}

template <class Type>
void Head_AVL_Tree<Type>::print_tree(){
    if(!head){
        std::cout << "tree is empty" << std::endl;
        return;
    }
    head->print_tree(0);
}

template <class Type>
void Head_AVL_Tree<Type>::insert(Type value){
    if(!head){
        Node_AVL_Tree<Type>* temp = new Node_AVL_Tree<Type>;
        temp->data = value;
        temp->height = 1;
        head = temp;
        return;
    }
    head = head->insert(value);
}

template <class Type>
bool Head_AVL_Tree<Type>::is_contain(Type desired){
    if(head->data == desired)
        return true;
    if(head->left && head->right && (head->left->is_contain(desired) || head->right->is_contain(desired)))
        return true;
    if(head->left && head->left->is_contain(desired))
        return true;
    if(head->right && head->right->is_contain(desired))
        return true;
    return false;
}

void make_deep(int deep, int flag){
  if(flag)
    for(int i = 0 ; i < deep ; i++)
      std::cout << "        ";
  else{
    for(int i = 0 ; i < deep-1 ; i++)
      std::cout << "        ";
    if(deep > 0)
      std::cout << "--------";
  }
}

void make_hight(int deep){
  make_deep(deep , 0);
  std::cout << '|' << std::endl;
  make_deep(deep , 1);
  std::cout << '|' << std::endl;
  make_deep(deep , 1);
}

#endif
