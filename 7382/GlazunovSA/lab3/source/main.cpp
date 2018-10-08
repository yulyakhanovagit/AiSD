#include <iostream>
#include <fstream>
#include "stack.cpp"
#define TEST
//#define SCRIPT
int main(){
	Mystack<char> stack(10);
	std::string text;
	#ifndef TEST
	#ifndef SCRIPT
	std::cout<<"this is stack.Enter...(for example: ados->stack->soda)"<<std::endl;
	#endif
	#endif
	getline(std::cin,text);


	#ifdef TEST
					#ifndef SCRIPT
					std::cout<<"this is stack.Enter...(for example: ados->stack->soda)"<<std::endl;
					#endif 
	std::cout<<"START PUSHING!!!"<<std::endl; 
	#endif
	for(int i=0;i<text.size();i++)
	{
		#ifdef TEST
					std::cout<<"PUSH"<<"   "<<text[i]<<"   ("<<i<<")"<<std::endl;
		#endif
		stack.push(text[i]);				//add elements in stack
	}
	#ifdef TEST
	std::cout<<"___________________________________________\n"<<"STOP PUSHING AND START POPING :)"<<std::endl;
	#endif
	for(int i=0;i<text.size();i++)
	{
				#ifdef TEST
					std::cout<<"POP"<<"   ";
					std::cout<<"TOP:"<<stack.top()<<"  ";
					std::cout<<"SIZE:"<<stack.size()<<std::endl;
					stack.top();
					std::ofstream file("result_lab3.txt",std::ios::app);
    				file << stack.pop();
    				file.close();
				#else 
							#ifndef SCRIPT	
								std::cout<<stack.pop();
							#else
								std::ofstream file("output_of_lab3.txt",std::ios::app);
    							file << stack.pop();
    							file.close();
							#endif
				#endif
	}

	std::cout<<std::endl;
return 0;
}
