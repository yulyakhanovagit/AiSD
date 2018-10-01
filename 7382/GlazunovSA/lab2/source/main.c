#include <iostream>
#include <string>
#include <cstdio>
#include "list.cpp"//class,where there is list :)
//#define SCRIPT_TEST
#define TEST_ALG
bool check_next_symbol(std::string &text,int shift)				//true- ( A )
{																//false- ( )
	for(int i=shift;i<text.size()&&((text[i])!=')');i++)			
		{
			if((text[i])!=' ')
			return true;
		}
	return false;
}

std::string input(){
	std::string text;
	getline(std::cin,text);	
	return text;
}

bool istextcorrect(std::string text)
{
	int sum=0;
	for(int i=0;i<text.size();i++)
	{
		if(sum<0)									//if situation: ))(( - total sum=0,but
			return false;							// it's wrong ,that why sum is checked 
		if(text[i]=='(')							//in cycle
			sum++;
		if(text[i]==')')
			sum--;
	}
	if(sum==0)
	return true;

return false;
}

int main(){
Mylist stk;
bool first_correct_bracket=false;							
#ifndef SCRIPT_TEST
std::cout<<"Hello,I am checker of brackets.Enter..."<<std::endl;
#endif
std::string text=input();				//read text
int pad=0;
if(first_correct_bracket=istextcorrect(text))
for(int i=0;i<text.size();i++)
{
	#ifdef TEST_ALG
	for(int j = 0;j<pad*3;j++)
	{std::cout<<" ";}
	std::cout
	<<"depth of brackets:"<<pad<<std::endl;
	for(int j = 0;j<pad*3;j++)
	{std::cout<<" ";}

		std::cout<<"symbol= "<<text[i]<<std::endl<<"___________________________________"<<std::endl;
	
	#endif
	if(text[i]=='(')
	{
		stk.push('(',check_next_symbol(text,i+1) );

				#ifdef TEST_ALG
					if(check_next_symbol(text,i+1))
						{
							pad++;
						}
				#endif
	}
	if(text[i]==')')
	{
		stk.push(')',false);

	}
}

	if(first_correct_bracket) 						 
		{												
			#ifdef SCRIPT_TEST						
 			FILE *f;									
    		f = fopen("output_of_lab2.txt","wt");		
    		fprintf(f, "%d",stk.count());						
    		fclose(f);
 			return 0;
 			#else
 			std::cout<<"RESULT="<<stk.count()<<std::endl;
 			return 0;
 			#endif
		}

	#ifdef SCRIPT_TEST
 			FILE *f;
    		f = fopen("output_of_lab2.txt","wt");
    		fprintf(f, "error");
    		fclose(f);
 			return 0;
 			#else
 			std::cout<<"error"<<std::endl;
 			#endif

	return 0;
}