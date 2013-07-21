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
 
 * DONE Write Dictionary compiler
 
 * DONE Parse Dictionary into letter files
 
 * DONE Create Search database for Dictionary
 
 * Debug.. Debug for documentation
 
 * Fix the read_in() function
 
 * Add a not-word search function (with score calc?)
 
 * Write score calculator
 
 * Replace all implementaions of strlen() with strlen()
 
 * Fix the tile bag filler to be a better approximation
 
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
#define RAKLEN 8

/* --------------------------------------------------------------------------------- *
 * ---------------------------  Function Prototypes  ------------------------------- *
 * --------------------------------------------------------------------------------- */

int NorY(void /*scanf*/);						// Function to fetch and verify (Y/N) questions.
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
void save_game(void);							// Saves the game
void Ctrl(int sum_ctrl_char);					// Activates appropriate #CTRL action

int word_searcher(char tiles[][MAXLEN]);		// Finds all the words in tiles[][]
int chk_dict(char query[]);			// Check the dictionary for the given word query
void make_upper( char string[]);  // Convert to UPPERcase
void make_lower( char string[]);	// Convert to lowerCASE


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
	char rack[RAKLEN +1];			    // Your rack of 8 letters
	int word_length=0;		    // Length of the most recent wordup or down)
	int vector[3];				// Starting position: {direction, row, column}
/*	int hash_ctrl=0;	*/		// Indicates presence of #COMMAND use 
	char word[MAXLEN];			// String for holding the submitted word


		
	srand(time(0));
	
	
	printf("This is Lexical-Density.\n A word game that you play on your own to get better at Scrabble.");
	printf("\n\n If at anytime you would like to see the rules or quit the game,\nsimply type #RULES or #QUIT .");

	printf("\n\nAre you a new player (Y/N)?\n>> ");
	switch (NorY()) {
		case 1:
			printf("Welcome to the game. Would you like to hear the rules?\n>> ");
			if (NorY() == 'Y') {show_rules();}
			printf("\nOkay! Let's get started.");
			break;
		case 0:
			printf("Welcome back! What is your tag?\n>> ");
			// >>Lylr
			scanf("%s",tag);
			printf("There are no saved games for '%s'.\n",tag);
			printf("Did you misspell it (Y/N)?\n>> ");
			if (NorY())
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

int NorY(void)								// Function to fetch and verify (Y/N) questions.
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
				return(1);
				break;
			case 'N':
			case 'n':
				flag=1;
				return(0);
				break;
			default:
				printf("Only [y]es or [n]o responses will be accepted.\n>> ");
				break;
		}
	}
	printf("ERROR"); // Should never get here. Strictly for debug.
	return(-1);
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
	char values[MAXLEN][9] = {"1  EAION","1  RTLSU","2  DG","3  BCMP","4  FHVWY","5  K","8  JX","10 QZ"};
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
	for (i=0; i<RAKLEN; i++) {printf("%2c",rack[i]);}
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
	for (i=0; i<RAKLEN; i++) {
		rack[i] = '_';
	}
	rack[RAKLEN +1]='\0';
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
	
	for (i=0; i<RAKLEN; i++)						// Move through rack[] looking for '_'
	{
		if (rack[i]=='_')					// If rack slot is empty, fill it
		{	rack[i] = next_tile(tile_bag);	}
	}
}

void empty_rack(char rack[])				// Removes the used letters from the letter rack
{
	char temp[RAKLEN +1]={};
	int i,p=0;
	
	for (i=0; i<RAKLEN; i++)			// Goes through rack[] and removes '#'
	{
		if (rack[i] != '#')		// '#' is the flag char that removed letters are replaced with
		{	temp[p]=rack[i]; p++;	}
		
	}
	for (i=p; i<RAKLEN; i++)			// Fill remainder with  '_'
	{	temp[i] = '_';	}
	
	for (i=0; i<RAKLEN; i++)			// Read tiles back into rack[]
	{	rack[i]=temp[i];	}
}

int check_rack(char word[],int vector[], char tiles[][MAXLEN], char rack[])
											// Checks that the submitted word is in the rack
{
	char used[RAKLEN +1] = {};
	char temp[RAKLEN +1] = {};
	int board[MAXLEN-1] = {};
	int i=0,k=0,c=0,b=0,length,m=0;
	
	length = strlen(word);
	
	switch (vector[0])						// Look to see what letters in word[] are already in play
	{
		case 1:								// Horizontal or RIGHT
			for (i=0; i<length; i++)	{
				if ( tiles[vector[1]][(vector[2]+i)] == word[i] ){	board[i]=1;	b++;	}
			}
			break;
	
		case -1:							// Vertical or DOWN
			for (i=0; i<length; i++)	{
				if ( tiles[(vector[1]+i)][vector[2]] == word[i] ){	board[i]=1;	b++;	} 
			}
			break;
	}
	
	for (i=0; i<length; i++)				// Pick out the letters of word[] that are from the rack
	{
		if (board[i]==0) {	used[k]=word[i];	k++;	}
	}

	for (i=0; i<RAKLEN; i++)						// Read rack[] into temp[]
	{	temp[i]=rack[i];	}
	
	for (i=0; i<k; i++)						// Look in temp[] for the letters used[]
	{
		if (used[i]=='\0')					// NULL char will be assigned to empty blocks in word[] string
		{	break;	}
		m=0;
		while (m<RAKLEN)		
		{
			if (used[i] == temp[m])			// Look for match
			{	
				temp[m] = '#';
				c++;	m=RAKLEN;				// Match found -> exit loop
			}
			m++;							// Match not found -> increment and continue
		}
	}
	if ( (length - b) == c )				// 'b' is the number of letters in word[] that are on the board
	{
		for (i=0; i<RAKLEN; i++) 
		{	rack[i] = temp[i];	}			// Fill used letter spaces in rack with '#'
		return(1);
	} else {
		return(0);
	}
}
											// Checks that there is enough space for the given word
int check_space(char word[], int size, char tiles[][MAXLEN],int vector[])
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
{	
	int check1=0,flag=1,i=0,length;
	int check2[MAXLEN] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	length=strlen(word);
	
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
			if (NorY()) {	save_game();	}
			return(1);
		}
			
		default:
			printf("\n\nBAD INPUT\n\n");
			break;
	}
	return(0);
}


void place_word(char word[], char tiles[][MAXLEN], int vector[])		// Places word on the board
{
	int i=0;
	
	for (i=0; i<strlen(word); i++)	
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

int word_searcher(char tiles[][MAXLEN])		// Finds all the words in tiles[][]
/* Searches through tiles[][] for all possible words and stores them in found_words.txt */
{
	char row[MAXLEN] = {};
	char string[MAXLEN] = {};
	char word[MAXLEN] = {};
	int i,j,flag;
	int first_letter,last_letter;
	int numwrds=0,numrow=0;
	FILE * found_words;
	FILE * not_words;
	const char* ptr;
	
	found_words = fopen("found_words.txt", "w");
	not_words = fopen("not_words.txt", "w");
	
	for (flag=1; flag<3; flag++)			// Determines direction
	{
		for (numrow=0; numrow<MAXLEN; numrow++)
		{
			switch (flag)
			{
				case 1:						// Search the rows
					strcpy(row,tiles[numrow]);
					break;
				case 2:						// Search the columns
					for (i=0; i<MAXLEN; i++) 
						row[i] = tiles[i][numrow];	
					break;
				default:
					fclose(not_words);
					fclose(found_words);
					return(numwrds);
			}
			for ( ptr = strtok(row,"- |"); ptr /* Ends when *ptr == NULL */; ptr = strtok(NULL,"- |") )
			{			/* Moves though the row and picks out each contiguous char string */
				strcpy(string,ptr);
				for (first_letter=0; first_letter<strlen(string); first_letter++) 		
				{		/* Goes though each word, with insteasing length that starts with first_letter */
					for (last_letter=first_letter+1; last_letter<strlen(string); last_letter++)
					{	/* .. Then increments the first_letter */
						j=0; memset(word,'\0',MAXLEN);
						for (i=first_letter; i<=last_letter; i++){	word[j]=string[i];	j++;	}
						if (chk_dict(word))						// Returns 1 for found, 0 otherwise
						{
							make_upper(word);
							fprintf(found_words,"%s\n", word);	// Save list of found words to file
							numwrds++;							// Increment number found
						} else {
							make_upper(word);
							fprintf(not_words, "%s\n",word);	// Save list of non-words to file
						}
					}
				}
			}
		} 
	}
	fclose(not_words);
	fclose(found_words);
	return(numwrds);
}


int chk_dict(char query[])		// Check the dictionary for the given word query
/* Description of dictionary file format
 *	Each file contains all the words that start with the first letter of the file
 *	The length of everyword in the file is equal to the numerical suffix of the filename
 *	The first line is an index listing the number of words that have #index as their second letter
 *	The last node of the index is the total number of words in the file (not including the index).
 *	
 *	Algorithm:
 *	1)	letter = word[0]
 *	2)	length = strlen(word)
 *	3)	skip to word[1] ,; n = (int)skip -97
 *	4)	Open filename = ("%c%d.txt",letter,length)
 *	5)	Read index into dir[26]
 *	6)	Number of lines to skip is equal to sum of dir[0]...dir[n-1]
 *	7)	Begin search with this line as START
 *	8)	END = START + dir[n]
 *	9)	If list is very large, use binary search with these points as terminaters
 *	10)	Other wise a linear search will do.
 */
{
	// char query[16]="zip";	// Comment in for debug
	FILE * dict_src;
	int length = strlen(query);
	int skip=0,i;
	char filename[10]={};		// String for holding the filename of the dictionary section we want
	int dir[27] = {};			// Directory array to hold index at beginning of file
	fpos_t wrdz_start;
	int top,bottom,middle,found;
	char word[16]={};
	
	make_lower(query);			// Required because dictionary is entirely lowercase
	if (length<=1) {	return(0);	}
	
	sprintf(filename,"%c%d.txt",query[0],length);					// Open the file
	dict_src = fopen(filename,"r");
	if	(dict_src == NULL){ printf("\nERROR: No File"); return(0);}	// Check is file exists
	for (i=0;i<27 ; i++) {	fscanf(dict_src,"%d",&dir[i]);	}		// Read the index into the directory array
	for (i=0; i<( (int)query[1] -97); i++) {	skip += dir[i];	}	// Skip = sum of dir[0] to dir[ first letter ]
	fgetpos(dict_src, &wrdz_start /* Begin word list */ );
	
	// --- Begin binary seach for query in word list -----
	bottom = skip;				// 1. Let bottom be the subscript of the initial array element.
	top = dir[i] - 1 + skip;	// 2. Let top be the subscript of the last array element.
	found = -1;					// 3. Let found be false.
	while (	(bottom<=top)		/* 4. Repeat as long as bottom isn't greater than top	*/
		   && (found == -1)	)	/*			and the target has not been found.			*/
	{
		middle = (top-bottom)/2 + bottom  ;	// a. Let middle be the subscript of the element halfway between bottom and top.
		fsetpos(dict_src, &wrdz_start);
		fseek(dict_src, ( middle * (length +1) ) + 3 , SEEK_CUR);
		fscanf(dict_src,"%s",word);
		if (strcmp(word,query)==0){			// b. if the element at middle is the target
			found = middle;						// i. Set found to true and index to middle.
		}else if(strcmp(word,query) > 0){			// else if the element at middle is larger than the target 
			top = middle -1;					// ii. Let top be middle-1.
		}else {										// else
			bottom = middle +1;					// iii. Let bottom be middle + 1.
		}
	}
	if (found!=-1) {			// 5. If the target was found
		fclose(dict_src);// Close file
		return(1);							// a. return the index .
	} else {										// else
		fclose(dict_src);// Close file
		return (0);							// b. return -1
	}
	// -------- End of binary search --------

}

void make_upper( char string[])  // Convert to UPPERcase
{
	int i;
	for (i=0; i<=strlen(string); i++){
		if ( (string[i]>='a') && (string[i]<='z') )	{
			string[i] = (char)((int)string[i] - 32);
		}								
	}
}
void make_lower( char string[])	// Convert to lowerCASE
{
	int i;
	for (i=0; i<=strlen(string); i++){
		if ( (string[i]>='A') && (string[i]<='Z') )	{
			string[i] = (char)((int)string[i] + 32);
		}								
	}
}


int read_in( char word[], int vector[] )
/* Scans input and parses. Return is: word length (success), 0 (failure), or -1 for #CTRL# .
 *********************************************************************************************
 * Function call chould always be called as:
 *********************************************************************************************
 switch( read_in(word,vector) ){
	case 0:
		// no word found
		break;
	case -1:
		ctrl_dispatch(word,tile_bag,rack);
		break;
	default: 
		// Play word
 }
 *********************** OR ***********************
 option = read_in(word,vector);
 if( option ==0)
	// no word found
 if( option < 0)
	ctrl_dispatch(word,tile_bag,rack);
 if( option > 0)
	// play word
 *********************************************************************************************/	
{
	int flag=-1;
	char input[80] = {};
	char temp[MAXLEN];	
	
	fgets(input,80,stdin);						// Read in as string
	make_upper(input);							// Change a-z to A-Z
	sprintf(strchr(input,'\n'),"%c",'\0');		// Strip \n char from end
	
	memset(vector,0,sizeof(vector[0])*3);
	while (1 /* all parts are not found */) 
	{
		memset(temp,'\0',MAXLEN);
		switch (flag)
		{
			case -1:
				if (strdlm(temp, input,"#", 0) >0){
					memset(input,0,80);
					sprintf(input,"#%s#",temp);
					if (ctrl_dispatch(input,NULL,NULL,NULL,NULL) ){
						strcpy(word,input);
						return(-1);	
					}
					return(0);					// No "words" read in
				}
				break;
			case 0:								// Scan input for "word" or 'word'
				sprintf( temp, "%c%c",(char)34,(char)39); // 34 & 39 = "double" & 'single' quote
				memset(word,'\0',MAXLEN);
				strdlm(word, input, temp, 0);
				strncpy ( strstr(input,word), "----------------", strlen(word) );
				printf("\n Found word: %s",word);
				break;
			case 1:								// Scan input for row number [01-15]
				strdlm(temp, input, "0123456789", 1);
				vector[1] = atoi(temp);
				printf("\n Found row: %d",vector[1]);									// DEBUG
				break;
			case 2:								// Scan input for direction specifier [X,Y]
				strdlm(temp, input, "XY", 1);				// X & Y = (char) 88 & 89
				vector[0] =( ( (int)temp[0] - 88) * -2) +1; // 88,89 -> 1,-1
				printf("\n Found direction: %d",vector[0]);								// DEBUG
				break;
			case 3:								// Scan input for column letter [A-O]
				strdlm(temp, input, "ABCDEFGHIJKLMNO", 1);
				vector[2]=( (int)temp[0]-65 );				// (int)'A' = 65
				printf("\n Found column: %d",vector[2]);								// DEBUG
				break;
			default:							// Check to see if all parts have been found
				if (strlen(word) && vector[0] && vector[1] && vector[2] ){
					return(strlen(word));					// Exit word_length if all parts found
				} else{
					printf("\n Not all segments found.");
					return(0);					// Exit 0 if not all have been found
				} 
		}
		flag++;									// Look for the next object
	}
} // Return = length; 0 = fail





