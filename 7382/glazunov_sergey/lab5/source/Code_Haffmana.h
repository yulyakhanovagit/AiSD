#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <fstream>
//#define __INFILE__
using namespace std;
class Code_Haffmana
{
public:
	Code_Haffmana();
	~Code_Haffmana();
	void get_input(); 
	void set_input(); 
	void create_code_haffmana();
	void count_symbol_frequency();
	void create_list();
	void create_tree_of_haffmana();
	void print(Node*root, int pad);
	void create_code_of_each_symbol(Node*root);
	void print_code_haffmana();
	Node* get_root();
private:
	string input;
	list<Node*>myList;
	map<char, int>symbol_frequency;
	map<char, int>::iterator iter;
	int len_of_input;
	Node*root_of_tree_haffmana;
	vector<bool>code;
	map<char, vector<bool> >table;
};


