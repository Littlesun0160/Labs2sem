#include <iostream>

template <typename Type, int rows, int columns>
class Matrix
{
private:
	Type m_Matrix[rows][columns] = {};
public:
	Matrix() {}
	//конструктор копирования
	Matrix(const Matrix& other)
	{
		for (int i = 0; i < rows;i++)
		{
			for (int j = 0; j < columns; j++)
			{
				(*this).m_Matrix[i][j] = other.m_Matrix[i][j];
			}
		}
	}
	//оператор присваивания копированием
	Matrix& operator=(const Matrix& other)
	{
		if ((*this).m_Matrix != other.m_Matrix)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					(*this).m_Matrix[i][j] = other.m_Matrix[i][j];
				}
			}
		}
		return (*this);
	}
	~Matrix() {};

	//операторы ввода и вывода
	friend std::istream& operator>>(std::istream& in, Matrix& other)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				in >> other.m_Matrix[i][j];
			}
		}
		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, const Matrix& other)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				out << other.m_Matrix[i][j] << " ";
			}
			out << "\n";
		}
		return out;
	}

	//операторы +, +=
	Matrix& operator+= (const Matrix& other)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				(* this).m_Matrix[i][j] += other.m_Matrix[i][j];
			}
		}
		return (*this);
	}
	Matrix operator+(const Matrix& other)
	{
		Matrix intermediate = *this;
		intermediate += other;
		return intermediate;
	}

	//оператор для получения и изменения элемента по индексу
	Type& operator() (int nrow, int ncolumn)
	{
		return (*this).m_Matrix[nrow][ncolumn];
	}

	//операторы * и *=
	template <int newcolumns>
	Matrix<Type,rows,newcolumns> operator*(Matrix<Type,columns,newcolumns>& other)
	{
		Matrix<Type, rows, newcolumns> result;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < newcolumns; j++)
			{
				for (int k = 0; k < columns; k++)
				{
					result(i,j) += (*this).m_Matrix[i][k] * other(k, j);
				}
			}
		}
		return result;
	}
	Matrix<Type,rows,rows>& operator*=(Matrix<Type,rows,rows>& other)
	{
			(*this) = (*this) * other;
			return (*this);
	}

	//оператор++
	Matrix<Type, rows, columns>& operator++ ()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				(*this).m_Matrix[i][j]++;
			}
		}
		return (*this);
	}

	//Вычисление определителя
	Type Determinant()
	{
		if (rows == columns)
		{
			if (rows == 1)
			{
				return (*this).m_Matrix[0][0];
			}
			if constexpr (rows == 2)
			{
				Type intermediate = (m_Matrix[0][0] * m_Matrix[1][1]) - (m_Matrix[0][1] * m_Matrix[1][0]);
				return intermediate;
			}
			if constexpr (rows == 3)
			{
				Type intermediate = (m_Matrix[0][0] * m_Matrix[1][1] * m_Matrix[2][2] + m_Matrix[0][2] * m_Matrix[1][0]
					* m_Matrix[2][1] + m_Matrix[0][1] * m_Matrix[1][2] * m_Matrix[2][0] - m_Matrix[0][2] * m_Matrix[1][1]
					* m_Matrix[2][0] - m_Matrix[0][0] * m_Matrix[1][2] * m_Matrix[2][1] - m_Matrix[0][1] * m_Matrix[1][0]
					* m_Matrix[2][2]);
				return intermediate;
			}
		}
	}
};


int main()
{
	setlocale(LC_ALL, "rus");

	Matrix<int, 2, 2> matr1;
	std::cin >> matr1;
	std::cout << "Матрица1:" << "\n" << matr1;
	Matrix<int, 2, 2> matr2(matr1);
	std::cout << "Матрица2, заданная конструктором копирования:" << "\n" << matr2;
	Matrix<int, 2, 2> matr3 = matr1;
	std::cout << "Матрица3, заданная оператором присваивания копированием:" << "\n" << matr3;

	//Проверка операторов +, +=, *, *=
	matr3 += matr1; std::cout << "Матрица3 += Матрица1:" << "\n" << matr3;
	matr2 = matr1 + matr3; std::cout << "Матрица2 = Матрица1 + Матрица3:" << "\n" << matr2;

	Matrix<int, 2, 3> matr4;
	std::cin >> matr4;
	Matrix<int, 2, 3> result = matr2 * matr4;
	std::cout << "Матрица2 * Матрица4:" << "\n" << result;
	
	matr3 *= matr1; std::cout << "Матрица3, умноженная на Матрицу1:" << "\n" << matr3;

	//Оператор++, определитель, оператор вызова определенного элемента матрицы
	++matr3;
	std::cout << "++matr3:" << "\n" << matr3;
	std::cout << "Определитель матрицы1 = " << matr1.Determinant() << "\n";
	std::cout << "matr1[1][1] = " << matr1(1, 1) << "\n";
	matr1(1, 1) = 2; std::cout << matr1(1, 1);

}
