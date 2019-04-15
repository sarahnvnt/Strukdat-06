#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Kontak{
	
 	char name[10];
  	char phone[12];
  	Kontak* nextKontak;
};

struct Index{
	
 	char index[1];
  	Kontak* FirstKontak;
 	Index* next;
};

typedef Index* pointerInd;
typedef Kontak* pointerKon;
typedef pointerInd listInd;

void createListInd(listInd& First){
 	First=NULL;
}

void createElmtInd(pointerInd& pBaru){
 	pBaru= new Index;
 	cout<<"Masukan Index :"; cin>>pBaru->index;
 	pBaru->next=NULL;
 	pBaru->FirstKontak=NULL;
}

void createElmtKontak(pointerKon& pBaru){
 	pBaru= new Kontak;
 	cout<<"Masukan Nama   :"; cin>>pBaru->name;
 	cout<<"Masukan Nomor  :"; cin>>pBaru->phone;
 	pBaru->nextKontak=NULL;
}

void traversalInd(listInd First){
	pointerInd pBantu;
 	pBantu=First;
 	cout<<"Index :"<<endl;
 	while(pBantu!=NULL){
  	cout<<"|- "<<pBantu->index<<endl;
  	pBantu=pBantu->next;
 }
}

void linearSearch(listInd First,char key[20],int& status,pointerInd& pCari){
 	status=0;
 	pCari=First;
 	while(status==0 && pCari!=NULL){
  	if(strcmp(pCari->index,key)==0){
   	status=1;
  }
  else{	
   pCari=pCari->next;
 }
 }
}

void insertFirstInd(listInd& First,pointerInd pBaru){
	if(First==NULL){
  	First=pBaru;
 }
 else{
  	pBaru->next=First;
  	First=pBaru;
  }
}

void deleteFirstInd(listInd& First,pointerInd pHapus){
	if(First==NULL){
    cout<<"tidak ada yang dihapus "<<endl;
  }
 else if(First->next==NULL){
    pHapus=First;
  	First=NULL;
  }
 else{
    pHapus=First;
    First=pHapus->next;
    First->next=NULL;
  }
}

void insertFirstKontak(listInd& First,char key[20],pointerKon pBaru){
	pointerInd pInd;
  	int ketemu;
   	cout<<"Masukan Index yang Akan di cari: "; cin>>key;
  	linearSearch(First,key,ketemu,pInd);
  	if(ketemu){
    	cout<<"Ditemukan dengan Index :"<<pInd->index<<endl;
    if(pInd->FirstKontak==NULL){
    	pInd->FirstKontak=pBaru;
    }
   else{
   	pBaru->nextKontak=pInd->FirstKontak;
    pInd->FirstKontak=pBaru;
   }
  }
 else{
 	cout<<"Nama Index tidak di temukan"<<endl;
  }
}

void deleteFirstKontak(listInd& First,char key[20],pointerKon& pHapus ){
 	int ketemu;
 	pointerInd pInd;
  	cout<<"Masukan Index yang di cari: "; cin>>key;
  	linearSearch(First,key,ketemu,pInd);
   	if(ketemu){
    	cout<<"Ditemukan dengan nama :"<<pInd->index;
    if(pInd->FirstKontak==NULL){
      	cout<<"Tidak ada yang di hapus"<<endl;
  }
   else if(pInd->FirstKontak->nextKontak==NULL){
   	pHapus=pInd->FirstKontak;
    pInd->FirstKontak=NULL;
   }
   else{
   	pHapus=pInd->FirstKontak;
    pInd->FirstKontak=pInd->FirstKontak->nextKontak;
    pHapus->nextKontak=NULL;
   }
  }
  else{
    cout<<"Nama Index tidak di temukan"<<endl;
  }
}

void traversalIndKontak(listInd First){
    pointerInd pBantuInd;
    pointerKon pBantuKon;
    cout<<"Traversal Index"<<endl;
    pBantuInd=First;
    while (pBantuInd!=NULL){
        cout<<"|- "<<pBantuInd->index<<endl;
        pBantuKon=pBantuInd->FirstKontak;
        while (pBantuKon!=NULL) {
         	cout<<"\t|- "<<pBantuKon->name<< " / "<<pBantuKon->phone<<endl;
         	pBantuKon=pBantuKon->nextKontak;
        }
        pBantuInd=pBantuInd->next;
    }
}

void sorted(listInd& First){
 	if(First=NULL) return;
 	while(First!=NULL){
  	cout<<First->index<<" ";
  	Kontak *temp=First->FirstKontak;
  	while(temp!=NULL){
   	cout<<temp->name<<" ";
   	temp=temp->nextKontak;
  }
  First=First->next;
 }
  cout<<endl;
}

main(){
    listInd a;
    int nd,nC,pilih;
    char key [20];
    pointerInd pd,pc,phd;
    pointerKon pk,phk;
    createListInd(a);
    do{
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1.Insert Index"<<endl;
        cout<<"2.Insert Nama"<<endl;
        cout<<"3.Delete First Index"<<endl;
        cout<<"4.Delete First Nama"<<endl;
        cout<<"5.Tampilkan Phone Book"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Masukan pilihan :"; cin>>pilih;
        switch(pilih){
        case 1 :
            cout<<"Masukan jumlah Index : ";
            cin>>nd;
            for(int i=0;i<nd;i++){
                createElmtInd(pd);
                insertFirstInd(a,pd);
            }
        break;
        case 2 :cout<<"Masukan jumlah Nama :";
            cin>>nC;
            traversalInd(a);
            for(int i=0;i<nC;i++){
                createElmtKontak(pk);
                insertFirstKontak(a,key,pk);
            }
        break;
        case 3 :
            deleteFirstInd(a,phd);
            traversalInd(a);
        break;
        case 4:
            deleteFirstKontak(a,key,phk);
            traversalIndKontak(a);
        break;
        case 5 :
            traversalIndKontak(a);
            sorted(a);
        break;
        default :
            exit(0);
        }
        system("pause");
    }while(pilih!=6);
}
