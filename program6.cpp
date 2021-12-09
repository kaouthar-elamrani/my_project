#include <iostream>
using std::string;
class Personne
{
private:
    string Nom;
    string Prenom;
    string DateNaissance;

public:
    Personne(string lname, string fname, string dateOfBirth) // mettre les valeurs au variables
    {
        Nom = lname;
        Prenom = fname;
        DateNaissance = dateOfBirth;
    }
    // les variables sont privés ils ne vont pas etre accessible aux autres classes que par que les getters qui retourne ses variables

    string getNom()
    {
        return Nom;
    }

    string getPrenom()
    {
        return Prenom;
    }

    string getDateNaissance()
    {
        return DateNaissance;
    }

    void Afficher()
    {
        std::cout << " Hey last name is " << Nom << " . My first name is " << Prenom << " . I was born on " << DateNaissance << std::endl;
    }
};
class Employe : public Personne // sous classe employe
{
public:
    double Salaire;
    Employe(string lname, string fname, string dateOfBirth, double salary) : Personne(lname, fname, dateOfBirth) // constructeur a herité 3 variables du constructeur Personne et definie un nouvel variable
    {
        Salaire = salary;
    }
    void Afficher() // redefinition de Afficher() : aspect de polymorphisme
    {
        std::cout << " Hey last name is " << getNom() << " . My first name is " << getPrenom() << " . I was born on " << getDateNaissance() << " . I get " << Salaire << " $ ." << std::endl;
    }
};
class Chef : public Employe
{
public:
    string Service;
    Chef(string lname, string fname, string dateOfBirth, double salary, string service) : Employe(lname, fname, dateOfBirth, salary)
    {
        Service = service;
    }
    void Afficher()
    {
        std::cout << " Hey last name is " << getNom() << " . My first name is " << getPrenom() << " . I was born on " << getDateNaissance() << " . I get " << Salaire << " $ ."
                  << "I'm a " << Service << std::endl;
    }
};
class Directeur : Chef
{
public:
    string Societe;
    Directeur(string lname, string fname, string dateOfBirth, double salary, string service, string company) : Chef(lname, fname, dateOfBirth, salary, service)
    {
        Societe = company;
    }
    void Afficher()
    {
        std::cout << " Hey last name is " << getNom() << " . My first name is " << getPrenom() << " . I was born on " << getDateNaissance() << " . I get " << Salaire << " $ ."
                  << "I'm a " << Service << " at " << Societe << std::endl;
    }
};

int main()
{
    Personne P = Personne("amr", "kayy", "10/01/1999");
    P.Afficher();
    Employe E = Employe("amr", "kayy", "10/01/1999", 1875.5);
    E.Afficher();
    Chef C = Chef("amr", "kayy", "10/01/1999", 1875.5, "Manager");
    C.Afficher();
    Directeur D = Directeur("amr", "kayy", "10/01/1999", 1875.5, "Manager", "PMCOM");
    D.Afficher();

    return 0;
}