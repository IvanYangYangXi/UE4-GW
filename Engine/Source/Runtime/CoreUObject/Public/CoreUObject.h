// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Misc/MonolithicHeaderBoilerplate.h"
MONOLITHIC_HEADER_BOILERPLATE()


#include "Core.h"
#include "UObject/ErrorException.h"
#include "Modules/ModuleManager.h"
#include "UObject/ScriptInterface.h"
#include "UObject/Script.h"
#include "UObject/ScriptMacros.h"
#include "UObject/ObjectMacros.h"
#include "UObject/UObjectAllocator.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/UObjectMarks.h"
#include "UObject/UObjectBase.h"
#include "UObject/UObjectBaseUtility.h"
#include "UObject/UObjectArray.h"
#include "UObject/UObjectHash.h"
#include "UObject/WeakObjectPtr.h"
#include "UObject/Object.h"
#include "UObject/CoreNative.h"
#include "UObject/UObjectIterator.h"
#include "UObject/CoreNetTypes.h"
#include "UObject/CoreNet.h"
#include "Serialization/ArchiveUObject.h"
#include "UObject/GarbageCollection.h"
#include "Misc/TextBuffer.h"
#include "UObject/Class.h"
#include "Templates/SubclassOf.h"
#include "Serialization/PropertyLocalizationDataGathering.h"
#include "UObject/StructOnScope.h"
#include "Templates/Casts.h"
#include "UObject/PersistentObjectPtr.h"
#include "UObject/LazyObjectPtr.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/Interface.h"
#include "UObject/LevelGuids.h"
#include "UObject/Package.h"
#include "UObject/MetaData.h"
#include "UObject/DebugSerializationFlags.h"
#include "UObject/PropertyTag.h"
#include "Serialization/SerializedPropertyScope.h"
#include "UObject/UnrealType.h"
#include "UObject/EnumProperty.h"
#include "UObject/TextProperty.h"
#include "UObject/Stack.h"
#include "UObject/ObjectRedirector.h"
#include "UObject/UObjectAnnotation.h"
#include "UObject/ObjectMemoryAnalyzer.h"
#include "UObject/ReferenceChainSearch.h"
#include "Async/AsyncFileHandle.h"
#include "Internationalization/TextPackageNamespaceUtil.h"
#include "Serialization/ArchiveCountMem.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "Serialization/ObjectWriter.h"
#include "Serialization/ObjectReader.h"
#include "Serialization/ArchiveShowReferences.h"
#include "Serialization/FindReferencersArchive.h"
#include "Serialization/FindObjectReferencers.h"
#include "Serialization/ArchiveFindCulprit.h"
#include "Serialization/ArchiveObjectGraph.h"
#include "Serialization/TraceReferences.h"
#include "Serialization/ArchiveTraceRoute.h"
#include "Serialization/DuplicatedObject.h"
#include "Serialization/DuplicatedDataReader.h"
#include "Serialization/DuplicatedDataWriter.h"
#include "Serialization/ArchiveReplaceObjectRef.h"
#include "Serialization/ArchiveReplaceOrClearExternalReferences.h"
#include "Serialization/ArchiveObjectPropertyMapper.h"
#include "Serialization/ArchiveReferenceMarker.h"
#include "Serialization/ArchiveAsync.h"
#include "Serialization/ArchiveObjectCrc32.h"
#include "Misc/PackageName.h"
#include "UObject/ConstructorHelpers.h"
#include "Async/Async.h"
#include "Serialization/BulkData.h"
#include "UObject/PackageFileSummary.h"
#include "UObject/ObjectResource.h"
#include "UObject/Linker.h"
#include "UObject/LinkerLoad.h"
#include "UObject/LinkerSave.h"
#include "UObject/GCObject.h"
#include "Serialization/AsyncPackage.h"
#include "Serialization/AsyncLoading.h"
#include "Misc/NotifyHook.h"
#include "Misc/RedirectCollector.h"
#include "UObject/ScriptStackTracker.h"
#include "Misc/WorldCompositionUtility.h"
