#include<iostream>
#include<fstream>
#include<climits>//for INT_MAX and INT_MIN
#include<cstdlib>//for exit
#include<cmath>//for POW
int strtoint(std::string text,int size);
//#define TEST          //for illustation of recursion
//#define SCRIPT_TEST   //for runtest.sh
bool is_number(std::string text)
{
	int max_value[10]={2,1,4,7,4,8,3,6,4,7};
	if((text[0]!='-'&&text.size()<10)||(text[0]=='-'&&text.size()<11))
		return true;

	int i=0;
	int j=0;
	if(text[0]=='-')
		i=1;
	int highpoint=10+i;
	for(;i<highpoint;i++)
	{
		if(text[i]>max_value[j++])
			return false;
	}

	return true;
}
void find_size_of_int(std::string text,int &i,int &size)
{

    if(text[i] == '-') {
        size++;
        i++;
    }
    while(isdigit(text[i]))
    {
        i++;
        size++;
    }
}
int multiply(std::string text,int &shift,int pad,int bonus_pad)
{
    int i=shift;
    int size=0;
    int total;
    std::string cur;

#ifdef TEST                                             //this part for illustration of recursion
    for(int k=0; k<pad; k++)                            //
        std::cout<<"\t";                                //
    		for(int k=0; k<bonus_pad; k++)                      //
        		std::cout<<" ";                                  //
    			std::cout<<pad<<"."<<bonus_pad<<".multiply"<<std::endl;        //
#endif

    find_size_of_int(text,i,size);//it's a search of number in string
    cur=text.substr(shift,size);//take a part of string for transmutation in int
    shift=i;
    total=strtoint(cur,size);

    if(text[shift]=='*')
    {
        shift++;
        return total*multiply(text,shift,pad,++bonus_pad);
    }

    return total;
}

int recmath(std::string text,int shift,int pad) {//the first recursion
    if(text.size()==shift)//exit of recursion
        return 0;//

    int size=0,total,i=shift;//total-is answer;
    std::string cur;
    
    find_size_of_int(text,i,size);
    cur=text.substr(shift,size);//take a part of string for transmutation in int
    shift=i;
    total=strtoint(cur,size);

#ifdef TEST
    for(int k=0; k<pad; k++)
        std::cout<<"\t";
    std::cout<<pad<<".recmath"<<std::endl;
#endif
    if(text[shift]=='+'){
        int curcheck=recmath(text,shift+1,++pad);
       
        if(total>INT_MAX-abs(curcheck))
{
#ifdef SCRIPT_TEST
    FILE *f;
    f = fopen("output_of_lab1.txt","wt");
    fprintf(f, "error" );
    fclose(f);
#else
    std::cout<<"error"<<std::endl;
        exit(0);
#endif
}    

    return total+curcheck;
}

    if(text[shift]=='*')//the second recursion(multiply)
    {
         shift++;
         int curcheck=multiply(text,shift,pad,0);
         if(curcheck!=0)
         if(abs(total)>INT_MAX/abs(curcheck))
		
		{
			#ifdef SCRIPT_TEST
    		FILE *f;
    		f = fopen("output_of_lab1.txt","wt");
    		fprintf(f, "error" );
    		fclose(f);
    		exit(0);
			#else
    		std::cout<<"error"<<std::endl;
        	exit(0);
			#endif
		}

        total*=curcheck;
        return total+recmath(text,shift,++pad);//
    }

    return total;
}

int strtoint(std::string text,int size) {       //this function is like atoi in C
    int total=0;
    int i=0;
    int check=1;
    if(text[0]=='-') {
        i=1;
        check=-1;
    }

    for(; i<size; i++)
    {
        total+=((int)(text[i])-'0')*pow(10,size-i-1);
    }

    if(!is_number(text))//compare size of number with normal situation
		{
		#ifdef SCRIPT_TEST
  		  FILE *f;
    		f = fopen("output_of_lab1.txt","wt");
    		fprintf(f, "error" );
    		fclose(f);
    		exit(0);
		#else
    		std::cout<<"error"<<std::endl;
        	exit(0);
		#endif
		}

    return check*total;
}

bool textcorrect(std::string text){                     //this function checks stdin
    int check=0;
    if(text[text.size()-1]<'0'||text[text.size()-1]>'9')// if stdin is wrong for calculator 
        return false;//check last symbol                //func. send false

    for(int i=0;i<text.size();i++)
    {
        if(isalpha(text[i])||text[i]=='.'||text[i]==',')//check symbol in string
            return false;
    }

    if(text[0]<'0'||text[0]>'9')//check the first symbol
            if(text[0]!='-')
                return false;

    for(int i=0;i<text.size();i++)// if there is a situation like "5+*3" -it's false
    {
        if(check==2)
            return false;
        if(text[i]=='+'||text[i]=='*')
        {    
            check++;
            continue;
        }
        check=0;

    }

    for(int i=0;i<text.size();i++)
    	{
    		if(i!=0)
    			if(text[i]=='-'&&text[i-1]!='+'&&text[i-1]!='*')
    				return false;
    	}
return true;    
}

int main()
{
    std::string text;
    int fin;
#ifndef SCRIPT_TEST
    std::cout<<"Hello,I am calculator.Enter..."<<std::endl;
#endif
    getline(std::cin,text);
    for(int i=0;i<text.size();i++)
   		if(text[i]==' ') 
    	{                                       // "This is an example sentence."
    	text.erase (i,1);
    	i--;
    	}   
    

for(int i=0; i<text.size(); i++)
        if(text[i]=='-')
        {
            if(text[i+1]=='-')
            {
                text.erase (i,1);
                text[i]='+';
                i--;

            }
        }
        
        for(int i=0;i<text.size();i++)
    {
        if(i&&text[i]=='-')
            if(text[i-1]=='+'||text[i-1]=='*')
            {
                continue;
            }
            else if(isdigit(text[i-1]))
            {
                text.insert(i,"+");
            }
    }
    
        bool iscorrect=textcorrect(text);
    if(iscorrect)
    fin=recmath(text,0,0);
#ifdef SCRIPT_TEST
    FILE *f;
    f = fopen("output_of_lab1.txt","wt");
    if(iscorrect){
    fprintf(f, "%d",fin);
    }
    else
    {
        fprintf(f, "error" );
    }
    fclose(f);
#else
    if(!iscorrect){
        std::cout<<"error"<<std::endl;
        return 0;
    }
    std::cout<<"result="<<fin<<std::endl;
#endif
    return 0;
}
