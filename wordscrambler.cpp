#include <iostream>
#include<cstdlib>

using namespace std;


int random(int a, int b){ //generates random number between a and b
    srand((unsigned) time(NULL));
    
    int random = a + (rand() % b - 1);
    return random;
}

string scramble(string word){ //scrambles given string
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
    const std::string wordlist[50]={"marine", "dimension", "equinox", "robot", "infinite", "dragon", "unity", "judgment", "canadian", "forestry",
                                    "classroom", "rainbow", "hope", "shift", "quest", "elite", "achieve", "loyalty", "legendary", "word",
                                    "goat", "leader", "avenue", "straw", "glue", "offense", "dine", "coal", "minute", "socialist",
                                    "judicial", "gradual", "throne", "hook", "graze", "sermon", "still", "pie", "exemption", "worth",
                                    "queue", "record", "crackpot", "departure", "pawn", "corn", "publisher", "degree", "air", "crime"};
    bool play = true;

    cout << "==============\n"; //Game title
    cout << "Word Scrambler\n";
    cout << "==============\n";

    while(play){ //gameplay loop
        const string word = wordlist[random(0, 49)];
        string next, answer;
        bool isCorrect = false;
        int counter = 1;
        string scrambled = scramble(scramble(scramble(scramble(word))));
        cout << "Unscramble the following word: " << scrambled << "\nYou have 3 guesses.\n";
        cin >> answer;
        while(!isCorrect){
            if(answer == word){
                cout << "That's the right word!\n";
                isCorrect = true;
            }
            else{
                if(counter == 3){
                    cout << "That's incorrect. The unscrambled word was " << word << ".\n";
                    isCorrect = true;
                }
                else{
                    cout << "That's incorrect. Try again!\n";
                    cout << "You have " << 3 - counter << " guesses left.\n";
                    counter++;
                    cin >> answer;
                }                
            }
        }       
        cout << "Play again? Type yes to continue.\n";
        cin >> next;
        if(next != "yes") play = false;
    }    
}
