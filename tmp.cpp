#include <iostream>
class A;
class B
{
   
    public:
    void fun()
    {
        // x->yabbaDabbaDo();//错误：A类的对象在定义之前被使用
    }
    private:
        A *x; //正确，经过前向引用声明，可以声明A类的对象指针
};
class A
{
    public:
        void yabbaDabbaDo();
    private:
        B* y;

};
int main() {
    return 0;
}
