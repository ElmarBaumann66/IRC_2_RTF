﻿#ifndef Unit8H
#define Unit8H

class TColorRemover : public TObject
{
 public:
	UnicodeString __fastcall FormatContent(UnicodeString Source);
	UnicodeString __fastcall RemoveEscapes(UnicodeString Source);
	UnicodeString __fastcall ReplaceAlphabet(UnicodeString Source,int Mode);
	UnicodeString __fastcall WrapText(UnicodeString Source);
};

#endif
