// SSE2Wrapper.h : Very thin object wrapper over the SSE2 types
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#pragma once

// Very thin and specific classes to have the SSE2 integer
// types more C++ friendly.

class CSSE2Unsigned16Saturated
{
public:
	CSSE2Unsigned16Saturated()
	{
	}
	CSSE2Unsigned16Saturated( __m128i m128i )
	{
		m_m128i = m128i;
	}
	CSSE2Unsigned16Saturated( ULONGLONG qw )
	{
		m_m128i = _mm_loadl_epi64((__m128i*)&qw);
	}

	CSSE2Unsigned16Saturated& operator=( const CSSE2Unsigned16Saturated& m )
	{
		m_m128i = m.m_m128i;
		return( *this );
	}
	CSSE2Unsigned16Saturated& operator=( const ULONGLONG &qw )
	{
		m_m128i = _mm_loadl_epi64((__m128i*)&qw);
		return( *this );
	}

	operator __m128i() const
	{
		return( m_m128i );
	}

	// least significant half
	operator ULONGLONG() const
	{
		return( *m_m128i.m128i_i64 );
	}

	void Clear()
	{
		m_m128i = _mm_setzero_si128();
	}

	void Fill( const ULONGLONG &qw )
	{
		__m64 m;
		m.m64_u64 = qw;
		m_m128i = _mm_set1_epi64( m );
	}

	CSSE2Unsigned16Saturated& operator+=( const CSSE2Unsigned16Saturated& m )
	{
		m_m128i = _mm_adds_epu16( m_m128i, m );
		return( *this );
	}
	CSSE2Unsigned16Saturated& operator-=( const CSSE2Unsigned16Saturated& m )
	{
		m_m128i = _mm_subs_epu16( m_m128i, m );
		return( *this );
	}
	CSSE2Unsigned16Saturated& operator>>=( int nBits )
	{
		m_m128i = _mm_srli_epi16( m_m128i, nBits );
		return( *this );
	}

	CSSE2Unsigned16Saturated& operator<<=( int nBits )
	{
		m_m128i = _mm_slli_epi16( m_m128i, nBits );
		return( *this );
	}

	CSSE2Unsigned16Saturated& operator&=( const CSSE2Unsigned16Saturated& m )
	{
		m_m128i = _mm_and_si128(m_m128i, m);
		return(*this);
	}

	CSSE2Unsigned16Saturated& operator|=( const CSSE2Unsigned16Saturated& m )
	{
		m_m128i = _mm_or_si128(m_m128i, m);
		return(*this);
	}

	CSSE2Unsigned16Saturated& AndNot( const CSSE2Unsigned16Saturated& m )
	{
		m_m128i = _mm_andnot_si128(m, m_m128i);
		return(*this);
	}

	ULONGLONG PackBytes() const
	{
		return( *_mm_packus_epi16(m_m128i, _mm_setzero_si128()).m128i_i64 );
	}

	// aligned
	void Store( void *pAddr )
	{
		ASSERT((DWORD_PTR(pAddr)& 0xF) == 0);
		_mm_store_si128( (__m128i *)pAddr, m_m128i );
	}

	// aligned
	void StoreU( void *pAddr )
	{
		_mm_storeu_si128( (__m128i *)pAddr, m_m128i );
	}

	// aligned
	void Load( void *pAddr )
	{
		ASSERT((DWORD_PTR(pAddr)& 0xF) == 0);
		m_m128i = _mm_load_si128( (__m128i *)pAddr );
	}

	// aligned
	void LoadU( void *pAddr )
	{
		m_m128i = _mm_loadu_si128( (__m128i *)pAddr );
	}

	// aligned
	void PackBytes( void *pAddr, const CSSE2Unsigned16Saturated& mUpper ) const
	{
		ASSERT((DWORD_PTR(pAddr)& 0xF) == 0);
		_mm_store_si128( (__m128i *)pAddr, _mm_packus_epi16( m_m128i, mUpper ) );
	}

	// Unaligned, documented to be slower.
	void PackBytesU( void *pAddr, const CSSE2Unsigned16Saturated& mUpper ) const
	{
		_mm_storeu_si128( (__m128i *)pAddr, _mm_packus_epi16( m_m128i, mUpper ) );
	}


	void UnpackBytesLo( const ULONGLONG &qw )
	{
		m_m128i = _mm_unpacklo_epi8( _mm_loadl_epi64((__m128i*)&qw), _mm_setzero_si128() );
	}
	void UnpackBytesHi( ULONGLONG qw )
	{
		m_m128i = _mm_unpacklo_epi8( _mm_setzero_si128(), _mm_loadl_epi64((__m128i*)&qw) );
	}

	void UnpackBytes(CSSE2Unsigned16Saturated &mmLeft)
	{
		mmLeft = _mm_unpackhi_epi8( m_m128i, _mm_setzero_si128() );
		m_m128i = _mm_unpacklo_epi8( m_m128i, _mm_setzero_si128() );
	}

public:
	__m128i m_m128i;
};

inline CSSE2Unsigned16Saturated operator+( const CSSE2Unsigned16Saturated& m1, const CSSE2Unsigned16Saturated& m2 )
{
	return( _mm_adds_epu16( m1.m_m128i, m2.m_m128i ) );
}

inline CSSE2Unsigned16Saturated operator-( const CSSE2Unsigned16Saturated& m1, const CSSE2Unsigned16Saturated& m2 )
{
	return( _mm_subs_epu16( m1.m_m128i, m2.m_m128i ) );
}

inline CSSE2Unsigned16Saturated operator<<( const CSSE2Unsigned16Saturated& m1, int nBits )
{
	return( _mm_slli_epi16( m1, nBits ) );
}

inline CSSE2Unsigned16Saturated operator>>( const CSSE2Unsigned16Saturated& m1, int nBits )
{
	return( _mm_srli_epi16( m1, nBits ) );
}

inline CSSE2Unsigned16Saturated operator&( const CSSE2Unsigned16Saturated& m1, const CSSE2Unsigned16Saturated& m2 )
{
	return(_mm_and_si128(m1, m2));
}
