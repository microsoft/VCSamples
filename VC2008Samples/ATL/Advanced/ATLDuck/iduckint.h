// iduckint.h: Declaration of IDuckInt
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef INC_IDUCKINT_H
#define INC_IDUCKINT_H

	interface DECLSPEC_UUID("120B72AE-65BF-11D0-9DDC-00A0C9034892")

	IDuckInt : public IUnknown
	{
	public:
		virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Quack(
			BSTR szWhosCalling) = 0;

		virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Flap(
			BSTR szWhosCalling) = 0;

		virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Paddle(
			BSTR szWhosCalling) = 0;

		virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Walk(
			BSTR szWhosCalling) = 0;

	};

#endif
