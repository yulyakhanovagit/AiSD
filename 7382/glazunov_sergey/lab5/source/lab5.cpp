#include <iostream>
#include "Code_Haffmana.h"

int main()
{
	Code_Haffmana code;
	cout<<"enter:"<<endl;
	code.set_input();
	code.count_symbol_frequency();
	code.create_list();
	code.create_tree_of_haffmana();
	code.print(code.get_root(), 0);
	code.create_code_of_each_symbol(code.get_root());
	cout<<"Code haffmana:";
	code.print_code_haffmana();
	cout<<"\n";
	return 0;
}

