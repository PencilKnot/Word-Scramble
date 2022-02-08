#include <iostream>
#include<cstdlib>

using namespace std;


void random(string word){
    srand((unsigned) time(NULL));
    int length = word.length();

    int random = 1 + (rand() % length - 1);
    return random;
}

int main(){
    string word;
    cin >> word;
    cout << random(word);
    cout << "Here is a random number!";
}