#ifndef CASTRO_HABEC_F_H
#define CASTRO_HABEC_F_H

#include <AMReX_ArrayLim.H>
#include <AMReX_BLFort.H>

#ifdef __cplusplus
extern "C" {
#else
#define RadBoundCond int
#endif

  void hbmat3(const int* lo, const int* hi,
              int lo_x, int hi_x,
              int ori_lo, int idir,
              BL_FORT_FAB_ARG_3D(mat),
              int cdir, int bctype,
              const int* tf, const int* tf_lo, const int* tf_hi,
              amrex::Real bcl,
              const int* mask, const int* m_lo, const int* m_hi,
              BL_FORT_FAB_ARG_3D(bcoefs),
              amrex::Real beta, const amrex::Real* dx,
              amrex::Real flux_factor,
              const amrex::Real* spa, const int* s_lo, const int* s_hi);

  void hbflx(BL_FORT_FAB_ARG(flux),
             BL_FORT_FAB_ARG(soln),
             ARLIM_P(reglo), ARLIM_P(reghi), 
             const int& cdir, const RadBoundCond& bct,
             const int& bho, const amrex::Real& bcl,
             const amrex::Real* bcval, ARLIM_P(fslo), ARLIM_P(fshi), 
             const BL_FORT_IFAB_ARG(mask),
             BL_FORT_FAB_ARG(bcoefs),
             const amrex::Real& beta, const amrex::Real* dx, const int& inhom);

  void hbflx3(BL_FORT_FAB_ARG(flux),
              BL_FORT_FAB_ARG(soln),
              ARLIM_P(reglo), ARLIM_P(reghi),
              const int& cdir, const int& bctype, const int* tf,
              const int& bho, const amrex::Real& bcl,
              const BL_FORT_FAB_ARG(bcval),
              const BL_FORT_IFAB_ARG(mask),
              BL_FORT_FAB_ARG(bcoefs),
              const amrex::Real& beta, const amrex::Real* dx,
              const amrex::Real& flux_factor, const amrex::Real* r,
              const int& inhom,
              const amrex::Real* spa, ARLIM_P(splo), ARLIM_P(sphi));

  void hdterm(BL_FORT_FAB_ARG(dterm),
              BL_FORT_FAB_ARG(soln),
              ARLIM_P(reglo), ARLIM_P(reghi),
              const int& cdir, const RadBoundCond& bct,
              const amrex::Real& bcl,
              const BL_FORT_FAB_ARG(bcval),
              const BL_FORT_IFAB_ARG(mask),
              BL_FORT_FAB_ARG(dcoefs),
              const amrex::Real* dx);

  void hdterm3(BL_FORT_FAB_ARG(dterm),
               BL_FORT_FAB_ARG(soln),
               ARLIM_P(reglo), ARLIM_P(reghi),
               const int& cdir, const int& bctype, const int* tf,
               const amrex::Real& bcl,
               const BL_FORT_FAB_ARG(bcval),
               const BL_FORT_IFAB_ARG(mask),
               BL_FORT_FAB_ARG(dcoefs),
               const amrex::Real* dx);

  void hmac(const int* lo, const int* hi,
            BL_FORT_FAB_ARG_3D(mat),
            BL_FORT_FAB_ARG_3D(acoefs),
            amrex::Real alpha);

  void hmbc(const int* lo, const int* hi,
            BL_FORT_FAB_ARG_3D(mat),
            BL_FORT_FAB_ARG_3D(bcoefs),
            amrex::Real beta, const amrex::Real* dx, int idir);

  void hmmat(const int* lo, const int* hi,
             BL_FORT_FAB_ARG_3D(mat),
             int cdir, int bct, int bho, amrex::Real bcl,
             const BL_FORT_IFAB_ARG_3D(mask),
             BL_FORT_FAB_ARG_3D(bcoefs),
             amrex::Real beta, const amrex::Real* dx);

  void hmmat3(const int* lo, const int* hi,
              int lo_x, int hi_x,
              int ori_lo, int idir,
              BL_FORT_FAB_ARG_3D(mat),
              int cdir, int bctype,
              const BL_FORT_IFAB_ARG_3D(tf),
              int bho, amrex::Real bcl,
              const BL_FORT_IFAB_ARG_3D(mask),
              BL_FORT_FAB_ARG_3D(bcoefs),
              amrex::Real beta, const amrex::Real* dx,
              amrex::Real flux_factor,
              BL_FORT_FAB_ARG_3D(spa));

  void set_abec_flux(const int* lo, const int* hi,
                     int idir,
                     BL_FORT_FAB_ARG_3D(c), 
                     BL_FORT_FAB_ARG_3D(d), 
                     amrex::Real beta,
                     const amrex::Real* dx,
                     BL_FORT_FAB_ARG_3D(flux));

#ifdef __cplusplus
};
#endif

#endif
