#ifndef _SUDOKU_COLOR_H
#define _SUDOKU_COLOR_H

#include <iostream>

namespace Color
{
enum Code
{
    BOLD = 1,//粗体文字
    RESET = 0,//重置样式

    //BG_* 为背景颜色
    BG_BLACK = 40,
    BG_RED = 41,
    BG_GREEN = 42,
    BG_YELLOW = 43,
    BG_BLUE = 44,
    BG_MAGENTA = 45,//品红
    BG_CYAN = 46,//青色
    BG_LIGHT_GRAY = 47, // 实际是白色，终端为正常显示会进行调整
    BG_DEFAULT = 49,//默认
    
    //FG_* 为前景颜色
    FG_BLACK = 30,
    FG_RED = 31,
    FG_GREEN = 32,
    FG_YELLOW = 33,
    FG_BLUE = 34,
    FG_MAGENTA = 35,
    FG_CYAN = 36,
    FG_LIGHT_GRAY = 37,//白色
    FG_DEFAULT = 39,//默认
    FG_DARK_GRAY = 90, //亮黑
    FG_LIGHT_RED = 91, //亮红
    FG_LIGHT_GREEN = 92,
    FG_LIGHT_YELLOW = 93,
    FG_LIGHT_BLUE = 94,
    FG_LIGHT_MAGENTA = 95,
    FG_LIGHT_CYAN = 96,
    FG_WHITE = 97,
    //这些颜色和样式是基于 ANSI 转义序列的，例如，设置背景色为红色的代码为 \033[41m
};

//保存和管理文本的样式（如粗体）以及颜色（前景色和背景色）
//md、bg 和 fg 分别表示样式、背景色和前景色。类型都是 Code 枚举类型。
class Modifier
{
    Code md, bg, fg;

  public:
    Modifier() : md(Color::RESET),bg(Color::BG_DEFAULT),fg(Color::FG_DEFAULT) {}
    Modifier(Code Mode, Code BackGround, Code FrontGround) : md(Mode),bg(BackGround),fg(FrontGround) {}
    friend std::ostream &
    // 设置粗体文本，红色背景，绿色前景
    //std::cout << "\033[1;41;32m" << "这是粗体，红色背景，绿色前景的文本" << "\033[0m" << std::endl;
    
    operator<<(std::ostream &os, const Modifier &mod)
    {   
        return os << "\033[" << mod.md << ";" << mod.bg << ";" << mod.fg << "m";
    }
};
} // namespace Color

#endif