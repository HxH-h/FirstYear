# include "calcultor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
# include <QString>
# include <QDebug>
# include <QMessageBox>
# include <iostream>
using namespace std;
#include <string>
# include <stack>
# include <cmath>
stack<char> save;
stack<double> number;
string ret;
int priority(char c) {
    switch(c){
        case '+':
        return 1;
        case '-':
        return 1;
        case '*':
        return 2;
        case '/':
        return 2;
    }
}
double change(string c){
    int n=c.length()-1;
    double sum=0;
    if(c[c.length()-1]=='0'){
        for(int i=0;i<c.length();i++){
        sum+=(c[i]-'0')*pow(10,n-1);
        n--;
        }
        return sum;
    }else{
        int d=c.length();
    int e=c[c.length()-1]-'0';
    int pos=d-e-2;
    double a=0,power1=pos-1,temp=0,power2=1;
    for(int i=0;i<c.length()-1;i++){
        if(i<pos){
            a+=(c[i]-'0')*pow(10,power1);
            power1--;
        }else if(i>pos){
            temp=(c[i]-'0')*pow(0.1,power2);
            a+=temp;
            power2++;
        }
    }
    return a;
    }

}
void trans(string c){
    char temp;
    int pos=0,flag=0;
    char show;
    for(int i=0;i<c.length();i++){
        if(c[i]>='0'&&c[i]<='9'||c[i]=='.'){
            while(c[i]>='0'&&c[i]<='9'||c[i]=='.'){
            show=c[i];
            ret.push_back(c[i]);
            if(flag==1){
                pos++;
            }
            if(c[i]=='.'){
                flag=1;
            }
            i++;
        }
            ret.push_back(pos+'0');
            ret.push_back(' ');
            pos=0;
            flag=0;
        }

        if(c[i]=='('){
            save.push(c[i]);
        }else if(c[i]==')'){
            temp=save.top();
            while(temp!='('){
                save.pop();
                ret.push_back(temp);
                temp=save.top();
            }
            save.pop();
        }else if(save.empty()){
            save.push(c[i]);
        }else{
            char cmp=save.top();
            if(priority(c[i])>priority(cmp)||cmp=='('){
                save.push(c[i]);
            }else{
                while(priority(c[i])<=priority(cmp)&&!save.empty()){
                    ret.push_back(cmp);
                    save.pop();
                    if(!save.empty()){
                        cmp=save.top();
                    }
                    if(cmp=='('){
                        goto out;
                    }
                }
                out:save.push(c[i]);
            }
        }
    }
    while(!save.empty()){
        temp=save.top();
        ret.push_back(temp);
        save.pop();
    }
}
void calculate(string c){
    for(int i=0;i<c.length();i++){
        if(c[i]>='0'&&c[i]<='9'||c[i]=='.'){
            string num;
            while(c[i]>='0'&&c[i]<='9'||c[i]=='.'){
                num+=c[i];
                i++;
            }
            double numb=change(num);
            number.push(numb);
        }
        if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'){
            double a=number.top();
            number.pop();
            double b=number.top();
            number.pop();
                switch(c[i]){
                case '+':
                number.push(b+a);
                break;
                case '-':
                number.push(b-a);
                break;
                case '*':
                number.push(b*a);
                break;
                case '/':
                number.push(b/a);
                break;
            }
        }
    }
}
void MainWindow::ishow(){
    QString input;
    input=ui->lineEdit->text();
    if(input==""){
        QMessageBox::warning(this,("error"),("the input can not be empty!!!"),QMessageBox::Ok);
        return ;
    }
    string in=input.toStdString();
    trans(in);
    calculate(ret);
    double res=number.top();
    number.pop();
    QString out;
    if(res-(int)res==0){
        out=QString::number(res);
    }else{
        out=QString::number(res,'f',5);
    }
    ui->lineEdit_2->setText(out);
}
