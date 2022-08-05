#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


char*  CardType(long long totalsum, char* input){

	int length = strlen(input) - 1;

	if(totalsum % 10 != 0){
        return "Invalid\n";
    }
	if((length == 16 || length == 13) && input[0] == '4'){
        return "Visa\n";
    }
	//Mastercard
	else if(length == 16 && input[0] == '5' && (input[1] > '0' && input[1] < '6')){
        return "Mastercard\n";
    }
	else if(length == 15 && input[0]== '3' && (input[1] == '4' || input[1] == '7')){
    	return "AMEX\n";
    }
	else{
		return "INVALID\n";
    }
}

//Lugn's Algorithm
long long LugnsAlgo(char* input){

	int length = strlen(input) - 1;

	//Sum of start at second last one times 2
	long long sum1 = 0;
	char* doubled = malloc(20);
	//For loop to iterate over original input string
	for(int i = length - 2; i>=0; i = i - 2)
	{
		char* data  = malloc(2);
		sprintf(data,"%i",(input[i] -'0') *2);
		strcat(doubled, data);
		free(data);
	}
	for(int i = 0; i < strlen(doubled); i++)
    {
        printf("%c\n", doubled[i]);
        sum1 += doubled[i] - '0';
    }

	//Sum of starting at last one
	long long  sum2 = 0;
	for(int i = length - 1; i >= 0; i = i - 2)
	{
		sum2 += (input[i] -  '0');
	}

	free(doubled);
	return sum1 + sum2;
}

//Function that checks if the string has any letters
int OnlyNumbers(const char *input){

	//Determine length
	int length = strlen(input) - 1;

	for(int i = 0; i < length; i++)
		{
			if(isdigit(input[i]))
				continue;
			else
				return 1;
		}
	return 0;
}

//Main Function
int main(void){

	char* input = malloc(20);

	printf("Enter your visa Number : ");
    while(1)
	{
		fgets(input, 20, stdin);
		int length = strlen(input) - 1;
		int DigitPresent = OnlyNumbers(input);
		if(!DigitPresent && length > 0)
			break;
		printf("Try again ^_^ : ");
	}
	long long totalsum = LugnsAlgo(input);
	printf("%s",CardType(totalsum, input));

	free(input);
    return 0;
}