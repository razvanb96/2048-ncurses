//Functie pentru verificarea castigului
//sau pierderii jocului
int verificare(int mat[4][4])
{
	int i,j,zero=0,win=0,s=0;
	/*************************
	verific daca am 2048
	*************************/
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(mat[i][j]==2048)
				win=1;
		}
	if(win==1)
		return 1;
	/*******************************************************
	Realizez o copie a matricii, copie careia ii efectuez 
	toate mutarile posibile pentru a verifica 
	daca mai exista mutari valide
	********************************************************/
	int copie[4][4];
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			copie[i][j]=mat[i][j];
	s=moveup(copie);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(copie[i][j]!=mat[i][j])
				return 0;
			copie[i][j]=mat[i][j];
		}
	s=movedown(copie);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(copie[i][j]!=mat[i][j])
				return 0;
			copie[i][j]=mat[i][j];
		}
	s=moveleft(copie);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(copie[i][j]!=mat[i][j])
				return 0;
			copie[i][j]=mat[i][j];
		}
	s=moveright(copie);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(copie[i][j]!=mat[i][j])
				return 0;
			copie[i][j]=mat[i][j];
		}
	return 2;
}
//Functie pentru interschimbul
// matricii actuale cu matricea anterioara
void undo(int mat[4][4],int matant[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			mat[i][j]=matant[i][j];
}
//Functie pentru auto_move
//returneaza caracterul 'x'
char auto_move(int mat[4][4])
{
	int i,j,s,care,max,smax;
	int copie[4][4],zero[4],scor[4];
	for(i=0;i<4;i++)
		zero[i]=0;
	/******************************************************
	realizez o copie a matricii, careia ii aplic toate 
	tipurile de mutari, in vederea obtinerii numarului 
	maxim de casute liber,si scorul obtinut in respectivele
	i
	******************************************************/
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			copie[i][j]=mat[i][j];
	s=moveup(copie);
	if(s==1)
		zero[0]=-1;
	else
	{
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				if(copie[i][j]==0)
					zero[0]++;
				copie[i][j]=mat[i][j];
			}
		scor[0]=s;
	}
	s=movedown(copie);
	if(s==1)
		zero[1]=-1;
	else
	{
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				if(copie[i][j]==0)
					zero[1]++;
				copie[i][j]=mat[i][j];
			}
		scor[1]=s;
	}
	s=moveleft(copie);
	if(s==1)
		zero[2]=-1;
	else
	{
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				if(copie[i][j]==0)
					zero[2]++;
				copie[i][j]=mat[i][j];
			}
		scor[2]=s;
	}
	s=moveright(copie);
	if(s==1)
		zero[3]=-1;
	else
	{
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				if(copie[i][j]==0)
					zero[3]++;
				copie[i][j]=mat[i][j];
			}
		scor[3]=s;
	}
	max=0;smax=-1;
	for(i=0;i<4;i++)
		if(zero[i]>max)
		{
			max=zero[i];
			care=i;
		}
	for(i=0;i<4;i++)
		if(zero[i]==max)
			if(scor[i]>smax)
			{	
				smax=scor[i];
				care=i;
			}
	/********************************************
	functia returneaza carcterul pentru mutarea care
	a eliberat cel mai mare numar de casute si a 
	obtinut punctajul cel mai mare
	*********************************************/
	if(care==0)
		return 'w';
	if(care==1)
		return 's';
	if(care==2)
		return 'a';
	if(care==3)
		return 'd';
}
//Functie pentru Umplerea aleatorie a unei casute din
//matrice cu 2 sau cu 4
void aleatoriu(int mat[4][4])
{ 
    int n,m,v,ok=0;	
	time_t seconds;
	time (&seconds);
	srand(((unsigned int) seconds));
	/************************************************
	in n si m voi obtine(prin rand modulo 4) viitoarele
	coordonate pentru casuta ce o voi umple daca e 0 cu
	valoarea data de 2^ rand modulo 2
	************************************************/
	while(ok==0)
	{	
		n=rand()%4;
		m=rand()%4;
		v=rand()%2+1;
		if(mat[n][m]==0)
		{
			mat[n][m]=pow(2,(double)v);
			ok=1;
		}
	}
}
//Funcite pentru mutare si alipire spre NORD/SUS
int moveup(int mat[4][4])
{
	int i,j,k,s=0,mutare=0;
	int v[4];
	/************************************************
	Memorez fiecare coloana a matricii intr-un vector v
	doar daca valoarea respectiva difera de 0 , apoi, 
	pana la completarea vectorului adaug 0 in acesta;
	Retin numarul de mutari pe care il realizez;
	************************************************/
	for(j=0;j<4;j++)
	{
		k=0;
		for(i=0;i<4;i++)
		{	
			if(i<3)
				if(mat[i][j]==0)
					if(mat[i+1][j]!=0)
						mutare++;
			if(mat[i][j]!=0)
			{
				v[k]=mat[i][j];
				k++;
			}
		}
		for(i=k;i<4;i++)
			v[i]=0;
	/************************************************
	Prin parcurgerea vectorului verific daca 2 casute
	alaturate sunt egale si le unesc, mutand elementele
	din vector cu cate o casuta, si adaugand 0 in capat;
	retin numarul de mutari si scorul pe care il realizez;
	************************************************/
		for(i=0;i<3;i++)
		{
			if((v[i]==v[i+1]) && (v[i]!=0))
			{
				v[i]=2*v[i+1];
				s=s+v[i];
				mutare++;
				k=i+1;
				while(k<3)
				{
					v[k]=v[k+1];
					k++;
				}
				v[k]=0;
			}
		}
	/************************************************
	actualizez matricea cu vectorul obtinut
	************************************************/
		for(i=0;i<4;i++)
			mat[i][j]=v[i];
	}
	/************************************************
	daca s-a realizat macar o mutare adaug in matrice 
	o valoare aleatorie si returnez scorul obtinut
	(0 sau mai multiplu de 2;
	Daca nu returnez scorul 1, scor ce este codificat
	ca eroare;
	************************************************/
	if(mutare!=0)
		aleatoriu(mat);
	else
		s=1;
	return s;
}
//Exact ca moveup
int movedown(int mat[4][4])
{
	int i,j,k,s=0,mutare=0;
	int v[4];
	for(j=0;j<4;j++)
	{
		k=0;
		for(i=3;i>=0;i--)
		{	if(i>0)
				if(mat[i][j]==0)
					if(mat[i-1][j]!=0)
						mutare++;
			if(mat[i][j]!=0)
			{
				v[k]=mat[i][j];
				k++;
			}
		}
		for(i=k;i<4;i++)
			v[i]=0;
		for(i=0;i<3;i++)
		{
			if((v[i]==v[i+1]) && (v[i]!=0))
			{
				v[i]=2*v[i+1];
				s=s+v[i];
				mutare++;
				k=i+1;
				while(k<3)
				{
					v[k]=v[k+1];
					k++;
				}
				v[k]=0;
			}
		}
		for(i=3;i>=0;i--)
			mat[i][j]=v[3-i];
	}
	if(mutare!=0)
		aleatoriu(mat);
	else
		s=1;
	return s;
}
//Exact ca moveup
int moveleft(int mat[4][4])
{
	int i,j,k,s=0,mutare=0;
	int v[4];
	for(i=0;i<4;i++)
	{
		k=0;
		for(j=0;j<4;j++)
		{	if(j<3)
				if(mat[i][j]==0)
					if(mat[i][j+1]!=0)
						mutare++;
			if(mat[i][j]!=0)
			{
				v[k]=mat[i][j];
				k++;
			}
		}
		for(j=k;j<4;j++)
			v[j]=0;
		for(j=0;j<3;j++)
		{
			if((v[j]==v[j+1]) && (v[j]!=0))
			{
				v[j]=2*v[j];
				mutare++;
				s=s+v[j];
				k=j+1;
				while(k<3)
				{
					v[k]=v[k+1];
					k++;
				}
				v[k]=0;
			}
		}
		for(j=0;j<4;j++)
			mat[i][j]=v[j];
	}
	if(mutare!=0)
		aleatoriu(mat);
	else
		s=1;
	return s;
}
//Exact ca moveup
int moveright(int mat[4][4])
{
	int i,j,k,s=0,mutare=0;
	int v[4];
	for(i=0;i<4;i++)
	{
		k=0;
		for(j=3;j>=0;j--)
		{	if(j>0)
				if(mat[i][j]==0)
					if(mat[i][j-1]!=0)
						mutare++;
			if(mat[i][j]!=0)
			{
				v[k]=mat[i][j];
				k++;
			}
		}
		for(j=k;j<4;j++)
			v[j]=0;
		for(j=0;j<3;j++)
		{
			if((v[j]==v[j+1]) && (v[j]!=0))
			{
				v[j]=2*v[j];
				s=s+v[j];
				mutare++;
				k=j+1;
				while(k<3)
				{
					v[k]=v[k+1];
					k++;
				}
				v[k]=0;
			}
		}
		for(j=3;j>=0;j--)
			mat[i][j]=v[3-j];
	}
	if(mutare!=0)
		aleatoriu(mat);
	else
		s=1;
	return s;
}
