#include <iostream>
#include <string>
using namespace std;

//Template: Meaning it does not matter what type is used
template<typename theType>
void SelectionSort(theType numbers[], int numbersSize) {
	int i = 0;
	int j = 0;
	int indexSmallest = 0;
	theType temp;  // Temporary variable for swap
	for (i = 0; i < numbersSize; ++i) {
		// Find index of smallest remaining element
		indexSmallest = i;
		for (j = i + 1; j < numbersSize; ++j) {
			if ( numbers[j] < numbers[indexSmallest] ) {
				indexSmallest = j;
			}
		}
		// Swap numbers[i] and numbers[indexSmallest]
		temp = numbers[i];
		numbers[i] = numbers[indexSmallest];
		numbers[indexSmallest] = temp;
	}
}

//Template: Meaning it does not matter what type is used
template<typename myType>
void Merge (myType numbers[], int i, int j, int k) {
	//Determines size of parition
	int mergedSize = k - i + 1;
	//Copy for merged number
	myType mergedNumbers[];
	//Used to determine where the merged number will go
	int mergePos = 0;
	//Left and right parition start position
	int leftPos = 0;
	int rightPos = 0;
	//Initlization
	leftPos = i;
	rightPos = j+1;
	//Determines what partition the smallest number will go to
	while (leftPos <= j && rightPos <= k) {
		if ((numbers[leftPos]) < (numbers[rightPos])) {
			mergedNumbers[mergePos] = numbers[leftPos];
			++leftPos;
		}
		else {
			mergedNumbers[mergePos] = numbers[rightPos];
			++rightPos;
		}
		++mergePos;
	}
	//Add remaining elements to merged numbers if left is emty:
	while (leftPos <= j) {
		mergedNumbers[mergePos] = numbers[leftPos];
		++leftPos;
		++mergePos;
	}
	//Add remaining elements to merged numbers if right is empty
	while (rightPos <= k) {
		mergedNumbers[mergePos] = numbers[rightPos];
		++rightPos;
		++mergePos;
	}
	//Take numbers from copy and store it back into the original list, numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
		numbers[i + mergePos] = mergedNumbers[mergePos];
	}
}

//Template: Meaning it does not matter what type is used
template<typename thisType>
void MergeSort (thisType numbers[], int beginNum, int endNum) {
	//Merge point
	/*//For use to get mid point
	//Yay, recurrsion.
	if (beginNum < endNum) {
		midNum = (beginNum + endNum) / 2;
		ZipSort(numbers, beginNum, midNum);
		ZipSort(numbers, midNum + 1, endNum);
		Merge(numbers, beginNum, midNum, endNum);
	}*/
	//Base case!
	int size = endNum;
	if (beginNum >= size - 1) {
		return;
	}
	int low = beginNum;
	for (int index = beginNum + 1; index < size; index++)
	{
		if (numbers[index] < numbers[low])
			low = index;
	}
	thisType temp = numbers[beginNum];
	numbers[beginNum] = numbers[low];
	numbers[low] = temp;
	//Recurrsion!
	MergeSort(numbers, beginNum + 1, 0);
}

template<typename someType>
void print(someType someArray[], int size){
	cout << "{";
	for (int x = 0; x < size; ++x)
	{
		cout << someArray[x];
		if (x < (size - 1))
		{
			cout << " ";
		}
	}
	cout << "}";
}

int main(){
	//Arrays to test:
	string randomWords [] = {"jiffy", "zappy", "loopy", "bubbly", "catty", "daddy", "zany", "iffy", "snippy"};
	int intList [] = {25,10,8,6,43,89,14, 32, 0};
	float floatList [] = {5.34, 1.11, 33.43, 2.45, 89.67, 77.051, 10.6, 9.3456, 100.21};
	int sizeRW = sizeof(randomWords)/sizeof(randomWords[0]); //Num size for randomWords array
	int sizeIL = (sizeof(intList)/sizeof(intList[0])); //Size of intList array
	int sizeFL = (sizeof(floatList)/sizeof(floatList[0])); //Size of floatList array
	cout << "This used SelectionSort:" << endl;
	//Selection sort for string array
	SelectionSort(randomWords, sizeRW);
	print(randomWords, sizeRW);
	cout << endl;
	//Selection sort for int array
	SelectionSort(intList, sizeIL);
	print(intList, sizeIL);
	cout << endl;
	//Selection sort for float array
	SelectionSort(floatList, sizeFL);
	print(floatList, sizeFL);
	cout << endl;
	//Time to merge.
	cout << "\nThis used MergeSort:" << endl;
	//Merge sort and print for string array
	MergeSort(randomWords, 0, 9);
	print(randomWords, 9);
	cout << " ";
	cout << endl;
	//Merge sort and print for int array
	MergeSort(intList, 0, sizeIL);
	print(intList, sizeIL);
	cout << " ";
	cout << endl;
	//Merge sort and print for float array
	MergeSort(floatList, 0, sizeFL);
	print(floatList, sizeFL);
}