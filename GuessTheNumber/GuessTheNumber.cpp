#include <string>
#include <iostream>
using namespace std;

// Needed? Not really, but it's nice to have.
// Worth checking to make sure there's nothing that can be done in a fucky manner though, e.g. memory related or overflow related or something like that.
// TODO: Move to Utils class
template <typename T>
void print(T message)
{
	cout << message << endl;
}

void init()
{
	srand(time(NULL));
}

void play_game()
{
	int attempts = 0;
	int random = rand() % 250; // TODO: Add difficulties EASY, MEDIUM, HARD
	while (true)
	{
		attempts += 1;
		print("Enter a number between 0 and 250");
		int guess;
		cin >> guess;

		// Makes sure input is an integer
		// TODO: Reject decimal numbers
		while (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			print("Enter a number between 0 and 250");
			cin >> guess;
		}

		guess == guess < 0 ? 0 : guess > 250 ? 250 : guess;

		if (guess == random) {
			printf("You won. It took %i attempts\n", attempts);
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
