#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"

struct hssv{
	char hoten[21];
	char masv[21];
	int dtb;
};

struct node{
	hssv data;
	struct node *pNext;
};
typedef struct node NODE;

struct list{
	node *pHead;
	node *pTail;
};
typedef struct list LIST;

void create(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *create_node(hssv hs)
{
	node *p = new NODE;
	p->pNext = NULL;
	p->data = hs;
	return p;	
}

void add_l(LIST &l,NODE *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail =p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void add_f(LIST &l,NODE *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead =p;
	}
}
void nhap(hssv &hs)
{
	fflush(stdin);
	printf("\nnhap ho va ten sinh vien la: ");
	gets(hs.hoten);
	
	fflush(stdin);
	printf("\nnhap ma sinh vien la: ");
	gets(hs.masv);
	
	fflush(stdin);
	printf("\nnhap diem trung binh la: ");
	scanf("%d",&hs.dtb);
}
void nhap_ds(LIST &l)
{
	hssv hs;
	int i,n;
	create(l);
	do
	{
		printf("\nnhap so luong sinh vien la: ");
		scanf("%d",&n);
	}
	while (n<0 || n>50);
	for (i=0;i<n;i++)
	{
		nhap(hs);
		NODE *p = create_node(hs);
		add_l(l,p);
	}
}
void xuat(LIST l)
{
	printf("\n%-15s%-15s%-15s","Ho va ten","ma sinh vien","diem trung binh");
	NODE *p = l.pHead;
	while (p!=NULL)
	{
		printf("\n%-15s%-15s%-15d",p->data.hoten,p->data.masv,p->data.dtb);
		p=p->pNext;
	}
}
 // 1.them node p vao sau node q nam trong ds lien ket don
/*void add_p_sau_q(LIST &l,NODE *p)
 {
 	int x;
 	cout<<"\nnhap gia tri cho node q: ";
 	cin>>x;
 	NODE *q =create_node(x);
 	if (q->data  == l.pHead->data && l.pHead->pNext == NULL)
 		add_l(l,p);
 	else
 	{
 		for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
 			if (q->data == k->data)
 			{
 				NODE *h=create_node(p->data);
 				NODE *g = k->pNext;				
				h->pNext =g;
				k->pNext =h;
			}
 		
	}
 }
 // 2.them node p vao truoc node q nam trong danh sach lien ket don
void add_p_truoc_q(LIST &l,NODE *p)
{
 	int x;
 	cout<<"\nnhap gia tri cho node q: ";
 	cin>>x;
 	NODE *q =create_node(x);
 	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
 	{
 		add_f(l,p);
 	}
 	else
 	{
 		NODE *g=new NODE;
 		for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
 		{
 			if(q->data == k->data && q->data != l.pHead->data)
 			{
 				NODE *h=create_node(p->data);
				h->pNext =k;
				g->pNext =h;
			}
			else if (q->data == k->data && q->data == l.pHead->data)
			{
				NODE *h=create_node(p->data);
				h->pNext =k;
				g->pNext =h;
				add_f(l,p);
			}
			g=k;	
		}
	 }
}*/
// 1.1.selectionSort thu tu giam dan 
// 1.2.insertionSort thu tu tang dan 
// 1.3.bubble Sort   thu tu giam dan 
void swap(hssv &a,hssv &b)
{
	hssv temp ;
	temp = a;
	a = b;
	b = temp;
}
void selectionSort(LIST l)
{
	NODE *p,*q,*m;
	p=l.pHead;
	while (p!=NULL)
	{
		m=p;
		q=p->pNext;
		while (q!=NULL)
		{
			if (q->data.dtb > m->data.dtb)
				m=q;
				q=q->pNext;
		}
		swap(p->data,m->data);
		p=p->pNext;
	}
}
void  bubbleSort(LIST l)
{
	for (NODE *p=l.pHead;p!=NULL;p=p->pNext)
		  for(NODE *q=p->pNext;q!=NULL;q=q->pNext)
		  if (p->data.dtb < q->data.dtb)
		  	swap(p->data,q->data);
}
void insertionSort(LIST l)
{
	NODE *i,*j;
	char min;
	for (i=l.pHead->pNext;i!=NULL;i=i->pNext)
	{
		min=i->data.dtb;
		for (j=i->pNext;j!=NULL && j->data.dtb > min;j=j->pNext)
		{
			i->data.dtb = j->data.dtb;
			j->data.dtb = min;
		}
	}
}
// 2.xoa hoc sinh thu 3 trong danh sach lien ket don
void xoa_hs3(LIST &l)
{
	NODE *g= new NODE;
	int dem= 0;
	for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		dem++;
		if (dem == 3)
		{
			g->pNext=k->pNext;
			delete k;
		};
		g=k;
	}
}
// 3.chen  1 sinh vien moi vao vi tri thu 2
void chen_hs2(LIST &l,NODE *p)
{
	int dem=0;
	for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		dem++;
		if (dem == 2)
		{
			p->pNext = k->pNext;
			k->pNext = p;
		}
	}
}
// 4. chen vao vi tri bat ky trong danh sach lien ket don
void insert_vtbk(LIST &l,NODE *p,int vt)
{
	int n;
	for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		n++;
	}
	if (l.pHead == NULL)
	{
		add_f(l,p);
	}
	else if (vt = n+1)
	{
		add_l(l,p);
	}
	else
	{
		int dem=0;
		NODE *g = new NODE;
		for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
		{
			dem++;
			if (dem == vt)
			{
				NODE *h= create_node(p->data);
				h->pNext = k;
				g->pNext = h;
				break;
			}
			g=k;
		}
	}	 
}
// 5.xoa node dau trong danh sach lien ket don
void xoa_f(LIST &l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	else
	{
		NODE *p=l.pHead;
		l.pHead=l.pHead->pNext;
		delete p;
	}
}
// 6.xoa node cuoi trong danh sach lien ket don
void xoa_l(LIST &l)
{
	if (l.pHead == NULL)
		return;
	if (l.pHead->pNext == NULL)
		xoa_f(l);
	else
	for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
		}
	}
}
// 7.xoa 1 node nam sau node q trong danh sach lien ket don
void xoa_node_sau_q(LIST &l,NODE *q)
{
	for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		NODE *g=k->pNext;
		if (k->data.dtb == q->data.dtb)
		{
			if(g->pNext != NULL)
			{
				k->pNext = g->pNext;
				delete g;
				return ;
			}
			else 
			{
				k->pNext = NULL;
				l.pTail = k;
				delete g;
				return ;
			}
		}
	}
}
// 8.xoa 1 node co khoa k bat ky trong danh sach lien ket don
/*void xoa_node_cokhoa_bk(LIST &l,int x)
{
	if (l.pHead == NULL)
	{
		return ;
	}
	if (l.pHead == x)
	{
		xoa_f(l);
		return;
	}
	if (l.pTail == x)
	{
		xoa_l(l);
		return;
	}
	NODE *g= new NODE;
	for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		if (k->data == x)
		{
			g->pNext = k->pNext;
			delete k;
		}
		g=k;
	}
}*/
// 9.xoa 1 node tai vi tri bat ky trong danh sach lien ket don
void xoa_node_bk(LIST &l,int vt)
{
	NODE *g=new NODE ;
	if (vt == 0 || l.pHead == NULL || l.pHead == NULL)
	{
		xoa_f(l);
	}
	else
	{
		int dem=0;
		for (NODE *k=l.pHead;k!=NULL;k=k->pNext)
		{
			dem++;
			if (dem != vt)
			{
				printf("\nvi tri nhap vao khong hop le: !");
			}
			else
			{
				g->pNext=k->pNext;
				delete k;
			}
			g=k;
			
		}
	}
}
int main()
{
	LIST l;
	hssv b;
	nhap_ds(l);
	xuat(l);
/*	
	xoa_hs3(l);
	printf("\n=============DANH SACH SAU KHI XOA============ :");
	xuat(l);
	nhap (b);
	NODE *p=create_node(b);
	chen_hs2(l,p);
	printf("\n=============DANH SACH SAU KHI CHEN============ :");
	xuat(l);
	insertionSort(l);
	printf("\nthe sorted link list using insertion sort is :");
	xuat(l);
	int vt;
	nhap (b);
	NODE *p=create_node(b);
	do
	{
	printf("\nnhap vi tri can them la: ");
	scanf("%d",&vt);
	if (vt < 1 || vt > n+1)
	{
		printf("\nvi tri can them khong nam trong danh sach)
	}
}
	insert_vtbk(l,p,vt);
	printf("\n=============DANH SACH SAU KHI CHEN============ :");
	xuat(l);
	
	
//	xoa_node_sau_q(l,q)
	printf("\ndanh sach sau khi xoa la: ");
	xuat(l);*/
	
	xoa_l(l);
	printf("\n=============DANH SACH SAU KHI CHEN============ :");
	xuat(l);
	return 0;
}




