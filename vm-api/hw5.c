/*
 * @Author: misaki misakiwang74@gmail.com
 * @Date: 2023-12-06 14:07:21
 * @LastEditors: misaki misakiwang74@gmail.com
 * @LastEditTime: 2023-12-06 14:16:15
 */
#include<stdlib.h>

int main() {
    int data = malloc(sizeof(int) * 100);
    data[100] = 10; // error
    free(data);
    return 0;
}