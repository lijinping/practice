#include <iostream>
#include <algorithm>

using namespace std;

void HeapAdjust(int *a,int i,int size)  //������ 
{
    int lchild=2*i+1;       //i�����ӽڵ���� 
    int rchild=2*i+2;     //i���Һ��ӽڵ���� 
    int max=i;            //��ʱ���� 
    int nChild;

    for(;2*i+1<size;i=nChild)   //Ӱ������ڵ㣬ѭ������ 
    {
        //�ӽ���λ��=2*�������λ�ã�+1
        nChild=2*i+1;
        //�õ��ӽ���нϴ�Ľ��
        if(nChild<size-1&&a[nChild+1]>a[nChild])++nChild;
        //����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
        if(a[i]<a[nChild])
        {
            int nTemp=a[i];
            a[i]=a[nChild];
            a[nChild]=nTemp; 
        }
        else 
        {
             break; //�����˳�ѭ��
        }
    }
    /*if(i<=size/2)          //���i����Ҷ�ڵ�Ͳ��ý��е��� 
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

void BuildHeap(int *a,int size)    //������   �Ӻ���ǰȫ����һ�� 
{
    int i;
    i=size/2;
    for(i=size/2;i>=0;i--)    //��Ҷ�ڵ�������ֵΪsize/2 
    {
        HeapAdjust(a,i,size);    
    }    
    
    cout << "xxxxxxxxxxxxxxxxxxx" << endl;
    for(int i=0;i<size;i++)
            cout<<a[i]<<" ";
} 

void HeapSort(int *a,int size)    //������ 
{
    int i;
    BuildHeap(a,size);
    for(i=size-1;i>=0;i--)
    {
        //cout<<a[1]<<" ";
        int xx=a[i];
        a[i]=a[0];
        a[0]=xx;           //�����Ѷ������һ��Ԫ�أ���ÿ�ν�ʣ��Ԫ���е�����߷ŵ������ 
        //BuildHeap(a,i);        //������Ԫ�����½���Ϊ�󶥶� 
        HeapAdjust(a,0,i);      //���µ����Ѷ��ڵ��Ϊ�󶥶�   ��ǰ����Ӱ�����ĸ��ڵ㣬�ͼ����������ӽڵ� ���ڶѽ�����ǰ���£� 
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
