#include <iostream>

class IntArr
{
private:
	int cap;
	int nrOfel;
	int* arr;

	void initialise(int from)
	{
		for (size_t i = from; i < cap; i++)
		{
			arr[i] = 0;
		}
	}

	void expand()
	{
		cap *= 2;
		int* tempArr = new int[cap];

		for (size_t i = 0; i < nrOfel; i++)
		{
			tempArr[i] = arr[i];
		}

		delete[] arr;
		arr = tempArr;
		initialise(nrOfel);
	}

public:
	IntArr()
	{
		cap = 10;
		nrOfel = 0;
		arr = new int[cap];
	}

	~IntArr()
	{
		delete[]arr;
	}

	void add(int el)
	{
		if (nrOfel >= cap)
			expand();

		arr[nrOfel++] = el;
	}

	int getAt(int index) const
	{
		if (index < 0 || index >= nrOfel)
			throw ("Out of bounds exception!");

		return arr[index];
	}

	void popBack()
	{
		if (nrOfel > 0)
			arr[--nrOfel] = 0;
		else
			throw("Empty array!");
	}

	int getNrOfEl() { return nrOfel; }
};

int main()
{
	IntArr arr;

	arr.add(10);
	arr.add(11);
	arr.add(10);
	arr.add(11);
	arr.add(10);
	arr.add(11);
	arr.add(10);
	arr.add(11);
	arr.add(10);
	arr.add(11);
	arr.add(10);
	arr.add(11);
	arr.add(10);
	arr.add(11);
	arr.add(10);

	for (size_t i = 0; i < arr.getNrOfEl(); i++)
	{
		std::cout << i << ": " << arr.getAt(i) << std::endl;
	}

	system("PAUSE");

	return 0;
}
