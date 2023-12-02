'''
Author: misaki misaki-wang@qq.com
Date: 2023-12-02 17:14:00
LastEditors: misaki misaki-wang@qq.com
LastEditTime: 2023-12-02 19:17:23
'''
#! /usr/bin/env python3

import random

def sjf_simulation(job_lengths):
    # 初始化
    time_elapsed = 0
    response_times = []

    # 按作业长度对作业进行排序
    sorted_jobs = sorted(job_lengths)

    # 模拟 SJF 调度
    for job_length in sorted_jobs:
        response_times.append(time_elapsed)  # 记录当前作业的响应时间
        time_elapsed += job_length  # 更新经过的时间

    return response_times

# 模拟不同长度的作业
job_lengths = [random.randint(1, 1000) for _ in range(5)]  # 生成 5 个随机长度的作业
response_times = sjf_simulation(job_lengths)

print("作业长度: ", job_lengths)
print("响应时间: ", response_times)
