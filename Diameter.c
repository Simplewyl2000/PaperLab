#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EDGES_MAX 100000011
#define Pse 0 //搜索引擎使用比率

struct graphArr{
    int u, v;
}Edges[EDGES_MAX];///<Edges[i]表示第i条边由节点u与节点v相连

int numberOfEdge=0;
int i,j,k;
int m,n;
float totaledge=0;
int total=4000;
int ans[4000][4000];
int cc=0;
float sum;
int main()
{
    memset(Edges, 0, sizeof(Edges));///<初始化graphArr数组
    FILE *fp1;
    if((fp1 = fopen("dblp.txt", "r")) == NULL)///<打开社交网络连通图的文件.txt，并写入graphArr数组
    {
        printf("Fail to open fp1!\n");
        return 0;
    }
    else
    {
        int x, y,sample;
        /// int z;
        numberOfEdge = 0;sample=0;
        while(!feof(fp1))
        {
            if(sample<=EDGES_MAX){
                fscanf(fp1, "%d%d", &x, &y);
                if(x>4000)
                    x=x%4000;
                if(y>4000)
                    y=y%4000;
                Edges[numberOfEdge].u = x;
                Edges[numberOfEdge].v = y;
                numberOfEdge++;
            }
            else break;
            sample++;

        }
    }
    fclose(fp1);


      int orig1,orig2;
      int original_edge = numberOfEdge;
          for(int loop=0;loop<Pse*original_edge;loop++)
          {
              orig1= rand() % (total);
               orig1+=1;
              orig2= rand() % (total);
               orig2+=1;
              Edges[numberOfEdge].u=orig1;
              Edges[numberOfEdge].v=orig2;
              numberOfEdge++;
          }


    for(i=0;i<total;i++)///初始化邻接矩阵
    {
        for(j=0;j<total;j++)
        {
            ans[i][j]=-1;
        }
        ans[i][i]=0;
    }

    for(i=0;i<numberOfEdge;i++)
    {

        m=Edges[i].u;
        n=Edges[i].v;
        ans[m][n]=1;///对邻接矩阵赋值
        //cc++;
    }

    for(k=0;k<total;k++)
    {
        for(i=0;i<total;i++)
        {
            for(j=0;j<total;j++)
            {
                if(ans[i][k]==-1||ans[k][j]==-1)
                    continue;
                if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
                    ans[i][j]=ans[i][k]+ans[k][j];
            }
        }
    }
    int num=total*total,index=0;
    int sum=0;
    int max=-1;
    for(i=0;i<total;i++)
    {
        for(j=0;j<total;j++)
        {
            if(ans[i][j]>max)
            {
                max=ans[i][j];
                sum+=ans[i][j];
            }
            if(ans[i][j]==-1)
                sum+=100;//不联通则将距离视为大整数100

        }
        printf("i: %d\n",i);
    }

    printf("diameter: %d\n",max);
    sum=(float)(sum/num);
    printf("average: %d\n",sum);
    return 0;

}
