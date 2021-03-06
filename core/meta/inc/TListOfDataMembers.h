// @(#)root/cont
// Author: Philippe Canal Aug 2013

/*************************************************************************
 * Copyright (C) 1995-2013, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TListOfDataMembers
#define ROOT_TListOfDataMembers

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TListOfDataMembers                                                   //
//                                                                      //
// A collection of TDataMember objects designed for fast access given a //
// DeclId_t and for keep track of TDataMember that were described       //
// unloaded member.                                                     //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef ROOT_THastList
#include "THashList.h"
#endif

#ifndef ROOT_TDictionary
#include "TDictionary.h"
#endif

class TExMap;
class TDataMember;

class TListOfDataMembers : public THashList
{
private:
   typedef TDictionary::DeclId_t DeclId_t;
   TClass    *fClass; // Context of this list.  Not owned.

   TExMap    *fIds;      // Map from DeclId_t to TDataMember*
   THashList *fUnloaded; // Holder of TDataMember for unloaded DataMembers.
   Bool_t     fIsLoaded; // Mark whether Load was executed.

   TListOfDataMembers(const TListOfDataMembers&);              // not implemented
   TListOfDataMembers& operator=(const TListOfDataMembers&);   // not implemented

public:

   TListOfDataMembers(TClass *cl);
   ~TListOfDataMembers();

   virtual void Clear(Option_t *option);
   virtual void Delete(Option_t *option="");

   using THashList::FindObject;
   virtual TObject   *FindObject(const char *name) const;

   TDictionary *Get(DeclId_t id);
   TDictionary *Get(DataMemberInfo_t *info);

   Bool_t     IsLoaded() const { return fIsLoaded; }
   void       AddFirst(TObject *obj);
   void       AddFirst(TObject *obj, Option_t *opt);
   void       AddLast(TObject *obj);
   void       AddLast(TObject *obj, Option_t *opt);
   void       AddAt(TObject *obj, Int_t idx);
   void       AddAfter(const TObject *after, TObject *obj);
   void       AddAfter(TObjLink *after, TObject *obj);
   void       AddBefore(const TObject *before, TObject *obj);
   void       AddBefore(TObjLink *before, TObject *obj);

   void       RecursiveRemove(TObject *obj);
   TObject   *Remove(TObject *obj);
   TObject   *Remove(TObjLink *lnk);

   void Load();
   void Unload();
   void Unload(TDictionary *member);

   ClassDef(TListOfDataMembers,0);  // List of TDataMembers for a class
};

#endif // ROOT_TListOfDataMembers
