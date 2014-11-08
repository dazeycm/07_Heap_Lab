#include <string>

//left child = 2 * i + 1
//right child = 2 * i + 2
//parent = (i - 1) / 2

/*

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
	//TODO
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

	if (backingArray[parent] > backingArray[index] && index > 0)	{
			backingArray[parent].swap(backingArray[index]);
			index = parent;
			bubbleUp(parent);
	}

}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	int left = 2 * index + 1;
	int right = 2 * index + 2;
}

template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	std::pair<Pri, T> tmp = backingArray[0];
	backingArray[0] = backingArray[numItems];
	numItems--;
	trickleDown(0);

	return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
}
