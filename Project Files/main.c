// ----- Algorithms -------

// 1) Generate the letters	
// 2) Print the board
// 3) Start playing
	/* 1) Ask for placement
	 * 2) Check that word fits
	 * 3a)It fits, so check for valid placement
	 * 3b)It doesn't, so ignore input
	 * 4a)It's valid so stick it on the board
	 * 5) In any case return to step 1 */
// 4) Run out of space
// 5) Check that all words are spelled correctly
// 6) Tally up points.
// 7) Award score
// 8) Offer to save the game
// 9) Ask to play again -> Return to step 1






#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* --------------------------------------------------------------------------------- *
 * ---------------------------  Function Prototypes  ------------------------------- *
 * --------------------------------------------------------------------------------- */

char NorY(void);								// Function to fetch and verify (Y/N) questions.
void Draw_board(int size, char tiles[], char rack[]);
												// Draws the board and rack
void border(int size);							// Draws the border of the playing board
int read_in(char word[],int vector[]);			// Scanning input and stores. Return is length.
void new_game(int size, int tile_bag[],char tiles[], char rack[]);
												// Re-initializes boards and vars to play again
char next_tile(int tile_bag[]);					// Returns the next letter in the stack
void fill_rack(int tile_bag[], char rack[]);	// Fills the letter rack from the bag
void empty_rack(char rack[]);					// Removes the used letters from the letter rack
int check_rack(char word[], char rack[]);		// Checks that the submitted word is in the rack
int check_space(int word_length,char word[],int size, char tiles[], int vector[]);
												// Checks that there is enough space for the given word
void place_word(int word_length, char word[], char tiles[], int vector[]);
												// Places word on the board
void show_rules();								// Prints all the rules and explains the game
void end_game(int *end);						// Player ends the game.
int hash_check();								// Checks to see if the user entered a #CONTROLL string
int get_length(char str[]);						// Returns the length (non-zero indexes) of a string
int sum(int seq[]);								// Sum a sequence of numbers in an array

int main()
{
	int i=0,end;
	double high_score=0.123;
	char tiles[255];			// Array to hold tiles placed on the board: {row,column}
	char tag[20];				// String to hold the player's gamer tag
	int  size=0;					// Size of the board
	int tile_bag[301];			// Array of mixed tiles. 
								/* If i wanted to have an array of pointers i could use
	char *letters[] = {*p1,*p2,...};
								 * This works because an array IS a pointer.
								 * I could use this to create an array of Files.  */
	char rack[8];			    // Your rack of 8 letters
	int word_length=0;		    // Length of the most recent wordup or down)
	int vector[3];				// Starting position: {direction, row, column}
	int hash_ctrl=0;				// Indicates presence of #COMMAND use 
	char word[8];				// String for holding the submitted word


// 1) Generate the letters	

	
	
	
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
	
	printf("How big of a board would you like (5-15)?\n>> ");
	scanf("%d",&size);
	while ((size >15) || (size < 5))			// Check to make sure the selected size is within bounds
	{
		printf("Im sorry, %d is not a valid option.",size);
		printf("\nPlease enter a value between 5 and 15, inclusive.\n>> ");
		scanf("%d",&size);
	}
	if (size%2 == 0)							// If even, resize it
		{					
		printf("Scrabble boards are always an odd size.");
		if (size == 6) {
			size =5;
		}else {
			size+=1;
		}
	}
	printf("\nRight. Board size %d it is. Let's play!\n\n",size);
// 2) Print the board
	new_game(size,tile_bag,tiles,rack);	// Initialize a bunch of stuff
	fill_rack(tile_bag, rack);
	Draw_board( size, tiles, rack);			// Proper function call for tiles[][] and rack[]	

// 3) Start playing
// 3.1) Ask for placement
	printf("What word would you like to play?\n>> ");
	word_length = read_in(word,vector);
	if (word_length<0){
		end = 0-word_length;	}						// Hashcheck
	while (end==0) 
	{
//3.2) Check that word fits
//3.3a)It fits, so check for valid placement
		if( (check_space(word_length,word,size,tiles,vector))	// Checks that there is enough space for the given word
		 && (check_rack(word, rack)) )						// Checks that the submitted word is in the rack
		{					
//3.4a)It's valid so stick it on the board
			i=0;
			place_word(word_length,word, tiles,vector);	// Places word on the board
			empty_rack(rack);					// Removes the used letters from the letter rack
			fill_rack(tile_bag, rack);			// Fills the letter rack from the bag
			Draw_board(size, tiles, rack);
			printf("Excellent. What word would you like to play next?\n>> ");
			word_length = read_in(word,vector);
			if (word_length<0){
				end = 0-word_length;	}				// Hashcheck
		
//3.3b)It doesn't, so ignore input
		} else {
			i++;
			if (i<=7) {
// 4) Run out of space
				printf("\n I'm sorry, but that just won't work.");
				printf("\n Why don't you try something else?\n>> ");
				word_length = read_in(word,vector);
				if (word_length<0){
					end = 0-word_length;	}			// Hashcheck
			}else {
				printf("\nYou seem to be having a lot of trouble playing a word.");
				printf("\n If you can't play any more words, type #END .");
				word_length = read_in(word,vector);
				if (word_length<0){
					end = 0-word_length;	}			// Hashcheck
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

void Draw_board(int size, char tiles[], char rack[])	// Function for drawing the board
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
	char values[16][9] = {"1  EAION","1  RTLSU","2  DG","3  BCMP","4  FHVWY","5  K","8  JX","10 QZ"," "," "," "," "," "," "," "," "};
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
			printf(" %c |",tiles[(row-1)*(column-1)]);
		}
		printf("%11c%s",' ',values[row+row-1]);
		border(size);
		printf("%11c%s",' ',values[row+row]);
	}
// 5) Print letter rack
	printf("\n\nYour Letters:");
	for (i=0; i<=7; i++) {printf("%2c",rack[i]);}
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

void new_game(int size, int tile_bag[],char tiles[],char rack[])		// Initializes boards and vars to play again
{
					// {A,B,C,D, E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z}
	int ref_freq[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
	int freq_dst[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
	int i,r,s,t,x,y;		// Incrementor, Random holder, and Stop counter
	
// Wipe the board blank
	for (y=0; y<15; y++)
	{
		for (x=0; x<15; x++)
		{tiles[y*x] =  ' ';}
	}
	tiles[((size/2) +1)*((size/2) +1)] = '@';
	
// Refill the tile bag
	
	//Populate tile_bag[] with 300 tiles chosen at random
	tile_bag[0] = 300;
	
	for (i=1; i<=300; i++)			// Create the "stack" or letter bag
	{
		r=rand()%26;
		s=0;
		while (freq_dst[r]<=0)	// Check to see if letter has been picked too much
		{
			r=rand()%26;
			s++;
			if (s>20)				// Reloads the freq distribution if more than 20 zeros in a row
			{
				s=0;			
				for (t=0; t<26; t++) {
					freq_dst[t] = ref_freq[t];
				}
			}
		}
		tile_bag[i] = 65+r;		// (char)65 = 'A'
		freq_dst[r] = freq_dst[r] - 1;
	}

// Fill letter rack with spaces ( underscores )
	for (i=0; i<=8; i++) {
		rack[i] = '_';
	}
}	
	
char next_tile(int tile_bag[])				// Returns the next letter in the stack
{
	int position;
	char letter;
	
	position = tile_bag[0];				// Index0 stores the position of the next char
	letter = (char)tile_bag[position];	// Letters in the array are int
	position = position - 1;			// Decrement the position is the next char
	tile_bag[0] = position;				// Update the position index
	
	return(letter);	
}
	
void fill_rack(int tile_bag[], char rack[])	// Fills the letter rack from the bag
{
	int i;
	
	for (i=0; i<8; i++)			// Move through rack[] looking for '_'
	{
		if (rack[i]=='_')		// If rack slot is empty, fill it
		{	rack[i] = next_tile(tile_bag);	}
	}
}
void empty_rack(char rack[])				// Removes the used letters from the letter rack
{
	char temp[8];
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

int check_rack(char word[], char rack[])	// Checks that the submitted word is in the rack
{
	char temp[8];
	int i,k,c=0,length=0;
	
	for (i=0; i<8; i++)				// Read rack[] into temp[]
	{	temp[i]=rack[i]; length++;}
	
	for (i=0; i<8; i++)				// Look in temp[] for the letters in word[] 
	{
		if ((int)word[i]==0)		// NULL char will be assigned to empty blocks in word[] string
		{	break;	}
		k=0;
		while (k<8)		
		{
			if (word[i] == temp[k])	// Look for match
			{	
				temp[k] = '#';
				c++;
				k=8;				// Match found -> exit loop
			}
			k++;					// Match not found -> increment and continue
		}
	}
	if (length==c) {
		return(1);
		for (i=0; i<8; i++) {
			rack[i] = temp[i];	// Fill used letter spaces in rack with '#'
		}
	}else {
		return(0);
	}
}

int check_space(int word_length,char word[], int size, char tiles[],int vector[])
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
	int check1=0,flag=0,i;
	int check2[8] = {0,0,0,0,0,0,0,0};
	
	switch (vector[0]) 
	{
		case 1:								// Vertical or DOWN
			if ( (vector[1] + word_length) < size ) {
				check1=1;}
			for (i=0; i<word_length; i++)	// 1 = PASS, 0 = Fail, 2 = Intersection
			{
				if ( (tiles[vector[1]*(vector[2]+i)])=='@' ) {
					check2[i]=-1;
				} else if ( (tiles[vector[1]*(vector[2]+i)])=='_' ) {
					check2[i]= 1; 
				} else if ( (tiles[vector[1]*(vector[2]+i)])==word[i] ){
					check2[i]= 2;
				} else {
					check2[i]= 0;
				}
				flag = check1 * check2[i];
			}
			break;
		case -1:							// Vertical or DOWN
			if ( (vector[1] + word_length) < size ) {
				check1=1; }
			for (i=0; i<word_length; i++)	// 1 = PASS, 0 = Fail, -1 = GAMESTART
			{
				if ( (tiles[(vector[1]+i)*vector[2]])=='_' ) {
					check2[i]=1; 
				} else if ( (tiles[(vector[1]+i)*vector[2]])==word[i] ){
					check2[i]=2;
				} else if ( (tiles[(vector[1]+i)*vector[2]])=='@' ) {
					check2[i]=-1;
				} else {
					check2[i]=0;
				}
				flag = check1 * check2[i];
			}
			break;
		default:
			printf("\nERROR: Space check mismatch.");
			break;
	}
	if ( (flag%2==0) || (flag==-1) ) {
		return(1);
	} else {
		return(0);
	}
	
}


int read_in(char word[],int vector[])		// Scans input and parses. Return is word length or -1
{
	int i,k,x=0,y=0,z=0,flag=0,length=0;
	char input[10];
	int row[]={99,99};
	
	for (i=0; i<3; i++) {vector[i]=99;}
	
	while ( ((x!=1) && (y!=2)) || (z!=3) )	// Verify that input has BOTH vector[], word[]
											// OR that input has #CONTROL
	{
		x++;
		for (i=0; i<10; i++){
			input[i] = (char)0;}			// Initialize input[]
		
		scanf("%s",input);					// Read in as string
		for (i=0; i<10; i++)				// Determine string kind based on contents
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
					flag=2;					// Position deliminated with spaces
					break;
			}
		}
		switch (flag)						// Parse string
		{
			case 1:							// String is word
				for (i=0; i<8; i++)
				{
					while ((int)input[i] !=0 ) 
					{
						if (input[i]>='A')	// Fill word[]. Count length
						{
							word[i]=input[i];
							length++;
						}
						
					}
				}
				x=1;
				break;
			case 2:							// String is position
				for (i=0; i<5; i++) 
				{
					k=0;
					// Parse Vector
					if (input[i]=='X'){		// X = "Right"
						vector[0]=  1;}
					if (input[i]=='Y'){		// Y = "Down"
						vector[0]= -1;	}
					
					// Parse Column
					if ( (input[i]>='A') &&	// Column letters from 'A' to 'O'
						 (input[i]<='O') )
					{	vector[2]=( (int)input[i]-65 );		}
					
					// Parse Row
					if ( (input[i]>='0') &&	// Row num from 0 to 9
						 (input[i] <= '9') )
					{	row[k]=( (int)input[i]-48 ); k++;	}
				}							// End parse
				
				if (row[1]>9)				// Sum collective number for row
				{ 
					row[1] = row[0];
					row[0] = 0;
				}							
				vector[1] = row[0] * 10 + row[1];
				
				for (i=0; i<3; i++) {
					k+=vector[i];
				}	// Sum vector[] for parity check
				if (k<32) {
					y=2;
				} else {
					printf("ERROR: Bad vector sum");
				}

				break;
				
			case 3:							// String is #CTRL
				length=get_length(input);
				switch (length)				// Determine which it is
				{
					case 430:		// "#RULES"
						show_rules();
						length = 0;
						break;
					case 358:		// "#QUIT"
					case 250:		// "#END"
						length = -1;
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
		if (x>5) {
			printf("ERROR: x>5");
			break;
		}
	}
		
	return(length);							// Return the length(int) of the word or (-1)
}
		
void show_rules()							// Prints all the rules and explains the game
{
	printf("\n\n");
	printf("LOTS OF RULES");
	printf("\n\n");
}

int get_length(char str[])					// Returns the length (non-zero indexes) of an array or string
{
	int l,i=0;
	while ((int)str[i]!=0)
	{
		l++;
		i++;
	}
	
	return(l);
}

void place_word(int word_length,char word[], char tiles[], int vector[])		// Places word on the board
{
	int i;
	
	while ((int)word[i]!=0)
	{
		switch (vector[0]) 
		{
		case 1:								// Vertical or DOWN
			for (i=0; i<word_length; i++)	
			{
				tiles[vector[1]*(vector[2]+i)] = word[i];
			}	
			break;
		case -1:							// Vertical or DOWN
			for (i=0; i<word_length; i++)	
			{
				tiles[(vector[1]+i)*vector[2]] = word[i];
			}
			break;
		}
		i++;
	}
}








