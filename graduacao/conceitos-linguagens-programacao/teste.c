#include <stdio.h>

#define typeof(var) _Generic( (var),\
char: "Char",\
int: "Integer",\
float: "Float",\
char *: "String",\
void *: "Pointer",\
default: "Undefined")

int main(){
    printf("%d - %u - %u", -2147483647-1U<-2147483647, -2147483647-1U, -1U-2147483647);
    return 0;
}