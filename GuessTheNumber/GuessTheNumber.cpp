#include <string>
#include <iostream>
using namespace std;

// TODO: Separate into separate functions.
int main()
{
	srand(time(NULL));
	int choice;
	do
	{
		// TODO: Add some sort of print function
		cout << "0) Exit\n1) Start Game" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Exiting..." << endl;
			return 0;
		case 1:
			int attempts = 0;
			int random = rand() % 250; // TODO: Add difficulties EASY, MEDIUM, HARD
			while (true)
			{
				attempts += 1;
				cout << to_string(random) << endl;
				cout << "Enter a number between 0 and 250" << endl;
				int guess;
				cin >> guess;
				if (guess == random) {
					printf("You won. It took %i attempts\n", attempts);
					break;
				}
				// TODO: Surely this can be done better
				string output = guess < random ? "Too low." : "Too high.";
				cout << output << endl;
			}
		}
	} while (choice != 0);
}
