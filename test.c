#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_math.h"
int main() {
    // 初始化随机数种子
    srand(time(NULL));

    int rows = 18;  // 18排
    int cols = 9;   // 每排9个座位

    printf("\n========== 电影院座位图 (18排×9列) ==========\n\n");

    // 生成每一排座位
    for (int i = 1; i <= rows; i++) {
        printf("%2d排: ", i);  // 使用%2d确保对齐

        for (int j = 1; j <= cols; j++) {
            // 随机决定座位是否被购买（约20%的概率）
            int is_sold = (rand() % 100) < 20;

            if (is_sold) {
                // 已购买：白色背景显示座位号
                printf("\033[47;30m%d\033[0m ", j);
            }
            else {
                // 未购买：正常显示
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    // 图例说明
    printf("\n图例: 普通数字: 可购买, ");
    printf("\033[47;30m白色背景数字\033[0m: 已购买\n");

    return 0;
}