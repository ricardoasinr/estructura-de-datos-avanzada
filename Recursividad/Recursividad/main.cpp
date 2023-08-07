//
//  main.cpp
//  Recursividad
//
//  Created by Ricardo Asin on 9/2/23.
//

#include <iostream>
using namespace std;

int fact(int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    cout<<fact(4)<<endl;
    
    
    
    return 0;
}
int fact(int n) {
    if(n>=1){
        
        return n*fact(n-1);
    }
    else {
        return 1;
    }
}

