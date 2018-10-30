#pragma once
class Node
{
public:
	Node();
	Node(char _symbol,int _number) { number = _number;symbol = _symbol; }
	Node(Node*_left, Node*_right) { number = _left->number + _right->number;left = _left;right = _right; }
	~Node(){delete left;delete right;}
	int number;
	char symbol;
	Node*left, *right;
};
struct My_Comparator_for_list
{
	bool operator ()(Node*fst,Node*snd)
	{
		return fst->number < snd->number;
	}
};

