// TODO: Make sure naming conventions are followed
// TODO: Check to see if any of this can be done better
#include <string>
#include <iostream>
using namespace std;

// Needed? Not really, but it's nice to have.
// TODO: Move to Utils
template <typename T>
void print(T message)
{
	cout << message << endl;
}

// TODO: Move to Utils
void print_array(int array[], int size)
{
	for (int i = 0; i < size; i++) 
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

void play_game()
{
	int attempts = 0;
	int random = rand() % 251; // TODO: Add difficulties EASY, MEDIUM, HARD
	int guesses[251];
	int count = 0;
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
		guesses[count++] = guess;

		if (guess == random) {
			printf("You won. It took %i attempts\n", attempts);
			print("Guesses:\n");
			print_array(guesses, count);
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
