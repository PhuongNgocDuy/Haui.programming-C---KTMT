#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"

struct tthh 
{
	char tensp[16];
	char nuocsanxuat[12];
	int soluong;
	float dongia,thanhtien;	
};
void nhap(struct tthh *sp, int n)
{
	int i;
	float price,a;
	for (i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nnhap ten san pham la: ");
		gets((sp+i)->tensp);
		fflush(stdin);
		printf("\nnuoc san xuat la: ");
		gets((sp+i)->nuocsanxuat);
		fflush(stdin);
		printf("\nnhap so luong: ");
		scanf("%d",&(sp+i)->soluong);
		fflush(stdin);
		printf("\nnhap don gia la: ");
		scanf("%f",&price);
		(sp+i)->dongia=price;
		a=(sp+i)->soluong * (sp+i)->dongia;
		(sp+i)->thanhtien=a;		
	}
}
void xuat(struct tthh *sp, int n)
{
	int i;
	printf("\n%-5s%-15s%-15s%-15s%-15s%-15s","STT","ten san pham","nuoc san xuat",
	"so luong","don gia","thanh tien");
	for (i=0;i<n;i++)
		printf("\n%-5d%-15s%-15s%-15d%-15.2f%-15.2f",i,(sp+i)->tensp,(sp+i)->nuocsanxuat,
		(sp+i)->soluong,(sp+i)->dongia,(sp+i)->thanhtien);
}
// cau 1: tim mat hang co so luong nho nhat trong mang
void timsp_soluong_min(struct tthh *sp ,int n)
{
	int i,min=(sp+0)->soluong,dem=0;
	for(i=0;i<n;i++)
		if((sp+i)->soluong < min)
		{
			min=((sp+i)->soluong);
			dem++;
		}
	for(i=0;i<n;i++)	
		if ((sp+i)->soluong==min)
			printf("\ncac san pham co so luong nho nhat la: %s",(sp+i)->tensp);
}
// cau 2:tim ten mat hang co gia cao nhat trong mang
void timsp_dongia_max(struct tthh *sp, int n)
{
	int i,max=(sp+0)->dongia,dem=0;
	for(i=0;i<n;i++)
		if((sp+i)->dongia > max)
		{
			max=(sp+i)->dongia;
			dem++;
		}
	for(i=0;i<n;i++)
		if((sp+i)->dongia==max)
			printf("\ncac san pham co don gia cao nhat la: %s ",(sp+i)->tensp);
}
// cau 3: tim mat hang co so tien thanh toan lon nhat trong mang
void timsp_thanhtien_max(struct tthh *sp, int n)
{
	int i,max=(sp+0)->thanhtien,dem=0;
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien > max)
		{
			max=(sp+i)->thanhtien;
			dem++;
		}
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien==max)
			printf("\ncac san pham co don gia cao nhat la: %s ",(sp+i)->tensp);
}
// cau 4: tim mat hang co so tien thanh toan nho nhat trong mang
void timsp_thanhtien_min(struct tthh *sp, int n)
{
	int i,min=(sp+0)->thanhtien,dem=0;
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien < min)
		{
			min=(sp+i)->thanhtien;
			dem++;
		}
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien==min)
			printf("\ncac san pham co don gia cao nhat la: %s ",(sp+i)->tensp);
}
// cau 5: tim vi tri cac mat hang co so tien thanh toan nho nhat trong mang 
void vt_sp_thanhtoan_min(struct tthh *sp , int n)
{
	int i,min=(sp+0)->thanhtien,dem=0;
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien < min)
			{
				min=(sp+i)->thanhtien;
				dem++;
			}
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien==min)
			printf("\nvi tri so tien thanh toan nho nhat la: %d",i);	
}
// cau 6: Tim vi tri cac mat hang la gao trong mang
void vt_sp_gao(struct tthh *sp, int n)
{
	int i;
	for(i=0;i<n;i++)
		if(stricmp((sp+i)->tensp,"gao")==0)
			printf("\n vi tri cac mat hang la gao la: %d",i);
}
// cau 7: tim vi tri mat hang pepsi xuat hien dau tien trong mang
void vt_sp_pepsi(struct tthh *sp,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(stricmp((sp+i)->tensp,"pepsi")==0)
		{
			printf("\nvi tri pepsi dau tien trong mang la: %d",i);
			break;
		}
}
// cau 8: dem so mat hang san xuat tai viet nam
void dem_sp_vietnam(struct tthh *sp, int n)
{
	int i,dem=0;
	for (i=0;i<n;i++)
		if(stricmp((sp+i)->nuocsanxuat,"viet nam")==0)
			dem++;
	if (dem==0)
		printf("\nkhong co mat hang nao cua viet nam: !!! ");
	else
		printf("\ntong so cac mat hang san xuat tai viet nam la: %d",dem);
}
// cau 9:dem cac mat hang co so luong nhieu nhat trong mang
int dem_soluong_max(struct tthh *sp, int n)
{
	int i,dem=0,max=(sp+0)->soluong;
	for(i=0;i<n;i++)
		if((sp+i)->soluong > max)
			max=(sp+i)->soluong;
	for(i=0;i<n;i++)
		if((sp+i)->soluong==max)
			dem++;	
	return dem;	
}
// cau 10:dem cac mat hang co so tien thanh toan nhieu nhat trong mang
int dem_thanhtoan_max(struct tthh *sp, int n)
{
	int i,dem=0,max=(sp+0)->thanhtien;
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien > max)
			max=(sp+i)->thanhtien;
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien==max)
			dem++;	
	return dem;	
}
// cau 11: tinh trung binh cong so tien thanh toan cac mat haang trong mang
void TBC_thanhtien(struct tthh *sp,int n)
{
	int i,sum=0,dem=0;
	for(i=0;i<n;i++)
	{
		sum+=(sp+i)->thanhtien;
		dem++;
	}
	printf("\nTBC thanh tien la: %.2f",(float)sum/dem);		
}
// cau 12: tinh trung binh cong cac mat hang la coca trong mang
void TBC_coca(struct tthh *sp, int n)
{
	int i,sum=0,dem=0;
	for (i=0;i<n;i++)
		if(stricmp((sp+i)->tensp,"coca")==0)
		{
			sum+=(sp+i)->thanhtien;
			dem++;
		}
	if (dem==0)
		printf("\nkhong co mat hang coca trong mang: !!! ");
	else
		printf("\nTBC coca trong mang La: %.2f",(float)sum/dem);		
}
//cau 13:tinh tong so tien phai thanh toan cho tat ca cac mat hang
float thanhtoan_all(struct tthh *sp, int n)
{
	int i;
	float sum=0;
	for (i=0;i<n;i++)			
		sum+=(sp+i)->thanhtien;
	return sum;
}
// cau 14: tinh tong so tien thanh toan cho mat hang la gao
void sum_thanhtoan_gao(struct tthh *sp, int n)
{
	int i;
	float sum=0,dem=0;
	for(i=0;i<n;i++)
		if(stricmp((sp+i)->tensp,"gao")==0)
			{
			sum+=(sp+i)->thanhtien;
			dem++;
			}
	if (dem==0) 
		printf("\nkhong co mat hang gao trong mang: !!! ");
	else
		printf("\ntong so tien thanh toan gao la: %f ",sum);
}
// >---------------------SAP XEP MANG THEO DIEU KIEN CHO TRUOC---------------------------< 
//cau 15: sap xep mang theo thu tu tang dan theo so tien phai thanh toan cac mat hang
void hoanvi(struct tthh *sp1,struct tthh *sp2)
{
	struct tthh temp;
	temp=*sp1;
	*sp1=*sp2;
	*sp2=temp;
}
void sapxep1(struct tthh *sp, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if ((sp+i)->thanhtien > (sp+j)->thanhtien)
				hoanvi(sp+i,sp+j);
}
// cau 16: sap xep mang theo thu tu tang dan theo so luong cac mat hang
void sapxep2(struct tthh *sp,int n)
{
	
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if ((sp+i)->soluong > (sp+j)->soluong)
				hoanvi(sp+i,sp+j);
}
// cau 17:sap xep mang theo tu tang dan theo don gia cac mat hang
void sapxep3(struct tthh *sp,int n)
{
	
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if ((sp+i)->dongia > (sp+j)->dongia)
				hoanvi(sp+i,sp+j);
}
// cau 18: sap xep mang sao cho cac mat hang la gao ve dau mang va cac mat hang khac ve cuoi mang
void sapxep4(struct tthh *sp, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(stricmp((sp+i)->tensp,"gao")!=0 && stricmp((sp+j)->tensp,"gao")==0 )
				hoanvi(sp+i,sp+j);
}
// cau 19: sap xep mang theo thu tu tang dan cac mat hang ve so luong tai viet nam
void sapxep5(struct tthh *sp, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(stricmp((sp+i)->nuocsanxuat,"vietnam")==0 && stricmp((sp+j)->nuocsanxuat,"vietnam")==0 
			&& (sp+i)->soluong > (sp+j)->soluong )
				hoanvi(sp+i,sp+j);
}
// >---------------------chen mang theo dieu kien cho truoc----------------------<
// cau 20: chen mat hag co so luong lon nhat vao vi tri k cua mang (dk 0<=k<=n)
void chen(struct tthh *sp, int *n, struct tthh spnew,int k)
{
	int i;
	for(i=*n;i>k;i--)
	*(sp+i)=*(sp+i-1);
	*(sp+k)=spnew;
	(*n)++;
}

void chen_soluong_max_k(struct tthh *sp, int *n,int k)
{
	struct tthh spnew;
	int i,max=(sp+0)->soluong;
	for(i=0;i<*n;i++)
		if((sp+i)->soluong > max)		
			max=(sp+i)->soluong;
	for(i=0;i<*n;i++)
		if((sp+i)->soluong==max)
		{
			spnew=*(sp+i);			
		}
		{
		chen(sp,n,spnew,k);
		}
}
// cau 20:chen mat hang san xuat tai viet nam dau tien vao vi tri cuoi cung cua mang
struct tthh spvndt(struct tthh *sp, int n)
{
	int i;
	struct tthh spvn;
	for (i=0;i<n;i++)
		if (stricmp((sp+i)->nuocsanxuat,"viet nam")==0)
			{
				spvn=*(sp+i);
				break;
			}
	return spvn;
}
void chenspvndt_cc(struct tthh *sp, int *n)
{
	struct tthh a;
	a = spvndt(sp,*n);
	chen(sp,n,a,*n-1);
}
// cau 21: chen phan tu nguyen to lon nhat vao vi tri dau tien cua mang (co van de)


//----------------------->XOA PHAN TU THEO DIEU KIEN CHO TRUOC-----------------//
// CAU 23: XOA CAC MAT HANG CO SO LUONG NHO NHAT TRONG MANG
int min_soluong(struct tthh *sp, int n)
{
	int i,min=(sp+0)->soluong;
	for(i=0;i<n;i++)
		if((sp+i)->soluong < min)
			min=(sp+i)->soluong;
	return min;
}
void xoa(struct tthh *sp ,int *n , int vt)
{
	int i;
	for(i=vt;i<*n-1;i++)
	*(sp+i)=*(sp+i+1);
	(*n)--;
}
void xoa_minsl(struct tthh *sp , int *n)
{
	int i,min=min_soluong(sp,*n);
	for (i=0;i<*n;i++)
		if((sp+i)->soluong==min)
			{
				xoa(sp,n,i);
				i--;
			}
	
}
void xoa_china(struct tthh *sp, int *n)
{
	int i;
	for (i=0;i<*n;i++)
		if(stricmp((sp+i)->nuocsanxuat,"china")==0)
		{
			xoa(sp,n,i);
			i--;
		}
}
// cau 25: xoa cac mat hang co ten la cocacola cua mang
void xoa_coca(struct tthh *sp, int *n)
{
	int i;
	for (i=0;i<*n;i++)
		if(stricmp((sp+i)->tensp,"coca")==0)
		{
			xoa(sp,n,i);
			i--;
		}
}
// cau 26:xoa mat hang co so luong lon nhat trong mang
int max_soluong(struct tthh *sp, int n)
{
	int i,max=(sp+0)->soluong;
	for(i=0;i<n;i++)
		if((sp+i)->soluong > max)
			max=(sp+i)->soluong;
	return max;
}
void xoa_maxsl(struct tthh *sp , int *n)
{
	int i,max=max_soluong(sp,*n);
	for (i=0;i<*n;i++)
		if((sp+i)->soluong==max)
			{
				xoa(sp,n,i);
				i--;
			}
	
}
// cau 27:xoa mat hang co tong thanh tien nho nhat
int min_thanhtien(struct tthh *sp, int n)
{
	int i,min=(sp+0)->thanhtien;
	for(i=0;i<n;i++)
		if((sp+i)->thanhtien < min)
			min=(sp+i)->thanhtien;
	return min;
}
void xoa_mintt(struct tthh *sp , int *n)
{
	int i,min=min_thanhtien(sp,*n);
	for (i=0;i<*n;i++)
		if((sp+i)->thanhtien==min)
			{
				xoa(sp,n,i);
				i--;
			}
	
}
//--------------------TACH MANG THEO DIEU KIEN CHO TRUOC-------------//
// CAU 28: TACH MANG THANH 2 MANG, MOT MANG CHUA MAT HANG BANH
// VA MOT MANG CHUA MAT HANG CON LAI
void tach1(struct tthh *sp,int n,struct tthh *arr1,int *n1,struct tthh *arr2,int *n2)
{
	int i;
	*n1=*n2=0;
	for (i=0;i<n;i++)
		if(stricmp((sp+i)->tensp,"banh")==0)
		{
			*(arr1+*n1)=*(sp+i);
			(*n1)++;
		}
		else
		{
			*(arr2+*n2)=*(sp+i);
			(*n2)++;
		}
}





main()
{
	struct tthh *sp,*arr1,*arr2;
	int n,n1,n2;
	do
	{
		printf("\nnhap n: ");
		scanf("%d",&n);
	}
	while(n<0 || n>20);
	sp=(struct tthh*)malloc(2*n*sizeof(struct tthh));
	arr1=(struct tthh*)malloc(2*n*sizeof(struct tthh));
	arr2=(struct tthh*)malloc(2*n*sizeof(struct tthh));
	
	nhap(sp,n);
	printf("\n----------------------------\n");
	printf("mang vua nhap la: ");
	xuat(sp,n);
	printf("\n-------------------------------\n");
	 cau 1: 
	timsp_soluong_min(sp,n);
	 cau 2:
	timsp_dongia_max(sp,n);
 	cau 3:
	timsp_thanhtien_max(sp,n);
	 cau 4: 
	timsp_thanhtien_min(sp,n);
	 cau 5:
	vt_sp_thanhtoan_min(sp,n);
	 cau 6:
	vt_sp_gao(sp,n);
	 cau 7: 
	vt_sp_pepsi(sp,n);
	 cau 8:
	dem_sp_vietnam(sp,n);
	 cau 9: 
	printf("\ndem mat hang co so luong max la: %d",dem_soluong_max(sp,n));
	 cau 10:
	printf("\ndem cac mat hang co thah toan max la: %d", dem_thanhtoan_max(sp,n));
 cau 11:
	TBC_thanhtien(sp,n);
	cau 12:
	TBC_coca(sp,n);
	cau 13:
	printf("\nso tien phai thanh toan cho tat ca cac mat hang la: %f",thanhtoan_all(sp,n));
	 cau 14:
	sum_thanhtoan_gao(sp,n);
	 cau 15: 
	sapxep1(sp,n);
 	sapxep2(sp,n);
	sapxep3(sp,n);
	sapxep4(sp,n);
	sapxep5(sp,n);
	int k;
	do
	{
		printf("\nnhap vi tri can chen k:");
		scanf("%d",&k);
	}
	while (k<0 || k>n);
	chen_soluong_max_k(sp,&n,k);
	printf("\nmang sau khi chen la: ");
	xuat(sp,n);
	printf("\nmang sau khi sap xep la : ");
	xuat(sp,n);
	chenspvndt_cc(sp,&n);
	printf("\nmang sau khi chen spvndt vao vi tri cc La: ");
	xuat(sp,n);
	 cau 22:
	printf("\nnhap 1 mat hang bat ky la: ");
	nhap(&a,1);
	chen(sp,&n,a,k);
	printf("\nmang sau khi chen la: ");
	xuat(sp,n);	
	cau 23: 
	xoa_minsl(sp,&n);
	cau 24:
	xoa_china(sp,&n);
	xoa_coca(sp,&n); 	
	xoa_maxsl(sp,&n);
	xoa_mintt(sp,&n);
	printf("\nmang sau khi xoa la: ");
	xuat(sp,n);	*/
	tach1(sp,n,arr1,&n1,arr2,&n2);
	if (n1==0)
		printf("\nmang khong co san pham la banh: !!! ");
	else
		printf("\ncac san pham banh trong mang la: ");
		xuat(arr1,n1);
	if (n2==0)
		printf("\ntrong mang chi co san pham la banh !!! ");
	else
		printf("\nmang chua cac san pham khong phai la banh: ");
		xuat(arr2,n2);
	free(sp);
	free(arr2);
	free(arr1);
}



