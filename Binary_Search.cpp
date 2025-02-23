#include <iomanip>
#include <iostream>
#include <cassert>

using namespace std;

void PrintHelper(int* arr, int n, int left, int right)
{
    cout << "[" << left << "," << right << "]" << endl;

    cout << "Indices: "; // Index
    for (int i = left; i <= right; i++)
        cout << setw(2) << i << " "; 
    // setw() => () 내 int값만큼의 공간을 가지고 출력
    cout << endl;

    cout << "Values: " << setw(2);
    for (int i = left; i <= right; i++)
        cout << setw(2) << arr[i] << " ";
    cout << endl;
}

int BinarySearch(int* arr, int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        PrintHelper(arr, n, left, right);

        int middle = (left + right) / 2;

        cout << "middle " << middle << endl;

        if (x < arr[middle])
        {
            right = middle - 1;
            cout << "right " << right << endl;
        }
        else if (x > arr[middle])
        {
            left = middle + 1;
            cout << "left " << left << endl;
        }
        else
        {
            cout << "Found " << middle << endl;
            return middle;
        }
    }
    cout << "Not Found" << endl;
    return -1;
}
int main()
{
    // 정렬된 배열 (임의의 배열 사용 가능, 여기서는 디버깅 편의를 위해 index와 같은 값)
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //int arr[] = { 2, 4, 5, 5, 6, 8, 9, 10, 12, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);

    assert(n > 0);

    // 정렬이 안된 배열은 미리 정렬

    BinarySearch(arr, n, 1);

    //for (int x = 0; x < n; x++)
    //	cout << x << " " << BinarySearch(arr, n, x) << endl;

    return 0;
}
