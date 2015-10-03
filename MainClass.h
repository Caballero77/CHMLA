#include <fstream>
#include <iostream>
#include <iomanip>

class Alg
{
protected:
	float **A;
	float *B;
	float *X;
	int Size;
	int Precision = 5;
public:
	Alg();
	void SetPrecision(int _Precision);
	void ShowMainData();
	void ShowResult();
};

class LU :public Alg
{
private:
	float** L, ** U, *Y;
	void SetLU();
	void SetY();
	void SetX();
public:
	LU();
	~LU();
	void DoCalculate();
	void ShowResult();
};

class GaussAlg :public Alg
{
private:
	float** Inverse;
	float Key;

public:
	GaussAlg();
	~GaussAlg();
	void DoCalculate();
	void ShowResult();
};

class MOSR :public Alg //MOSR - method of square roots
{
private:
	float **U, *Y;
	void SetU();
	void SetY();
	void SetX();
public:
	MOSR();
	~MOSR();
	void DoCalculate();
	void ShowResult();
};