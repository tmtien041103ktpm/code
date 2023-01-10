
// edit by tienminhtran


#include <stdio.h>
#include <stdlib.h>
/*
Write a program for buiding double linked list (Display menu)
 Add one node at first
 Add one node at last
 Add many node at first
 Add many node at last
 Add one node after select node
 Display List
 Find one node
 Select and display n(th) node
 Display node count
 Remove one node
 Remove List
 Get sum of all nodes
 Inserting a new node in a sorted list
*/
struct Dnode
{
    int data;
    Dnode *pPre;  // tror den phan tu dung trc
    Dnode *pNext; // tro toi phan tu dung sau
};

struct Dlist
{

    Dnode *pHead; // tror den phan tu dau ds
    Dnode *pTail; // tro toi phan tu cuoi ds
};
void KhoiTao(Dlist &ds)
{
    // dat dia chi dau danh sach bang NULL
    ds.pHead = NULL;
    // dat dia chi cuoi danh sach bang NULL
    ds.pTail = NULL;
}
Dnode *getNode(int x)
{
    Dnode *p = new Dnode; // cap phat bo nho
    if (p == NULL)
    {
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    p->pPre = NULL;
    return p;
}

// them vao dau ds
void ThemDau(Dlist &ds, Dnode *p)
{
    // neu danh sach rong thi them vao node dau va cuoi
    if (ds.pHead == NULL)
    {
        ds.pHead = ds.pTail = p;
    }
    else
    {
        // dat con tro next cua node can them toi node dau danh sach
        p->pNext = ds.pHead;
        // dat con tro prev cua node dau ve node p
        ds.pHead->pPre = p;
        // gan lai node dau cua danh sach bang node p
        ds.pHead = p;
    }
}
void ThemCuoi(Dlist &ds, Dnode *p)
{
    // kiem tra danh sach rong neu rong thi them vao dau va cuoi
    if (ds.pHead == NULL)
    {
        ds.pHead = ds.pTail = p;
    }
    else
    {
        // dat con tro next cua pTail hien tai vao p la node can them cuoi
        ds.pTail->pNext = p;
        // dat con tro prev cua node p ve phan tu cuoi danh sach
        p->pPre = ds.pTail;
        // thay doi lai phan tu cuoi danh sach
        ds.pTail = p;
    }
}

void NhapDau(Dlist &ds, int &n)
{
    // duyet N lan
    for (int i = 0; i < n; i++)
    {
        // nhap du lieu la so nguyen int x
        int x;
        printf("Nhap vao so %d: ", i);
        scanf("%d", &x);
        // tao node p
        Dnode *p = new Dnode;
        // dua du lieu vua nhap vao node p
        p = getNode(x);
        // dua node p vao ham them cuoi va truyen vao node p vua tao
        ThemCuoi(ds, p);
    }
}
void NhapCuoi(Dlist &ds, int &n)
{
    // duyet N lan
    for (int i = 0; i < n; i++)
    {
        // nhap du lieu la so nguyen int x
        int x;
        printf("Nhap vao so %d: ", i);
        scanf("%d", &x);
        // tao node p
        Dnode *p = new Dnode;
        // dua du lieu vua nhap vao node p
        p = getNode(x);
        // dua node p vao ham them cuoi va truyen vao node p vua tao
        ThemCuoi(ds, p);
    }
}
void Xuat(Dlist ds)
{
    // khoi tao mot node
    Dnode *p = new Dnode;
    // duyet tu dau danh sach den cuoi danh sach voi dieu kien p!=NULL
    for (p = ds.pHead; p != NULL; p = p->pNext)
    {
        // hien thi du lieu cua tung node
        printf("%d\n", p->data);
    }
}

Dnode *TimKiem(Dlist ds, int x)
{
    // tao node p
    Dnode *p;
    // gan p bang phan tu dau danh sach
    p = ds.pHead;
    // su dung vong lap
    while ((p != NULL) && (p->data != x))
    {
        p = p->pNext;
    }
    // tra ve ket qua, neu NULL thi khong tim thay
    return p;
}

void XoaDau(Dlist &ds)
{
    // gan p bang phan tu dau danh sach
    Dnode *p = ds.pHead;
    // thuc hien gan lai phan tu dau danh sach
    ds.pHead = ds.pHead->pNext;
    ds.pHead->pPre = NULL;
    // neu khong ton tai phan tu dau danh sach
    if (ds.pHead == NULL)
    {
        ds.pTail = NULL;
    }
    // thay doi con tro next ve NULL
    p->pNext = NULL;
    // xoa node p duoc gan bang phan tu dau danh sach
    delete p;
    // printf("\nXoa vi tri dau danh sach\n");
    // Xuat(ds);
}
void XoaCuoi(Dlist &ds)
{
    // tao node p va gan bang phan tu cuoi danh sach
    Dnode *p = ds.pTail;
    // thuc hien gan lai phan tu cuoi danh sach
    ds.pTail = ds.pTail->pPre;
    ds.pTail->pNext = NULL;
    // kiem tra phan tu cuoi neu rong
    if (ds.pTail == NULL)
    {
        ds.pHead = NULL;
    }
    // thay doi con tro prev cua node p ve NULL
    p->pPre = NULL;
    // xoa p duoc gan bang phan tu cuoi danh sach
    delete p;
    printf("\nXoa vi tri cuoi danh sach\n");
    Xuat(ds);
}
void XoaTheoKhoaK(Dlist &ds, int k)
{
    // nhap vao k can tim
    printf("\nNHAP K: ");
    scanf("%d", &k);
    // tim kiem theo du lieu x va gan vao node p
    Dnode *p = TimKiem(ds, k);
    // neu tim thay ket qua
    if (p != NULL)
    {
        // neu p->prev == NULL thuc hien xoa dau
        if (p->pPre == NULL)
        {
            XoaDau(ds);
            return;
        }
        // neu p->next == NULL thuc hien xoa cuoi
        if (p->pPre == NULL)
        {
            XoaCuoi(ds);
            return;
        }
        // thay doi lai lien ket cua phan tu co khoa K can xoa
        p->pPre->pNext = p->pNext;
        p->pNext->pPre = p->pPre;
        // gan con tro prev va next cua phan tu co khoa K can xoa ve null
        p->pPre = NULL;
        p->pNext = NULL;
        // xoa node p co phan tu la khoa k
        delete p;
    }
    printf("\nDANH SACH SAU KHI XOA DAU, XOA CUOI VA XOA THEO KHOA K\n");
    Xuat(ds);
}
void addAfter(Dlist &ds, Dnode *q, Dnode *newnode)
{
    if (q != NULL)
    {
        Dnode *p = q->pNext;
        newnode->pNext = p;
        newnode->pPre = q;
        q->pNext = newnode;
        if (p != NULL)
            p->pPre = newnode;
        else
            ds.pTail = newnode;
    }
}
void InsertAfter(Dlist &ds, Dnode *q, int x)
{
    Dnode *new_ele = getNode(x);
    if (new_ele != NULL)
        addAfter(ds, q, new_ele);
    Xuat(ds);
}
int demnode(Dlist &ds)
{
    int dem = 0;
    Dnode *p;
    for (p = ds.pHead; p != NULL; p = p->pNext)
    {
        dem++;
    }
    return dem;
}
int tinhSoLuong(Dlist &ds)
{
    int s = 0;
    Dnode *p;
    for (p = ds.pHead; p != NULL; p = p->pNext)
    {
        s = s + p->data;
    }
    return s;
}
int RemoveHead(Dlist &ds, int x)
{
    if (ds.pHead != NULL)
    {
        Dnode *node = ds.pHead;
        x = node->data;
        // Luu gi� tr? c?a node head l?
        ds.pHead = node->pNext;
        delete node; // H?y node head di
        if (ds.pHead == NULL)
            ds.pTail = NULL;
        return 1;
    }
    return 0;
}
void DestroyList(Dlist &ds)
{
    Dnode *node = ds.pHead;
    while (node != NULL)
    {
        XoaDau(ds);
        node = ds.pHead;
    }
    ds.pTail = NULL;
}
Dnode *Select_and_display_node(Dlist ds, int x, int &n)
{

    Dnode *p = ds.pHead;
    for (int i = 0; i < n; i++)
    {
        p = p->pNext;
        if (i == x)
        {

            return p;
        }
    }
    return NULL;
}
void menu()
{
    printf("\n-----------MENU---------------\n");
    printf("1/ Add one node at first\n");
    printf("2/ Add one node at last\n");
    printf("3/ Add many node at first\n");
    printf("4/ Add many node at last\n");
    printf("5/ Add one node after select node\n");
    printf("6/ Display List\n");
    printf("7/ Find one node\n");
    printf("8/ Select and display n(th) node\n");
    printf("9/ Display node count\n");
    printf("10/Remove one node\n");
    printf("11/Remove List\n");
    printf("12/Get sum of all nodes\n");
    printf("13/Inserting a new node in a sorted list\n");
}
int main()
{
    // khai bao mot danh sach lien ket doi
    Dlist ds;
    int n;
    // khoi tao danh sach
    KhoiTao(ds);
    int chon;
    printf("NHAP N: ");
    scanf("%d", &n); // khoi tao danh sach
    do
    {
        menu();
        printf("Moi ban nhap lua chon\n");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            printf("Them node vao dau \n");
            int nodedau;
            printf("Nhap node can chen dau: \n");
            scanf("%d", &nodedau);
            Dnode *a = new Dnode;
            a = getNode(nodedau);
            // dua node p vao ham them dau va truyen vao node p vua tao
            ThemDau(ds, a);
            break;
        case 2:
            printf("Them node vao cuoi \n");
            int nodecuoi;
            printf("Nhap node can chen cuoi: \n");
            scanf("%d", &nodecuoi);
            Dnode *b = new Dnode;
            b = getNode(nodecuoi);
            // dua node p vao ham them cuoi va truyen vao node p vua tao
            ThemCuoi(ds, b);
            break;
        case 3:
            KhoiTao(ds);    // goi ham nhap tryuyen vao danh sach va N phan tu
            NhapDau(ds, n); // goi ham xuat cac du lieu co trong danh sach
            printf("DANH SACH VUA NHAP DAU\n");
            break;
        case 4:
            KhoiTao(ds);     // goi ham nhap tryuyen vao danh sach va N phan tu
            NhapCuoi(ds, n); // goi ham xuat cac du lieu co trong danh sach
            printf("DANH SACH VUA NHAP CUOI\n");
            break;
        case 5:
            printf("Them mot nut vao sau node qaddAfter  \n");
            int t;
            printf("Nhap node q: ");
            scanf("%d", &t);
            Dnode *qaddAfter = new Dnode;
            qaddAfter = getNode(t);
            InsertAfter(ds, qaddAfter, 10);
            break;
        case 6:
            printf("DANH SACH LA\n");
            Xuat(ds);
            break;
        case 7:
            int x;
            printf("NHAP GIA TRI CAN TIM KIEM: ");
            scanf("%d", &x);
            // goi ham tim kiem truyen vao gia tri x va gan vao node p
            Dnode *p = TimKiem(ds, x);
            // kiem tra ket qua tim kiem
            if (p == NULL)
            {
                printf("\nKHONG TIM THAY KET QUA");
            }
            else
            {
                printf("\nTIM THAY KET QUA: ");
                printf("%d", p->data);
            }
            break;
        case 8:
            printf("Select and display n(th) node");
            int u;
            printf("Nhap vi tri u:");
            scanf("%d", &u);
            Select_and_display_node(ds, u, n);
            break;
        case 9:
            printf("Dem so node %d: \n", demnode(ds));
            break;
        case 10:
            printf("\nXOA NODE \n");
            int k;
            XoaTheoKhoaK(ds, k);
            break;
        case 11:
            printf("Remove List\n");
            // RemoveHead(ds, 2);
            printf("DA XOA HET DANH SACH\n");
            DestroyList(ds);
            break;
        case 12:
            printf("Lay so luong %d: ", tinhSoLuong(ds));
            break;
        case 13:
            printf("Inserting a new node in a sorted list");
            break;
        }
    } while (chon != 14);
}
// int n;
//    printf("NHAP N: ");
//    scanf("%d", &n);//khoi tao danh sach
//    KhoiTao(ds);//goi ham nhap tryuyen vao danh sach va N phan tu
//    NhapDau(ds, n);//goi ham xuat cac du lieu co trong danh sach
//    printf("DANH SACH VUA NHAP DAU\n");
//    Xuat(ds);
//
/*
    KhoiTao(ds);// goi ham nhap tryuyen vao danh sach va N phan tu
    NhapCuoi(ds, n);// goi ham xuat cac du lieu co trong danh sach
    printf("DANH SACH VUA NHAP CUOI\n");
    Xuat(ds);


    printf("Them node vao dau \n");
    int nodedau;
    printf("Nhap node can chen dau: \n");
    scanf("%d", &nodedau);
    Dnode *a = new Dnode;
    a = getNode(nodedau);
    // dua node p vao ham them dau va truyen vao node p vua tao
    ThemDau(ds, a);
    Xuat(ds);

    printf("Them node vao cuoi \n");
    int nodecuoi;
    printf("Nhap node can chen cuoi: \n");
    scanf("%d", &nodecuoi);
    Dnode *b = new Dnode;
    b = getNode(nodecuoi);
    // dua node p vao ham them cuoi va truyen vao node p vua tao
    ThemCuoi(ds, b);
    Xuat(ds);
 */

//    printf("Them mot nut vao sau node qaddAfter  \n");
//    int t;
//    printf("Nhap node q: ");
//    scanf("%d", &t);
//    Dnode *qaddAfter = new Dnode;
//    qaddAfter = getNode(t);
//    InsertAfter(ds, qaddAfter, 10);
//    Xuat(ds);
//
//	printf("Dem so node %d: \n", demnode(ds));
//    printf("Lay so luong %d: ", tinhSoLuong(ds));
//
//
//    int x;
//    printf("NHAP GIA TRI CAN TIM KIEM: ");
//    scanf("%d", &x);
//    // goi ham tim kiem truyen vao gia tri x va gan vao node p
//    Dnode *p = TimKiem(ds, x);
//    // kiem tra ket qua tim kiem
//    if (p == NULL)
//    {
//        printf("\nKHONG TIM THAY KET QUA");
//    }
//    else
//    {
//        printf("\nTIM THAY KET QUA: ");
//        printf("%d", p->data);
//    }
//
//    // xoa dau danhs sach
//    XoaDau(ds);
//
//    // xoa cuoi danh sach
//    XoaCuoi(ds);
//
//    // Xoa theo khoa K
//    int k;
//    XoaTheoKhoaK(ds, k);
