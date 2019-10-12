#include "sendthread.h"
#include "mainwindow.h"
#include <QDebug>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
sendThread::sendThread(QObject *parent) : QThread(parent)
{}
void sendThread::run()
{

    int j,n,num;
     QString fullPath;
     char buff[100];
     char send[1000];
    qDebug("thread:%d\n",syni);
    if(Sfile[syni].flag == TOONE || Sfile[syni].flag == ONLYONE)
     {
         // 到左
        if((access(Sfile[syni].pa2,F_OK)) == -1)
           {
            none = none + 1;
                return;
           }

         int z = 0;
         num = 0;
         n = strlen(Sfile[syni].pa1);
         for(j=n-1;j>=0;--j)
         {
             num++;
             if(Sfile[syni].pa1[j] == '/')
                 break;
         }
         for(z = 0 ;z<n-num;++z)
             buff[z] = Sfile[syni].pa1[z];
         buff[z] = '\0';
         qDebug("%s",buff);
         fullPath = QString::fromLocal8Bit(buff);

         QDir dir(fullPath);
         if(dir.exists())
         {
             qDebug("have\n");
         }
         else
         {
             dir.mkpath(fullPath);
             qDebug("no\n");
         }
         sprintf(send,"cp %s %s",Sfile[syni].pa2,Sfile[syni].pa1);
                 system(send);
     }
     else if(Sfile[syni].flag == TOTWO || Sfile[syni].flag == ONLYTWO)
    {
        // 到右
        if((access(Sfile[syni].pa1,F_OK)) == -1)
           {
            none = none + 1;
                return;
           }

        num = 0;
        int z = 0;
        n = strlen(Sfile[syni].pa2);
        for(j=n-1;j>=0;j--)
        {
            num++;
            if(Sfile[syni].pa2[j] == '/')
                break;
        }
        for(z = 0 ;z<n-num;z++)
            buff[z] = Sfile[syni].pa2[z];
        buff[z] = '\0';
    //    strncpy(buff,Sfile[i].pa2,n-num);
        qDebug("%s",buff);

        fullPath = QString::fromLocal8Bit(buff);
        QDir dir(fullPath);
        if(dir.exists())
        {
            qDebug("have\n");
        }
        else
        {
           dir.mkpath(fullPath);
            qDebug("no\n");
            qDebug()<<fullPath<<endl;
        }

        sprintf(send,"cp %s %s",Sfile[syni].pa1,Sfile[syni].pa2);
        system(send);
    }

    qDebug("%s,%s,%d\n",Sfile[syni].pa1,Sfile[syni].pa2,Sfile[syni].flag);
    emit isdone();
}
