#include"stdio.h"
#include"stdlib.h"
//cau 1
void nhap(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("ptu arr[%d]=",i);
		scanf("%d",arr+i);
	}
}
void xuat(int *arr, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%5d",*(arr+i));
}
//cau 2
int ktcp(int n)
{
	int i;
	for(i=1;i<=n;i++)
		if(i*i==n)
			return 1;
	return 0;		
}
int min_cp(int *arr,int n)
{
	int i, min,dem=0;
	for(i=0;i<n;i++)
		if(ktcp(*(arr+i))==1)
			{
				min=*(arr+i);
				dem++;
			}
	for(i=0;i<n;i++)
		if(dem==0)
			return 0;
		else if(ktcp(*(arr+i))==1&&min>*(arr+i))
				min=*(arr+i);
		return min;
}
int ktnt(int n)
{
	int i,dem=0;
	for(i=1;i<=n;i++)
		if(n%i==0)
			dem++;
	if(dem==2)
		return 1;
	else
		return 0;
}
int vtntcc(int *arr,int n)
{
	int i,vt;
	for(i=0;i<n;i++)
		if(ktnt(*(arr+i))==1)
			vt=i;
	return vt;	
}
void chen_x_vt(int *arr,int *n,int x,int vt)
{
	int i;
	for(i=*n;i>vt;i--)
		*(arr+i)=*(arr+i-1);
	*(arr+vt)=x;
	(*n)++;
}
void chen_mincp_ntcc(int *arr,int *n)
{
	int x=min_cp(arr,*n);
	int vt=vtntcc(arr,*n);
	chen_x_vt(arr,n,x,vt);		
}
//cau 3
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
	else if(n==sodao(n))
			return 1;
		 else
		 	return 0;
}
int max_dx(int *arr,int n)
{
	int i,max,dem=0;
	for(i=0;i<n;i++)
		if(ktdx(*(arr+i))==1)
		{
			max=*(arr+i);
			dem++;
		}
	for(i=0;i<n;i++)
		if(dem==0)
			return 0;
		else if(ktdx(*(arr+i))==1&&max<*(arr+i))
				max=*(arr+i);
		return max;
}
int maxmang(int *arr,int n)
{
	int i, max=*arr;
	for(i=1;i<n;i++)
		if(max<*(arr+i))
			max=*(arr+i);
	return max;
}
int vtmaxamang(int *arr,int n)
{
	int i,vt;
	for(i=0;i<n;i++)
		if(*(arr+i)==maxmang(arr,n))
			vt=i;
	return vt;
}
void chen_maxdx_maxmangcc(int *arr,int *n)
{
	int vt=vtmaxamang(arr,*n);
	int x = max_dx(arr,*n);
	chen_x_vt(arr,n,x,vt);	
}
//cau 4
int ktht(int n)
{
	int i, sum =0;
	for(i=1;i<n;i++)
		if(n%i==0)
			sum=sum+i;
	if(n==sum)
		return 1;
	else 
		return 0;	
}
int min_ht(int *arr,int n)
{
	int i, min,dem=0;
	for(i=0;i<n;i++)
		if(ktht(*(arr+i))==1)
			{
				min=*(arr+i);
				dem++;
			}
	for(i=0;i<n;i++)
		if(dem==0)
			return 0;
		else if(ktht(*(arr+i))==1&&min>*(arr+i))
				min=*(arr+i);
		return min;	
}
int min_sole(int *arr,int n)
{
	int i, min,dem=0;
	for(i=0;i<n;i++)
		if(*(arr+i)%2!=0)
			{
				min=*(arr+i);
				dem++;
			}
	for(i=0;i<n;i++)
		if(dem==0)
			return 0;
		else if(*(arr+i)%2!=0&&min>*(arr+i))
				min=*(arr+i);
		return min;
}
int vtminsoledt(int *arr,int n)
{
	int i,vt;
	for(i=0;i<n;i++)
		if(*(arr+i)==min_sole(arr,n))
		{
			vt=i;
			break;
		}	
	return vt;	
}
void chen_minht_minsoledt(int *arr,int *n)
{
	int x = min_ht(arr,*n);
	int vt = vtminsoledt(arr,*n);
	chen_x_vt(arr,n,x,vt);
}
//cau 5
void chen_x_vtdt(int *arr,int *n,int x)
{
	int vt=0;
	chen_x_vt(arr,n,x,vt);
}
//cau 6
void chen_x_saumaxmang(int *arr,int *n,int x)
{
	int vt = vtmaxamang(arr,*n)+1;
	chen_x_vt(arr,n,x,vt);
}
//cau7

int max_ht(int *arr,int n)
{
	int i, max,dem=0;
	for(i=0;i<n;i++)
		if(ktht(*(arr+i))==1)
			{
				max=*(arr+i);
				dem++;
			}
	for(i=0;i<n;i++)
		if(dem==0)
			return 0;
		else if(ktht(*(arr+i))==1&&max<*(arr+i))
				max=*(arr+i);
		return max; 
}
int vt_maxhtdt(int *arr,int n)
{
	int i, vt=0;
	for(i=0;i<n;i++)
		if(*(arr+i)==max_ht(arr,n))
		{
			vt=i;
			break;
		}
	return vt;
}
void chen_x_vtmaxhtdt(int *arr,int *n,int x)
{
	int vt = vt_maxhtdt(arr,*n);
	chen_x_vt(arr,n,x,vt);	
}
//cau 8
int min_dx(int *arr,int n)
{
	int i, min,dem=0;
	for(i=0;i<n;i++)
		if(ktdx(*(arr+i))==1)
			{
				min=*(arr+i);
				dem++;
			}
	for(i=0;i<n;i++)
		if(dem==0)
			return 0;
		else if(ktdx(*(arr+i))==1&&min>*(arr+i))
				min=*(arr+i);
		return min;	
}
int vt_mindxcc(int *arr,int n)
{
	int i,vt;
	for(i=0;i<n;i++)
		if(*(arr+i)==min_dx(arr,n))
			vt=i;
	return vt;
}
void chen_x_vtmindxcc(int *arr,int *n,int x)
{
	int vt = vt_mindxcc(arr,*n);
	chen_x_vt(arr,n,x,vt);	
}
//cau 9
int vt_nt_dt(int *arr, int n)
{
	int i,vt=0;
	for(i=0;i<n;i++)
		if(ktnt(*(arr+i))==1)
		{
			vt=i;
			break;
		}
	return vt;	
}
void chen_x_vtsauntdt(int *arr,int *n,int x)
{
	int vt = vt_nt_dt(arr,*n)+1;
	chen_x_vt(arr,n,x,vt);	 	
}
main()
{
//cau 1
	int i, n, *arr;
	do
	{
		printf("nhap so ptu cua mang n = ");
		scanf("%d",&n);
	}
	while(n<=0||n>100);
	arr=(int *)malloc(2*n*sizeof(int));
	nhap(arr,n);
	printf("mang ban vua nhap la :");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 2	
chen_mincp_ntcc(arr,&n);
	printf("mang sau khi chen so cp be nhat vao vi tri ntcc la:\n");
	xuat(arr,n);
	printf("\n");
//cau 3

chen_maxdx_maxmangcc(arr,&n);
	printf("mang sau khi chen so dx lon nhat vao vi tri so lon nhat cc la:\n");
	xuat(arr,n);
	printf("\n");
//cau 4
chen_minht_minsoledt(arr,&n);
	printf("mang sau khi chen so ht be nhat vao vi tri so le nho nhat la:\n");
	xuat(arr,n);
	printf("\n");
//cau 5
int x;
printf("Moi nhap vao ptu X bat ky : ");
scanf("%d",&x);
chen_x_vtdt(arr,&n,x);
printf("mang sau khi chen ptu %d vao vi tri dau tien la:\n",x);
	xuat(arr,n);
	printf("\n");
//cau 6
chen_x_saumaxmang(arr,&n,x);
printf("mang sau khi chen ptu %d vao phia sau ptu lon nhat trong mang la:\n",x);
	xuat(arr,n);
	printf("\n");
//cau 7
//loi xuat cuoi mang
chen_x_vtmaxhtdt(arr,&n,x);
printf("mang sau khi chen ptu %d vao vi tri so hoan thien lon nhat dau tien la:\n",x);
	xuat(arr,n);
	printf("\n");
//cau 8
chen_x_vtmindxcc(arr,&n,x);
printf("mang sau khi chen ptu %d vao vi tri so doi xung be nhat cuoi cung la:\n",x);
	xuat(arr,n);
	printf("\n");	
//cau 9	
chen_x_vtsauntdt(arr,&n,x);	
printf("mang sau khi chen ptu %d vao phia sau so nt dau tien la:\n",x);
	xuat(arr,n);
	printf("\n");	
	
free(arr);
}
/*
test n=15

493 7 13 33 6 81 493 36 25 31 23 29 66 28 121 


*/
