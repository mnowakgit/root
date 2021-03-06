// @(#)root/cont
// Author: Philippe Canal Aug 2013

/*************************************************************************
 * Copyright (C) 1995-2013, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TListOfDataMembers                                                   //
//                                                                      //
// A collection of TDataMember objects designed for fast access given a //
// DeclId_t and for keep track of TDataMember that were described       //
// unloaded data member.                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TListOfDataMembers.h"
#include "TClass.h"
#include "TExMap.h"
#include "TDataMember.h"
#include "TGlobal.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"

ClassImp(TListOfDataMembers)

//______________________________________________________________________________
TListOfDataMembers::TListOfDataMembers(TClass *cl) : fClass(cl),fIds(0),fUnloaded(0),fIsLoaded(kFALSE)
{
   // Constructor.

   fIds = new TExMap;
   fUnloaded = new THashList;
}

//______________________________________________________________________________
TListOfDataMembers::~TListOfDataMembers()
{
   // Destructor.

   THashList::Delete();
   delete fIds;
   fUnloaded->Delete();
   delete fUnloaded;
}

//______________________________________________________________________________
void TListOfDataMembers::AddFirst(TObject *obj)
{
   // Add object at the beginning of the list.

   THashList::AddFirst(obj);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddFirst(TObject *obj, Option_t *opt)
{
   // Add object at the beginning of the list and also store option.
   // Storing an option is useful when one wants to change the behaviour
   // of an object a little without having to create a complete new
   // copy of the object. This feature is used, for example, by the Draw()
   // method. It allows the same object to be drawn in different ways.

   THashList::AddFirst(obj,opt);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddLast(TObject *obj)
{
   // Add object at the end of the list.

   THashList::AddLast(obj);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddLast(TObject *obj, Option_t *opt)
{
   // Add object at the end of the list and also store option.
   // Storing an option is useful when one wants to change the behaviour
   // of an object a little without having to create a complete new
   // copy of the object. This feature is used, for example, by the Draw()
   // method. It allows the same object to be drawn in different ways.

   THashList::AddLast(obj, opt);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddAt(TObject *obj, Int_t idx)
{
   // Insert object at location idx in the list.

   THashList::AddAt(obj, idx);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddAfter(const TObject *after, TObject *obj)
{
   // Insert object after object after in the list.

   THashList::AddAfter(after, obj);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddAfter(TObjLink *after, TObject *obj)
{
   // Insert object after object after in the list.

   THashList::AddAfter(after, obj);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddBefore(const TObject *before, TObject *obj)
{
   // Insert object before object before in the list.

   THashList::AddBefore(before, obj);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::AddBefore(TObjLink *before, TObject *obj)
{
   // Insert object before object before in the list.

   THashList::AddBefore(before, obj);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)d);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Add((Long64_t)id,(Long64_t)g);
      }
   }
}

//______________________________________________________________________________
void TListOfDataMembers::Clear(Option_t *option)
{
   // Remove all objects from the list. Does not delete the objects unless
   // the THashList is the owner (set via SetOwner()).

   fUnloaded->Clear(option);
   fIds->Clear();
   THashList::Clear(option);
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
void TListOfDataMembers::Delete(Option_t *option /* ="" */)
{
   // Delete all TDataMember object files.

   fUnloaded->Delete(option);
   THashList::Delete(option);
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
TObject *TListOfDataMembers::FindObject(const char *name) const
{
   // Specialize FindObject to do search for the
   // a data member just by name or create it if its not already in the list

   TObject *result = THashList::FindObject(name);
   if (!result) {
      TInterpreter::DeclId_t decl;
      if (fClass) decl = gInterpreter->GetDataMember(fClass->GetClassInfo(),name);
      else        decl = gInterpreter->GetDataMember(0,name);
      if (decl) result = const_cast<TListOfDataMembers*>(this)->Get(decl);
   }
   return result;
}

//______________________________________________________________________________
TDictionary *TListOfDataMembers::Get(DeclId_t id)
{
   // Return (after creating it if necessary) the TDataMember
   // describing the data member corresponding to the Decl 'id'.

   if (!id) return 0;

   TDictionary *dm = (TDataMember*)fIds->GetValue((Long64_t)id);
   if (!dm) {
      if (fClass) {
         if (!gInterpreter->ClassInfo_Contains(fClass->GetClassInfo(),id)) return 0;
      } else {
         if (!gInterpreter->ClassInfo_Contains(0,id)) return 0;
      }
      DataMemberInfo_t *info = gInterpreter->DataMemberInfo_Factory(id,fClass ? fClass->GetClassInfo() : 0);

      // Let's see if this is a reload ...
      const char *name = gInterpreter->DataMemberInfo_Name(info);

      TDictionary *update = (TDictionary *)fUnloaded->FindObject(name);
      if (update) {
         if (fClass) {
            ((TDataMember*)update)->Update(info);
         } else {
            ((TGlobal*)update)->Update(info);
         }
         dm = update;
      }
      if (!dm) {
         if (fClass) dm = new TDataMember(info, fClass);
         else dm = new TGlobal(info);
      }
      // Calling 'just' THahList::Add would turn around and call
      // TListOfDataMembers::AddLast which should *also* do the fIds->Add.
      THashList::AddLast(dm);
      fIds->Add((Long64_t)id,(Long64_t)dm);
   }
   return dm;
}

//______________________________________________________________________________
TDictionary *TListOfDataMembers::Get(DataMemberInfo_t *info)
{
   // Return (after creating it if necessary) the TDataMember
   // describing the data member corresponding to the Decl 'id'.

   if (!info) return 0;

   TDictionary::DeclId_t id = gInterpreter->GetDeclId(info);
   TDictionary *dm = (TDataMember*)fIds->GetValue((Long64_t)id);
   if (!dm) {
      if (fClass) {
         if (!gInterpreter->ClassInfo_Contains(fClass->GetClassInfo(),id)) return 0;
      } else {
         if (!gInterpreter->ClassInfo_Contains(0,id)) return 0;
      }

      DataMemberInfo_t *dm_info = gInterpreter->DataMemberInfo_FactoryCopy(info);

      // Let's see if this is a reload ...
      const char *name = gInterpreter->DataMemberInfo_Name(info);
      TDataMember *update = (TDataMember *)fUnloaded->FindObject(name);
      if (update) {
         update->Update(dm_info);
         dm = update;
      }
      if (!dm) {
         if (fClass) dm = new TDataMember(dm_info, fClass);
         else dm = new TGlobal(dm_info);
      }
      // Calling 'just' THahList::Add would turn around and call
      // TListOfDataMembers::AddLast which should *also* do the fIds->Add.
      THashList::AddLast(dm);
      fIds->Add((Long64_t)id,(Long64_t)dm);
   }
   return dm;
}

//______________________________________________________________________________
void TListOfDataMembers::RecursiveRemove(TObject *obj)
{
   // Remove object from this collection and recursively remove the object
   // from all other objects (and collections).
   // This function overrides TCollection::RecursiveRemove that calls
   // the Remove function. THashList::Remove cannot be called because
   // it uses the hash value of the hash table. This hash value
   // is not available anymore when RecursiveRemove is called from
   // the TObject destructor.

   if (!obj) return;

   THashList::RecursiveRemove(obj);
   fUnloaded->RecursiveRemove(obj);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   }
}

//______________________________________________________________________________
TObject* TListOfDataMembers::Remove(TObject *obj)
{
   // Remove object from the list.

   Bool_t found;

   found = THashList::Remove(obj);
   if (!found) {
      found = fUnloaded->Remove(obj);
   }
   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   }
   if (found) return obj;
   else return 0;
}

//______________________________________________________________________________
TObject* TListOfDataMembers::Remove(TObjLink *lnk)
{
   // Remove object via its objlink from the list.

   if (!lnk) return 0;

   TObject *obj = lnk->GetObject();

   THashList::Remove(lnk);
   fUnloaded->Remove(obj);

   if (fClass) {
      TDataMember *d = dynamic_cast<TDataMember*>(obj);
      if (d) {
         DeclId_t id = d->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   } else {
      TGlobal *g = dynamic_cast<TGlobal*>(obj);
      if (g) {
         DeclId_t id = g->GetDeclId();
         fIds->Remove((Long64_t)id);
      }
   }
   return obj;
}

//______________________________________________________________________________
void TListOfDataMembers::Load()
{
   // Load all the DataMembers known to the intepreter for the scope 'fClass'
   // into this collection.

   if (fClass && fClass->GetClassInfo() == 0) return;

   if (fClass && fClass->Property() & (kIsClass|kIsStruct|kIsUnion)) {
      // Class and union are not extendable, if we already
      // loaded all the data member there is no need to recheck
      if (fIsLoaded) return;
   }
   // In the case of namespace, even if we have loaded before we need to
   // load again in case there was new data member added.
   // (We may want to avoid doing it if there was no change in the AST).

   // Mark the list as loaded to avoid an infinite recursion in the case
   // where we have a data member that is a variable size array.  In that
   // case TDataMember::Init needs to get/load the list to find the data
   // member used as the array size.
   fIsLoaded = kTRUE;

   ClassInfo_t *info;
   if (fClass) info = fClass->GetClassInfo();
   else info = gInterpreter->ClassInfo_Factory();

   DataMemberInfo_t *t = gInterpreter->DataMemberInfo_Factory(info);
   while (gInterpreter->DataMemberInfo_Next(t)) {
      // if the name cannot be obtained there is no use to put in list
      if (gInterpreter->DataMemberInfo_IsValid(t) && gInterpreter->DataMemberInfo_Name(t)) {
         // Get will check if there is already there or create a new one
         // (or re-use a previously unloaded version).
         Get(t);
      }
   }
   if (!fClass) gInterpreter->ClassInfo_Delete(info);
}

//______________________________________________________________________________
void TListOfDataMembers::Unload()
{
   // Mark 'all func' as being unloaded.
   // After the unload, the data member can no longer be found directly,
   // until the decl can be found again in the interpreter (in which
   // the func object will be reused.

   TObjLink *lnk = FirstLink();
   while (lnk) {
      DeclId_t id;
      TDictionary *data = (TDictionary *)lnk->GetObject();
      if (fClass) id = ((TDataMember*)data)->GetDeclId();
      else id = ((TGlobal*)data)->GetDeclId();

      fIds->Remove((Long64_t)id);
      fUnloaded->Add(data);

      lnk = lnk->Next();
   }

   THashList::Clear();
   fIsLoaded = kFALSE;
}

//______________________________________________________________________________
void TListOfDataMembers::Unload(TDictionary *mem)
{
   // Mark 'func' as being unloaded.
   // After the unload, the data member can no longer be found directly,
   // until the decl can be found again in the interpreter (in which
   // the func object will be reused.

   if (THashList::Remove(mem)) {
      // We contains the object, let remove it from the other internal
      // list and move it to the list of unloaded objects.

      DeclId_t id;
      if (fClass) id = ((TDataMember*)mem)->GetDeclId();
      else id = ((TGlobal*)mem)->GetDeclId();
      fIds->Remove((Long64_t)id);
      fUnloaded->Add(mem);
   }
}
