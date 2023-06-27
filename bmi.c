#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

/**
 * main - Entry point of the program. Calculates Tina's Body Mass Index (BMI).
 *
 * Return: Always 0
 */
int main(void)
{
	char weightPrompt[] = "Please enter your weight in kilograms (e.g., 68.5): ";
	char heightPrompt[] = "Please enter your height in centimeters (e.g., 165): ";
	char bmiMessage[] = "Tina, your Body Mass Index (BMI) is: ";

	char weightStr[BUFFER_SIZE];
	char heightStr[BUFFER_SIZE];
	float weight, height, bmi;

	write(STDOUT_FILENO, weightPrompt, sizeof(weightPrompt) - 1);
	fflush(stdout);

	ssize_t weightLength = read(STDIN_FILENO, weightStr, BUFFER_SIZE);
	weightStr[weightLength - 1] = '\0'; /* Remove trailing newline */
	weight = atof(weightStr);

	write(STDOUT_FILENO, heightPrompt, sizeof(heightPrompt) - 1);
	fflush(stdout);

	ssize_t heightLength = read(STDIN_FILENO, heightStr, BUFFER_SIZE);
	heightStr[heightLength - 1] = '\0'; /* Remove trailing newline */
	height = atof(heightStr);

	height /= 100;

	bmi = weight / (height * height);

	write(STDOUT_FILENO, bmiMessage, sizeof(bmiMessage) - 1);
	char bmiStr[BUFFER_SIZE];
	int bmiLength = snprintf(bmiStr, BUFFER_SIZE, "%.2f\n", bmi);
	write(STDOUT_FILENO, bmiStr, bmiLength);

	return (0);
}
