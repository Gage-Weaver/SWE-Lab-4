#include <stdio.h>

void findCombinations(int score, int *plays, int num_plays, int *count, int start) {
	if (score == 0) { //Base case (score has been worked down to 0)
		printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n",
		       count[0], count[1], count[2], count[3], count[4]); //print out the properly formatted score summary
		return; //return to get out of this
	}
	if (score < 0) { //if the score is less than 0
		return; //return to get out
	}
	for (int i = start; i < num_plays; i++) { //for loop through each play
		count[i]++; //move onto the next play type
		findCombinations(score - plays[i], plays, num_plays, count, i); //call again with i as index as current play could be used again
		count[i]--; //backtracking to try other combos
	}
}
int main() {
	int score; //declare score variable
	int plays[] = {8, 7, 6, 3, 2}; //declare list of scores
	int count[5] = {0}; //declare list keeping count of score types
	while (1) { //infinite while loop until broken
		printf("Enter 0 or 1 to STOP\n"); //let user know how to stop
		printf("Enter the NFL score: "); //prompt user for score
		scanf("%d", &score); //scanf to get the score
		if (score <= 1) break; //if invalid score is entered end program
		printf("Possible combinations of scoring plays if a teams score is %d:\n", score); //print out header for possible scores
		findCombinations(score, plays, 5, count, 0);  //cal find combinations function with users score entered
	}
	return 0; //return 0 to terminate program
}