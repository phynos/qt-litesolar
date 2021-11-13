#ifndef TTT_GLOBAL_H
#define TTT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TTT_LIBRARY)
#  define TTTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TTTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TTT_GLOBAL_H
