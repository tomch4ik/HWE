#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int sum_of_numbers(int num)
{
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int sum_of_positive_numbers(const vector<int>& arr)
{
    int sum = 0;
    for (int num : arr)
    {
        if (num > 0)
        {
            sum += num;
        }
    }
    return sum;
}

int min_number(const vector<int>& arr)
{
    int max_negative = 0;
    int position = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0 && (position == -1 || arr[i] > max_negative))
        {
            max_negative = arr[i];
            position = i;
        }
    }
   
    return position;
}

int popular(const vector<int>& arr)
{
    int most_popular = arr[0];
    int max_count = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            most_popular = arr[i];
        }
    }
    return most_popular;
}

int divisible_by_3(const vector<int>& arr)
{
    int index = -1;

    for (int i = 1; i < arr.size(); i += 1)
    {
        if (arr[i] % 3 == 0 && (index == -1 || arr[i] > index))
        {
             index = arr[i];
        }
    }

    return index;
}

vector<int> find_intersection(const vector<int>& arr1, const vector<int>& arr2) 
{
    vector<int> result;
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(result));
    return result;
}


vector<int> find_difference(const vector<int>& arr1, const vector<int>& arr2) 
{
    vector<int> result;
    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(result));
    return result;
}


void swap_numbers(vector<int>& arr)
{
    int max_even = -1;      
    int min_odd = -1;        
    int max_even_index = -1; 
    int min_odd_index = -1;  

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            if (max_even == -1 || arr[i] > max_even)
            {
                max_even = arr[i];
                max_even_index = i;
            }
        }
        else
        {
            if (min_odd == -1 || arr[i] < min_odd)
            {
                min_odd = arr[i];
                min_odd_index = i;
            }
        }
    }
    if (max_even_index != -1 && min_odd_index != -1)
    {
        swap(arr[max_even_index], arr[min_odd_index]);
    }
    else
    {
        fill(arr.begin(), arr.end(), 0);
    }
}


int main() {
    vector<int> arr = { 12, 104, 81, -2, 0, -1, 12, 12 };
    vector<int> arr1 = { 13, 104, 21, -2, 0, -1, 15, 126};
    int totalSum = 0;
    int the_biggest_num_by_3 = divisible_by_3(arr);


    cout << "Massive: ";
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (auto ptr = arr.begin(); ptr != arr.end(); ptr++)
    {
        totalSum += sum_of_numbers(*ptr);
    }

    cout << "Sum of numbers: " << totalSum << endl;
    cout << "Sum of positive numbers: " << sum_of_positive_numbers(arr) << endl;
    cout << "Position of min number: " << min_number(arr) << endl;
    cout << "Most popular number: " << popular(arr) << endl;
    if (the_biggest_num_by_3 != -1)
    {
        cout << "The biggest number divided by 3: " << the_biggest_num_by_3 << endl;
    }
    else
    {
        cout << "No number" << endl;
    }
    
    swap_numbers(arr);
    cout << "Massive after swap: ";
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(arr.begin(), arr.end());
    sort(arr1.begin(), arr1.end());

   
    vector<int> intersection = find_intersection(arr, arr1);
    cout << "Same numbers in 2 massives: ";
    copy(intersection.begin(), intersection.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    /*cout << "Different numbers in 2 massives: ";
    copy(symmetric_difference.begin(), symmetric_difference.end(), ostream_iterator<int>(cout, " "));
    cout << endl;*/
   

}