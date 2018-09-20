#include <iostream>
//#define TEST
using namespace std;

bool check_str(string str){									//This function finds symbol '/' and returns true if it is in the line
        #ifdef TEST										//otherwise returns false
                cout << "Checking for the occurrence of a symbol:'/'." << endl;
        #endif
        if(str.find('/')==string::npos){
		#ifdef TEST
                        cout << "Checking failed!"<<endl;
                #endif
		return false;
	}
        else{
                #ifdef TEST
                        cout << "Checking passed!"<<endl;
		#endif
		return true;
	}
}

string fun(string str, unsigned int d){									//Recuration function wich divide the string if it contains '/'
#ifdef TEST												//then write the result of recuration call of itself to the variable - result
        cout << "Recurtion depth = " << d << endl << "Input data for function: \""<<str<< "\"\n";	//multiplying it with the substring which does't contains '/'
#endif													//and returns the result
	if(check_str(str)){										//if the input string does't contains '/' function returns this string
		size_t pos=str.find('/');
        	string substr=str.substr(0,pos);
#ifdef TEST
        	cout << "Substring without symbol '/': \""
                << substr<< "\" , Second substring: \""
                << str.substr(pos+1)<< "\"\n"<< endl;
#endif
        	string result=fun(str.substr(pos+1, str.length()-1), d+1)+substr;
        	return result;
	}
	else{
		return str;
	}
}

int main(){											//Main function wich reads the line from the terminal,
        string str;										//runs the recuration function fun
        getline(cin, str);									//and writes the result in the terminal
        str=fun(str,0);
        cout << "Programm result: \""<< str<< "\"" << endl;
        return 0;
}

