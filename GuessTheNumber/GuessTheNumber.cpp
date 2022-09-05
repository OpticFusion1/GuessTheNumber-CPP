// TODO: Make sure naming conventions are followed
// TODO: Check to see if any of this can be done better
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "Utils.cpp"

using namespace std;

// TODO: Move to Utils
void print_vector(vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		// TODO: Make the output nicer. Perhaps support something like cout << array[i] << "\t" within print
		cout << array[i] << "\t"; // Temporary until replaced
//		print(to_string(array[i]) + "\t");
	}
	print("\n");
}

// TODO: Move this into a GuessManager class. Said class would include is_already_guessed, add_guess, and get_guesses functions.
// This GuessManager would also handle getting/setting the best score, if the current score is better than the best score and general guess managery things
bool is_already_guessed(vector<int> guesses, int guess)
{
    if (guesses.empty()) {
        return false;
    }
    for (int i =0; i < guesses.size(); i++) 
    {
        if (guesses[i] == guess)
        {
            return true;
        }
    }
    return false;
}

void init()
{
	srand(time(NULL));
}

void createfile(string name)
{
	ofstream file(name);
	file.close();
}

void play_game()
{
	string filename = "best_score.txt";
	bool newgame = false;
	
	if (!filesystem::exists(filename))
	{
		createfile(filename);
		newgame = true;
	}

	int attempts = 0;
	int random = rand() % 251; // TODO: Add difficulties EASY, MEDIUM, HARD
	print(random);
	vector<int> guesses;
	while (true)
	{
		attempts += 1;
		print("Enter a number between 0 and 250");
		int guess;
		cin >> guess;

		// Makes sure input is an integer
		// TODO: Reject decimal numbers
		// TODO: Move to Utils and abstract away if possible
		while (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			print("Enter a number between 0 and 250\n");
			cin >> guess;
		}

		guess == guess < 0 ? 0 : guess > 250 ? 250 : guess;

        if (is_already_guessed(guesses, guess))
        {
            printf("You already guessed the number %i\n", guess);
            continue;
        }
		guesses.push_back(guess);

		if (guess == random) {
			printf("You won. It took %i attempts\n", attempts);
			print("Guesses:\n");
			print_vector(guesses);

			// TODO: Add the ability to store multiple best scores w/ names
			// e.g. TODD: 10\nJILL: 1\nJosh: 5. This should be part of the GuessManager class
			// TODO: Clean up code
			ifstream input("best_score.txt");

			if (!input.is_open()) 
			{
				print("Unable to read file\n");
				return;
			}

			int best_score = 9999;
			
			if (!newgame)
			{
				input >> best_score;
			}

			ofstream output("best_score.txt");

			if (!output.is_open())
			{
				print("Unable to read file\n");
				return;
			}

			if (newgame)
			{
				printf("Saving due to new game. Current best score is %i\n", attempts);
				output << attempts;
				return;
			}

			if (attempts < best_score)
			{
				printf("New best score achieved!\nOld Best Score %i!\nNew Best Score %i!\n", best_score, attempts);
				output << attempts;
			}
			break;
		}

		print(guess < random ? "Too low." : "Too high.");
	}
}

void main_menu()
{
	int choice;
	do
	{
		print("0) Exit\n1) Start Game");
		cin >> choice;
		switch (choice)
		{
		case 0:
			print("Exiting...");
			exit(0);
		case 1:
			play_game();
		}
	} while (choice != 0);
}

int main()
{
	init();
	main_menu();
}
