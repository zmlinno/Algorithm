#include<iostream>
#include<assert.h>

using namespace std;

// int main()
// {
//     int a = 0;

//     //如果写成下面这个样，那么地址就是一样的了。
//     int &b = a;

//     //引用，那么b就是a的别名了
//     cout << &b << endl;
//     cout << &a << endl;

//     cout << b << endl;
//     //但是a和b的地址并不一样。

//     b++;
//    // a++;

//     int &c = a;
//     int &d = c;

//     d++;
//     cout << d << endl;

//     return 0;
//     //加起来是2，

// }





//  void Swap(int* a,int* b)
//  {
    
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
//     //传过去的地址，所以要把地址给他们
//  }




// int main()
// {
//     int x = 0,y = 1;
//     Swap(&x,&y);
    
//     return 0;
// }




// void Swap(int &a,int &b)
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }




// int main()
// {
//     int x = 0,y = 1;
//     printf("%d %d\n",x,y);
//     Swap(x,y);
//     printf("%d %d\n",x,y);

//     return 0;
// }







// int main()
// {
//     int a = 0;
//     //引用必须初始化
    
//     // int& b;
//     // b = c;



//     //2.引用定义后，不能改变指向
//     int &b = a;
//     int c = 2;
//     b = c;//不是改变指向，而是赋值


//     //3.一个变量可以有多个引用，多个别名
//     int d = b;
//     return 0;

// }










//指针和引用的功能有类似
//引用不能完全代替指针，引用定义后，不能改变指向



int fun()
{
    int a = 0;
    return a;
}
int main()
{
    int ret = fun();
    cout<< ret <<endl;
    return 0;
}






