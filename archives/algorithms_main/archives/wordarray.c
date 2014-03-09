#include <stdio.h>

int main(){
	char word[50]; // insert \0 at end

	char word2[50] = {'t','e','s','t','\0'}; // sets \0 to other 45 char data
	char word2same[50] = "test";

	//pointer test
	char ch;
	*&ch = 'P';

	return 0;
}