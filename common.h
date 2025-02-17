//// 公共头文件
#ifndef _SUDOKU_COMMON_H_
#define _SUDOKU_COMMON_H_

static const unsigned int UNSELECTES = 0;

//enum class 是C++11的新特性，用来定义枚举类型
//enum class的优点是可以避免枚举类型的污染
//enum class的缺点是不能直接使用枚举类型的值，需要通过枚举类型::枚举值来使用
//enum class的底层实现是int类型
enum class Difficulty :int  //难度
{
    EASY = 1,
    NORMAL,
    HARD  
};

enum class State : int //格子状态
{
    INITED = 0,
    ERASED,
};

enum class keyMode :int  //按键模式
{
    NORMAL =1,
    VIM
};

struct KeyMap //存储键盘按键的映射
{
    //这里调换了顺序!
    const char ESC = 0x1B;//退出游戏
    const char U = 0x75;//撤销上一步操作
    const char ENTER = 0x0D;
    char UP;
    char LEFT;
    char DOWN;
    char RIGHT;
};

//由keyMap派生出Normal和Vim两个类
struct Normal : keyMap 
{
    Normal()
    {
        UP =0x77;
        LEFT =0x61; 
        DOWN =0x73;
        RIGHT =0x64;   
    }
};

struct Vim : keyMap
{
    Vim()
    {
        UP =0x6B;
        LEFT =0x68;
        DOWN =0x6A;
        RIGHT =0x6C;
    }
};

//数独网格中的一个点
using point_t = struct point_t 
{
    int x;
    int y;
};

//数独网格中的一个点和它的状态
using point_value_t = struct point_value_t
{
    int value;
    State state;
};

//允许该类对象作为比较器使用
class CPointSort
{
    public:
        //重载了 () 运算符,判断是否相等
        bool operator()(const point_t &lhs, const point_t *rhs) const
        {
            if((lhs.x==rhs.x)&&(lhs.y==rhs.y))
                return false;
            else
                return true;
        }
};

#endif