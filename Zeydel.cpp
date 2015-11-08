#include "MainClass.h"

void Zeydel::DoCalculate()
{
	Change();
	float *temp_X = new float[Size];
	bool b = true;
	int Count = 0;
	for (int i = 0; i < Size; i++)
	{
		X[i] = 0;
	}
	do
	{
		Count++;
		//std::cout << "Work";
		for (int i = 0; i < Size; i++)
		{
			float var = 0;
			for (int j = 0; j < Size; j++)
			{
				if (i != j)
				{
					var += (A[i][j] * X[j]);
				}
			}
			temp_X[i] = X[i];
			X[i] = (B[i] - var) / A[i][i];
		}
		
	} while (converge(temp_X) && (Count <= MaxIter));
	MaxIter = Count;
}

bool Zeydel::converge(float* temp_X)
{
	float buf = 0;
	for (int i = 0; i < Size; i++)
	{
		buf += (X[i] - temp_X[i])*(X[i] - temp_X[i]);
	}
	if (sqrt(buf) < Error)
	{
		return false;
	}
	return true;
}