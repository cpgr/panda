#ifndef SOLIDTEMPERATURESOURCE_H
#define SOLIDTEMPERATURESOURCE_H

#include "Kernel.h"

// Forward Declaration
class SolidTemperatureSource;

template<>
InputParameters validParams<SolidTemperatureSource>();

class SolidTemperatureSource : public Kernel
{
public:
  SolidTemperatureSource(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

   const  MaterialProperty<Real> & _source_rate;

};
#endif //SOLIDTEMPERATURESOURCE_H
