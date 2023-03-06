#include "polinoms.h"

void Polinom::Set()
{
    while (true)
    {
        double coef = 0;
        int deg = 0, tmp = 0;
        cout << "Enter 1 to add a monom or 0 to finish the input" << endl;
        cin >> tmp;
        if (tmp == 1)
        {
            cout << "Enter the coef" << endl;
            cin >> coef;
            if (std::cin.fail())
            {
                throw exception("Coef error");
                return;
            }
            cout << "x^";
            cin >> tmp;
            if (std::cin.fail() || tmp > 9 || tmp < 0)
            {
                throw exception("X-degree error");
                return;
            }
            deg += tmp * 100;
            cout << "y^";
            cin >> tmp;
            if (std::cin.fail() || tmp > 9 || tmp < 0)
            {
                throw exception("Y-degree error");
                return;
            }
            deg += tmp * 10;
            cout << "z^";
            cin >> tmp;
            if (std::cin.fail() || tmp > 9 || tmp < 0)
            {
                throw exception("Z-degree error");
                return;
            }
            deg += tmp;
            if (coef != 0)
            {
                Monom monom(deg, coef);
                polinom.sortInsert(monom);
            }
        }
        else
            return;
    }
}
void Polinom::Print()
{
    Node<Monom>* p = polinom.getFirst();
    cout << "(" << p->data << ")";
    p = p->next;
    while (p)
    {
        cout << " + (" << p->data << ")";
        p = p->next;
    }
    cout << endl;
}
Polinom operator+(Polinom& p1, Polinom& p2)
{
    Polinom res;
    Node<Monom>* ptr_p1 = p1.polinom.getFirst();
    Node<Monom>* ptr_p2 = p2.polinom.getFirst();
    while (ptr_p1 && ptr_p2)
    {
        if (ptr_p1->data < ptr_p2->data)
        {
            res.polinom.sortInsert(ptr_p2->data);
            ptr_p2 = ptr_p2->next;
        }
        else if (ptr_p1->data == ptr_p2->data)
        {
            Monom tmp(ptr_p1->data.getDeg(), ptr_p1->data.getCoef() + ptr_p2->data.getCoef());
            res.polinom.sortInsert(tmp);
            ptr_p1 = ptr_p1->next;
            ptr_p2 = ptr_p2->next;
        }
        else
        {
            res.polinom.sortInsert(ptr_p1->data);
            ptr_p1 = ptr_p1->next;
        }
    }
    while (ptr_p1)
    {
        res.polinom.sortInsert(ptr_p1->data);
        ptr_p1 = ptr_p1->next;
    }
    while (ptr_p2)
    {
        res.polinom.sortInsert(ptr_p2->data);
        ptr_p2 = ptr_p2->next;
    }
    return res;
}
Polinom operator*(Polinom& p1, double coef)
{
    Polinom res;
    Node<Monom>* p = p1.polinom.getFirst();
    while (p)
    {
        Monom tmp(p->data.getDeg(), p->data.getCoef() * coef);
        res.polinom.sortInsert(tmp);
        p = p->next;
    }
    return res;
}
Polinom operator-(Polinom& p1, Polinom& p2)
{
    Polinom res;
    Node<Monom>* ptr_p1 = p1.polinom.getFirst();
    Node<Monom>* ptr_p2 = p2.polinom.getFirst();
    while (ptr_p1 && ptr_p2)
    {
        if (ptr_p1->data < ptr_p2->data)
        {
            res.polinom.sortInsert(ptr_p2->data);
            ptr_p2 = ptr_p2->next;
        }
        else if (ptr_p1->data == ptr_p2->data)
        {
            Monom tmp(ptr_p1->data.getDeg(), ptr_p1->data.getCoef() - ptr_p2->data.getCoef());
            res.polinom.sortInsert(tmp);
            ptr_p1 = ptr_p1->next;
            ptr_p2 = ptr_p2->next;
        }
        else
        {
            res.polinom.sortInsert(ptr_p1->data);
            ptr_p1 = ptr_p1->next;
        }
    }
    while (ptr_p1)
    {
        Monom tmp(ptr_p1->data.getDeg(), (-1) * ptr_p1->data.getCoef());
        res.polinom.sortInsert(tmp);
        ptr_p1 = ptr_p1->next;
    }
    while (ptr_p2)
    {
        Monom tmp(ptr_p2->data.getDeg(), (-1) * ptr_p2->data.getCoef());
        res.polinom.sortInsert(tmp);
        ptr_p2 = ptr_p2->next;
    }
    return res;
}
Polinom operator*(Polinom& p1, Polinom& p2)
{
    Polinom res;
    Node<Monom>* ptr_p1 = p1.polinom.getFirst();
    Node<Monom>* ptr_p2 = p2.polinom.getFirst();
    while (ptr_p1)
    {
        Polinom add;
        while (ptr_p2)
        {
            int fdeg = ptr_p1->data.getDeg() + ptr_p2->data.getDeg();
            if (fdeg / 100 < ptr_p1->data.getDeg() / 100)
                throw exception("X-degree error");
            if (fdeg / 10 % 10 < ptr_p1->data.getDeg() / 10 % 10)
                throw exception("Y-degree error");
            if (fdeg % 10 < ptr_p1->data.getDeg() % 10)
                throw exception("Z-degree error");
            Monom tmp(fdeg, ptr_p1->data.getCoef() * ptr_p2->data.getCoef());
            add.polinom.sortInsert(tmp);
            ptr_p2 = ptr_p2->next;
        }
        res = res + add;
        ptr_p2 = p2.polinom.getFirst();
        ptr_p1 = ptr_p1->next;
    }
    return res;
}
