#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	char a[10][9];
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);
	int b[10];
	for (int i = 0; i < n; i++)
		b[i] = strlen(a[i]);

	char c[10][9];
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		int t = 0;
		for (int j = 0; j < 8 - b[i]; j++)
		{
			c[i][j] = ' ';
			k = j;
		}
		if (b[i] != 8)
			k++;

		for (int j = k; j < 8; j++)
		{
			c[i][j] = a[i][t];
			t++;
		}
	}
	/*
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%c", c[i][j]);
		}
		printf("\n");
	}
	*/
	
	int e[8][26] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		int d[26] = { 0 };
		for (int j = 0; j < 26; j++)
		{
			if (c[j][i] == 'A')d[0]++;	else if (c[j][i] == 'B')d[1]++; else if (c[j][i] == 'C')d[2]++;
			else if (c[j][i] == 'D')d[3]++;	else if (c[j][i] == 'E')d[4]++; else if (c[j][i] == 'F')d[5]++;
			else if (c[j][i] == 'G')d[6]++; else if (c[j][i] == 'H')d[7]++; else if (c[j][i] == 'I')d[8]++;
			else if (c[j][i] == 'J')d[9]++; else if (c[j][i] == 'K')d[10]++; else if (c[j][i] == 'L')d[11]++;
			else if (c[j][i] == 'M')d[12]++; else if (c[j][i] == 'N')d[13]++; else if (c[j][i] == 'O')d[14]++;
			else if (c[j][i] == 'P')d[15]++; else if (c[j][i] == 'Q')d[16]++; else if (c[j][i] == 'R')d[17]++;
			else if (c[j][i] == 'S')d[18]++; else if (c[j][i] == 'T')d[19]++; else if (c[j][i] == 'U')d[20]++;
			else if (c[j][i] == 'V')d[21]++; else if (c[j][i] == 'W')d[22]++; else if (c[j][i] == 'X')d[23]++; 
			else if (c[j][i] == 'Y')d[24]++; else if (c[j][i] == 'Z')d[25]++;


		}
		for (int j = 0; j < 26; j++)
			e[i][j] = d[j];
	}
	/*
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", e[i][j]);
		}
		printf("\n");
	}
	*/
	int f[26]={0};
	int min = 10;
	
	for (int v = 0; v < 8; v++)
	{
		int pin = 0;
		int pin2 = 0;
		for (int i = 0; i < 26; i++)
		{
			if (e[v][i] > 0)
			{
				
				f[i] = min-1;
				for (int k = 0; k < 26; k++)
				{
					if (e[v + 1][k] == 10 && e[v][i] == 1 && e[v + 1][i] == 0)
					{
						for (int j = v + 2; j < 8; j++)
						{
							if (e[j][i] > e[j][k])
							{
								break;
							}
							else if (e[j][i] < e[j][k])
							{
								pin++;
								pin2 = k;
								
								break;
							}
						}
					}
				}
				for (int k = 0; k < 26; k++)
				{
					if (k == i)
						continue;
					if (e[v][i] < e[v][k])
					{
						f[i]--;
					}
					else if (e[v][i] == e[v][k])
					{
						for (int j = 0; j < 8; j++)
						{
							if (e[j][i] > e[j][k])
							{
								break;
							}
							else if (e[j][i] < e[j][k])
							{
								f[i]--;
								break;
							}
						
						}
					}
				}

				if (pin == 1)
				{
					f[i]--;
					f[pin2] = f[i] + 1;
				}
			}

		}
		if (pin == 1)
		{
			for (int j = 0; j < 8; j++)
				e[j][pin2] = 0;
			
		}
		for (int i = 0; i < 26; i++)
		{
			if (f[i] != 0)
			{
				for (int j = 0; j < 8; j++)
					e[j][i] = 0;
			}
		}
		for (int i = 0; i < 25; i++)
		{
			int x = 0;
			for (int j = i+1; j <26; j++)
			{
				if (f[i]!=0 && f[i] == f[j])
				{
					x++;
					
				}
			}
			for (int j = 0; j < x; j++)
				f[i]--;
		}
		
		for (int i = 0; i < 26; i++)
		{
			if (f[i] < min && f[i] != 0)
			{
				min = f[i];
			}
		}
	}
	/*
	for (int i = 0; i < 26; i++)
		printf("%d ", f[i]);
	printf("\n");
	*/
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < b[i]; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	*/
		int sum[26] = {0};
	for (int i = 0; i < n; i++)
	{
		int p = 1;
		for (int j = 0; j < b[i]; j++)
		{
			p = 1;
			for (int k = 0; k < j; k++)
			{
				p *= 10;
			}
			
			if (a[i][b[i] - j-1] == 'A')	p *= f[0]; else	if (a[i][b[i] - j-1] == 'B')p *= f[1]; else	if (a[i][b[i] - j-1] == 'C')p *= f[2];
			else if (a[i][b[i] - j-1] == 'D')p *= f[3]; else if (a[i][b[i] - j-1] == 'E')p *= f[4]; else	if (a[i][b[i] - j-1] == 'F')p *= f[5];
			else if (a[i][b[i] - j-1] == 'G')p *= f[6]; else if (a[i][b[i] - j-1] == 'H')p *= f[7]; else	if (a[i][b[i] - j-1] == 'I')p *= f[8];
			else if (a[i][b[i] - j-1] == 'J')p *= f[9]; else if (a[i][b[i] - j - 1] == 'K')p *= f[10]; else if (a[i][b[i] - j - 1] == 'L')p *= f[11];
			else if (a[i][b[i] - j - 1] == 'M')p *= f[12]; else if (a[i][b[i] - j - 1] == 'N')p *= f[13]; else if (a[i][b[i] - j - 1] == 'O')p *= f[14];
			else if (a[i][b[i] - j - 1] == 'P')p *= f[15]; else if (a[i][b[i] - j - 1] == 'Q')p *= f[16]; else if (a[i][b[i] - j - 1] == 'R')p *= f[17];
			else if (a[i][b[i] - j - 1] == 'S')p *= f[18]; else if (a[i][b[i] - j - 1] == 'T')p *= f[19]; else if (a[i][b[i] - j - 1] == 'U')p *= f[20];
			else if (a[i][b[i] - j - 1] == 'V')p *= f[21]; else if (a[i][b[i] - j - 1] == 'W')p *= f[22]; else if (a[i][b[i] - j - 1] == 'X')p *= f[23];
			else if (a[i][b[i] - j - 1] == 'Y')p *= f[24]; else if (a[i][b[i] - j - 1] == 'Z')p *= f[25];
			sum[i] += p;
		}

		
	}
	/*
	for (int i = 0; i < n; i++)
		printf("%d\n", sum[i]);
		*/
	int sum2 = 0;
	for (int i = 0; i < n; i++)
		sum2 += sum[i];

	printf("%d", sum2);

	return 0;
}