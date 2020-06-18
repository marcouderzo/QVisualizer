#ifndef ONDA_H
#define ONDA_H

#include <vector>
#include <complex>

class Onda{

private:
  unsigned int frames;

public:

  Onda();
  virtual ~Onda() = default;
  void setFrames(unsigned int);
  unsigned int getFrames() const;
  virtual std::vector<double> run(std::complex<double>*, unsigned int, unsigned int, double ) = 0;

};

#endif
