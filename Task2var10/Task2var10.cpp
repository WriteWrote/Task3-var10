// Task2var10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <vector>
#include "MyComparator.h"

using namespace std;


/*
Реализовать шаблон класса (функции), принимающий элементы любого типа 
и поддерживающий базовые операции в соответствии со своим назначением. 
В качестве внутренней структуры хранения данных можно использовать, например, динамический массив. 
Использование шаблона должно осуществляться из функции main() и содержать 
примеры работы как минимум с двумя разными типами данных (например, int и string).

10.	Шаблон функции быстрой сортировки qsort(), принимающий критерий сравнения в виде аргумента шаблона.
*/

template<typename T>
T* quickSort(T* arr, int size, MyComparator<T> &comp) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    T mid = arr[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (arr[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (arr[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //левый кусок
        quickSort(arr, j + 1, comp);
    }
    if (i < size) {
        //правый кусок
        quickSort(&arr[i], size - i, comp);
    }
    
    // как терять объекты типа T, если они сложнее примитивов?

    return arr;
}

int main()
{
    string *strArr = new string[4]{"str1","str2","STR1","STR2"};
    int* intArr = new int[4]{12, 2, 31, 4};
    
    MyComparator<string> strComp;
    MyComparator<int> intComp;
    
    string* resStr = quickSort(strArr, 4, strComp);
    int* resInt = quickSort(intArr, 4, intComp);

    for (size_t i = 0; i < 4; i++)
    {
        cout << resStr[i] <<endl;
    }
    cout << endl;
    for (size_t i = 0; i < 4; i++)
    {
        cout << resInt[i] << endl;
    }

    return 0;
}
