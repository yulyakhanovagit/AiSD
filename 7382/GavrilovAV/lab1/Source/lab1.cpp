#include <iostream>
//#define TEST

bool check_str(std::string str){									//This function finds symbol '/' and returns true if it is in the line
        #ifdef TEST										//otherwise returns false
                std::cout << "Checking for the occurrence of a symbol:'/'." << std::endl;
        #endif
        if(str.find('/')==std::string::npos){
		#ifdef TEST
                        std::cout << "Checking failed!"<<std::endl;
                #endif
		return false;
	}
        else{
                #ifdef TEST
                        std::cout << "Checking passed!"<<std::endl;
		#endif
		return true;
	}
}

std::string fun(std::string str, unsigned int d){									//Recuration function wich divide the string if it contains '/'
#ifdef TEST												//then write the result of recuration call of itself to the variable - result
	std::cout << "Recurtion depth = " << d << std::endl << "Input data for function: \""<<str<< "\"\n";	//appending it with the substring which does't contains '/'
#endif													//and returns the result
	if(check_str(str)){										//if the input string does't contains '/' function returns this string
		size_t pos=str.find('/');
        	std::string substr=str.substr(0,pos);
#ifdef TEST
        	std::cout << "Substring without symbol '/': \""
                << substr<< "\" , Second substring: \""
                <<str.substr(pos+1)<< "\"\n"<< std::endl;
#endif
        	std::string result=fun(str.substr(pos+1, str.length()-1), d+1)+substr;
        	return result;
	}
	else{
		return str;
	}
}

int main(){											//Main function wich reads the line from the terminal,
        std::string str;										//runs the recuration function fun
        std::getline(std::cin, str);									//and writes the result in the terminal
        str=fun(str,0);
        std::cout << "Programm result: \""<< str<< "\"" << std::endl;
        return 0;
}

