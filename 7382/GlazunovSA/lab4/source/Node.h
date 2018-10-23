#pragma once
template<typename V>
class Node
{
public:
	Node() {}
	Node(V _value, Node*_left, Node*_right) { value = _value;left = _left;right = _right; }
	~Node(){
		delete left;
		delete right;
	}
	V value;
	Node*left, *right;
};
