#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // 设置随机种子
    srand(time(NULL));

    // 生成一个随机数
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "欢迎来到猜数字游戏！我已经想好了一个1到100之间的数字，请猜一猜：" << endl;

    do {
        cout << "请输入你的猜测: ";
        cin >> guess;

        if (guess < secretNumber) {
            cout << "猜小了，再试试！" << endl;
        } else if (guess > secretNumber) {
            cout << "猜大了，再试试！" << endl;
        }

        attempts++;
    } while (guess != secretNumber);

    cout << "恭喜你猜对了！正确答案是 " << secretNumber << "，你一共用了 " << attempts << " 次猜测。" << endl;

    return 0;
}
