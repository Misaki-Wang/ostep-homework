/*
 * @Author: misaki misakiwang74@gmail.com
 * @Date: 2023-12-02 15:32:33
 * @LastEditors: misaki misakiwang74@gmail.com
 * @LastEditTime: 2023-12-02 19:56:57
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

#define ITERATIONS 10000

int main() {
    int pipe1[2], pipe2[2];
    char buf;
    struct timeval start, end;
    pid_t pid;
    long seconds, useconds;
    double total_time, average_time;

    // 创建两个管道
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        return 1;
    }

    // 创建子进程
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {  // 子进程
        for (int i = 0; i < ITERATIONS; i++) {
            read(pipe1[0], &buf, 1);      // 从 pipe1 读取
            write(pipe2[1], &buf, 1);     // 写入 pipe2
        }
    } 
    else {         // 父进程
        gettimeofday(&start, NULL);     // 记录开始时间

        for (int i = 0; i < ITERATIONS; i++) {
            write(pipe1[1], &buf, 1);    // 写入 pipe1
            read(pipe2[0], &buf, 1);     // 从 pipe2 读取
        }

        gettimeofday(&end, NULL);       // 记录结束时间

        // 计算总耗时
        seconds  = end.tv_sec  - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_time = ((seconds) * 1000 + useconds / 1000.0) + 0.5;

        // 计算平均耗时
        average_time = total_time / ITERATIONS;

        printf("Average context switch time: %f milliseconds\n", average_time);
    }

    return 0;
}
