#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs)
{
    if (lhs != nullptr && rhs != nullptr)
    {
        int a = *lhs;
        int c = a;
        *lhs = *rhs;
        *rhs = c;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value)
{
    if (num_rows < 1 || num_cols < 1)
    {
        return nullptr;
    }
    int **arr = new int *[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        arr[i] = new int[num_cols];
    }
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            arr[i][j] = init_value;
        }
    }
    return arr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols)
{
    if (num_cols > 0 && num_rows > 0 && arr_2d_source && arr_2d_target)
    {
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                arr_2d_target[i][j] = arr_2d_source[i][j];
            }
        }
        return true;
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr)
{
    for (int i = 0; i < arr.size() / 2; i++)
    {
        int s = arr[i];
        arr[i] = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = s;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end)
{
    if (arr_begin && arr_end)
    {
        for(;arr_end>arr_begin; arr_end--, arr_begin++)
        {
            swap_args(arr_begin,arr_end);
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size)
{
    if(arr && size>0)
    {
        int *max = arr;
        for(int i = 0;i < size ; i++)
        {
            if(*arr > *max)
            {
                max = arr;
            }
            arr+=1;
        }
        return max;
    }
    else
    {
        return nullptr;
    }
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr)
{
    vector<int> odd_numbers{};
    for(int el : arr)
    {
        if(std::abs(el) % 2 == 1)
        {
            odd_numbers.push_back(el);
        }
    }
    return odd_numbers;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b)
{
    vector<int> common_elements{};
    for(int & i : arr_a)
    {
        for (int j : arr_b)
        {
            if(i == j)
            {
                common_elements.push_back(i);
            }
        }
    }
    return common_elements;
}