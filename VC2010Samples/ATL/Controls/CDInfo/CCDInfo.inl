// CCDInfo.INL : inlines for CDInfo class
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

inline short CDInfo::GetNumberOfTracks()
{
	return m_nNumberOfTracks;
}

inline void CDInfo::SetNumberOfTracks(short nTracks)
{
	m_nNumberOfTracks = nTracks;
}

inline short CDInfo::GetTrackLength(short nTrack)
{
	if (nTrack>0 && nTrack<=m_nNumberOfTracks)
		return m_nTrackLength[nTrack-1];
	else
		return 0;
}

inline void CDInfo::SetTrackLength(short nTrack, short nNewLength)
{
	if (nTrack>0 && nTrack<=m_nNumberOfTracks)
		m_nTrackLength[nTrack-1] = nNewLength;
}

inline short CDInfo::GetTotalLength()
{
	short nTotalLength = 0;
	short nTrack;
	for (nTrack=0; nTrack<m_nNumberOfTracks; nTrack++)
		nTotalLength = (short)(nTotalLength + m_nTrackLength[nTrack]);
	return nTotalLength;
}
