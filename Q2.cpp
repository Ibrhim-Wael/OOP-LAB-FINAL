#include <iostream>
using namespace std;

class BankAccount
{
private:
  int accountID;
  float balance; 
public:
    BankAccount(int id,float bal):accountID(id),balance(bal){};
    void deposit(float value){balance+=value;}
    float getBalance(){return balance;}
    void setBalance(float v){
        balance=v;
    }
    void display(){
        cout<<"id is :"<<accountID<<endl;
        cout<<"Balance is : "<<balance<<endl;
    }
};

class Transaction
{
private:
  BankAccount &fromaccount;
  BankAccount &toaccount;
  float value;
  bool completed=0;
public:
Transaction(BankAccount &fromacc,BankAccount &toacc,float v):fromaccount(fromacc),toaccount(toacc),value(v){};
void excute()
{
    if(value<=fromaccount.getBalance())
    {
        fromaccount.setBalance((fromaccount.getBalance()-value));
        toaccount.setBalance((toaccount.getBalance()+value));
        completed=1;
        cout<<"Transaction Completed"<<endl;
    }else
    {
        cout<<"Transaction Cannot Be Completed"<<endl;
        completed=0;
    }
}
 void cancel()
{
     if(completed){
            fromaccount.setBalance((fromaccount.getBalance()+value));
            toaccount.setBalance((toaccount.getBalance()-value));
        }
        else{cout<<"Transaction Was not completed to be canceled"<<endl;}
}
};

int main(){
    BankAccount b1(5675,800);
    BankAccount b2(5729,700);
    Transaction t1(b1,b2,500);
    t1.excute();
    b1.display();//800-500=300
    b2.display();//700+500=1200
    t1.cancel();
    b1.display();//800
    b2.display();//700
    Transaction t2(b1,b2,900);
    t2.excute();//transaction cannot be done
    b1.display();//800
    b2.display();//700
    t2.cancel();//The Transaction was not done to be canceled
}
