#include <stdio.h>
#include <stdlib.h>
#include "int_vector.h"
int main()
{
    int capacity,index,item,i,size,newcap,input;
    IntVector *a;
    printf("Capacity: ");
    scanf ("%d",&capacity);
   
    a = int_vector_new(capacity);

    IntVector *b;

    {
    printf("\nVector was created\n");
    printf("1)Copy\n");
    printf("2)Free\n");
    printf("3)get item\n");
    printf("4)set item\n");
    printf("5)Get capacity\n");
    printf("6)Get size\n");
    printf("7)Push back\n");
    printf("8)Pop back\n");
    printf("9)Vector resize\n");
    printf("10)Vector reserve\n");
    printf("0)Esc the program\n");
    }
    for (i = 0; i <= 100; i++)
    {
	printf("\nChoose the operation: ");
	scanf("%d", &input);
	printf("\n");
	switch( input )
	{
		case 1:
		    b = int_vector_copy(a);
		    printf("\nVector was copied\n");
		    for (i=0;i<b->size;i++)
		    {
			printf("%d ",int_vector_get_item(b,i));
		    }
		    break;
		    
		case 2:
		    int_vector_free(a);
		    break;
		case 3:
		    printf("\nIndex: ");
		    scanf("%d",&index);
		    printf("%d",int_vector_get_item(a,index));
		    break;
		
		case 4:	
		    printf("\nIndex: ");
		    scanf("%d",&index);
		    printf("\nItem: ");
		    scanf("%d",&item);
	            int_vector_set_item(a, index, item);
		    printf("\nV = ");
		    for(i=0;i < a->size;i++)
		    {
			printf("%d ",int_vector_get_item(a,i));
		    }
		    printf("\n");
		    break;	
		case 5:
		    printf("\nCapacity = %zd\n",int_vector_get_capacity(a));
		case 6:
		    printf("\n size %zd\n",int_vector_get_size(a));
		    break;
		case 7:
		    printf("\nItem: ");
		    scanf("%d",&item);
		    int_vector_push_back(a,item);
		    printf("\n V= ");
		    for (i=0;i<a->size;i++)
		    {
			printf("%d ",int_vector_get_item(a,i));
		    }
		    printf("\n");
		    break;
		case 8:
		    printf("\nPop back started\n");
		    int_vector_pop_back(a);
		    for(i=0;i<a->size;i++)
		    {
			printf("%d ",int_vector_get_item(a,i));
		    }
		    printf("\n");
		    break;
		case 9:
		    
		    scanf("%d",&size);
		    int_vector_resize(a,size);
		    printf("\nV = ");
		    for(i=0;i<a->size;i++)
		    {
			printf("%d ",int_vector_get_item(a,i));
		    }
		    printf("\n");
		    break;
		case 10:
		    printf("\nNew capacity: ");
		    scanf("%d",&newcap);
		    int_vector_reserve(a,newcap);
		    printf("New Capacity = %zd\n",int_vector_get_capacity(a));
		    break;
		case 0:
		    return 0;
		    break;
	}
    }
    return 0;
}
