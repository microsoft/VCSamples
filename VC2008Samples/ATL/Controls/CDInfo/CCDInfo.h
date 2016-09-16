// CCDINFO.H : CDInfo device management class declarations
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include <mmsystem.h>

#define MAX_TRACKS 100

class CDInfo
{
public:
	CDInfo();
	~CDInfo();
	short   Read();
	short   GetNumberOfTracks();
	void    SetNumberOfTracks(short nTracks);
	short   GetTrackLength(short nTrack);
	void    SetTrackLength(short nTrack, short nNewLength);
	short   GetTotalLength();
	void    Play(short nTrack);
private:
	short               m_nNumberOfTracks;
	short               m_nTrackLength[MAX_TRACKS];
	MCI_STATUS_PARMS    m_MCIStatus;
	MCI_OPEN_PARMS      m_MCIOpen;
};

#include "CCDInfo.inl"
