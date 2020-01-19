//nick venuto ©
//1.18.2010
//Chapter 9 Array Expander

//Write a function that accepts an int array and the arrays size as arguments.  The funtion should create a new array    twice the size of the argument array.  The function should copy the contents of the argument array to the new array and initialize the unused elements of the second array with 0. The function should return a pointer to the new array.

# include <iostream>
using namespace std; 

//Function Prototypes
int* doubleTheSize(int* arr, int size);

int main()
{
	int array[5] = { 1,2,3,4,5 };
	int* newArr = nullptr; 
	newArr = doubleTheSize(array, 5);

	cout << "The original array is: \n";
	for (int index = 0; index < 5; index++)
		cout << array[index] << " ";
	cout << endl; 
	cout << "\nThe new array is: \n"; 
	for (int index = 0; index < 10; index++)
		cout << newArr[index]<<" "; 
	cout << endl;
	delete[] newArr;
	newArr = nullptr; 
}

int* doubleTheSize(int* arr, int size)
{
	
	int newSize = size * 2; 
	int *newArray = new int[newSize];
	for (int cnt1 = 0; cnt1 < newSize; cnt1++)
		newArray[cnt1] = 0;
	for (int cnt1 = 0; cnt1 < size; cnt1++)
		*(newArray + cnt1) = *(arr + cnt1);
	return newArray; 

}