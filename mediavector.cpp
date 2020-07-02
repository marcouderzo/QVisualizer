#include "mediavector.h"
#include <QDebug>

using namespace std;

MediaVector::MediaVector():paths(nullptr), numberOfElements(0), numberOfCells(0){}

MediaVector::~MediaVector()
{
  delete [] paths;
}

void MediaVector::resize()
{
  if(numberOfCells == 0)
      numberOfCells += 1;
  else
      numberOfCells *= 2;

  FileAudio** aux = new FileAudio*[numberOfCells];

  for (unsigned int i = 0; i < numberOfElements; ++i)
    aux[i] = paths[i];

  delete [] paths;
  paths = aux;
}

unsigned int MediaVector::getSize()const
{
  return numberOfElements;
}

unsigned int MediaVector::getCells() const
{
  return numberOfCells;
}

void MediaVector::pop(unsigned int index)
{
    if(numberOfElements != 0 && index < numberOfElements)
    {
        numberOfElements--;
        FileAudio* aux = *(paths+index);
        for(unsigned int i = index; i < numberOfElements; i++)
        {
            *(paths + i) = *(paths + i + 1);
        }
        delete aux;
        paths[numberOfElements] = nullptr;
     }
}


FileAudio* MediaVector::operator [] (unsigned int i) const
{
    return *(paths+i);
}

void MediaVector::push(FileAudio* s)
{
  if(numberOfElements==numberOfCells)
  {
      resize();
  }
  paths[numberOfElements] = s;
  numberOfElements++;
}

void MediaVector::swap(unsigned int i, unsigned int j)
{
    if(i >= numberOfElements || j >= numberOfElements){
        return;
    }
    FileAudio* aux = paths[i];
    paths[i] = paths[j];
    paths[j] = aux;
}


MediaVector::Iterator MediaVector::begin()const
{
    qDebug()<<"from Iterator begin";
    return paths[0];
}

MediaVector::Iterator MediaVector::end()const
{
    qDebug()<<"from Iterator end: number of elements-1"<< numberOfElements-1;
    return paths[numberOfElements-1];
}

/////////////////////////////////////////////////////////////////////////////////////

MediaVector::Iterator::Iterator(FileAudio* ptr):p(ptr){qDebug()<<p;}

MediaVector::Iterator& MediaVector::Iterator::operator ++()
{
    p++;
    return *this;
}

MediaVector::Iterator& MediaVector::Iterator::operator --()
{
    p--;
    return *this;
}

FileAudio& MediaVector::Iterator::operator * () const
{
    return *p;
}

FileAudio* MediaVector::Iterator::operator -> () const
{
    return p;
}

bool MediaVector::Iterator::operator == (const Iterator& it)const
{
    return p == it.p;
}

bool MediaVector::Iterator::operator != (const Iterator& it)const
{
    return p != it.p;
}


MediaVector::ConstIterator::ConstIterator(FileAudio* ptr):p(ptr){}

const FileAudio& MediaVector::ConstIterator::operator*() const
{
    return *p;
}

const FileAudio* MediaVector::ConstIterator::operator->() const
{
    return p;
}

MediaVector::ConstIterator MediaVector::ConstIterator::operator ++()
{
    p++;
    return *this;
}

MediaVector::ConstIterator MediaVector::ConstIterator::operator --()
{
    p--;
    return *this;
}

bool MediaVector::ConstIterator::operator == (const MediaVector::ConstIterator& cit) const
{
    return p == cit.p;
}

bool MediaVector::ConstIterator::operator != (const MediaVector::ConstIterator& cit)const
{
    return p != cit.p;
}
