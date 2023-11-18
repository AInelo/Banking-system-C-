#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class Bank_Account
{
	int Money_Deposit;
	char type;
	int acno;
	char name[70];
public:
	
	void report() const;
	int retMoney_Deposit() const;
	void create_Bank_Account();
	void dep(int);
	int retacno() const;
	void Display_Account() const;
	void Updation();
	char rettype() const;
	void draw(int);
};      


void Bank_Account::Updation()
{
	cout<<"\n\tBank_Account No. : "<<acno;
	cout<<"\n\tMise a jour du nom du titulaire du compte bancaire : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tType de mise a jour du compte_bancaire : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tSolde de mise a jour Total-Argent : ";
	cin>>Money_Deposit;
}
void Bank_Account::create_Bank_Account()
{
	system("CLS");
	cout<<"\n\tVeuillez saisir le numero de compte_bancaire : ";
	cin>>acno;
	cout<<"\n\n\tVeuillez saisir le nom du titulaire du compte Bank_Account : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tVeuillez saisir le type de compte_bancaire (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tVeuillez saisir le montant total de depart : ";
	cin>>Money_Deposit;
	cout<<"\n\n\tCompte_bancaire cree..";
}

void Bank_Account::Display_Account() const
{
	cout<<"\n\tBank_Account No. : "<<acno;
	cout<<"\n\tNom du titulaire du compte bancaire : ";
	cout<<name;
	cout<<"\n\tType de compte_bancaire : "<<type;
	cout<<"\n\tSolde Total-Argent : "<<Money_Deposit;
}
int Bank_Account::retacno() const
{
	return acno;
}


char Bank_Account::rettype() const
{
	return type;
}
void Bank_Account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<Money_Deposit<<endl;
}
void Bank_Account::dep(int x)
{
	Money_Deposit+=x;
}
void Bank_Account::draw(int x)
{
	Money_Deposit-=x;
}
int Bank_Account::retMoney_Deposit() const
{
	return Money_Deposit;
}


void write_Bank_Account();
void display_sp(int);
void display_all();

void delete_Bank_Account(int);
void Money_Deposit_withdraw(int, int);
void Updation_Bank_Account(int);
int main()
{
	char ch;
	int num;
	do
	{
	system("CLS");
	cout<<"\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	
	cout<<"\t\tSYSTeME DE GESTION BANCAIRE";
	cout<<"\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

		cout<<"\t\t    ::MENU PRINCIPAL::\n";
		cout<<"\n\t\t1. NOUVEAU compte_bancaire";
		cout<<"\n\t\t2. Money_Deposit Total-Argent";
		cout<<"\n\t\t3. RETIRER l'argent total";
		cout<<"\n\t\t4. DEMANDE DE SOLDE";
		cout<<"\n\t\t5. LISTE DE TOUS LES TITULAIRES DE TITULAIRES DE COMPTES BANCAIRES";
		cout<<"\n\t\t6. FERMER UN compte_bancaire";
		cout<<"\n\t\t7. Mise a jour d'AN Bank_Account";
		cout<<"\n\t\t8. SORTIE";
		cout<<"\n\n\t\tSelectionnez votre option (1-8): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_Bank_Account();
			break;
		case '2':
			system("CLS");
			cout<<"\n\n\tVeuillez entrer le numero de compte bancaire : "; cin>>num;
			Money_Deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\tVeuillez entrer le numero de compte bancaire : "; cin>>num;
			Money_Deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\tVeuillez entrer le numero de compte bancaire. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout<<"\n\n\tVeuillez entrer le numero de compte bancaire. : "; cin>>num;
			delete_Bank_Account(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\tVeuillez entrer le numero de compte bancaire. : "; cin>>num;
			Updation_Bank_Account(num);
			break;
		 case '8':
		 	system("CLS");
			cout<<"\n\n\tPresente par ainelo.com";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}





void write_Bank_Account()
{
	Bank_Account ac;
	ofstream outFile;
	outFile.open("Bank_Account.dat",ios::binary|ios::app);
	ac.create_Bank_Account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
	outFile.close();
}
void delete_Bank_Account(int n)
{
	Bank_Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Le fichier n'a pas pu être ouvert !! Appuyez sur une touche...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		}
	}
    inFile.close();
	outFile.close();
	remove("Bank_Account.dat");
	rename("Temp.dat","Bank_Account.dat");
	cout<<"\n\nRecord Deleted ..";
}

void display_sp(int n)
{
	Bank_Account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Le fichier n'a pas pu être ouvert !! Appuyez sur une touche...";
		return;
	}
	cout<<"\n\tDeTAILS DU SOLDE\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\tLe numero de compte_banque n'existe pas";
}


void display_all()
{
	system("CLS");
	Bank_Account ac;
	ifstream inFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"Le fichier n'a pas pu être ouvert !! Appuyez sur une touche...";
		return;
	}
	cout<<"\n\n\t\tLISTE DES TITULAIRES DE COMPTES_BANCAIRES\n\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	cout<<"A/c no.      NOM           Type Solde du compte\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		ac.report();
	}
	inFile.close();
}
void Updation_Bank_Account(int n)
{
	bool found=false;
	Bank_Account ac;
	fstream File;
    File.open("Bank_Account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"Le fichier n'a pas pu être ouvert !! Appuyez sur une touche...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			cout<<"\n\n\tVeuillez saisir les nouveaux details de Bank_Account"<<endl;
			ac.Updation();
			int pos=(-1)*static_cast<int>(sizeof(Bank_Account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		    cout<<"\n\n\tEnregistrement mis a jour";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\tEnregistrement non trouve ";
}

void Money_Deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Bank_Account ac;
	fstream File;
    File.open("Bank_Account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"Le fichier n'a pas pu être ouvert !! Appuyez sur une touche...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			if(option==1)
			{
				cout<<"\n\n\tTO Money_DepositSS Total-Argent";
				cout<<"\n\n\tVeuillez saisir le montant total a deposer : ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tPOUR RETIRER l'argent total";
				cout<<"\n\n\tVeuillez saisir le montant total a retirer : ";
				cin>>amt;
				int bal=ac.retMoney_Deposit()-amt;
				if(bal<0)
					cout<<"Insuffisance du solde";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
			cout<<"\n\n\tEnregistrement mis a jour";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\tEnregistrement non trouve ";

}
