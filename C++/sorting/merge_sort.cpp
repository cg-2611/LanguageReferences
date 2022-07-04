#include <iostream>
#include <vector>

void merge(std::vector<int> &array, int left, int mid, int right);
void merge_sort(std::vector<int> &array, int left, int right);
void print_array(std::vector<int> array);

void merge(std::vector<int> &array, int left, int mid, int right)
{
    std::vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {

		if (array[i] <= array[j])
        {
			temp.push_back(array[i]);
			i++;
		}
		else
        {
			temp.push_back(array[j]);
			j++;
		}

	}

	while (i <= mid)
    {
		temp.push_back(array[i]);
		i++;
	}

	while (j <= right)
    {
		temp.push_back(array[j]);
		j++;
	}

	for (size_t k = left; k <= right; k++)
    {
		array[k] = temp[k - left];
    }

    print_array(array);
}

void merge_sort(std::vector<int> &array, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }

}

void print_array(std::vector<int> array)
{
    std::cout << "[";
    for(size_t i = 0; i < array.size() - 1; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout <<  array[array.size() - 1] << "]" << std::endl;
}

int main(int argc, const char *argv[])
{
    std::vector<int> unsorted_array = {9, 3, 2, 7, 1, 4, 5, 8, 6};
    std::cout << "Unsorted Array:" << std::endl;
    print_array(unsorted_array);

    std::cout << "\nInsertion Sort:" << std::endl;
    merge_sort(unsorted_array, 0, unsorted_array.size() - 1);

    return 0;
}
