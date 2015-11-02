#include "MainClass.h"

Alg::Alg()
{
	std::cout << "Input name of file with matrix :" << std::endl;
	char NameOfFile[20];
	std::cin >> NameOfFile;
	std::fstream File;
	File.open(NameOfFile);
	Size = 0;
	char buf[20];
	while (!File.eof())
	{
		File.getline(buf, 2014, '\n');
		Size++;
	}
	File.seekg(0);
	A = new float*[Size];
	B = new float[Size];
	X = new float[Size];
	for (int i = 0; i < Size; i++)
	{
		A[i] = new float[Size];
	}
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size + 1; j++)
		{
			if (j != Size)
			{
				File >> A[i][j];
			}
			else
			{
				File >> B[i];
			}
		}
	}
	File.close();
	SetPrecision(Precision);
}

void Alg::ShowMainData()
{
	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size; j++)
			std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << A[i][j] << " ";
		std::cout << std::setw(Precision + 1) << std::right << B[i] << std::endl;
	}
}

void Alg::ShowResult()
{
	std::cout << "Result == ";
	for (int i = 0; i < Size; i++)
		std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision) << X[i] << " ";
}

void Alg::SetPrecision(int _Precision)
{
	Precision = _Precision;
	std::cout << std::setw(Precision + 1) << std::right << std::setprecision(Precision);
}