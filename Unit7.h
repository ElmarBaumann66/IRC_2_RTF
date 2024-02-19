// ---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H

class TColorParser : public TObject
{
 public:
	UnicodeString __fastcall RemoveBackColors(UnicodeString FInput);
	UnicodeString __fastcall PrepareLine(UnicodeString Line);
	UnicodeString __fastcall PrepareLine_(UnicodeString FInput);
	UnicodeString __fastcall RemEscapes(UnicodeString(FInput));
	UnicodeString __fastcall RemStyles(UnicodeString(FInput));
	UnicodeString __fastcall RemoveLastChars(UnicodeString FInput);
    UnicodeString __fastcall WrapExtendedAscii(UnicodeString FInput);
};

#endif
