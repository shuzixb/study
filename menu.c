/**************************************************************************************************/
/*Copyright (c) shuzixb@qq.com 2018-2019                                                          */
/*                                                                                                */
/*  FILE NAME                   :  MENU.C                                                         */
/*  PRINCIPAL AUTHOR            :  shuzixb                                                        */
/*  SUBSYSTEM NAME              :  menu                                                           */
/*  LANGUAGE                    :  C                                                              */
/*  TARGET ENVIRONMENT          :  ANY                                                            */
/*  DATE OF FIRST RELEASE       :  2018/11/16                                                     */
/*  DESCRIPTION                 :  This is a menu program                                         */
/**************************************************************************************************/

/*
 * Revision log:
 * Created by shuzixb,2018/11/16
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linktable.h"
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_num     10


typedef struct DataNode
{
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int (*handler)();
}tDataNode;

/*
tDataNode *FindCmd(tLinkTable *head,char *cmd)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode!=NULL)
    {
	 if(strcmp(pNode->cmd,cmd)==0)
             return pNode;
	 pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return NULL;
}
*/

int SearchCondition(tLinkTableNode * pLinkTableNode,void * args)
{
    char * cmd=(char*)args;
    tDataNode* pNode=(tDataNode*)pLinkTableNode;
    if(strcmp(pNode->cmd,cmd)==0)
        return SUCCESS;
    return FAILURE;
}

int Help();
int Quit();

int ShowAllCmd(tLinkTable *head)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode!=NULL)
    {
        printf("%s - %s\n",pNode->cmd,pNode->desc);
	pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return 0;
}


int InitMenuData(tLinkTable **ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();
    tDataNode *pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="Menu List:";
    pNode->handler=Help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);

    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="version";
    pNode->desc="Menu Program V1.0";
    pNode->handler=NULL;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);

    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="quit from menu program V1.0";
    pNode->handler=Quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);

    return 0;
}

tLinkTable *head=NULL;


int main()
{
    char cmd[CMD_MAX_LEN];
    InitMenuData(&head);
    while(1)
    {
        printf("Input a cmd number >");
	scanf("%s",cmd);
	tDataNode *p=(tDataNode*)SearchLinkTableNode(head,SearchCondition,(void*)cmd);
	if(p==NULL)
	{
            printf("This is a wrong cmd!\n");
	    continue;
	}
	printf("%s - %s\n",p->cmd,p->desc);
	if(p->handler!=NULL)
	{
	    p->handler();
	}
    }
    return 0;
}





int Help()
{
    ShowAllCmd(head);
    return 0;
}

int Quit()
{
    exit(0);
    return 0;
}
