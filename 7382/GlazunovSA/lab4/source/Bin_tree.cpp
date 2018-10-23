#include "Bin_tree.h"

template<typename T>
Bin_tree<T>::Bin_tree()
{
	index_of_str = 1;
	root = nullptr;
}

template<typename T>
Bin_tree<T>::Bin_tree(string text)
{
	index_of_str = 1;
	str_bin_tree = text;
	root = nullptr;
	create_bin_tree(root, 0);
}

template<typename T>
Bin_tree<T>::~Bin_tree()
{
}

template<typename T>
void Bin_tree<T>::set_str_bin_tree()
{
	getline(cin,str_bin_tree);
}

template<typename T>
void Bin_tree<T>::get_str_bin_tree()
{
	cout << "bin_tree :" << str_bin_tree << endl;
}

template<typename T>
Node<T>* Bin_tree<T>::end_of_right(Node<T> * cur)
{
	Node<T> * vur = cur;
	while (vur->right != nullptr)
		vur = vur->right;
	return vur;
}
template<typename T>
Node<T>* Bin_tree<T>::end_of_right_v2(Node<T>* cur)
{
	Node<T> * vur = cur;
	if(vur->right != nullptr)
	while (vur->right->right != nullptr)
		vur = vur->right;
	return vur;
}
template<typename T>
void Bin_tree<T>::create_bin_tree(Node<T>*cur, int level)
{
	if ((unsigned)index_of_str >= str_bin_tree.length())return;
	if (cur == nullptr)
	{
		cur = new Node<T>();
		cur->left = nullptr;
		cur->right = nullptr;
		root = cur;
	}
	while ((unsigned)index_of_str < str_bin_tree.length())
	{
		if (str_bin_tree[index_of_str] == '(')
		{
			index_of_str++;

			Node<T>*vur = end_of_right_v2(cur);
			create_left(vur);
			create_bin_tree(vur->left, level);
			continue;
		}
		if (str_bin_tree[index_of_str] != ')') {
			Node<T>*vur = end_of_right(cur);
			add_value(vur, str_bin_tree[index_of_str]);
			create_right(vur);
			index_of_str++;
		}
		else
		{
			index_of_str++;
			return;
		}
	}
}


template<typename T>
void Bin_tree<T>::add_value(Node<T>*root,T _value)
{
	root->value = _value;
	root->left = nullptr;
	root->right = nullptr;
}

template<typename T>
void Bin_tree<T>::print(Node<T>* root,int pad)
{
	if (root != nullptr)
		if(root->value)
	{
		print(root->left, pad + 3);
		for (int i = 0;i < pad;i++)
		{
			cout << "   ";
		}
		if (root->value) cout<< root->value<<"("<<pad/3<<")"<< endl;
		print(root->right, pad + 3);
	}
}

template<typename T>
void Bin_tree<T>::create_left(Node<T> * cur)
{
	cur->left = new Node<T>();
}

template<typename T>
void Bin_tree<T>::create_right(Node<T>* cur)
{
	cur->right = new Node<T>();
}
