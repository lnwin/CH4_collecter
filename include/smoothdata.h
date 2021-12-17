//
// MATLAB Compiler: 7.1 (R2019b)
// Date: Fri Dec 17 15:00:57 2021
// Arguments:
// "-B""macro_default""-W""cpplib:smoothdata,all,version=1.0""-T""link:lib""-d""
// C:\Users\Administrator\Desktop\smoothdata\for_testing""-v""C:\Users\Administr
// ator\Desktop\smoothdata.m"
//

#ifndef smoothdata_h
#define smoothdata_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_smoothdata_C_API 
#define LIB_smoothdata_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_smoothdata_C_API 
bool MW_CALL_CONV smoothdataInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_smoothdata_C_API 
bool MW_CALL_CONV smoothdataInitialize(void);

extern LIB_smoothdata_C_API 
void MW_CALL_CONV smoothdataTerminate(void);

extern LIB_smoothdata_C_API 
void MW_CALL_CONV smoothdataPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_smoothdata_C_API 
bool MW_CALL_CONV mlxSmoothdata(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_smoothdata
#define PUBLIC_smoothdata_CPP_API __declspec(dllexport)
#else
#define PUBLIC_smoothdata_CPP_API __declspec(dllimport)
#endif

#define LIB_smoothdata_CPP_API PUBLIC_smoothdata_CPP_API

#else

#if !defined(LIB_smoothdata_CPP_API)
#if defined(LIB_smoothdata_C_API)
#define LIB_smoothdata_CPP_API LIB_smoothdata_C_API
#else
#define LIB_smoothdata_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_smoothdata_CPP_API void MW_CALL_CONV smoothdata(int nargout, mwArray& y, mwArray& winsz, const mwArray& A, const mwArray& varargin);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
