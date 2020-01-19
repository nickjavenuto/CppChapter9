//nickvenuto
//1/19/2020 ©
//Write a program that dynamically allocates an array large enough to hold a user defined number of test scores.  Once all the scores are entered, the array should be passed to a function that sorts them in ascending order. Another function should be called that calculates the average score.  THe program should display the sorted list of scores and average with appropriate headings.  Use pointer notation rather than array notation whenever possible.  INPUT VALIDATION ->Dont accept negative numbers for test scores

#include<iostream>
using namespace std; 

//Prototype functions; 
int* dynoAlloArr(int size);
int* sortAscending(int array[], int size);
int findAvg(int *array, int size);

//Main Function
int main()
{
	//Get user input for size of dynamically allocated array
	int numScores; 
	cout << "How many test scores do we need to collect?" << endl; 
	cin >> numScores; 
	if (numScores <= 0)
	{
		cout << "The number of test scores must be above 0" << endl << "How many test scores do we need to collect?" << endl;
		cin >> numScores;
	}
	//define pointers for the dynamically allocated arrays
	int* testScores = nullptr; 
	
	//dynamically allocate memory and create the array
	testScores = dynoAlloArr(numScores);

	//Collect the scores and store them in the new array
	cout << "Enter the test scores for the following student: " << endl; 
	for (int cnt1 = 0; cnt1 < numScores; cnt1++)
	{
		int score; 
		cout << "Student " << cnt1 + 1 << ": "; 
		cin >> score; 
		if (score < 0)
		{
			cout << "Negative scores are not acceptable inputs\nStudent "<<cnt1+1<<": ";
			cin >> score; 
		}
		*(testScores + cnt1) = score;
	}
	cout << endl; 
	//Sort the scores in ascending order
	testScores = sortAscending(testScores, numScores);
	cout << "The test scores in ascending order are as follow: " << endl; 
	for (int cnt1 = 0; cnt1 < numScores; cnt1++)
		cout << *(testScores + cnt1) << " ";
	cout << endl; 
	//Print the average test score
	int average = findAvg(testScores, numScores);
	cout << "The average test of the test scores is " << average << endl; 
}

int* dynoAlloArr(int size)
{
	int* newArr = new int[size];
	return newArr; 
}

int* sortAscending(int array[], int size)
{
	int maxElement; 
	int index; 

	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(array[index], array[index + 1]);
			}
		}
	}

	return array; 

}

int findAvg(int *array, int size)
{
	int total = 0; 
	int average; 
	for (int cnt1 = 0; cnt1 < size; cnt1++)
		total += array[cnt1];
	average = total / size;
	return average;

}

