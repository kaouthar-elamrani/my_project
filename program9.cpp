#include <iostream>

class Test
{
public:
    std::string Name;
    static int count; // static variable count

    void call(std::string name) // la fonction call met valeur au variable Name et incremente le count
    {
        Name = name;
        count++;
    }
    Test() {} // constructeur par defaut
};
int Test::count = 0;
int main()
{
    Test m, k;      // objet de class Test
    m.call("kayy"); // appel a la fonction
    m.call("kayy");
    k.call("jayy");
    k.call("jayy");
    std::cout << "the function call() have been called " << Test::count << " times ."; // affichage

    return 0;
}
