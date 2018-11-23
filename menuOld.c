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

#include"linklist.h"

int Help();
int Quit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_num     10


/* menu program */

static tDataNode head[]=
{
    {"help","this is help cmd",Help,&head[1]},
    {"quit","Quit from the program!",Quit,&head[2]},
    {"version","menu program v1.0",NULL,NULL}
};


int main(void)
{
    /* cmd line begins */
    while(1)
    {
	char cmd[CMD_MAX_LEN];
	printf("Input a cmd number >");
	scanf("%s",cmd);
	tDataNode *p=FindCmd(head,cmd);
	if(p==NULL)
	{
	    printf("This is a wrong cmd!\n");
	    continue;
	}
	printf("%s - %s\n",p->cmd,p->desc);
	if(p->handler !=NULL)
	    p->handler();
    }
}

int Help()
{
    ShowAllCmd(head);
}

int Quit()
{
    exit(0);
}
