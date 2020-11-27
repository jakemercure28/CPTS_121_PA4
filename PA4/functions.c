#include "functions.h"

void print_game_rules() {  
	
	// welcomes player to the game 
	printf("Welcome to Craps!\n\n Press 1 to display the rules or 2 to skip over them.\n");

	int display_rules = 0;
	do{
		printf("1. Display rules\n2. Skip rules\n");
		scanf("%d", &display_rules);
	
		if (display_rules == 1) {  // prints game rules, extends pretty far ---->
			printf("\nRules: A player rolls two dice. \nAfter the dice have come to rest, the sum of both dice is calculated.\n\nIf the sum is 7 or 11 on the first throw, the player wins. \nIf the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e. the \"house\" wins). \nIf the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point.\" \n\nTo win, you must continue rolling the dice until you \"make your point.\" \nThe player loses by rolling a 7 before making the point.");
			break;
		}
	} while (display_rules != 2); // skips games rules 
}


double get_bank_balance(void){ // prompts user for bank balance
	
	double bank_balance_local = 0;
	printf("\n\nHow much money do you want to start the game with? ");
	scanf("%lf", &bank_balance_local);
	
		return bank_balance_local;
}

double get_wager_amount(void){  // prompts user for betting amount
	
	double wager_amount_local = 0;
	printf("\nPlace your bets: ");
	scanf("%lf", &wager_amount_local);
		return wager_amount_local;
}

int check_wager_amount(double wager_amount, double bank_balance) {

	// checks if user bets more than has in bank
	int wager_check = 0;
	if (wager_amount <= bank_balance) {
		wager_check = 1;
	}
	else wager_check = 0;

	while (wager_check == 0) {
		printf("\nYou only have $%.2lf, you can't bet more than you have!", bank_balance);
		wager_amount = get_wager_amount(); // gets new wager amount if greater than bank balance
		wager_check = check_wager_amount(wager_amount, bank_balance);
	}
		return wager_amount;
}		
int roll_die(void) {

	int die = rand() % 6 + 1; // determines random number between 1-6

	switch (die) { // prints correct die to console
	case 1:
		printf("\n+-------+\n|       |\n|   o   |\n|       |\n+-------+");
		break;
		
	case 2:
		printf("\n+-------+\n| o     |\n|       |\n|     o |\n+-------+\n");
		break;

	case 3:
		printf("\n+-------+\n| o     |\n|   o   |\n|     o |\n+-------+\n");
		break;

	case 4:
		printf("\n+-------+\n| o   o |\n|       |\n| o   o |\n+-------+\n");
		break;

	case 5:
		printf("\n+-------+\n| o   o |\n|   o   |\n| o   o |\n+-------+\n");
		break;

	case 6:
		printf("\n+-------+\n| o   o |\n| o   o |\n| o   o |\n+-------+\n");
		break;
	}
	return die; // returns the rolled die to main
}

int calculate_sum_dice(int die1_value, int die2_value) {
	
	int dice_sum_local = die1_value + die2_value;
	return dice_sum_local;
}

int is_win_loss_or_point(int sum_dice) {
	
	if (sum_dice == 7 || sum_dice == 11) {  // returning 1 is the result of a win
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) { // returning 0 is the result of a loss
		return 0;
	}
	else return-1; 
}

int is_point_loss_or_neither(int sum_dice, int point_value) {
	
	if (sum_dice == point_value) {  // this returns a win
		return 1;
	}
	else if (sum_dice == 7) {  // returns a 
		return 0;
	}
	else return -1;
}

void chatter_messages(int number_rolls, int point_value, int pt_loss_neither, double initial_bank_balance, double bank_balance) {
	
	// prints the status of the bank, number of rolls and after each roll
	if (pt_loss_neither == 1) {
		printf("\nPoint value saved!\n");
	}
	
		printf("\nNumber of rolls: %d\nCurrent point value: %d\nInitial bank balance: %lf\nCurrent bank balance: %lf", number_rolls, point_value, initial_bank_balance, bank_balance);
	
	
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {

	switch (add_or_subtract) {
		// add wager to bank balance
	case 1: bank_balance += wager_amount;
		break;
		// subtract wager from bank balance
	case 0: bank_balance -= wager_amount;
		break;
	default:
		break;
	}
	return bank_balance;
}