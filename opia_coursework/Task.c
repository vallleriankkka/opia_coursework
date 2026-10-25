#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

struct tm* mytime;
time_t t;

int time_now(char* buf, struct tm* mytime);


int main()
{
	setlocale(LC_CTYPE, "");

	/*t = time(NULL);
	mytime = localtime(&t);
	char buf1[128];
	printf(time_now(buf1, mytime));*/

}

int time_now(char* buf, struct tm* mytime)
{
	return sprintf(buf, "Время %02d:%02d:%02d", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
}

int measurement()
{
	double L, Q, X;
	int k, D;
	k = 1;
	L = 1.0;
	D = 10;
	
	for (int i = 0; i <= D; i++)
	{
        Q[i] = (X[i] - X[i - k]) / k;
		if (Q > L)
		{
			if (Q > L)
				printf("Предупреждение");

		}
		else
			printf("Норма");

	}
