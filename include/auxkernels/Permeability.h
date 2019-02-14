

#ifndef PERMEABILITY_H
#define PERMEABILITY_H

#include "AuxKernel.h"

//Forward Declarations
class Permeability;

template<>
InputParameters validParams<Permeability>();

/**
 * Constant auxiliary value
 */
class Permeability : public AuxKernel
{
public:
  Permeability(const InputParameters & parameters);

  virtual ~Permeability() {}

protected:
  /**
   * AuxKernels MUST override computeValue.  computeValue() is called on
   * every quadrature point.  For Nodal Auxiliary variables those quadrature
   * points coincide with the nodes.
   */
  virtual Real computeValue() override;

  const MaterialProperty<Real> & _Re;
};

#endif //PERMEABILITY_H
