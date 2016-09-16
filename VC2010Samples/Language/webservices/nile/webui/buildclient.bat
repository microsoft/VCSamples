REM build the login page
cl /Zi /Od /clr /LD  login.cpp /link  /out:login.dll 

REM build the account page
cl /Zi /Od /clr /LD  account.cpp /link  /out:account.dll

REM build the specials page
cl /Zi /Od /clr /LD  specials.cpp /link  /out:specials.dll

REM build the results page
cl /Zi /Od /clr /LD  results.cpp /link  /out:results.dll

REM build the cart page
cl /Zi /Od /clr /LD  cart.cpp /link  /out:cart.dll

REM build the addtocart page
cl /Zi /Od /clr /LD  addtocart.cpp /link  /out:addtocart.dll

REM build the checkout page
cl /Zi /Od /clr /LD  checkout.cpp /link  /out:checkout.dll
