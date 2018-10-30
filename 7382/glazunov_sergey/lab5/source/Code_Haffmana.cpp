#include "Code_Haffmana.h"


Code_Haffmana::Code_Haffmana()
{
}


Code_Haffmana::~Code_Haffmana()
{
}

void Code_Haffmana::get_input()
{
	cout << input << endl;
}

void Code_Haffmana::set_input()
{
	getline(cin,input);
	len_of_input = input.length();
	if(!len_of_input)
		{
		cout<<"string cant be empty\n";
		exit(0);
		}
}

void Code_Haffmana::create_code_haffmana()
{
}

void Code_Haffmana::count_symbol_frequency()
{
	for (int i = 0;i < len_of_input;i++)
	{
		symbol_frequency[input[i]]++;
	}
}

void Code_Haffmana::create_list()
{
	for (iter=symbol_frequency.begin();iter!=symbol_frequency.end();iter++) 
	{ 
		Node*cur = new Node(iter->first,iter->second);
		myList.push_back(cur);
	}
}

void Code_Haffmana::create_tree_of_haffmana()
{
	while (myList.size()!=1) 
	{
		myList.sort(My_Comparator_for_list());
		Node*left = myList.front();
		myList.pop_front();
		Node*right = myList.front();
		myList.pop_front();
		Node*new_node = new Node(left,right);
		myList.push_front(new_node);
	}
	root_of_tree_haffmana = myList.front();
}

void Code_Haffmana::print(Node * root, int pad)
{
	if (root != nullptr) 
	{
		print(root->left, pad + 3);
		for (int i = 0;i < pad;i++)
		{
			cout << "   ";
		}
		if (root->symbol) cout <<root->number<<" ("<< root->symbol<<")"<< endl;
		else cout << root->number << endl;
		print(root->right,pad+3);
	}
}

void Code_Haffmana::create_code_of_each_symbol(Node*root)
{
	if (root->left!=NULL) 
	{
		code.push_back(0);
		create_code_of_each_symbol(root->left);
	}
	if (root->right!=NULL)
	{
		code.push_back(1);
		create_code_of_each_symbol(root->right);
	}
	if (root->left == NULL && root->right == NULL)
	{
		table[root->symbol] = code;
	}
	if(!code.empty())
	code.pop_back();
}

void Code_Haffmana::print_code_haffmana()
{
	for (int i = 0;i < len_of_input;i++)
	{
		vector<bool>bin_number = table[input[i]];
		for (int j = 0;j < bin_number.size();j++)
		{
			cout << bin_number[j];
		}
	}
}

Node* Code_Haffmana::get_root()
{
	return root_of_tree_haffmana;
}

