#ifndef MEDIAVECTOR_H
#define MEDIAVECTOR_H

#include <iostream>
#include <fstream>

class MediaVector{

private:

    std::string* paths;
    unsigned int numberOfElements;
    unsigned int numberOfCells;
    bool loadFromFile(fstream&);
    unsigned int getSize() const;
    unsigned int getCells() const;
    void resize();

public:

  MediaVector();
  explicit MediaVector(fstream& )//per caricare la playlist

  ~MediaVector();
  //costruttore di copia e assegnazione non vengono usate, quindi non saranno ridefinite

  std::string* operator [] (unsigned int) const;
  std::string& operator * () const;
  std::string* operator -> () const;

  void push(std::string);
  string pop(unsigned int =0);
  void empty();
  void exportPlaylist() const;

  void swap();

  class Iterator{

    private:
      std::string* p;

    public:
      Iterator();
      std::string& operator *() const;
      std::string* operator ->() const;
      Iterator operator ++ (int);
      Iterator operator -- (int);
  };

  class ConstIterator{};

    private:
      const std::string* p;

    public:
      ConstIterator();
      const std::string& operator *() const;
      const std::string* operator ->() const;
      Iterator operator ++ (int);
      Iterator operator -- (int);

  };

#endif
