#include "fun.h"

int main() {
    system("chcp 65001"); //подключение русского языка
    int q = 15;
    int b = 55;
    int N = 15; //количество элементов в массиве для 1 задания

    int *arr = new int[N]; //выделение памяти для массива на N элементов

    int permutations = 0; //инициализация количества перестановок
    int comparisons = 0; //инициализация количества сравнений


    //Сортировка выбором
    cout << "\nSELECTION_SORT\n";

    //Произвольный массив
    cout << "\nПРОИЗВОЛЬНЫЙ МАССИВ\n";
    random_sequence(N, arr); //генерация произвольного массива
    permutations = 0; //обнуление числа перестановок
    comparisons = 0; //обнуление числа сравнений
    selection_sort(N, arr, permutations, comparisons, true); //сортировка выбором произвольного массива
    cout << "permutations: " << permutations << endl; //вывод на экран числа перестановок
    cout << "comparisons: " << comparisons << endl; //вывод на экран числа сравнений

    //Убывающий массив
    cout << "\nУБЫВАЮЩИЙ МАССИВ\n";
    descending_sequence(N, arr); //генерация убывающего массива
    permutations = 0; //обнуление числа перестановок
    comparisons = 0; //обнуление числа сравнений
    selection_sort(N, arr, permutations, comparisons, true); //сортировка выбором убывающего массива
    cout << "permutations: " << permutations << endl; //вывод на экран числа перестановок
    cout << "comparisons: " << comparisons << endl; //вывод на экран числа сравнений

    //Возрастающий массив
    cout << "\nВОЗРАСТАЮЩИЙ МАССИВ\n";
    ascending_sequence(N, arr); //генерация возрастающего массива
    permutations = 0; //обнуление числа перестановок
    comparisons = 0; //обнуление числа сравнений
    selection_sort(N, arr, permutations, comparisons, true); //сортировка выбором возрастающего массива
    cout << "permutations: " << permutations << endl; //вывод на экран числа перестановок
    cout << "comparisons: " << comparisons << endl << endl; //вывод на экран числа сравнений


    //Сортировка Шелла
    cout << "\nSHELL_SORT\n";

    //Произвольный массив
    cout << "\nПРОИЗВОЛЬНЫЙ МАССИВ\n";
    random_sequence(N, arr); //генерация произвольного массива
    permutations = 0; //обнуление числа перестановок
    comparisons = 0; //обнуление числа сравнений
    shell_sort(N, arr, permutations, comparisons, true); //сортировка Шелла произвольного массива
    cout << "permutations: " << permutations << endl; //вывод на экран числа перестановок
    cout << "comparisons: " << comparisons << endl << endl; //вывод на экран числа сравнений

    //Убывающий массив
    cout << "\nУБЫВАЮЩИЙ МАССИВ\n";
    descending_sequence(N, arr); //генерация убывающего массива
    permutations = 0; //обнуление числа перестановок
    comparisons = 0; //обнуление числа сравнений
    shell_sort(N, arr, permutations, comparisons, true); //сортировка Шелла убывающего массива
    cout << "permutations: " << permutations << endl; //вывод на экран числа перестановок
    cout << "comparisons: " << comparisons << endl << endl; //вывод на экран числа сравнений

    //Возрастающий массив
    cout << "\nВОЗРАСТАЮЩИЙ МАССИВ\n";
    ascending_sequence(N, arr); //генерация возрастающего массива
    permutations = 0; //обнуление числа перестановок
    comparisons = 0; //обнуление числа сравнений
    shell_sort(N, arr, permutations, comparisons, true); //сортировка Шелла возрастающего массива
    cout << "permutations: " << permutations << endl; //вывод на экран числа перестановок
    cout << "comparisons: " << comparisons << endl << endl; //вывод на экран числа сравнений

    delete [] arr;

    void (*func_generate[])(int, int*, int*) = {random_sequence, descending_sequence, ascending_sequence};
    char name_func_generate[][100] = {"\t\t   ПРОИЗВОЛЬНЫЙ МАССИВ\n", "\t\t   УБЫВАЮЩИЙ МАССИВ\n", "\t\t   ВОЗРАСТАЮЩИЙ МАССИВ\n"};
    int dimension[] = {1000,10'000, 50'000, 100'000}; //массив размерностей

    for (int i = 0; i < 3; i++)
    {
        cout << name_func_generate[i];


        cout << "SELECTION_SORT\n";
        cout << "Длина \t\tВремя(мс)\tПерест.\t\tСравн.\n";
        for (int j = 0; j < 4; j++)
        {
            int *arr1 = new int[dimension[j]]; //выделение памяти для массива
            int *arr2 = new int[dimension[j]]; //выделение памяти для массива
            func_generate[i](dimension[j], arr1, arr2);
            permutations = 0; //обнуление числа перестановок
            comparisons = 0; //обнуление числа сравнений
            auto begin = std::chrono::steady_clock::now(); //старт отсчета времени
            selection_sort(dimension[j], arr1, permutations, comparisons);
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            cout << dimension[j] << "\t\t" << elapsed_ms.count() << "\t\t" << permutations << "\t\t" << comparisons << endl;

            delete [] arr1;
            delete [] arr2;
        }

        cout << "\nSHELL_SORT\n";
        cout << "Длина \t\tВремя(мс)\tПерест.\t\tСравн.\n";
        for (int j = 0; j < 4; j++)
        {
            int *arr1 = new int[dimension[j]]; //выделение памяти для массива
            int *arr2 = new int[dimension[j]]; //выделение памяти для массива
            func_generate[i](dimension[j], arr1, arr2);
            permutations = 0; //обнуление числа перестановок
            comparisons = 0; //обнуление числа сравнений
            auto begin = std::chrono::steady_clock::now(); //старт отсчета времени
            shell_sort(dimension[j], arr2, permutations, comparisons);
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            cout << dimension[j] << "\t\t" << elapsed_ms.count() << "\t\t" << permutations << "\t\t" << comparisons << endl;

            delete [] arr1;
            delete [] arr2;
        }
        cout << endl;

    }

    system("PAUSE");
    return 0;
}
