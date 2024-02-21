#include <iostream>
#include <ostream> 

class Item
{
private:
    int _key, _val;

public:
    Item() : _key(0), _val(0) {};
    Item(int key, int val) : _key(key), _val(val) {}
    friend std::ostream &operator<<(std::ostream &out, const Item &i)
    {
        out << "(" << i._key << "," << i._val << ")";
        return out;
    } // Impressão de i: "(<item._key>,<item._val>)". Sem quebra de linha. Sem as aspas
    friend bool operator>(const Item &i1, const Item &i2)
    {
        return i1._val > i2._val;
    } // i1 > i2 se e somente se i1._val > i2._val
};
