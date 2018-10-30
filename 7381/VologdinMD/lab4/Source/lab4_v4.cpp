#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
//max depth is 5
#define N 63
typedef char type;

int Left (int x)
{
    return x*2+1;
}

int Right (int x)
{
    return x*2+2;
}

template <typename T>
bool isNull(T x)
{
    if (x == '0' || x == '^')
        return true;
    else
        return false;
}

template <typename T>
bool enterBT(T * array, int cur)
{
    char bkt;
    std::cin >> array[cur]; // root reading
    std::cin >> bkt;  // reading '('
    if (bkt != '(' && bkt != '^')
    {
        std::cout << "Error in the tree view in " << cur << std::endl;
        return false;
    }
    if (bkt =='(')
    {
        if (!enterBT(array,Left(cur))) // reading the left subtree
        {
            return false;
        }
        std::cin >> bkt; // reading ')'
        if (bkt != ')')
        {
            std::cout << "Error in the tree view in " << cur << std::endl;
            return false;
        }
    }
    if (bkt == '^')
        array[Left(cur)] = '^';
    std::cin >> bkt; // reading '('
    if (bkt != '(' && bkt != '^')
    {
        std::cout << "Error in the tree view in " << cur << std::endl;
        return false;
    }
    if (bkt =='(' )
    {
        if (!enterBT(array,Right(cur))) // reading the right subtree
        {
            return false;
        }
            
        std::cin >> bkt; // reading ')'
        if (bkt != ')')
        {
            std::cout << "Error in the tree view in " << cur << std::endl;
            return false;
        }
    }
    if (bkt == '^')
        array[Right(cur)] = '^';
    return true;
}

template <typename T>
bool sravn(T * arr, int d, T x, int cur_pos)
{
    if (!isNull(arr[d]))
    {
        if (x == arr[d] && d!=cur_pos) //comparison of the root in the tree
        {
            std::cout << "Duplicate is " << x << std::endl;
            return true;
        }
        if(sravn(arr,Left(d),x,cur_pos))  //comparing the root of the left subtree in the tree.
            return true;
        if (sravn(arr,Right(d),x,cur_pos)) //comparing the root of the right subtree in the tree.
            return true;   
    }
    return false;
}

template <typename T>
bool isduplicate(T * arr, int d)
{
    if (!isNull(arr[d]))
    {
        if (sravn(arr, 0,arr[d],d)) //comparison of all elements of the tree with the root
            return true;
        if(isduplicate(arr,Left(d))) //search in the left subtree
            return true;
        if(isduplicate(arr,Right(d))) //search in the left subtree
            return true;
    }
    return false;
}

int main()
{
    char bkt;
    std::cin >> bkt; // reading '('
    if (bkt != '(')
    {
        std::cout << "Error in the tree view in 1" << std::endl;
        return (0);
    }
    type mas[N];
    for (int i =0;i<N;i++)
        mas[i]='0';
    if(!enterBT(mas, 0)) // reading tree
    {
        return (0);
    }
    std::cin >> bkt; // reading ')'
    if (bkt != ')')
    {
        std::cout << "Error in the tree view in the end" << std::endl;
        return (0);
    }
    for (int i=0;i<N;i++)
        std::cout << i << ' ' << mas[i] <<std::endl;
    
    if (isduplicate(mas,0)) // search for repetitions
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    return (0);
}
