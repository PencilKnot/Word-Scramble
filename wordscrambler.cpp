#include <iostream>
#include<cstdlib>

using namespace std;


int random(string word){
    srand((unsigned) time(NULL));
    int length = word.length();

    int random = 1 + (rand() % length - 1);
    return random;
}

string scramble(string word){
    int first=0, last=word.length();
    for(int i=first; i<last; i++){
        int rand=random(word);
        char index=word[i];
        word[i]=word[rand];
        word[rand]=index;
    }
    return word;
}

int main(){
    string word;
    cin >> word;
    string scrambled = scramble(word);
    cout << "Here is a scrambled word: " << scrambled;
}
