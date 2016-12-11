//Function for the "You Lose!" screen
int you_lose(int scor)
{
	WINDOW *wnd;
	int nrows,ncols;
	wnd=initscr();
	start_color();
	init_pair(1,COLOR_RED,COLOR_BLACK);
	attrset(A_BOLD);
	cbreak();
	noecho();
	getmaxyx(wnd,nrows,ncols);
	clear();
	wbkgd(wnd,COLOR_PAIR(1));
	int cm=ncols/2,rm=nrows/2;
	/************************************************
	ASCII Art print
	************************************************/
	mvprintw(rm-3,cm-35," __   __  _______  __   __    ___      _______  _______  _______  __ ");
	mvprintw(rm-2,cm-35,"|  | |  ||       ||  | |  |  |   |    |       ||       ||       ||  |");
	mvprintw(rm-1,cm-35,"|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||_     _||  |");
	mvprintw(rm,cm-35,  "|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____   |   |  |  | ");
	mvprintw(rm+1,cm-35,"|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  |  |   |  |__| ");
	mvprintw(rm+2,cm-35,"  |   |  |       ||       |  |       ||       | _____| |  |   |   __  ");
	mvprintw(rm+3,cm-35,"  |___|  |_______||_______|  |_______||_______||_______|  |___|  |__| ");
	refresh();
	int delay=3000000;
	usleep(delay);
	highscoref(scor);
	return 0;
}
//Function for the "You Win!" screen
int you_win(int scor)
{
	WINDOW *wnd;
	int nrows,ncols;
	wnd=initscr();
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	cbreak();
	noecho();
	getmaxyx(wnd,nrows,ncols);
	clear();
	attrset(A_BOLD);
	wbkgd(wnd,COLOR_PAIR(1));
	int cm=ncols/2,rm=nrows/2;
	/************************************************
	ASCII Art print
	************************************************/
	mvprintw(rm-7,cm-37," _______  _______  __    _  _______  ______    _______  _______  _______ ");
	mvprintw(rm-6,cm-37,"|       ||       ||  |  | ||       ||    _ |  |   _   ||       ||       |");
	mvprintw(rm-5,cm-37,"|       ||   _   ||   |_| ||    ___||   | ||  |  |_|  ||_     _||  _____|");
	mvprintw(rm-4,cm-37,"|       ||  | |  ||       ||   | __ |   |_||_ |       |  |   |  | |_____ ");
	mvprintw(rm-3,cm-37,"|      _||  |_|  ||  _    ||   ||  ||    __  ||       |  |   |  |_____  |");
	mvprintw(rm-2,cm-37,"|     |_ |       || | |   ||   |_| ||   |  | ||   _   |  |   |   _____| |");
	mvprintw(rm-1,cm-37,"|_______||_______||_|  |__||_______||___|  |_||__| |__|  |___|  |_______|");
	mvprintw(rm  ,cm-37,"       __   __  _______  __   __    _     _  ___   __    _  __           ");
	mvprintw(rm+1,cm-37,"      |  | |  ||       ||  | |  |  | | _ | ||   | |  |  | ||  |          ");
	mvprintw(rm+2,cm-37,"      |  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| ||  |          ");
	mvprintw(rm+3,cm-37,"      |       ||  | |  ||  |_|  |  |       ||   | |       ||  |          ");
	mvprintw(rm+4,cm-37,"      |_     _||  |_|  ||       |  |       ||   | |  _    ||__|          ");
	mvprintw(rm+5,cm-37,"        |   |  |       ||       |  |   _   ||   | | | |   | __           ");
	mvprintw(rm+6,cm-37,"        |___|  |_______||_______|  |__| |__||___| |_|  |__||__|          ");
	refresh();
	int delay=3000000;
	usleep(delay);
	highscoref(scor);
	return 0;
}
