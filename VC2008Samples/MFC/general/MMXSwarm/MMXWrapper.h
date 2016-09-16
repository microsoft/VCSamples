// MMXWrapper.h : Very thin object wrapper over the MMX types
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

// Very thin and specific classes to have the MMX types more C++ friendly.
class CMMXUnsigned16Saturated
{
public:
	CMMXUnsigned16Saturated()
	{
	}
	CMMXUnsigned16Saturated( DWORD dw )
	{
		m_m64 = _m_from_int( dw );
	}
	CMMXUnsigned16Saturated( __m64 m64 )
	{
		m_m64 = m64;
	}
	CMMXUnsigned16Saturated( ULONGLONG qw )
	{
		m_m64.m64_u64 = qw;
	}

	CMMXUnsigned16Saturated& operator=( DWORD dw )
	{
		m_m64 = _m_from_int( dw );
		return( *this );
	}
	CMMXUnsigned16Saturated& operator=( const CMMXUnsigned16Saturated& m )
	{
		m_m64 = m.m_m64;
		return( *this );
	}
	CMMXUnsigned16Saturated& operator=( ULONGLONG qw )
	{
		m_m64.m64_u64 = qw;
		return( *this );
	}

	operator __m64() const
	{
		return( m_m64 );
	}

	operator ULONGLONG() const
	{
		return( m_m64.m64_u64 );
	}

	void Clear()
	{
		m_m64 = _mm_setzero_si64();
	}

	CMMXUnsigned16Saturated& operator+=( const CMMXUnsigned16Saturated& m )
	{
		m_m64 = _mm_adds_pu16( m_m64, m );
		return( *this );
	}
	CMMXUnsigned16Saturated& operator-=( const CMMXUnsigned16Saturated& m )
	{
		m_m64 = _mm_subs_pu16( m_m64, m );
		return( *this );
	}
	CMMXUnsigned16Saturated& operator>>=( int nBits )
	{
		m_m64 = _mm_srli_pi16( m_m64, nBits );
		return( *this );
	}

	CMMXUnsigned16Saturated& operator<<=( int nBits )
	{
		m_m64 = _mm_slli_pi16( m_m64, nBits );
		return( *this );
	}

	CMMXUnsigned16Saturated& operator&=( const CMMXUnsigned16Saturated& m )
	{
		m_m64 = _mm_and_si64(m_m64, m);
		return(*this);
	}

	CMMXUnsigned16Saturated& operator|=( const CMMXUnsigned16Saturated& m )
	{
		m_m64 = _mm_or_si64(m_m64, m);
		return(*this);
	}

	CMMXUnsigned16Saturated& AndNot( const CMMXUnsigned16Saturated& m )
	{
		m_m64 = _mm_andnot_si64(m, m_m64);
		return(*this);
	}

	DWORD PackBytes() const
	{
		return( _m_to_int( _mm_packs_pu16( m_m64, _mm_setzero_si64() ) ) );
	}

	ULONGLONG PackBytes( const CMMXUnsigned16Saturated& mUpper ) const
	{
		return( _mm_packs_pu16( m_m64, mUpper ).m64_u64 );
	}

	void UnpackBytesLo( DWORD dw )
	{
		m_m64 = _mm_unpacklo_pi8( _m_from_int( dw ), _mm_setzero_si64() );
	}
	void UnpackBytesHi( DWORD dw )
	{
		m_m64 = _mm_unpacklo_pi8( _mm_setzero_si64(), _m_from_int( dw ) );
	}

	void UnpackBytes(CMMXUnsigned16Saturated &mmLeft)
	{
		mmLeft = _mm_unpackhi_pi8( m_m64, _mm_setzero_si64() );
		m_m64 = _mm_unpacklo_pi8( m_m64, _mm_setzero_si64() );
	}

public:
	__m64 m_m64;
};

inline CMMXUnsigned16Saturated operator+( const CMMXUnsigned16Saturated& m1, const CMMXUnsigned16Saturated& m2 )
{
	return( _mm_adds_pu16( m1.m_m64, m2.m_m64 ) );
}

inline CMMXUnsigned16Saturated operator-( const CMMXUnsigned16Saturated& m1, const CMMXUnsigned16Saturated& m2 )
{
	return( _mm_subs_pu16( m1.m_m64, m2.m_m64 ) );
}

inline CMMXUnsigned16Saturated operator<<( const CMMXUnsigned16Saturated& m1, int nBits )
{
	return( _mm_slli_pi16( m1, nBits ) );
}

inline CMMXUnsigned16Saturated operator>>( const CMMXUnsigned16Saturated& m1, int nBits )
{
	return( _mm_srli_pi16( m1, nBits ) );
}

inline CMMXUnsigned16Saturated operator&( const CMMXUnsigned16Saturated& m1, const CMMXUnsigned16Saturated& m2 )
{
	return(_mm_and_si64(m1, m2));
}
