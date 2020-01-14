//nick venuto
//1.13.2020©
/*This is a review of pointers, beginning the Advanced C++ Class*/
#include <iostream>
#include <iomanip>


using namespace std; 




int main()
{
	//step 1: Create the arrays and variables
	double dArr[5]; //explicit because it tells you it will have 5 elements
	long lArr[7] = { 100000, 134567, 9, -234567, -1, 123489 };
	int iArr[3][5];
	char sName[31] = "nick venuto"; // for char arrays, include 1 for the null terminator.  i.e. 30 elements = 31
	short cnt1, cnt2; 
	long double total = 0;//initialize the accumulator to zero 
	long highest; 

	//for loop to put a random number into each element fo dArr.
	srand((unsigned int)time(NULL)); 
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		dArr[cnt1] = rand();
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		total += dArr[cnt1]; 
	

	cout << "The total of the elements in dArr is " << total << " using subscript notation" << endl; 
	cout << "The average of the elements in dArr is " << total / 5 << " using subscript notation" << endl;
	
	total = 0; 

	//another loop to add up the elements of double array using pointer notation
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		total += *(dArr+cnt1);
	//step 6a: print out total and average
	cout << "The total of the elements in dArr is " << total <<" using pointer notation"<<endl;
	cout << "The average of the elements in dArr is " << total / 5 << " using pointer notation" << endl;

	//find the highest element in lArr
	for (cnt1 = 1, highest = lArr[0]; cnt1 < 7; cnt1++)
	{
		if (lArr[cnt1] > highest)
			highest = lArr[cnt1] ; 
	}
	//print the highest element in lArr
	cout << highest << " is the highest element in lArr"<<endl;

	// a for loop to put a random number, each with a value no lower than 1 and no higher than 53, 
	//into each element of iArr, the array of integer.
	for (cnt1 = 0; cnt1 < 3; cnt1++)
	{
		for (cnt2 = 0; cnt2 < 5; cnt2++)
			iArr[cnt1][cnt2] = rand() % 53 + 1; 
	}
	//use a seperate loop to pring iArr with 3 rows on your screen, using setw() to control width of 
	//each column
	for (cnt1 = 0; cnt1 < 3; cnt1++)
	{
		for (cnt2 = 0; cnt2 < 5; cnt2++)
			cout << setw(8) << iArr[cnt1][cnt2]; 
		cout << endl; 
	}

	cout << endl; 
	//print the 2 dimiensional array, iArr, so that all 3 numbers in column 0 are printed then
	//on the next line all 3 numbers in column 1, etc.
	for (cnt2 = 0; cnt2 < 5; cnt2++)
	{
		for (cnt1 = 0; cnt1 < 3; cnt1++)
			cout << setw(8) << iArr[cnt1][cnt2];
		cout << endl;
	}

	//12: us cin.getline to type another name into the variable sName
	cout << "sName is currently " << sName << endl; 
	cout << "Please type another name into variable sName" << endl; 
	cin.getline(sName, 31);
	cout << "sName is now "<< sName << endl; 

	//13:print the ASCII value of each character in the char array, 1 perline.
	cnt1 = 0; 
	while (sName[cnt1] != '\0')
	{
		cout << int(sName[cnt1]) << endl; //to get the ASCII value, cast it into an int
		cnt1++; 
	}
	cout << endl; 
	//14: make the array of char, sName, have the name Albert Einstein in it. 
	strcpy_s(sName, "Albert Einstein"); 
	cout << "using strcpy_s, sName is now " << sName << endl; 

	//step 15: 
	cout<< "The 12th charachters ASCII value is "<<int(sName[11])<<endl;

	//step 16: define a pointer to a double, pdArray
	double* pdArray;

	//step 17: assidn the pointer, pdarray, to contain the address of the double array, dArr
	pdArray = dArr; 

	//step 18: us an array name, dArr, to print out the array elements with subscript notation.
	cout << "The elements of dArr using subscript notation are: " << endl; 
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		cout << dArr[cnt1] << " "; 
	cout << endl; 

	//step 19: use the pointer to print all the elements of the array, dArr, using pointer notation
	cout << "The elements of dArr using pointer notation are: " << endl;
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		cout << *(pdArray+cnt1) << " ";
	cout << endl;

	//step 20: use the pointer to print out the array elements with pointer notation, but change the
	//pointer to point to the actual array element rather than the method in 18
	cout << "The address stored in the pdArray before the loop is " << pdArray << endl;
	
	for (cnt1 = 0; cnt1 < 5; cnt1++, pdArray++)
		cout << *pdArray << " ";
	cout << endl;
	cout << pdArray << endl; 

	//21: use the array name and pointer notation for the double array to print the entire array
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		cout << *(dArr + cnt1) << " ";
	cout << endl; 
	//22: using a different pointer, piArray, dynamically allocate enough memory for 100 ints and assign
	//the address to the pointer

	int* piArray; 
	piArray = new int[100];
	//or in 1 statement int* piArray =new int[100];

	//23 in a for loop assign every element in the array and random number between 1 and 49
	for (cnt1 = 0; cnt1 < 100; cnt1++)
		*(piArray+cnt1) = rand() % 49 + 1; 
	//24:using cout pring the first 10 items in the dynamically created array
	for (cnt1=0; cnt1<10; cnt1++)
		cout << *(piArray+cnt1) << " "; 

	//c++11 smart pointers - added in class
	short many; 
	cout << endl; 
	cout << "How many new doubles do you want?" << endl; 
	cin >> many; 
	unique_ptr<double[]>ptr(new double[many]); 
	for (cnt1 = 0; cnt1 < many; cnt1++)
		ptr[cnt1] = cnt1 + 5; 
	for (cnt1 = 0; cnt1 < many; cnt1++)
		cout << ptr[cnt1] << " ";
	cout << endl; 

	//25:Free up the dynamically allocated memory creaded with the new key word
	delete[]piArray; 
	
	//25: Free up the dynamically allocated memory




	
	return 0; 
}

