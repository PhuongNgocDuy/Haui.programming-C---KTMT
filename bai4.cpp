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
//cau 1 xoa ptu tai vi tri le
void xoa(int *arr, int *n, int vt)
{
	int i;
	for(i=vt;i<*n-1;i++)
	*(arr+i)=*(arr+i+1);
	(*n)--;
}
void xoa_vtle(int *arr,int *n)
{
	int i;
	for(i=0;i<*n;i++)
		if(*(arr+i)%2!=0)
		{
			xoa(arr,n,i);
			i--;
		}
}
//cau 2	xoa ptu co gia tri lon nhat
int maxmang(int *arr,int n)
{
	int i, max=*arr;
	for(i=0;i<n;i++)
		if(max<*(arr+i))
			max=*(arr+i);
	return max;
}
void xoa_maxmang(int *arr,int *n)
{
	int i;
	int vt = maxmang(arr,*n);
	for(i=0;i<*n;i++)
		if(*(arr+i)==vt)
		{
			xoa(arr,n,i);
			i--;
		}
}
//cau 3	xoa tat ca cac ptu co gia tri nho hon X (x dc nhap tu ban phim)
void xoa_smaller_x(int *arr,int *n, int x)
{
	int i;
	for(i=0;i<*n;i++)
		if(*(arr+i)<x)
		{
			xoa(arr,n,i);
			i--;
		}
}
//cau 4	xoa cac ptu co gia tri nho nhat trong mang
int minmang(int *arr,int n)
{
	int i, min = *arr;
	for(i=0;i<n;i++)
		if(min>*(arr+i))
			min=*(arr+i);
	return min;
}
void xoa_minmang(int *arr,int *n)
{
	int i;
	int min = minmang(arr,*n);
	for(i=0;i<*n;i++)
		if(*(arr+i)==min)
		{
			xoa(arr,n,i);
			i--;
		}
}
//cau 5	xoa ptu chan dau tien
void xoa_chandt(int *arr,int *n)
{
	int i;
	for(i=0;i<*n;i++)
	{
		if(*(arr+i)%2==0)
		{
			xoa(arr,n,i);
			i--;
		}
		break;
	}
}
//cau 6	xoa ptu chinh phuong lon nhat
int ktcp(int n)
{
	int i;
	for(i=0;i<=n;i++)
		if(i*i==n)
			return 1;
	return 0;
}
int maxcp(int *arr,int n)
{
	int i, max,dem=0;
	for(i=0;i<n;i++)
		if(ktcp(*(arr+i))==1)
			{
				max=*(arr+i);
				dem++;
			}
	for(i=0;i<n;i++)
		if(dem==0)
			return 0;
		else if(ktcp(*(arr+i))==1&&max<*(arr+i))
				max=*(arr+i);
		return max;	
}
void xoa_maxcp(int *arr,int *n)
{
	int i;
	int max=maxcp(arr,*n);
	for(i=0;i<*n;i++)
		if(*(arr+i)==max)
		{
			xoa(arr,n,i);
			i--;
		}
}
//cau 7 xoa tat ca cac ptu doi xung trong mang
int sodao(int n)
{
	int temp=0;
	do
	{
		temp=temp*10+n%10;
		n=n/10;
	}
	while(n!=0);
	return temp;
}
int ktdx(int n)
{
	if(n<10)
		return 0;
	if(n==sodao(n))
		return 1;
	return 0;
}
int tontai_dx(int *arr,int n)
{
	int i, dem = 0;
	for(i=0;i<n;i++)
		if(ktdx(*(arr+i))==1)
			dem++;
	if(dem!=0)
		return 1;
	return 0;
}
void xoa_dx(int *arr,int *n)
{
	int i;
	for(i=0;i<*n;i++)
		if(ktdx(*(arr+i))==1)
		{
			xoa(arr,n,i);
			i--;
		}
}
//cau 8	xoa tat ca cac ptu hoan thien trong mang
int tontai_ht(int *arr,int n)
{
	int i, dem = 0;
	for(i=0;i<n;i++)
		if(ktht(*(arr+i))==1)
			dem++;
	if(dem!=0)
		return 1;
	return 0;
}
int ktht(int n)
{
	int i, sum =0;
	for(i=1;i<n;i++)
		if(n%i==0)
			sum=sum+i;
	if(n==sum)
		return 1;
	return 0;
}
void xoa_ht(int *arr,int *n)
{
	int i;
	for(i=0;i<*n;i++)
		if(ktht(*(arr+i))==1)
		{
			xoa(arr,n,i);
			i--;
		}
}
main()
{	
	int n, i, *arr;
	do
	{
		printf("Moi nhap vao so ptu cua mang : ");
		scanf("%d",&n);
	}
	while(n<=0||n>100);
	arr=(int *)malloc(n*sizeof(int));
	printf("-------------------------------\n");
	nhap(arr,n);
	printf("mang ban vua nhap la :");
	printf("\n--------------------------------------------------\n");
	xuat(arr,n);
	printf("\n--------------------------------------------------\n");
//cau 1
xoa_vtle(arr,&n);
printf("mang sau khi xoa cac ptu le la :");
printf("\n--------------------------------------------------\n");
xuat(arr,n);
printf("\n--------------------------------------------------\n");	
//cau 2
if(n==0)
	printf(" ");
else
{
	xoa_maxmang(arr,&n);
	printf("mang sau khi xoa cac ptu lon nhat la :");
	printf("\n-------------------------------\n");
	xuat(arr,n);
	printf("\n-------------------------------\n");	
}
//cau 3
if(n==0)
	printf(" ");
else
{
	int x;
	printf("moi nhap vao 1 so X bat ky :");
	scanf("%d",&x);
	xoa_smaller_x(arr,&n,x);
	printf("mang sau khi xoa cac ptu nho hon %d la :",x);
	printf("\n-------------------------------\n");
	xuat(arr,n);
	printf("\n-------------------------------\n");	
}
//cau 4
if(n==0)
	printf(" ");
else
{
	xoa_minmang(arr,&n);
	printf("mang sau khi xoa cac ptu nho nhat la :");
	printf("\n-------------------------------\n");
	xuat(arr,n);
	printf("\n-------------------------------\n");	
}
//cau 5
if(n==0)
	printf(" ");
else
{
	xoa_chandt(arr,&n);
	printf("mang sau khi xoa ptu chan dau tien la :");
	printf("\n-------------------------------\n");
	xuat(arr,n);
	printf("\n-------------------------------\n");	
}
//cau 6
if(n==0)
	printf(" ");
else
{
	if(maxcp(arr,n)==0)
		printf("Mang khong co ptu cp nao!!!\n");
	else
	{
		xoa_maxcp(arr,&n);
		printf("mang sau khi xoa cac ptu cp lon nhat la :");
		printf("\n-------------------------------\n");
		xuat(arr,n);
		printf("\n-------------------------------\n");
	}	
}
//cau 7
if(n==0)
	printf(" ");
else
{
	if(tontai_dx(arr,n)==0)
		printf("Mang khong co ptu doi xung nao!!!\n");
	else
	{
		xoa_dx(arr,&n);
		printf("mang sau khi xoa cac ptu doi xung la :");
		printf("\n-------------------------------\n");
		xuat(arr,n);
		printf("\n-------------------------------\n");
	}		
}
//cau 8
if(n==0)
	printf(" ");
else
{
	if(tontai_ht(arr,n)==0)
		printf("Mang khong co ptu hoan thien nao!!!\n");
	else
	{
		xoa_ht(arr,&n);
		printf("mang sau khi xoa cac ptu hoan thien la :");
		printf("\n-------------------------------\n");
		xuat(arr,n);
		printf("\n-------------------------------\n");
	}		
}
if(n==0)
	printf("\nMang khong con ptu nao!!!\n\n");
else
	printf(" ");	

free(arr);	
}
/*
test n=20
91 2 36 23 212 16 13 64 27 0 53 4 8 88 49 336 998 6 100 28
*/
