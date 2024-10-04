#include <stdio.h>

int main() {
	float temperature, tempCelsius; //declare a float for the temperature inputted by user and one for the temp in celsius
	char tempScale; //declare a character for the user to input their temperature scale

	printf("Enter the temperature scale (C/F/K): "); //prompt user to input temperature scale
	scanf(" %c", &tempScale); //scan for input

	printf("Enter the temperature: "); //prompt user to input temperature
	scanf("%f", &temperature); //scan for input


	if (tempScale == 'C') { //if input is already in celsius
		tempCelsius = temperature; // Already in Celsius
	} else if (tempScale == 'F') { //if the temp is in fahrenheit
		tempCelsius = ((temperature - 32) * (5.0 / 9.0)); // Fahrenheit to Celsius
	} else if (tempScale == 'K') { //if the temp is in kelvin
		tempCelsius = (temperature - 273.15); // Kelvin to Celsius
	} else { //if none of these are caught
		printf("Invalid scale entered. Please use C, F, or K.\n"); //tell user the input was invalid
		return 1; // Exit the program
	}

	if (tempCelsius <= 0) { //if temp below or at 0
		printf("Freezing: it is %.2f degrees Celsius Wear a heavy coat\n", tempCelsius); //tell user its freezing with formatting to only show 2 decimal places 
	} else if (tempCelsius <= 10) { //if temp is below or at 10 but above 0
		printf("Cold: it is %.2f degrees Celsius Wear a normal jacket!\n", tempCelsius); //tell user its cold with formatting to only show 2 decimal places 
	} else if (tempCelsius <= 25) { //if temp is below or at 25 but above 10
		printf("Comfortable: it is %.2f degrees Celsius, you will be fine to dress normally\n", tempCelsius); //tell user its comfortable with formatting to only show 2 decimal places 
	} else if (tempCelsius <= 35) { //if temp is below or at 35 but above 25
		printf("Hot: it is %.2f degrees Celsius, make sure you hydrate\n", tempCelsius); //tell user its hot with formatting to only show 2 decimal places 
	} else { //if no other conditions are caught it is above 35 degrees
		printf("Extremely Hot: it is %.2f degrees Celsius do not go outside\n", tempCelsius); //tell user its extremely hot with formatting to only show 2 decimal places 
	}

	return 0; // Successful program termination
}