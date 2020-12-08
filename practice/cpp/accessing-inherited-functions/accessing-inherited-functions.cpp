#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};


class D : public A, public B, public C 
{

    int val;

    public:
        //Initially val is 1
         D() : A(),  B(), C()
         {
             val = 1;
         }

         //Implement this function
         void update_val(int new_val)
         {
            int tmp = new_val;
            while (tmp % 2 == 0) {
                tmp = tmp / 2;
                A::func(val);
            }

            while (tmp % 3 == 0) {
                tmp = tmp / 3;
                B::func(val);
            }

            while (tmp % 5 == 0) {
                tmp = tmp / 5;
                C::func(val);
            }

         }
         //For Checking Purpose
         void check(int); //Do not delete this line.
};
