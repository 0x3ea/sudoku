//命令头文件
#ifndef _SUDOKU_COMMAND_H_
#define _SUDOKU_COMMAND_H_

#include <memory>
#include "common.h"

class CScene;
class CCommand//操作命令的类，可能涉及执行和撤销操作
{

public:
    //构造函数
    CCommand(CScene* pOwner);
    CCommand(CScene *pOwner, const point_t &point, int preValue, int curValue);
    //拷贝构造函数
    CCommand(const CCommand &);
    //析构函数，通常用于释放资源（如内存、文件句柄等）
    ~CCommand();

    bool execute(int nInputValue);  //执行命令
    void undo();  //撤销命令 
    point_t getPoint() { return _stPoint; }  //表示该命令操作的数独格子的坐标位置
    int getPreValue() { return _nPreValue; }  //表示该命令操作之前的数值
    int getCurValue() { return _nCurValue; }  //表示该命令操作之后的数值
    void setPoint(const point_t &point) { _stPoint = point; }  
    void setPreValue(int preValue) { _nPreValue = preValue; }
    void setCurValue(int curValue) { _nCurValue = curValue; }

private:
    CScene* _pOwner;
    point_t _stPoint;
    int _nPreValue;
    int _nCurValue;  // actually the member is never used
};  

#endif