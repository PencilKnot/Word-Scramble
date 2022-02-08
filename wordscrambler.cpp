#include <iostream>
#include<cstdlib>

using namespace std;


int random(int a, int b){
    srand((unsigned) time(NULL));
    
    int random = a + (rand() % b - 1);
    return random;
}

string scramble(string word){
    int first=0, last=word.length();
    for(int i=first; i<last; i++){
        int rand=random(1, word.length());
        char index=word[i];
        word[i]=word[rand];
        word[rand]=index;
    }
}

int main(){
    string word;
    cin >> word;
    string scrambled = scramble(scramble(scramble(scramble(word))));
    cout << "Here is a scrambled word: " << scrambled;
}
