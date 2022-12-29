#include <iostream>
using namespace std;

string XOR(string data, string t) {
    string tem = "";
    for(int i=0; i<t.size() ; i++) {

        if(data[i] == t[i]) {
            tem += "0";
        }
        else {
            tem += "1";
        }
    }
    return tem;
}

int main() {

    string data = "100100000";
    cout << "Enter data : ";
    cin >> data;

    string divisor = "1101";
    cout << "Enter CRC generator : ";
    cin >> divisor;

    // adding trailing zeros
    for(int i=0; i< divisor.size()-1; i++) {
        data += '0';
    }

    if(data.size() < divisor.size()) {
        cout << "Enter data correctly" << endl;
    }

    int n=divisor.size();
    string tem = "";

    while(n <= data.size()) {

        // xor operation
        if(tem == "") {
            tem = XOR(data, divisor);
        }
        else {
            tem = XOR(tem, divisor);
        }

        // removing leading '0's
        while(tem[0] == '0') {
            tem = tem.substr(1, tem.size()-1);
        }

        // adding bits from data
        while(tem.size() != divisor.size()) {
            if(n <= data.size())
                tem += data[n++];
            else
                break;
        }
    }

    while(tem.size() != divisor.size()) {
        tem = '0' + tem;
    }

    cout << "CRC code is : " << tem << endl;
}