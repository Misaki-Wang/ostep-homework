/*
 * @Author: misaki misaki-wang@qq.com
 * @Date: 2023-12-02 15:17:57
 * @LastEditors: misaki misaki-wang@qq.com
 * @LastEditTime: 2023-12-02 19:28:36
 */
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("/dev/null", O_RDONLY); // 打开 /dev/null 用于读取
    if (fd < 0) {
        perror("Failed to open /dev/null");
        return 1;
    }

    struct timeval start, end;
    long seconds, useconds;
    double total_time, average_time;
    int iterations = 10000000000; // 设置迭代次数

    // 记录开始时间
    gettimeofday(&start, NULL);

    for (int i = 0; i < iterations; i++) {
        read(fd, NULL, 0); // 执行 0 字节的读取
    }

    // 记录结束 时间
    gettimeofday(&end, NULL);

    // 计算总耗时
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    total_time = ((seconds) * 1000 + useconds/1000.0) + 0.5; // 加上 0.5 是为了在转换到毫秒时进行四舍五入 

    // 计算平均耗时
    average_time = total_time / iterations;

    printf("Average time per system call: %f milliseconds\n", average_time);

    close(fd);
    return 0;
}
