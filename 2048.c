// File that contains the main function of the game
#include "biblioteci.h"
#include "sigla.h"
#include "meniuri.h"
#include "fisiere.h"
#include "joc.h"
#include "mutari.h"
#include "final.h"

int main()
{
	sigla();
	//Function that shows the Logo
	clear();
	//Function that clears the screen
	main_menu();
	//Function that shows the main menu of the game
	endwin();
	return 0;
	//the exit of the game
}
