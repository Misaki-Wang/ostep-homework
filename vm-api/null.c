/*
 * @Author: misaki misakiwang74@gmail.com
 * @Date: 2023-12-06 13:49:27
 * @LastEditors: misaki misakiwang74@gmail.com
 * @LastEditTime: 2023-12-06 13:52:30
 */
#include<stdio.h>
#include<stdlib.h>

int main() {
    int *p = NULL;
    // printf("%d\n", *p);
    free(p);
    return 0;
}