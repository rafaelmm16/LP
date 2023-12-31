/*
 * Copyright (c) 2005-2009 Jaroslav Gresula
 *
 * Distributed under the MIT license (See accompanying file
 * LICENSE.txt or copy at http://jagpdf.org/LICENSE.txt)
 *
 */
#ifndef ERRCODES_JG1528_H__
#define ERRCODES_JG1528_H__

//#include <D:\Estudos e Faculdade\)))CEUNES\LP - Linguagem de programação\TrabalhoLP\jagpdf-1.4.0.win32.x86.c_cpp\include\jagpdf\detail\types.h>
#include "D:\Estudos e Faculdade\)))CEUNES\LP - Linguagem de programação\TrabalhoLP\jagpdf-1.4.0.win32.x86.c_cpp\include\jagpdf\detail\types.h"
/*
 * error codes
 */

#ifdef __cplusplus
namespace jag {
namespace pdf
{
  const jag_Int err_no_error           = 0;
  const jag_Int err_invalid_operation  = 1;
  const jag_Int err_io_error           = 2;
  const jag_Int err_internal_error     = 3;
  const jag_Int err_invalid_input      = 4;
  const jag_Int err_invalid_value      = 5;
  const jag_Int err_operation_failed   = 6;
}}
#else

#define jag_err_no_error           0
#define jag_err_invalid_operation  1
#define jag_err_io_error           2
#define jag_err_internal_error     3
#define jag_err_invalid_input      4
#define jag_err_invalid_value      5
#define jag_err_operation_failed   6

#endif


#endif
/** EOF @file */
