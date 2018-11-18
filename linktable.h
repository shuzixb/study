#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#include<pthread.h>

#define SUCCESS 0
#

/* LinkTable Node Type */
typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;

/* LinkTable Type */

typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinktableNode *pTail;
    int        sumOfNode;
    pthread_mutex_t mutex;
}tLinkTable;

/* Create a LinkTable */
tLinkTable *CreateLinkTable();

/* Delete a LinkTable */
int DeleteLinkTable(tLinkTable *pLinkTable);

/* Add a LinkTableNode to LinkTable */
int AddLinkTableNode(tLinkTabel *pLinkTable,tLinkTableNode *pNode);

/* Delete a LinkTableNode from LinkTable */
int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

/* get LinkTabelHead */
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);

/* get next LinkTableNode */
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

#endif /* _LINK_TABLE_H_ */
