#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i; // Iteration index
    
    /* Array syntax for defining an array */
    int array_size = 10;
    int array[array_size];
    /* End array syntax declaration */

    /* Explicit memory allocation for defining the same array */
    
    // Allocate a block of array_size integers and assign the address
    // of the beginning of the memory block to the pointer memblock
    int *memblock = malloc(array_size * sizeof(int));
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
    /* End string declaration as array of characters */
    
    /* Fill declared arrays with integers */
    for (i=0; i < array_size; i++)
    {
        // assign the value i to the ith element 
        array[i] = i;
        
        // set the value inside the memory address at memblock + (i bytes) to i
        *(memblock+i) = i;
    }
    /* End fill with integers */

    /* Print out results to verify exactly what the above code did */

    // Note: this increments three bytes BEYOND the allocated memory (buffer overrun)
    for (i=0; i < (array_size + 3); i++)
    {
        // print the array values using array syntax
        printf("array[%d] : %d\t", i, array[i]);
         
        // print values contained in each memory address starting at memblock 
        printf("*(memblock + %d) : %d\t", i, *(memblock+i));
        
        // print each character in the string using array syntax
        printf("foo[%d] : %c\t", i, foo[i]);
        
        // do the same thing as above, but in memory pointer notation
        printf("*(foo + %d) : %c\n", i, *(foo+i));
    }
    
    // explicitly free the block of memory malloc-ed at memblock 
    free(memblock);

    // memory not explicitly freed is automatically freed on function exit
    return 0;
}
