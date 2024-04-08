#include <stdio.h>

int main() {
    int number;
    int square, cube;
    
    // 提示用户输入一个整数
    printf("请输入一个整数: ");
    scanf("%d", &number);
    
    // 计算输入数字的平方和立方
    square = number * number;
    cube = number * number * number;
    
    // 输出结果
    printf("输入数字的平方是: %d\n", square);
    printf("输入数字的立方是: %d\n", cube);
    
    return 0;
}
