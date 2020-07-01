#ifndef MEDIAVECTOR_H
#define MEDIAVECTOR_H

#include "Model/fileaudio.h"

class MediaVector{

private:

    FileAudio** paths;
    unsigned int numberOfElements;
    unsigned int numberOfCells;
    void resize();

public:

  MediaVector();
  ~MediaVector();
  //costruttore di copia e assegnazione non vengono usate, quindi non saranno ridefinite

  FileAudio* operator [] (unsigned int) const;

  void push(FileAudio*);
  void pop(unsigned int =0);
  void swap(unsigned int, unsigned int);
  unsigned int getSize() const;
  unsigned int getCells() const;

  class Iterator{

    private:
      FileAudio** p;

    public:
      Iterator();
      Iterator(FileAudio*);
      FileAudio& operator *() const;
      FileAudio* operator ->() const;
      Iterator& operator ++ ();
      Iterator& operator -- ();
      bool operator == (const Iterator&)const;
      bool operator != (const Iterator&)const;
  };

  class ConstIterator{

    private:
      FileAudio** p;

    public:
      ConstIterator();
      ConstIterator(FileAudio*);
      const FileAudio& operator *() const;
      const FileAudio* operator ->() const;
      ConstIterator operator ++ ();
      ConstIterator operator -- ();
      bool operator == (const ConstIterator&) const;
      bool operator != (const ConstIterator&) const;

  };

  Iterator begin() const;
  Iterator end() const;

};

#endif
