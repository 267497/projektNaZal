#include <iostream>

using namespace std;
class Klient{
    private:
        int id_klienta;
        string imie;
        string nazwisko;
        string adres;
        string email;
        string nr_telefonu;
    public:
        Klient(int id,string imie,string nazwisko){
            this->id_klienta=id;
            this->imie=imie;
            this->nazwisko=nazwisko;
        }
   		void wyswietl_profil(int id_klienta);
   		void listareklamacji();
};

class Produkt{
    private:
        int id_produktu;
        string nazwa;
    public:
        Produkt(int id,string nazwa){
            this->id_produktu=id;
            this->nazwa=nazwa;
        }
        void pokazProdukt(int id_produktu);
        bool usunProdukt(int id_produktu);
};

class Transakcja: public Produkt, public Klient{
	private:
		int id_transakcji;
		int id_produktu;
		int id_klienta;
		int ilosc;
		int status;
	public:
		Transakcja();

		bool zamow(int id_produktu, int id_klienta, int ilosc, int status=0) {
		    bool ok=true;
			ilosc = ilosc;
			if(ok) return true;
			else return false;
		}
        void wyswietl_transakcje(int id_transakcji,int ilosc,int status){
        }
		void lista_transakcji() {
		    int id;
		    int ilosc;
		    int status;
		    cin>>id;
		    cin>>ilosc;
		    cin>>status;
			wyswietl_transakcje (int id_transakcji,int ilosc,int status);
		}

		int id_zakupu() {
			lista_transakcji();
			cin >> id_transakcji;
			return id_transakcji;
		}

};

class Reklamacja{
        string data;
        int id_reklamacji;
        int id_pracownika;
        int status;
        string email;
        Transakcja transakcja;
    public:
        Reklamacja(){
        }
        Reklamacja(int id,string nazwa,string data,int id_reklamacji,int id_pracownika,int status){
            this->data=data;
            this->id_reklamacji=id_reklamacji;
            this->id_pracownika=id_pracownika;
            this->status=status;
        }
        bool zlozreklamacje(int id_klienta, int id_zakupu, int id_pracownika);
        int czytaj_status(int id_reklamacji);
};

class Pracownik:public Reklamacja{
    private:
        int id_pracownika;
        string imie;
        string nazwisko;
    public:
        Pracownik(int id,string imie,string nazwisko):Reklamacja(){
            this->id_pracownika=id;
            this->imie=imie;
            this->nazwisko=nazwisko;
        }
        void przyjmijreklamacje();
        void zmienstatusreklamacji(int id_reklamacji);
};

class Administrator:public Pracownik{
    public:
        Administrator(int id,string imie,string nazwisko):Pracownik(id,imie,nazwisko){}
        bool zrobpracownika();
        bool zmienuprawieniapracownika();
        bool usunpracownika();
};

class DzialReklamacji:public Reklamacja,public Klient,public Administrator{
	public:
				void pokazPracownikow();
				void pokazWszystkieReklamacje();
				void pokazKlientowReklamujacych();
				void pokazInfoAdministratora();
};


int main()
{
    return 0;
}
