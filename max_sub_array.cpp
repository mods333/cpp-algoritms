#include<iostream>

typedef struct subarray{
	int start;
	int end;
	int maxsum;
	int sum;
}subarray;

subarray max_sub_array(int a[], int size)
{
	subarray s;
	s.maxsum = 0;
	s.sum = 0;
	s.start = 0;
	s.end = 0;
	for (int i = 0; i < size; i++)
	{
		s.sum += a[i];
		if (s.sum>0)
		{
			if (s.sum > s.maxsum)
			{
				s.maxsum = s.sum;
				s.end = i;
			}
		}
		else
		{
			s.sum = 0;
			s.start = i;
		}

	}
	return s;

}
void main()
{
	subarray t;
	int a[20];
	int size;
	int i;
	std::cout << "Enter the size of the array : ";
	std::cin >> size;
	std::cout << "Enter the elements of the array";
	for (i = 0; i < size; i++)
		std::cin >> a[i];
	t = max_sub_array(a, size);
	std::cout << "The maximum sub array is :" << std::endl;
	for (i = t.start+1; i < t.end+1; i++)
		std::cout << a[i] << " , ";
	getchar();
	getchar();



}
