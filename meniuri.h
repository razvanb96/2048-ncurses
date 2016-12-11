//Functie care schimba Highlit-ul pe elementul din meniu
// ce primeste ca parametrii pozitia veche si o returneaza
//pe cea noua
int schimb(int old,int new,int rm,int cm)
{
	int poz;
	char *s;
	if(old==1)
	{	
		move(rm-3,cm-5);
		s=" NEW  GAME ";
		attroff(A_STANDOUT);
		addstr(s);
		if(new==-1)
		{
			move(rm+3,cm-3);
			s=" CLOSE ";
			attron(A_STANDOUT);
			addstr(s);
			poz=4;
		}
		else
		{
			move(rm-1,cm-3);
			s=" RESUME ";
			attron(A_STANDOUT);
			addstr(s);
			poz=2;
		}
	}
	if(old==2)
	{	
		move(rm-1,cm-3);
		s=" RESUME ";
		attroff(A_STANDOUT);
		addstr(s);
		if(new==-1)
		{
			move(rm-3,cm-5);
			s=" NEW  GAME ";
			attron(A_STANDOUT);
			addstr(s);
			poz=1;
		}
		else
		{
			move(rm+1,cm-5);
			s=" HIGH SCORE ";
			attron(A_STANDOUT);
			addstr(s);
			poz=3;	
		}
	}
	if(old==3)
	{	
		move(rm+1,cm-5);
		s=" HIGH SCORE ";
		attroff(A_STANDOUT);
		addstr(s);
		if(new==-1)
		{
			move(rm-1,cm-3);
			s=" RESUME ";
			attron(A_STANDOUT);
			addstr(s);
			poz=2;
		}
		else
		{
			move(rm+3,cm-3);
			s=" CLOSE ";
			attron(A_STANDOUT);
			addstr(s);
			poz=4;
		}
	}
	if(old==4)
	{
		move(rm+3,cm-3);
		s=" CLOSE ";
		attroff(A_STANDOUT);
		addstr(s);
		if(new==-1)
		{
			move(rm+1,cm-5);
			s=" HIGH SCORE ";
			attron(A_STANDOUT);
			addstr(s);
			poz=3;	
		}
		else
		{
			move(rm-3,cm-5);
			s=" NEW  GAME ";
			attron(A_STANDOUT);
			addstr(s);
			poz=1;
		}
	}
	return poz;	
}
void highscoref(int scor)
{
	WINDOW *hscr;
	int nrows,ncols;
	int c=0,l,i;
	int v[11];
	v[10]=scor;
	citirehighscoref(v);
	hscr=initscr();
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);
	cbreak();
	noecho();
	getmaxyx(hscr,nrows,ncols);
	clear();
	int rm=nrows/2,cm=ncols/2;
	wbkgd(hscr,COLOR_PAIR(1));
	refresh();
	/************************************************
	Sectiune pentru afisare ASCII ART
	************************************************/
	mvprintw(1,cm-40," __   __ ___ _______ __   __ _______ _______ _______ ______   _______ _______ ");
	mvprintw(2,cm-40,"|  | |  |   |       |  | |  |       |       |       |    _ | |       |       |");
	mvprintw(3,cm-40,"|  |_|  |   |    ___|  |_|  |  _____|       |   _   |   | || |    ___|  _____|");
	mvprintw(4,cm-40,"|       |   |   | __|       | |_____|       |  | |  |   |_||_|   |___| |_____ ");
	mvprintw(5,cm-40,"|       |   |   ||  |       |_____  |      _|  |_|  |    __  |    ___|_____  |");
	mvprintw(6,cm-40,"|   _   |   |   |_| |   _   |_____| |     |_|       |   |  | |   |___ _____| |");
	mvprintw(7,cm-40,"|__| |__|___|_______|__| |__|_______|_______|_______|___|  |_|_______|_______|");
	move(0,0);
	for(i=0;i<10;i++)
	{	if(v[i]!=0)
			if((v[i]==scor) &&(c==0))
				{	mvprintw(9+i,cm-11,"->");
					attron(A_STANDOUT);
					mvprintw(9+i,cm-9," %d) \t%d ",i+1,v[i]);
					attroff(A_STANDOUT);
					printw("<-");
					c++;
				}
			else
				mvprintw(9+i,cm-8,"%d) \t%d",i+1,v[i]);
	}
	refresh();
	char d;
	while(1)
	{	
		d=getch();
		d=tolower(d);
		if((d=='q'))
			{
				main_menu();
				break;
			}
		
	}

}

int highscore()
{
	WINDOW *hscr;
	int nrows,ncols;
	int c=0,l,i;
	//int *v;
	//calloc(10,sizeof(int));
	int v[10];
	citirehighscore(v);
	hscr=initscr();
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);
	cbreak();
	noecho();
	getmaxyx(hscr,nrows,ncols);
	clear();
	int rm=nrows/2,cm=ncols/2;
	wbkgd(hscr,COLOR_PAIR(1));
	refresh();
	/************************************************
	Sectiune pentru afisarea ASCII ART
	************************************************/
	mvprintw(1,cm-40," __   __ ___ _______ __   __ _______ _______ _______ ______   _______ _______ ");
	mvprintw(2,cm-40,"|  | |  |   |       |  | |  |       |       |       |    _ | |       |       |");
	mvprintw(3,cm-40,"|  |_|  |   |    ___|  |_|  |  _____|       |   _   |   | || |    ___|  _____|");
	mvprintw(4,cm-40,"|       |   |   | __|       | |_____|       |  | |  |   |_||_|   |___| |_____ ");
	mvprintw(5,cm-40,"|       |   |   ||  |       |_____  |      _|  |_|  |    __  |    ___|_____  |");
	mvprintw(6,cm-40,"|   _   |   |   |_| |   _   |_____| |     |_|       |   |  | |   |___ _____| |");
	mvprintw(7,cm-40,"|__| |__|___|_______|__| |__|_______|_______|_______|___|  |_|_______|_______|");
	move(0,0);
	for(i=0;i<10;i++)
		if(v[i]!=0)
			mvprintw(9+i,cm-8,"%d) \t%d",i+1,v[i]);
	refresh();
	char d;
	while(1)
	{	
		d=getch();
		d=tolower(d);
		if((d=='q'))
			{
				main_menu();
				break;
			}
		
	}
	return 0;
}
int selectie(int poz)
{
	if(poz==1)
		return new_game();
	if(poz==2)
		return resume_game();
	if (poz==3)
		return highscore();
	poz=4;
	if(poz==4)
		return 0;
}
int main_menu()
{
	WINDOW *wnd;
	int nrows,ncols;	
	wnd=initscr();
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);
	cbreak();
	noecho();
	getmaxyx(wnd,nrows,ncols);
	clear();
	wbkgd(wnd,COLOR_PAIR(1));
	refresh();
	/************************************************
	Sectiune pentru afisarea meniului;
	************************************************/
	char *s;
	int rm=nrows/2,cm=ncols/2;
	move(rm-3,cm-5);
	s=" NEW  GAME ";
	attron(A_STANDOUT);
	addstr(s);
	attroff(A_STANDOUT);
	move(rm-1,cm-3);
	s=" RESUME ";
	addstr(s);
	move(rm+1,cm-5);
	s=" HIGH SCORE ";
	addstr(s);
	move(rm+3,cm-3);
	s=" CLOSE ";
	addstr(s);
	move(nrows-1,ncols/2-15);
	attron(COLOR_PAIR(1) | A_BLINK | A_DIM);
	s="(c) Razvan Buhaianu - 313CC  ";
	addstr(s);
	attroff(COLOR_PAIR(1) | A_BLINK | A_DIM);
	move(0,0);
	curs_set(0);
	refresh();
	int d;
	int poz=1;
	keypad(wnd,TRUE);
	/************************************************
	Sectiune pentru realizarea unei selectii prin 
	intermediul tastelor sageata_sus, sageata_jos si q
	prin intermediul functiei schimb, functie ce imi 
	returneaza o pozitie
	************************************************/
	while(1)
	{	
		d=getch();
	
		d=tolower(d);
		if(d=='q')
			break;
		if(d== KEY_UP)
			poz=schimb(poz,-1,rm,cm);
		if(d== KEY_DOWN)
			poz=schimb(poz,1,rm,cm); 
		if(d==10)
		{
			if(selectie(poz)==0)
				break;
		}
	}
	return 0;
}
