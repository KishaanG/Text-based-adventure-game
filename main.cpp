/*

	Author: Kishaan Gidda
	Description: A choose your own adventure story (made on replit)
	Last modified: 28 January, 2022

*/

/// ================= Pre-processor commands ============================

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

/// ================= Structures ============================

struct Character {
	string name;
	string jobChoice;
	int luck;
	int intelligence;
	int awareness;
	int athleticism;
};

struct Items {
	int money;
	bool waterBottle = false;
	bool maze = false;
	bool numLock = false;
	bool frames = false;
	bool letterLock = false;
	bool soccerBall = false;
	bool rope = false;
};

/// ================= Prototypes ============================

void initialize(Character &, string, string, int, int, int, int);

void display(Character &);

void keyToContinue();

/// ======== Main menu =========

void mainMenuCase(Character &, int, Items &);

int menu(string, string[], int, string);

/// ======== name =========

void userNameMenu(string &);

/// ======== job =========

void userJobMenu(string &, int &);

/// ======== attributes =========

void randomAttributeNumber(int &, int, int);

void statMaker(
	int &,
	int &,
	int &,
	int &,
	int,
	int,
	int,
	int,
	int,
	int,
	int,
	int);

void statDisplay(int, int, int, int);

void statsReroll(int &, int &, int &, int &, int, int);

/// ============== Game ==============

int gameIntro(Items &);
bool statChecker(int, int, int, int, int, int, int, int);
bool loseMoney(Items &, int);
void gameMenu(Items &, Character &);
int cairoAirport(Items &, Character &, int &);
int thePyramid(Items &, Character &);
int sideOfRoad(Items &, Character &);
int taxiSideOfRoad(Items &, Character &);
int hitchhikeSideOfRoad(Items &, Character &);
int sneakAround(Items &, Character &);
int inPyramid(Items &, Character &);
int findWayOut(Items &, Character &);
int useLuck(Items &, Character &);
int useIntelligence(Items &, Character &);
int useAwareness(Items &, Character &);
int useAthleticism(Items &, Character &);
int room1(Items &, Character &);
int room2(Items &, Character &);
void ballMaze(Items &, Character &);
void numberLock(Items &, Character &);
void wallFrames(Items &, Character &);
void hint(Items &, Character &);
bool mazeGame(string[], char, int &, int, int, int, int, Items &);
void letterLock(Items &, Character &);
int finalRoom(Items &, Character &);
void statIncrease(Character &, int, int, string, string);
int inPrison(Items &, Character &);
int breakingOut(Items &, Character &);
int ventCrawl(Items &, Character &);
int midnight(Items &, Character &);
int leavePyramid(Items &, Character &);
int outOfPyramid(Items &, Character &);
int stuckInPyramid(Items &, Character &);
bool lookAround(Items &, Character &, int &);

/// ================= Definitions ============================

void keyToContinue() {
	cout << "Type any key to continue" << endl;
	getchar();
	getchar();
	system("clear");
	return;
}

/// ======== Display / initialize ============

void initialize(
	Character &guy,
	string _userName,
	string _userJob,
	int _luck,
	int _intelligence,
	int _awareness,
	int _athleticism) {
	guy.name = _userName; /// This is used to set the varaibles of the Character
						  /// structure
	guy.jobChoice = _userJob;
	guy.luck = _luck;
	guy.intelligence = _intelligence;
	guy.awareness = _awareness;
	guy.athleticism = _athleticism;
}

void display(Character &guy) {
	cout << "Username: " << guy.name
		 << endl; /// This displays the variables of the Character structure
	cout << "Your job: " << guy.jobChoice << endl;
	cout << "Your luck: " << guy.luck << endl;
	cout << "Your intelligence: " << guy.intelligence << endl;
	cout << "Your awareness: " << guy.awareness << endl;
	cout << "Your athleticism: " << guy.athleticism << endl;
}

/// ======== main menu =========

int menu(
	string prompt,
	string options[],
	int numberOfOptions,
	string errorMsg) {
	int response; /// This is a menu to display questions and get the response
				  /// of the user
	do {
		cout << prompt << endl;
		for (int i = 0; i < numberOfOptions; i++) {
			cout << i + 1 << ") " << options[i] << endl;
		}
		cin >> response;
		if (response < 1 or response > numberOfOptions) {
			cout << errorMsg << endl;
			keyToContinue();
		}
	} while (response < 1 or response > numberOfOptions);
	return response;
}

void userMainMenuCase(Character &guy, int difficulty, Items &guyItems) {
	guyItems.money = 4000; /// I give the variable money in the structure Items
						   /// a value of 4000
	string menuPrompt =
		"Welcome to a choose your own adventure game. What would you like to:";
	string errorMessage = "That is not a valid choice.";
	int userChoice = 0;
	string menuOptions[3] = {
		"Choose your username", "Choose a job", "See all your details"};
	userChoice = menu(menuPrompt, menuOptions, 3, errorMessage);
	bool userNameDone = false;
	bool userJobDone = false;
	string userJob = "";
	int userJobNumber = 0;
	string userNameChoice = "";
	int luckStat = 0;
	int intelligenceStat = 0;
	int awarenessStat = 0;
	int athleticismStat = 0;

	do { /// This will be the first menu when the character is being made

		switch (userChoice) {
		case 1:
			system("clear");
			userNameMenu(userNameChoice);
			userNameDone = true;
			keyToContinue();
			break;

		case 2:
			system("clear");
			userJobMenu(userJob, userJobNumber);
			userJobDone = true;
			keyToContinue();
			break;

		case 3:
			system("clear");
			initialize(
				guy,
				userNameChoice,
				userJob,
				luckStat,
				intelligenceStat,
				awarenessStat,
				athleticismStat);
			display(guy);
			keyToContinue();
			break;

		default:
			system("clear");
			cout << "That wasn't one of the options. " << endl;
			keyToContinue();
			break;
		}

		if (userNameDone == false or userJobDone == false) {
			userChoice = menu(menuPrompt, menuOptions, 3, errorMessage);
		} else if (userNameDone == true and userJobDone == true) {
			string menuPrompt1 =
				"What would you like the difficulty level to be?";
			string options1[2] = {
				"Normal",
				"Hard, your stats are reduced by 10 and money amount is "
				"reduced from $4000 to $3000"};

			difficulty = menu(
				menuPrompt1,
				options1,
				2,
				errorMessage); /// This determins what difficulty the user wants
			if (difficulty == 2) {
				guyItems.money -= 1000;
			}

			srand(time(NULL));
			statsReroll(
				luckStat,
				intelligenceStat,
				awarenessStat,
				athleticismStat,
				userJobNumber,
				difficulty); /// This will get the stats of the character
			initialize(
				guy,
				userNameChoice,
				userJob,
				luckStat,
				intelligenceStat,
				awarenessStat,
				athleticismStat); /// This initializes the character
			display(guy);		  /// Then this displays the character
		}

	} while (userNameDone == false or userJobDone == false);

	return;
}

/// ======== username =========

void userNameMenu(string &userName) { /// This gets the username
	userName = "";
	cout << "Enter your username (preferably something simple and easy to "
			"remember): "
		 << endl;
	cin >> userName;
	return;
}

/// ======== job =========

void userJobMenu(
	string &userJobName,
	int &userJob) { /// This gets the job they choose
	userJobName = "";
	string menuPrompt = "Would you like to be:";
	string errorMessage = "Please type either '1', '2', or '3'.";
	string menuOptions[3] = {"An engineer has a balanced chance at each stat",
							 "An athlete has better chances in athleticism and "
							 "awareness but worse in intelligence",
							 "A doctor has better chances at intelligence and "
							 "luck but worse at athleticism"};

	string jobs[3] = {"Engineer", "Athlete", "Doctor"};
	userJob = menu(menuPrompt, menuOptions, 3, errorMessage);
	userJob -= 1;

	userJobName = jobs[userJob];

	return;
}

/// ======== stats =========

void randomAttributeNumber(
	int &randNumStorage,
	int lengthOfInterval,
	int startOfInterval) { /// This generates a random number
	randNumStorage = rand() % lengthOfInterval +
		startOfInterval; /// This makes a random number
	return;
}

void statMaker(
	int &characterLuck,
	int &characterIntelligence,
	int &characterAwareness,
	int &characterAthleticism,
	int lengthOfInterval,
	int startOfInterval,
	int lengthOfInterval1,
	int startOfInterval1,
	int lengthOfInterval2,
	int startOfInterval2,
	int lengthOfInterval3,
	int startOfInterval3) { /// This sets the attributes for each stat
	randomAttributeNumber(
		characterLuck, lengthOfInterval, startOfInterval); /// Luck stat
	randomAttributeNumber(
		characterIntelligence,
		lengthOfInterval1,
		startOfInterval1); /// Intelligence stat
	randomAttributeNumber(
		characterAwareness,
		lengthOfInterval2,
		startOfInterval2); /// Awareness stat
	randomAttributeNumber(
		characterAthleticism,
		lengthOfInterval3,
		startOfInterval3); /// Athleticism stat
	return;
}

void statDisplay(
	int characterLuck,
	int characterIntelligence,
	int characterAwareness,
	int characterAthleticism) { /// This is used if I want to only display stats
	cout << "Your luck is: " << characterLuck << endl;
	cout << "Your intelligence is: " << characterIntelligence << endl;
	cout << "Your awareness is: " << characterAwareness << endl;
	cout << "Your athleticism is: " << characterAthleticism << endl;
	return;
}

void statsReroll(
	int &luck,
	int &intelligence,
	int &awareness,
	int &athleticism,
	int job,
	int difficulty) {
	int userRepeat = 0;
	do {
		if (job == 0) /// Engineer
		{
			statMaker(
				luck,
				intelligence,
				awareness,
				athleticism,
				30,
				60,
				30,
				60,
				25,
				60,
				35,
				50); /// The numbers give different odds in each stat depending
					 /// on the job
		} else if (job == 1) /// Athlete
		{
			statMaker(
				luck,
				intelligence,
				awareness,
				athleticism,
				30,
				60,
				55,
				30,
				14,
				85,
				9,
				90);
		} else if (job == 2) /// Doctor
		{
			statMaker(
				luck,
				intelligence,
				awareness,
				athleticism,
				14,
				85,
				9,
				90,
				30,
				60,
				55,
				30);
		}

		if (difficulty ==
			2) /// If they chose the harder difficulty, this decreases the stats
		{
			luck -= 10;
			intelligence -= 10;
			awareness -= 10;
			athleticism -= 10;
		}
		statDisplay(luck, intelligence, awareness, athleticism);

		do { /// This will redo the entire function if they want new stats
			cout << "Would you like new random stats? '1' for yes, '2' to "
					"continue. "
				 << endl;
			cin >> userRepeat;
			if (userRepeat > 2 or userRepeat < 1) {
				cout << "Please type either '1' or '2'. " << endl;
			}

		} while (userRepeat > 2 or userRepeat < 1);

		system("clear");

	} while (userRepeat == 1);
}

/// ================================== Game ==================================

void statIncrease(
	Character &guy,
	int highestNum,
	int increaseNum,
	string statToIncrease,
	string
		prompt) { /// This will increase stats but never let them get above 99
	if (statToIncrease == "awareness") {
		if (guy.awareness >=
			highestNum) { /// If the stat is more than the highest number that
						  /// doesn't give above 99, this sets the stat to 99
						  /// rather than above 99.
			cout << prompt << guy.awareness << " --> 99" << endl;
			guy.awareness = 99;
		} else { /// This will add the amount increase I decided as long as it
				 /// doesn't go above 99.
			cout << prompt << guy.awareness << " --> "
				 << guy.awareness + increaseNum << ".\n";
			guy.awareness += increaseNum;
		}
	} else if (statToIncrease == "intelligence") {
		if (guy.intelligence >= highestNum) {
			cout << prompt << guy.intelligence << " --> 99" << endl;
			guy.intelligence = 99;
		} else {
			cout << prompt << guy.intelligence << " --> "
				 << guy.intelligence + increaseNum << ".\n";
			guy.intelligence += increaseNum;
		}
	} else if (statToIncrease == "athleticism") {
		if (guy.athleticism >= highestNum) {
			cout << prompt << guy.athleticism << " --> 99" << endl;
			guy.athleticism = 99;
		} else {
			cout << prompt << guy.athleticism << " --> "
				 << guy.athleticism + increaseNum << ".\n";
			guy.athleticism += increaseNum;
		}
	} else if (statToIncrease == "luck") {
		if (guy.luck >= highestNum) {
			cout << prompt << guy.luck << " --> 99" << endl;
			guy.luck = 99;
		} else {
			cout << prompt << guy.luck << " --> " << guy.luck + increaseNum
				 << ".\n";
			guy.luck += increaseNum;
		}
	}

	return;
}

bool statChecker(
	int highestNum,
	int middleNum,
	int smallNum,
	int highNumChance,
	int mediumNumChance,
	int smallNumChance,
	int lowestNumChance,
	int stat) { /// This will give different odds out for returning true or
				/// false depending on the stat's value

	int randNum = 0;

	if (stat >= highestNum) { /// This makes the odds for the highest number
		randomAttributeNumber(randNum, 100, 1);
		if (randNum <= highNumChance) {
			return true;
		} else {
			return false;
		}

	} else if (stat >= middleNum) {
		randomAttributeNumber(randNum, 100, 1);
		if (randNum <= mediumNumChance) {
			return true;
		} else {
			return false;
		}
	} else if (stat >= smallNum) {
		randomAttributeNumber(randNum, 100, 1);
		if (randNum <= smallNumChance) {
			return true;
		} else {
			return false;
		}
	} else {
		randomAttributeNumber(randNum, 100, 1);
		if (randNum <= lowestNumChance) {
			return true;
		} else
			return false;
	}
}

bool loseMoney(
	Items &guyItems,
	int subtractAmount) { /// This will subtract money only if they have enough
						  /// money
	if (guyItems.money - subtractAmount >= 0) {
		guyItems.money -= subtractAmount;
		cout << "You have: $" << guyItems.money << " left. " << endl;
		return true;
	} else {
		cout << "You don't have enough money. You have: $" << guyItems.money
			 << " left. " << endl;
		keyToContinue();
		return false;
	}
}

bool mazeGame(
	int maze[],
	string keyToPress,
	int &playerPos,
	int directionAdd,
	int mazeSize,
	int endPos) { /// This is the logic behind the maze game used 2 times in the
				  /// story. It can work with any size maze as long as it is a
				  /// square maze.
	int storage = 0;
	int sqrtMazeSize = sqrt(mazeSize);

	if (keyToPress == "U") /// This prevents them from going above the maze
	{
		if (playerPos - sqrt(mazeSize) < 0)
			return false;
	}

	if (keyToPress == "U" or
		keyToPress == "L") /// Going left and up in a maze require subtracting
	{
		if (maze[playerPos - directionAdd] ==
			0) /// Direction add depends on whether they go left or up, if they
			   /// go left, I only subtract 1 to see if the space to the left of
			   /// the player in the array is a 0
		{ /// If it is a 0, I move the player there
			storage = playerPos;
			maze[playerPos - directionAdd] = 9;
			playerPos -= directionAdd;
			maze[storage] = 0;
			if (playerPos == endPos) {
				return true;
			}
			system("clear");
			for (int i = 0; i < mazeSize; i++) {
				cout << maze[i];
				cout << "  ";
				if ((i + 1) % sqrtMazeSize == 0) {
					cout << endl;
				}
			}
		}
	} else {
		if (maze[playerPos + directionAdd] == 0) {
			storage = playerPos;

			maze[playerPos + directionAdd] = 9;
			playerPos += directionAdd;
			maze[storage] = 0;

			system("clear");
			for (int i = 0; i < mazeSize; i++) {
				cout << maze[i];
				cout << "  ";
				if ((i + 1) % sqrtMazeSize == 0) {
					cout << endl;
				}
				if (playerPos == endPos) {
					return true;
				}
			}
		}
	}
	return false;
}

int gameIntro(Items &guyItems) {
	bool moneySpent;
	string menuPrompt = "Do you buy the plane ticket to search for the ball? ";
	string errorMessage = "Type either 1 or 2.";
	int userChoice = 0;
	string menuOptions[2] = {"Yes", "No"};

	cout << "Legend has it, there is a priceless soccer ball made completely "
			"out of diamonds. It is known to be hidden somewhere in the great "
			"pyramid of Giza. The plane ticket to get from Ottawa to Cairo is "
			"$2000, you have $"
		 << guyItems.money << ". " << endl;

	userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);

	if (userChoice == 1) /// If they go on the flight they spend 2 000, I don't
						 /// use the loseMoney function because the player has
						 /// to be able to afford the flight
	{
		guyItems.money -= 2000;
		return 1;
	} else {
		cout << "You played it safe and didn't risk your money. "
			 << endl; /// This immidiately ends the game
		return 99;
	}
}

int cairoAirport(Items &guyItems, Character &guy, int &counter) {
	bool affordable = false;
	int userChoice = 0;
	bool luckCheck = false;
	int randNum = 0;
	int userWaterChoice = 0;
	string menuPrompt = "Which taxi do you choose? ";
	string menuPrompt1 =
		"While in the taxi, the driver offers you a 1 litre water bottle for "
		"the low price of $30, do you buy it?";
	string errorMessage1 = "Type either 1 or 2";
	string menuOptions1[2] = {"Yes", "No"};
	string errorMessage = "Type either 1, 2, 3, or 4.";
	string menuOptions[3] = {
		"A rusty old chevy that costs $100 for the drive and you need to be "
		"very lucky for it not to break down",
		"A somewhat new Ford that costs $200 for the drive and is pretty "
		"unlikely to break down",
		"A modern new BMW that costs $400 for the drive and won't break down"};
	if (counter == 0) { /// If it is the first time they got to tis location:
		cout << "At the Cairo airport there are many taxis waiting for you "
				"that you can take. "
			 << endl;
		counter++;
	}

	userChoice = menu(menuPrompt, menuOptions, 3, errorMessage);
	keyToContinue();

	affordable = false;

	if (userChoice == 1) /// Car 1
	{
		affordable = loseMoney(guyItems, 100);

		if (affordable) {
			cout << "You take the Chevy" << endl;

			userWaterChoice = menu(menuPrompt1, menuOptions1, 2, errorMessage1);
			if (userWaterChoice == 1) {
				affordable = loseMoney(guyItems, 30);
				if (affordable) {
					guyItems.waterBottle = true;
				}
			}

			luckCheck = statChecker(
				90,
				75,
				50,
				20,
				15,
				10,
				5,
				guy.luck);   /// This generates different odds of returning true
							 /// depending on the luck stat
			if (luckCheck) { /// If true:
				statIncrease(
					guy,
					90,
					10,
					"luck",
					"You got lucky your car didn't break down, and your luck "
					"increases from ");
				return 2;
			} else {
				return 3;
			}
		} else {
			cout << "You can't afford a car and are forced to return to Ottawa."
				 << endl;
			return 99;
		}
	} else if (userChoice == 2) /// Car 2
	{
		affordable = loseMoney(guyItems, 200);

		if (affordable) {
			cout << "You take the Ford." << endl;
			userWaterChoice = menu(menuPrompt1, menuOptions1, 2, errorMessage1);
			if (userWaterChoice == 1) {
				affordable = loseMoney(guyItems, 30);
				if (affordable) {
					guyItems.waterBottle = true;
				}
			}
			luckCheck = statChecker(85, 75, 50, 10, 20, 40, 50, guy.luck);
			if (luckCheck == false) {
				statIncrease(
					guy,
					95,
					5,
					"luck",
					"You got pretty lucky, that your car didn't break down, "
					"and your luck increases from ");
				return 2;
			} else {
				return 3;
			}
		} else {
			cout << "You can't afford the ford car." << endl;
			return 1;
		}
	} else /// Car 3
	{
		affordable = loseMoney(guyItems, 400);
		if (affordable) {
			statIncrease(
				guy,
				95,
				5,
				"awareness",
				"You were aware the risk of the two other cars and chose "
				"safety, so your awareness increases from ");
			return 2;
		} else {
			cout << "The BMW is too expensive. " << endl;
			return 1;
		}
	}
}

int sideOfRoad(Items &guyItems, Character &guy) {
	int userChoice = 0;
	string menuPrompt =
		"Do you chose to wait for a new taxi, or try to hitchhike? ";
	string errorMessage = "Type either 1 or 2";
	string menuOptions[2] = {"Taxi", "Hitch hike"};

	cout << "The car breaks down and you're stranded to walk by yourself while "
			"the taxi driver goes somewhere else looking for a mechanic. After "
			"hours of walking you become dehydrated from the heat and need "
			"water..."
		 << endl;
	if (guyItems.waterBottle ==
		false) { /// If they didn't buy the water bottle, the game is over
		cout << "However, you start to regret not buying the water bottle and "
				"slowly die on the side of the road."
			 << endl;
		return 99;
	}
	cout << "Luckily, you remember you bought a water bottle from the taxi "
			"driver and start drinking. ";

	statIncrease(
		guy,
		90,
		10,
		"intelligence",
		"Your smart decision made your intelligence increase from ");

	guyItems.waterBottle = false;
	userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);
	if (userChoice == 1) {
		return 4;
	} else {
		return 5;
	}
}

int taxiSideOfRoad(Items &guyItems, Character &guy) {
	bool affordable = false;
	int userChoice = 0;
	bool awareTrueOrFalse;
	string menuPrompt =
		"Do you pay for the taxi, or try to hitch hike instead? ";
	string errorMessage = "Type either 1 or 2";
	string menuOptions[2] = {"Take the taxi -$200", "Hitch hike instead"};

	awareTrueOrFalse =
		statChecker(90, 75, 55, 100, 90, 80, guy.awareness, guy.awareness);

	if (awareTrueOrFalse) {
		cout << "As you start running low on water, your awareness kicks in "
				"and you finally see a taxi and call for it. However, the "
				"driver was just ending his shift and is asking for double the "
				"normal cost, costing you $200 for the ride. ";
		userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);
		if (userChoice == 1) {
			statIncrease(
				guy,
				90,
				10,
				"awareness",
				"Due to your sharp awareness to spot the cab, your awareness "
				"increased from ");

			affordable = loseMoney(guyItems, 200);
			if (affordable) {
				return 2;
			} else {
				return 5;
			}
		}
	}

	return 5;
}

int hitchhikeSideOfRoad(Items &guyItems, Character &guy) {
	int userChoice = 0;
	int userQuizChoice = 0;
	bool intelligenceChance = false;
	string menuPrompt = "What is 3/7 chicken, 2/3 cat, and 2/4 goat? ";
	string errorMessage = "Type either 1, 2, 3, or 4";
	string menuOptions[4] = {"Chiffon", "Changsha", "A dog", "Chicago"};
	cout << "You start hitchhiking and find someone willing to pick you up "
			"right away but you can only enter if you are smart enough either "
			"with high enough intelligence or being able to solve his riddle. ";
	userQuizChoice = menu(menuPrompt, menuOptions, 4, errorMessage);
	if (userQuizChoice == 4) { /// If they get the right answer:
		cout << "You were right! He let you in for the ride and brought you "
				"straight to your destination. "
			 << endl;
		statIncrease(
			guy, 95, 5, "intelligence", "Your intelligence increased from ");

		return 2;
	}
	intelligenceChance =
		statChecker(90, 75, 60, 70, 60, 50, 40, guy.intelligence);
	if (intelligenceChance) {
		cout << "You got the riddle wrong, however, the driver thinks you're "
				"smart enough and lets you in. "
			 << endl;
		return 2;
	} else {
		cout << "The driver didn't think you were smart enough and drove off "
				"leaving you in the dust and you get lost in the middle of "
				"nowhere and slowly die. "
			 << endl;
		return 99;
	}
}

int thePyramid(Items &guyItems, Character &guy) {
	bool affordable;
	string menuPrompt = "There are only two ways to make it into the pyramid, "
						"paying the guards that are asking $1200 or sneaking "
						"around them. Which do you choose?";
	string errorMessage = "Type either 1 or 2.";
	int userChoice = 0;
	string menuOptions[2] = {
		"Pay off the guards (- $1200)", "Try to sneak around them"};
	cout << "You finally arrive at the pyramid and see lots of security "
			"protecting it."
		 << endl;
	userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);

	if (userChoice == 1) {
		affordable = loseMoney(guyItems, 1200);
		if (affordable) { /// If they can pay, they go straight to the pyramid
			return 6;
		} else { /// Otherwise they go sneak around
			return 7;
		}

	} else {
		return 7;
	}
}

int sneakAround(Items &guyItems, Character &guy) {
	string menuPrompt = "Do you go to jail or try to make it past the guard? ";
	string errorMessage = "Type either 1 or 2.";
	int userChoice = 0;
	string menuOptions[2] = {"Go to jail", "Find a way out"};
	bool athleticismTrueOrFalse;
	cout << "You start looking around for another way in...\nYou notice that "
			"on the other side of the pyramid, there is little to no security "
			"since visitors are not allowed there. As you start heading over a "
			"security guard looks in your direction. You start sprinting to "
			"stay out of sight, edging closer and closer to the other side."
		 << endl;
	keyToContinue();

	athleticismTrueOrFalse = statChecker(
		90,
		70,
		50,
		60,
		45,
		30,
		25,
		guy.athleticism); /// This generates odds based on guy's athleticism
	if (athleticismTrueOrFalse) { /// If true:
		cout << "Your athleticisim pays off and you hide behind the pyramid on "
				"the other side, unnoticed."
			 << endl;
		return 6;
	}

	cout << "As soon as you feel safe on the other side, you hear a guard "
			"shouting at you. He confronts you, threatening to send you to "
			"jail. ";

	userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);
	if (userChoice == 1) {
		return 16;
	} else {
		return 8;
	}
}

int findWayOut(Items &guyItems, Character &guy) {
	string menuPrompt = "Which stat do you chose to use?";
	string errorMessage = "Type either 1, 2, 3, or 4.";
	int userChoice = 0;
	string menuOptions[4] = {
		"Luck", "Intelligence", "Awareness", "Athleticism"};

	cout << "You start thinking about what your strongest stats are and how "
			"you can use them to your advantage. "
		 << endl;
	statDisplay(guy.luck, guy.intelligence, guy.awareness, guy.athleticism);

	userChoice = menu(menuPrompt, menuOptions, 4, errorMessage);
	if (userChoice == 1) /// Luck
	{
		return 9;
	} else if (userChoice == 2) /// Intelligence
	{
		return 10;
	} else if (userChoice == 3) /// Awareness
	{
		return 11;
	} else /// Athleticism
	{
		return 12;
	}
}

int useLuck(Items &guyItems, Character &guy) {
	bool luckTrueOrFalse = false;
	cout << "You decide luck is your strongest stat. Your plan is simple, do a "
			"coin flip with the security guard to decide whether you can stay "
			"or have to go to jail. The guard agrees only if he gets to call "
			"the side. The guard calls heads. "
		 << endl;

	luckTrueOrFalse = statChecker(
		90,
		70,
		51,
		100,
		guy.luck,
		guy.luck,
		50,
		guy.luck); /// This generates different odds depending on the variable
				   /// guy.luck
	if (luckTrueOrFalse) { /// If the odds return true:
		cout << "You flip the coin, you have an instinctual feeling that it "
				"will land tails. The coin lands and it's tails! Your luck "
				"saved you this time."
			 << endl;
		return 6;
	} else { /// If the odds return false:
		cout << "Your luck runs out and the coin lands heads, landing you in "
				"jail only to be sent back to Ottawa and banning you from "
				"returning to Egypt. "
			 << endl;
		return 16;
	}
}

int useIntelligence(Items &guyItems, Character &guy) {
	bool intTrueOrFalse;
	cout << "You decide intelligence is your strongest stat. Your plan is to "
			"outsmart the police officer since you studied the ins and outs of "
			"the laws in Egypt. "
		 << endl;

	intTrueOrFalse = statChecker(
		90,
		80,
		65,
		100,
		guy.intelligence,
		guy.intelligence,
		guy.intelligence,
		guy.intelligence);
	if (intTrueOrFalse) {
		cout << "You start using your lawyering skills. You see that your "
				"words are truly confusing the officer by the look on his "
				"face. He ends up agreeing to let you on the other side but "
				"you're only awarded five minutes total. "
			 << endl;
		return 6;
	} else {
		cout << "As you try outsmarting, he cuts you off abruptly while "
				"laughing and tells you you're going to jail. "
			 << endl;
		return 16;
	}
}

int useAwareness(Items &guyItems, Character &guy) {
	bool awarenessTrueOrFalse;
	cout << "You decide awareness is your strongest stat. Your plan is simple, "
			"dupe the officer and sneak away from him while he's distracted. "
		 << endl;

	awarenessTrueOrFalse = statChecker(
		90,
		70,
		51,
		100,
		guy.awareness,
		guy.awareness,
		guy.awareness,
		guy.awareness);
	if (awarenessTrueOrFalse) {
		cout << "You tell him that you see a person driving a crane using a "
				"wrecking ball that is about to hit the pyramid. As he looks "
				"around to see whatever your talking about, you quickly run "
				"and hide. Somehow he believed you and you go unnoticed. "
			 << endl;
		return 6;
	} else {
		cout << "You tell him that you see a person driving a crane using a "
				"wrecking ball that is about to hit the pyramid. However, he "
				"knows that's an obvious lie and sends you to jail. "
			 << endl;
		return 16;
	}
}

int useAthleticism(Items &guyItems, Character &guy) {
	bool athleticismTrueOrFalse;
	cout << "You decide athleticism is your strongest stat. Your know your "
			"plan and immidiately put it into action. You grab a football and "
			"give it to the officer and then start running pretending like "
			"your a wide-reciever. "
		 << endl;

	athleticismTrueOrFalse = statChecker(
		90,
		70,
		51,
		100,
		guy.athleticism,
		guy.athleticism,
		guy.athleticism,
		guy.athleticism);
	if (athleticismTrueOrFalse) {
		cout << "You make a hail mary run and he throws you a dime, completely "
				"forgetting that he was trying to arrest you, while you run "
				"off and hide. "
			 << endl;
		return 6;
	} else {
		cout << "You make a hail mary run and instead of throwing the ball to "
				"you, your athleticism was too low and he catches up with you "
				"and tackles you and sends you off to jail. "
			 << endl;
		return 16;
	}
}

int inPyramid(Items &guyItems, Character &guy) {
	string menuPrompt = "Which room do you enter";
	string errorMessage = "Type either 1 or 2.";
	int userChoice = 0;
	string menuOptions[2] = {"Room 1", "Room 2"};

	cout
		<< "While admiring the pyramid, you notice there is a block that is "
		   "slightly loose. Your curiosity forces you to push it, and as you "
		   "do so, you see a couple blocks sliding open like a door. As you "
		   "walk in, it slides shut behind you. Some torches light up and lead "
		   "you down a tunnel to what looks like an escape room.\n\nThere are "
		   "two rooms:\nOne with a table that has a ball in a maze on top of "
		   "it, a box that is locked with a 4 number code, and 6 frames on the "
		   "walls that you can move with the numbers 3, 9, 5, 1, 2, and 8\nA "
		   "second room with a box that has a lock that takes "
		<< guy.name.length()
		<< " letters.\n*Note*: You will be able to switch rooms whenever you "
		   "want. "
		<< endl;

	userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);

	if (userChoice == 1) { /// This sends them to room 1
		return 13;
	} else if (userChoice == 2) { /// This sends them to room 2
		return 14;
	}

	return 0;
}

int room1(Items &guyItems, Character &guy) {
	if (guyItems.maze == true and guyItems.numLock == true and
		guyItems.letterLock == true and guyItems.frames == true) {
		return 15;
	}
	bool affordable;
	string menuPrompt = "What would you like to do? ";
	string errorMessage = "Type either 1, 2, 3, or 4";
	int userChoice = 0;
	string menuOptions[5] = {"The maze",
							 "Box locked by a 4 number lock",
							 "Ordering the frames on the wall",
							 "Get a hint -$200",
							 "Switch rooms"};

	do {
		if (guyItems.letterLock == true and guyItems.numLock == false) {
			cout << "\n\nThe birthyear of Kishaan can lead to opening the "
					"number lock."
				 << endl
				 << endl;
		}

		if (guyItems.numLock == true and guyItems.frames == false) {
			cout << "\n\n_________________________\n| 1 | 2 | 3 | 4 | 5 | 6 "
					"|\n|_______________________|\n| 2 | 1 | 9 | 3 | 5 | 8 "
					"|\n|_______________________|\n\n";
		}

		userChoice = menu(menuPrompt, menuOptions, 5, errorMessage);
		switch (userChoice) {
		case 1: /// Maze game
			ballMaze(guyItems, guy);
			break;

		case 2: /// 4 number lock
			numberLock(guyItems, guy);
			break;

		case 3: /// Frames on the wall
			wallFrames(guyItems, guy);
			break;

		case 4: /// Hint function
			affordable = loseMoney(guyItems, 200);
			if (affordable) {
				hint(guyItems, guy);
			}
			break;

		case 5: /// Switch rooms
			return 14;
			break;
		}
	} while (userChoice != 5);

	return 99;
}

void ballMaze(Items &guyItems, Character &guy) {
	system("clear");
	if (guyItems.maze) /// If they finished the maze already I don't let them do
					   /// it again
	{
		cout << "You already completed the ball maze. " << endl;
		return;
	}

	int playerPos = 3;
	int storage = 0;
	bool mazeComplete = false;
	string playerDirection;
	int maze[100] = {
		/// This is the maze
		1, 1, 1, 9, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1,
		0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1,
		1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1,
		1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

	for (int i = 0; i < 100; i++) {
		cout << maze[i];
		cout << "  ";
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	cout << "Your goal is to get to the bottom of the maze. What direction do "
			"you want to go? (Your are the 9, 1s are walls, 0s are spaces)."
		 << endl;

	do {
		cout << "\nRight 'R'\nLeft 'L'\nUp'U'\nDown 'D'" << endl;

		cin >> playerDirection;

		boost::to_upper(playerDirection);

		if (playerDirection == "U" or playerDirection == "D") {
			mazeComplete = mazeGame(
				maze,
				playerDirection,
				playerPos,
				10,
				100,
				94); /// If they go up or down, the change is 10 in the array
					 /// position
		} else if (
			playerDirection == "L" or
			playerDirection == "R") { /// If they go left or right, the change
									  /// is 1 in the array position
			mazeComplete =
				mazeGame(maze, playerDirection, playerPos, 1, 100, 94);
		}

	} while (mazeComplete == false);

	guyItems.maze = true;
	cout << "Suddenly, you hear a loud noise coming from the second room."
		 << endl;
	keyToContinue();

	return;
}

void numberLock(Items &guyItems, Character &guy) {
	system("clear");
	if (guyItems.numLock) {
		cout << "You already completed the number lock. " << endl;
		return;
	}
	string menuPrompt = "Do you want to guess again?";
	string errorMessage = "Type either 1 or 2";
	string menuOptions[2] = {"Yes", "No"};

	int userRepeat = 0;
	int userGuess = 0;
	int correctNum = 2006;

	do {
		cout << "What 4 numbers do you want to try?" << endl;
		cin >> userGuess;			   /// This will get the user's guess
		if (userGuess == correctNum) { /// This verifies the guess
			guyItems.numLock = true;
			cout << "Inside the box there is a "
					"graph:\n_________________________\n| 1 | 2 | 3 | 4 | 5 | "
					"6 |\n|_______________________|\n| 2 | 1 | 9 | 3 | 5 | 8 "
					"|\n|_______________________|"
				 << endl;
			keyToContinue();
		} else {
			userRepeat = menu(menuPrompt, menuOptions, 2, errorMessage);
		}
	} while (userRepeat == 1 and guyItems.numLock == false);
}

void wallFrames(Items &guyItems, Character &guy) {
	if (guyItems.frames) {
		cout << "You already completed the frames. " << endl;
		keyToContinue();
		return;
	}
	string menuPrompt = "Do you want to guess again?";
	string errorMessage = "Type either 1 or 2";
	string menuOptions[2] = {"Yes", "No"};
	int userRepeat = 0;
	int correctNum = 219358;
	int userGuess = 0;
	do {
		cout << "Order the frames: " << endl;
		cin >> userGuess;
		if (userGuess == correctNum) {
			guyItems.frames = true;
			cout << "You got the correct order and start hearing some gears "
					"turning next to you..."
				 << endl;
			keyToContinue();
		} else {
			userRepeat = menu(menuPrompt, menuOptions, 2, errorMessage);
		}

	} while (userRepeat == 1 and guyItems.frames == false);
	return;
}

int room2(Items &guyItems, Character &guy) {
	if (guyItems.maze == true and guyItems.numLock == true and
		guyItems.letterLock == true and
		guyItems.frames == true) { /// If they finichsed all the puzzles, this
								   /// sends them to the final room
		return 15;
	}
	bool affordable;
	string menuPrompt = "What would you like to do? ";
	string errorMessage = "Type either 1, 2, or 3";
	int userChoice = 0;
	int counter = 0;
	string menuOptions[3] = {"The box locked by letter combination lock",
							 "Get a hint -$200",
							 "Go to room 1"};

	if (guyItems.maze == true and guyItems.letterLock == false and
		counter == 0) {
		cout << "\n\nWhen you enter the room, a secret drawer slides out of "
				"the wall with a note. 'What belongs to you but other people "
				"use more than you? The box with the letters may open from "
				"this clue.'\n\n";
		counter++;
	}

	do {
		userChoice = menu(menuPrompt, menuOptions, 3, errorMessage);
		switch (userChoice) {
		case 1: /// Maze game
			letterLock(guyItems, guy);
			break;

		case 2: /// Hint function
			affordable = loseMoney(guyItems, 200);
			if (affordable) {
				hint(guyItems, guy);
			}
			break;

		case 3: /// Switch rooms
			return 13;
			break;
		}
	} while (userChoice != 4);

	system("clear");

	return 99;
}

void letterLock(Items &guyItems, Character &guy) {
	if (guyItems.letterLock) {
		cout << "You already completed the letter lock. " << endl;
		keyToContinue();
		return;
	}
	string menuPrompt = "Do you want to guess again?";
	string errorMessage = "Type either 1 or 2";
	string menuOptions[2] = {"Yes", "No"};

	int userRepeat = 0;
	string userGuess = "";
	string correctAns = guy.name;
	boost::to_upper(correctAns);

	do {
		cout << "What letters do you want to try?" << endl;
		cin >> userGuess;			 /// This gets the user guess
		boost::to_upper(userGuess);  /// This puts the user guess in upper case
		if (userGuess == correctAns) /// This checks if the guess is correct
		{
			guyItems.letterLock = true;
			cout
				<< "Inside the box was another note: 'The birthyear of Kishaan "
				   "can be a stumbler and open the box locked by numbers.'"
				<< endl;
			keyToContinue();
		} else {
			userRepeat = menu(menuPrompt, menuOptions, 2, errorMessage);
		}
	} while (userRepeat == 1 and guyItems.letterLock == false);

	system("clear");

	return;
}

void hint(
	Items &guyItems,
	Character &guy) { /// This gives hints depending on how far on in the
					  /// "escape room" the user is
	if (guyItems.maze == false and guyItems.numLock == false and
		guyItems.frames == false and guyItems.letterLock == false) {
		cout << "If you want a place start, the maze might be quite smart."
			 << endl;
		keyToContinue();
	} else if (
		guyItems.maze == true and guyItems.numLock == false and
		guyItems.frames == false and guyItems.letterLock == false) {
		cout << "Your in-game name can open the box with the letter lock. Your "
				"name is: "
			 << guy.name << endl;
		keyToContinue();
	} else if (
		guyItems.maze == true and guyItems.numLock == false and
		guyItems.frames == false and guyItems.letterLock == true) {
		cout << "Kishaan's birthyear is 2006." << endl;
		keyToContinue();
	} else if (
		guyItems.maze == true and guyItems.numLock == true and
		guyItems.frames == false and guyItems.letterLock == true) {
		cout << "The numbers at the bottom of the graph are the numbers on the "
				"frame and the top numbers on the graph tells you which number "
				"is first, second, third, etc."
			 << endl;
		keyToContinue();
	} else if (
		guyItems.maze == true and guyItems.numLock == true and
		guyItems.frames == true and guyItems.letterLock == true) {
		cout << "Switch to room 2 and you will see a hidden door." << endl;
		keyToContinue();
	}
}

int finalRoom(Items &guyItems, Character &guy) {
	cout << "Suddenly, a door flush with the wall slides open to reveal, on a "
			"shining high pedestal, the famous gold and diamond soccer ball. "
			"You take the ball and start leaving the pyramid."
		 << endl;
	guyItems.soccerBall = true;
	return 20;
}

int inPrison(Items &guyItems, Character &guy) {
	string menuPrompt = "Are you going to try to break out?";
	string errorMessage = "Tyoe either 1 or 2";
	int userChoice = 0;
	string menuOptions[2] = {"Yes", "No"};
	int counter = 0;

	if (counter ==
		0) { /// I only want to say this the first time they arrive in prison
		cout << "You get to prison and immidiately recognize it as a low "
				"security prison with very little security and is relatively "
				"close to the airport you landed at. "
			 << endl;
		counter++;
	}

	userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);

	if (userChoice == 1) {
		return 17;
	} else {
		cout << "You stay in jail for a week and then get sent to Ottawa, "
				"getting banned from returning. "
			 << endl;
		return 99;
	}
}

int breakingOut(Items &guyItems, Character &guy) {
	bool awarenessTrueOrFalse = false;
	string menuPrompt = "When do you attempt your breakout";
	string errorMessage = "Type either 1, 2, or 3.";
	int userChoice = 0;
	string menuOptions[3] = {"Early morning", "Mid-day", "Midnight"};

	cout << "You start thinking of ways to break out. You realize that picking "
			"the lock and sneaking out of the jail is the easiest route. "
		 << endl;

	userChoice = menu(menuPrompt, menuOptions, 3, errorMessage);
	if (userChoice == 1) { /// This is what happens when they choose morning
		cout << "Your plan is to pick the lock as early as possible and make "
				"it out of the jail by crawling through the vents. "
			 << endl;
		awarenessTrueOrFalse =
			statChecker(90, 80, 70, 100, 95, 85, 75, guy.awareness);
		if (awarenessTrueOrFalse) { /// This checks their awareness, if it high,
									/// it returns 18
			return 18;
		} else { /// If the odds came out false, it brings them back to ask if
				 /// they want to break out
			cout << "You start lock picking but your low awareness caused you "
					"to get caught by a guard that you didn't notice, you get "
					"placed in solitary confinement for a week then back to "
					"your normal cell. "
				 << endl;
			return 16;
		}

	} else if (userChoice == 2) { /// If they chose 2, they are immidiately
								  /// asked again if they want to break out
								  /// again
		cout << "You decide to attempt in the middle of the day. You reach "
				"around to the outside of your cell playing around with the "
				"lock trying to open, however, a guard spots you right away "
				"and puts you in solitary confinement for a week."
			 << endl;
		return 16;
	} else { /// If they chose 3, 19 is returned
		cout << "You decide the middle of the night is the easiest time to "
				"break-out and see a couple of options to break out. "
			 << endl;
		return 19;
	}
}

int ventCrawl(Items &guyItems, Character &guy) {
	int playerPos =
		3; /// This is the initial position of the player in the maze
	int storage = 0;
	bool mazeComplete = false;
	string playerDirection = "";
	int maze[100] = {
		/// This is the maze, an array
		1, 0, 1, 9, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1,
		1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1,
		1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
		1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1,
		1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};

	cout << "You get in the vents and realise that it is almost like a maze... "
			"(you need to follow the 0s, the 1s are walls, you are the 9)"
		 << endl;

	for (int i = 0; i < 100; i++) { /// This displays the maze
		cout << maze[i];
		cout << "  ";

		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	do {
		cout << "\nRight 'R'\nLeft 'L'\nUp'U'\nDown 'D'" << endl;
		cin >> playerDirection;
		boost::to_upper(
			playerDirection); /// This puts the string into upper case

		if (playerDirection == "U" or playerDirection == "D") {
			mazeComplete =
				mazeGame(maze, playerDirection, playerPos, 10, 100, 98);
		} else if (playerDirection == "L" or playerDirection == "R") {
			mazeComplete =
				mazeGame(maze, playerDirection, playerPos, 1, 100, 98);
		}

	} while (mazeComplete == false);

	cout << "You made it out and run to the Cairo airport, completely "
			"unnoticed. "
		 << endl;

	return 1;
}

int midnight(Items &guyItems, Character &guy) {
	string menuPrompt = "How do you chose to break out?";
	string errorMessage = "Type either 1 or 2.";
	int userChoice = 0;
	string menuOptions[2] = {
		"Break the toilet and crawl thourgh the pipe", "Crawl in the vents"};
	userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);

	if (userChoice == 1) {
		cout << "You break the toilet and realize you can't fit in the pipes "
				"and get sent to solitary confinement"
			 << endl;
		return 16;
	} else if (userChoice == 2) {
		return 18;
	}

	return 0;
}

int leavePyramid(Items &guyItems, Character &guy) {
	int lookAroundCounter = 0;
	bool athleticismTrueOrFalse = false;
	string menuPrompt =
		"When leaving the temple, a boulder starts rolling towards you in a "
		"narrow alley and you only see two ways to avoid it. ";
	string errorMessage = "Type either 1 or 2";
	int userChoice = 0;
	string menuOptions[2] = {
		"Out run the boulder", "Hide in a crevice in the wall"};

	userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);

	if (userChoice == 1) {
		athleticismTrueOrFalse = statChecker(
			90,
			80,
			60,
			guy.athleticism - 10,
			guy.athleticism - 10,
			guy.athleticism - 20,
			35,
			guy.athleticism);

		if (athleticismTrueOrFalse) { /// If they got lucky, 21 is returned
			cout << "Your speed saved you! " << endl;
			return 21;
		} else { /// If you get unlucky, the game ends
			cout << "The boulder was quicker than you and you died. " << endl;
			return 99;
		}
	} else { /// If they chose 2, they get stuck in the pyramid and 22 is
			 /// returned
		cout << "You hid in the crevice and the boulder quickly went past you "
				"and blocks the way out."
			 << endl;
		return 22;
	}
}

int stuckInPyramid(Items &guyItems, Character &guy) {
	bool escaped = false;
	int lookAroundCounter = 0; /// This will keep track of the amount of times
							   /// the lookAround has been ran
	bool intelligenceChecker = false;
	string menuPrompt = "How do you get out?";
	string errorMessage = "That is not a valid choice.";
	int userChoice = 0;
	string menuOptions[3] = {
		"Look around for anything",
		"Kick the soccer ball at the boulder repeatedly until it breaks",
		"Try to move the boulder"};

	cout << "You start looking around for ways out.";

	do {
		userChoice = menu(menuPrompt, menuOptions, 3, errorMessage);
		if (userChoice == 1) { /// If they look around, I call the function
			keyToContinue();
			escaped = lookAround(guyItems, guy, lookAroundCounter);
		} else if (userChoice == 2) {
			if (guyItems.soccerBall) {
				cout << "You repeatedly kick the ball at the boulder because "
						"you heard that diamonds are strong, however, the ball "
						"shatters into thousands of pieces. "
					 << endl;
				guyItems.soccerBall =
					false; /// The soccer ball breaks and they lose it
				keyToContinue();
			} else {
				cout << "You already broke the soccer ball. :(" << endl;
				keyToContinue();
			}

		} else if (userChoice == 3) {
			if (guy.intelligence <
				75) { /// If their intelligence is under 75 they can't proceed
					  /// to escape this way
				cout << "You weren't strong enough or smart enough to move the "
						"boulder."
					 << endl;
				keyToContinue();
			} else { /// If their intelligence is above 75, they can escape this
					 /// way
				intelligenceChecker = statChecker(
					95,
					90,
					83,
					100,
					95,
					90,
					guy.intelligence,
					guy.intelligence);
				if (intelligenceChecker) { /// If they get lucky, they need the
										   /// rope to escape
					cout << "You are so smart that you immidiately realize "
							"that you can make a pulley to lift the boulder, "
							"but you would need a strong rope."
						 << endl;
					if (guyItems.rope) { /// If they have the rope:
						cout << "Luckily, you remember you picked up a rope "
								"while searching around and use it to make the "
								"pulley and get out of the pyramid. "
							 << endl;
						escaped = true;
					} else { /// If they don't have the rope:
						cout << "However, you don't have a rope and might be "
								"better off looking for one. "
							 << endl;
						keyToContinue();
					}
				} else if (intelligenceChecker == false) { /// If they got
														   /// unlucky, they get
														   /// told they
														   /// couldn't move it
														   /// just yet.
					cout << "You weren't strong enough or smart enough to move "
							"the boulder just yet."
						 << endl;
					keyToContinue();
				}
			}
		}
	} while (escaped == false); /// It loops this while they haven't escaped
	return 21;
}

bool lookAround(Items &guyItems, Character &guy, int &counter) {
	string menuPrompt = "Do you flip the lever?";
	string errorMessage = "Type either 1 or 2,";
	int userChoice = 0;
	string menuOptions[2] = {"Yes", "No"};

	if (counter ==
		0) { /// On their first time looking around, they find a lever
		cout << "You find a lever hidden away behind a rock." << endl;
		userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);
		if (userChoice == 1) { /// They pull the lever:
			cout << "You see the boulder slowly crack opening up the exit to "
					"the pyramid. "
				 << endl;
			return true;
		} else { /// They don't pull the lever:
			cout << "You play it safe and don't flip the lever. " << endl;
			keyToContinue();
		}
	} else if (counter == 1) { /// The second time looking around they find the
							   /// rope they might need
		cout << "After searching for a while looking around you find a really "
				"sturdy rope with bones laying next to it. Clearly someone "
				"else attempted to escape. You take the rope."
			 << endl;
		guyItems.rope = true;
	} else if (counter == 2) { /// Third time looking around, they can use the
							   /// rope to escape without the soccer ball
		if (guyItems.rope) {
			cout << "After looking around for a thrid time, you see a hole in "
					"the top of the pyramid which might just save you. You "
					"toss the rope up and over it snags on to something "
					"allowing you to escape, but without the soccer ball."
				 << endl;
			guyItems.soccerBall = false;
			return true;
		}
	}
	counter++; /// This will increase the counter so the next time this function
			   /// is run, it has been increased.
	return false;
}

int outOfPyramid(Items &guyItems, Character &guy) {
	string menuPrompt = "\nDo you sell it for 100 million dollars, or keep it "
						"for generations to come?";
	string errorMessage = "Type either 1 or 2.";
	int userChoice = 0;
	string menuOptions[2] = {"Sell it", "Keep it"};

	if (guyItems.soccerBall) { /// If they have the soccer ball
		cout << "You made it out of the pyramid. While flying back to Canada, "
				"you get into a deep thought, do you sell the ball?"
			 << endl;
		userChoice = menu(menuPrompt, menuOptions, 2, errorMessage);
		if (userChoice == 1) {
			cout << "You made a terrible decision, as you sell it, the police "
					"track you down to recover the ball and you get arrested "
					"being put away for life. "
				 << endl;
		} else {
			cout << "You keep the ball and admire it every day knowing that "
					"you put in hard work to get it. "
				 << endl;
		}
	} else {
		cout << "You went home empty handed, but with a journey to remember. "
			 << endl;
	}

	return 99; /// This function ends the game no matter what happens
}

void gameMenu(Items &guyItems, Character &guy) {
	int nextFunction =
		0; /// This determines what the next function is in the case structure
	int counter = 0; /// This is a counter variable

	nextFunction =
		gameIntro(guyItems); /// This gets the returned number of the game intro
							 /// to see where the case strutures goes next.
	do {
		switch (nextFunction) {
		case 1:
			keyToContinue();
			nextFunction = cairoAirport(
				guyItems, guy, counter); /// The return value of the function is
										 /// what the next function to run is.
			break;

		case 2:
			keyToContinue();
			nextFunction = thePyramid(guyItems, guy);
			break;

		case 3:
			keyToContinue();
			nextFunction = sideOfRoad(guyItems, guy);
			break;

		case 4:
			keyToContinue();
			nextFunction = taxiSideOfRoad(guyItems, guy);
			break;

		case 5:
			keyToContinue();
			nextFunction = hitchhikeSideOfRoad(guyItems, guy);
			break;

		case 6:
			keyToContinue();
			nextFunction = inPyramid(guyItems, guy);
			break;

		case 7:
			nextFunction = sneakAround(guyItems, guy);
			break;

		case 8:
			keyToContinue();
			nextFunction = findWayOut(guyItems, guy);
			break;

		case 9:
			keyToContinue();
			nextFunction = useLuck(guyItems, guy);
			break;

		case 10:
			keyToContinue();
			nextFunction = useIntelligence(guyItems, guy);
			break;

		case 11:
			keyToContinue();
			nextFunction = useAwareness(guyItems, guy);
			break;

		case 12:
			keyToContinue();
			nextFunction = useAthleticism(guyItems, guy);
			break;

		case 13:
			keyToContinue();
			nextFunction = room1(guyItems, guy);
			break;

		case 14:
			keyToContinue();
			nextFunction = room2(guyItems, guy);
			break;

		case 15:
			nextFunction = finalRoom(guyItems, guy);
			break;

		case 16:
			keyToContinue();
			nextFunction = inPrison(guyItems, guy);
			break;

		case 17:
			keyToContinue();
			nextFunction = breakingOut(guyItems, guy);
			break;

		case 18:
			keyToContinue();
			nextFunction = ventCrawl(guyItems, guy);
			break;

		case 19:
			keyToContinue();
			nextFunction = midnight(guyItems, guy);
			break;

		case 20:
			keyToContinue();
			nextFunction = leavePyramid(guyItems, guy);
			break;

		case 21:
			keyToContinue();
			nextFunction = outOfPyramid(guyItems, guy);
			break;

		case 22:
			keyToContinue();
			nextFunction = stuckInPyramid(guyItems, guy);
			break;
		}
	} while (nextFunction != 99);
}

/// ======== main =========

int main() {
	Character guy;			 /// This makes a new Character called guy
	Items guyItems;			 /// This makes a new Items called guyItems
	int difficultyLevel = 0; /// This is the difficulty of the game
	userMainMenuCase(
		guy, difficultyLevel, guyItems); /// This runs the first case structure
	system("clear");
	gameMenu(guyItems, guy); /// This runs the game scenes case structure
	return 0;
}
