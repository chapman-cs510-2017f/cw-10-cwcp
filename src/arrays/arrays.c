#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

void set_arrays(int array_size, int array[array_size], long double *memblock) 
{
       /* Fill declared arrays with integers */
    int i;
    for (i=0; i < array_size; i++)
    {
        // assign the value i to the ith element 
        array[i] = i;
        
        // set the value inside the memory address at memblock + (i bytes) to i
        *(memblock+i) = i;
    }
    /* End fill with integers */

}

void print_arrays(int array_size, int array[array_size], long double *memblock,const char *foo)
{
        int i;
        for (i=0; i < (array_size + 3); i++)
    {
        // print the array values using array syntax
        printf("array[%d] : %d\t", i, array[i]);
        
        // print values contained in each memory address starting at memblock 
        printf("*(memblock + %d) : %Lf\t", i, *(memblock+i));
        
        // print each character in the string using array syntax
        printf("foo[%d] : %c\t", i, foo[i]);
        
        // do the same thing as above, but in memory pointer notation
        printf("*(foo + %d) : %c\n", i, *(foo+i));
    } 
}

int main(void)
{
    /* Array syntax for defining an array */
    int array_size = 10;
    int array[array_size];
    /* End array syntax declaration */

    /* Explicit memory allocation for defining the same array */
    
    // Allocate a block of array_size integers and assign the address
    // of the beginning of the memory block to the pointer memblock
    long double *memblock = malloc(array_size * sizeof(int));
    /* WARNING: malloc may fail and return a NULL value for the pointer
                Good programming practice mandates checking for such failures.
    */
    if (NULL == memblock) {
      // Print to the "file" of standard error, rather than standard out
      fprintf(stderr, "malloc failed\n");
      // Return a non-successful integer
      return -1;
    }

    /* End explicit memory allocation declaration */
    
    /* String example showing the two methods are equivalent */
    // constant character array (i.e., a string)
    const char *foo = "Foo bar .";
    
    set_arrays(array_size,array,memblock);
    print_arrays(array_size,array,memblock, foo);

    // explicitly free the block of memory malloc-ed at memblock 
    free(memblock);

    // memory not explicitly freed is automatically freed on function exit
    return 0;
}
