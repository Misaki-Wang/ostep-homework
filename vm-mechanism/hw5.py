'''
Author: misaki misakiwang74@gmail.com
Date: 2023-12-06 16:57:07
LastEditors: misaki misakiwang74@gmail.com
LastEditTime: 2023-12-06 18:28:45
'''
import subprocess
import matplotlib.pyplot as plt

def run_script(limit, seed):
    # 调用原始脚本并捕获输出
    command = f'python relocation.py -s {seed} -l {limit} -c'
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    output = result.stdout

    # 统计有效和无效的地址
    valid_count = output.count('VALID')
    invalid_count = output.count('SEGMENTATION VIOLATION')

    if valid_count + invalid_count == 0:
        return 0
    return valid_count / (valid_count + invalid_count)

# 设置界限寄存器的不同值
limits = range(0, 1024, 10)  # 假设地址空间的最大大小为1024
seeds = [1, 2, 3, 4, 5]      # 不同的随机种子

# 为每个种子和界限寄存器值运行脚本
valid_ratios = {seed: [run_script(limit, seed) for limit in limits] for seed in seeds}

# 绘制图表
for seed, ratios in valid_ratios.items():
    plt.plot(limits, ratios, label=f'Seed {seed}')

plt.xlabel('Bounds Register Value')
plt.ylabel('Fraction of Valid Addresses')
plt.title('Fraction of Valid Addresses vs Bounds Register Value')
plt.legend()
plt.show()

plt.savefig('hw5.png')
    