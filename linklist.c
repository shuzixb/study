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


/* data struct and its operations */

#include"linklist.h"

tDataNode* FindCmd(tDataNode *head,char *cmd)
{
    if(head==NULL||cmd==NULL)
    {
        return NULL;
    }
    tDataNode *p=head;
    while(p!=NULL)
    {
        if(!strcmp(p->cmd,cmd))
            return p;
	p=p->next;
    }
    return NULL;
}

int ShowAllCmd(tDataNode *head)
{
    printf("Menu List:\n");
    tDataNode *p=head;
    while(p!=NULL)
    {
        printf("%s - %s\n",p->cmd,p->desc);
	p=p->next;
    }
    return 0;
}

