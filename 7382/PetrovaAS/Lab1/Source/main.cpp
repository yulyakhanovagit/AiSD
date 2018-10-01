#include <iostream>

/*Вариант 1*/ 

typedef unsigned long long ull;

ull getValue();
ull rec(ull n, ull m, int k);

int main()
{
	/*reading data from the input stream*/
    std:: cout << "Enter the number for which you want to calculate the binomial coefficient: ";
    ull n = getValue();
    std:: cout << n << "\n";

    std:: cout << "Enter the number of the coefficient: " ;
    ull m = getValue();
    std:: cout << m << "\n";

    std:: cout << "Intermediate value\n";
    ull r=rec(n,m,0);
    std:: cout << "Answer: [" << r << "]\n";

    return 0;
}

ull getValue() {

    /*checking the entered data for correctness*/
    ull value;
    std:: cin >> value;
    if(!std::cin.good()) { 
		/* If cin have an exception like ERANGE value or symbols in cin it returns false*/
        std::cerr << "Error with input. Aborting!";
        exit(1);
    }
    return value;
}

ull rec(ull n, ull m, int k){

	if (m>n/2)
        m=n-m;
	/*checking for 0 or 1*/
    if (m==n)
        return 1;
    if (m==0)
        return 1;
    if (m>n)
        return 0;
	/*algorithm for calculating binomial coefficients*/
    ull r;
	r=rec(n-1,m,k+1)+rec(n-1,m-1,k+1);
    /*intermediate values output*/
    for(int i=0;i<k;i++){
        std:: cout << " "; 
    }
    std:: cout << "intermediate value for C("<< n << "," << m << ") = "<< r << "\n";
    for(int i=k;i>0;i--){
        std:: cout << " "; 
    }
    return r;
}
