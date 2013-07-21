/*
 *  test.c
 *  Project Files
 *
 *  Created by Lyle Moffitt on 4/25/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#define MAXLEN 16		// MUST be (MAXLEN -1)%2 == 1 && MAXLEN >5
#define RAKLEN 8
#define HMAX 40
#define LMAX 128
#define ATOZ "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DBG 1			// Debugging flag; 1/0 = ON / OFF

void make_upper( char string[]);							// Convert to UPPERcase

void make_lower( char string[]);							// Convert to lowerCASE

int strdlm(char output[],char input[], char delms[], int inclusive);

int ctrl_dispatch(char ctrl_str[] );

int read_in(char word[],int vector[]);		

void new_game(void);

char next_tile(int tile_bag[]);								// Returns the next letter in the stack

void fill_rack(int tile_bag[], char rack[]);				// Fills the letter rack from the bag

void empty_rack(char rack[]);								// Removes the used letters from the letter rack

int check_rack(char word[],int vector[], char tiles[][MAXLEN], char rack[]);		
															// Checks that the submitted word is in the rack

//int show_rules(void);										// Prints all the rules and explains the game. Return 1 to Quit

int NorY(void);

int toss_tiles(int tile_bag[], char rack[] );

void persist(char tiles[][MAXLEN],int tile_bag[],char rack[], char tag[] );

int load_crrnt(char tiles[][MAXLEN],int tile_bag[],char rack[], char tag[],int *size );

int word_searcher(char tiles[][MAXLEN]);					// Finds all the words in tiles[][]

int chk_dict(char query[]);									// Check the dictionary for the given word query

int endgame(void);

int score_word(char word[]);
	
double calc_net_score(FILE * alt_out);						// Calculates final score for game

int bffr_print(char sbuf[][LMAX],FILE * output);	
															// Draws  sbuf[][] to sprcified *ouput OR *stdout

void Draw_board(char tiles[][MAXLEN], char rack[], char sbuf[][LMAX]);

int strovr(char dest[], char src[], int pos);				// Places src[] at starting pos(ition) in dest[]

void update_save(double score, char sbuf[][LMAX]);

int sort_scores(int n, char names[][20], double high[], double avg[] );

void swapD (double* dx, double* dy);						/* swap the values pointed to by *x and *y */

int chk_tag(char tag[20]);									// Check to see if the tag is already being used

void place_word(char word[], char tiles[][MAXLEN], int vector[]);		// Places word on the board

int bffr_cache(char sbuf[][LMAX],int ovr_wrt);				// Read/write to the buffer cache

void word_updater(void);	// Updates the screen buffer to show hghest and lowest scoring words 

void delay(double secs);									// Wait specified number of secs


int main ()
{
	//  ----- COPIED FROM MAIN -----
	char tiles[MAXLEN][MAXLEN];								// Array to hold tiles placed on the board: {row,column}
	int  size=15;											// Size of the board
	int tile_bag[230];										// Array of mixed tiles. 15^2 + 5 = 230
															/* If i wanted to have an array of pointers i could use
	char *letters[] = {*p1,*p2,...};						 * This works because an array IS a pointer.
															 * I could use this to create an array of Files.  */				   
	char rack[RAKLEN +1];									// Your rack of 8 letters
	int vector[3];											// Starting position: {direction, row, column}
//	int hash_ctrl=0;										// Indicates presence of #COMMAND use 
	char word[MAXLEN];										// String for holding the submitted word
	char tag[20];											// String to hold the player's gamer tag
	
	// NEW VARIABLES
	char sbuf[HMAX][LMAX];									// Screen buffer to print from & with
	
	// dbug only
	int stop  = 1;
	
	srand(time(0));

	bffr_print(sbuf, stdout);
	new_game();
	load_crrnt(tiles, tile_bag, rack, tag, &size);
	fill_rack(tile_bag, rack);
	while(stop){
		persist(tiles, tile_bag, rack, tag);
		Draw_board(tiles, rack,sbuf);
		bffr_print(sbuf, stdout);
		switch( read_in(word,vector) ){
			case 0:
				printf("\n No word was found. Try again");
				break;
			case -1:
				if (strcmp("#STOP#", word) ==0)
					stop=0;
				break;
			default: 
				printf("\n Fantastic. You managed to play the word %s ...",word);
				delay(2);
				if ( check_rack(word, vector, tiles, rack) ){
					place_word(word, tiles, vector);
				}else {
					printf("\n\n Word cannot be played.");
					delay(5);
				}
				Draw_board(tiles, rack,sbuf);
				bffr_print(sbuf, stdout);
				empty_rack(rack);
				Draw_board(tiles, rack,sbuf);
				bffr_print(sbuf, stdout);
				fill_rack(tile_bag, rack);
				Draw_board(tiles, rack,sbuf);
				bffr_print(sbuf, stdout);
				
				
		}
	}
	return(0);  
}// ------------- END MAIN ---------------

# define END_OF_MAIN 0

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
	
	printf("\n What is your input ? \n >> ");
	do{	memset(input,0,80);								// Null set input before read
		fgets(input,80, stdin);							// Read in line
		sprintf(strchr(input,'\n'),"%c",'\0');			// Strip \n char from end
	} while(strlen(input) <3);							// Check for appropriate length
	make_upper(input);									// Change a-z to A-Z
	
	memset(vector,0,sizeof(vector[0])*3);
	while (1){
		memset(temp,'\0',MAXLEN);
		switch (flag)
		{
			case -1:
				if (strdlm(temp, input,"#", 0) >0){
					memset(input,0,80);
					sprintf(input,"#%s#",temp);
					if (ctrl_dispatch(input)){
						strcpy(word,input);
						return(-1);	
					}
					return(0);							// No "words" read in
				}
				break;
			case 0:										// Scan input for "word" or 'word'
				sprintf(temp,"%c%c",(char)34,(char)39); // 34 & 39 = "double" & 'single' quote
				memset(word,'\0',MAXLEN);
				strdlm(word, input, temp, 0);
				strncpy ( strstr(input,word), "----------------", strlen(word) );
				if (word && DBG)
					printf("\n Found word: %s",word);
				break;
			case 1:										// Scan input for row number [01-15]
				strdlm(temp, input, "0123456789", 1);
				vector[1] = atoi(temp);
				if (vector[1] && DBG)
					printf("\n Found row: %d",vector[1]);									// DEBUG
				break;
			case 2:										// Scan input for direction specifier [X,Y]
				strdlm(temp, input, "XY", 1);			// X & Y = (char) 88 & 89 -> 1 & -1
				vector[0] =( ( (int)temp[0] - 88) * -2) +1; 
				if (vector[0] && DBG)
					printf("\n Found direction: %d",vector[0]);								// DEBUG
				break;
			case 3:										// Scan input for column letter [A-O]
				strdlm(temp, input, "ABCDEFGHIJKLMNO", 1);
				vector[2]=( (int)temp[0]-64 );			// (int)'A' = 65
				if (vector[2] && DBG)
					printf("\n Found column: %d",vector[2]);								// DEBUG
				break;
			default:									// Check to see if all parts have been found
				if (strlen(word) && vector[0] && vector[1] && vector[2] ){
					return(strlen(word));				// Exit word_length if all parts found
				} else{
					printf("\n Not all segments found.");
					return(0);							// Exit 0 if not all have been found
				} 
		}
		flag++;											// Look for the next object
	}
} // Return = length; 0 = fail

void make_upper( char string[])							// Convert to UPPERcase
{
	int i;
	for (i=0; i<=strlen(string); i++)
	{
		if ( (string[i]>='a') && (string[i]<='z') )	
		{
			string[i] = (char)((int)string[i] - 32);
		}								
	}
}
void make_lower( char string[])							// Convert to lowerCASE
{
	int i;
	for (i=0; i<=strlen(string); i++)
	{
		if ( (string[i]>='A') && (string[i]<='Z') )	
		{
			string[i] = (char)((int)string[i] + 32);
		}								
	}
}

int strdlm(char output[],char input[], char delms[], int inclusive)		// String deliminator
{	/* Reads in from *ptr and returns first portion to match delimination, value=length */
	int i=0 ;
	char * pch1;
	char * pch2;
	
	char * temp1 = NULL;
	temp1 = (char *) calloc(strlen(input), sizeof(char));
	memset(temp1,'\0',strlen(input));
	
	pch1 = strpbrk(input, delms);						// Find first matching char
	switch (inclusive)
	{
		case 1:
			for (pch1 = strpbrk(input, delms); pch1 ;pch1 = strpbrk(pch1 +1,delms))
			{	/* Inclusive case : 0-9, XY, A-O */
				strncat(temp1,pch1,1);	i++;
			}
			break;
		case 0:				/*	If pch1 != NULL,	THEN IF strbrk() != 0,		ELSE pch1 */
			for (pch2 = pch1 + 1;
				 (long int)pch1 ? (pch2 < strpbrk(pch1+1,delms)) : (long int)pch1 ;
				 pch2++)
			{	/* Exclusive case : "word" or 'word', etc.. */
				strncat(temp1,pch2,1);	i++;
			}
			break;
		default:
			return(-1);
	}
	strcpy(output,temp1);
	free(temp1);
	temp1 = NULL;
	return(i);
}	// Return = length

int ctrl_dispatch(char ctrl_str[])						// Check for #CTRL# and then execute 
/* Check string input to see if it is a recognized #CTRL# sequence.					*
 * If pointers for tile_bag[] and rack[] are provided, then #CTRL# is also executed	*/
{
	char ctrl_key[9][10] = {/*0*/"#RULES#",	/*1*/"#WORDS#",	/*2*/"#END#",
							/*3*/"#SCORE#",	/*4*/"#TOSS#",	/*5*/"#RESTART#",
							/*6*/"#SPELL#",	/*7*/"#SWAP#",	/*LAST*/""};
	int i;
	
	int tile_bag[230] = {};
	char rack[RAKLEN +1] = {};
	char temp[MAXLEN]={};

	
	for (i=0; strlen(ctrl_key[i]); ++i){				// Figure out which #CTRL# sequence it is.
		if (0 == strcmp(ctrl_str, ctrl_key[i]) )
			break; 
	}
	switch (i)	{
		case 0:											// "#RULES#"
			//show_rules();
			printf("\n So these are the rules..");
			return(1);
		case 1:											// "#WORDS#"
			word_updater();
			return(1);
		case 2:											// "#END#"
			endgame();
			return(1);
		case 3:											// "#SCORE#"
			printf("\n What word would you like to check the point value of? \n >>");
			scanf("%s",temp);
			make_upper(temp);
			strdlm(temp, temp, ATOZ, 1);
			printf("\n The point value of %s is %d pts. ",temp,score_word(temp));
			delay(1);
			return(1);
		case 4:											// "#TOSS#"
		case 7:											// "#SWAP#"
			load_crrnt(NULL, tile_bag, rack, NULL, NULL);
			if( (tile_bag != NULL) && (rack != NULL) ) 
				toss_tiles(tile_bag,rack);
			return(1);
		case 5:											// "#RESTART#"
			printf("\n Are you sure you want to restart the game? >> ");
			if(NorY())
				new_game();
			return(1);
		case 6:											// "#SPELL#"
			printf("\n What word would you like to check? >> ");
			scanf("%s",temp);
			if ( chk_dict(temp)  ) {
				printf("\n Yes, %s is a recognized word.",temp);
			}else {
				printf("\n Sorry, %s is not a recognized word.",temp);
			}
			delay(1);
			return(1);
		default /* case 9: */:
			printf("\n %c %s %c is not a recognized #CTRL# sequence.",'"',ctrl_str,'"');
			delay(1);
			return(0);
	}	
}	// Return 1 = success; 0 = fail

void new_game(void)
/************************ Initializes board, rack, and tile_bag *******************************
 * The method for creating the tile_bag is analagous to the following:
 *
 * 1) There exits a pile of tiles.
 * 2) We want to create a stack of randomized tiles similar to a deck of cards
 * 3) The chance of grabbing any given tile at random from the pile
 *		is roughly equal to the freq[tile] / (total number of tiles, i.e. the sum)
 * 4) When a tile is removed from the pile and added to the stack..
 *		 i) The top of the stack gets one tile higher
 *		ii) And the number of tiles in the pile decreases
 * 5) When there are no tiles left in the pile, it magically reappears as it originally was.
 **********************************************************************************************/
{
	int size=0;
	int tile_bag[230] = {};
	char tiles[MAXLEN][MAXLEN] = {};
	char rack[RAKLEN+1] = {};
	char tag[20] = {};
	//				   {A,B,C,D, E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z}
	int ref_freq[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
	int freq_dst[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1}; // 98 total
	int i,r,j,k,sum;// ^This^ is a list of how many of each tile are in the hypothicical "pile"
	
	
	do {
		printf("\n What name would you like to save your games under?\n >> ");
		do{ memset(tag,0,20);
			fgets(tag, 20, stdin);						// Get gamer tag to use for game
			make_upper(tag);
			tag[strcspn(tag, "\n")] = '\0';
		}while(strlen(tag)<2);
		printf(" You entered: %s as your tag. Is that correct? >> ",tag);
	} while (NorY() == 0) ;
	
	printf("\n How big of a board would you like (5-%d)? >> ",(MAXLEN -1) );
	scanf("%d",&size);									// Get board size
	while ((size > MAXLEN-1) || (size < 5))				// Check to make sure the selected size is within bounds
	{
		printf(" I'm sorry, %d is not a valid option.",size);
		printf("\n Please enter a value between 5 and %d, inclusive.\n >> ",(MAXLEN -1));
		scanf("%d",&size);
	}
	if (size%2 == 0){									// If even, round up
		printf(" Scrabble boards are always an odd size.");
		if (size == 6) {
			size =5;									// Except if size == 6
		}else {	size++;	}
	}
	printf("\n Right. Board size %d it is. \n",size);
	
	tile_bag[0] = size * size;							// Initialize [0] with number of tiles = board area
	for (i=1; i<=tile_bag[0]; i++)						// Create the "stack" or tile_bag
	{
		do{
			sum = 0;
			for (j=0; j<26; j++)						// 'sum' the number of tiles in the hypothetical pile
				sum += freq_dst[j];	
			if (sum <= 0){								/* The hypothetical  pile is empty */
				for (j=0; j<26; j++)					// Recreate the original pile (with same distribution)
					freq_dst[j] = ref_freq[j];	
			}
		} while (sum <= 0);
		
		r = 0;
		if(sum /* prevents div by 0 */)
			r=rand()%sum;								// Pick a random tile from available tiles in pile
		j = 0;
		for (k=0; k<26; ++k) {							// Find which letter the picked tile is
			j += freq_dst[k];
			if( ((j>r) && (sum==0)) || ((j>=r) && sum) )	{	break;}
		} 
		tile_bag[i] = 65+k;								// Add chosen tile to the "stack"
		freq_dst[k]--;									// Remove chosen tile from hypothetical pile
	}
	tile_bag[tile_bag[0]+1] = -999;						// Add sentinal
// Set up board	
	for (i=0; i<size; i++){								// Wipe the board blank (with spaces)
		memset(tiles[i],' ',size);
		if (DBG) 
			fill_rack(tile_bag, tiles[i]);
	}
	if(DBG)
		tile_bag[0] = size * size;
	tiles[size/2][size/2] = '@';						// Place starting char
	for (i=size; i<MAXLEN; i++)
		memset(tiles[i],0,MAXLEN);

// Fill letter rack with spaces ( underscores )
	
	memset(rack,'_',RAKLEN);
	
	persist(tiles, tile_bag, rack, tag);				// Save all this to a persistence file.
	delay(1);
}	


char next_tile(int tile_bag[])							// Returns the next letter in the stack
{
	int position;
	char letter;
	
	position = tile_bag[0];								// Index0 stores the position of the next char
	letter = (char)tile_bag[position];					// Letters in the array are int
	position = position - 1;							// Decrement the position is the next char
	tile_bag[0] = position;								// Update the position index
	
	return(letter);	
}
	

void fill_rack(int tile_bag[], char rack[])				// Fills the letter rack from the bag
{
	int i;
	
	for (i=0; i<strlen(rack); i++)						// Move through rack[] looking for '_'
	{
		if (isalpha(rack[i]) == 0)						// If rack slot is empty, fill it
			rack[i] = next_tile(tile_bag);	
	}
}


void empty_rack(char rack[])							// Removes the used letters from the letter rack
{
	char temp[RAKLEN +1]={};
	int i,p=0;
	
	for (i=0; i<RAKLEN; i++)							// Goes through rack[] and removes '#'
	{
		if ( isalpha(rack[i]) )							// '#' is the flag char that removed letters are replaced with
		{	temp[p]=rack[i]; p++;	}
	}
	for (i=p; i<RAKLEN; i++)							// Fill remainder with  '_'
	{	temp[i] = '_';	}
	
	strncpy(rack,temp,RAKLEN);							// Read tiles back into rack[]
}


int check_rack(char word[],int vector[], char tiles[][MAXLEN], char rack[])
/* Checks that the submitted word is in the rack and on board. Return 1 if found, otherwise return 0 */
{
	char used[RAKLEN +1] = {};
	char temp[RAKLEN +1] = {};
	int board[MAXLEN] = {};
	int i=0,k=0,c=0,b=0,length,m=0;
	
	length = strlen(word);
	if( (vector != NULL) && (tiles != NULL ) ){
		switch (vector[0])								// Look to see what letters in word[] are already in play
		{
			case 1:										// Horizontal or RIGHT
				for (i=0; i<length; i++)	{
					if ( tiles[vector[1]-1][(vector[2]+i-1)] == word[i] ){	board[i]=1;	b++;	}
				}
				break;
			case -1:									// Vertical or DOWN
				for (i=0; i<length; i++)	{
					if ( tiles[(vector[1]+i-1)][vector[2]-1] == word[i] ){	board[i]=1;	b++;	} 
				}
				break;
		}
	}
	for (i=0; i<length; i++)							// Pick out the letters of word[] that are from the rack
	{
		if (board[i]==0) {	used[k]=word[i];	k++;	}
	}
	strncpy(temp,rack,RAKLEN);							// Read rack[] into temp[]
	
	for (i=0; i<k; i++)									// Look in temp[] for the letters used[]
	{
		if (used[i]=='\0')								// NULL char will be assigned to empty blocks in word[] string
		{	break;	}
		for (m=0; m<RAKLEN; m++)		
		{
			if (used[i] == temp[m])						// Look for match
			{	
				temp[m] = '_';
				c++;	m=RAKLEN;						// Match found -> exit loop
			}
		}												// Match not found -> increment and continue
	}
	if ( (length - b) == c )							// 'b' is the number of letters in word[] that are on the board
	{
		strncpy(rack,temp,RAKLEN);						// Fill used letter spaces in rack with '_'
		return(1);
	} else {
		return(0);
	}
}	// Return 1 = FOUND; 0 = fail


int NorY(void)											// Function to fetch and verify (Y/N) questions.
{
	char str[20] = {};
	while (/* Until return(value) is sent */ 1){
		scanf("%s", str);								// Scan in response
		make_upper(str);					
		if ((strcmp(str, "YES")==0) || (str[0] == 'Y') )
			return(1);									// Return 1 for YES
		if ((strcmp(str, "NO")==0) || (str[0] == 'N'))
			return(0);									// Return 0 for NO
		printf(" Only yes or no responses will be accepted. \n>> ");
	}
	printf("ERROR");									// Should never get here. Strictly for debug.
	return(-1);
}	// Return 0 = NO; 1 = YES


int toss_tiles(int tile_bag[], char rack[] )			// Toss away a specified set of tiles in exchange for new ones
{
	char junk[80]={};
	
	do{	memset(junk,0,80);
		printf("\n What tiles would you like to toss? \n >> ");
		fgets(junk,80, stdin);							// Tiles to toss from player
		sprintf(strchr(junk,'\n'),"%c",'\0');			// Strip new line char from end
	} while(strlen(junk) <1);					
	make_upper(junk);									// Homogeize
	strdlm(junk, junk, ATOZ, 1);						// Compress input down to just letters and make contiguous
	printf(" Are you sure you want to throw out the tiles : %s?\n>> ",junk);
	if(NorY()){
		check_rack(junk, NULL, NULL, rack);				// Check that the specified tiles are in the rack
		empty_rack(rack);								// Clear out #(s) left by check_rack()
		fill_rack(tile_bag, rack);						// Put new tiles in the open spots
		return (1);
	}else {
		return (0);
	}
}	// Return 0 = fail; 1 = success


void persist(char tiles[][MAXLEN],int tile_bag[],char rack[], char tag[] )
/* Saves the current game state to a file. The file will exist as long as no other player	*
 *		wishes to play, or until the game is saved to the master file.						*/
{
	FILE * current_game;
	int i;
	int size;
	char temp[80] = {};
	char filename[30] = {};
	char str[32] = {};
	
	if (strspn(rack, "#") == strlen(rack)) {
		strcpy(filename,tag);
		strcat(filename,".txt");
	} else {
		strcpy(filename,"current.txt");
	}
	size = strlen(tiles[0]);
	current_game = fopen(filename, "w");				// Open the file
	for (i=-3; i<MAXLEN; i++)
	{
	    switch (i)
		{
			case -3:
				sprintf(str, "%s",tag);					// Save gamer tag
				break;
			case -2:
				sprintf(str, "%d",size);				// Save board size
				break;
			case -1:
				sprintf(str, "%s",rack);				// Save rack
				break;
			default:
				sprintf(str, "%s",tiles[i]);			// Save current game board
				break;
		}
		memset(temp,0,80);								// Zero out temp
		strcpy(temp,"###############################");	// 31 char + \n == 32 bytes 
		strovr(temp, str, 2);							// Insert str(ing) into temp[] without altering sizeof(temp)
		fprintf(current_game,"%s\n", temp);				// Write 32 byte block to file
	}
	for( i=0; i<=tile_bag[0]+1; i++)					// Save tile_bag
		fprintf(current_game, "%d ",tile_bag[i]);
	fclose(current_game);								// Close the file
}


int load_crrnt(char tiles[][MAXLEN],int tile_bag[],char rack[], char tag[],int *size )
/* Saves the current game state to a file. The file will exist as long as no other player	*
 *		wishes to play, or until the game is saved to the master file.						*/
{
	FILE * current_game;
	int i;
	char temp[80] = {};
	char temp2[80] = "0123456789 @_ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	current_game = fopen("current.txt","r");			// Open the file
	
	if (current_game == NULL) {							// Check that it was opened correctly
		printf("\n No current game persistence found.");
		fclose(current_game);
		return(0);
	}
	for (i=-3; i<MAXLEN; i++)
	{	switch (i)
		{	case -3:
				if (tag == NULL){						// Check gamer tag
					fseek(current_game, 33, SEEK_CUR);
				}else{
					fgets(temp, 33, current_game);
					strdlm(tag, temp, temp2, 1);		// Load gamer tag[]
				}break;
			case -2:
				if (size == NULL){						// Check board size
					fseek(current_game, 32, SEEK_CUR);
				}else{
					fgets(temp, 33, current_game);
					strdlm(temp, temp, temp2, 1);		// Load board *size
					*size = atoi(temp);
				}break;
			case -1:
				if (rack == NULL){						// Check rack
					fseek(current_game, 32, SEEK_CUR);
				}else{
					fgets(temp, 33, current_game);
					strdlm(rack, temp, temp2, 1);		// Load tile rack[]
				}break;
			default:
				if (tiles == NULL){						// Check tiles
					fseek(current_game,	32*MAXLEN, SEEK_CUR);
				}else{
					fgets(temp, 33, current_game);
					strdlm(tiles[i], temp, temp2, 1);	// Load game board tiles[][]
				}break;
		}
	}
	if (tile_bag != NULL)
		for (i=0;(tile_bag[i-1] != -999);i++)			// Load tile_bag[]
			fscanf(current_game, "%d",&tile_bag[i]);
	fclose(current_game);								// Close persistence file
	return(1);
}	// Return 0 if no file, othewise return 1

int word_searcher(char tiles[][MAXLEN])	// Finds all the words in tiles[][]
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
	
	for (flag=1; flag<3; flag++)						// Determines direction
	{	/* Load the rows and then the columns of tiles[][] one by one */
		for (numrow=0; numrow<MAXLEN; numrow++)
		{
			switch (flag)
			{
				case 1:									// Search the rows
					strcpy(row,tiles[numrow]);
					break;
				case 2:									// Search the columns
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
					{									/* .. Then increments the first_letter */
						j=0; memset(word,'\0',MAXLEN);
						for (i=first_letter; i<=last_letter; i++){	word[j]=string[i];	j++;	}
						if (chk_dict(word))				// Returns 1 for found, 0 otherwise
						{
							make_upper(word);			// Save list of found words to file
							fprintf(found_words,"%s\n", word);	
							numwrds++;					// Increment number found
						} else {
							make_upper(word);			// Save list of non-words to file
							fprintf(not_words, "%s\n",word);	
						}
					}
				}
			}
		} 
	}
	fclose(not_words);
	fclose(found_words);
	return(numwrds);
}	// Return # of words


int chk_dict(char query[])								// Check the dictionary for the given word query
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
	char filename[10]={};								// String for holding the filename of the dictionary section we want
	int dir[27] = {};									// Directory array to hold index at beginning of file
	fpos_t wrdz_start;
	int top,bottom,middle,found;
	char word[16]={};
	
	make_lower(query);									// Required because dictionary is entirely lowercase
	if (length<=1) {	return(0);	}
	
	sprintf(filename,"%c%d.txt",query[0],length);		// Open the file
	dict_src = fopen(filename,"r");
	if	(dict_src == NULL){
		printf("\nERROR: No File");
		return(0);	}									// Check is file exists
	for (i=0;i<27 ; i++) {	
		fscanf(dict_src,"%d",&dir[i]);	}				// Read the index into the directory array
	for (i=0; i<( (int)query[1] -97); i++) {
		skip += dir[i];	}								// Skip = sum of dir[0] to dir[ first letter ]
	fgetpos(dict_src, &wrdz_start /* Pointer to the beginnning of the word list */ );
	
	// -------------------- Begin binary seach for query in word list --------------------
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
		make_upper(query);
		fclose(dict_src);// Close file
		return(1);							// a. return the index .
	} else {										// else
		make_upper(query);
		fclose(dict_src);// Close file
		return (0);							// b. return -1
	}
	// -------- End of binary search --------

}	// Return 0 = NOT word; return 1 = IS word


int endgame(void)										// Go through the motions of ending the game
{
	char tiles[MAXLEN][MAXLEN];
	int tile_bag[230];
	char rack[RAKLEN+1];
	char tag[20];
	int size = (strchr(tiles[0], 0) - tiles[0] );
	double score,hiscore;
	FILE * file_ptr;
	char temp[80]={};
	char sbuf[HMAX][LMAX]={};

	
	if ( load_crrnt(tiles, tile_bag, rack, tag, &size) )
		return (0/* Fail */);							// Load current game state
	word_searcher(tiles);								// Find all the words
	score = calc_net_score(NULL);							// Calculate player's score
	printf("\n\n Your board has a lexical density of %.4lf words per unit area.",score);
	printf("\n Would you like to see the list of words you used?\n >>");
	if (NorY()) {
		file_ptr= fopen("scores.txt", "r");
		while ( fgets(temp, 80, file_ptr) != NULL ) {
			printf("\n");
			fputs(temp, stdout);						// Show words found and their score values
		}
		fclose(file_ptr);
	}
	printf("\n\n Would you like to see the high score list?");
	if (NorY()) {										// Compare with the other high scores
		file_ptr= fopen("master_save.txt", "r");
		fscanf(file_ptr, "%s",temp);
		while ( fgets(temp, 80, file_ptr) != NULL ) {
			sscanf(temp,"%*s%lf", &hiscore);
			if ( hiscore < score) {						// Show current player's score in correct place relative to others
				printf("\n%20s %10.8lf %10.8lf",tag,hiscore,hiscore);
			}
			printf("\n");
			fputs(temp, stdout);
		}
		fclose(file_ptr);
	}
	printf("\n\n Would you like to save your game before quitting? >> ");
	if (NorY()) {
		update_save(score, sbuf);						// Save game to master file
	}
	return(0);
}

int score_word(char word[])								// Calculates total point value of a given word
{
	char points[11][11] = {/*0*/"",/*1*/"EAIONRTLSU",/*2*/"DG",/*3*/"BCMP",/*4*/"FHVWY",
							/*5*/"K",/*6*/"",/*7*/"",/*8*/"JX",/*9*/"",/*10*/"QZ"};
	int score = 0;
	int i,j;
	make_upper(word);
	for(i=0;i<strlen(word);i++)	{						// For each character in word..
		for (j=1; j<11; ++j)	{						// Find the point echelon in which the char resides...
			if (strchr(points[j], (int)word[i]) != NULL) {
				score += j;								// And increment the SCORE accordingly
			}
		}
	}
	return(score);	
}	// Total score is sent as return value

double calc_net_score(FILE * alt_out)					// Calculates final score for game
{
	double totscore=0;
	FILE * infile;
	FILE * scr_lst;
	char temp[MAXLEN] = {};
	int tik=0;
	int wrd_scr=0;
	int size;
	
	load_crrnt(NULL, NULL, NULL, NULL, &size);
	
	if (size == 0) { return(0);}						// Make sure size != 0 to prevent div by zero
	if (alt_out){
		scr_lst = alt_out;
	} else{
		scr_lst = fopen("scores.txt", "w");
	}
	do{	/* Loop until done */
		switch (tik)									// Marker for incrementing action choice
		{
			case 0:
				infile = fopen("found_words.txt", "r");
				wrd_scr =  1;							// Correct words are positively scored
				if (!(alt_out))
					fprintf(scr_lst, "#CORRECT#          #VALUE#\n");
				break;
			case 1:
				fclose(infile);
				break;
			case 2:
				infile = fopen("not_words.txt", "r");
				wrd_scr = -1;							// Incorrect words are negatively scored.
				if (!(alt_out))
					fprintf(scr_lst, "\n#INCORRECT#        #VALUE#\n");
				break;
			case 3:
				fclose(infile);
				break;
			default:
				totscore = totscore / pow( (double)size,2.0) ;
				fprintf(scr_lst, "#EOF#");
				fclose(scr_lst);
				return(totscore);
				break;
		}
		if (tik%2) /* TRUE if odd */ {	tik++;	}
		
		while (fscanf(infile, "%s", temp) != EOF)
		{
			if (abs(wrd_scr) == wrd_scr)
				wrd_scr = 1 ;							// If positive, make  1
			if (abs(wrd_scr) == (wrd_scr*-1)) 
				wrd_scr = -1 ;							// If negative, make -1
			wrd_scr *= score_word(temp);
			totscore += (double) wrd_scr;
			fprintf(scr_lst, "%-20s%5d\n",temp,wrd_scr);
		}
	} while(1);
	
	return(0);
}

int bffr_print(char sbuf[][LMAX],FILE * output)	
														// Draws the contents of sbuf[][] into the console (stdout)
{
	int i,numlines=0;
	if(!(**sbuf)){										// Clear the screen buffer	with spaces
		for (i=0; i<HMAX; i++){ 
			memset(sbuf[i],' ',(LMAX-2));
			sbuf[i][LMAX-1] = '\0';	// Must null terminate to secure proper handling when passed as pointer
		}
		if (DBG) {										// Print corners for debug 
			sbuf[0][0] = '#';
			sbuf[0][LMAX-2] = '#';
			sbuf[HMAX-1][0] = '#';
			sbuf[HMAX-1][LMAX-2] = '#';
		}
		return(0);
	}
	fprintf(output, "\n");								// Print initial new line
	for (i=0; i<HMAX; i++)
	{
		if (strspn(sbuf[i], " ") >=(LMAX -4) )
			continue;									// Skip empty lines
		fputs(sbuf[i], output);							// Print full line of buffer
		fprintf(output, "\n");							// Move to next line
		numlines++;										// Increment number of lines printed
	}
	
	bffr_cache(sbuf, 1);								// Store in buffer cache
	delay(.5);
	return(numlines);
}	// Return # of lines printed or 0 if run for initilization

void Draw_board(char tiles[][MAXLEN], char rack[], char sbuf[][LMAX])	
														// Function for drawing the board
/*	Program should draw a board that looks like this (roughly)
	This board happens to be for board size = 5 .. Height = (3+ 2*size +2)
                                                                           
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
	int i,j;
	char values[9][9] = {"Value:","1  EAION","1  RTLSU","2  DG","3  BCMP","4  FHVWY","5  K","8  JX","10 QZ"};
	char temp1[MAXLEN*4 +4] = {};
	char temp2[MAXLEN*4 +4] = {};
	int size = strlen(tiles[0]);

	sbuf[0][0] = '\0';
	bffr_print(sbuf, NULL);								// Fill buffer with spaces
	
// 1) Print the column lettering
	for (i=0; i<size; i++) {
		sprintf(temp1,"   %c", (char)(65+i));			// sPrint row letter and spaces
		strcat(temp2,temp1);							// Cat. above to make full row of letters
	}
	strovr(sbuf[1], temp2, 3);							// Overwtire letters onto appropraite spaces
	
// 2) Print values
	for (i=0; i<9; i++)
		strovr(sbuf[i+1], values[i], (16 + (4*(size -1))) );
	
// 3) Print border
		sprintf(temp1,"+");								// sPrint initial char (with \0 terminus)
		sprintf(temp2,"|");
	for (i=1; i<=size; i++)	{
		strcat(temp1," - +");							// Cat. following chars starting from \0
		strcat(temp2,"   |");
	}
	strovr(sbuf[2],temp1,4);							// Write first line of board
	for (i=0; i<(2*size); i++) {	
		if(i%2)	{										// On every other row, print..
			strovr(sbuf[i+3], temp1, 4);				// + - + - + - +
			continue;									// ... OR ...
		}
		strovr(sbuf[i+3], temp2, 4);					// |   |   |   |
	}
// 4) Print row numbers
	for (i=0; i<size; i++) {
		sprintf(temp1, " %02d", (i+1));					// Count out number of rows
		strovr(sbuf[3+ (i*2)], temp1, 0);				// Print on every other row
		for (j=0; j<size; j++) {
			sbuf[3+ (i*2)][(j*4)+6] = tiles[i][j];		// ... And the tiles for those rows
		}
	}
// 5) Print letter rack
	if (rack != NULL){
		sprintf(temp1,"Your Letters:");					// Initialze row with sting
		for (i=0; i<RAKLEN; i++) {
			sprintf(temp2,"%2c",rack[i]);			
			strcat(temp1,temp2);						// Cat. each letter in the rack
		}
		sbuf[4+ size*2][8] = '\0';						// Same as '\n', i.e. tells bffr_print to keep the whitespace
		strovr(sbuf[4+ size*2 +1], temp1, 4);			// Overwrite string to appropriate place
	}
}	// END OF FUNCTIION CALL


int strovr(char dest[], char src[], int pos)			// Places src[] at index = pos(ition) in dest[]
{	/* "String overwrite" */
	int i=0;
	if (strlen(dest) - strlen(src) <= 0)				// If src is too long or zero-length
		return(0);
	while(	i < strlen(src) &&							/* ..As long as it doesn't pass the end of dest[] */
			pos < strlen(dest)	)
		dest[pos++] = src[i++];							// Copy each char in src[] to dest[]
	return(1);
}	// Return 0 fail; 1 success


void update_save(double score, char sbuf[][LMAX])
/********************  Structure of a "master_save" file:  ********************
 *
n_saved_tags\n
nametag1             0.hiscore0 0.avgscor0 \n
[----- 20 chars ---] [-- 10 --] [-- 10 --] \n
[--- 32 chars per line with \n included ---]
 *
 * Each nametag has an associated file of the form "nametag.txt" that 
 *		contains their highest scoring board as well as their mos words	
 *
 ******************************************************************************/
{
	FILE * savfile;										// Vars for saving
	char temp[50];
	int number, i=0;
	char tag[20];

	char * names;										// Vars for loading scores
	double * highscore;
	double * avgscore;
	int * numgames;
	
	char tiles[MAXLEN][MAXLEN]={};						// Vars for updating player's file
	int size;
	char filename[25] = {};
	FILE * player_file;
	
	savfile = fopen("master_save.txt", "r");			// Open the master save file
	
	load_crrnt(tiles, NULL, NULL, tag, &size);
	fscanf(savfile, "%d", &number);						// Allocate heap space
	names = (char *) calloc(number+2, sizeof(char*));
	highscore = (double *) calloc(number+2, sizeof(double));
	avgscore = (double *) calloc(number+2, sizeof(double));
	
	for (i=0;(i<number) && (fgets(temp,50,savfile) /* Read data in */ != NULL); i++){
		*(&names+(i*sizeof(char*))) = (char *) calloc(20, sizeof(char));
		sscanf(temp,"%s %lf %lf", names[i], &highscore[i], &avgscore[i]);
	}
	strcpy(names[i],tag);								// Add new data to the arrays
	highscore[i] = score;
	avgscore[i] = 0;
	numgames[i] = 1;
														// Sort the data
	if (sort_scores(number, names, highscore, avgscore))
	{
		strcpy(filename,tag);							// Derive filename from tag
		strcat(filename, ".txt");
		player_file = fopen(filename, "W");				// Open the file
		Draw_board(tiles, NULL, sbuf);
		bffr_print(sbuf, player_file);					// Print to the player's file
		fprintf(player_file, "\n Highscore: %lf",score);
		fclose(player_file);
		number--;
	}					
	fclose(savfile);									// Close save file
	savfile = fopen("master_save.txt", "w");			// Re-open for writing
	fprintf(savfile, "%d",++number);					// Write new number of saves
	for (i=0;i<number; i++)								// Write out new (sorted) save data
		fprintf(savfile,"\n%20s %10.8lf %10.8lf", names[i], highscore[i], avgscore[i]);
	fclose(savfile);									// Close save file
	free(names);										// De-allocate heap space
	names = NULL;
	free(highscore);
	highscore = NULL;
	free(avgscore);
	avgscore = NULL;	
}	// End function call

int sort_scores(int n, char names[][20], double high[], double avg[] )
/* Avariation of "bubblesort" that handles parallel arrays */
{
    int last;											// subscript of last element of unsorted array
    int i=0,j;											//  index of first element in pair being compared 
	int flag=1;
	
    /*for each value of last from n-1(whole array) to 1 (2 element array)*/
	for (j=0;j<2;j++)
	{	for (last = n-1; last>=1; last--)				/* for each value of i from 0 to last-1*/
		{	for (i=0; i<= last-1; i++)					/* if list[i]>list[i+1] */
			{	switch (j)
				{	
					case 0:								// Swap these two elements
						if (high[i]<high[i+1]){			// If the latter is greater
							swapD( &high[i], &high[i+1] );
							if(avg)
							swapD( &avg[i], &avg[i+1] );
						}
						break;
					case 1:								// Check if tag is the same as another
						if(avg==NULL)	{	return(0);	}
						if (strcmp(names[i],names[last])==0)
						{	if (avg[i] - avg[last] == -avg[i])
								flag=0;					// If new score is worse than old, set flag=o
							memset(names[last],0,20);
							avg[i] = (avg[i] + avg[last] +high[last])/2.0;	// Calc. new avg
							high[last]=0;				// .. otherwise delete it.
						}
						break;
				}
			}
		}
	}
	return(flag);
}	// Exit 1 of 0 if duplicate is found to be worse than older value


void swapD (double* dx, double* dy)						/* swap the values pointed to by *x and *y */
{
    double dz;
    dz = *dx;											// Copy left to temp
    *dx = *dy;											// Copy right to left
    *dy = dz;											// Copy temp to right
}

int chk_tag(char tag[20])								// Check to see if the tag is already being used
{
	char temp[80];
	char name[20];
	int i=0;
	FILE * inf;
	
	inf = fopen("master_save.txt", "r");				// Open the file containing all the player tags
	
	while (fgets(temp, 80, inf) != NULL) {
		fscanf(inf, "%s",name);							// Read each tag
		make_upper(name);								// Make them the same format
		make_upper(tag);
		if(strcmp(name, tag) == 0)						// Compare them
			i=1;										// Return 1 if same
	}
	fclose(inf);
	return(i);
}	// Return 0 = fail, 1 = found
	
	
void place_word(char word[], char tiles[][MAXLEN], int vector[])		// Places word on the board
{
	int i=0;
	
	for (i=0; i<strlen(word); i++)	
	{
		switch (vector[0]) 
		{
		case 1:											// Vertical or DOWN
			tiles[vector[1]][(vector[2]+i)] = word[i];
			break;
				
		case -1:										// Vertical or DOWN
			tiles[(vector[1]+i)][vector[2]] = word[i];
			break;
		}
	}
}	

int bffr_cache(char sbuf[][LMAX],int ovr_wrt)			// Read/write to the buffer cache
{
	FILE * cache;
	int i,j;
	char nl;
	switch ((ovr_wrt && 1)) {
		case 1:
			cache = fopen("cache.txt", "w");
			//cache = stdout;
			if(cache == NULL)							// Check for correct opening
				return(0);
			if(sbuf)
				for (i=0; i<HMAX; i++) {
					for (j=0; j<LMAX; j++) {
						putc((int)sbuf[i][j], cache);	// Store chars in FILE
						fprintf(cache,"\n");				// Add \n
					}
				}
			break;
		case 0:
			cache = fopen("cache.txt", "r");
			if(cache == NULL)							// Check for correct opening
				return(0);
			if(sbuf)
				for (i=0; i<HMAX; i++) {
					for (j=0; j<LMAX; j++) {
						sbuf[i][j] = (char)getc(cache); // Read chars in FILE
						nl = (char)getc(cache);		// Add \n
					}
				}
			break;
		default:
			return(-1);
			break;
	}
	fclose(cache);
	return(1);
}
	
void word_updater(void)	// Updates the screen buffer to show hghest and lowest scoring words 
{
	char buffer[HMAX][LMAX];
	char words[HMAX][20]={};
	double scores[HMAX] ={};
	char tiles[MAXLEN][MAXLEN] = {};
	int size,i,j;
	char temp[40]={};
	FILE * ftmp;
	ftmp = tmpfile();									// Open temp file
	
	load_crrnt(tiles, NULL, NULL, NULL, &size);			// Load data
	word_searcher(tiles);								// Find words
	calc_net_score(ftmp);								// Calculate scores
	rewind(ftmp);
	do { 
		sort_scores(HMAX, words, scores, NULL);			// Sort best and worst
		fscanf(ftmp, "%s %lf",words[HMAX*3/5],&scores[HMAX*3/5]);
	} while (strcmp(words[HMAX*3/5],"#EOF#"));			// Look for sentinel
	memset(words[HMAX*3/5],0,20);
	scores[HMAX*3/5] = 0;
	bffr_cache(buffer, 0);
	for (i=0; i<(3+ (size*2) *3/5); i++) {
		sprintf(temp, "%-20s%5.0lf", words[i], scores[i]);
		strovr(buffer[i], temp, (30+ (4*(size -1))));
	}
	for (j=HMAX; i<(3+ (size*2)); i++) {
		sprintf(temp, "%-20s%5.0lf", words[j], scores[j--]);
		strovr(buffer[i], temp, (30+ (4*(size -1))));
	}
	bffr_cache(buffer, 1);								// Return to cache
	fclose(ftmp);
}
	
void delay(double secs) 									// Wait specified number of secs	
{
	int c0;													/* for clock ticks */
	int cps=CLOCKS_PER_SEC;									/* clock ticks per second */
	int clicksToDelay;
	
	clicksToDelay = cps*secs;
	c0=clock();
	while (clock()-c0 < clicksToDelay);
	   /*printf("#");*/
}

	
	
	


