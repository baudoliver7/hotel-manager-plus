#ifndef LISTEDECHAMBRES_H
#define LISTEDECHAMBRES_H

#include <QList>
#include "Chambre.h"

template<class T = Chambre*>
class ListeDeChambres : public QList<T>
{
public:
    ListeDeChambres();
    ListeDeChambres(const ListeDeChambres<T> & lc);
    T at(int i);
    T at(QString identifiant);
    void append(const T & t);
    void append(const ListeDeChambres<T> & t);

    inline int getNbreDeChambresLibres(){return m_nbreChambresLibres;};
    inline int getNbreDeChambresOccupees(){return m_nbreChambresOccupees;};
    ListeDeChambres<T> chambresLibres();
    ListeDeChambres<T> chambresOccupees();
    void ranger();
    void rangerParNumero(QList<T> & lc);
    void actualiser();

    typename QList<T>::iterator it;

private:
    int m_nbreChambresLibres;
    int m_nbreChambresOccupees;

};

template<class T>
ListeDeChambres<T>::ListeDeChambres()
{

}

template<class T>
ListeDeChambres<T>::ListeDeChambres(const ListeDeChambres<T> &lc)
{
    QList<T>::clear();
    ListeDeChambres::append(lc);
}

template <class T>
T ListeDeChambres<T>::at(int i)
{
    it = this->begin();
    while(it != this->end())
    {
        if((*it)->identifiant() == QList<T>::at(i)->identifiant())
        {
            return (*it);
        }
        it++;
    }

    return 0;
}

template <class T>
T ListeDeChambres<T>::at(QString identifiant)
{
    it = this->begin();
    while(it != this->end())
    {
        if((*it)->identifiant() == identifiant)
        {
            return (*it);
        }
        it++;
    }

    return 0;
}

template <class T>
void ListeDeChambres<T>::append(const T & t)
{
    QList<T>::append(t);
    this->ranger();
}

template <class T>
ListeDeChambres<T> ListeDeChambres<T>::chambresLibres()
{
    ListeDeChambres<T> chambres;

    for(int i = 0; i < this->size(); i++)
    {
        if(QList<T>::at(i)->libre())
        {
            chambres << QList<T>::at(i);
        }
    }

    return chambres;
}

template <class T>
ListeDeChambres<T> ListeDeChambres<T>::chambresOccupees()
{
    ListeDeChambres<T> chambres;

    for(int i = 0; i < this->size(); i++)
    {
        if(!QList<T>::at(i)->libre())
        {
            chambres << QList<T>::at(i);
        }
    }

    return chambres;
}

template <class T>
void ListeDeChambres<T>::append(const ListeDeChambres<T> & lt)
{
    QList<T>::append(lt);
    this->ranger();
}

template <class T>
void ListeDeChambres<T>::ranger()
{
    QList<T> listeDeChambresLibres;
    QList<T> listeDeChambresOccupees;

    for(int i = 0; i < this->size() ; i++)
    {
        if(QList<T>::at(i)->libre())
        {
            listeDeChambresLibres.append(QList<T>::at(i));
        }

        if(!QList<T>::at(i)->libre())
        {
            listeDeChambresOccupees.append(QList<T>::at(i));
        }
    }

    rangerParNumero(listeDeChambresLibres);
    rangerParNumero(listeDeChambresOccupees);

    this->clear();
    QList<T>::append(listeDeChambresLibres);
    QList<T>::append(listeDeChambresOccupees);

    m_nbreChambresOccupees = listeDeChambresOccupees.count();
    m_nbreChambresLibres = listeDeChambresLibres.count();
}

template <class T>
void ListeDeChambres<T>::actualiser()
{
    ranger();
}

template <class T>
void ListeDeChambres<T>::rangerParNumero(QList<T> & lc)
{
    for(int i = 0; i < lc.count() - 1; i++)
    {
        for(int j = i + 1; j < lc.count(); j++)
        {
            if(lc.at(i)->numero() > lc.at(j)->numero())
            {
                lc.swap(i, j);
            }
        }
    }
}


#endif // LISTEDECHAMBRES_H
