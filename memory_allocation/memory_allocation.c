#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *p;//Pointer to reveive references to memory allocated
    p = malloc(50 * sizeof(int));//Uses sizeof to determine the size of the whole.
                                 //So allocates space for 50 integers
    
    if(p) //Checks if the memory was allocated
    {	    
        printf("Yes, is was successful allocation \n");
        free(p);
    }
    else
        printf("Sorry, there is not enough memory on the heap =/ \n");

    return 0;
}
