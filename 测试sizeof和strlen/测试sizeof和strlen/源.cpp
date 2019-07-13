#include<iostream>
#include<stdio.h>
#include<string.h>

int main()
{
	//char a[] = "abcdef";//自动接/0
	//char b[] = { 'a','b','c','d','e','f','\0' };//手动接/0
	//const char *c = "abcdef";
	//printf("%s\n", a);
	//printf("%s\n", b);
	//printf("%s\n", c);

	//printf("sizeof(a) = %d，7\n", sizeof(a));
	//printf("sizeof(b) = %d，7\n", sizeof(b));
	//printf("sizeof(c) = %d，4\n", sizeof(c));
	//printf("strlen(a) = %d，6\n", strlen(a));
	//printf("strlen(b) = %d，6\n", strlen(b));
	//printf("strlen(c) = %d，6\n", strlen(c));
	float x = -2.3E-1;
	int y = 2e5;
	int z = 2e6;
	printf("2e3 = %d\n", (int)(2e3));
	printf("-2.3E-1 = %f\n", x);
	system("pause");
	return 0;
}