#include "RevMatrix.h"

Matrix::Matrix()
{
	cout << "Input matrix size \n";
	cin >> size;

	if (size <= 0) {
		cout << "Wrong size \n";
		return;
	}


	matrixContent = new float *[size];

	for (int i = 0; i < size; i++)
	{
		matrixContent[i] = new float[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrixContent[i][j] = 0;
			cout << "[" << matrixContent[i][j] << "]";
		}
		cout << "\n";
	}

	fillMatrix();
	showMatrix();
	transponateMatrix();

	discremenant = findDiscremenant(matrixContent, size);
	cout << "\n" << "Discremenant" << "\n" << discremenant << '\n';

	if (discremenant == 0) {
		cout << "No reverse matrix! \n";
		return;
	}

	findAlgebraicAddition();

	cout << "\n" << "Algebraic Addition \n";
	algebraicAddition->showMatrix();

	cout << "\n" << "Transponated Algebraic Addition \n";
	transponateAlgebraicAddition();

	getRevesreMatrix();
	cout << "\n Reverse Matrix \n";
	showMatrix(reverseMatrix);
}

Matrix::Matrix(size_t sz, float ** content) {
	size = sz;
	
	matrixContent = new float * [size];



	for (int i = 0; i < size; i++)
	{
		matrixContent[i] = new float[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			setMatrixContentNumberByIndex(i, j, content[i][j]);
		}
	}
}

Matrix::~Matrix()
{

	for (int i = 0; i < size; i++) {
		delete[] matrixContent[i];
	}
	delete[] matrixContent;
}

void Matrix::showMatrix() {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "[" << matrixContent[i][j] << "]";
		}
		cout << "\n";
	}
}


void Matrix::showMatrix(Matrix *matrix) {
	for (int i = 0; i < matrix->size; i++)
	{
		for (int j = 0; j < matrix->size; j++)
		{
			cout << "[" << matrix->matrixContent[i][j] << "]";
		}
		cout << "\n";
	}
}

void Matrix::fillMatrix() {

	float num;

	cout << "Input numbers \n";

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> num;
				setMatrixContentNumberByIndex(i, j, num);

			}
			cout << "\n";
		}
}

void Matrix::setMatrixContentNumberByIndex(int col, int row, float num) {
	if (col < 0 || col >= size || row < 0 || row >= size) {
		cout << "Wrong column or row \n";
		return;
	}

	matrixContent[col][row] = num;
}

void Matrix::transponateAlgebraicAddition() {
	Matrix *transponated = new Matrix(size, algebraicAddition->getMatrixContent());
	transponatedAlgebraicAddition = transponated;

	transponate(transponatedAlgebraicAddition);

	cout << "\n Transponated Algebraic Addition \n";
	showMatrix(transponatedAlgebraicAddition);
}


void Matrix::transponateMatrix() {
	Matrix *transponated = new Matrix(size, matrixContent);
	transponatedMatrix = transponated;

	transponate(transponatedMatrix);

	cout << "\n Transponated matrix \n";
	showMatrix(transponatedMatrix);
}

void Matrix::transponate(Matrix *matrix) {
	float temp = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			temp = matrix->matrixContent[j][i];
			matrix->matrixContent[j][i] = matrix->matrixContent[i][j];
			matrix->matrixContent[i][j] = temp;
		}
	}

}

float Matrix::findDiscremenant(float ** content, int sizeContent) {
	if (sizeContent < 0) {
		cout << "Error, sizeContent < 0 \n";
		return -1;
	}
	
	if (sizeContent == 1) {
		return content[0][0];
	}

	float discremenant = 0;

	for (int i = 0; i < sizeContent; i++)
	{
		discremenant += content[0][i] * powerNum(-1, i) * findDiscremenant(cutContentForDiscremenant(content ,sizeContent, i, 0), sizeContent - 1);
	}

	return discremenant;
}

float **Matrix::cutContentForDiscremenant(float **content, int sizeContent, int col, int row) {
	float **newContent = new float *[sizeContent - 1];


	for (int i = 0; i < sizeContent - 1; i++)
	{
		newContent[i] = new float[size];
	}

	int counterJ = 0;
	int counterI = 0;

	bool used = false;

	for (int i = 0; i < sizeContent; i++)
	{
		if (row != sizeContent-1 && i == row) {
			i++;
		}
		

		for (int j = 0; j < sizeContent; j++)
		{
			if (j == col)j++;

			if (counterI >= sizeContent - 1) {
				return newContent;
			}

			newContent[counterI][counterJ] = content[i][j];
			counterJ++;

			

		}
		counterJ = 0;

	
			counterI++;
	}
	return newContent;
}


void Matrix::findAlgebraicAddition() {
	Matrix *algebraicAdditionTemp = new Matrix(size , matrixContent);
	algebraicAddition = algebraicAdditionTemp;


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			algebraicAddition->setMatrixContentNumberByIndex(i,j, findDiscremenant(cutContentForDiscremenant(getMatrixContent(),size, j ,i), size - 1) * powerNum(-1, i+j));
		}
	}

}

void Matrix::getRevesreMatrix() {
	Matrix *revMatrixTemp = new Matrix(size, transponatedAlgebraicAddition->getMatrixContent());

	reverseMatrix = revMatrixTemp;

	if (discremenant == 0) {
		cout << "Error, discremenant == 0 \n";
		return;
	}

	float oneDivideDiscrem = 1 / discremenant;
	reverseMatrix->multiplyOnNum(oneDivideDiscrem);
}


void Matrix::multiplyOnNum(float num) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			matrixContent[i][j] = num * matrixContent[i][j];
		}
	}
}

float **Matrix::getMatrixContent() {
	return matrixContent;
}




int powerNum(int num, int power) {
	if (power == 0) {
		return 1;
	}

	int res = num;

	for (int i = 1; i < power; i++)
	{
		res *= num;
	}

	return res;
}

