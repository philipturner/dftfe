#ifndef NNGGA_H
#define NNGGA_H
#ifdef DFTFE_WITH_TORCH
#  include <string>
#  include <torch/torch.h>
#  include <excDensityPositivityCheckTypes.h>
namespace dftfe
{
  class NNGGA
  {
  public:
    NNGGA(std::string                          modelFileName,
          const bool                           isSpinPolarized = false,
          const excDensityPositivityCheckTypes densityPositivityCheckType =
            excDensityPositivityCheckTypes::MAKE_POSITIVE,
          const double rhoTol = 1.0e-8);
    ~NNGGA();
    void
    evaluateexc(const double *     rho,
                const double *     sigma,
                const unsigned int numPoints,
                double *           exc);
    void
    evaluatevxc(const double *     rho,
                const double *     sigma,
                const unsigned int numPoints,
                double *           exc,
                double *           dexc);

  private:
    std::string                          d_modelFileName;
    torch::jit::script::Module *         d_model;
    const bool                           d_isSpinPolarized;
    const double                         d_rhoTol;
    const excDensityPositivityCheckTypes d_densityPositivityCheckType;
  };
} // namespace dftfe
#endif
#endif // NNGGA_H
