/*
 * @Author: misaki misakiwang74@gmail.com
 * @Date: 2023-12-06 14:21:10
 * @LastEditors: misaki misakiwang74@gmail.com
 * @LastEditTime: 2023-12-06 14:27:01
 */
#include<stdlib.h>
#include<stdio.h>

int main(){
    int *data = malloc(sizeof(int) * 100);

    if(data == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    free(data + 50); // error

    return 0;
}