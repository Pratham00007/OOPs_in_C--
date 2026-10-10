#include<bits/stdc++.h>
using namespace std;

class Account{

        private:
        string name;
        int Acc_no;
        int bal;

        public:
        
        void create_acc(int no){

            Acc_no=no;

            cout<<"Name";
            cin>>name;
            cout<<"Inital Deposit";
            cin>>bal;

            if(bal<0){
                cout<<"Invalid Balance";
                bal=0;
            }

            cout<<"Successfully Created\n";
            cout<<"Your Account number: "<<Acc_no<<endl;
        }

        int get_acc_no(){
            return Acc_no;
        }

        void deposit(int amt){
            if(amt<0){
                cout<<"Invalid Amt";
                return ;
            }else{
                bal+=amt;
                cout<<"Deposit Succesfull\n";
            }
        }

        void withdraw(int amt){
            if(amt<0){
                cout<<"Invalid amt\n"; return ;
            }
            else if(amt>bal){
                cout<<"Less Balance\n";
                
            }else{
                bal-=amt;
                cout<<"Succesfull\n";
            }
        }

        void show_det(){
            cout<<Acc_no;
            cout<<name;
            cout<<bal;
            
        }

        void updatedetail(){
            cout<<"Enter New Name:";
            cin>>name;
            cout<<"Updated Successfully\n";
        }

        void show_bal(){
            cout<<bal<<endl;
        }

};



int main(){

    Account Acc[100];
    int cnt=0, inp, next_Acc=1000;



    do{
        cout<<"1. Create Account"<<"\n2. Show Account Detail"
        <<"\n3. Deposit Amt"<<"\n4. Withdraw Money"
        <<"\n5. Show Balance"<<"\n-1 To Exit";

        cout<<"\nEnter Choice: ";
        cin>>inp;

        if(inp==-1){
            cout<<"Thank You For Banking";
            break;
        }
        else if(inp==1){
            if(cnt<100){
                Acc[cnt].create_acc(next_Acc++);
                cnt++;
            }else{
                cout<<"Limit Reached to add\n";
            }
        }else if(inp>=2 && inp<=5){
            int acc_no,index=-1;
            cout<<"Enter Acc no:";
            cin>>acc_no;
            for(int i=0;i<cnt;i++){
                if(Acc[i].get_acc_no()==acc_no){
                    index=i;
                }
            }
            if(index==-1){
                cout<<"No Acc found";
                
            }


            if(inp==2){
                Acc[index].show_det();
            }else if(inp==3){
                int depo=0;
                cin>>depo;
                Acc[index].deposit(depo);
            }else if(inp==4){
                int withd=0;
                cin>>withd;
                Acc[index].withdraw(withd);
            }else if(inp==5){
                Acc[index].show_bal();
            }

        }else{
            cout<<"Invalid input\n";
        }
    }while(inp!=-1);

    return 0;
}