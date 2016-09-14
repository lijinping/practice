#include <iostream>
#include <algorithm>

using namespace std;

void HeapAdjust(int *a,int i,int size)  //调整堆 
{
    int lchild=2*i+1;       //i的左孩子节点序号 
    int rchild=2*i+2;     //i的右孩子节点序号 
    int max=i;            //临时变量 
    int nChild;

    for(;2*i+1<size;i=nChild)   //影响后续节点，循环处理 
    {
        //子结点的位置=2*（父结点位置）+1
        nChild=2*i+1;
        //得到子结点中较大的结点
        if(nChild<size-1&&a[nChild+1]>a[nChild])++nChild;
        //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if(a[i]<a[nChild])
        {
            int nTemp=a[i];
            a[i]=a[nChild];
            a[nChild]=nTemp; 
        }
        else 
        {
             break; //否则退出循环
        }
    }
    /*if(i<=size/2)          //如果i不是叶节点就不用进行调整 
    {
        if(lchild<size&&a[lchild]>a[max])
        {
            max=lchild;
        }    
        if(rchild<size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        
        cout << "*******" << endl;
        cout << "a[i]:" << a[i] << endl;
        cout << "a[lchild]:" << a[lchild] << endl;
        cout << "a[rchild]:" << a[rchild] << endl;
        
        cout << "####" << endl;
        if(max!=i)
        {
            int xx=a[max];
            a[max]=a[i];
            a[i]=xx;
        }
        

        for(int i=0;i<size;i++)
            cout<<a[i]<<" ";
    }   */     
}

void BuildHeap(int *a,int size)    //建立堆   从后往前全处理一次 
{
    int i;
    i=size/2;
    for(i=size/2;i>=0;i--)    //非叶节点最大序号值为size/2 
    {
        HeapAdjust(a,i,size);    
    }    
    
    cout << "xxxxxxxxxxxxxxxxxxx" << endl;
    for(int i=0;i<size;i++)
            cout<<a[i]<<" ";
} 

void HeapSort(int *a,int size)    //堆排序 
{
    int i;
    BuildHeap(a,size);
    for(i=size-1;i>=0;i--)
    {
        //cout<<a[1]<<" ";
        int xx=a[i];
        a[i]=a[0];
        a[0]=xx;           //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面 
        //BuildHeap(a,i);        //将余下元素重新建立为大顶堆 
        HeapAdjust(a,0,i);      //重新调整堆顶节点成为大顶堆   从前往后影响了哪个节点，就继续调整其子节点 （在堆建立的前提下） 
    }
} 

int main(int argc, char *argv[])
{
     int a[]={0,16,20,3,11,17,8,99,188,275};

    int size=10;

        HeapSort(a,size);
        cout << endl;
        for(int i=0;i<size;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    int x;
    cin>>x;
    return 0;
}
