#include <iostream>
#include<cstdlib>

using namespace std;


int random(int a, int b){
    srand((unsigned) time(NULL));
    
    int random = a + (rand() % b - 1);
    return random;
}

string scramble(string word){
    int first = 0, last = word.length();
    for(int i = first; i < last; i++){
        int rand = random(1, word.length());
        char index = word[i];
        word[i] = word[rand];
        word[rand] = index;
    }
    return word;
}

int main(){
    std::string wordlist[50]={"marine", "dimension", "equinox", "robot", "infinite", "dragon", "unity", "judgment", "canadian", "forestry",
                              "classroom", "rainbow", "hope", "shift", "quest", "elite", "achieve", "loyalty", "legendary", "word",
                              "goat", "leader", "avenue", "straw", "glue", "offense", "dine", "coal", "minute", "socialist",
                              "judicial", "gradual", "throne", "hook", "graze", "sermon", "still", "pie", "exemption", "worth",
                              "queue", "record", "crackpot", "departure", "pawn", "corn", "publisher", "degree", "air", "crime"};

    bool play = true;
    while(play){
        string word = wordlist[random(0, 49)];
        string next, answer;
        bool isCorrect = false;
        string scrambled = scramble(scramble(scramble(scramble(word))));
        cout << "Unscramble the following word: ";
        cout << scrambled << "\n";
        cin >> answer;
        while(!isCorrect){
            if(answer == word){
                cout << "That's the right word!\n";
                isCorrect = true;
            }
            else{
                cout << "That's incorrect. Try again!\n";
                cin >> answer;
            }
        }
        
        cout << "Play again? Type yes to continue.\n";
        cin >> next;
        if(next != "yes") play = false;
    }
    
}
