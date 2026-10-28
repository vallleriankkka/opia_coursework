#include <locale.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	const char* name;
	double X[5];      
	double Q[5];      
	int state;      
} Component;
int measurement(Component c);


int main()
{
	setlocale(LC_CTYPE, "");

	Component qry = { "QRY", {41.9, 47.8, 48.3, 48.8, 49.3}, {0}, 0 };
	Component rpc = { "RPC", {57.4, 55.4, 53.4, 51.4, 54.8}, {0}, 0 };
	Component nic = { "NIC", {30.2, 29.5, 34.1, 33.4, 32.6}, {0}, 0 };

	measurement(qry);
	measurement(rpc);
	measurement(nic);

	return 0;
}


int measurement(Component c)
{
		int run = 0;
		c.state = 0;
		printf("%s:\n", c.name);
		for (int i = 1; i < 5; i++)
		{
			c.Q[i] = c.X[i] - c.X[i - 1];

			if (fabs(c.Q[i]) > 1.0)
			{
				run = run + 1;
				if (run >= 2)
				{
					c.state = 1;
					printf("Q[%d]=%.2f ПРЕДУПРЕЖДЕНИЕ\n", i, c.Q[i]);
				}
				else
					printf("Q[%d]=%.2f норма для двух измерений\n", i, c.Q[i]);
			}
			else
			{
				run = 0;
				printf("Q[%d]=%.2f НОРМА\n", i, c.Q[i]);
			}
		}
		return 0;
}

	

	
