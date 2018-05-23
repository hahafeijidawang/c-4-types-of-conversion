/*

    static_cast 静态类型转换，如int转换成char

    reinterpret_cast 重新解释类型

    dynamic_cast 命名上理解是动态类型转换，如子类和父类之间的多态类型转换。

    const_cast   字面上理解就是去const属性。

    4种类型转换的格式。

    TYPE B  = static_cast<TYPE>(a);

*/
#include <iostream>

using namespace std;

class Animal
{
public:
    friend void playObj(Animal *base);
       virtual void cry() = 0;
};

class Dog : public Animal{

public:

    void cry(){

        cout<<"wangwang"<<endl;

    }

    void doHome(){

        cout<<"看家"<<endl;
    }


};
  class Cat:public Animal{

public:

  void cry(){

      cout<<"miaomiao"<<endl;

  }

  void doThing(){

      cout<<"cacth mouse"<<endl;

  }



  };

  void playObj(Animal *base){


      base->cry();//1 有继承 2虚函数重写 3父类指针 指向子类====》多态
     //能识别子类对象
      // dynamic_cast 运行时类型识别。
      //父类转换成子类没有问题 而子类-》父类就不一定了。
      Dog *pDog = dynamic_cast<Dog *>(base);
      if(pDog != NULL){

          pDog->doHome();

      }
      Cat *pCat = dynamic_cast<Cat *>(base); //dynamic_cast
      if(pCat != NULL){

          pCat->doThing();

      }

  }



int main()
{
    Dog d1;
    Cat c1;
    Animal *pBase = NULL;

    pBase = &d1;
    pBase = static_cast<Animal *>(&d1);
    //强制类型转换
    pBase = reinterpret_cast<Animal*>(&d1);

    playObj(&d1);

    playObj(&c1);


    double dpi = 3.1415926;

    int num1 = (int)dpi;//c类型转换

    int num2= static_cast<int>(dpi);//静态类型转换，编译时c++编译器会做类型转换。

    int num3 = dpi;//c语言中 隐式转换的地方 均可以使用 static_cast<>()进行类型转换。

    //char * ====> int *

    char *p1 = "hello.....itcast";

    int *p2 = NULL;

    p2 = reinterpret_cast <int *>(p1);

    cout<<"p1:"<<p1<<endl;

    cout<<"p2:"<<p2<<endl;



    return 0;
}

