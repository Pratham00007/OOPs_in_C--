#include<bits/stdc++.h>
using namespace std;

class Teacher{
    private:
    
    double salary;
    public: 
    string name;
    string dept;
    string subject;

    // setter
    void set_sal(double s){
        salary=s;
    }
    void get_sal(){
        cout<<salary<<endl;
    }

};

int main(){
    Teacher t1;
    t1.name="Aaman";
    cout<<t1.name;
    cout<<t1.dept;

    t1.set_sal(25000);
    t1.get_sal();
}