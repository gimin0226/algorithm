#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring> //strcmp 함수가 선언된 헤더 파일
int main(void)
{
	int M;
	scanf("%d", &M);
	char a[10]={'0'};
	int b;
	int m = 0;
	bool s[21] = { false };
	//bool ans[3000000]={false};
	//int i=0;

	while (m != M)
	{
		scanf("%s", a);
		
		if (strcmp(a,"all")!=0 && strcmp(a,"empty")!=0)
			scanf("%d", &b);
		if (strcmp(a,"add")==0) 
//문자열 비교 strcmp(a,b)에서 a>b이면 1출력 a==b이면 0출력 a<b이면 -1출력
		{
			
			if(s[b]==0)
				s[b]=!s[b];
		}
		else if (strcmp(a,"remove")==0)
		{
			if (s[b] == 1)
				s[b]=!s[b];
		}
		else if (strcmp(a,"check")==0)
		{
			printf("%d\n", s[b]);
			//ans[i] = s[b];
			//i++;
		}
		else if (strcmp(a,"toggle")==0)
		{
			s[b]=!s[b];
		}
		else if (strcmp(a,"all")==0)
		{
			for (int i = 0; i < 21; i++)
				s[i] = true;
		}
		else if (strcmp(a,"empty")==0)
		{
			for (int i = 0; i < 21; i++)
				s[i] = false;
		}
		m++;	

	}

	/*for (int j = 0; j < i; j++)
	{
		printf("%d\n", ans[j]);
	}
	*/
	return 0;


}