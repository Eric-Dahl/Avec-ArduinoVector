#include <iostream>
#include <string>
#include "Avec.h"

using namespace std;

int main(){
    Avec<int> vec;
    cout << vec.size() << endl;
    for(int i = 0; !vec.isFull(); i++){
        vec.add(i);
        cout << vec.size() << '\t';
    }
    cout << endl;
    for(int i = 0; i <= vec.size(); i++){
        cout << vec[i] << '\t';
    }
    cout << endl;
    while(!vec.isEmpty()){
        vec.remove(0);
    }
    cout << "\n\n\n";
    for(int i = 0; i <= vec.MAX_SIZE; i++){
        cout << vec[i] << endl;
    }
}


