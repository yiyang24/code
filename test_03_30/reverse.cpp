#include <iostream>
#include <cstring>

using namespace std;

// 定义函数，使用指针来逆转字符串
void reverseString(char* str) {
    int len = strlen(str);
    char* start = str;
    char* end = str + len - 1;

    // 交换字符串的前后字符，直到 start 指针超过 end 指针
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        // 移动指针，继续交换下一对字符
        start++;
        end--;
    }
}

int main() {
    char str[] = "Hello, world!";

    cout << "原始字符串: " << str << endl;

    // 调用函数，传递字符串的地址
    reverseString(str);

    cout << "逆转后的字符串: " << str << endl;

    return 0;
}
