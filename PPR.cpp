#include "MainClass.h"

void PPR::DoCalculate()
{
	std::cout << Size;
	setAlpBet();
	setResult();
}

void PPR::setAlpBet()
{
	Alpha[0] = (-1) * A[0][1];
	Beta[0] = B[0];
	for (int i = 0; i < Size - 2; i++)
	{
		float r = c[i] - Alpha[i] * a[i];
		Alpha[i + 1] = b[i] / r;
		Beta[i + 1] = (a[i] * Beta[i] - B[i + 1]) / r;
	}
}

void PPR::setResult()
{
	X[Size - 1] = (B[Size - 1] - A[Size - 1][Size - 2] * Beta[Size - 1]) / (1 + A[Size - 1][Size - 2] * Alpha[Size - 1]);
	for (int i = Size - 2; i >= 0; i--)
	{
		X[i] = Alpha[i] * X[i + 1] + Beta[i];
	}
}

PPR::PPR()
{
	Alpha = new float[Size];
	Beta = new float[Size];
	a = new float[Size - 2];
	b = new float[Size - 2];
	c = new float[Size - 2];
	for (int i = 1; i < Size - 1; i++)
	{
		a[i - 1] = A[i][i - 1];
		b[i - 1] = A[i][i + 1];
		c[i - 1] = -A[i][i];
	}
}

PPR::~PPR()
{
	delete[]a;
	delete[]b;
	delete[]c;
	delete[]Alpha;
	delete[]Beta;
}

void PPR::ShowMainData()
{
	Alg::ShowMainData();
	std::cout << "A = ";
	for (int i = 0; i < Size - 2; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl << "B = ";
	for (int i = 0; i < Size - 2; i++)
	{
		std::cout << b[i] << " ";
	}
	std::cout << std::endl << "C = ";
	for (int i = 0; i < Size - 2; i++)
	{
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;
}

void PPR::ShowResult()
{
	std::cout << "Alpha = ";
	for (int i = 0; i < Size -1 ; i++)
	{
		std::cout << Alpha[i] << " ";
	}
	std::cout << std::endl << "Beta  =  ";
	for (int i = 0; i < Size - 1 ; i++)
	{
		std::cout << Beta[i] << " ";
	}
	std::cout << std::endl;
	Alg::ShowResult();
}