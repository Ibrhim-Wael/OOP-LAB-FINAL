#include <iostream>
using namespace std;

class Student
{
private:
 string name;
 int id;
 float marks[3];   
public:
Student():name("Blank"),id(0){marks[0]=0;marks[1]=0;marks[2]=0;}
Student(string n,int i,float m[3]):name(n),id(i)//Construcor
{
    marks[0]=m[0];
    marks[1]=m[1];
    marks[2]=m[2];
};
float calculateAverage()//Member Function CalcAvg()
{
    float avg;
    float sum=0;
    for (int i = 0; i < 3; i++)
    {
        sum+=marks[i];
    }
    avg=sum/3;
    return avg;
}
bool operator ==(Student s1)//Operator Overloading Function
{
    if(calculateAverage()==s1.calculateAverage()){return 1;}
    else{return 0;}
}
void setmarks(int n)
{
for (int i = 0; i < 3; i++)
{
    cout<<"Please enter the mark for subject no "<<(i+1)<<" to student no "<<(n+1)<<endl;
    cin>>marks[i];
}
}
void displayavg(int i)
{
    cout<<"The Averge for student no "<<(i+1)<<" is : "<<calculateAverage()<<endl;
};
};

int main(){
Student s[3];
for (int i = 0; i < 3; i++)
{
    s[i].setmarks(i);
}
for (int i = 0; i < 3; i++)
{
    s[i].displayavg(i);
}
if(s[0]==s[1])
{
    cout<<"average is equal"<<endl;
}else
{
    cout<<"Average Not Equal"<<endl;
}
}
