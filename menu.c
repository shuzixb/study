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

int Help();
int Quit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_num     10

typedef struct DataNode
{
    char* cmd;
    char* desc;
    int   (*handler)();
    struct DataNode *next;
} tDataNode;

static tDataNode head[]=
{
    {"help","this is help cmd",Help,&head[1]},
    {"quit","Quit from the program!",Quit,&head[2]},
    {"version","menu program v1.0",NULL,NULL}
};


int main(void)
{
    char cmd[CMD_MAX_LEN];
    while(1)
    {
	char cmd[CMD_MAX_LEN];
	printf("Input a cmd number >");
	scanf("%s",cmd);
	tDataNode *p=head;
	while(p!=NULL)
        {
	    if(strcmp(p->cmd,cmd)==0)
            {
                printf("%s - %s\n",p->cmd,p->desc);
	        if(p->handler!=NULL)
		{
		    p->handler();
		}	
		break;
	    }
	    p=p->next;
        }
    }
}

int Help()
{
    printf("Menu List:\n");
    tDataNode *p=head;
    while(p !=NULL)
    {
        printf("%s - %s\n",p->cmd,p->desc);
	p=p->next;
    }
}

int Quit()
{
    exit(0);
}
