#include <vector>

template <typename Type>
class Stack{
public:
    void push(Type data);
    Type pop();
    void print_stack();
    bool is_empty();
private:
    std::vector<Type> mas;
};

template <typename Type>
bool Stack<Type>::is_empty(){
    if(mas.size() == 0)
      return true;
    return false;
}

template <typename Type>
void Stack<Type>::push(Type data){
    mas.push_back(data);
}

template <typename Type>
Type Stack<Type>::pop(){
    Type data = mas[mas.size()-1];
    mas.pop_back();
    return data;
}

template <typename Type>
void Stack<Type>::print_stack(){
    for(int i = mas.size()-1; i >= 0; i--)
        std::cout << mas[i] << std::endl;
    std::cout << std::endl;
}
