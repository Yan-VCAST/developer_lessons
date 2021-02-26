#include <stdio.h>

int main()
{
    int result = 0;
    int input = 1;
    
    int a = 1;
    int b = 2;
    
    asm volatile (
        "movl %1, %0\n" // "%1" means the second param below, while "%0" is the first param
        : "=r"(result)  // "=" means output, "r" indicates register
        : "r"(input)
        );
        
    printf("result = %d\n", result);
    printf("input = %d\n", input);
    
    asm volatile (
        "movl %%eax, %%ecx\n"
        "movl %%ebx, %%eax\n"
        "movl %%ecx, %%ebx\n"
        : "=a"(a), "=b"(b)
        : "a"(a), "b"(b)
        );
        
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    return 0;
}
