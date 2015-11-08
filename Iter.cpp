#include "MainClass.h"

void Iter::setError(float error)
{
	Error = error;
}

void Iter::setMaxIter(int maxIter)
{
	MaxIter = maxIter;
}

void Iter::showCalculate(bool show)
{
	ShowCalculate = show;
}

void Iter::ShowResult()
{
	Alg::ShowResult();
	std::cout << std::endl << "Count fo iterations == " << MaxIter << std::endl;
}

void Iter::Change()
{
	for (int k = 0; k < Size - 1; k++)
	{
		float max = 0;
		int m;
		for (int i = k; i < Size; i++){
			if (max < abs(A[i][k])) { m = i; max = abs(A[i][k]); }
		}
		if(m != k) {
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
	}
}