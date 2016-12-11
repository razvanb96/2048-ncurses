//Compare function for Qsort
int compara(const void *a, const void *b)
{
	const int *ia= (const int *)a;
	const int *ib = (const int *)b;
	return *ib-*ia;
}
//Loading the maatrix from file
//For the Game Resume
int load(int mat[4][4],int scor)
{
	FILE *ifile;
	ifile=fopen("salvare2048","r");
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			fscanf(ifile,"%d ",&mat[i][j]);
	fscanf(ifile,"%d",&scor);
	fclose(ifile);
	return scor;
}
//Saving the matrix in file
//For Game Resume
void save(int mat[4][4],int scor)
{
	FILE *ifile;
	ifile=fopen("salvare2048","w");
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			fprintf(ifile,"%d ",mat[i][j]);
		fprintf(ifile,"\n");
	}
	fprintf(ifile,"%d",scor);
	fclose(ifile);
}
/**************************************
function for reading and loading in
vector the values from the highscore 
file. Used in the highscore check without
adding a new score
*//////////////////////////////////////////
void citirehighscore(int v[10])
{
	FILE *ifile;
	ifile=fopen("highscores","r");
	int i;
	for(i=0;i<10;i++)
		fscanf(ifile,"%d",&v[i]);
	fclose(ifile);
	
}
/****************************************
Function for read, load, sort and save
in the highscore file of the values.
Used in case of adding a new highscore
*********************************************/
void citirehighscoref(int v[11])
{
	FILE *ifile;
	ifile=fopen("highscores","r");
	int i;
	for(i=0;i<10;i++)
		fscanf(ifile,"%d",&v[i]);
	fclose(ifile);
	qsort(v,11,sizeof(int),compara);
	FILE *ofile;
	ofile=fopen("highscores","w");
	for(i=0;i<10;i++)
		fprintf(ofile,"%d\n",v[i]);
	fclose(ofile);
	
}
