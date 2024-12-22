/********************************************************
This code is an example to demonstrate the typedef usage with structure
*********************************************************/

# include <stdio.h>

typedef struct Point{    // Typedef structure Point with variable Point_t
	int x;
	int y;
}Point_t;

struct Pt{          // Structure Pt 
	int x;
	int y;
};

int main()
{
	Point_t p1;
	p1.x = 50;
	p1.y = 60;
	printf("%d \n",p1.x);
	printf("%d \n",p1.y);

  struct Pt p2;
	p2.x = 50;
	p2.y = 60;
	printf("%d \n",p2.x);
	printf("%d \n",p2.y);

	return 0;
}


