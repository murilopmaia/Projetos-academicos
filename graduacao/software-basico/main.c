#include <stdio.h>

int equalBit(int x, int y){
    return (x ^ (~y)) & 1;
}

int main(){
    printf("%d", equalBit(10, 5));
    return 0;
}

/*
1010
0101
1111
0001
0001

1010
1101
0111
0001
0001
*/