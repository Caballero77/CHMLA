#include <fstream>
#include <iostream>
#include <iomanip>
#include <thread>

class Alg
{
protected:
	float **A;
	float *B;
	float *X;
	int Size;
	int Precision = 3;
public:
	Alg();
	void SetPrecision(int _Precision);
	virtual void ShowMainData();
	virtual void ShowResult();
	virtual void DoCalculate() = 0;
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

class PPR :public Alg
{
private:
	float* Alpha,*Beta,*a,*b,*c;
	void setAlpBet();
	void setResult();
public:
	PPR();
	~PPR();
	void DoCalculate();
	void ShowMainData();
	void ShowResult();
};

class Iter : public Alg
{
protected:
	float Error = 0.0000000001;
	int MaxIter = 1000000;
	bool ShowCalculate = false;
	void Change();
public:
	virtual void DoCalculate() = 0;
	void ShowResult();
	void setError(float error);
	void setMaxIter(int maxIter);
	void showCalculate(bool show);
}; 

class Yakobi : public Iter
{
public:
	void DoCalculate();
};

class Zeydel : public Iter
{
private:
	bool converge(float *temp_X);
public:
	void DoCalculate();
};
