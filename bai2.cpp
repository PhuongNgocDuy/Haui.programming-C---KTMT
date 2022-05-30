/*
bai tap sap xep mang
test: n=15
-1 4 2 36 6 15 28 -25 31 -37 -23 81 13 41 -17


*/
#include"stdio.h"
#include"stdlib.h"
void nhap(int *arr, int n);
void xuat(int *arr, int n);
void hoanvi(int *num1, int *num2);
void sxep_giam(int *arr, int n);//cau 1
int ktnt(int n);
void sxep_tang_nt(int *arr,int n);//cau 2
void sxep_tang_le(int *arr, int n);//cau 3
void sxep_giam_chan(int *arr, int n);//cau 4
void sxep_chantang_legiam(int *arr, int n);//cau 5
void sxep_chandau_lecuoi(int *arr, int n);//cau 6
void sxep_ntdau(int *arr, int n);//cau 7(cac so ko la so nt xep cuoi)
int ktcp(int n);
void sxep_cpdau(int *arr,int n);//cau 8(cac so ko la so cp xep cuoi)
void sxep_amtangdau_duonggiamcuoi(int *arr, int n);//cau 9
int ktht(int n);
void sxep_ht_dau_giam(int *arr, int n);//cau 10(cac so ko la so ht thi xep cuoi tang dan)
main()
{
	int i, n, *arr;
	do
	{
		printf("nhap so ptu cua mang n = ");
		scanf("%d",&n);
	}
	while(n<=0||n>=100);
	arr=(int *)malloc(n*sizeof(int));
	nhap(arr,n);
	printf("mang ban vua nhap la :");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 1	
sxep_giam(arr,n);
	printf("mang sau khi dc sap xep theo thu tu giam dan la :");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 2
sxep_tang_nt(arr,n);
	printf("mang sau khi dc sap xep theo thu tu tang dan so nt la :");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 3
sxep_tang_le(arr,n);
printf("mang sau khi dc sap xep theo thu tu tang dan so le la :");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 4
sxep_giam_chan(arr,n);
printf("mang sau khi dc sap xep theo thu tu giam dan so chan la :");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 5
sxep_chantang_legiam(arr,n);
printf("mang sau khi dc sap xep theo thu tu tang dan so chan, giam dan so le la :");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 6
sxep_chandau_lecuoi(arr,n);
printf("mang sau khi dc sap xep theo ptu chan o dau mang va so le o cuoi mang la :");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 7
sxep_ntdau(arr,n);
printf("mang sau khi dc sap xep cac ptu nt o dau la:");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 8
sxep_cpdau(arr,n);
printf("mang sau khi dc sap xep cac ptu cp o dau la:");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 9
sxep_amtangdau_duonggiamcuoi(arr,n);
printf("mang sau khi dc sap xep theo thu tu am tang o dau va duong giam ve sau la:");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");
//cau 10
sxep_ht_dau_giam(arr,n);
printf("mang sau khi dc sap xep cac ptu hoan thien o dau la:");
	printf("\n-----------------------------------\n");
	xuat(arr,n);
	printf("\n-----------------------------------\n");


	

	
	
	
	
	
	free(arr);
}
void nhap(int *arr, int n)
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
void hoanvi(int *num1,int *num2)
{
	int temp;
	temp=*num1;
	*num1=*num2;
	*num2=temp;	
}
void sxep_giam(int *arr, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(arr+i)<*(arr+j))
				hoanvi(arr+i,arr+j);
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
void sxep_tang_nt(int *arr, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(ktnt(*(arr+i))==1 && ktnt(*(arr+j))==1 && *(arr+i) >  *(arr+j))
				hoanvi(arr+i,arr+j);
}
void sxep_tang_le(int *arr, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(arr+i)%2!=0 && *(arr+j)%2!=0 && *(arr+i)>*(arr+j))
				hoanvi(arr+i,arr+j);
}
void sxep_giam_chan(int *arr,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(arr+i)%2==0 && *(arr+j)%2==0 && *(arr+i)<*(arr+j))
				hoanvi(arr+i,arr+j);
}
void sxep_chantang_legiam(int *arr, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(arr+i)%2==0 && *(arr+j)%2==0 && *(arr+i)>*(arr+j)||*(arr+i)%2!=0 && *(arr+j)%2!=0 && *(arr+i)<*(arr+j))
				hoanvi(arr+i,arr+j);
}
void sxep_chandau_lecuoi(int *arr, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(arr+i)%2!=0 && *(arr+j)%2==0)
				hoanvi(arr+i,arr+j);
}
void sxep_ntdau(int *arr, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(ktnt(*(arr+i))!=1 && ktnt(*(arr+j))==1)
				hoanvi(arr+i,arr+j);
}
int ktcp(int n)
{
	int i;
	for(i=1;i<n;i++)
		if(i*i==n)
			return 1;
	return 0;
}
void sxep_cpdau(int *arr,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(ktcp(*(arr+i))!=1 && ktcp(*(arr+j))==1)
				hoanvi(arr+i,arr+j);
}
void sxep_amtangdau_duonggiamcuoi(int *arr, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(arr+i)>0 && *(arr+j)<0)
				hoanvi(arr+i,arr+j);// sap xep dau am cuoi duong
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(arr+i)<0 && *(arr+j)<0 && *(arr+i)>*(arr+j))
				hoanvi(arr+i,arr+j);// sap xep am tang
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(arr+i)>0 && *(arr+j)>0 && *(arr+i)<*(arr+j))
				hoanvi(arr+i,arr+j);// sap xep duong giam
}
int ktht(int n)// so ht la so co tong cac uoc bang chinh no. VD: 6 = 1+2+3
{	
	int i,sum = 0;//khai bao biem sum
    for(i=1;i<=n/2;i++)
	{
        if(n%i==0) 
            sum+=i;
    }
    if(sum==n) return 1; // tra ve true
    return 0;	
}
void sxep_ht_dau_giam(int *arr, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(ktht(*(arr+i))!=1 && ktht(*(arr+j))==1)
				hoanvi(arr+i,arr+j);
}

