#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - lista sorteada
 * @list: la lista a organizar
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *Ptemp, *temp2;

	if (*list == NULL)
		return;
	temp = temp->next;
	while (temp)
	{
		Ptemp = temp->prev;
		if (temp->n < temp->prev->n)
		{
			while ((temp->prev != NULL) && (temp->n < temp->prev->n))
			{
				temp2 = temp->next;
				temp->next = temp->prev;
				temp->prev->next = temp2;
				if (temp2 != NULL)
					temp2->prev = temp->prev;
				temp2 = temp->prev;
				if (temp->prev->prev == NULL)
				{
					temp->prev = NULL;
					*list = temp;
				}
				else
				{
					temp->prev = temp2->prev;
					temp->prev->next = temp;
				}
				temp2->prev = temp;
				print_list(*list);
			}
			temp = Ptemp;
		}
		if (temp != NULL)
			temp = temp->next;
	}
}
