#include<bits/stdc++.h>
using namespace std;

class Student{


    public:
    Student(){
        cout<<"Student Object Created\n";
    }
    void display(){
        cout<<"Student details displayed\n";
    }
    ~Student(){
        cout<<"Student object destroyed\n";
    }
};


class Animal{
    public:
    void eat(){
        cout<<"Eat\n";
    }
};

class Dog : public Animal{
    public:
    void bark(){
        cout<<"barks\n";
    }
};

class BankAccount{
    private:
    double balance=0;
    public:
    void deposit(int amt){
        if(amt<=0) cout<<"invalid Amt";
        else{
            balance+=amt;
            cout<<"Success\n";
        }
    }
    void showBal(){
        cout<<fixed<<setprecision(2);
        cout<<balance<<endl;
    }

};

int main(){
    Student stu;
    stu.display();

    Dog dg;
    dg.bark();
    dg.eat();

    BankAccount ba;
    ba.showBal();
    ba.deposit(1000);
    ba.showBal();
    
    return 0;
}