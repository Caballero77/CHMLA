#include "MainClass.h"

void MOSR::SetU()
{
	float m;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			U[i][j] = 0;
		}
	}
	for (int i = 0; i < Size;i++)
	{
		m = 0;
		for (int k = 0; k < i; k++)
		{
			m += U[k][i] * U[k][i];
		}
		U[i][i] = sqrt(A[i][i] - m);
		for (int j = 1; j < Size; j++)
		{
			if (j > i)
			{
				m = 0;
				for (int k = 0; k < i; k++)
				{
					m += U[k][i] * U[k][j];
				}
				U[i][j] = (A[i][j] - m) / U[i][i];
			}
			if (j < i)
			{
				U[i][j] = 0;
			}
		}
	}
}

void MOSR::SetY()
{
	float m;
	for (int i = 0; i < Size; i++)
	{
		m = 0;
		for (int k = 0; k < i; k++)
		{
			m += Y[k] * U[k][i];
		}
		Y[i] = (B[i] - m) / U[i][i];
	}
}

void MOSR::SetX()
{
	float m = 0;
	for (int i = Size - 1; i >= 0; i--)
	{
		m = 0;
		for (int k = i + 1 ; k < Size; k++)
		{
			m += U[i][k] * X[k];
		}
		X[i] = (Y[i] - m) / U[i][i];
	}
}

void MOSR::ShowResult()
{
	std::cout << "U == " << std::endl;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << U[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Y == ";
	for (int i = 0; i < Size; i++)
	{
		std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << Y[i] << " ";
	}
	std::cout << std::endl << "Result (X) == ";
	for (int i = 0; i < Size; i++)
	{
		std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << X[i] << " ";
	}
	std::cout << std::endl;
}

void MOSR::DoCalculate()
{
	SetU();
	SetY();
	SetX();
}

MOSR::~MOSR()
{
	for (int i = 0; i < Size; i++)
	{
		delete[]U[i];
		delete[]A[i];
	}
	delete[]U;
	delete[]A;
	delete[]Y;
	delete[]X;
	delete[]B;
}

MOSR::MOSR()
{
	Y = new float[Size];
	U = new float*[Size];
	for (int i = 0; i < Size; i++)
	{
		U[i] = new float[Size];
	}
}