#include <iostream>
#include <string>

using namespace std;


int main() {
    int numbers[10][10];
    int num = 1;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            numbers[i][j] = num;
            num++;
            cout << numbers[i][j] << " ";
        }
        cout << endl;
    }

    

    
}