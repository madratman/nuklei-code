#ifndef NUKLEI_TXTOBSERVATION_H
#define NUKLEI_TXTOBSERVATION_H


#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <boost/shared_ptr.hpp>

#include <nuklei/Definitions.h>
#include <nuklei/Color.h>
#include <nuklei/LinearAlgebra.h>
#include <nuklei/Observation.h>
#include <nuklei/member_clone_ptr.h>

namespace nuklei {



  /**
   * Text format reader.
   * @author Renaud Detry <detryr@montefiore.ulg.ac.be>
   */
  class TxtObservation : public Observation
    {
    public:
      static const double TOL;
      
      Type type() const { return TXT; }
 
      std::auto_ptr<kernel::base> getKernel() const
      {
        return k_->clone();
      }
      
      void setKernel(const kernel::base& k)
      {
        NUKLEI_TRACE_BEGIN();
        k_ = k;
        NUKLEI_TRACE_END();
      }
  
      TxtObservation();
      TxtObservation(const kernel::base& k);
      ~TxtObservation() {};

    private:
      member_clone_ptr<kernel::base> k_;
    };

}

#endif
