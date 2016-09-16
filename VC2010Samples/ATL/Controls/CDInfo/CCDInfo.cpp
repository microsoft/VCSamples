// ccdinfo.cpp : device manager class implementation
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "ccdinfo.h"

CDInfo::CDInfo()
{
	// We don't have an open device yet
	m_MCIOpen.wDeviceID = 0;
	m_nNumberOfTracks = 0;
}

CDInfo::~CDInfo()
{
	// If we have an open device then we'll be nice and close it.
//  if (m_MCIOpen.wDeviceID != -1)
//  {
//      mciSendCommand(m_MCIOpen.wDeviceID, MCI_CLOSE, NULL, NULL);
//  }
}

short CDInfo::Read()
{
	int   i;
	short nTrackLength;

	m_nNumberOfTracks = 0;
	m_MCIOpen.lpstrDeviceType = (LPCTSTR)MCI_DEVTYPE_CD_AUDIO;
	if (mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE|MCI_OPEN_TYPE_ID, (DWORD_PTR)&m_MCIOpen))
	{
		ATLTRACE(_T("Couldn't open CD player"));
	}

	m_MCIStatus.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
	if (mciSendCommand(m_MCIOpen.wDeviceID, MCI_STATUS, MCI_STATUS_ITEM|MCI_WAIT, (DWORD_PTR)&m_MCIStatus))
	{
		ATLTRACE(_T("Error getting number of tracks"));
		mciSendCommand(m_MCIOpen.wDeviceID, MCI_CLOSE, NULL, NULL);
		return 0;
	}
	m_nNumberOfTracks = (short)m_MCIStatus.dwReturn;
	if (m_nNumberOfTracks > MAX_TRACKS)
		m_nNumberOfTracks = MAX_TRACKS;

	m_MCIStatus.dwItem = MCI_STATUS_LENGTH;
	for (i=0; i<m_nNumberOfTracks; i++)
	{
		m_MCIStatus.dwTrack = i+1;
		mciSendCommand(m_MCIOpen.wDeviceID, MCI_STATUS, MCI_TRACK|MCI_STATUS_ITEM|MCI_WAIT, (DWORD_PTR)&m_MCIStatus);
		nTrackLength = (short)(MCI_MSF_MINUTE(m_MCIStatus.dwReturn)*60 + MCI_MSF_SECOND(m_MCIStatus.dwReturn));
		m_nTrackLength[i] = nTrackLength;
	}
	mciSendCommand(m_MCIOpen.wDeviceID, MCI_CLOSE, NULL, NULL);

	return m_nNumberOfTracks;
}

void CDInfo::Play(short nTrack)
{
	MCI_SET_PARMS   mciSet;
	MCI_PLAY_PARMS  mciPlay;

	m_MCIOpen.lpstrDeviceType = (LPCTSTR)MCI_DEVTYPE_CD_AUDIO;
	if (mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE|MCI_OPEN_TYPE_ID, (DWORD_PTR)&m_MCIOpen))
	{
		ATLTRACE(_T("Couldn't open CD player"));
	}

	// Set the time format to track/minute/second/frame (TMSF).
	mciSet.dwTimeFormat = MCI_FORMAT_TMSF;
	if (mciSendCommand(m_MCIOpen.wDeviceID, MCI_SET, MCI_SET_TIME_FORMAT, (DWORD_PTR)&mciSet))
	{
		mciSendCommand(m_MCIOpen.wDeviceID, MCI_CLOSE, 0, NULL);
		return;
	}

	mciPlay.dwCallback = 0;
	mciPlay.dwFrom = MCI_MAKE_TMSF(nTrack, 0, 0, 0);
	if (mciSendCommand(m_MCIOpen.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD_PTR)&mciPlay))
	{
		ATLTRACE(_T("Error playing track"));
	}

	mciSendCommand(m_MCIOpen.wDeviceID, MCI_CLOSE, 0, NULL);
}
