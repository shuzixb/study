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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DataNode
{
    char* cmd;
    char* desc;
    int   (*handler)();
    struct DataNode *next;
} tDataNode;

tDataNode* FindCmd(tDataNode *head,char *cmd);

int ShowAllCmd(tDataNode *head);
