#ifndef MEDIAVECTOR_H
#define MEDIAVECTOR_H

#include "Model/fileaudio.h"

template <class T>
class MediaVector{

private:

    T* paths;
    unsigned int numberOfElements;
    unsigned int numberOfCells;
    void resize();

public:

  MediaVector();
  ~MediaVector();
  //costruttore di copia e assegnazione non vengono usate, quindi non saranno ridefinite

  T& operator [] (unsigned int) const;

  void push(T*);
  void pop(unsigned int =0);
  void swap(unsigned int, unsigned int);
  unsigned int getSize() const;
  unsigned int getCells() const;

  class Iterator{

    private:
      T* p;

    public:
      Iterator(T*);
      T& operator *() const;
      T* operator ->() const;
      Iterator& operator ++ ();
      Iterator& operator -- ();
      bool operator == (const Iterator&)const;
      bool operator != (const Iterator&)const;
  };

  class ConstIterator{

    private:
      T* p;

    public:
      ConstIterator(T*);
      const T& operator *() const;
      const T* operator ->() const;
      ConstIterator& operator ++ ();
      ConstIterator& operator -- ();
      bool operator == (const ConstIterator&) const;
      bool operator != (const ConstIterator&) const;

  };

  ConstIterator begin() const;
  ConstIterator end() const;

};

#endif

template<class T>
MediaVector<T>::MediaVector():paths(nullptr), numberOfElements(0), numberOfCells(0){}

template <class T>
MediaVector<T>::~MediaVector(){

    delete[] paths;
}

template<class T>
T& MediaVector<T>::operator [] (unsigned int i)const{

    return paths[i];
}

template<class T>
unsigned int MediaVector<T>::getCells() const{

    return numberOfCells;
}

template<class T>
unsigned int MediaVector<T>::getSize() const{

    return numberOfElements;
}

template <class T>
void MediaVector<T>::pop(unsigned int i){

    if(i >= 0 && i < numberOfElements){

        T* aux = paths + i;
        for(unsigned int j = i; j < numberOfElements - 1; j++){

            paths[j] = paths[j + 1];
        }
        paths[numberOfElements - 1] = nullptr;
        delete aux;
        numberOfElements--;
    }
}

template <class T>
void MediaVector<T>::resize(){

    if(numberOfCells == 0){

        numberOfCells = 1;
    }else{

        numberOfCells *= 2;
    }

    T* aux = paths;
    paths = new T[numberOfCells];

    for(unsigned int i = 0; i < numberOfElements; i++){

        paths[i] = aux[i];
    }

    delete[] aux;
}

template <class T>
void MediaVector<T>::push(T* t){

    if(numberOfCells == numberOfElements){

        resize();
    }
    paths[numberOfElements] = *t;
    numberOfElements++;
}

template <class T>
void MediaVector<T>::swap(unsigned int i, unsigned int j){

    T* aux = paths + i;
    paths[i] = paths[j];
    paths[j] = *aux;
}

template<class T>
typename MediaVector<T>::ConstIterator MediaVector<T>::begin()const{

    return ConstIterator(paths);
}

template<class T>
typename MediaVector<T>::ConstIterator MediaVector<T>::end() const{

    return ConstIterator(paths + numberOfElements);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
MediaVector<T>::Iterator::Iterator(T* ptr):p(ptr){}

template <class T>
T& MediaVector<T>::Iterator::operator *() const{

    return *p;
}

template <class T>
T* MediaVector<T>::Iterator::operator ->() const{

    return p;
}

template <class T>
typename MediaVector<T>::Iterator& MediaVector<T>::Iterator::operator ++(){

    p++;
    return *this;
}

template <class T>
typename MediaVector<T>::Iterator& MediaVector<T>::Iterator::operator --(){

    p--;
    return *this;
}

template <class T>
bool MediaVector<T>::Iterator::operator ==(const Iterator& it) const{

    return p == it.p;
}

template <class T>
bool MediaVector<T>::Iterator::operator !=(const Iterator& it) const{

    return p != it.p;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
MediaVector<T>::ConstIterator::ConstIterator(T* ptr):p(ptr){}

template <class T>
const T& MediaVector<T>::ConstIterator::operator *() const{

    return *p;
}

template <class T>
const T* MediaVector<T>::ConstIterator::operator ->() const{

    return p;
}

template <class T>
typename MediaVector<T>::ConstIterator& MediaVector<T>::ConstIterator::operator ++(){

    p++;
    return *this;
}

template <class T>
typename MediaVector<T>::ConstIterator& MediaVector<T>::ConstIterator::operator --(){

    p--;
    return *this;
}

template <class T>
bool MediaVector<T>::ConstIterator::operator ==(const ConstIterator& it) const{

    return p == it.p;
}

template <class T>
bool MediaVector<T>::ConstIterator::operator !=(const ConstIterator& it) const{

    return p != it.p;
}
