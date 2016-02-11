
//  main.cpp
//  Bilibili
//
//  Created by fufan on 15/4/11.
//  Copyright (c) 2015年 fufan. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int n,m,T,q;
int w[50000];
std::pair<int,int> screen[50000];
int main()
{

    std::cin>>T;
    for(int i1 = 1;i1<=T;i1++)
    {
        std::cin>>n>>m>>q;
        int now = 0;
        memset(screen,0,sizeof(screen));
        memset(w,0,sizeof(w));
        std::cout<<"Case "<<'#'<<T<<std::endl;
        for(int i2 = 1;i2<=q;i2++)
        {
            int time,len;
            std::cin>>time>>len;
            int gap = time -now;
            now += gap;
            for(int i3=1;i3<=n;i3++)//跳到当前状态
            {
                if(screen[i3].first==0&&screen[i3].second==0&&w[i3]==0)
                    continue;
                screen[i3].first+=gap;
                screen[i3].second+=gap;
                if(w[i3]!=0)//处理右边（左边小）
                {
                    if(w[i3]>gap)
                    {
                        w[i3]-=gap;
                        screen[i3].first = 1;
                    }
                    else
                    {
                        screen[i3].first-=w[i3];
                        screen[i3].first++;
                        w[i3] = 0;
                    }
                }
                if(screen[i3].first>m)//如果全出去了
                {
                    screen[i3].first = 0;
                    screen[i3].second = 0;
                }
                else//出去一部分
                {
                    if(screen[i3].second>m)
                        screen[i3].second = m;
                }
            }
            int falg = 0;
            for(int i3= 1;i3<=n;i3++)
            {
                if(screen[i3].first==0&&screen[i3].second==0)
                {
                    falg = i3;
                    break;
                }
            }
            if(falg)
            {
                w[falg] = len;
                printf("%d\n",falg);
            }
            else
                printf("Failed!\n");
        }
    }

    return 0;
}


