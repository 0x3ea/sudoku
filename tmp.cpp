#include <iostream>
namespace printhello
{
    void print(std::string name)
    {
        std::cout << "Hello, " << name << std::endl;
        // std::cout << "\033[1;41;32m"<< "Hello, " << name << std::endl;
    }
}
// using namespace printhello;
int main() {

    
    // 设置粗体文本，红色背景，绿色前景
    // std::cout << "\033[1;41;32m" << "这是粗体，红色背景，绿色前景的文本" << "\033[0m" << std::endl;
    printhello::print(std::string("you"));
    return 0;
}
