#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

// generate a random index in the range [0, b)
int random(int b) {
  srand(time(NULL));
  return (rand() % b); 
}

//Fisher-Yates shuffle algorithm
string scramble(string word) {
  srand(time(NULL));
  int len = word.length();
  for (int i = len - 1; i; --i) {
	  int j = rand() % (i + 1);
	  swap(word[i], word[j]);
  }
  return word;
}

int main() {

    const string wordlist[50] = {"marine", "dimension", "equinox", "robot", "infinite", "dragon", "unity", "judgment", "canadian", "forestry", "classroom", "rainbow", "hope", "shift", "quest", "elite", "achieve", "loyalty", "legendary", "word", "goat", "leader", "avenue", "straw", "glue", "offense", "dine", "coal", "minute", "socialist", "judicial", "gradual", "throne", "hook", "graze", "sermon", "still", "pie", "exemption", "worth", "queue", "record", "crackpot", "departure", "pawn", "corn", "publisher", "degree", "air", "crime"};

    //game title
    cout << "==============\n";
    cout << "Word Scrambler\n";
    cout << "==============\n\n";

    // gameplay loop
    while(1){
        const string word = wordlist[random(50)];
        string next, answer;
        bool isCorrect = false;
        int counter = 3;
        string scrambled = scramble(scramble(scramble(scramble(word))));
        int check = scrambled.compare(word);
        while (check == 0) {
            scrambled = scramble(word);
            check = scrambled.compare(word);
        }
        cout << "Unscramble the following word: " << scrambled << "\nYou have 3 guesses.\n";
        cin >> answer;
	    
	    //check user input
	    while(1) {
		--counter;
		if(answer == word) {
		    cout << "Correct! Well done.\n";
		    break;
	    	}
		if(counter == 0) {
		    cout << "Sorry, you did not get the word. It was: \"" << word << "\".\n";
		    break;
		}
		cout << "Incorrect. You have " << counter << " guesses left. Try again!\n";
		cin >> answer;
	}

	//replay inquiry
        cout << "Play again? Type yes to continue.\n";
        cin >> next;
        if (next != "yes") {
	    break;
    	}
    }

  cout << "Thank you for playing Word Scrambler.\n";

  return 0;    
}
