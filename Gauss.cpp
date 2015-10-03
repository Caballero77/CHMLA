#include "MainClass.h"

GaussAlg::~GaussAlg()
{
	for (int i = 0; i < Size; i++)
	{
		delete[]A[i];
		delete[]Inverse[i];
	}
	delete[]X;
	delete[]B;
	delete[]A;
	delete[]Inverse;
}

GaussAlg::GaussAlg()
{
	Inverse = new float*[Size];
	for (int i = 0; i < Size; i++)
	{
		Inverse[i] = new float[Size];
	}
}

void GaussAlg::DoCalculate()
{
	bool v = true;
	float* x, ** M, *b,** CloneA;
	x = new float[Size];
	M = new float*[Size];
	b = new float[Size];
	CloneA = new float*[Size];
	for (int i = 0; i < Size; i++)
	{
		CloneA[i] = new float[Size];
		Inverse[i] = new float[Size];
		M[i] = new float[Size];
	}
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			CloneA[i][j] = A[i][j];
		}
	}
	for (int n = 0; n < Size; n++){
		for (int k = 0; k < Size; k++){
			b[k] = 0;
			x[k] = 0;
		}
		b[n] = 1;
		for (int k = 0; k < Size - 1; k++){
			float max = 0;
			int m;
			for (int i = k; i < Size; i++){
				if (max < abs(A[i][k])) { m = i; max = abs(A[i][k]); }
			}
			if (max == 0) { std::cout << "WTF !? " << k << std::endl; system("Pause"); }
			else {
				if (v && (k != m)) Key++;
				float c;
				c = b[k];
				b[k] = b[m];
				b[m] = c;
				for (int j = k; j < Size; j++){
					c = A[k][j];
					A[k][j] = A[m][j];
					A[m][j] = c;
				}
			}
			for (int i = k + 1; i < Size; i++){
				M[i][k] = -(A[i][k] / A[k][k]);
				b[i] = b[i] + M[i][k] * b[k];
				for (int j = k + 1; j < Size; j++)
					A[i][j] = A[i][j] + M[i][k] * A[k][j];
			}
		}
		x[Size - 1] = b[Size - 1] / A[Size - 1][Size - 1];
		for (int k = Size - 2; k >= 0; k--){
			float m = 0;
			for (int j = k + 1; j < Size; j++) m += A[k][j] * x[j];
			x[k] = (b[k] - m) / A[k][k];
		}
		for (int g = 0; g < Size; g++)
			Inverse[g][n] = x[g];
		v = false;
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				A[i][j] = CloneA[i][j];
			}
		}
	}
	Key = float(pow(-1, Key));
	for (int i = 0; i < Size; i++) Key *= A[i][i];
	for (int k = 0; k < Size - 1; k++){
		float max = 0;
		int m;
		for (int i = k; i < Size; i++){
			if (max < abs(A[i][k])) { m = i; max = abs(A[i][k]); }
		}
		if (max == 0) { std::cout << "WTF !? " << k << std::endl; system("Pause"); }
		else {
			float c;
			c = B[k];
			B[k] = B[m];
			B[m] = c;
			for (int j = k; j < Size; j++){
				c = A[k][j];
				A[k][j] = A[m][j];
				A[m][j] = c;
			}
		}
		for (int i = k + 1; i < Size; i++){
			M[i][k] = -(A[i][k] / A[k][k]);
			B[i] = B[i] + M[i][k] * B[k];
			for (int j = k + 1; j < Size; j++)
				A[i][j] = A[i][j] + M[i][k] * A[k][j];
		}
	}
	X[Size - 1] = B[Size - 1] / A[Size - 1][Size - 1];
	for (int k = Size - 2; k >= 0; k--){
		float m = 0;
		for (int j = k + 1; j < Size; j++) m += A[k][j] * X[j];
		X[k] = (B[k] - m) / A[k][k];
	}
	delete[]x;
	delete[]b;
	for (int i = 0; i < Size; i++)
	{
		delete[]M[i];
		delete[]CloneA[i];

	}
}

void GaussAlg::ShowResult()
{
	std::cout << "Inverse " << std::endl;
	for (int i = 0; i < Size;i++)
	{
		for (int j = 0; j < Size; j++)
		{
			std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << Inverse[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Key of matrix == " << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << Key << std::endl;
	Alg::ShowResult();
}