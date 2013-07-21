/******************************************
 *                                         
 * Official Name:  Lyle Moffitt         
 *
 * Section: 1 (3:45)  
 *                                        
 * E-mail:  ljmoffit@syr.edu               
 *                                         
 * Assignment:   Final Project
 *                                         
 * Environment/Compiler:  Xcode 3.2.6               
 *                                         
 * Due Date:  May 2, 2013               
 *                                         
 *******************************************/
/*****************************************************************
 *                                                                
 *	1. Problem:                                                    
 *		
 *	2. Analysis:                                                   
 *		Input:
 *			
 *		Output:
 *			
 *		Formulas:
 *
 *		Dialogue:
 *
 *		Examples:                   
 *                                                                
 *	3. Algorithm:                                                  
 *		
 *                                                             
 *	5. Testing:
 *		
 
 ******************************************************************/
/*****************************************************************
	TO DO List : Not in any particular order
 ******************************************************************************************
 
 * Write Dictionary compiler
 
 * Parse Dictionary into letter files
 
 * Create Search database for Dictionary
 
 * Debug.. Debug for documentation
 
 * Write Menus
 
 * Fix #Ctrl
 
 * Write save/load feature
 
 * Write Highscore ranker
 
 * Write Algorithms for all functions
 
 * http://lcs.syr.edu/faculty/baruch/ecs102/Assignments/projectCompletion.html
 
  ******************************************************************************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 16

/* --------------------------------------------------------------------------------- *
 * ---------------------------  Function Prototypes  ------------------------------- *
 * --------------------------------------------------------------------------------- */

char NorY(void);								// Function to fetch and verify (Y/N) questions.
void Draw_board(int size, char tiles[][MAXLEN], char rack[]);
												// Draws the board and rack
void border(int size);							// Draws the border of the playing board
int read_in(char word[],int vector[]);			// Scanning input and stores. Return is length.
void new_game(int size, int tile_bag[],char tiles[][MAXLEN], char rack[]);
												// Re-initializes boards and vars to play again
char next_tile(int tile_bag[]);					// Returns the next letter in the stack
void fill_rack(int tile_bag[], char rack[]);	// Fills the letter rack from the bag
void empty_rack(char rack[]);					// Removes the used letters from the letter rack
int check_rack(char word[],int vector[], char tiles[][MAXLEN], char rack[]);		
												// Checks that the submitted word is in the rack
int check_space(char word[],int size, char tiles[][MAXLEN], int vector[]);
												// Checks that there is enough space for the given word
void place_word(char word[], char tiles[][MAXLEN], int vector[]);
												// Places word on the board
int show_rules();								// Prints all the rules and explains the game. Return 1 to Quit
void end_game(int *end);						// Player ends the game.
int hash_check();								// Checks to see if the user entered a #CONTROLL string
int get_length(char str[]);						// Returns the length (non-zero indexes) of a string
void save_game(void);							// Saves the game
void Ctrl(int sum_ctrl_char);					// Activates appropriate #CTRL action




/* --------------------------------------------------------------------------------- *
 * ---------------------------  Begin MAIN Function  ------------------------------- *
 * --------------------------------------------------------------------------------- */
int main()
/* ----- Algorithms -------

 1) Generate the letters	
 2) Print the board
 3) Start playing
	 1) Ask for placement
	 2) Check that word fits
	 3a)It fits, so check for valid placement
	 3b)It doesn't, so ignore input
	 4a)It's valid so stick it on the board
	 5) In any case return to step 1 
 4) Run out of space
 5) Check that all words are spelled correctly
 6) Tally up points.
 7) Award score
 8) Offer to save the game
 9) Ask to play again -> Return to step 1 */
{
	int i=0,end=0;
	int bool[2];
	double high_score=0.123;
	char tiles[MAXLEN][MAXLEN];	// Array to hold tiles placed on the board: {row,column}
	char tag[20];				// String to hold the player's gamer tag
	int  size=0;				// Size of the board
	int tile_bag[226];			// Array of mixed tiles. 15^2 + 1 = 226
								/* If i wanted to have an array of pointers i could use
	char *letters[] = {*p1,*p2,...};
								 * This works because an array IS a pointer.
								 * I could use this to create an array of Files.  */
	char rack[9];			    // Your rack of 8 letters
	int word_length=0;		    // Length of the most recent wordup or down)
	int vector[3];				// Starting position: {direction, row, column}
/*	int hash_ctrl=0;	*/		// Indicates presence of #COMMAND use 
	char word[MAXLEN];			// String for holding the submitted word


		
	srand(time(0));
	
	
	printf("This is Lexical-Density.\n A word game that you play on your own to get better at Scrabble.");
	printf("\n\n If at anytime you would like to see the rules or quit the game,\nsimply type #RULES or #QUIT .");

	printf("\n\nAre you a new player (Y/N)?\n>> ");
	switch (NorY()) {
		case 'Y':
			printf("Welcome to the game. Would you like to hear the rules?\n>> ");
			if (NorY() == 'Y') {show_rules();}
			printf("\nOkay! Let's get started.");
			break;
		case 'N':
			printf("Welcome back! What is your tag?\n>> ");
			// >>Lylr
			scanf("%s",tag);
			printf("There are no saved games for '%s'.\n",tag);
			printf("Did you misspell it (Y/N)?\n>> ");
			if (NorY() == 'Y')
			{
				printf("That's ok you'll get better after a few games.");
				printf("What is your tag?");
				// >> Lyle
				scanf("%s",tag);
			}
			
			printf("Hello again %s. Your highest score is %lf.",tag,high_score);
			printf("\nLet's see if you can beat it...\n\n");
			break;

		default:
			printf("ERROR");
			break;
	}
	
	printf("How big of a board would you like (5-%d)?\n>> ",MAXLEN);
	scanf("%d",&size);
	while ((size > MAXLEN-1) || (size < 5))								// Check to make sure the selected size is within bounds
	{
		printf("Im sorry, %d is not a valid option.",size);
		printf("\nPlease enter a value between 5 and %d, inclusive.\n>> ",MAXLEN);
		scanf("%d",&size);
	}
	if (size%2 == 0)												// If even, round up
		{					
		printf("Scrabble boards are always an odd size.");
		if (size == 6) {
			size =5;												// Except if size == 6
		}else {
			size+=1;
		}
	}
	printf("\nRight. Board size %d it is. Let's play!\n\n",size);
	
// 1) Generate the letters
	new_game(size,tile_bag,tiles,rack);								// Initialize a bunch of stuff
	fill_rack(tile_bag, rack);
	
// 2) Print the board
	Draw_board( size, tiles, rack);									// Proper function call for tiles[][] and rack[]	

// 3) Start playing
// 3.1) Ask for placement
	printf("What word would you like to play?\n>> ");
	word_length = read_in(word,vector);
	if (word_length<0){
		end=0-word_length;}						// Hashcheck
	while (end==0) 
	{
//3.2) Check that word fits
//3.3a)It fits, so check for valid placement
		bool[0]=0; bool[1]=0;
		bool[0]= check_space(word,size,tiles,vector);				// Checks that there is enough space for the given word
		bool[1]= check_rack(word,vector,tiles, rack);				// Checks that the submitted word is in the rack
		
		if (bool[0]==1 && bool[1]==1) 
		{					
//3.4a)It's valid so stick it on the board
			i=0;
			place_word(word, tiles,vector);							// Places word on the board
			empty_rack(rack);										// Removes the used letters from the letter rack
			fill_rack(tile_bag, rack);								// Fills the letter rack from the bag
			Draw_board(size, tiles, rack);
			printf("Excellent. What word would you like to play next?\n>> ");
			word_length = read_in(word,vector);
			if (word_length<0){
				end=0-word_length;}				// Hashcheck
		
//3.3b)It doesn't, so ignore input
		} else {
			i++;
			if (i<=5) {
// 4) Run out of space
				printf("\nI'm sorry, but that just won't work.");
				printf("\nWhy don't you try something else?\n>> ");
				word_length = read_in(word,vector);
				if (word_length<0){
					end=0-word_length;}			// Hashcheck
			}else {
				printf("\nYou seem to be having a lot of trouble playing a word.");
				printf("\nIf you can't play any more words, type #END .");
				word_length = read_in(word,vector);
				if (word_length<0){
					end=0-word_length;}			// Hashcheck
			}
		}
//3.5) In any case return to step 3.1
	}
	

// 5) Check that all words are spelled correctly
// 6) Tally up points.
// 7) Award score
// 8) Offer to save the game
// 9) Ask to play again -> Return to step 1

	return(0);
}



/* --------------------------------------------------------------------------------- *
 * ---------------------------  Function Definitions ------------------------------- *
 * --------------------------------------------------------------------------------- */

char NorY(void)								// Function to fetch and verify (Y/N) questions.
{
	char response;
	int flag=0;
	while (flag!=1)
	{
		scanf(" %c", &response);
		switch (response)
		{
			case 'Y':
			case 'y':
				flag=1;
				return('Y');
				break;
			case 'N':
			case 'n':
				flag=1;
				return('N');
				break;
			default:
				printf("Only [y]es or [n]o responses will be accepted.\n>> ");
				break;
		}
	}
	printf("ERROR"); // Should never get here. Strictly for debug.
	return('E');
}

void Draw_board(int size, char tiles[][MAXLEN], char rack[])	// Function for drawing the board
/*	Program should draw a board that looks like this (roughly)
	This board happens to be for board=5
                                                                           
      A   B   C   D   E				Value:
    + - + - + - + - + - +			1  EAION
 01 |   |   |   |   |   |			1  RTLSU	
    + - + - + - + - + - +			2  DG			
 02 |   |   |   |   |   |			3  BCMP			
    + - + - + - + - + - +			4  FHVWY
 03 |   |   | @ |   |   |			5  K			
    + - + - + - + - + - +		    8  JX
 04 |   |   |   |   |   |			10 QZ
    + - + - + - + - + - +			
 05 |   |   |   |   |   |			
    + - + - + - + - + - +			

Your Letters: A G E L E I F R
 */
{
	int row,column,i;
	char values[MAXLEN][9] = {"1  EAION","1  RTLSU","2  DG","3  BCMP","4  FHVWY","5  K","8  JX","10 QZ"," "," "," "," "," "," "," "," "};
// 1) Print the row lettering
	printf("\n\n      ");
	for (column=1; column<=(size); column++)
	{
		printf("%c   ",(char)(column+64));
	}
// 2) Print "Value"
	printf("%10cValue:",' ');
// 3) Print border
	border(size);			// Begins with '\n'
	printf("%11c%s",' ',values[0]);
// 4) Print rows
	for (row=1; row<=size; row++)
	{
		printf("\n %02d |",(row));
		for (column=1; column<=size; column++)
		{
			printf(" %c |",tiles[(row-1)][(column-1)]);
		}
		printf("%11c%s",' ',values[row+row-1]);
		border(size);
		printf("%11c%s",' ',values[row+row]);
	}
// 5) Print letter rack
	printf("\n\nYour Letters:");
	for (i=0; i<8; i++) {printf("%2c",rack[i]);}
	printf("\n\n");
	
	// END OF FUNCTIION CALL
}
	
void border(int size)						// Function to draw the top and bottom of each row
{
	int i;
	printf("\n    +");
	for (i=1; i<=size; i++) {
		printf(" - +");
	}
}

void new_game(int size, int tile_bag[],char tiles[][MAXLEN],char rack[])		
											// Initializes boards and vars to play again
{
					// {A,B,C,D, E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z}
	int ref_freq[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
	int freq_dst[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
	int i,r,s,t,x,y;						// Incrementor, Random holder, and Stop counter
	
// Wipe the board blank
	for (y=0; y<MAXLEN; y++)
	{
		for (x=0; x<size; x++)
		{tiles[y][x] =  ' ';}
		for (x=size; x<MAXLEN; x++)
		{tiles[y][x] =  '\0';}
	}
	for (y=size; y<MAXLEN; y++)
	{
		for (x=size; x<MAXLEN; x++)
		{tiles[y][x] =  '\0';}
	}
	tiles[size/2][size/2] = '@';
	
//Populate tile_bag[] with tiles chosen at random
	tile_bag[0] = size * size;
	
	for (i=1; i<=tile_bag[0]; i++)			// Create the "stack" or letter bag
	{
		r=rand()%26;
		s=0;
		while (freq_dst[r]<=0)				// Check to see if letter has been picked too much
		{
			r=rand()%26;
			s++;
			if (s>40)						// Reloads the freq distribution if more than 40 zeros in a row
			{
				s=0;			
				for (t=0; t<26; t++) {
					freq_dst[t] = ref_freq[t];
				}
			}
		}
		tile_bag[i] = 65+r;					// (char)65 = 'A'
		freq_dst[r] = freq_dst[r] - 1;
	}

// Fill letter rack with spaces ( underscores )
	for (i=0; i<8; i++) {
		rack[i] = '_';
	}
	rack[9]='\0';
}	
	
char next_tile(int tile_bag[])				// Returns the next letter in the stack
{
	int position;
	char letter;
	
	position = tile_bag[0];					// Index0 stores the position of the next char
	letter = (char)tile_bag[position];		// Letters in the array are int
	position = position - 1;				// Decrement the position is the next char
	tile_bag[0] = position;					// Update the position index
	
	return(letter);	
}
	
void fill_rack(int tile_bag[], char rack[])	// Fills the letter rack from the bag
{
	int i;
	
	for (i=0; i<8; i++)						// Move through rack[] looking for '_'
	{
		if (rack[i]=='_')					// If rack slot is empty, fill it
		{	rack[i] = next_tile(tile_bag);	}
	}
}

void empty_rack(char rack[])				// Removes the used letters from the letter rack
{
	char temp[9]={'\0','\0','\0','\0','\0','\0','\0','\0'};
	int i,p=0;
	
	for (i=0; i<8; i++)			// Goes through rack[] and removes '#'
	{
		if (rack[i] != '#')		// '#' is the flag char that removed letters are replaced with
		{	temp[p]=rack[i]; p++;	}
		
	}
	for (i=p; i<8; i++)			// Fill remainder with  '_'
	{	temp[i] = '_';	}
	
	for (i=0; i<8; i++)			// Read tiles back into rack[]
	{	rack[i]=temp[i];	}
}

int check_rack(char word[],int vector[], char tiles[][MAXLEN], char rack[])
											// Checks that the submitted word is in the rack
{
	char used[9] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char temp[9] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	int board[MAXLEN-1] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i=0,k=0,c=0,b=0,length,m=0;
	
	length = get_length(word);
	
	switch (vector[0])						// Look to see what letters in word[] are already in play
	{
		case 1:								// Horizontal or RIGHT
			for (i=0; i<length; i++)	
			{
				if ( tiles[vector[1]][(vector[2]+i)] == word[i] ){	board[i]=1;	b++;	}
			}
			break;
	
		case -1:							// Vertical or DOWN
			for (i=0; i<length; i++)	
			{
				if ( tiles[(vector[1]+i)][vector[2]] == word[i] ){	board[i]=1;	b++;	} 
			}
			break;
	}
	
	for (i=0; i<length; i++)				// Pick out the letters of word[] that are from the rack
	{
		if (board[i]==0) {	used[k]=word[i];	k++;	}
	}

	for (i=0; i<8; i++)						// Read rack[] into temp[]
	{	temp[i]=rack[i];	}
	
	for (i=0; i<k; i++)						// Look in temp[] for the letters used[]
	{
		if (used[i]=='\0')					// NULL char will be assigned to empty blocks in word[] string
		{	break;	}
		m=0;
		while (m<8)		
		{
			if (used[i] == temp[m])			// Look for match
			{	
				temp[m] = '#';
				c++;
				m=8;						// Match found -> exit loop
			}
			m++;							// Match not found -> increment and continue
		}
	}
	if ( (length - b) == c )				// 'b' is the number of letters in word[] that are on the board
	{
		for (i=0; i<8; i++) 
		{	rack[i] = temp[i];	}			// Fill used letter spaces in rack with '#'
		return(1);
	} else {
		return(0);
	}
}

int check_space(char word[], int size, char tiles[][MAXLEN],int vector[])
											// Checks that there is enough space for the given word
{
	/* -- Algorithm --
	 * 1) Find vector axis:
	 *		 1 = "Right" & Fills a row
	 *		-1 = "Down" & Fills a column
	 * 2) Read matching positon row or column
	 * 3) Check length
	 *		Axis= 1
	 *			IF (column)+(length) > (size-1) -> FAIL
	 *		Axis=-1
	 *			IF (row)+(length) > (size-1) -> FAIL
	 * 4) Check tile mismatch
	 *		Axis= 1
	 *			IF word[i] != tiles[ vector[1] ][ vector[2] + i ]  -> FAIL
	 *		Axis=-1
	 *			IF word[i] != tiles[ vector[1] + i ][ vector[2] ]  -> FAIL
	 * 5) Did not FAIL -> Return 1
	 */
	int check1=0,flag=1,i=0,length;
	int check2[MAXLEN] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	length=get_length(word);
	
	switch (vector[0])						// Vector[] = {Direction,Row, Column}
	{
		case 1:								// Horizontal or RIGHT
			if ( (vector[2] + length) <= size ) {	check1=1;	}
			
			for (i=0; i<length; i++)		// 1 = PASS, 0 = Fail, 2 = Intersection
			{
				if ( tiles[vector[1]][(vector[2]+i)]=='@' ) {
					check2[i]=-1;
				} else if ( tiles[vector[1]][(vector[2]+i)]==' ' ) {
					check2[i]= 1; 
				} else if ( tiles[vector[1]][(vector[2]+i)]==word[i] ) {
					check2[i]= 2;
				} else {
					check2[i]= 1;
				}
				flag = flag * check1 * check2[i];
			}
			break;
	
		case -1:							// Vertical or DOWN
			if ( (vector[1] + length) <= size ) {	check1=1;	}
			
			for (i=0; i<length; i++)		// 1 = PASS, 0 = Fail, -1 = GAMESTART
			{
				if ( tiles[(vector[1]+i)][vector[2]]==' ' ) {
					check2[i]= 1; 
				} else if ( tiles[(vector[1]+i)][vector[2]]==word[i] ){
					check2[i]= 2;
				} else if ( tiles[(vector[1]+i)][vector[2]]=='@' ) {
					check2[i]=-1;
				} else {
					check2[i]= 1;
				}
				flag = flag * check1 * check2[i];
			}
			break;
		default:
			printf("\nERROR: Space check mismatch.");
			break;
	}
	
	if ( ((flag%2==0)&&(flag!=0)) || (flag==-1) ) {
		return(1);
	} else {
		return(0);
	}
	
}

int read_in(char word[],int vector[])		// Scans input and parses. Return is word length or -1
{
	int i,k=0,m=0,x=0,y=0,z=0,flag=0,length=0;
	char input[MAXLEN];
	int row[]={99,99};
	
	for (i=0; i<3; i++) {vector[i]=99;}
	for (i=0; i<MAXLEN; i++) {word[i]='\0';}
	
	while ( ((x!=1) || (y!=2)) && (z!=3) )	// Verify that input has BOTH vector[], word[]
											// OR that input has #CONTROL
	{
		m++;
		for (i=0;i<=MAXLEN;i++){input[i]='\0';}	// Initialize input[]
		
		scanf("%s",input);					// Read in as string
		i=0; k=0; flag=0;
		while( input[i]!='\0')				// Determine string kind based on contents
		{
			if ( (input[i]>='a') && (input[i]<='z') )	
			{
				input[i] = (char)((int)input[i] - 32);
			}								// Convert to UPPERCASE
			
			switch (input[i])				// Sort string kind
			{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					flag=2;					// String is position
					break;
				case '#':					// Contains a hashtag '#'
					flag=3;					// String is hash-control
					break;
				case ((char)34):			// string is "WORD" 
				case ((char)39):			// string is 'WORD'
					flag=1;
					break;
				default:
					if (flag==0) {flag=2;}	// Position deliminated with spaces
					if (get_length(input)<=2)
					{	flag=2;	}			// Too short to be a word
					break;
			}
			i++;
		}
		switch (flag)						// Parse string
		{
			case 1:							// String is word
				length=0;
				for (i=0; i<MAXLEN; i++)
				{
					if (input[i]>='A')		// Fill word[]. Count length
					{
						word[length]=input[i];
						length++;
					}
				}
				x=1;
				break;
				
			case 2:							// String is position
				i=0; k=0;
				while (input[i]!='\0')
				{
					// Parse Vector
					if (input[i]=='X')		// X = "Right"
					{	vector[0]=  1;	k=0;	}
					if (input[i]=='Y')		// Y = "Down"
					{	vector[0]= -1;  k=0;	}
					
					// Parse Column
					if ( (input[i]>='A') &&	// Column letters from 'A' to 'O'
						 (input[i]<='O') )
					{	vector[2]=( (int)input[i]-65 );	k=0;	}
					
					// Parse Row
					if ( (input[i]>='0') &&	// Row num from 0 to 9
						 (input[i]<='9') )
					{	row[k]=( (int)input[i]-48 ); k++;		}
					i++;
				}							// End parse
				
				if (row[1]>9)				// Sum collective number for row
				{ 
					row[1] = row[0];
					row[0] = 0;
				}
				if (vector[1]>MAXLEN) {
					vector[1] = (row[0] * 10) + (row[1]-1);
				}
				k=0;
				for (i=0; i<3; i++) 
				{	k = k + vector[i];	}	// Sum vector[] for parity check
				if (k<32) {
					y=2;
				} else {
					row[0] = 99;
					row[1] = 99;
					k=0;
				}
				
				break;
				
			case 3:							// String is #CTRL
				for (i=0; i<get_length(input); i++) {
					length += (int)input[i];
				}
				switch (length)				// Determine which it is
				{
					case 430:				// "#RULES"
						show_rules();
						length = 0;
						break;
					case 358:				// "#QUIT"
					case 250:				// "#END"
						length = -1;
						break;
					case 350:				// "#SWAP"
						
						break;
					default:
						length=0;
						printf("\nNot a recognized #CONTROL .");
						break;
				}
				z=3;
				break;
				
			default:
				printf("ERROR: No parse match");
				break;
		}
		if (m>5) {
			printf("ERROR: Too many inputs");
			break;
		}
	}
		
	 return(length);						// Return the length(int) of the word or (-1)
}
		
int show_rules()							// Prints all the rules and explains the game
{
	char option='\0';
	
	printf("\n\n");
	printf("		Welcome to the Lexical-Density #RULES page.\n");
	
	printf("Which section would you like to see?\n");
	printf("1) Introduction \n2) Gameplay \n3) Winning \n4) Saving \n5) Exit\n\n");
	
	while (option<49 || option>53) {	scanf("%c",&option);	}
	
	switch (option)
	{
		case '1':
		{
			printf("1) INTRODUCTION\n\n");
			
			printf("The goal of the game is to put as many words on the board as possible. \n");
			printf("Playing is easy, if you know how to play Bananagrams and/or Scrabble, \n");
			printf("than you should have no problems playing this game. However, to win you \n");
			printf("will need to think outside the box (or /inside/ the box in this case). \n");
			printf("The goal of the game is to place as many words as possible in the \n");
			printf("smallest area possible, using letters as efficiently as possible. \n");
		}
			break;

		case '2':
		{
			printf("2) GAME PLAY\n\n");
			
			printf("Every turn you will be given letters up the up to the size of your \n");
			printf("board. From these you must pick those you wish to place on the board. On \n");
			printf("the first turn, your word must intersect the starting character '@'. On \n");
			printf("every subsequent turn your word must intersect some portion of the what \n");
			printf("is already on the board. Words may overlap, be lengthened and can even \n");
			printf("be overwritten. Be careful though, you the total number of letters you \n");
			printf("get is equal to the number of spots on your board.\n\n");
			
			printf("When playing words, you must specify:\n");
			printf("- The WORD with quotes (\" or ')\n");
			printf("- The COLUMN (A,B,C,D,..etc.)\n");
			printf("- The ROW number\n");
			printf("- What AXIS you want your letters placed on (X or Y)\n");
			
			printf("If you are stuck you also have the option to #TRASH letters that you \n");
			printf("can't use. \n");
		}
			break;
			
		case '3':
		{
			printf("3) WINNING\n\n");
			
			printf("At the end of play the number of correctly spelled words on the board \n");
			printf("will be tallied and scored according to the per letter point-values of \n");
			printf("Scrabble. Incorrectly spelled words will be subtracted from this score. \n");
			printf("You word-score will then by your by the area of the board (hence the \n");
			printf("name \"Lexical-Density\").\n\n");
			
			printf("When calculating the Lexical-Density of the board, any adjacent sequence \n");
			printf("of letters will be counted as a word. All 'words' will be checked \n");
			printf("against the SOWPODS dictionary, so regular Scrabble rules apply in terms \n");
			printf("of word choice.\n");
		}
			break;
			
		case '4':
		{
			printf("4) SAVING\n\n");
			
			printf("You may #SAVE your game at anytime. Players using a specified 'tag' are \n");
			printf("able to save multiple completed games, and will be able to see pertinent \n");
			printf("statistics across them.\n");
			printf("\n\n");
		}
			break;
			
		case '5':
		{
			printf("5) QUIT\n\n");
			printf("Would you like to save your game before quitting?");
			option = NorY();
			if (option == 'Y') {	save_game();	}
			return(1);
		}
			
		default:
			printf("\n\nBAD INPUT\n\n");
			break;
	}
	return(0);
}

int get_length(char str[])					// Returns the length (non-zero indexes) of an array or string
{
	int l=0,i=0;
	while (str[i]!='\0')
	{
		l++;
		i++;
	}
	
	return(l);
}

void place_word(char word[], char tiles[][MAXLEN], int vector[])		// Places word on the board
{
	int i=0,length;
	
	length=get_length(word);
	
	for (i=0; i<length; i++)	
	{
		switch (vector[0]) 
		{
		case 1:								// Vertical or DOWN
			tiles[vector[1]][(vector[2]+i)] = word[i];
			break;
				
		case -1:							// Vertical or DOWN
			tiles[(vector[1]+i)][vector[2]] = word[i];
			break;
		}
	}
}

void save_game(void)
{
	printf("\nGame saved.");
}











