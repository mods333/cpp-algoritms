#include<iostream>
 
typedef struct{
	int peakr;
	int peakc;
}position;


position find_peak(int a[10][10], int r, int c1, int c2)
{
	position p;

	int kr = r / 2;
	p.peakc= (c1 + c2) / 2;
	
	p.peakr = 0;
	for (int i = 0; i < r; i++)
	if (a[p.peakr ][p.peakc] < a[i][p.peakc])
		p.peakr = i;
	if (a[p.peakr][p.peakc] > a[p.peakr][p.peakc + 1] && a[p.peakr][p.peakc] > a[p.peakr][p.peakc - 1])
		return p;
	else if (a[p.peakr][p.peakc] < a[p.peakr][p.peakc - 1])
		return find_peak(a, r, c1, p.peakc);
	else if (a[p.peakr][p.peakc] < a[p.peakr][p.peakc + 1])
		return find_peak(a, r, p.peakc, c2);

		
}
void main()
{
	int a [10][10], r, c;
	int i, j;
	
	position s;
	std::cout << "Enter the number of rows and columns :  ";
	std::cin >> r >> c; 
	std::cout << "Enter the elements of the array" << std::endl;

	for (i = 0; i < r;i++ )
	for (j = 0; j < c; j++)
		std::cin >> a[i][j];

	s = find_peak(a, r, 0, c);
	std::cout << "The position is given by (" << s.peakr << "," << s.peakc << ")";
	getchar();
	getchar();

	

}
