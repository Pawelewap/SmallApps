#include <stdio.h>

int main(int argc, char *argv[])
{
	int s = 0;
	int i = 0;
	printf("Podaj ilosc liczb do obliczenia: ");
	scanf_s("%d", &s);
	int *n = malloc(s * sizeof(int));
	

	for (i = 0; i < s; i++)
	{

		if (i == 0 || i == 1)
		{
			n[i] = 1;
			printf("\n%d", n[i]);
		}

		else
		{
			n[i] = n[i - 1] + n[i - 2];
			printf("\n%d", n[i]);
		}
	}
	printf("\n");
	return 0;
}
