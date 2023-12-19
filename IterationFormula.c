#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

float iterationFormula(float qp, int n, float x)
{
	return (x * x * x * x * x)/(4 * n * n + 10 * n + 6) * qp;
}

void fail()
{
	printf("\nВы все сломали. В следующий раз вводите корректные значения.");
	exit(1);
}

int main()
{
	system("chcp 1251");
	float eps = 0.0, x = 0.0;
	printf("\nВведите значение точности, большее -1:\t");
	scanf_s("%f", &eps);
	int overflow = 0;
	int n = 1;
	float q1 = 0.0;
	float q2 = 0.0;
	float s = 0.0;

	if (eps <= -1) fail();
	printf_s("\nВведите x:\t");
	scanf_s("%f", &x);
	q1 = iterationFormula(1., n, x);
	s += q1;

	while ((fabs(q1 - q2) > eps) & (overflow == 0))
	{
		q2 = q1;
		n++;
		q1 = iterationFormula(1., n, x);
		if (n % 2 == 0) s += q1;
		else s -= q1;

		if ((s > FLT_MAX) || (q1 > FLT_MAX))
			overflow = 1;
	}
	if (overflow == 0)
		printf("Результат %f был достигнут за %u итераций", s, n - 1);
	else
		printf("\nУказанная точность недостижима, %u итераций\n", n - 1);
	printf("\nРабота выполнена Левицким Павлом, группа 423-2");
}