/******************************************************
This program will simulate the game of Crapps.
Two dice are used to play, betting is allowed.

Programmer: Jake Mercure
Date: 2/21/2020

*******************************************************/

#include "functions.h"


int main(void){
	/*************************************************************
							Global variables
	
	**************************************************************/

	double bank_balance = 0, initial_bank_balance = 0, wager_amount = 0, wager_amount_test = 0,
		sum_dice = 0;
	int option = 0, die1_value = 0, die2_value = 0, number_rolls = 0, win_loss_pt, point_value = 0,
		pt_loss_neither = 0, add_or_subtract = 0;
	

	/**************************************************************
							Initial game setup
	
	***************************************************************/
	
		// used to determine randomness of die roll calculation
	srand((unsigned int)time(NULL));

		// display rules
	print_game_rules();

		// get balances
	bank_balance = get_bank_balance();
	wager_amount = get_wager_amount();

		// save initial bank balance
	initial_bank_balance = bank_balance;
	
		// check wager amount to see if greater than bank amount
	wager_amount = check_wager_amount(wager_amount, bank_balance);
		
	/*********************************************************
		first roll of game, seperate from proceeding rolls
	
	**********************************************************/
	
	die1_value = roll_die();
	die2_value = roll_die();

		//sum dice, adds both rolls together
	sum_dice = calculate_sum_dice(die1_value, die2_value);

		// did they win, lose, or point
	win_loss_pt = is_win_loss_or_point(sum_dice);

		// swtich statement used to determine wins, losses and points
	switch (win_loss_pt) {
		case 1:
			printf("\nYou win!");
			add_or_subtract = 1;
			bank_balance = adjust_bank_balance(bank_balance, wager_amount, add_or_subtract);
			break;
		case 0:
			printf("\nYou lose!");
			add_or_subtract = 0;
			bank_balance = adjust_bank_balance(bank_balance, wager_amount, add_or_subtract);
			break;
		case -1:
			point_value = sum_dice;
			break;
	}
	number_rolls++; // adds 1 roll after the first roll is completed
	chatter_messages(number_rolls, point_value, pt_loss_neither, initial_bank_balance, bank_balance); // prints after first roll
	/*****************************************************************
							proceeding rolls
	
	******************************************************************/
	
	do {	
		// show menu and choose option, if its not 1 or 2, try again.
		printf("\n\n1. Roll again\n2. Quit game\n");
		scanf("%d", &option);

		if (option == 1){  // if option = 1, run the game
			
			wager_amount = get_wager_amount();

			// check wager amount if over bank amount
			wager_amount = check_wager_amount(wager_amount, bank_balance);

			// adds to roll count
			number_rolls++;

			// dice roll
			die1_value = roll_die();
			die2_value = roll_die();

			//sum of dice
			sum_dice = calculate_sum_dice(die1_value, die2_value);

			//did they get a point, loss or neither
			pt_loss_neither = is_point_loss_or_neither(sum_dice, point_value);
			
			switch (pt_loss_neither) {
			case 1:
				printf("\nYou win!");
				add_or_subtract = 1;
				bank_balance = adjust_bank_balance(bank_balance, wager_amount, add_or_subtract);
					break;
			case 0:
				printf("\nYou lose!");
				add_or_subtract = 0;
				bank_balance = adjust_bank_balance(bank_balance, wager_amount, add_or_subtract);
					break;
			case -1:
				add_or_subtract = -1;
				bank_balance = adjust_bank_balance(bank_balance, wager_amount, add_or_subtract);
					break;
			}
			
			// print player stats
			chatter_messages(number_rolls, point_value, pt_loss_neither, initial_bank_balance, bank_balance);

		}

	} while (option != 2);

	/***************************************************************
						End of proceeding rolls

	****************************************************************/

	printf("\n\nThanks for playing.");

		return 0;
}