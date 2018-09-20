#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void rec(int left, int right, char *arr)
{
    for (int i=0;i<left-1;i++)
    	printf("    ");
    printf("call rec\n");
    char temp;
    if (left==right)
    {
        printf("Result ");
        for (int i=0;i<right;i++)
            printf("%c ", arr[i]);                                                     //End of recursion
        printf("\n");
    }
    else
        for (int i=left-1;i < right;i++)
        {
            if (left-1 != i)
            {
                temp=arr[left-1];
                arr[left-1]=arr[i];
                arr[i]=temp;
            }
            rec(left+1,right,arr);
            if (left-1 != i)
            {
                temp=arr[left-1];
                arr[left-1]=arr[i];
                arr[i]=temp;
            }
        }
    return;
}

int main()
{
    int N;
    if (scanf("%d",&N) != 1)
    {
        printf("Incorrect data\n");                                                     //Data checking
        return 0;
    }    
    char arr[N];
    char simv;
    for (int i=0;i<N;i++)
    {
        scanf("%c",&simv);                                                              //Reading characters
        if (!isspace(simv))
        {
            arr[i] = simv;                                                              //Data checking
            for (int j=0;j<i;j++)
                if (arr[i]==arr[j])
                {
                    printf("Sorry,you have the same symbols, try another\n");
                    i--;
                }
        }
        else
            i--;
    }
    printf("\n");
    rec(1,N,arr);                                                                        //Recursion call
    return 0;
}