/*
 * @Author: misaki misakiwang74@gmail.com
 * @Date: 2023-12-06 13:59:36
 * @LastEditors: misaki misakiwang74@gmail.com
 * @LastEditTime: 2023-12-06 14:06:42
 */
#include<stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    *p = 10;
    // free(p);
    return 0;
}