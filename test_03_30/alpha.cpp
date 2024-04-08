#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void countCharacters(const string& str) {
    unordered_map<char, int> charCount;

    // 初始化字母和非字母的计数为0
    for (char c = 'a'; c <= 'z'; ++c)
        charCount[c] = 0;

    charCount[' '] = 0; // 空格算作非字母

    // 遍历字符串并统计各种字符的数量
    for (char c : str) {
        if (isalpha(c)) {
            // 如果是字母，则转换为小写字母进行统计
            charCount[tolower(c)]++;
        } else {
            // 如果不是字母，则直接统计为非字母
            charCount[' ']++;
        }
    }

    // 输出统计结果
    cout << "字符统计结果：" << endl;
    for (char c = 'a'; c <= 'z'; ++c)
        cout << c << ": " << charCount[c] << endl;
    cout << "非字母(包括空格等): " << charCount[' '] << endl;
}

int main() {
    string input;
    cout << "请输入一段字符串: ";
    getline(cin, input);

    countCharacters(input);

    return 0;
}
