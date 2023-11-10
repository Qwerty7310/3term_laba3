#include "fun.h"

//Генерация произвольного числа в заданном диапазоне
int get_random_number(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(min, max);
    return (int)dist(mt);
}

//Генерация произвольного массива
void random_sequence(int n, int *array) {
    for (int i = 0; i < n; i++)
    {
        array[i] = get_random_number(0, 50);
    }
}
void random_sequence(int n, int *array1, int *array2) {
    for (int i = 0; i < n; i++)
    {
        array1[i] = get_random_number(0, 50);
        array2[i] = array1[i];
    }
}

//Генерация возрастающего массива
void ascending_sequence(int n, int *array) {
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
}
void ascending_sequence(int n, int *array1, int *array2) {
    for (int i = 0; i < n; i++) {
        array1[i] = i;
        array2[i] = array1[i];
    }
}

//Генерация убывающего массива
void descending_sequence(int n, int *array) {
    for (int i = 0; i < n; i++) {
        array[i] = n - i;
    }
}
void descending_sequence(int n, int *array1, int *array2) {
    for (int i = 0; i < n; i++) {
        array1[i] = n - i;
        array2[i] = array1[i];
    }
}


//Сортировка выбором с выводом на экран
void selection_sort(int n, int *array, int &p, int &c, bool flag)
{
    p = 0; //число перестановок
    c = 0; //число сравнений
    int i;
    if (flag)
    {
        cout << "Начало:\t";
        print_array(n, array);
    }
        for (i = 0; i < n - 1; i++)
    {

        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[smallest])
            {
                smallest = j;
            }
            c++;
        }
        if (smallest != i)
        {
            swap(array[i], array[smallest]);
            p++;
        }
        if (flag)
        {
            cout << "Шаг " << i + 1 << ":\t";
            print_array(n, array);
        }
    }
}

//Сортировка Шелла с выводом на экран
void shell_sort (int n, int *array, int &p, int &c, bool flag)
{
    p = 0; //число перестановок
    c = 0; //число сравнений
    int h = 1;
    while (h <= n/3) h = 3*h + 1;
    cout << "Начало:\t";
    print_array(n, array);
    int step = 0;
    for (h; h > 0; h = (h-1)/3)
    {
        for (int i = h; i < n; i++)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= h && array[j - h] > temp; j -= h)
            {
                array[j] = array[j - h];
                p++;
                c++;
            }
            if (j >= h) c++;
            array[j] = temp;
        }
        step++;
        cout << "Шаг " << step << ":\t";
        print_array(n, array);
    }
}

//Сортировка выбором без вывода на экран
void selection_sort(int n, int *array, int &p, int &c)
{
    p = 0; //число перестановок
    c = 0; //число сравнений
    int i;
    for (i = 0; i < n - 1; i++)
    {

        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[smallest])
            {
                smallest = j;
            }
            c++;
        }
        if (smallest != i)
        {
            swap(array[i], array[smallest]);
            p++;
        }
    }
}

//Сортировка Шелла без вывода на экран
void shell_sort (int n, int *array, int &p, int &c)
{
    p = 0; //число перестановок
    c = 0; //число сравнений
    int h = 1;
    while (h <= n/3) h = 3*h + 1;
    for (h; h > 0; h = (h-1)/3)
    {
        for (int i = h; i < n; i++)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= h && array[j - h] > temp; j -= h)
            {
                array[j] = array[j - h];
                p++;
                c++;
            }
            if (j >= h) c++;
            array[j] = temp;
        }
    }
}

//Вывод массива на экран
void print_array(int n, int *array)
{
    for (int i=0; i<n; i++)
        cout << array[i] << "  ";
    cout << endl;
}