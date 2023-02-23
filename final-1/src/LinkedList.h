/*
 * LinkedList.h
 *
 *  Created on: 14 feb. 2023
 *      Author: Monsalbo Lucio
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;

/****************************************************************************
				     			DECLARACIONES
*****************************************************************************/
LinkedList* ll_newLinkedList(void);

int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);

int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

int ll_add(LinkedList* this, void* pElement);

void* ll_get(LinkedList* this, int index);

int ll_set(LinkedList* this, int index,void* pElement);

int ll_remove(LinkedList* this,int index);

int ll_clear(LinkedList* this);

int ll_deleteLinkedList(LinkedList* this);

int ll_indexOf(LinkedList* this, void* pElement);

int ll_isEmpty(LinkedList* this);

int ll_push(LinkedList* this, int index, void* pElement);

void* ll_pop(LinkedList* this,int index);

int ll_contains(LinkedList* this, void* pElement);

int ll_containsAll(LinkedList* this,LinkedList* this2);

LinkedList* ll_subList(LinkedList* this,int from,int to);

LinkedList* ll_clone(LinkedList* this);

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

LinkedList* ll_map(LinkedList* this,int (pFuncion)(void* element));

LinkedList* ll_filter (LinkedList* this, int (*pFunc) (void* element));

#endif /* LINKEDLIST_H_ */
