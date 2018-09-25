#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SHOW_RECURSION

// Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* This function takes three parameters:
    1. String
    2. Starting index of the substring
    3. Ending index of the substring.
    4. Counting var for array results
    5. Array where permutations will be in  */
void permute(char *str, int left, int right, int *num, char **result)
{

#ifdef SHOW_RECURSION // block for demonstrating recursion's work
    if(left == 0)
    {
        printf("Work of recursion:\n");
    }
    char space[] = "   ";  // string helps to write all function call correctly
    for(int i = 0; i<left; i++)
    {
        printf("%s", space);
    }
    printf("permute: level %d\n", left+1); // depth of recursion = left+1
#endif

    if(right == -1)  // if there is empty string
    {
        return;
    }
    if (left == right)  // base condition of recursion 
    {
        strcpy(result[*num], str);
        (*num)++;
	printf("%d: %s\n", *num, str);
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
	    printf("[%s] --> swap '%c' with '%c' --> ", str, str[left], str[i]);
            swap((str+left), (str+i)); //symbol with index i is fixed
	    printf("[%s]\n", str);
            permute(str, left+1, right, num, result); //call function for substring
            swap((str+left), (str+i));
        }
    }
}

// calculation of factorial
int fact(int n)
{
    int res = 1;
    for(int i = n; i!=1; i--)
    {
        res*=i;
    }
    return res;
}

// to clean file output.txt
void clean_file()
{
    FILE *f = fopen("./output.txt", "w");
    fclose(f);
}


int main()
{
    char str[30];
    char **result;
    int num = 0;
    int len;
    int fact_len;

    printf("Hello! This is permutation maker. Enter your sequance: ");
    fgets(str, 28, stdin);  //read string
    printf("\n");
    if(str[strlen(str)-1] == '\n')
    {
        str[strlen(str)-1] = '\0';
    }

    len = strlen(str);
    fact_len = fact(len);
    result = calloc(fact_len, sizeof(char*));  // memory allocation for array for permutations
    for(int i = 0; i<fact_len; i++)
    {
        result[i] = calloc(len+1, sizeof(char));
    }

    permute(str, 0, len-1, &num, result);

    printf("Your sequance: %s\n", str);
    clean_file();                          // clean output.txt in case if it isn't empty
    FILE *f = fopen("./output.txt", "a");
    for(int i = 0; i<fact_len; i++)
    {
        fprintf(f, "%s\n", result[i]);
        printf("%d: %s\n", i+1, result[i]); // write on the screen all permutations
    }
    fclose(f);

    for(int i = 0; i<fact_len; i++)  // free memory
    {
        free(result[i]);
    }
    free(result);
    return 0;
}
