#include<iostream>
#include<string>
using namespace std;

class Bank_Account {
    public:
    string cutomer_name ;
    int account_number;
    int balance;
    void deposit();
    void withdraw();
};
void Bank_Account :: deposit(){
    int _amount ;
    cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT : ";
    cin>>_amount;
    balance+=_amount;
    cout<<"YOU HAVE DEPOSITED "<<_amount<<endl;
}

void Bank_Account :: withdraw(){
    int _amount ;
    cout<<"ENTER THE AMOUNT YOU WANT TO WITHDRAW : ";
    cin>>_amount;
    if (balance-_amount>0){
    balance-=_amount;
    cout<<"YOU HAVE WITHDRAWN "<<_amount<<endl;
    }
}

class Current : public Bank_Account {


};

class Saving : public Bank_Account{

};


int main(){

    
    return 0;
}