#include"stdio.h"
#include"stdlib.h"
void nhap(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("ptu arr[%d]=",i);
		scanf("%d",arr+i);
	}	
}
void xuat(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%5d",*(arr+i));
} 
//cau 1
void Tach_chanle(int *arr,int *arr1,int *arr2,int *arr3,int n,int *n1,int *n2,int *n3)
{
	int i, num1=0,num2=0,num3=0;
	for(i=0;i<n;i++)
	{
		if(*(arr+i)==0)// mang chi chua so 0
		{
			*(arr3+num3)=*(arr+i);
			num3++;
		}else if(*(arr+i)%2==0)// mang chi chua cac so chan
				{
					*(arr1+num1)=*(arr+i);
					num1++;
				}
				else//mang chi chua so le
					{
						*(arr2+num2)=*(arr+i);
						num2++;
					}
	}
	*n1=num1;
	*n2=num2;
	*n3=num3;
	
}
//cau 2
int ktht(int n)
{
	if(n==0)
		return 0;
	int i,sum = 0;//khai bao biem sum
    for(i=1;i<=n/2;i++){
        if(n%i==0) 
            sum+=i;
    }
    if(sum==n) return 1; // tra ve true
    return 0;
}
int sodao(int n)
{
	int temp=0;
	while(n!=0)
	{
		temp=temp*10+n%10;
		n=n/10;
	}
	return temp;
}
int ktra_dx(int n)
{
	if(n<10)
		return 0;
	if(sodao(n)==n)
		return 1;
	else
		return 0;
}
void Tach_ht_dx(int *arr,int *arr4,int *arr5,int *arr6,int n,int *n4,int *n5,int *n6)
{
	int i;
	*n4=0,*n5=0,*n6=0;
	for(i=0;i<n;i++)
	{
		if(ktht(*(arr+i))==1)// mang chi chua so ht
		{
			*(arr4+*n4)=*(arr+i);
			(*n4)++;
		}
		if(ktra_dx(*(arr+i))==1)// mang chi chua cac so dx
		{
				*(arr5+*n5)=*(arr+i);
				(*n5)++;
		}
		if(ktht(*(arr+i))==0 && ktra_dx(*(arr+i))==0)//mang chi chua so ko la ht, dx
		{
				*(arr6+*n6)=*(arr+i);
				(*n6)++;
		}
	}
}
void Tach_amduong(int *arr,int *arr7,int *arr8,int n,int *n7,int *n8)
{
	int i;
	*n7=0,*n8=0;
	for(i=0;i<n;i++)
	{
		if(*(arr+i)<0)// mang chi chua so am
		{
			*(arr7+*n7)=*(arr+i);
			(*n7)++;
		}
		if(*(arr+i)>0)// mang chi chua cac so duong
		{
			*(arr8+*n8)=*(arr+i);
			(*n8)++;
		}
	}
}
main()
{
	int i,n,n1,n2,n3,n4,n5,n6,n7,n8;
	int *arr,*arr1,*arr2,*arr3,*arr4,*arr5,*arr6,*arr7,*arr8;
	/*
	arr1: mang so chan
	arr2: mang so le
	arr3: mang chua so 0
	arr4: mang so ht
	arr5: mang so dx
	arr6: mang cac so ko la ht,dx
	arr7: mang so am 
	arr8: mang so duong
	*/
	do
	{
		printf("Moi nhap vao so ptu cua mang : ");
		scanf("%d",&n);
	}
	while(n<=0||n>100);
	arr=(int *)malloc(2*n*sizeof(int));
	arr1=(int *)malloc(2*n*sizeof(int));	
	arr2=(int *)malloc(2*n*sizeof(int));
	arr3=(int *)malloc(2*n*sizeof(int));
	arr4=(int *)malloc(2*n*sizeof(int));
	arr5=(int *)malloc(2*n*sizeof(int));
	arr6=(int *)malloc(2*n*sizeof(int));
	arr7=(int *)malloc(2*n*sizeof(int));
	arr8=(int *)malloc(2*n*sizeof(int));
	printf("-------------------------------\n");
	nhap(arr,n);
	printf("mang ban vua nhap la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr,n);
	printf("\n--------------------------------------------------\n");
//cau 1
printf("Mang sau khi chia la:\n");
Tach_chanle(arr,arr1,arr2,arr3,n,&n1,&n2,&n3);
if(n1==0)
	printf("Mamg ko co so chan nao!!!\n");
else
{
	printf("mang chua toan so chan la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr1,n1);
	printf("\n--------------------------------------------------\n");
}
if(n2==0)
	printf("Mamg ko co so le nao!!!\n");
else
{
	printf("mang chua toan so le la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr2,n2);
	printf("\n--------------------------------------------------\n");
}
if(n3==0)
	printf("Mamg ko co so 0 nao!!!\n");
else
{
	printf("mang chua toan so 0 la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr3,n3);
	printf("\n--------------------------------------------------\n");
}
//cau 2	
Tach_ht_dx(arr,arr4,arr5,arr6,n,&n4,&n5,&n6);
if(n4==0)
	printf("Mang ko co so hoan thien nao!!!\n");
else
{
	printf("mang chua toan so hoan thien la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr4,n4);
	printf("\n--------------------------------------------------\n");	
}
if(n5==0)
	printf("Mang ko co so doi xung nao!!!\n");
else
{
	printf("mang chua toan so doi xung la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr5,n5);
	printf("\n--------------------------------------------------\n");	
}
if(n6==0)
	printf("Mang ko co so nao vua la so ht vua la so dx!!!\n");
else
{
	printf("mang chua cac so khong phai la so hoan thien hoac so doi xung la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr6,n6);
	printf("\n--------------------------------------------------\n");	
}	
// cau 3
Tach_amduong(arr,arr7,arr8,n,&n7,&n8);
if(n7==0)
	printf("Mang ko co so am nao!!!\n");
else
{
	printf("mang chua cac so am la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr7,n7);
	printf("\n--------------------------------------------------\n");	
}
if(n8==0)
	printf("Mang ko co so duong nao!!!\n");
else
{
	printf("mang chua cac so duong la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr8,n8);
	printf("\n--------------------------------------------------\n");	
}			
free(arr);
}
/*
test n=20
77. 2 3. 4 5 6 121. 8 -10. 100. 3. 12 13 -14. 28 3 17 -3. 29. 19.
x=3
*/
