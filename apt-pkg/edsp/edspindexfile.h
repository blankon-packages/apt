// -*- mode: cpp; mode: fold -*-
// Description								/*{{{*/
/* ######################################################################
   The scenario file is designed to work as an intermediate file between
   APT and the resolver. Its on propose very similar to a dpkg status file
   ##################################################################### */
									/*}}}*/
#ifndef PKGLIB_EDSPINDEXFILE_H
#define PKGLIB_EDSPINDEXFILE_H

#include <apt-pkg/indexfile.h>
#include <apt-pkg/debindexfile.h>

class edspIndex : public debStatusIndex
{
   /** \brief dpointer placeholder (for later in case we need it) */
   void *d;

   public:

   virtual const Type *GetType() const;

   virtual bool Merge(pkgCacheGenerator &Gen,OpProgress *Prog) const;

   edspIndex(string File);
};

#endif
