//Simple calculator
//v1: Calculation with no space, no negative, 10 digits
//v2: Calculation with no negative, 10 digits, float

#include <iostream>
#include <string>
using namespace std;

void print(string s){
    cout << "------------" << endl;
    cout << '|';
    for(int i = 0; i < 10-s.length(); i++){
        cout << " ";
    }
    cout << s << '|' << endl;
    cout << "------------" << endl;
    cout << "| 1 2 3 |+ |" << endl;
    cout << "| 4 5 6 |- |" << endl;
    cout << "| 7 8 9 |* |" << endl;
    cout << "| . 0   |/ |" << endl;
    cout << "------------" << endl;
}

string parse(string s){
    int a, b; //Integer of number
    string as = "", bs = ""; //String of number
    int opt = s.length();

    for(int i = 0; i < s.length(); i++)
        if(s[i] < '0')
            opt = i;
    
    if(opt == s.length())
        return s;

    as = s.substr(0, opt);
    bs = s.substr(opt+1, s.length()-opt-1);

    a = stoi(as);
    b = stoi(bs);

    switch(s[opt]){
        case '+':
            return to_string(a+b);
        case '-':
            return to_string(a-b);
        case '*':
            return to_string(a*b);
        case '/':
            return to_string(a/b);
        default:
            return as;
    }
    return "";
}

//Calculator for 10 digits
int main(){
    string s;
    bool isValid = true;

    while(1){
        cout << "Enter your calculation with no space and positive number (QUIT to exit): ";
        cin >> s;
        if(s == "QUIT")
            break;

        for(char i:s){
            if((i >= '0' && i <= '9') || i == '+' || i == '-' || i == '*' || i == '/'){
                continue;
            }else{
                cout << "Invalid Input!" << endl;
                isValid = false;
                break;
            }
        }

        if(isValid)
            print(parse(s));            
    }

    return 0;
}