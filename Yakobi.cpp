#include "MainClass.h"

void Yakobi::DoCalculate()
{
	Change();
	int Count = 0;
	float* temp_X = new float[Size], error;
	do
	{
		error = 0;
		for (int i = 0; i < Size; i++){
			temp_X[i] = B[i];
		}
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				if (i != j)
				{
					temp_X[i] -= A[i][j] * X[j];
				}
			}
			float x = temp_X[i] / A[i][i];
			float e = fabs(X[i] - x);
			X[i] = x;
			if (e > error)
			{
				error = e;
			}
		}
		Count++;
	} while ((error > Error) && (Count <= MaxIter));
	MaxIter = Count;
}
