#include <locale.h>
#include <stdio.h>
#include <math.h>

int measurement(const char* name);


int main()
{
	setlocale(LC_ALL, ".utf-8");

	measurement("QRY");
	measurement("RPC");
	measurement("NIC");

	return 0;
}


int measurement(const char* name)
{
		int run = 0;
		double pastX, Q;

		printf("%s:\n", name);

		printf("X[0] = ");
		scanf("%lf", &pastX);

		for (int i = 1; i < 5; i++)
		{
			double x;
			printf("X[%d] = ", i);
			scanf("%lf", &x);

			Q = x - pastX;
			pastX = x;

			if (fabs(Q) > 1.0)
			{
				run = run + 1;
				if (run >= 2)
				{
					printf("Q[%d]=%.2f ПРЕДУПРЕЖДЕНИЕ\n", i, Q);
				}
				else
					printf("Q[%d]=%.2f норма для двух измерений\n", i, Q);
			}
			else
			{
				run = 0;
				printf("Q[%d]=%.2f НОРМА\n", i, Q);
			}
		}
		return 0;
}

	

	
