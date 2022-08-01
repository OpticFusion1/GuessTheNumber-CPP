#include <string>
#include <iostream>
using namespace std;

// Needed? Not really, but it's nice to have.
// Worth checking to make sure there's nothing that can be done in a fucky manner though, e.g. memory related or overflow related or something like that.
template <typename T>
void print(T const* message)
{
	cout << message << endl;
}

// TODO: Separate into separate functions.
int main()
{
	srand(time(NULL));
	int choice;
	do
	{
		print("0) Exit\n1) Start Game");
		cin >> choice;
		switch (choice)
		{
		case 0:
			print("Exiting...");
			return 0;
		case 1:
			int attempts = 0;
			int random = rand() % 250; // TODO: Add difficulties EASY, MEDIUM, HARD
			while (true)
			{
				attempts += 1;
				print("Enter a number between 0 and 250");
				int guess;
				cin >> guess;
				if (guess == random) {
					printf("You won. It took %i attempts\n", attempts);
					break;
				}
				print(guess < random ? "Too low." : "Too high.");
			}
		}
	} while (choice != 0);
}
