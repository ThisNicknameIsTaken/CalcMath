#include <iostream>


using namespace std;

class Matrix
{

public:
	Matrix();
	Matrix(size_t sz, float **content);
	~Matrix();
	 
	void setMatrixContentNumberByIndex(int col, int row, float num);
	float **getMatrixContent();

private:
	float discremenant = -999;
	size_t size;
	float **matrixContent;
	Matrix *transponatedMatrix;
	Matrix *reverseMatrix;
	Matrix *algebraicAddition;
	Matrix *transponatedAlgebraicAddition;

	void fillMatrix();
	void showMatrix();
	void showMatrix(Matrix *matrix);

	void transponateMatrix();
	void transponateAlgebraicAddition();
	void transponate(Matrix *matrix);

	void findAlgebraicAddition();

	float findDiscremenant(float **content, int sizeContent);
	float **cutContentForDiscremenant(float **content, int sizeContent, int col, int row = -1);

	void getRevesreMatrix();
	void multiplyOnNum(float num);

	//void reverseMatrix();

	//void multiplyMatrix(Matrix *matrix);
};

int powerNum(int num, int power);