//author: Devin Martineau
//date: 4/22/25
//purpose: project 10

#define SIZE 7
#define MAX_SIZE 30
#define MAX_ROW 2
#include<stdio.h>

void lowercase(char wordup[][MAX_SIZE], int index);
void uppercase(char wordup[][MAX_SIZE], int index, char correct_word[SIZE]);
void arrows(char wordup[][MAX_SIZE], int index, char correct_word[SIZE]);
void win_condition(char correct_word[SIZE], int count);
int winner(char wordup[][MAX_SIZE], int index, char correct_word[SIZE]);

int main(){
int column, count = 0, index = 0;
char wordup[MAX_ROW][MAX_SIZE], correct_word[SIZE];
int win = winner(wordup, index, correct_word);


FILE *fptr;
fptr = fopen("mystery.txt", "r");
	if (fptr == NULL) {
		printf("Can't open file\n");
		return 0;
	}
fgets(correct_word, SIZE, fptr);
fclose(fptr);

for(int row = 0; row < MAX_ROW; row++){
//	if(count < 6){
		count = count + 1;
		printf("\nGUESS %d! Enter your guess: ", row + 1);
		for(int column = 0; column < 1; column++){
			 fgets(wordup[row], SIZE, stdin);
		}
			if(wordup[MAX_ROW][MAX_SIZE] != 5){
				printf("Your guess must be 5 letters long.\nPlease try again: ");
				for(int column = 0; column < 1; column++){
					fgets(wordup[row], SIZE, stdin);
				}
			}
		printf("================================\n");
		lowercase(wordup, index);
		uppercase(wordup, index, correct_word);
		for(int index = 0; index < count; index++){
			printf("%s", wordup[index]);
			arrows(wordup, index, correct_word); 
		}
		index = index + 1;
/*	}
	else if(win == 5){
		win_condition(correct_word, count);
	}*/
}

return 0;
}
//lowercase converter
void lowercase(char wordup[][MAX_SIZE],int index){

	for(int column = 0; column < SIZE; column++){
		if(wordup[index][column] >=  65 && wordup[index][column] <= 90){
			wordup[index][column] = wordup[index][column] + 32;
		}
	}
}
//uppercase converter
void uppercase(char wordup[][MAX_SIZE], int index, char correct_word[SIZE]){

	for(int column = 0; column < 5; column++){
		if(wordup[index][column] == correct_word[column]){
			wordup[index][column] = wordup[index][column] - 32;
		}
	}
}

//arrow placers
void arrows(char wordup[][MAX_SIZE], int index, char correct_word[SIZE]){

	for(int column = 0; column < 6; column++){
		if(wordup[index][column] >=  65 && wordup[index][column] <= 90){
			for(int i = 0; i < 6; i++){
			if(wordup[index][i] == correct_word[column]){
				printf("^");
			}
			else{
				printf(" ");
			}
			}
		}
	}
	printf("\n");
}

//win
int winner(char wordup[][MAX_SIZE], int index, char correct_word[SIZE]){
int win = 0;
	for(int column = 0; column < 5; column++){
		if(wordup[index][column] == correct_word[column]){
			win = win + 1;
		}
	}
return win;
}

//the win condition
void win_condition(char correct_word[SIZE], int count){

FILE *fptr;
fptr = fopen("mystery.txt", "r");
	if (fptr == NULL) {
		printf("Can't open file\n");
	}
fgets(correct_word, SIZE, fptr);
fclose(fptr);

printf("		%s", correct_word[SIZE]);
printf("	You won in %d guess!\n", count);
	switch(count){
		case '1':
			printf("		GOATED!\n");
			break;
		case '2':
			printf("		Amazing!\n");
			break;
		case '3':
			printf("		Amazing!\n");
			break;
		case '4':
			printf("		Nice!\n");
			break;
		case '5':
			printf("		Nice!\n");
			break;
		case '6':

			break;
		}
}
