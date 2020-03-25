#include "MediaVector.h"

//create media vector empty
MediaVector::MediaVector(): numberOfElements(0){
  paths = new std::string*[0];
}

//crea una playlist dal file f
MediaVector::MediaVector(fstream& f){
  paths = new std::string*[0];
  try{
    loadFromFile(f);
  }catch(std::exception& ex){
    std::cerr << "Could not open file" << std::endl;
    delete this;
  }
}

MediaVector::~MediaVector(){
  delete [] paths;
}

bool MediaVector::loadFromFile(fstream& f)
{
  f.open();
  if(!f){
    throw std::runtime_error("Could not open file");
  }
  int i = 0;
  while(!eof){

    std::string word;
    std::cin >> word;
    if(numberOfCells == numberOfElements){
      resize();
    }
    paths[i] = word;
    i++;
    numberOfElements++;
  }
  f.close();
}

void MediaVector::resize(){

  std::string aux [numberOfCells];
  for(int i = 0; i < numberOfCells; i++){

      aux[i] = paths[i];
  }
  delete[] paths;
  numberOfCells *= 2;
  paths = new string*[numberOfCells];
  for(int i = 0; i < numberOfCells; i++){

      paths[i] = aux[i];
  }
}

unsigned int MediaVector::getSize()const{
  return numberOfElemets;
}

unsigned int MediaVector::getCells() const{
  return numberOfCells;
}

string MediaVector::pop(unsigned int index){

}

void MediaVector::empty(){

  for(int i = 0; i < numberOfElments; i++){
      pop();
  }
}

void MediaVector::push(std::string s){

  if(numberOfElments==numberOfCells){
    resize();
  }
  numberOfElements++;
  paths[numberOfElments] = s;
}
