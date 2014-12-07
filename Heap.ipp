#include <string>

//left child = 2 * i + 1
//right child = 2 * i + 2
//parent = (i - 1) / 2

/*
I used http://courses.cs.washington.edu/courses/cse373/11wi/homework/5/BinaryHeap.java to help with how bubbleup
and http://opendatastructures.org/ods-cpp/10_1_Implicit_Binary_Tree.html for trickledown
*/

template<class Pri, class T>
Heap<Pri, T>::Heap(){
	backingArray = new std::pair<Pri, T>[START_SIZE];
	numItems = 0;
	arrSize = START_SIZE;
}

template<class Pri, class T>
Heap<Pri, T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri, T>::grow(){
	std::pair<Pri, T>* newArr = new std::pair<Pri, T>[arrSize * 2];
	arrSize *= 2;

	for (int i = 0; i < numItems; i++)	{
		newArr[i] = backingArray[i];
	}
	delete[] backingArray;
	backingArray = newArr;

}

template<class Pri, class T>
void Heap<Pri, T>::add(std::pair<Pri, T> toAdd){
	if (numItems == arrSize)
		grow();

	backingArray[numItems] = toAdd;
	bubbleUp(numItems);

	numItems++;
}

template<class Pri, class T>
void Heap<Pri, T>::bubbleUp(unsigned long index){
	int parent = (index - 1) / 2;

	if (backingArray[parent].first > backingArray[index].first && index > 0)	{
			backingArray[parent].swap(backingArray[index]);
			index = parent;
			bubbleUp(parent);
	}

}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	do
	{
		int j = -1;
		int r = 2 * index + 2;

		if (r < numItems && backingArray[r].first < backingArray[index].first)	{
			int l = 2 * index + 1;
			if (backingArray[l] < backingArray[r])	{
				j = l;
			}
			else {
				j = r;
			}
		}
		else {
			int l = 2 * index + 1;
			if (l < numItems && backingArray[l].first < backingArray[index].first)	{
				j = l;
			}
		}
		if (j >= 0)
			backingArray[index].swap(backingArray[j]);

		index = j;
	} while (index <= 0);
	
}

template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	std::pair<Pri, T> tmp = backingArray[0];
	backingArray[0] = backingArray[numItems - 1];
	numItems--;
	trickleDown(0);

	return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
}
