//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdGlobal.hpp>
#include <IdBaseComponent.hpp>
#include <IdCmdTCPClient.hpp>
#include <IdComponent.hpp>
#include <IdIRC.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TEdit *IRCEdit;
	TButton *Button1;
	TLabel *Label1;
	TMemo *ResultMemo;
	TRichEdit *TestRTF;
	TButton *Button2;
	TLabel *Label2;
	TLabel *Label3;
	TPopupMenu *RTFPopup;
	TMenuItem *LightBackground1;
	TMenuItem *DarkBackground1;
	TCheckBox *ToggleCheck;
	TPopupMenu *EditPopup;
	TMenuItem *Bold1;
	TMenuItem *Underline1;
	TMenuItem *Italic1;
	TMenuItem *Strikeout1;
	TMenuItem *N1;
	TMenuItem *White1;
	TMenuItem *Black1;
	TMenuItem *Blau1;
	TMenuItem *Green1;
	TMenuItem *Red1;
	TMenuItem *Brown1;
	TMenuItem *Lila1;
	TMenuItem *Orange1;
	TMenuItem *Yellow1;
	TMenuItem *Lightgreen1;
	TMenuItem *Cyan1;
	TMenuItem *LightCyan1;
	TMenuItem *LightBlue1;
	TMenuItem *Pink1;
	TMenuItem *Grey1;
	TMenuItem *LightGray1;
	TMenuItem *N2;
	TMenuItem *NoColor1;
	TMenuItem *NoStyle1;
	TMenuItem *N3;
	TMenuItem *Info1;
	TMenuItem *Font1;
	TFontDialog *FontDialog1;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall LightBackground1Click(TObject *Sender);
	void __fastcall DarkBackground1Click(TObject *Sender);
	void __fastcall ToggleCheckClick(TObject *Sender);
	void __fastcall Bold1Click(TObject *Sender);
	void __fastcall Underline1Click(TObject *Sender);
	void __fastcall Italic1Click(TObject *Sender);
	void __fastcall Strikeout1Click(TObject *Sender);
	void __fastcall White1Click(TObject *Sender);
	void __fastcall Black1Click(TObject *Sender);
	void __fastcall Blau1Click(TObject *Sender);
	void __fastcall Green1Click(TObject *Sender);
	void __fastcall Red1Click(TObject *Sender);
	void __fastcall Brown1Click(TObject *Sender);
	void __fastcall Lila1Click(TObject *Sender);
	void __fastcall Orange1Click(TObject *Sender);
	void __fastcall Yellow1Click(TObject *Sender);
	void __fastcall Lightgreen1Click(TObject *Sender);
	void __fastcall Cyan1Click(TObject *Sender);
	void __fastcall LightCyan1Click(TObject *Sender);
	void __fastcall LightBlue1Click(TObject *Sender);
	void __fastcall Pink1Click(TObject *Sender);
	void __fastcall Grey1Click(TObject *Sender);
	void __fastcall LightGray1Click(TObject *Sender);
	void __fastcall NoColor1Click(TObject *Sender);
	void __fastcall NoStyle1Click(TObject *Sender);
	void __fastcall Info1Click(TObject *Sender);
	void __fastcall Font1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TForm1(TComponent* Owner);
	bool colortype;

	UnicodeString NBL;
	UnicodeString NBR;
	UnicodeString TBL;
	UnicodeString TBR;

        TColor DarkBack;

	TStrings *str;               // rtfparser

	void __fastcall UpdateFormatList(int pos, int length);

        bool isASCII(const char Letter);

	UnicodeString __fastcall CheckChar(UnicodeString Input);
	UnicodeString __fastcall KeyDecodeBinary(UnicodeString AString);
	UnicodeString __fastcall KeyDecodeHex(UnicodeString AString);
	UnicodeString __fastcall KeyDecodeDecimal(UnicodeString AString);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif