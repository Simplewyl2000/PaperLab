#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define  NODE_NUMBER 317081
#define EDGES_MAX 100000011
#define LOOPS  101   ///初始化循环次数
#define Pse 0.55
#define Pinit 0.01
#define Pinfect 0.03

struct graphArr{
    int u, v;
}Edges[EDGES_MAX];  ///<Edges[i]表示第i条边由节点u与节点v相连

int arr1[NODE_NUMBER], arr2[NODE_NUMBER];///<arr1[]是上一时间片的感染节点，arr2[]是下一时间片的感染节点

int p1, p2, p3;
int numberOfEdge=0;

int infectedProbabitity(double rate)
{
    int n = rate * 100;

    int data = rand() % 100;
    if(data < n)
        return 1;
    else
        return 0;
}

int main()
{

    int x, y;

    memset(Edges, 0, sizeof(Edges));
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));

    FILE *fp1;
    if((fp1 = fopen("dblp.txt", "r")) == NULL)
    {
        printf("Fail to open fp1!\n");
        return 0;
    }
    else
    {

        numberOfEdge = 0;
        while(!feof(fp1))
        {
            fscanf(fp1, "%d%d", &x, &y);
            x++; y++;
            Edges[numberOfEdge].u = x;
            Edges[numberOfEdge].v = y;
            numberOfEdge++;
        }
    }
    fclose(fp1);

    //搜索引擎的作用
    int orig1,orig2;
    int original_edge = numberOfEdge;
    for(x=0;x<Pse*original_edge;x++)
    {
        orig1= rand() % (NODE_NUMBER-1);
        orig1+=1;
        orig2= rand() % (NODE_NUMBER-1);
        orig2+=1;
        if(orig1!=orig2)
        {
            Edges[numberOfEdge].u=orig1;
            Edges[numberOfEdge].v=orig2;
            numberOfEdge++;
        }
    }




    FILE *fp2;

    if((fp2 = fopen("results.txt", "w")) == NULL)
    {
        printf("Fail to open fp2!\n");
        return 0;
    }
    else
    {

        srand((int)time(0));

        int k = 0;
        for(k = 1; k <NODE_NUMBER; k++)
        {///<循环遍历arr1数组，让每个未被感染的节点以一定概率p被感染
            if(arr1[k] == 0)
            {
                p1 = infectedProbabitity(Pinit);
                if(p1 == 1)
                    arr1[k] = 1;
            }
        }


        int numberOfInfected = 0; ///<被感染的节点数目
        int total=0;
        int loop = LOOPS;
        while(loop > 0)
        {
            ///<通过社交网络感染部分
            int i = 0;
            memset(arr2, 0, sizeof(arr2));///<初始化arr2数组

            for(; i < numberOfEdge; i++)
            {
                if(arr1[Edges[i].u] == 1)
                {
                    p2 = infectedProbabitity(Pinfect);
                    if(p2 == 1)
                        arr2[Edges[i].v] = 1;
                }
                if(arr1[Edges[i].v] == 1)
                {
                    p2 = infectedProbabitity(Pinfect);
                    if(p2 == 1)
                        arr2[Edges[i].u] = 1;
                }
            }

            ///<求出每次循环被感染的节点数目
            int numberOfInfected = 0; ///<被感染的节点数目
            for(k = 1; k < NODE_NUMBER; k++)
            {
                if(arr1[k] == 1)
                    numberOfInfected++;
            }



            total = numberOfInfected;


            double pp = ((double)numberOfInfected)/(NODE_NUMBER-1);

            fprintf(fp2, "%f\n", pp);
            ///<将arr2数组写入arr1数组，为下一轮循环做准备
            for(k = 1; k < NODE_NUMBER; k++)
            {
                if(arr1[k] == 0)
                    arr1[k] = arr2[k];
            }

            loop--;///<循环次数减1
            printf("Loop no.%d\n",loop);
        }


        fclose(fp2);
    }

    return 0;
}
