// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <windows.h>

// TODO: reference additional headers your program requires here

#include <cassert>
#include <algorithm>
#include <vector>
#include <memory>
#include <string>
#include <regex>
#include <list>

class ManifestFragment;
class PublisherManifestFragment;
class ConfigManifestFragment;
class MessageLogger;
class XMLReader;

typedef std::tr1::shared_ptr<ManifestFragment> SafeManifestFragment;
typedef std::tr1::shared_ptr<PublisherManifestFragment> SafePublisherManifestFragment;
typedef std::tr1::shared_ptr<ConfigManifestFragment> SafeConfigManfiestFragment;
typedef std::tr1::shared_ptr<MessageLogger> SafeMessageLogger;
typedef std::tr1::shared_ptr<XMLReader>	SafeXMLReader;

using std::tr1::enable_shared_from_this;
using std::tr1::regex_replace;
using std::tr1::regex_search;
using std::tr1::regex_match;
using std::tr1::shared_ptr;
using std::tr1::wsmatch;
using std::tr1::wregex;

using std::wstring;
using std::vector;
using std::unique;
using std::list;
using std::sort;

#include "resource.h"

#define VC_LIBS_FILTER	L".*microsoft.*mfc.*|.*microsoft.*atl.*|.*microsoft.*crt.*|.*openmp.*"

#define MIN_ERROR_VALUE						1000
#define MAX_ASSEMBLY_DEEP					10


#define LOG_LEVEL_0			0
#define LOG_LEVEL_1			1
#define LOG_LEVEL_2			2
#define LOG_LEVEL_3			3