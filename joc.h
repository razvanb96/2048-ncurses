//Function for the new Game
int new_game()
{
	WINDOW *wnd;
	int nrows,ncols;
	wnd=initscr();
	start_color();
	/************************************************
	Setting the color pairs
	************************************************/
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_BLUE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_BLACK);
	init_pair(4,COLOR_CYAN,COLOR_BLACK);
	init_pair(5,COLOR_YELLOW,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_MAGENTA,COLOR_BLACK);
	init_pair(8,COLOR_BLACK,COLOR_RED);
	init_pair(9,COLOR_BLACK,COLOR_GREEN);
	halfdelay(60);
	noecho();
	getmaxyx(wnd,nrows,ncols);
	clear();
	wbkgd(wnd,COLOR_PAIR(5));
	int rm=nrows/2;
	int cm=ncols/2;
	char d,*s;
	int i,j,scor,scorant,vs,verif;
	scor=0;
	/************************************************
	Loading the matrix with the 2 random chosen values
	at random chosen positions
	************************************************/
	int mat[4][4],matant[4][4];
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			mat[i][j]=0;
	int c,delay=2000000;
	aleatoriu(mat);
	aleatoriu(mat);
	/************************************************
	Printing the Matrix and saving it in the matant
	file for the Undo case.
	************************************************/
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(mat[i][j]==0)
			{
					mvprintw(rm-7+i*2,cm-9+j*6,"--");
			}
				else
				{
					if(mat[i][j]==2)
					{	
						attron(COLOR_PAIR(5));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(5));
					}
					if(mat[i][j]==4)
					{	
						attron(COLOR_PAIR(1));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(1));
					}
				}
			matant[i][j]=mat[i][j];
		}
	/************************************************
	Printing the rest of the GUI With the Legend of moves
	************************************************/
	attron(A_BLINK);
	mvprintw(nrows-1,cm-15,"(c) Razvan Buhaianu - 313CC  ");
	attroff(A_BLINK);
	mvprintw(0,cm-4,"=2 0 4 8=");
	mvprintw(rm+3,cm-39,"Mutari:");
	attron(A_STANDOUT|A_DIM);
	mvprintw(rm+7,cm-33," A ");
	mvprintw(rm+7,cm-29," S ");
	mvprintw(rm+7,cm-25," D ");
	mvprintw(rm+7,cm-11," X: AUTOMOVE ");
	mvprintw(rm+5,cm-29," W ");
	mvprintw(rm+5,cm-11," U: UNDO ");
	mvprintw(rm+3,cm-11," Q: QUIT ");
	attroff(A_STANDOUT|A_DIM);
	mvprintw(rm-3,cm+20,"Scor:%d",scor);
	scorant=scor;
	/*******************************************************
	The game loop ends when you win/Lose or when you press Q
	(in this case the Matric is saved for the game resume)
	*******************************************************/
	while(1)
	{   
	    c=getch();
		c=tolower(c);
		if(c!='u')
		{
			scorant=scor;	
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					matant[i][j]=mat[i][j];
		}
		clear();
		attron(A_BLINK);
		mvprintw(nrows-1,cm-15,"(c) Razvan Buhaianu - 313CC  ");
		attroff(A_BLINK);
		mvprintw(0,cm-4,"=2 0 4 8=");
		mvprintw(rm+3,cm-39,"Mutari:");
		attron(A_STANDOUT|A_DIM);
		mvprintw(rm+7,cm-33," A ");
		mvprintw(rm+7,cm-29," S ");
		mvprintw(rm+7,cm-25," D ");
		mvprintw(rm+7,cm-11," X: AUTOMOVE ");
		mvprintw(rm+5,cm-29," W ");
		mvprintw(rm+5,cm-11," U: UNDO ");
		mvprintw(rm+3,cm-11," Q: QUIT ");
		attroff(A_STANDOUT|A_DIM);
		mvprintw(rm-3,cm+20,"Scor:%d",scor);
		scorant=scor;
	/************************************************
	Checking the pressed key and calling the move
	function(for that direction)/Automove Function/
	undo function or quit
	************************************************/
		if((c=='x') || (c==ERR))
			c=auto_move(mat);
		if(c=='w')
		{
			vs=moveup(mat);
			if(vs!=1)
				scor=scor+vs;
		}
		if(c=='s')
		{
			vs=movedown(mat);
			if(vs!=1)	
				scor=scor+vs;
		}
		if(c=='a')
		{
			vs=moveleft(mat);
			if(vs!=1)		
				scor=scor+vs;
		}
		if(c=='d')
		{
			vs=moveright(mat);
			if(vs!=1)
				scor=scor+vs;
		}
		if(c=='u')
		{
			undo(mat,matant);
			scor=scorant;
		}
		if(c=='q')
		{
			save(mat,scor);
			return main_menu();
		}
	/************************************************
	Print the resulted Matrix
	************************************************/
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				if(mat[i][j]==0)
				{
					mvprintw(rm-7+i*2,cm-9+j*6,"--");
				}
				else
				{
					if(mat[i][j]==2)
					{	
						attron(COLOR_PAIR(5));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(5));
					}
					if(mat[i][j]==4)
					{	
						attron(COLOR_PAIR(1));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(1));
					}
					if(mat[i][j]==8 || mat[i][j]==512)
					{	
						attron(COLOR_PAIR(2));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(2));
					}
					if(mat[i][j]==16 || mat[i][j]==256)
					{	
						attron(COLOR_PAIR(3));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(3));
					}
					if(mat[i][j]==32 || mat[i][j]==1024)
					{	
						attron(COLOR_PAIR(4));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(4));
					}
					if(mat[i][j]==64 || mat[i][j]==2048)
					{	
						attron(COLOR_PAIR(6));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(6));
					}
					if(mat[i][j]==128)
					{	
						attron(COLOR_PAIR(7));
						mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
						attroff(COLOR_PAIR(7));
					}
				
				}
			}
		mvprintw(rm-3,cm+20,"Scor:%d",scor);
		verif=verificare(mat);
		if(verif==1)
			{
				usleep(2000000);
				break;
			}
		if(verif==2)
			break;
			
	}
	/************************************************
	Check if Win or Lose and call the next functions
	(show highscore and return to main menu)
	************************************************/
	if(verif==(2))
		you_lose(scor);
	if(verif==(1))
		you_win(scor);
	return main_menu();
}
/************************************************************
Function for Resume game
The same as New Game but loads the Matrix from a file
************************************************************/
int resume_game()
{
	WINDOW *wnd;
	int nrows,ncols;
	wnd=initscr();
	start_color();
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_BLUE,COLOR_BLACK);
	init_pair(3,COLOR_WHITE,COLOR_BLACK);
	init_pair(4,COLOR_CYAN,COLOR_BLACK);
	init_pair(5,COLOR_YELLOW,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_MAGENTA,COLOR_BLACK);
	halfdelay(60);
	noecho();
	getmaxyx(wnd,nrows,ncols);
	clear();
	wbkgd(wnd,COLOR_PAIR(5));
	refresh();
	int rm=nrows/2;
	int cm=ncols/2;
	char d,*s;
	int i,j,scor,scorant;
	int mat[4][4],matant[4][4],vs;
	scor=load(mat,scor);
	refresh();
	int c,verif,delay=2000000;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(mat[i][j]==0)
			{
				mvprintw(rm-7+i*2,cm-9+j*6,"--");
			}
			else
			{
				if(mat[i][j]==2)
				{	
					attron(COLOR_PAIR(5));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(5));
				}
				if(mat[i][j]==4)
				{	
					attron(COLOR_PAIR(1));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(1));
				}
				if(mat[i][j]==8 || mat[i][j]==512)
				{	
					attron(COLOR_PAIR(2));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(2));
				}
				if(mat[i][j]==16 || mat[i][j]==256)
				{	
					attron(COLOR_PAIR(3));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(3));
				}
				if(mat[i][j]==32 || mat[i][j]==1024)
				{	
					attron(COLOR_PAIR(4));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(4));
				}
				if(mat[i][j]==64 || mat[i][j]==2048)
				{	
					attron(COLOR_PAIR(6));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(6));
				}
				if(mat[i][j]==128)
				{	
					attron(COLOR_PAIR(7));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(7));
				}
				
			}
			matant[i][j]=mat[i][j];
		}
	attron(A_BLINK);
	mvprintw(nrows-1,cm-15,"(c) Razvan Buhaianu - 313CC  ");
	attroff(A_BLINK);
	mvprintw(0,cm-4,"=2 0 4 8=");
	mvprintw(rm+3,cm-39,"Mutari:");
	attron(A_STANDOUT|A_DIM);
	mvprintw(rm+7,cm-33," A ");
	mvprintw(rm+7,cm-29," S ");
	mvprintw(rm+7,cm-25," D ");
	mvprintw(rm+7,cm-11," X: AUTOMOVE ");
	mvprintw(rm+5,cm-29," W ");
	mvprintw(rm+5,cm-11," U: UNDO ");
	mvprintw(rm+3,cm-11," Q: QUIT ");
	attroff(A_STANDOUT);
	mvprintw(rm-3,cm+20,"Scor:%d",scor);
	scorant=scor;
	while(1)
	{   c=getch();
		c=tolower(c);
		if(c!='u')
		{
			scorant=scor;	
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					matant[i][j]=mat[i][j];
		}
		clear();
		attron(A_BLINK);
		mvprintw(nrows-1,cm-15,"(c) Razvan Buhaianu - 313CC  ");
		attroff(A_BLINK);
		mvprintw(0,cm-4,"=2 0 4 8=");
		mvprintw(rm+3,cm-39,"Mutari:");
		attron(A_STANDOUT|A_DIM);
		mvprintw(rm+7,cm-33," A ");
		mvprintw(rm+7,cm-29," S ");
		mvprintw(rm+7,cm-25," D ");
		mvprintw(rm+7,cm-11," X: AUTOMOVE ");
		mvprintw(rm+5,cm-29," W ");
		mvprintw(rm+5,cm-11," U: UNDO ");
		mvprintw(rm+3,cm-11," Q: QUIT ");
		attroff(A_STANDOUT|A_DIM);
		mvprintw(rm-3,cm+20,"Scor:%d",scor);
		if((c=='x') || (c==ERR))
			c=auto_move(mat);
		if(c=='w')
		{
			vs=moveup(mat);
			if(vs!=1)
				scor=scor+vs;
		}
		if(c=='s')
		{
			vs=movedown(mat);
			if(vs!=1)	
				scor=scor+vs;
		}
		if(c=='a')
		{
			vs=moveleft(mat);
			if(vs!=1)		
				scor=scor+vs;
		}
		if(c=='d')
		{
			vs=moveright(mat);
			if(vs!=1)
				scor=scor+vs;
		}
		if(c=='u')
		{
			undo(mat,matant);
			scor=scorant;
		}
		if(c=='q')
		{
			save(mat,scor);
			break;
		}
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
				if(mat[i][j]==0)
			{
				mvprintw(rm-7+i*2,cm-9+j*6,"--");
			}
			else
			{
				if(mat[i][j]==2)
				{	
					attron(COLOR_PAIR(5));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(5));
				}
				if(mat[i][j]==4)
				{	
					attron(COLOR_PAIR(1));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(1));
				}
				if(mat[i][j]==8 || mat[i][j]==512)
				{	
					attron(COLOR_PAIR(2));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(2));
				}
				if(mat[i][j]==16 || mat[i][j]==256)
				{	
					attron(COLOR_PAIR(3));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(3));
				}
				if(mat[i][j]==32 || mat[i][j]==1024)
				{	
					attron(COLOR_PAIR(4));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(4));
				}
				if(mat[i][j]==64 || mat[i][j]==2048)
				{	
					attron(COLOR_PAIR(6));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(6));
				}
				if(mat[i][j]==128)
				{	
					attron(COLOR_PAIR(7));
					mvprintw(rm-7+i*2,cm-9+j*6,"%d",mat[i][j]);
					attroff(COLOR_PAIR(7));
				}
				
			}
		}
		mvprintw(rm-3,cm+20,"Scor:%d",scor);
		refresh();
		verif=verificare(mat);
		if(verif==1)
			{
				usleep(2000000);
				break;
			}
		if(verif==2)
			break;
			
	}
	if(verif==(2))
		you_lose(scor);
	if(verif==(1))
		you_win(scor);
	return main_menu();
}
