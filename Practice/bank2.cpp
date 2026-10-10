#include<bits/stdc++.h>
using namespace std;

class BankAccount{
    private:
    int balance;

    public:

    string accountHolder;
    int accountNumber;
    

    BankAccount(string name,int no, int bal){
        accountHolder=name;
        accountNumber=no;
        balance=bal;
    }


    void deposit(int amt){
        if(amt<0){
            cout<<"Invalid Amt\n";
            return ;
        }else{
            balance+=amt;
            cout<<"Added\n";
        }
    }
    void withdraw(int amt){
        if(amt<0){
            cout<<"Invalid Amt\n";
            return ;
        }else if(amt>balance){
            cout<<"Insufficient Balance\n";
        }else{
            balance-=amt;
            cout<<"Added\n";
        }
    }

    void details(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Acc Holder: "<<accountHolder<<endl;
        cout<<"balance available: "<<balance<<endl;
    }
};

int main(){
    BankAccount acc("Shree", 10001,  100);
    acc.details();
    acc.deposit(5000);
    acc.details();
    acc.withdraw(1000);
    acc.details();
    
}