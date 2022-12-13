#include <iostream>
#include <string>
#include <windows.h>
#include <limits>
#include <ios>
using namespace std;

void gotoxy(short int kolom, short int baris){
	COORD posisi = {kolom, baris};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posisi);
}

void putus(int i, string pone){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while(i > 0){ SetConsoleTextAttribute(hConsole, i);
	Sleep(200); cout << endl << "Selamat " << pone << " kamu berhasil putus dengannya :)))))))))))))))) ((((((((:"; i--; }
}

void paus(){ cout << endl << "Klik enter untuk lanjut" << endl; cin.clear(); cin.sync(); cin.get(); }

int main(){
	string pone,ptwo,pesan[100],masukan,kode;
	int banyakpesan,ref,poin = 100;
	start: system("clear");
	cout << "Yang ingin putus : "; cin >> pone;
	cout << endl<<"Yang jadi korban : "; cin >> ptwo;
	cout << endl <<"Hey " << ptwo <<" Masukkan kode kunci pesan : "; cin >> kode;
    cout << endl <<"Hey " << pone << " Masukkan berapa banyak kalimat yang ingin dibuat untuk pesan (Tidak boleh lebih dari lebih 60 dan kurang dari 2) : "; ulang:  cin >> banyakpesan;
    while (cin.fail() && !(cin>>banyakpesan)) { cin.clear(); cin.ignore(256,'\n'); cout << "Masukkan angka : "; }
	if(banyakpesan < 2 || banyakpesan > 60){ goto ulang; }
	cout << endl <<"Hey " << pone << " Masukkan pesan ke " << ptwo << " agar putus " << "(Hanya " << banyakpesan << " kalimat) : "; 
	
	for(int l = 0; l < banyakpesan; l++){
	 cin >> pesan[l]; if(l == 0) { cout<<pesan[l]; } 
	 else if(l != 0) { cout << " " << pesan[l]; }
	}       
    
    Sleep(3000); system("clear");
	for(int g = 0; g < 60; g++){
		gotoxy(24,10); cout << "____"; gotoxy(24,12); cout << "____"; gotoxy(g,10);  cout << " p";  gotoxy(g,11);  cout << "[[";
		gotoxy(g,12);  cout << "[["; Sleep(500); gotoxy(g,10); cout << "         "; gotoxy(g,11); cout << "         ";
		gotoxy(g,12); cout << "         "; if(g==26) {	g = 1; cout << "Pak pos sampai"; break; }
    }
    
    Sleep(3000); system("clear");
    cout << ptwo << " Masukkan kode untuk melihat pesan : "; lagi: cin >> masukan;
    if(masukan == kode){
    	system("clear");
        for(int l = 0; l < banyakpesan; l++){
    	if(l == 0){ cout << pesan[l]; } 
	    else if(l != 0){ cout << " " << pesan[l]; }
		}
		
		cout << endl; paus(); 
		cout << endl << ptwo << " Apakah kamu kesal dan ingin mengurangi poin " << ptwo << "? (ya/tidak) : ";
		cin >> masukan; if(masukan == "ya" || masukan == "Ya"){ poin -= 40; } else if(masukan == "tidak" || masukan == "Tidak"){ poin += 40; } else if(masukan != "tidak" || masukan != "ya"){ poin -= 40; cout << "dianggap sebagai ya."; }
	}   else if(masukan != kode){ goto lagi; }
	
	Sleep(3000); system("clear");
	cout << "giliran " << pone << endl; paus(); system("clear");
	if(poin > 100) {
		cout << pone << " Kamu gagal membujuknya." << endl;
	}   else if ( poin < 100) { cout << "Selamat " << pone << ", kamu hampir putus dengannya." << endl; }
	cout << "Selanjutnya adalah permainan batu gunting kertas, " << pone << " harus memenangkan permainan untuk mengurangi poin agar putus.";
	Sleep(6000); system("clear");
    
    int chance, skorgk; string plone, pltwo;  chance = 0;
    cout << "Gunting/Batu/Kertas" << endl; skorgk = 42;
    gunker: chance += 1; cout << pone << " : "; cin >> plone; system("clear");
	cout << ptwo << " : "; cin >> pltwo; system("clear"); 
	
	int prenum = 0, prexe = 0;  
	if(plone == "Kertas" || plone == "kertas"){	prenum = 6; }
	else if(plone == "Batu" || plone == "batu"){ prenum = 5; }
	else if(plone == "Gunting" || plone == "gunting"){ prenum = 4;	}
	
	if(pltwo == "Kertas" || pltwo == "kertas"){ prexe = 6; }
	else if(pltwo == "Batu" || pltwo == "batu"){ prexe = 5; }
	else if(pltwo == "Gunting" || pltwo == "gunting"){ prexe = 4; }
	
	if(plone == pltwo){ cout << "seri" << endl;  } else if(prenum != 0 || prexe != 0){
    if(prenum-prexe == 1){  skorgk += 1; cout << pone << " menang" << endl; } 
    else if(prexe-prenum == 1){  skorgk -= 1; cout << ptwo << " menang" << endl; }
    else if(prenum-prexe == 2){  skorgk -= 1; cout << ptwo << " menang" << endl; } 
    else if(prexe-prenum == 2){  skorgk += 1; cout << pone << " menang" << endl; }
    }
    
    if(plone == pltwo){ chance -= 1; }
    if(chance < 3){ goto gunker; }  if(skorgk > 42 && skorgk < 45){ poin -= 40; system("clear"); cout << pone << " menang, horeeee "; } 
	else if(skorgk < 42){ poin += 40; system("clear"); cout << ptwo << " menang, " << pone << " mengalah untuk " <<  ptwo << ", niat putus tidak ?"; } else if(skorgk > 44){ system("clear"); cout << "menang tiga kali berturut turut, pasti putus! horeeeee "; poin -= 100; }
	else if(skorgk == 42){ cout << "pastikan menulis dengan benar" << endl << endl; chance -= 3; goto gunker; } 
	
	cout << endl << "Terakhir ... "; Sleep(5000); system("clear");
	
    for(int g = 0; g < 60; g++){
		gotoxy(24,10); cout << "____"; gotoxy(24,12); cout << "____"; gotoxy(g,10);  cout << " O"; gotoxy(g,11);  cout << "<>";
		gotoxy(g,12);  cout << ". ."; Sleep(300); gotoxy(g,10); cout << "         ";
		gotoxy(g,11); cout << "         "; 	gotoxy(g,12); cout << "         ";
		 if(g<29){ gotoxy(g,8); cout << ptwo; Sleep(250); gotoxy(g,8); cout << "       "; }
		 if(g>26 && g<60){ gotoxy(45,10);  cout << " O";  gotoxy(45,11);  cout << "<>"; gotoxy(45,12);  cout << ". .";
	    gotoxy (50,10); cout << " O"; gotoxy(50,11); cout << " <>"; gotoxy(50,12); cout << ". .";
    }    if(g > 30){ gotoxy(34,15); cout << "Sepertinya aku melihat dia berduaan" << endl; 
	    }
	} Sleep(3000); system("clear");
    cout << "apakah " << pone << " cemburu ? ya/tidak" << endl;
	cin >> masukan; if(masukan == "ya" || masukan == "Ya"){ poin -= 20; } else if(masukan == "tidak" || masukan == "Tidak"){ poin += 20;	} Sleep(3000); system("clear");
	
    if(poin < 1){ cout << "Selamat " << pone << ", kamu berhasil putus dengan " << ptwo; putus(1000,pone); return 0; } 
	if(poin > 199){ cout << "poin kamu melebihi 100 atau " << poin << ", Kamu gagal putus"; return 0; } 
	
	cout << "1. Mengulang" << endl << "2. Menyerah" << endl;
	cout << "Kelihatannya kamu belum putus, " << "Mau mengulang dengan skor tersisa atau menyerah ? "; menyerah: cin >> ref; 
	if(ref == 1){ goto start; } else if(ref == 2){ cout << endl << "kalah"; return 0; } else if(ref != 1 || ref != 2){ goto menyerah; }
	
	return 0;
}