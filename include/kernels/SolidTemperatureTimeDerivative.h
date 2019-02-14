#ifndef SOLIDTEMPERATURETIMEDERIVATIVE
#define SOLIDTEMPERATURETIMEDERIVATIVE

#include "TimeDerivative.h"

// Forward Declarations
class SolidTemperatureTimeDerivative;

template<>
InputParameters validParams<SolidTemperatureTimeDerivative>();

class SolidTemperatureTimeDerivative : public TimeDerivative
{
public:

  SolidTemperatureTimeDerivative(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;


  const MaterialProperty<Real> & _porosity;
  const MaterialProperty<Real> & _solid_density;
  const MaterialProperty<Real> & _cps;


};

#endif //SOLIDTEMPERATURETIMEDERIVATIVE
