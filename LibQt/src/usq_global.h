#ifndef USQ_GLOBAL_H
#define USQ_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(USQ_LIBRARY)
#  define USQSHARED_EXPORT Q_DECL_EXPORT
#else
#  define USQSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // USQ_GLOBAL_H
