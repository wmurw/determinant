// -------------------------------------------------------------------------------------
// Функция вычисляет определитель матрицы T размерностью N с помощью миноров и рекурсии
// Миноры не копируются в новые матрицы, а передаются через указатели на исходную матрицу
// Учебный пример для медитации. Для реальных задач используйте метод Гаусса.
double det(double **T, int N)
{
	double det__;
	int sub_j, s;
	double **subT;		// Субматрица (минор) как набор указателей на исходную матрицу
	switch (N)
	{
	case 1:
		return T[0][0];
	case 2:
		return T[0][0] * T[1][1] - T[0][1] * T[1][0];
	default:
		if (N < 1) return nan("1");			// Некорректная матрица - вернуть "не число"
		subT = new double*[N-1];			// Массив указателей на столбцы минора
		det__ = 0;
		s = 1;						// Знак минора
		for (int i = 0; i < N; i++)			// Разложение по первому (нулевому) столбцу
		{
			sub_j = 0;
			for (int j = 0; j < N; j++)		// Заполнение минора указателями на исходные столбцы
				if (i != j)			// исключить i строку
				    subT[sub_j++] = T[j] + 1;	// здесь + 1 исключает первый (нулевой) столбец

			det__ = det__ + s * T[i][0] * det(subT, N-1);
			s = -s;
		};
		delete[] subT;
		return det__;
	};
};
