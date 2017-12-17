#include <stdio.h>  
#define MAX (99)  

int n; //��� ��
float p[MAX + 1];//p��
float q[MAX + 1]; // q��
float weight[MAX + 1][MAX + 1]; // weight  
float cost[MAX + 1][MAX + 1]; // cost 
int root[MAX + 1][MAX + 1]; // root

void optBST()
{
	int i, j, l, r;
	float temp;

	for (i = 1; i <= n + 1; i++)
	{
		//weight �� cost table �ʱ�ȭ
		weight[i][i - 1] = 0;
		cost[i][i - 1] = 0;		
	}
	for (l = 1; l <= n; l++) 
	{
		for (i = 1; i <= n - l + 1; i++)
		{
			j = i + l - 1;
			if (i == j) {
				weight[i][j] = q[j];
			}else{
			weight[i][j] = weight[i][j - 1] +p[j]+ q[j];
			cost[i][j] = 100;
			}
			for (r = i; r <= j; r++)
			{
				temp = cost[i][r-1] + cost[r][j] + weight[i][j];
				if (temp<cost[i][j])
				{
					cost[i][j] = temp;
					root[i][j] = r;
				}
			}
		}
	}
}

void main()
{
	int i, j;
	float flagq = 1.1;
	float flagp = 1.1;
	printf("real ��� n�� ��: ");
	scanf("%d", &n);
	n = n + 1;
	printf("\n");
	p[0] = 0;
	for (i = 2; i <= n; i++)
	{
		printf("p[%d] �� : ",i-1);
		scanf("%f", &p[i]);
		flagp = flagp - p[i];
		if (flagq<0)
		{
			printf("\n p�� �� 1 �ʰ�!");
			flagp = flagp + p[i];
			i--;
		}
	}
	printf("\n");
	for (i = 1; i <= n; i++)
	{
		printf("q[%d] �� : ", i - 1);
		scanf("%f", &q[i]);
		flagq = flagq - q[i];
		if (flagq<0)
		{
			printf("\n q�� �� 1 �ʰ�!");
			flagq = flagq + q[i];
			i--;
		}
	}

	optBST();

	printf("\n weight table\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf(" %.2f ", weight[i][j]);
		}
		printf("\n");
	}

	printf("\n cost table \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf(" %.2f ", cost[i][j]);
		}
		printf("\n");
	}
	
	printf("\n root table \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			int k;
			k = root[i][j]-1;
			if (k < 0)k = 0;
			printf(" %d ", k);
		}
		printf("\n");
	}
}