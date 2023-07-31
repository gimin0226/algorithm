#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		char a[100001];
		scanf("%s", a);
		int k = strlen(a);
		char* b = a;
		char* c = &a[k-1];
	
		int num=0;
		
		if (k % 2 == 0)
		{
			while (1)
			{
				if (num == 0)
				{
				
					if (*b == *c)
					{
						b++;
						c--;
					}
					else if (*b != *c)
					{
						

						num++;
						int i = 0;
						int ptr = 0;
						while (1)
						{
							if (*(b + i + 1) != *(c - i))
							{
								break;
							}
							if (b + i + 1 == c - i)
							{
								ptr++;
								break;
							}
							i++;
						}
						if (ptr == 0)
						{
							i = 0;
							while (1)
							{
								if (*(b + i) != *(c - i - 1))
								{
									break;
								}
								if (b + i + 1 == c - i)
								{
									ptr++;
									break;
								}
								i++;
							}
						}
						if (ptr == 1)
						{
							printf("1\n");
							break;
						}
						else
						{
							printf("2\n");
							break;
						}
					}
					if (b -1 == c)
					{
						printf("0\n");
						break;
					}
				}
			}
		}
		
		else if (k % 2 == 1)
		{
			while (1)
			{
				if (num == 0)
				{

					if (*b == *c)
					{
						b++;
						c--;
					}
					else if (*b != *c)
					{


						num++;
						int i = 0;
						int ptr = 0;
						while (1)
						{
							if (*(b + i + 1) != *(c - i))
							{
								break;
							}
							if (b + i+2 == c - i)
							{
								ptr++;
								break;
							}
							i++;
						}
						if (ptr == 0)
						{
							
							i = 0;
							while (1)
							{
								if (*(b + i) != *(c - i - 1))
								{
							
									break;
								}
								if (b + i +2 == c - i)
								{
									
									ptr++;
									break;
								}
								i++;
							}
						}
						if (ptr == 1)
						{
							printf("1\n");
							break;
						}
						else
						{
							printf("2\n");
							break;
						}
					}
				
					if (b == c)
					{
						printf("0\n");
						break;
					}
				}
			
			}
		}
	}
	return 0;
}