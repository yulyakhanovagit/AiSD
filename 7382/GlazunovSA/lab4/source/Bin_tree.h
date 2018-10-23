#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
template<typename T>
class Bin_tree
{
public:
	Bin_tree();
	Bin_tree(string text);
	~Bin_tree();
	void set_str_bin_tree();
	void get_str_bin_tree();
	void create_bin_tree(Node<T>*cur,int level);
	void add_value(Node<T>*root,T _value);
	void print(Node<T>*root,int pad);
	Node<T>*root;
	Node<T>*end_of_right(Node<T>*cur);
	Node<T>*end_of_right_v2(Node<T>*cur);
private:
	string str_bin_tree;
	int index_of_str;
	void create_left(Node<T>*cur);
	void create_right(Node<T>*cur);
};
