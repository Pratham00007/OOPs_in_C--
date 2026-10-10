#include<bits/stdc++.h>
using namespace std;


class Bank{
    private:
    int Acc_no;
    int pin;
    string name;
    int age;
    int balance;
    public:

    void Create_acc(int account_num){
        Acc_no=account_num;
        int new_pin,user_age,bal;
        string user_name;

        pin=new_pin;
        name=user_name;
        age=user_age;
        if(bal>0){
        balance=bal;}else{
            cout<<"Invalid balance\n";
        }
        cout<<"Succesful Created\n";
        cout<<account_num;
        

    }

    bool verify_pin(int ent){
        if(ent==pin) return true;
        else return false;
    }

    int get_accno(){
        return Acc_no;
    }

    void depo(int amt){
        if (amt<=0) cout<<"Invalid Amount\n";
        else{
            balance+=amt;
            cout<<"Success\n";
        }
    }
    void withd(int amt){
        if (amt<=0) cout<<"Invalid Amount\n";
        else{
            balance-=amt;
            cout<<"Success\n";
            cout<<"Available: "<<balance<<endl;
        }
    }

    bool correct_pin(int pin){
        if(pin>999 && pin<10000) return true;
        else{return false;}
    }

    void update_det(){
        string new_name;
        int new_pin,new_age;

        cout<<"New Name\n";
        cin>>new_name;
        cout<<"New Pin\n";;
        cin>>new_pin;
        cout<<"New Age\n";
        cin>>new_age;

        name=new_name;
        cout<<"Success Name Change\n";
        if(correct_pin(new_pin)){
            if(new_pin==pin){
                cout<<"Old==New not possible";
            }else{
                pin=new_pin;
                cout<<"Success Pin Change\n";
            }
        }

        
        if (age<=0) cout<<"Invalid Age\n";
        else{
            age=new_age;
            cout<<"Success Age Change\n";
        
    }

    
    }
    void Delete_Acc(){
        // i dont know
    }

    void histor(){
        // i dont know
    }

};


void acc_op(int index){
    Bank ba[100];
    int i;
    do{
        cout<<"1. Deposit"<<"2. Wihdraw"<<"3. Update Detail"<<"-1. to exit";
        cout<<"Enter Choice";
        cin>>i;
        if(i==1){
            int amt=0;
            cout<<"Enter amt";
            cin>>amt;
            ba[index].depo(amt);
        }else if(i==2){
            int amt=0;
            cout<<"Enter amt";
            cin>>amt;
            ba[index].withd(amt);
        }else if(i==3){
            
            ba[index].update_det();
        }else if(i==-1) break;
        else{
            cout<<"Invalid input";
        }



    }while(i!=-1);

}

int main(){
    Bank ba[100];
    int cnt=0,st=1001;
    int i;
    do{
        cout<<"1. Create Acc"<<"2. Login"<<"-1. to exit";
        cout<<"Enter Choice";
        cin>>i;
        if(i==1){
            if(cnt>=100) {cout<<"Limit full";}
            else{
                ba[cnt++].Create_acc(st++);
            }
        }else if(i==2){
            int acc_no;
            cin>>acc_no;
            for(int i=0;i<cnt;i++){
                if(ba[i].get_accno()==acc_no){
                    int pin;
                    cout<<"Enter Pin";
                    cin>>pin;
                    if(ba[i].verify_pin(pin)){
                        cout<<"Succesfull Login\n";
                    }else{
                        cout<<"Invalid Pin";
                    }
                }
    
            }
            cout<<"Wrong Account Number";
                
        }else if(i==-1) break;
        else{
            cout<<"Invalid input";
        }



    }while(i!=-1);
}