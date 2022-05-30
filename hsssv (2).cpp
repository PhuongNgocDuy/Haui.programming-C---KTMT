#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"conio.h"

struct hssv 
{
	char hovaten[16];
	char masinhvien[16];
	char lop[10];
	float diem_tb;
};
void nhap(struct hssv *hs, int n)
{
	int i;
	float d_tb;
	for (i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nnhap ho va ten sinh vien: ");
		gets((hs+i)->hovaten);
		fflush(stdin);
		printf("\nnhap ma sinh vien la: ");
		gets((hs+i)->masinhvien);
		fflush(stdin);
		printf("\nnhap lop hoc la: ");
		gets((hs+i)->lop);
		fflush(stdin);
		printf("\nnhap diem trung binh tich luy la: ");
		scanf("%f",&d_tb);
		(hs+i)->diem_tb=d_tb;
	}
}
void xuat(struct hssv *hs, int n)
{
	int i;
	printf("\n%-5s%-15s%-15s%-15s%-15s","STT","ho va ten","ma sinh vien","lop hoc","dtb");
	for(i=0;i<n;i++)
		printf("\n%-5d%-15s%-15s%-15s%-15.2f",i,(hs+i)->hovaten,(hs+i)->masinhvien,(hs+i)->lop,(hs+i)->diem_tb);
}
// cau 1: hien thi danh sach cac sinh vien co diem tbtl cao nhat
void ht_sv_tbtl_max(struct hssv *hs, int n)
{
	int i;
	float max=(hs+0)->diem_tb;
	for(i=0;i<n;i++)
		if((hs+i)->diem_tb > max)
			max=(hs+i)->diem_tb;
	for(i=0;i<n;i++)
		if((hs+i)->diem_tb==max)
			printf("\n%-5d%-15s%-15s%-15s%-15.2f",i,(hs+i)->hovaten,(hs+i)->masinhvien,(hs+i)->lop,(hs+i)->diem_tb);
}
// cau 2:hien thi vi tri cac sinh vien co diem tbtl thap nhat
void vt_sv_tbtl_min(struct hssv *hs, int n)
{
	int i;
	float min=(hs+0)->diem_tb;
	for (i=0;i<n;i++)
		if((hs+i)->diem_tb < min)
			min=(hs+i)->diem_tb;
	for (i=0;i<n;i++)
		if((hs+i)->diem_tb==min)
			printf("\nvi tri sinh vien co tbtl min la: %d",i);
}
// cau 3: hien thi danh sach cac sinh vien hoc lop KTMT1
void ht_sv_KTMT1(struct hssv *hs, int n)
{
	int i;
	for(i=0;i<n;i++)
		if(stricmp((hs+i)->lop,"ktmt1")==0)
			printf("\n%-5d%-15s%-15s%-15s%-15.2f",i,(hs+i)->hovaten,(hs+i)->masinhvien,(hs+i)->lop,(hs+i)->diem_tb);
}
// cau 4: hien thi danh sach cac sinh vien co ma sinh vien bat dau la 2019
void ht_sv_2019(struct hssv *hs, int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strncmp((hs+i)->masinhvien,"2019",4)==0)
				printf("\n%-5d%-15s%-15s%-15s%-15.2f",i,(hs+i)->hovaten,(hs+i)->masinhvien,(hs+i)->lop,(hs+i)->diem_tb);
}
// cau 5: sap xep theo thu tu tang dan diem trung binh tich luy
void hoanvi(struct hssv *hs1,struct hssv *hs2)
{
	struct hssv temp;
	temp=*hs1;
	*hs1=*hs2;
	*hs2=temp;
}
void sapxep1(struct hssv *hs, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if((hs+i)->diem_tb > (hs+j)->diem_tb)
				hoanvi(hs+i,hs+j);
}
// cau 6: sap xep sao cho cac sinh vien ktmt1 ve dau danh sach cac sinh vien lop khac ve cuoi danh sach
void sapxep2(struct hssv *hs , int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(stricmp((hs+i)->lop,"ktmt1")!=0 && stricmp((hs+j)->lop,"ktmt1")==0 )
				hoanvi(hs+i,hs+j);
}
// cau 7: sap xep sao cho cac sinh vien ktmt1 ve dau danh sach theo thu tu tang dan diem tbtl
void sapxep3(struct hssv *hs , int n)
{	
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(stricmp((hs+i)->lop,"ktmt1")!=0 && stricmp((hs+j)->lop,"ktmt1")==0)
				hoanvi(hs+i,hs+j);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
				if(stricmp((hs+i)->lop,"ktmt1")==0 && stricmp((hs+j)->lop,"ktmt1")==0 && (hs+i)->diem_tb > (hs+j)->diem_tb )
					hoanvi(hs+i,hs+j);
}
// cau 8: sap xep sao cho cac sinh vien ktmt1 ve cuoi danh sach theo thu tu tang dan ma sinh vien
void sapxep4(struct hssv *hs , int n)
{	
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(stricmp((hs+i)->lop,"ktmt1")==0 && stricmp((hs+j)->lop,"ktmt1")!=0)
				hoanvi(hs+i,hs+j);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
				if(stricmp((hs+i)->lop,"ktmt1")==0 && stricmp((hs+j)->lop,"ktmt1")==0 && (hs+i)->masinhvien > (hs+j)->masinhvien )
					hoanvi(hs+i,hs+j);
}
// cau 9: nhap thong tin cua mot sinh vien ,chen thong tin do vao vi tri k bat ky nhap vao (0<=k<=n)
void chen(struct hssv *hs , int *n,struct hssv hsnew,int k)
{
	int i;
	for(i=*n;i>k;i--)
	*(hs+i)=*(hs+i-1);
	*(hs+k)=hsnew;
	(*n)++;
}
// cau 10: nhap thong tin cua mot sinh vien chen thong tin cua sinh vien do vao vi tri dau mang
// cau 11:nhap thong tin cua sinh vien chen thong tin do vao vi tri cuoi cung cua mang
// cau 12: nhap thong tin cua 1 sinh vien,chen thong tin cua sinh vien do vao vi tri cua sv co diem tbtl cao nhat
int vt_tbtlmax(struct hssv *hs, int n)
{
	int i;
	float max=(hs+0)->diem_tb;
	for(i=0;i<n;i++)
		if((hs+i)->diem_tb > max)
			max=(hs+i)->diem_tb;
	for (i=0;i<n;i++)
		if((hs+i)->diem_tb == max)
			return i;	
}
void chensv_vt_tbtlmax(struct hssv *hs , int *n,struct hssv a)
{
	vt=vt_tbtlmax(hs,*n);
	chen(hs,n,a,vt);
}
// cau 13: tim vi tri cua sinh vien co diem trung binh tich luy cao nhat cuoi cung
void vt_tbtl_max_cc(struct hssv *hs, int n)
{
	int i,vt;
	float max=(hs+0)->diem_tb;
	for (i=0;i<n;i++)
		if((hs+i)->diem_tb > max)
			max=(hs+i)->diem_tb;
	for (i=0;i<n;i++)
		if((hs+i)->diem_tb==max)
			{
				vt=i;

			}
	printf("\nvi tri tbtl max cuoi cung la: %d",vt);
}
// cau 14: hien thi danh sach sinh vien co diem trung binh tich luy < 1.0
void ht_tbtl_nhohon1(struct hssv *hs,int n)
{
	int i;
	for(i=0;i<n;i++)
		if((hs+i)->diem_tb < 1)
			printf("\n%-5d%-15s%-15s%-15s%-15.2f",i,(hs+i)->hovaten,(hs+i)->masinhvien,(hs+i)->lop,(hs+i)->diem_tb);
}
// cau 15: hien thi danh sach sihn vien co hoc bong (tbtl>3.75)
void ht_tbtl_lonhon375(struct hssv *hs,int n)
{
	int i;
	for(i=0;i<n;i++)
		if((hs+i)->diem_tb > 3.75)
			printf("\n%-5d%-15s%-15s%-15s%-15.2f",i,(hs+i)->hovaten,(hs+i)->masinhvien,(hs+i)->lop,(hs+i)->diem_tb);
}
// cau 16: tim vi tri cua sinh vien ktmt1 dau tien trong mang
void vt_svktmt1_dt(struct hssv *hs, int n)
{
	int i,vt;
	for(i=0;i<n;i++)
		if(stricmp((hs+i)->lop,"ktmt1")==0)
			{
				vt=i;
				break;
			}
	printf("\nvi tri sinh vien ktmt1 dau tien la: %d ",vt);
}
/*// cau 17:nhap vao thong tin 1 sv,kiem tra va hien thi ra danh sach cac sinh vien co cung lop vs sv do
void ht1(struct hssv *hs, int n)
{
	struct hssv a;
	nhap(&a,1);
	int i;
	for (i=0;i<n;i++)
		if ( (hs+i)->lop == a->lop )
			printf("\n%-5d%-15s%-15s%-15s%-15.2f",i,(hs+i)->hovaten,
			(hs+i)->masinhvien,(hs+i)->lop,(hs+i)->diem_tb);
}*/
// cau 18: xao tat ca sinh vien co diem tbtl nho hon 1
void xoa(struct hssv *hs, int *n,int vt)
{
	int i;
	for(i=vt;i<*n-1;i++)
	*(hs+i)=*(hs+i+1);
	(*n)--;	
}	
void xoa_sv_tbtl_nhohon1(struct hssv *hs ,int *n)
{
	int i;
	for(i=0;i<*n;i++)
		if((hs+i)->diem_tb < 1.0)
		{
			xoa(hs,n,i);
			i--;
		}
}
// cau 19: xoa 1 sv o vi tri k bat ky
// cau 20:xoa cac sinh vien co diem trung binh cao nhat
int dtb_max(struct hssv *hs, int n)
{
	int i;
	float max=(hs+0)->diem_tb;
	for(i=0;i<n;i++)
		if ((hs+i)->diem_tb > max )
			max=(hs+i)->diem_tb;
	return max;
}
void xoa_max_tbtl(struct hssv *hs, int *n)
{
	int i;
	float max=dtb_max(hs,*n);
	for(i=0;i<*n;i++)
		if((hs+i)->diem_tb == max)
		{
			xoa(hs,n,i);
			i--;
		}
}
// cau 21: tach thanh cac mang sau:mot mang chua sv ktmt1 mot mang chua sv ktmt2
void tach_ktmt1_ktmt2(struct hssv *hs,int n,struct hssv *arr1,int *n1,struct hssv *arr2,int *n2)
{
	int i;
	*n1=*n2=0;
	for(i=0;i<n;i++)
	{
		if(stricmp((hs+i)->lop,"ktmt1")==0)
		{
			*(arr1+*n1)=*(hs+i);
			(*n1)++;
		}
		if(stricmp((hs+i)->lop,"ktmt2")==0)
		{
			*(arr2+*n2)=*(hs+i);
			(*n2)++;
		}
	}
}
// cau 22:tach mang thanh mang cac sinh vien co diem tbtl >=2 va mang chua cac sinh vien con lai
void tach2(struct hssv *hs,int n,struct hssv *arr3,int *n3,struct hssv *arr4,int *n4)
{
	int i;
	*n3=*n4=0;
	for(i=0;i<n;i++)
	{
		if((hs+i)->diem_tb >=2)
		{
			*(arr3+*n3)=*(hs+i);
			(*n3)++;
		}
		else
		{
			*(arr4+*n4)=*(hs+i);
			(*n4)++;
		}
	}
 } 
// cau 23:tach thanh hai mang mot mang chua cac sinh vien dat hoc bong (tbtl >=3.75) va mang cac sinh vien khong nhan dc hoc bong
void tach3(struct hssv *hs,int n,struct hssv *arr5,int *n5,struct hssv *arr6,int *n6)
{
	int i;
	*n5=*n6=0;
	for(i=0;i<n;i++)
	{
		if((hs+i)->diem_tb >=3.75)
		{
			*(arr5+*n5)=*(hs+i);
			(*n5)++;
		}
		else
		{
			*(arr6+*n6)=*(hs+i);
			(*n6)++;
		}
	}
 } 



main()
{
	struct hssv *hs,a,*arr1,*arr2,*arr3,*arr4,*arr5,*arr6;
	int n,n1,n2,n3,n4,n5,n6;
	do
	{
		printf("\nnhap so sinh vien trong lop: ");
		scanf("%d",&n);
	}
	while(n<0 || n>20);
	hs=(struct hssv*)malloc(2*n*sizeof(struct hssv));
/*	arr1=(struct hssv*)malloc(2*n*sizeof(struct hssv));
	arr2=(struct hssv*)malloc(2*n*sizeof(struct hssv));
	arr3=(struct hssv*)malloc(2*n*sizeof(struct hssv));
	arr4=(struct hssv*)malloc(2*n*sizeof(struct hssv));
	arr5=(struct hssv*)malloc(2*n*sizeof(struct hssv));
	arr6=(struct hssv*)malloc(2*n*sizeof(struct hssv));	
	nhap(hs,n);
	printf("\nmang vua nhap la: ");
	xuat(hs,n);
// 	cau 1:
	printf("\n-----------------------------------------\n");
	printf("\nDanh sach sinh vien co diem tbtl cao nhat la: ");
	printf("\n%-5s%-15s%-15s%-15s%-15s","STT","ho va ten","ma sinh vien","lop hoc","dtb");
	ht_sv_tbtl_max(hs,n);
// 	cau 2:
	printf("\n-----------------------------------------\n");
	vt_sv_tbtl_min(hs,n);
// 	cau 3:
	printf("\n-----------------------------------------\n");
	printf("\nDanh sach sinh vien hoc KTMT1 la: ");
	printf("\n%-5s%-15s%-15s%-15s%-15s","STT","ho va ten","ma sinh vien","lop hoc","dtb");
	ht_sv_KTMT1(hs,n);
// 	cau 4:
	printf("\n-----------------------------------------\n");
	printf("\nDanh sach sinh vien co ma sinh vien bat dan la 2019 la: ");
	ht_sv_2019(hs,n);
// 	cau 5:
	sapxep1(hs,n);
	sapxep2(hs,n);
	sapxep3(hs,n);
	sapxep4(hs,n);
	printf("\nmang sau khi sap xep la: ");
	xuat(hs,n);
//	 cau 9: 
	nhap(&a,1);
	int k;
	printf("\nnhap vi tri can chen k: ");
	scanf("%d",&k);
	chen(hs,&n,a,k);
	printf("\nmang sau khi chen la: ");
	xuat(hs,n);
//	 cau 10:
	nhap(&a,1);
	chen(hs,&n,a,0);
	printf("\nmang sau khi chen la: ");
	xuat(hs,n);
//	cau 11:
	nhap(&a,1);
	chen(hs,&n,a,n-1);
	printf("\nmang sau khi chen la: ");
	xuat(hs,n);
//	cau 12: 	
	chensv_vt_tbtlmax(hs,&n,a);
	printf("\nmang sau khi chen la: ");
	xuat(hs,n);
//	cau 13:
	vt_tbtl_max_cc(hs,n);
//	cau 14
	printf("\n-----------------------------------------\n");
	printf("\nDanh sach sinh vien co diem tbtl <1 la: ");
	printf("\n%-5s%-15s%-15s%-15s%-15s","STT","ho va ten","ma sinh vien","lop hoc","dtb");
	ht_tbtl_nhohon1(hs,n);
// 	cau 15:
	printf("\n-----------------------------------------\n");
	printf("\nDanh sach sinh vien duoc hoc bong la: ");
	printf("\n%-5s%-15s%-15s%-15s%-15s","STT","ho va ten","ma sinh vien","lop hoc","dtb");
	ht_tbtl_lonhon375(hs,n);
//	cau 16:
	vt_svktmt1_dt(hs,n);
/*	cau 17: chuongg trinh loi~~~~~~~~~~~
	printf("\n-----------------------------------------\n");
	printf("\nDanh sach sinh vien cung lop la: ");
	printf("\n%-5s%-15s%-15s%-15s%-15s","STT","ho va ten","ma sinh vien","lop hoc","dtb");
	ht1(hs,n);*/
	// cau 18:
//	xoa_sv_tbtl_nhohon1(hs,&n);
//	printf("\nmang sau khi xoa la: ");
//	xuat(hs,n);
	// cau 19:
//	int k;
/*	do
	{
		printf("\n nhap vi tri can xoa k: ");
		scanf("%d",&k);
	}
	while(k<0 || k>=n);
	xoa(hs,&n,k);
	printf("\nmang sau khi xoa la: ");
	xuat(hs,n);
// 	cau 19:
	xoa_max_tbtl(hs,&n);
	printf("\nmang sau khi xoa la: ");
	xuat(hs,n);
	tach_ktmt1_ktmt2(hs,n,arr1,&n1,arr2,&n2);
	if (n1==0)
		printf("\nmang khong co sinh vien lop ktmt 1: !!!");
	else
	{
		printf("\nmang gom cac sv ktmt1 la: ");
		xuat(arr1,n1);
	}
	if (n2==0)
		printf("\nmang khong co sinh vien lop ktmt 2: !!!");
	else
	{
		printf("\nmang gom cac sv ktmt2 la: ");
		xuat(arr2,n2);
	}
//	ht1(hs,n);
//	cau 22:
	tach2(hs,n,arr3,&n3,arr4,&n4);
	if (n3==0)
		printf("\nmang khong co sinh vien nao dc >=3.75: !!!");
	else
		{
			printf("\nmang gom cac sinh vien dc diem >=3.75 la: ");
			xuat(arr3,n3);
		}
	if (n4==0)
		printf("\nmang khong co sinh vien nao: !!!");
	else
		{
			printf("\nmang gom cac sinh vien con lai la: ");
			xuat(arr4,n4);
		}
//	 cau 23:
	tach3(hs,n,arr5,&n5,arr6,&n6);
	if (n5==0)
		printf("\nmang khong co sinh vien nao duoc hoc bong !!!");
	else
		{
			printf("\nmang gom cac sinh vien dc hoc bong la: ");
			xuat(arr5,n5);
		}
	if (n6==0)
		printf("\nmang khong co sinh vien nao: !!!");
	else
		{
			printf("\nmang gom cac sinh vien khong duoc hoc bong la: ");
			xuat(arr6,n6);
		}
	free(hs);
	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
	free(arr6);	*/
	nhap(&a,1);
	chen(hs,&n,a,n-1);
	printf("\nmang sau khi chen la: ");
	xuat(hs,n);	
	free(hs);	
}












