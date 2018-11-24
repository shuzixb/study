#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"

tLinkTable *CreateLinkTable()
{
    tLinkTable *pLinkTable=(tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable==NULL)
    {
	    return NULL;
    }
    pLinkTable->pHead=NULL;
    pLinkTable->pTail=NULL;
    pLinkTable->sumOfNode=0;
    //pthread_mutex_init(&(pLinkTable->mutex),NULL);
    return pLinkTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
    if(pLinkTable==NULL)
    {
        return 0;
    }
    while(pLinkTable->pHead!=NULL)
    {
        tLinkTableNode *tmp=pLinkTable->pHead;
	//pthread_mutex_lock(&(pLinkTable->mutex));
	pLinkTable->pHead=pLinkTable->pHead->pNext;
	pLinkTable->sumOfNode-=1;
	//pthread_mutex_unlock(&(pLinkTable->mutex));
	free(tmp);
    }
    pLinkTable->pHead=NULL;
    pLinkTable->pTail=NULL;
    pLinkTable->sumOfNode=0;
    //pthread_mutex_destroy(&(pLinkTable->mutex));
    free(pLinkTable);
    return SUCCESS;
}

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
    {
        return FAILURE;
    }
    pNode->pNext=NULL;
    //pthread_mutex_lock(&(pLinkTable->mutex));
    if(pLinkTable->pHead==NULL)
    {
        pLinkTable->pHead=pNode;
	pLinkTable->pTail=pNode;
	pLinkTable->sumOfNode=1;
    }
    else
    {
        pLinkTable->pTail->pNext=pNode;
	pLinkTable->pTail=pNode;
	pLinkTable->sumOfNode++;
    }
    //pthread_mutex_unlock(&(pLinkTable->mutex));

    return SUCCESS;
}

int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
    {
        return FAILURE;
    }
    //pthred_mutex_lock(&(pLinkTable->mutex));
    if(pLinkTable->pHead==pNode)
    {
        tLinkTableNode *tmp=pLinkTable->pHead;
	pLinkTable->pHead=pLinkTable->pHead->pNext;
	free(tmp);
	pLinkTable->sumOfNode--;
	if(pLinkTable->sumOfNode==0)
	{
	    pLinkTable->pTail=NULL;
	}
        //pthread_mutex_unlock(&(pLinkTable->mutex));
	return SUCCESS;
    }

    tLinkTableNode *tmp=pLinkTable->pHead;
    while(tmp!=NULL)
    {
        if(tmp->pNext==pNode)
        {
            tmp->pNext=pNode->pNext;
	    pLinkTable->sumOfNode--;
	    //pthread_mutex_unlock(&(pLinkTable->mutex));
	    return SUCCESS;
	}
	tmp=tmp->pNext;
    }
    return FAILURE;
}

tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable==NULL||pLinkTable->pHead==NULL)
        return NULL;
    return pLinkTable->pHead;
}

tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
        return NULL;
    else
	return pNode->pNext;
}

tLinkTableNode *SearchLinkTableNode(tLinkTable *pLinkTable,int Conditon(tLinkTableNode *pNode,void*args),void* args)
{
    if(pLinkTable==NULL||Conditon==NULL)
    {
        return NULL;
    }
    tLinkTableNode *pNode=pLinkTable->pHead;
    while(pNode!=NULL)
    {
        if(Conditon(pNode,args)==SUCCESS)
	{
	    return pNode;
	}
	pNode=pNode->pNext;
    }
    return NULL;
}
