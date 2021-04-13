#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

struct array
{
	void* buf;
	int array_size;
	int elem_size;
};


void Set_element(struct array* arr1, int index, void* value)
{
	void* p = (char*)arr1->buf + arr1->elem_size * index;
	memcpy(p, value, arr1->elem_size);
}

void Set_element_int(struct array* arr1)
{
	int temp;
	for (int i = 0; i < arr1->array_size; ++i) {
		printf("input the element %d -> ", i);
		scanf("%d", &temp);
		printf("\n");
		Set_element(arr1, i, &temp);
	}
}

void Set_element_double(struct array* arr1)
{
	double temp;
	for (int i = 0; i < arr1->array_size; ++i) {
		printf("input the element %d -> ", i);
		scanf("%lf", &temp);
		Set_element(arr1, i, &temp);
	}
}

void Print_Array(struct array* arr1)
{
	if(arr1 -> elem_size == sizeof(int))
	{
			Print_Array_int(arr1);
	}else
	{
			Print_Array_double(arr1);
	}
}

void Print_Array_int(struct array* arr1)
{
	for (int i = 0; i < arr1->array_size; ++i)
	{
		printf("Number[%d] = %d\n", i, *((int*)arr1->buf + i));
	}
	printf("\n");
}

void Print_Array_double(struct array* arr1)
{
	for (int i = 0; i < arr1->array_size; ++i)
	{
		printf("Number[%d] = %f\n", i, *((double*)arr1->buf + i));
	}
	printf("\n");
}

int Witch_type()
{
	int type,size;
	do {
		printf("Iput size of element(type int = 1, type double = 0) -> ");
		scanf("%d", &type);
		if((type!= 1) && (type != 0))
		{
			printf("ERROR PLEASE INPUT 1 OR 0 \n");
		}
	} while((type!= 1) && (type != 0));
	if(type == 1)
	{
		size = sizeof(int);
	}else
	{
		size = sizeof(double);
	}
	return size;
}

void Bubble_sort(struct array* mass)
{
	if(mass->elem_size == sizeof(int))
	{
			Bubble_sort_int(mass);
	}else
	{
			Bubble_sort_double(mass);
	}

}

void Bubble_sort_int(struct array* mass)
{
	int temp;
	for (size_t i = 0; i < mass->array_size; i++) {
				for (size_t j = 0; j < mass->array_size - i - 1; j++) {
					 	if(*((int*)mass->buf + j) < *((int*)mass->buf + j + 1))
						{
							temp = *((int*)mass->buf + j);
							*((int*)mass->buf + j) = *((int*)mass->buf + j + 1);
							*((int*)mass->buf + j + 1) = temp;
						}
				}
		}
}

void Bubble_sort_double(struct array* mass)
{
	double temp;
	for (size_t i = 0; i < mass->array_size; i++) {
				for (size_t j = 0; j < mass->array_size - i - 1; j++) {
					 	if(*((double*)mass->buf + j) < *((double*)mass->buf + j + 1))
						{
							temp = *((double*)mass->buf + j);
							*((double*)mass->buf + j) = *((double*)mass->buf + j + 1);
							*((double*)mass->buf + j + 1) = temp;
						}
				}
		}
}

struct array* Create_ar(int array_size, int elem_size)
{
	int temp;
	struct array* arr1 = (void*)malloc(sizeof(struct array));
	arr1->array_size = array_size;
	arr1->elem_size = elem_size;
	arr1->buf = (void*)malloc(array_size * elem_size);
	if(elem_size == sizeof(int))
	{
		Set_element_int(arr1);
	}
	if(elem_size == sizeof(double))
	{
		Set_element_double(arr1);
	}
	return arr1;
}

struct array* Create_ar_empty(int array_size,int elem_size)
{
	struct array* arr1 = (void*)malloc(sizeof(struct array));
	arr1->array_size = array_size;
	arr1->elem_size = elem_size;
	arr1->buf = (void*)malloc(array_size * elem_size);
	for (int i = 0; i < arr1->array_size; ++i)
	{
		elem_size = 0;
		Set_element(arr1, i, &elem_size);
	}
	return arr1;
}

struct array* Concatination_int(struct array* arr1, struct array* arr2)
{
	struct array* arr3 = Create_ar_empty((arr1 -> array_size)+(arr2 -> array_size),arr1 -> elem_size);
	for (size_t i = 0; i < arr1 -> array_size; i++) {
			*((int*)arr3 -> buf + i) = *((int*)arr1 -> buf + i);
	}
	for (size_t i = 0; i < arr2 -> array_size; i++) {
			*((int*)arr3 -> buf + arr1 -> array_size + i) = *((int*)arr2 -> buf + i);
	}
	return arr3;
}

struct array* Concatination_double(struct array* arr1, struct array* arr2)
{
	struct array* arr3 = Create_ar_empty((arr1 -> array_size)+(arr2 -> array_size),arr1 -> elem_size);
	for (size_t i = 0; i < arr1 -> array_size; i++) {
			*((double*)arr3 -> buf + i) = *((double*)arr1 -> buf + i);
	}
	for (size_t i = 0; i < arr2 -> array_size; i++) {
			*((double*)arr3 -> buf + arr1 -> array_size + i) = *((double*)arr2 -> buf + i);
	}
	return arr3;
}

struct array* Concatination(struct array* arr1, struct array* arr2)
{
	if((arr1 -> elem_size) == (arr2 -> elem_size))
	{
		struct array* arr3;
		if(arr1 -> elem_size == sizeof(int))
		{
			arr3 = Concatination_int(arr1,arr2);
			return arr3;
		}else
		{
			arr3 = Concatination_double(arr1,arr2);
			return arr3;
		}
	}
}

int square_int(int x)
{
	x = x * x;
	return x;
}

int twice_int(int x)
{
	x = x + x;
	return x;
}

double square_double(double x)
{
	x = x * x;
	return x;
}

double twice_double(double x)
{
	x = x + x;
	return x;
}

void Map_int(struct array* arr, int (*foo)(int))
{
	for (size_t i = 0; i < arr -> array_size; i++) {
			*((int*)arr -> buf + i) = foo(*((int*)arr -> buf + i));
	}
}

int Choose_var_of_MAP()
{
	int temp;
	do {
		printf("To square yout element press 1 or twice your element press 0  -> ");
		scanf("%d",&temp);
		if(temp != 1 && temp != 0 )
		{
			printf("ERROR PLEASE INPUT 1 OR 0 \n");
		}
	} while((temp != 1) && (temp != 0));
	return temp;
}

int Choose_var_of_WHERE()
{
	int temp;
	do {
		printf("To positive yout element press 1 or twice your negative press 0  -> ");
		scanf("%d",&temp);
		if((temp != 1) || (temp != 0 ))
		{
			printf("ERROR PLEASE INPUT 1 OR 0 \n");
		}
	} while((temp != 1) && (temp != 0));
	return temp;
}

void Map_double(struct array* arr, double (*foo)(double))
{
	for (size_t i = 0; i < arr -> array_size; i++) {
		*((double*)arr -> buf + i) = foo(*((double*)arr -> buf + i));
	}
}

void Map(struct array* arr)
{
	if(arr -> elem_size == sizeof(int))
	{
		if(Choose_var_of_MAP() == 1)
		{
			Map_int(arr, square_int);
		}else
		{
			Map_int(arr,twice_int);
		}
	}else
	{
		if(Choose_var_of_MAP() == 1)
		{
			Map_double(arr, square_double);
		}else
		{
			Map_double(arr,twice_double);
		}
	}

}

bool Positive_int(int x)
{
	if(x > 0)
	{
		return 1;
	}else
	{
		return 0;
	}
}

bool Negative_int(int x)
{
	if(x < 0)
	{
		return 1;
	}else
	{
		return 0;
	}
}

bool Negative_double(double x)
{
	if(x < 0)
	{
		return 1;
	}else
	{
		return 0;
	}
}

bool Positive_double(double x)
{
	if(x > 0)
	{
		return 1;
	}else
	{
		return 0;
	}
}

struct array* Where_int(struct array* arr, int (*foo)(int))
{
	  int temp = 0, tempS = 0;

		for (size_t i = 0; i < arr -> array_size; i++)
		{
			if(foo(*((int*)arr -> buf + i)) == 1 )
			{
				temp++;
			}
		}
		struct array* arrbool = Create_ar_empty(temp, sizeof(int));
		for (int i = 0; i < arr -> array_size; i++)
		{
				if(foo(*((int*)arr -> buf + i)) == 1 )
				{
					*((int*)arrbool -> buf + tempS) = *((int*)arr -> buf + i);
					tempS++;
				}
		}
		return arrbool;
}

struct array* Where_double(struct array* arr, int (*foo)(double))
{
	  int temp = 0, tempS = 0;

		for (size_t i = 0; i < arr -> array_size; i++)
		{
			if(foo(*((double*)arr -> buf + i)) == 1 )
			{
				temp++;
			}
		}
		struct array* arrbool = Create_ar_empty(temp, sizeof(double));
		for (int i = 0; i < arr -> array_size; i++)
		{
				if(foo(*((double*)arr -> buf + i)) == 1 )
				{
					*((double*)arrbool -> buf + tempS) = *((double*)arr -> buf + i);
					tempS++;
				}
		}
		return arrbool;
}

struct array* Where(struct array* arr)
{
	if(arr -> elem_size == sizeof(int))
	{
		if(Choose_var_of_WHERE() == 1)
		{
			Where_int(arr, Positive_int);
		}else
		{
			Where_int(arr,Negative_int);
		}
	}else
	{
		if(Choose_var_of_WHERE() == 1)
		{
			Where_double(arr, Positive_double);
		}else
		{
			Where_double(arr, Negative_double);
		}
	}
}


void test_int()
{
	struct array* massiv = Create_ar_empty(5,sizeof(int));
	struct array* massivcon = Create_ar_empty(5,sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		*((int*)massiv -> buf + i) = i ;
		*((int*)massivcon -> buf + i) =  i  ;
	}
	*((int*)massiv -> buf ) = -1;
	printf("Test int\n");
	Print_Array(massiv);
	printf("=========================\n");
	printf("It is a concatination\n");
	Print_Array(Concatination(massiv,massivcon));
	printf("=========================\n");
	printf("It is a sort\n");
	Print_Array(massivcon);
	Bubble_sort(massivcon);
	Print_Array(massivcon);
	printf("=========================\n");
	printf("It is a where\n");
	printf("Positive elements:\n");
	struct array* temparr = Where_int(massiv,Positive_int);
	Print_Array(temparr);
	printf("Positive elements:\n");
	struct array* temparr1 = Where_int(massiv,Negative_int);
	Print_Array(temparr1);
	printf("=========================\n");
	printf("It is a map\n");
	Map_int(massiv,square_int);
	Print_Array(massiv);
	Map_int(massiv,twice_int);
	Print_Array(massiv);
	free(massiv);
	free(temparr);
	free(temparr1);
	free(massivcon);
}

void test_double()
{
	struct array* massiv = Create_ar_empty(5,sizeof(double));
	struct array* massivcon = Create_ar_empty(5,sizeof(double));
	for (int i = 0; i < 5; i++)
	{
		*((double*)massiv -> buf + i) = 1.0 + i ;
		*((double*)massivcon -> buf + i) = 1.0 + i  ;
	}
	*((double*)massiv -> buf ) = -1.11;
	printf("Test double\n");
	Print_Array(massiv);
	printf("=========================\n");
	printf("It is a concatination\n");
	Print_Array(Concatination(massiv,massivcon));
	printf("=========================\n");
	printf("It is a sort\n");
	Print_Array(massivcon);
	Bubble_sort(massivcon);
	Print_Array(massivcon);
	printf("=========================\n");
	printf("It is a where\n");
	printf("Positive elements:\n");
	struct array* temparr = Where_double(massiv,Positive_double);
	Print_Array(temparr);
	printf("Negative elemets:\n");
	struct array* temparr1 = Where_double(massiv,Negative_double);
	Print_Array(temparr1);
	printf("=========================\n");
	printf("It is a map\n");
	Map_double(massiv,square_double);
	Print_Array(massiv);
	Map_double(massiv,twice_double);
	Print_Array(massiv);
	free(massiv);
	free(temparr);
	free(temparr1);
	free(massivcon);
}


void Test()
{
	test_int();
	test_double();
}

int main()
{
	Test();
	/*int array_size,elem_size;
	printf("Input array size -> ");
	scanf("%d", &array_size);
	elem_size = Witch_type();
	struct array* mass = Create_ar(array_size,elem_size);
	//struct array* mass1 = Create_ar(array_size,elem_size);
	/*printf("Input array size -> ");
	scanf("%d", &array_size);
	elem_size = Witch_type();
	struct array* mass1 = Create_ar(array_size,elem_size);
	printf("___________\n");
	Print_Array(mass);
	Print_Array(mass1);
	printf("___________\n");
	Print_Array(Concatination(mass,mass1));
	//Bubble_sort(mass);Positive_double
	free(mass1);
	//printf("elemnt 1 = %d",*((int*)mass -> buf));
	Print_Array(mass);
	printf(" ========================== \n");
	Map(mass);
	Print_Array(mass);
  //struct array* mass1 = Where(mass);
	printf(" ========================== \n");
	free(mass);
	//Print_Array(mass1);*/

	return 0;
}
