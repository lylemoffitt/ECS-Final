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
#define ATOZ "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

void make_upper( char string[]);				// Convert to UPPERcase

void make_lower( char string[]);				// Convert to lowerCASE

int strdlm(char output[],char input[], char deliminators[], int inclusive);

int ctrl_dispatch(char ctrl_str[],
				  /* for #TOSS# */ int tile_bag[], char rack[],
				  /* for #QUIT# and #SAVE# */ char tiles[][MAXLEN], char tag[]  );

int read_in(char word[],int vector[]);		

void new_game(int size, int tile_bag[],char tiles[][MAXLEN], char rack[]);

char next_tile(int tile_bag[]);					// Returns the next letter in the stack

void fill_rack(int tile_bag[], char rack[]);	// Fills the letter rack from the bag

void empty_rack(char rack[]);					// Removes the used letters from the letter rack

int check_rack(char word[],int vector[], char tiles[][MAXLEN], char rack[]);		
												// Checks that the submitted word is in the rack

int show_rules();								// Prints all the rules and explains the game. Return 1 to Quit

void end_game(int *end);						// Player ends the game.

int NorY(void);

int toss_tiles(int tile_bag[], char rack[] );

void persist(char tiles[][MAXLEN],int tile_bag[],char rack[], char tag[] );

int load_crrnt(char tiles[][MAXLEN],int tile_bag[],char rack[], char tag[],int *size );

int word_searcher(char tiles[][MAXLEN]);		// Finds all the words in tiles[][]

int chk_dict(char query[]);						// Check the dictionary for the given word query

int endgame(void);

int score_word(char word[]);

double calc_net_score(int size);				// Calculates final score for game



int main ()
{
	//  ----- COPIED FROM MAIN -----
	char tiles[MAXLEN][MAXLEN];					// Array to hold tiles placed on the board: {row,column}
	int  size=15;								// Size of the board
	int tile_bag[226] = {};						// Array of mixed tiles. 15^2 + 1 = 226
												/* If i wanted to have an array of pointers i could use
	char *letters[] = {*p1,*p2,...};			 * This works because an array IS a pointer.
												 * I could use this to create an array of Files.  */
	char rack[RAKLEN +1] = {};					// Your rack of 8 letters
	int vector[3];								// Starting position: {direction, row, column}
//	int hash_ctrl=0;							// Indicates presence of #COMMAND use 
	char word[MAXLEN]={};						// String for holding the submitted word
	char tag[20];								// String to hold the player's gamer tag
	
	// NEW VARIABLES
	char buffer[3*MAXLEN][3*MAXLEN];			// Screen buffer to print from & with

	
	// dbug only
	int stop  = 1;
	
	srand(time(0));

	
	new_game(size, tile_bag, tiles, rack);
	fill_rack(tile_bag, rack);
	while(stop){
		printf("\n\n Your rack: %s",rack);
		printf("\n Enter a aproperly formatted string for testing.\n >>> "); // DEBUG
		switch( read_in(word,vector) ){
			case 0:
				printf("\n No word was found. Try again");
				break;
			case -1:
				ctrl_dispatch(word,tile_bag,rack,NULL,NULL);
				break;
			default: 
				printf("\n Fantastic. You managed to play the word %s ...",word);
				stop = 0;
		}
	}
	return(0);  
}// ------------- END MAIN ---------------

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

void make_upper( char string[])					// Convert to UPPERcase
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
void make_lower( char string[])					// Convert to lowerCASE
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

int strdlm(char output[],char input[], char deliminators[], int inclusive)		// String deliminator
{	/* Reads in from *ptr and returns first portion to match delimination, value=length */
	int i=0;
	char * pch1;
	char * pch2;
	
	char * temp = NULL;
	temp = (char *) calloc(strlen(input), sizeof(char));
	memset(temp,'\0',strlen(input));
	
	pch1 = strpbrk(input, deliminators);	// Find first matching char
	switch (inclusive)
	{
		case 1:
			while (pch1 != NULL)
			{	/* Inclusive case : 0-9, XY, A-O */
				strncat(temp,pch1,1);	i++;
				pch1 = strpbrk(pch1 +1,deliminators);
			}
			break;
		case 0:
			for (pch2 = pch1 +1; pch2 < strpbrk(pch1+1,deliminators); pch2++)
			{	/* Exclusive case : "word" or 'word', etc.. */
				strncat(temp,pch2,1);	i++;
			}
			break;
		default:
			return(-1);
	}
	strcpy(output,temp);
	free(temp);
	temp = NULL;
	return(i);
}	// Return = length

int ctrl_dispatch(char ctrl_str[], /* The input string containing the #CTRL# */
				  /* for #TOSS# */ int tile_bag[], char rack[],
				  /* for #QUIT# and #SAVE# */ char tiles[][MAXLEN], char tag[]  )
/* Check string input to see if it is a recognized #CTRL# sequence.					*
 * If pointers for tile_bag[] and rack[] are provided, then #CTRL# is also executed	*/
{
	char ctrl_key[6][10] = {/*0*/"#RULES#", /*1*/"#QUIT#", /*2*/"#END#", /*3*/"#SAVE#", /*4*/"#TOSS#"};
	int i;
	
	for (i=0; i<6; ++i)
		if (0 == strcmp(ctrl_str, ctrl_key[i]) ){ break; }
	switch (i)
	{
		case 0:									// "#RULES#"
			// show_rules();
			return(1);
		case 1:									// "#QUIT#"
			// Include missing functionality here
			return(1);
		case 2:									// "#END#"
			// Include missing functionality here
			return(1);
		case 3:									// "#SAVE#"
			// save_game();
			return(1);
		case 4:									// "#TOSS#"
			if( (tile_bag != NULL) && (rack != NULL) ) {
				toss_tiles(tile_bag,rack);
			}
			return(1);
		default:
			printf("\n %c %s %c is not a recognized #CTRL# sequence.",'"',ctrl_str,'"');
			return(0);
	}		
}	// Return 1 = success; 0 = fail

void new_game(int size, int tile_bag[],char tiles[][MAXLEN],char rack[])		
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
					// {A,B,C,D, E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z}
	int ref_freq[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
	int freq_dst[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1}; // 98 total
	int i,r,j,k,sum;// ^This^ is a list of how many of each tile are in the hypothicical "pile"
	
// Wipe the board blank
	for (i=0; i<size; i++)
	{
		memset(tiles[i],'\0',MAXLEN);
		memset(tiles[i],' ',size);
	}
	for (i=size; i<MAXLEN; i++)
		memset(tiles[i],'\0',MAXLEN);
	tiles[size/2][size/2] = '@';
	
//Populate tile_bag[]  (i.e. the "stack" ) with tiles chosen at random
	tile_bag[0] = size * size;
	
	for (i=1; i<=tile_bag[0]; i++)			// Create the "stack" or tile_bag
	{
		do{
			sum = 0;
			for (j=0; j<26; j++)			// 'sum' the number of tiles in the hypothetical pile
				sum += freq_dst[j];	
			if (sum <= 0){					/* The hypothetical  pile is empty */
				for (j=0; j<26; j++){		// Recreate the original pile (with same distribution)
					freq_dst[j] = ref_freq[j];	}}
		} while (sum <= 0);
		
		r = 0;
		if(sum /* prevents div by 0 */)
			r=rand()%sum;						// Pick a random tile from available tles in pile
		j = 0;
		for (k=0; k<26; ++k) {
			j += freq_dst[k];
			if( ((j>r) && (sum==0)) || ((j>=r) && sum) )	{	break;}
		} 
		
		//for (j=0; j<=r; j += freq_dst[k]) {	k++;}
		if (65+k>90)
			printf("ERROR");
		tile_bag[i] = 65+k;					// Add chosen tile to the "stack"
		freq_dst[k]--;						// Remove chosen tile from hypothetical pile
}

// Fill letter rack with spaces ( underscores )
	memset(rack,'_',RAKLEN);
	rack[RAKLEN +1]='\0';
}	
	

char next_tile(int tile_bag[])					// Returns the next letter in the stack
{
	int position;
	char letter;
	
	position = tile_bag[0];					// Index0 stores the position of the next char
	letter = (char)tile_bag[position];		// Letters in the array are int
	position = position - 1;				// Decrement the position is the next char
	tile_bag[0] = position;					// Update the position index
	
	return(letter);	
}
	

void fill_rack(int tile_bag[], char rack[])		// Fills the letter rack from the bag
{
	int i;
	
	for (i=0; i<RAKLEN; i++)				// Move through rack[] looking for '_'
	{
		if (isalpha(rack[i]) == 0)			// If rack slot is empty, fill it
		{	rack[i] = next_tile(tile_bag);	}
	}
}


void empty_rack(char rack[])					// Removes the used letters from the letter rack
{
	char temp[RAKLEN +1]={};
	int i,p=0;
	
	for (i=0; i<RAKLEN; i++)				// Goes through rack[] and removes '#'
	{
		if ( isalpha(rack[i]) )				// '#' is the flag char that removed letters are replaced with
		{	temp[p]=rack[i]; p++;	}
	}
	for (i=p; i<RAKLEN; i++)				// Fill remainder with  '_'
	{	temp[i] = '_';	}
	
	strncpy(rack,temp,RAKLEN);				// Read tiles back into rack[]
}


int check_rack(char word[],int vector[], char tiles[][MAXLEN], char rack[])
/* Checks that the submitted word is in the rack and on board. Return 1 if found, otherwise return 0 */
{
	char used[RAKLEN +1] = {};
	char temp[RAKLEN +1] = {};
	int board[MAXLEN -1] = {};
	int i=0,k=0,c=0,b=0,length,m=0;
	
	length = strlen(word);
	if( (vector != NULL) && (tiles != NULL ) ){
		switch (vector[0])					// Look to see what letters in word[] are already in play
		{
			case 1:							// Horizontal or RIGHT
				for (i=0; i<length; i++)	{
					if ( tiles[vector[1]][(vector[2]+i)] == word[i] ){	board[i]=1;	b++;	}
				}
				break;
			case -1:						// Vertical or DOWN
				for (i=0; i<length; i++)	{
					if ( tiles[(vector[1]+i)][vector[2]] == word[i] ){	board[i]=1;	b++;	} 
				}
				break;
		}
	}
	for (i=0; i<length; i++)				// Pick out the letters of word[] that are from the rack
	{
		if (board[i]==0) {	used[k]=word[i];	k++;	}
	}
	strncpy(temp,rack,RAKLEN);				// Read rack[] into temp[]
	
	for (i=0; i<k; i++)						// Look in temp[] for the letters used[]
	{
		if (used[i]=='\0')					// NULL char will be assigned to empty blocks in word[] string
		{	break;	}
		for (m=0; m<RAKLEN; m++)		
		{
			if (used[i] == temp[m])			// Look for match
			{	
				temp[m] = '_';
				c++;	m=RAKLEN;			// Match found -> exit loop
			}
		}									// Match not found -> increment and continue
	}
	if ( (length - b) == c )				// 'b' is the number of letters in word[] that are on the board
	{
		strncpy(rack,temp,RAKLEN);			// Fill used letter spaces in rack with '_'
		return(1);
	} else {
		return(0);
	}
}	// Return 1 = FOUND; 0 = fail


int NorY(void)									// Function to fetch and verify (Y/N) questions.
{
	char response;
	while (/* Until return(value) is sent */ 1)
	{
		scanf(" %c", &response);
		switch (response)
		{
			case 'Y':
			case 'y':
				return(1);					// Return 1 for YES
				break;
			case 'N':
			case 'n':
				return(0);					// Return 0 for NO
				break;
			default:
				printf("Only [y]es or [n]o responses will be accepted.\n>> ");
				break;
		}
	}
	printf("ERROR"); // Should never get here. Strictly for debug.
	return(-1);
}	// Return 0 = NO; 1 = YES


int toss_tiles(int tile_bag[], char rack[] )
{
	char junk[80]={};
	
	printf("\n What tiles would you like to toss? \n>> ");
	fgets(junk, 80, stdin);
	sprintf(strchr(junk,'\n'),"%c",'\0');	// Strip \n char from end
	make_upper(junk);
	strdlm(junk, junk, ATOZ, 1);			// Compress input down to just letters and make contiguous
	printf(" Are you sure you want to throw out the tiles : %s?\n>> ",junk);
	if(NorY()){
		check_rack(junk, NULL, NULL, rack);
		empty_rack(rack);
		fill_rack(tile_bag, rack);
		return(1);
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
	char temp[80] = " ";
	
	strcat(temp, ATOZ);							// Interpolate some data
	size = strspn (tiles[0],temp);
												// Open the file
	current_game = fopen("current.txt", "w");
	fprintf(current_game, "#%s#\n",tag);		// Save gamer tag
	fprintf(current_game, "#%d#\n",size);		// Save board size
	fprintf(current_game, "#%s#\n",rack);		// Save rack
	for (i=0; i<size; i++) {					// Save current game board
		fprintf(current_game, "#%s#\n",tiles[i]);
	}
	i=0;
	while (tile_bag[i] != 0) {					// Save tile_bag
		fprintf(current_game, "%d ",tile_bag[i]);
	}
	fprintf(current_game, "%d",-999);
	fclose(current_game);
}


int load_crrnt(char tiles[][MAXLEN],int tile_bag[],char rack[], char tag[],int *size )
/* Saves the current game state to a file. The file will exist as long as no other player	*
 *		wishes to play, or until the game is saved to the master file.						*/
{
	FILE * current_game;
	int i;
	char temp[80] = {};
		
	if( tag && size && rack && tiles && tile_bag )
		return(0);
	
	current_game = fopen("current.txt","r");	// Open the file
	
	if (current_game == NULL) {
		printf("\n Error: No current game persistence found.");
		return(0);
	}
	if (tag != NULL){
		fgets(temp, 80, current_game);
		strdlm(tag, temp, "#", 0);				// Load gamer tag[]
		
	}
	if (size != NULL){
		fgets(temp, 80, current_game);
		strdlm(temp, temp, "#", 0);				// Load board *size
		*size = atoi(temp);
	}
	if (rack != NULL){
		fgets(temp, 80, current_game);
		strdlm(rack, temp, "#", 0);				// Load tile rack[]
	}
	if (tiles != NULL){
		for (i=0; i<*size; i++) {				// Load game board tiles[][]
			fgets(temp, 80, current_game);
			strdlm(tiles[i], temp, "#", 0);
		}
	}
	if (tile_bag != NULL){
		i=0;
		do{											// Load tile_bag[]
			fscanf(current_game, "%d",&tile_bag[i]);
			i++;
		} while(tile_bag[i-1] != -999);
		tile_bag[i-1] = 0;
	}
	
	fclose(current_game);
	return(1);
}	// Return 0 = fail; 1 = success


int word_searcher(char tiles[][MAXLEN])			// Finds all the words in tiles[][]
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
	{	/* Load the rows and then the columns of tiles[][] one by one */
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
}	// Return # of words


int chk_dict(char query[])						// Check the dictionary for the given word query
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

}	// Return 0 = NOT word; return 1 = IS word


int endgame(void)
{
	char tiles[MAXLEN][MAXLEN];
	int tile_bag[226];
	char rack[RAKLEN+1];
	char tag[20];
	int size;
	
	load_crrnt(tiles, tile_bag, rack, tag, &size);
	word_searcher(tiles);
	calc_net_score(size);
	
	return(0);
}

int score_word(char word[])					// Calculates total point value of a given word
{
	char points[11][11] = {/*0*/"",/*1*/"EAIONRTLSU",/*2*/"DG",/*3*/"BCMP",/*4*/"FHVWY",
							/*5*/"K",/*6*/"",/*7*/"",/*8*/"JX",/*9*/"",/*10*/"QZ"};
	int score = 0;
	int i,j;

	for(i=0;i<strlen(word);i++)				// For each character in word..
	{
		for (j=1; j<11; ++j)				// Find the point echelon in which the char resides...
		{
			if (strchr(points[j], (int)word[i]) != NULL) {
				score += j;					// And increment the SCORE accordingly
			}
		}
	}
	return(score);							// Total score is sent as return value
}

double calc_net_score(int size)				// Calculates final score for game
{
	double totscore=0;
	FILE * infile;
	FILE * scr_lst;
	char temp[MAXLEN] = {};
	int tik=0;
	int wrd_scr=0;
	
	if (size == 0) { return(0);}			// Make sure size != 0 to prevent div by zero
	
	scr_lst = fopen("scores.txt", "w");
	
	do{	/* Loop until done */
		switch (tik)						// Marker for incrementing action choice
		{
			case 0:
				infile = fopen("found_words.txt", "r");
				wrd_scr =  1;				// Correct words are positively scored
				fprintf(scr_lst, "CORRECT WORDS\n");
				break;
			case 1:
				fclose(infile);
				break;
			case 2:
				infile = fopen("not_words.txt", "r");
				wrd_scr = -1;				// Incorrect words are negatively scored.
				fprintf(scr_lst, "\nINCORRECT WORDS\n");
				break;
			case 3:
				fclose(infile);
				break;
			default:
				totscore = totscore / pow( (double)size,2.0) ;
				fclose(scr_lst);
				return(totscore);
				break;
		}
		if (tik%2) /* TRUE if odd */ {	tik++;	}
		
		while (fscanf(infile, "%s", temp) != EOF)
		{
			if (abs(wrd_scr) == wrd_scr) { wrd_scr = 1 ;}		// If positive, make  1
			if (abs(wrd_scr) == (wrd_scr*-1)) { wrd_scr = -1 ;}	// If negative, make -1
			wrd_scr *= score_word(temp);
			totscore += (double) wrd_scr;
			fprintf(scr_lst, "%-20s%5d\n",temp,wrd_scr);
		}
	} while(1);
	
	return(0);
}









