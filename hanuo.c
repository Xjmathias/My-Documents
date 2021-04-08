#include <stdio.h>

void hanio(int n,char s,char t,char d)
{
	if(1==n)
	{
		printf("1 from %c to %c\n",s,d);
		return;
	}
	hanio(n-1,s,d,t);
	printf("n-1 from %c to %c\n",n-1,s,t);
	hanio(n-1,t,s,d);

}
int main(int argc,const char* argv[])
{
	hanio(8,'A','B','C');
}
