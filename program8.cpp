#include <iostream>

using namespace std;

class Media
{
public:
    char *titre;
    virtual void imprimer() // puisque cette methode est utilisé dans les sous classes , virtual ici va permettre d'afficher pour chaque sous classe le contenu de cette methode redefinie dedans
    {
        cout << "Hey I'm the media class !" << endl;
    }
    char *id() // dans cette fonction j'ai donné valeur au titre
    {
        titre = "Eat Pray Love ...";
        return titre;
    }
    Media() // constructeur par defaut
    {
    }
};
class Livre : public Media // class herité du Media a la meme fonction imprimer() que la classe mere et sa propre fontion est attribu
{
public:
    string author;
    void author_book(string auteur)
    {
        author = auteur;
    }
    void imprimer()
    {
        cout << "L'auteur du livre est :" << author << endl;
    }

    Livre()
    {
    }
};

class Audio : public Media
{
public:
    string length;
    void length_audio(string len)
    {
        length = len;
    }
    void imprimer()
    {
        cout << "La longueur du audio est :" << length << endl;
    }

    Audio() {}
};
class CD : public Audio // cette classe herite du classe Media et aussi Audio
{
public:
    string voice;
    void voice_up(string voix)
    {
        voice = voix;
    }
    void imprimer()
    {
        cout << "Turn the voice " << voice << endl;
    }

    CD() {}
};

class Cassette : public Audio // cette classe herite du classe Media et aussi Audio
{
public:
    string voix;
    void voice_down(string v)
    {
        voix = v;
    }
    void imprimer()
    {
        cout << "Turn the voice " << voix << endl;
    }

    Cassette() {}
};

class Disque : public Audio // cette classe herite du classe Media et aussi Audio
{
public:
    string pla;
    void disque_playing(string p)
    {
        pla = p;
    }
    void imprimer()
    {
        cout << "The disque is " << pla << endl;
    }

    Disque() {}
};

class Presse : public Media // herite du classe Media
{
public:
    int number;
    void publier(int num)
    {
        number = num;
    }
    void imprimer()
    {
        cout << "The number of newspaper published today is " << number << endl;
    }

    Presse() {}
};
class Magazine : public Presse // cette classe herite du classe Media et aussi Presse
{
public:
    string celebrity;
    void couver(string cel)
    {
        celebrity = cel;
    }
    void imprimer()
    {
        cout << "The celebrity in the magazine cover is " << celebrity << endl;
    }

    Magazine() {}
};
class Journal : public Presse // cette classe herite du classe Media et aussi Presse
{
public:
    int numRub;
    void rubrique(int num)
    {
        numRub = num;
    }
    void imprimer()
    {
        cout << "The number of rubrics is " << numRub << endl;
    }

    Journal() {}
};

class Revue : public Presse // cette classe herite du classe Media et aussi Presse
{
public:
    int numEdi;
    void edition(int num)
    {
        numEdi = num;
    }
    void imprimer()
    {
        cout << "The number of edition is " << numEdi << endl;
    }

    Revue() {}
};

int main()
{
    Media m;
    m.imprimer();                          // appel au fonction imprimer definie dans la classe Media
    cout << "title is " << m.id() << endl; // appel au fonction id definie dans la classe Media et afficher son resultat
    Livre l;                               // objet l de la sous classe livre
    l.author_book("Robert Kiyosaki");      // la fontion definie dans la classe Livre et mettre une valeur au attribut
    // meme pour le reste
    Audio a;
    a.length_audio(" 1 min 35 s");
    CD c;
    c.voice_up("Up");
    Cassette s;
    s.voice_down("down");
    Disque d;
    d.disque_playing("playing...");
    Presse p;
    p.publier(456);
    Magazine k;
    k.couver("Gigi Hadid");
    Journal j;
    j.rubrique(7);
    Revue r;
    r.edition(5);

    Media *e1 = &l; // pointeur de la classe media qui pointe sur l'adresse d'objet l de la classe Livre
    e1->imprimer(); // imprimé le contenu de la fonction imprimer redefini dans la classe Livre
    Media *e2 = &a;
    e2->imprimer();
    Media *e3 = &c; // ici le pointeur *e3 peut etre un objet de la classe Media ou de classe Audio parcequ'il herite des deux
    e3->imprimer();
    Audio *e4 = &s; // comme ici
    e4->imprimer();
    Media *e5 = &d;
    e5->imprimer();
    Media *e6 = &p;
    e6->imprimer();
    Media *e7 = &k;
    e7->imprimer();
    Media *e8 = &j;
    j.imprimer();
    Media *e9 = &r;
    e9->imprimer();

    return 0;
}
