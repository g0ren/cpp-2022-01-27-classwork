#include <iostream>
using namespace std;

template<typename T>
void swap(T *x, T *y) {
	T t { };
	t = *x;
	*x = *y;
	*y = t;
}

template<typename T>
T* findInArray(T *a, T key, int size) {
	T *ptr { a };
	for (int i = 0; i < size; i++) {
		if (*ptr == key)
			return ptr;
		ptr++;
	}
	return nullptr;
}

void assign101(int *p) {
	*p = 101;
}

int* createArray(int size) {
	int *i = new int[size];
	return i;
}

void initArray(int *i, int size) {
	srand(time(NULL) + size);
	for (int j = 0; j < size; j++) {
		*(i + j) = rand() % 50;
	}
}

void printArray(int *i, int size) {
	for (int j = 0; j < size; j++) {
		cout << *(i + j) << " ";
	}
	cout << endl;
}

void simpleRemove(int *i, int key, int size) {
	int *ptr { };
	ptr = findInArray(i, key, size);
	if (ptr == nullptr)
		return;
	int diff { };
	diff = (int) (ptr - i);
	for (int j = 0; j < (size - diff - 1); j++) {
		*(ptr + j) = *(ptr + j + 1);
	}
	*(i + size - 1) = 0;
}

void RemoveValues(int *array, int *n, int value) {
	for (int i = 0; i < *n; i++) {
		if (array[i] == value) {
			*n -= 1;
			for (int j = i; j < *n; j++) {
				array[j] = array[j + 1];
			}

		}
	}
}

/*
 * Ввести значение 3-х вещественных переменных а и b и с. Направить
 указатели на эти переменные. С помощью указателя увеличить значение переменной с в
 3 раза. Затем поменять местами значения переменных а и с через их указатели.
 */
void operation() {
	double *a = new double { };
	double *b = new double { };
	double *c = new double { };
	cout << "Enter a,b,c" << endl;
	cin >> *a >> *b >> *c;
	*c *= 3;
	swap(a, c);
	cout << *a << ", " << *b << ", " << *c << endl;
	cout << *a + *b + *c << endl;
	delete a;
	delete b;
	delete c;
}

/*
 * Создать динамические массивы, используя указатели. Дано 2 массива х(n) и
 у(m). Сколько раз встречается последний элемент первого массива х(n) во втором
 массиве у(m).
 */
int result(int *x, int *y, int n, int m) {
	int compare { }, sum { };
	compare = *(x + n - 1);
	for (int i = 0; i < m; i++)
		if (*(y + i) == compare)
			sum++;
	return sum;
}

/*
 * Создать динамические массивы, используя указатели. Дано 2 массива х(n) и
 у(m). z(n+m)  =x + y
 */
int* concatenate(int *ar1, int *ar2, int size1, int size2) {
	int *r = new int[size1 + size2] { };
	int *ptr = r;
	for (int i = 0; i < size1; i++) {
		*ptr = *(ar1 + i);
		ptr++;
	}
	for (int i = 0; i < size2; i++) {
		*ptr = *(ar2 + i);
		ptr++;
	}
	return r;
}

int main() {
	//operation();
	int a1 { }, a2 { };
	int *ar1 { }, *ar2 { };
	cout << "Enter array1 size:" << endl;
	cin >> a1;
	cout << "Enter array2 size:" << endl;
	cin >> a2;
	ar1 = createArray(a1);
	initArray(ar1, a1);
	printArray(ar1, a1);

	ar2 = createArray(a2);
	initArray(ar2, a2);
	printArray(ar2, a2);

	//cout << result(ar1, ar2, a1, a2) << endl;
	int *ar3{};
	ar3=concatenate(ar1,ar2,a1,a2);
	printArray(ar3, a1+a2);
	delete[] ar1;
	delete[] ar2;
	delete[] ar3;
	/* cout << "Enter key to delete:" << endl;
	 cin >> key;
	 simpleRemove(ar, key, a);
	 printArray(ar, a);

	 delete[] ar;*/

}
