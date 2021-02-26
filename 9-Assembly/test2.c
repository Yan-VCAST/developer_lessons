#include <stdio.h>

int main()
{
    char* s = "Vector\n";
    int l = 7;
    
    printf("main begin\n");
    
    asm volatile (
        "movl $4, %%eax\n"
        "movl $1, %%ebx\n"
        "movl %0, %%ecx\n"
        "movl %1, %%edx\n"
        "int $0x80     \n"
        : 
        : "r"(s), "r"(l)
        : "eax", "ebx", "ecx", "edx"
    );
    
    printf("main end\n");
    
    return 0;
}
