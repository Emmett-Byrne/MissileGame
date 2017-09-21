//Emmett Byrne
//14 - 09 - 17

#include<iostream>
#include<time.h>

void DisplayIntro();
void DisplayTarget();
void missileInput();
void NewTarget();
void getCode();
void inputCode();
void launchMissile();


struct Coordinates
{
	int x;
	int y;
};

struct Missile
{
	int angVerticle;
	int angHorizontal;

	Coordinates blastCoords;

	int amount;
};

struct Target
{
	Coordinates coords;
	Coordinates coordsNear;
};

Missile missile;
Target target;
int code;
bool gameOver = true;

int main() 
{
	srand(time(NULL));
	DisplayIntro();

	do 
	{
		getCode();
		NewTarget();
		DisplayTarget();
		missileInput();
		inputCode();
		launchMissile();

	} while (!gameOver);

	std::cout << target.coords.x << std::endl;
	std::cout << target.coords.y << std::endl;

	std::system("pause");

	return 0;
};

void DisplayIntro()
{
	std::cout << "Welcome to Pew Pew Missiles\nThe objective of the game is to destroy the target given to you\nAfter you've been given your target you have 10 tries to hit it \nTo aim the missile you will have to put in a horizontal and vertical \nangle for the missile to be launched at\nthe missile has a blast radius of 50m" << std::endl;
	std::system("pause");
}

void DisplayTarget()
{
	std::cout << "The target is within 500m of the coordinates x:" << target.coordsNear.x << " y:" << target.coordsNear.y << ".\nYou have " << missile.amount << " missiles remaining. Good luck" << std::endl;
	std::system("pause");
}

void missileInput()
{
	bool valid = true;
	do
	{
		std::cout << "Input a an angle betewwn 0 and 45 for the verticle launch angle." << std::endl;
		std::cin >> missile.angVerticle;

		if (missile.angVerticle < 0 || missile.angVerticle > 45)
		{
			valid = false;
			std::cout << "invalid input" << std::endl;
		}
		else
		{
			valid = true;
		}

	} while (!valid);

	do
	{
		std::cout << "Input a an angle betewwn -45 and 45 for the horizontal launch angle." << std::endl;
		std::cin >> missile.angHorizontal;

		if (missile.angHorizontal < -45 || missile.angHorizontal > 45)
		{
			valid = false;
			std::cout << "invalid input" << std::endl;
		}
		else
		{
			valid = true;
		}

	} while (!valid);
}

void NewTarget()
{
	target.coords.x = rand() % 5000 - 2500;
	target.coords.y = rand() % 5000 + 2500;
	target.coordsNear.x = rand() % 500 - 250 + target.coords.x;
	target.coordsNear.y = rand() % 500 - 250 + target.coords.y;
	missile.amount = 10;
}

void getCode()
{
	code = rand() % 9000 + 1000;
	std::cout << "Here is your launch code,\nyour missile will not launch \nunless this is inputted correctly:\n" << code << std::endl;
	std::system("pause");
}

void inputCode()
{
	bool valid = true;

	do
	{

		int tempCode;
		std::cout << "Please Input launch code to arm missile" << std::endl;
		std::cin >> tempCode;

		if (tempCode == code)
		{
			valid = true;
		}
		else
		{
			valid = false;
			std::cout << "You have entered the wrong code and the missile explodes" << std::endl;
			missile.amount--;
			if (missile.amount <1)
			{
				gameOver = true;
			}
		}
	} while (!valid);

	std::cout << "Missile is now arming" << std::endl;
	system("pause");
	std::cout << "missile is armed" << std::endl;
	system("pause");
}

void launchMissile()
{
	std::cout << "Your missile has now launched" << std::endl;
	missile.blastCoords.x = missile.angVerticle * 166.6;
	missile.blastCoords.y = missile.angHorizontal * 0.02 * missile.blastCoords.x;

}
