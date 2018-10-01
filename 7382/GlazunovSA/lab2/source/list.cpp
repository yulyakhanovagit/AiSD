#include <iostream>
struct left_bracket{					//it's left son
	bool is_atom;
	struct el_of_list*element;
};
struct right_bracket{					//it's right son
	struct el_of_list*element;
};
struct el_of_list{							//no brothers
struct left_bracket*left;
struct right_bracket*right;
};
class Mylist
{
private:
	struct el_of_list*el;
	struct el_of_list* list;
	struct el_of_list*el1;
	int size_;
public:
	Mylist()
	{
		list = new struct el_of_list;			//if's first element of list
		list->left=NULL;						//
		list->right=NULL;
		el = list;
		el1=list;
		size_=0;
	}
	~Mylist()
	{
			delete_list(el1);//delete all elements of list
	}
	int size()
	{
		return size_;
	}
	void push(char symbol,bool next_symbol)
	{
		if(symbol=='(')								//if next_symbol==true it's mean pad_of_brackets++
		{
			el->left=new struct left_bracket;
			el->right=NULL;
			el->left->element=new struct el_of_list;
			el->left->is_atom=next_symbol;
			el=el->left->element;
			el->left=NULL;
			el->right=NULL;
		}
		if(symbol==')')
		{
			el->right=new struct right_bracket;
			el->left=NULL;
			el->right->element=new struct el_of_list;
			el=el->right->element;
			el->left=NULL;
			el->right=NULL;
		}
	}
	int count()													//this function return pad_of_brackets using the  'is_atom' from struct left_bracket
	{
		if(list->left==NULL&&list->right==NULL)
			return 0;

			if(list->left!=NULL)
			{
				if(list->left->is_atom)
					{
						list=list->left->element;
						return count()+1;
					}
				else
					{
						list=list->left->element;
						return count();
					}
			}

			if(list->right!=NULL)
			{
				list=list->right->element;
				return count();
			}

	}

	void delete_list(struct el_of_list*cur_el)
	{
		if(cur_el->left==NULL&&cur_el->right==NULL)
			{	
				if(cur_el)
					delete cur_el;
			}
		if(cur_el->left!=NULL)
			{
				delete_list(cur_el->left->element);
				if(cur_el->left)
					delete cur_el->left;
			}
		if(cur_el->right!=NULL)
			{
				delete_list(cur_el->right->element);
				if(cur_el->right)
					delete cur_el->right;
			}
	}
};