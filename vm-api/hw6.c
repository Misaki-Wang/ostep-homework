/*
 * @Author: misaki misakiwang74@gmail.com
 * @Date: 2023-12-06 14:11:53
 * @LastEditors: misaki misakiwang74@gmail.com
 * @LastEditTime: 2023-12-06 14:27:42
 */
#include<stdlib.h>
#include<stdio.h>

int main() {
    int *data = malloc(sizeof(int) * 100);

    if(data == NULL) {
        printf("malloc failed\n");
        return 1;
    }
// hello world
    data[0] = 10; 
    printf("%d\n", data[0]);
    free(data);
    printf("%d\n", data[0]);
    return 0;
}