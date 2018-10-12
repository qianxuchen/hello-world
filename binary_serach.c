#include <stdio.h>

int BinarySearch1(int *array, int array_count, int find_key, int is_asc)
{
	/*
	 * 二分法查找函数
	 * binary search function, if exist, return index; or return -1;
	 * array: source array by find
	 * array_count: count of array
	 * find_key: the find key
	 * is_asc: if array is ascending order, it's 0, or others 
	 * */
	if(array_count == 0)
		return -1;

	int head = 0, tail = array_count - 1;

	while(1)
	{
		int middle = (head + tail) / 2;

		int value = *(array + middle);

		if(head >= tail)
		{
			if(value == find_key)
				return head;
			else
				return -1;
		}

		if(value == find_key)
		{
			return middle;
		}
		else if(value > find_key)
		{
			if(is_asc == 0)
				tail = middle - 1;
			else
				head = middle + 1;
		}
		else
		{
			if(is_asc == 0)
				head = middle + 1;
			else
				tail = middle - 1;
		}

	}
}

int BinarySearch2(int *array, int key, int low, int high, int is_asc)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == array[mid])
        {
            return mid;
        }
        else if (key < array[mid])
        {
            if(is_asc == 0) 
		    high = mid - 1;
	    else
		    low = mid + 1;
        }
        else
        {
            if(is_asc == 0)
		    low = mid + 1;
	    else
		    high = mid - 1;
        }
    }
    return -1;
}

int BinarySearch(int *array, int array_count, int find_key, int is_asc)
{
	return BinarySearch2(array, find_key, 0, array_count - 1, is_asc);
}

int main()
{
	/*
	 * testing code, create 200 test items randomly, and loop through them
	 * */	
	printf("start test asc array...\n");
	
	int c_arr_len = 453323;

	//array: test array, ascending order.   result: save serach result, 0 is ok, 1 is error
	int array[c_arr_len], result[c_arr_len * 2];

	//init array
	for(int i=0; i<c_arr_len; i++)
	{
		array[i] = i * 2;
	}

	//start test
	for(int i=0; i<c_arr_len*2; i++)
	{	
		result[i] = BinarySearch(array, c_arr_len, i, 0);
	}
	
	//build result
	for(int i=0; i<c_arr_len*2; i++)
	{
		if(i % 2 == 0)
		{
			if(result[i] != (i / 2))
				printf("find %d = %d is error\t", i, result[i]);
		}
		else
		{
			if(result[i] != -1)
				printf("find %d = %d is error\t", i, result[i]);
		}
	}

	printf("\n");
	printf("start test desc array...\n");

	//reverse order array, test descending order
	for(int i=0; i<c_arr_len/2; i++)
	{
		result[0] = array[i];
		array[i] = array[c_arr_len- i - 1];
		array[c_arr_len - i - 1] = result[0];
	}

	//start test
	for(int i=0; i<c_arr_len*2; i++)
	{	
		result[i] = BinarySearch(array, c_arr_len, i, 1);
	}
	
	//build result
	for(int i=0; i<c_arr_len*2; i++)
	{
		if(i % 2 == 0)
		{
			if(result[i] != c_arr_len - 1 - (i / 2))
				printf("find %d = %d is error\t", i, result[i]);
		}
		else
		{
			if(result[i] != -1)
				printf("find %d = %d is error\t", i, result[i]);
		}
	}

	printf("\ntest code finish, if not output error info, test is ok!!!\n");

	return 0;
}
