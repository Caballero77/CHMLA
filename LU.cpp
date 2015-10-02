#include "MainClass.h"

void LU::ShowResult()
{
	std::cout << "L ==" << std::endl;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << L[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "U ==" << std::endl;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			std::cout << std::setw(Precision+1) << std::right << std::setprecision(Precision) << U[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Y = ";
	for (int i = 0; i < Size; i++)
	{
		std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << Y[i] << " ";
	}
	std::cout << std::endl << "Result (X) == ";
	for (int i = 0; i < Size; i++)
	{
		std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << X[i] << " ";
	}
}

void LU::SetLU()
{
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
		{
			U[0][i] = A[0][i];
			L[i][0] = A[i][0] / U[0][0];
			float Buf = 0;
			for (int k = 0; k < i; k++) Buf += L[i][k] * U[k][j];
			U[i][j] = A[i][j] - Buf;
			if (i > j) L[j][i] = 0;
			else
			{
				Buf = 0;
				for (int k = 0; k < i; k++) Buf += L[j][k] * U[k][i];
				L[j][i] = (A[j][i] - Buf) / U[i][i];
			}
		}
}

void LU::SetY()
{
	for (int i = 0; i < Size; i++)
	{
		float Buf = 0;
		for (int k = 0; k < i; k++) Buf += L[i][k] * Y[k];
		Y[i] = B[i] - Buf;
	}
}

void LU::SetX()
{
	for (int i = Size - 1; i >= 0; i--)
	{
		float Buf = 0;
		for (int k = i + 1; k < Size; k++) Buf += U[i][k] * X[k];
		X[i] = (Y[i] - Buf) / U[i][i];
	}
}

LU::~LU()
{
	for (int i = 0; i < Size; i++)
	{
		delete[]L[i];
		delete[]U[i];
		delete[]A[i];
	}
	delete[]L;
	delete[]U;
	delete[]A;
	delete[]Y;
	delete[]X;
	delete[]B;
}

void LU::DoCalculate()
{
	L = new float*[Size];
	U = new float*[Size];
	Y = new float[Size];
	for (int i = 0; i < Size; i++)
	{
		L[i] = new float[Size];
		U[i] = new float[Size];
	}
	SetLU();
	SetY();
	SetX();
}