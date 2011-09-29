// ijones, walters
#ifndef PKGLIB_DEBMETAINDEX_H
#define PKGLIB_DEBMETAINDEX_H

#include <apt-pkg/metaindex.h>
#include <apt-pkg/sourcelist.h>

#include <map>

class debReleaseIndex : public metaIndex {
   public:

   class debSectionEntry
   {
      public:
      debSectionEntry (string const &Section, bool const &IsSrc);
      string const Section;
      bool const IsSrc;
   };

   private:
   /** \brief dpointer placeholder (for later in case we need it) */
   void *d;
   std::map<string, vector<debSectionEntry const*> > ArchEntries;
   enum { ALWAYS_TRUSTED, NEVER_TRUSTED, CHECK_TRUST } Trusted;

   public:

   debReleaseIndex(string const &URI, string const &Dist);
   debReleaseIndex(string const &URI, string const &Dist, bool const Trusted);
   virtual ~debReleaseIndex();

   virtual string ArchiveURI(string const &File) const {return URI + File;};
   virtual bool GetIndexes(pkgAcquire *Owner, bool const &GetAll=false) const;
   vector <struct IndexTarget *>* ComputeIndexTargets() const;
   string Info(const char *Type, string const &Section, string const &Arch="") const;
   string MetaIndexInfo(const char *Type) const;
   string MetaIndexFile(const char *Types) const;
   string MetaIndexURI(const char *Type) const;
   string IndexURI(const char *Type, string const &Section, string const &Arch="native") const;
   string IndexURISuffix(const char *Type, string const &Section, string const &Arch="native") const;
   string SourceIndexURI(const char *Type, const string &Section) const;
   string SourceIndexURISuffix(const char *Type, const string &Section) const;
   string TranslationIndexURI(const char *Type, const string &Section) const;
   string TranslationIndexURISuffix(const char *Type, const string &Section) const;
   virtual vector <pkgIndexFile *> *GetIndexFiles();

   void SetTrusted(bool const Trusted);
   virtual bool IsTrusted() const;

   void PushSectionEntry(vector<string> const &Archs, const debSectionEntry *Entry);
   void PushSectionEntry(string const &Arch, const debSectionEntry *Entry);
   void PushSectionEntry(const debSectionEntry *Entry);
};

#endif
