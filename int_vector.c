#include "int_vector.h"

IntVector *int_vector_new(size_t initial_size)
{
	IntVector *v=(IntVector*)malloc(sizeof(IntVector));
	if(!v)
	{
		return 0;
	}
	
	v->data=(int*)malloc(initial_size*sizeof(int));
	if(!v->data)
	{
		free(v->data);
		
	}
	v->size = 0;
	v->capacity = initial_size;
	return v;
}

size_t int_vector_get_size(const IntVector *v)
{
	if (v) 
	{
		return v->size;
	}
	else
	{
		return 0;
	}
}

size_t int_vector_get_capacity(const IntVector *v)
{
	if (v) 
	{
		return v->capacity;
	}
	else
	{
		return 0;
	}
}

void int_vector_free(IntVector *v)
{
	if (v)
	{
		free(v->data);
		free(v);
	}
	
}
IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *copy=int_vector_new(v->capacity);
	if(!copy)
	{
		return NULL;
	}
	else
	{
		memcpy (copy->data,v->data,v->size);
		copy->capacity=v->capacity;
		copy->size=v->size;
		return copy;
	}
	
}
int int_vector_push_back(IntVector *v, int item)
{	
	if(!v)
	{
		return -1;
	}
       
	if(v->capacity == v->size)
	{
		v->capacity*=2;
	}
	
	v->data[v->size++]=item;
	return 0;
}
void int_vector_pop_back(IntVector *v)
{
	if(v->size == 0)
	{
		printf("Нет эффекта\n");
	}
	else
	{
		v->data[--v->size]=0;
	}
}
int int_vector_get_item(const IntVector *v, size_t index) 
{
	if (index > (v->size-1))
	{
		printf("\nError ");
		return 0;
	}
	else
	{
		return v->data[index];	
	}
}
void int_vector_set_item(IntVector *v, size_t index, int item) 
{
	
	if (!(index > (v->size)-1))
	{
		v->data[index]=item;
	}
}
int int_vector_shrink_to_fit(IntVector *v) 
{	
	if (!v)
	{
		return -1;
	}
	
	v->capacity = v->size;
	return 0;	
}
int int_vector_reserve(IntVector *v, size_t new_capacity) 
{
	if ( new_capacity <= v->capacity )
	{
		return -1;
	}
	else
	{
		v->capacity=new_capacity;
		return 0;
	}
}
int int_vector_resize(IntVector *v, size_t new_size) 
{
	int i;
	size_t k;
	if (v->size > new_size )
	{	
		return -1;
	}
	else 
	{
		k=v->size;
		v->size = new_size;		
		if(v->size > v->capacity)
		{
			int_vector_shrink_to_fit(v);
		}
		for (i=k-1;i < v->size-1;i++)
		{
			v->data[i]=0;
			
		}		

		printf("\nNew size: %zd",v->size);
		return 0;
	}
}



