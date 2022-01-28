#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

/* Function to determine the numeration type */
int IsRxcy(string str);

/* Function to transform a RXCY into the other numeration type*/
string DecomposeRxcy(string str);

/* Function to transform a non RXCY string into an RXCY string */
string DecomposeStr(string str);

int main() {
    string str;
    int i;
    cin >> i;
    while (i > 0){
        cin >> str;
        if (IsRxcy (str)){
            cout << DecomposeRxcy(str) + "\n";
        }else{
            cout << DecomposeStr(str)+ "\n";
        }
        i--;
    }
}

int IsRxcy(string str){
    //regex p("([R]\\d+[C]\\d+)");
    //return regex_match(str,p);
    int size = str.size();
    if (str[0] == 'R' && isdigit(str[1])){
        for (int i = 2; i < size; i++){
            if (str[i] == 'C'){
                return 1;
            }
        }
    }
    return 0;
}

string DecomposeRxcy(string str){
    int i, j, k, rem; 
    int temp = 0;
    string sub_str, dec_str;
    i = str.find('C');
    sub_str = str.substr(i + 1, str.size() - i);
    i = sub_str.size();
    j = 0;
    while (j < i ){
        k = (int)sub_str[j] - 48;
        temp += k * pow(10, (i-1) - j);
        j++;
    }
    i = str.find('C');
    dec_str = "";
    sub_str = str.substr(1, i - 1 );
    while (temp != 0){
        rem = temp % 26;
        if (rem == 0){
            dec_str = "Z" + dec_str;
            temp /= 26;
            temp--;
        }else{
            dec_str = (char) (rem + '@') + dec_str;
            temp /= 26;
        }
    }
    return dec_str + sub_str;
}

string DecomposeStr(string str){
    int i, j, num_temp;
    i = 0;
    string dec_str, sub_str;
    while(!isdigit(str[i])){
        i++;
    }
    dec_str = "R" + str.substr(i, str.size() -1) + "C"; 
    sub_str = str.substr(0, i);
    j = sub_str.size();
    i = 0;
    num_temp = 0;
    while (i < j){
        num_temp += ((int) sub_str[i] - 64) * pow(26, (j - 1) - i);
        i++;
    }
    dec_str = dec_str + to_string(num_temp);
    return dec_str;
}