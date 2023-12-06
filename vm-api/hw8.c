/*
 * @Author: misaki misakiwang74@gmail.com
 * @Date: 2023-12-06 14:34:01
 * @LastEditors: misaki misakiwang74@gmail.com
 * @LastEditTime: 2023-12-06 14:34:23
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Vector;

void initVector(Vector *v, size_t initialSize) {
    v->array = malloc(initialSize * sizeof(int));
    v->used = 0;
    v->size = initialSize;
}

void insertVector(Vector *v, int element) {
    if (v->used == v->size) {
        v->size *= 2;
        v->array = realloc(v->array, v->size * sizeof(int));
    }
    v->array[v->used++] = element;
}

void freeVector(Vector *v) {
    free(v->array);
    v->array = NULL;
    v->used = v->size = 0;
}

int main() {
    Vector v;
    initVector(&v, 5); // 初始化向量大小为 5

    for (int i = 0; i < 10; i++) {
        insertVector(&v, i); // 添加元素
    }

    freeVector(&v);
    return 0;
}
