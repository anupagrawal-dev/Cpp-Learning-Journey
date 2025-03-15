#include "Main.h"

void Function()
{
	static int i=0;
	i++;
	cout<<"i = "<<i<<endl;
}

int main()
{
	for(int i=0;i<5; i++)
		Function();
}
