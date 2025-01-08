#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    
    srand(static_cast<unsigned int>(time(0)));

    int number_to_guess = rand() % 100 + 1;

    int user_guess = 0;
    
    cout << "Welcome! the Guess the Number game:-" << endl;
    cout << "I have picked a number between 1 and 100. Try to guess it!" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> user_guess;

        if (user_guess < number_to_guess) {
            cout << "Your guess is too low. Try again!" << endl;
        } else if (user_guess > number_to_guess) {
            cout << "Your guess is too high. Try again!" << endl;
        } else {
            cout << "Congratulations! You've guessed the number " << number_to_guess << " correctly!" << endl;
            break;
        }
    }

    return 0;
}

