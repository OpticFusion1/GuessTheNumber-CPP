// TODO: Make sure naming conventions are followed
// TODO: Check to see if any of this can be done better
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;

// Needed? Not really, but it's nice to have.
// TODO: Move to Utils
template <typename T>
void print(T message)
{
	cout << message << endl;
	cout.clear();
	cout.flush();
}

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
			print("Enter a number between 0 and 250");
			cin >> guess;
		}

		guess == guess < 0 ? 0 : guess > 250 ? 250 : guess;
		// TODO: Add logic to enforce no duplications
		guesses.push_back(guess);

		if (guess == random) {
			printf("You won. It took %i attempts\n", attempts);
			print("Guesses:\n");
			print_vector(guesses);

			// TODO: Add the ability to store multiple best scores w/ names
			// TODO: Clean up code
			// e.g. TODD: 10\nJILL: 1\nJosh: 5
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
				printf("Saving due to new game. Current best score is %i", attempts);
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
