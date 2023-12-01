﻿#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

int factorial(float value)
{
    if (value == 0)
        return 1;
    else
        return value * factorial(value - 1);
}

float iterationFormula(float n, float x)
{
	float firstExponent = n + 1;
	float secondExponent = 2 * n + 1;
	float thirdExponent = 4 * n + 2;
	return (pow(-1, firstExponent) / factorial(secondExponent)) * (pow(x, thirdExponent) / n);
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
	float q1, q2 = 0.0;
	float s = 0;

	if (eps <= -1 ) fail();
	printf_s("\nВведите x:\t");
	scanf_s("%f", &x);
	q1 = iterationFormula(n, x);
	s += q1;

	while ((fabs(q1 - q2) > eps) & (overflow == 0))
	{
		q2 = q1;
		n++;
		q1 = iterationFormula(n, x);
		if (n % 2 == 0) s += q1;
		else s -= q1;

		if ((s > FLT_MAX) || (q1 > FLT_MAX))
			overflow = 1;
	}
	if (overflow == 0)
		printf("%f, %u", s, n);
	else
		printf("\nУказанная точность недостижима, %u\n", n);
	printf("Работа выполнена Левицким Павлом, группа 423-2");
}