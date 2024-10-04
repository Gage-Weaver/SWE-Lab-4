#include <stdio.h>

int main() {
    float temperature, tempCelsius; // Declare a float for the temperature inputted by user and one for the temp in Celsius
    char tempScale, targetScale; // Declare characters for the user to input their temperature scale and target scale

    printf("Enter the measured temperature scale (C/F/K): "); // Prompt user to input temperature scale
    scanf(" %c", &tempScale); // Scan for input

    printf("Enter the temperature: "); // Prompt user to input temperature
    scanf("%f", &temperature); // Scan for input

    // Convert to Celsius
    if (tempScale == 'C') {
        tempCelsius = temperature; // Already in Celsius
    } else if (tempScale == 'F') {
        tempCelsius = (temperature - 32) * (5.0 / 9.0); // Fahrenheit to Celsius
    } else if (tempScale == 'K') {
        tempCelsius = (temperature - 273.15); // Kelvin to Celsius
    } else {
        printf("Invalid scale entered. Please use C, F, or K.\n"); // Tell user the input was invalid
        return 1; // Exit the program
    }

    printf("Enter the target temperature scale (C/F/K): "); // Prompt for target scale
    scanf(" %c", &targetScale); // Scan for input

    // Convert to the target scale if needed
    float targetTemperature;
    if (targetScale == 'C') {
        targetTemperature = tempCelsius; // Already in Celsius
    } else if (targetScale == 'F') {
        targetTemperature = (tempCelsius * 9.0 / 5.0) + 32; // Celsius to Fahrenheit
    } else if (targetScale == 'K') {
        targetTemperature = tempCelsius + 273.15; // Celsius to Kelvin
    } else {
        printf("Invalid target scale entered. Please use C, F, or K.\n"); // Tell user the input was invalid
        return 1; // Exit the program
    }

    // Determine the category and advisory based on Celsius temperature, and format the float so it does not take up a ton of room
    if (tempCelsius <= 0) {
        printf("Freezing: it is %.2f degrees %c. Wear a heavy coat.\n", targetTemperature, targetScale); // Freezing
    } else if (tempCelsius <= 10) {
        printf("Cold: it is %.2f degrees %c. Wear a normal jacket!\n", targetTemperature, targetScale); // Cold
    } else if (tempCelsius <= 25) {
        printf("Comfortable: it is %.2f degrees %c. You will be fine to dress normally.\n", targetTemperature, targetScale); // Comfortable
    } else if (tempCelsius <= 35) {
        printf("Hot: it is %.2f degrees %c. Make sure you hydrate.\n", targetTemperature, targetScale); // Hot
    } else {
        printf("Extremely Hot: it is %.2f degrees %c. Do not go outside.\n", targetTemperature, targetScale); // Extremely Hot
    }

    return 0; // terminate program
}