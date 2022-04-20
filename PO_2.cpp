#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Locuinta {
public:
	Locuinta(string client, float discount, int suprafata_utila); 
	Locuinta(); 
	Locuinta(const Locuinta&); 
	~Locuinta(); 
	void set_client(string client);
	void set_discount(float discount);				
	void set_suprafata_utila(int suprafata_utila);
	string get_client();
	float get_discount();					
	int get_suprafata_utila();
	virtual void citire(istream& i) { i >> client >> discount >> suprafata_utila; }
	virtual void afisare(ostream& o) { o << client << " " << discount << " " << suprafata_utila; }
	virtual void calcul_chirie(int x, int y) = 0;  //x este pret/mp; y=1 cu discount y=0 fara discount
	Locuinta& operator=(const Locuinta& l);
	friend istream& operator >> (istream& stream, Locuinta& locuinta);
	friend ostream& operator <<(ostream& stream,  Locuinta& locuinta);
	

protected:		
	float discount;
	int suprafata_utila;
private:
	string client;

};


Locuinta::Locuinta() {}

Locuinta::Locuinta(string client, float discount, int suprafata_utila) {
	this->client = client;
	this->discount = discount;
	this->suprafata_utila = suprafata_utila;
}

Locuinta::Locuinta(const Locuinta& locuinta) {
	client = locuinta.client;
	discount = locuinta.discount;
	suprafata_utila = locuinta.suprafata_utila;
}

Locuinta::~Locuinta() {}

void Locuinta::set_client(string client) {
	this->client = client;
}

void Locuinta::set_discount(float discount) {
	this -> discount = discount;
}
void Locuinta::set_suprafata_utila(int supratafa_utila) {
	this->suprafata_utila = suprafata_utila;
}

string Locuinta::get_client() {
	return this->client;
}

float Locuinta::get_discount() {
	return this->discount;
}

int Locuinta::get_suprafata_utila() {
	return this->suprafata_utila;
}

Locuinta& Locuinta:: operator=(const Locuinta& l) {
	client = l.client;
	discount = l.discount;
	suprafata_utila = l.suprafata_utila;
	return *this;
}

istream& operator >>(istream& i, Locuinta& locuinta) {
	locuinta.citire(i);
	return i;
}

ostream& operator <<(ostream& o,  Locuinta& locuinta) {
	locuinta.afisare(o);
	return o;
}


class Apartament : public Locuinta {
public:
	Apartament(string client, float discount, int suprafata_utila,int etaj);
	Apartament();
	Apartament(const Apartament&);
	~Apartament();
	void set_etaj(int etaj);
	int get_etaj();
	static int get_numar_apartamente();
	void citire(istream& i) { Locuinta::citire(i); i >> etaj; }
	void afisare(ostream& o) { Locuinta::afisare(o); o << " " << etaj; }
	void calcul_chirie(int x, int y);
	Apartament& operator=(const Apartament&);
	friend istream& operator >> (istream& stream, Apartament& apartament);
	friend ostream& operator <<(ostream& stream,  Apartament& apartament);


private:
	int etaj;
	static int numar_apartamente;


};

Apartament::Apartament() {
	numar_apartamente++;
}

Apartament::Apartament(string client, float discount, int suprafata_utila, int etaj) : Locuinta(client, discount, suprafata_utila) {
	this->etaj = etaj;
	numar_apartamente++;
}

Apartament::Apartament(const Apartament& apartament) : Locuinta(apartament) {
	etaj = apartament.etaj;
}

Apartament::~Apartament() {}

int Apartament::numar_apartamente=-1;

 int Apartament::get_numar_apartamente() {
	return numar_apartamente;
}

void Apartament::set_etaj(int etaj) {
	this->etaj = etaj;
}

int Apartament::get_etaj() {
	return this->etaj;
}

istream& operator >>(istream& i, Apartament& apartament) {
	apartament.citire(i);
	return i;
}
Apartament& Apartament::operator=(const Apartament& a) {
	this->Locuinta::operator=(a);
	etaj = a.etaj;
	return *this;
}


ostream& operator <<(ostream& o,  Apartament& apartament) {
	apartament.afisare(o);
	return o;
}

void Apartament::calcul_chirie(int x, int y) {
	cout << x *suprafata_utila*(1-y*discount/100.0);
}


class Casa :public Locuinta {
public:
	Casa(string client, float discount, int suprafat_utila,int suprafata_teren);
	Casa();
	Casa(const Casa&);
	~Casa();
	void set_suprafata_teren(int suprafata_teren);
	int get_suprafata_teren();
	static int get_numar_case();
	void calcul_chirie(int x, int y);
	void citire(istream& i) { Locuinta::citire(i); i >> suprafata_teren; }
	void afisare(ostream& o) { Locuinta::afisare(o); o << " "<<suprafata_teren; }
	Casa& operator=(const Casa&);
	friend istream& operator >> (istream& i, Casa& casa);
	friend ostream& operator <<(ostream& o, Casa& casa);
	
private:
	int suprafata_teren;
	static int numar_case;
};

Casa::Casa() {
	numar_case++;
}

Casa::Casa (string client, float discount, int suprafat_utila,int suprafata_teren) :Locuinta(client, discount, suprafat_utila) {
	this->suprafata_teren = suprafata_teren;
}

Casa::Casa(const Casa& casa) : Locuinta(casa) {
	suprafata_teren = casa.suprafata_teren;
}
Casa::~Casa() {}

int Casa::numar_case=-1;

 int Casa::get_numar_case() {
	return numar_case;
}
void Casa::set_suprafata_teren(int suprafata_teren) {
	this->suprafata_teren = suprafata_teren;
}

int Casa::get_suprafata_teren() {
	return this->suprafata_teren;
}

Casa& Casa::operator=(const Casa& c) {
	this->Locuinta::operator=(c);
	suprafata_teren = c.suprafata_teren;
	return *this;
}

istream& operator >>(istream& i, Casa& casa) {
	casa.citire(i);
	return i;
}

ostream& operator <<(ostream& o, Casa& casa) {
	casa.afisare(o);
	return o;
}

void Casa::calcul_chirie(int x, int y) {
	cout << x * (suprafata_utila + 0.2 * suprafata_teren) * (1 - y * discount / 100.0);
}


int main() {
	int n, i;
	ifstream f("input.txt");
	f >> n;
	vector<Locuinta*> l;
	vector<Apartament> apartamente;
	vector<Casa> casa;
	l.resize(n);
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0)
			l[i] = new Casa(); //initializem adresa din pointer catre un obiect de tipul dorit
		else
			l[i] = new Apartament();
		f>> *l[i];
	}


	int choice, teren, etaj, pret_mp_apartament =10 , pret_mp_casa = 15;
	bool agentie = true, ok = true;  
	string alegere;
	Apartament ideal_apartament;
	Casa ideal_casa;
	cout<<"Bine ati venit la agentia Rares.Avem disponibile " << Apartament::get_numar_apartamente() << " apartamente si " << Casa::get_numar_case() << " case. Ce cauti ? \n";
	while (agentie != false) {
		ok = true; //folosim ok pentru a ramane in while pana cand se introduce un etaj/teren existent
		cout<<"\n \n \n \n";
		cout<<"1-apartament \n";
		cout<< "2-casa \n";
		cout<< "3-exit \n";
		cout<< "4-Lista completa locuinte(fost client,discount,suprafata utila,etaj/teren) + chirie fara discount \n";
		cout<< "enter your choice \n";

		cin >> choice;
		switch (choice) {
		case 1:
			cout << "ce etaj ati dori? \n";
			while (ok) {
				cin >> etaj;
					for (i = 0; i < l.size(); i++)
					{
						try {
							Apartament& a = dynamic_cast<Apartament&>(*l[i]);  
						}
						catch (bad_cast) {
							continue;
						}
						Apartament* a = dynamic_cast<Apartament*>(l[i]);  //downcasting pentru a accesa functia get_etaj
						if (a->get_etaj() == etaj)
							apartamente.push_back(*a); //introducem in vector obiectul dorit

					}
					if (apartamente.size())
					{
						cout<< "Ati dori un apartament mare? Va rog raspundeti cu Da sau Nu \n";
						ok = 0;
					}
					else
						cout<< "Nu avem etajul acesta disponibil \n";
	
			}
			cin >> alegere;
			ideal_apartament = apartamente[0];			//gasim cel mai mare sau cel mai mic apartament
			if (alegere == "Da" or alegere=="da") {
				for (i = 0; i < apartamente.size(); i++)
					if (apartamente[i].get_suprafata_utila() > ideal_apartament.get_suprafata_utila())
						ideal_apartament = apartamente[i];
			}
			else {
				for (i = 0; i < apartamente.size(); i++)
					if (apartamente[i].get_suprafata_utila() < ideal_apartament.get_suprafata_utila())
						ideal_apartament = apartamente[i];
			}
			cout << "Apartamentul ideal pentru dumneavoastra are o suprafata de " << ideal_apartament.get_suprafata_utila() << " mp" <<
				". Veti primi un discount o data la trei luni de plati ale chiriei de " << ideal_apartament.get_discount() << "%. Chiria este de "; ideal_apartament.calcul_chirie(pret_mp_apartament, 1);
			cout << "cu discount. Fara discount chiria este de "; ideal_apartament.calcul_chirie(pret_mp_apartament, 0); cout << "\n";
			cout << "Numele fostului chirias este " << ideal_apartament.get_client() << " daca doritit sa intrati in contact. \n";
			break; //afisam detalii despre apartament
		case 2:
			cout << "Cati mp(metri patrati) sa aiba curtea? \n";
			while (ok) {
				cin >> teren;
					for (i = 0; i < l.size(); i++)
					{
						try {
							Casa& c = dynamic_cast<Casa&>(*l[i]);
						}
						catch (bad_cast) {
							continue;
						}
						Casa* c = dynamic_cast<Casa*>(l[i]);		//downcasting pentru a accesa functia get_suprafata_teren
						if (abs(c->get_suprafata_teren() - teren) <= 100)
							casa.push_back(*c);		

					}
					if (casa.size())

					{
						cout << "Ati dori o casa mare? \n";
						ok = 0;
					}
					else
						cout << "Nu avem terenuri de dimensiuni asemanatoare. \n";

			}
					cin >> alegere;
					ideal_casa = casa[0];
					if (alegere == "Da" or alegere=="da") {
						for (i = 0; i < casa.size(); i++)
							if (casa[i].get_suprafata_utila() > ideal_casa.get_suprafata_utila())
								ideal_casa = casa[i];
					}
					else {
						for (i = 0; i < casa.size(); i++)
							if (casa[i].get_suprafata_utila() < ideal_casa.get_suprafata_utila())
								ideal_casa = casa[i];
					}
					cout << "Casa ideala pentru dumneavoastra are o suprafata de " << ideal_casa.get_suprafata_utila() << " mp. Si un teren de " << ideal_casa.get_suprafata_teren() <<
						"mp. Veti primi un discount o data la trei luni de plati ale chiriei de " << ideal_casa.get_discount() << "%. Chiria este de "; ideal_casa.calcul_chirie(pret_mp_casa, 1);
					cout << "cu discount. Fara discount chiria este de "; ideal_casa.calcul_chirie(pret_mp_casa, 0); cout << "\n";
					cout << "Numele fostului chirias este " << ideal_casa.get_client() << " daca doritit sa intrati in contact. \n";
					break;
		case 3:
			agentie = false;
			cout << "Multumim ca ati luat legatura cu noi. \n";		//agentie devine false pentru a iesi din meniu
			break;
		case 4:
			for (i = 0; i < l.size(); i++)
				if (i % 3 != 0)
				{
					cout << *l[i] << " chirie: "; l[i]->calcul_chirie(pret_mp_apartament, 0); cout << "\n";
				} 
				else
				{
					cout << *l[i] << " chirie: "; l[i]->calcul_chirie(pret_mp_casa, 0); cout << "\n";
				}
			break;
		default:
			cout << "Alegerea nu este valida \n";
			cin >> choice;
			break;
			}
		}
		cout << "\n \n \n";
	Apartament a1 = Apartament("Rares", 12, 140, 7);
	Apartament a2 = Apartament(a1);
	Casa c1 = Casa("Stefan", 7, 200, 1000);
	Casa c2 = Casa(c1);
	cout << a2<<" "<<c2;
	return 0;}
