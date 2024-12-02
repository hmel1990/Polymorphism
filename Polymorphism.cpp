#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;


class Device 
{
protected:
    string brand;
    string model;
    string name;
    int capacity; // ёмкость носителя
    int quantity; // количество
public:
    void set_brand(string brand)
    {
        this->brand = brand;
    }

    void set_model(string model)
    {
        this->model = model;
    }

    void set_name(string name)
    {
        this->name = name;
    }

    void set_capacity(int capacity)
    {
        this->capacity = capacity;
    }

    void set_quantity(int quantity)
    {
        this->quantity = quantity;
    }

    string get_brand()
    {
        return brand;
    }

    string get_model()
    {
        return model;
    }

    string get_name()
    {
        return name;
    }

    int get_capacity()
    {
        return capacity;
    }

    int get_quantity()
    {
        return quantity;
    }

    Device()
    {
        brand = "";
        model = "";
        name = "";
        capacity = 1;
        quantity = 1;
    }

    virtual void print()
    {
        cout << brand << "\n" << model << "\n" << name << "\n" << capacity << "\n" << quantity << "\n";
    }

    virtual void device_load()
    {
        cout << "«данные загружены»\n";
    }

    virtual void device_save()
    {
        cout << "«данные сохранены»\n";
    }
};

class HDD :public Device
{
public:
    void print () override
    {
        cout << brand << "\n" << model << "\n" << name << "\n" << capacity << "\n" << quantity << "\n" << "HDD";
    }

    void device_load() override
    {
        cout << "«данные загружены в жесткий диск»\n";
    }

    void device_save() override
    {
        cout << "«данные сохранены в жестком диске»\n";
    }
};

class Smartphone :public Device
{
public:
    void print() override
    {
        cout << brand << "\n" << model << "\n" << name << "\n" << capacity << "\n" << quantity << "\n" << "Smartphone";
    }

    void device_load() override
    {
        cout << "«данные загружены в смартфон»\n";
    }

    void device_save() override
    {
        cout << "«данные сохранены в смартфоне»\n";
    }
};
class Tablet :public Device
{
public:
    void print() override
    {
        cout << brand << "\n" << model << "\n" << name << "\n" << capacity << "\n" << quantity << "\n" << "Tablet";
    }

    void device_load() override
    {
        cout << "«данные загружены в планшет»\n";
    }

    void device_save() override
    {
        cout << "«данные сохранены в планшете\n";
    }
};


int main()
{
    setlocale(0, "");
    
    
      HDD *h = new HDD;
    Smartphone *s = new Smartphone;
    Tablet *t = new Tablet;

    vector <Device*> devices = {h,s,t};

    devices[0]->print();
    cout << "\n";
    devices[1]->device_save();
    cout << "\n";
    devices[2]->device_load();

    cout << "\nЗаполняем поля\n";
    devices[1]->set_brand("Apple");
    devices[1]->set_model("Pro Max");
    devices[1]->set_name("Iphone");
    devices[1]->set_capacity(256);
    devices[1]->set_quantity(5);
    devices[1]->print();

    for (auto device : devices)
    {
        delete device;
    }
    
  

    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //Используем список и итератор
    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    
    srand(time(0));

    list<Device*>devices2;
    
    for (int i = 0; i < 25; i++)
    {
        int r = rand() % 3+1;
        if (r == 1)
        {
            devices2.push_back(new HDD());
        }
        else if (r == 2)
        {
            devices2.push_back(new Smartphone());
        }
        else if (r == 3)
        {
            devices2.push_back(new Tablet());
        }    
    }

    list<Device*>::iterator it;
    it = devices2.begin();

    (*it)->device_load();


    advance(it, 4);
    cout << "Тип объекта: " << typeid(**it).name() << "\n";

    (*it)->device_load();
    (*it)->set_model("Samsung");
    cout << ((*it)->get_model());

    for (auto device : devices2)
    {
        delete device;
    }

}

