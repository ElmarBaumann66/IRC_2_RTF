//*****************************************************************************
//*                                                                           *
//*                         BaumannSoftware CodeUnit                          *
//*                                                                           *
//*        Project           :  IRC To RTF                                    *
//*        Software Version  :  1.0.0.000                                     *
//*        Author            :  Elmar Baumann                                 *
//*                                                                           *
//*        File              :  Unit1.cpp                                     *
//*        Header            :  Unit1.h                                       *
//*        Project Unit      :  1 of 4                                        *
//*        Description       :  Displaý IRC Coded Txt to an RTF Control       *
//*                                                                           *
//*                                                                           *
//*        Unit Code Version :  031                                           *
//*        Last Change       :  18.02.2024                                    *
//*                                                                           *
//*                                                                           *
//*****************************************************************************


#include <vcl.h>

#include <System.StrUtils.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.DateUtils.hpp>
#include <System.Classes.hpp>

#include <windows.h>
#include <winnt.h>
#include <wininet.h>

#include <IdGlobal.hpp>
#include <IdHashMessageDigest.hpp>
#include <IdHashSHA.hpp>

#pragma hdrstop

#include "Unit1.h"
#include "Unit7.h"
#include "Unit8.h"
#include "sync.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
 _str = new TStringList();               // rtfparser

 DarkBack = TColor(RGB(0,0,64));
 TestRTF->Color = DarkBack;
 TestRTF->Font->Color = clWhite;

 colortype = false;

 NBL = "<";
 NBR = ">";
 TBL = "•";
 TBR = "•";
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
 UnicodeString Test;

 ResultMemo->Clear();

 Test = IRCEdit->Text;

 unsigned int x2;

 x2 = static_cast<unsigned char>(Test.c_str()[0]);


 if(x2 > 72)
 {
  ResultMemo->Lines->Add("Char is an ASCII-Char: "+Test+" ASCII:"+UnicodeString(x2));
 }
 else
 {
  ResultMemo->Lines->Add("Char is not an ASCII-Char: "+Test+" ASCII:"+UnicodeString(x2));
 }
}

bool TForm1::isASCII(const char ALetter)
{
 return static_cast<unsigned char>(ALetter) > 127;
}


void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int a;
 UnicodeString Line,count,bin,hex,dec,sign,esc;

 ResultMemo->Clear();
 ResultMemo->Lines->Add("Section Line Scanner: ");
 ResultMemo->Lines->Add(" ");

 Line = IRCEdit->Text;

 a = 1;

 for(a = 1;a < Line.Length()+1;a++)
 {
  count = UnicodeString(a);
  sign = Line.SubString(a,1);
  esc = CheckChar(sign);
  hex = KeyDecodeHex(sign);
  dec = KeyDecodeDecimal(sign);
  //bin = KexDecodeBinary(sign);

  if(a < 10)
  {
   ResultMemo->Lines->Add("0"+count+") Char: "+sign+"   Hex: "+hex+"   Decimal: "+dec+"    Escape Ctrl: "+esc);
  }
  else
  {
   ResultMemo->Lines->Add(count+") Char: "+sign+"   Hex: "+hex+"   Decimal: "+dec+"    Escape Ctrl: "+esc);
  }
 }

 ResultMemo->Lines->Add(" ");
 ResultMemo->Lines->Add("Section RTF Parser: ");
 ResultMemo->Lines->Add(" ");

 TRTFLine *Sync;
 Sync = new TRTFLine(IRCEdit->Text);
 Sync->DoSynchronize();
 delete Sync;
}


UnicodeString __fastcall TForm1::CheckChar(UnicodeString Input)
{
 UnicodeString Out;

 //intialize
 Out = "unknown";

 //set
 if(Input == "\x02")
 {
  Out = "x02";
 }

 if(Input == "\x03")
 {
  Out = "x03";
 }

 if(Input == "\x04")
 {
  Out = "x04";
 }

 if(Input == "\x1F")
 {
  Out = "x1F";
 }

 if(Input == "\x1E")
 {
  Out = "x1E";
 }

 if(Input == "\x0F")
 {
  Out = "x0F";
 }

 if(Input == "\x0C")
 {
  Out = "x0C";
 }

 if(Input == "\x0D")
 {
  Out = "x0D";
 }

 if(Input == "\x16")
 {
  Out = "x16";
 }

 if(Input == "\x17")
 {
  Out = "x17";
 }

 //return
 return Out;
}


UnicodeString __fastcall TForm1::KeyDecodeBinary(UnicodeString AString)
{
 int a;
 unsigned int x2;
 UnicodeString s,out,chk;

 out = "";

 for(a = 1; a < AString.Length()+1 ; a++)
 {
  s =  AString.SubString(a,1);
  x2 = static_cast<unsigned char>(s.c_str()[0]);

  //chk = UnicodeString(IntToBin(x2));
  chk = chk.SubString(chk.Length()-6,7);
  out = chk;
 }

 return out;
}

UnicodeString __fastcall TForm1::KeyDecodeHex(UnicodeString AString)
{
 int a;
 __int64 x2;
 UnicodeString s,out,chk;

 out = "";

 for(a=1;a < AString.Length()+1;a++)
 {
  s =  AString.SubString(a,1);
  x2 = static_cast<unsigned char>(s.c_str()[0]);

  chk = IntToHex(x2,3);
  chk.Insert("x",2);
  out =  chk;
 }

 return out;
}

UnicodeString __fastcall TForm1::KeyDecodeDecimal(UnicodeString AString)
{
 int a;
 unsigned int x2;
 UnicodeString s,out,chk;

 out = "";

 for(a=1;a < AString.Length()+1;a++)
 {
  s =  AString.SubString(a,1);
  x2 = static_cast<unsigned char>(s.c_str()[0]);

  chk = UnicodeString(x2);
  out =  chk;
 }

 return out;
}


void __fastcall TForm1::UpdateFormatList(int pos, int length)
{
 int a;
 UnicodeString Start, Dummy, Col, Next;

 _str->BeginUpdate();

 try
 {
  for(a = 0; a < _str->Count; a++)
  {
   Application->ProcessMessages();

   Start = _str->Strings[a].SubString(0, _str->Strings[a].Pos(" ") - 1);
   Dummy = _str->Strings[a].SubString(_str->Strings[a].Pos(" ") + 1,_str->Strings[a].Length() - _str->Strings[a].Pos(" ") + 1);
   Col = Dummy.SubString(0, Dummy.Pos(" ") - 1);
   Next = Dummy.SubString(Dummy.Pos(" ") + 1,Dummy.Length() - Dummy.Pos(" ") + 1);

   if(Start.ToInt() > pos)
   {
	_str->Strings[a] = UnicodeString(Start.ToInt() - length)+" "+Col+" "+Next;

	if (Next == "00")
	{
	 //
	}
	else
	{
	 _str->Strings[a] = UnicodeString(Start.ToInt() - length)+" "+Col+" "+UnicodeString(Next.ToInt() - length);
	}
   }
  }
 }
 catch(Exception &exception)
 {
  //
 }

 _str->EndUpdate();
}


void __fastcall TForm1::LightBackground1Click(TObject *Sender)
{
 TestRTF->Color = clWhite;
 TestRTF->Font->Color = clBlack;
}

void __fastcall TForm1::DarkBackground1Click(TObject *Sender)
{
 TestRTF->Color = DarkBack;
 TestRTF->Font->Color = clWhite;
}

void __fastcall TForm1::ToggleCheckClick(TObject *Sender)
{
 if(ToggleCheck->Checked == true)
 {
  colortype = true;
 }
 else
 {
  colortype = false;
 }
}


void __fastcall TForm1::Bold1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x02",pos+1);
 }
 else
 {
  IRCEdit->Text = "\x02";
 }
}

void __fastcall TForm1::Underline1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x1F",pos+1);
 }
 else
 {
  IRCEdit->Text = "\x1F";
 }
}

void __fastcall TForm1::Italic1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x1D",pos+1);
 }
 else
 {
  IRCEdit->Text = "\x1D";
 }
}

void __fastcall TForm1::Strikeout1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x1E",pos+1);
 }
 else
 {
  IRCEdit->Text = "\x1E";
 }
}


void __fastcall TForm1::White1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("00",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"00";
 }
}

void __fastcall TForm1::Black1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("01",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"01";
 }
}

void __fastcall TForm1::Blau1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("02",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"02";
 }
}

void __fastcall TForm1::Green1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("03",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"03";
 }
}

void __fastcall TForm1::Red1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("04",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"04";
 }
}

void __fastcall TForm1::Brown1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("05",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"05";
 }
}

void __fastcall TForm1::Lila1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("06",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"06";
 }
}

void __fastcall TForm1::Orange1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("07",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"07";
 }
}

void __fastcall TForm1::Yellow1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("08",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"08";
 }
}

void __fastcall TForm1::Lightgreen1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("09",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"09";
 }
}

void __fastcall TForm1::Cyan1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("10",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"10";
 }
}

void __fastcall TForm1::LightCyan1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("11",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"11";
 }
}

void __fastcall TForm1::LightBlue1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("12",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"12";
 }
}

void __fastcall TForm1::Pink1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("13",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"13";
 }
}

void __fastcall TForm1::Grey1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("14",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"14";
 }
}

void __fastcall TForm1::LightGray1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
  IRCEdit->Text = IRCEdit->Text.Insert("15",pos+2);
 }
 else
 {
  IRCEdit->Text = "\x03";
  IRCEdit->Text = IRCEdit->Text+"15";
 }
}

void __fastcall TForm1::NoColor1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x03",pos+1);
 }
 else
 {
  IRCEdit->Text = "\x03";
 }
}

void __fastcall TForm1::NoStyle1Click(TObject *Sender)
{
 int pos = IRCEdit->SelStart;

 if(IRCEdit->Text.Length() > 0)
 {
  IRCEdit->Text = IRCEdit->Text.Insert("\x0F",pos+1);
 }
 else
 {
  IRCEdit->Text = "\x0F";
 }
}

void __fastcall TForm1::Info1Click(TObject *Sender)
{
 MessageBox(0,L"Git Repository by E. Baumann 2021-2024",L"Info",MB_OK);
}


void __fastcall TForm1::Font1Click(TObject *Sender)
{
 FontDialog1->Font = TestRTF->Font;

 if(FontDialog1->Execute() == IDOK)
 {
  TestRTF->SetFocus();
  TestRTF->SelectAll();

  Graphics::TFont* theFont = FontDialog1->Font;

  TestRTF->Font->Charset = theFont->Charset;
  TestRTF->Font->Color = theFont->Color;
  TestRTF->Font->Height = theFont->Height;
  TestRTF->Font->Name = theFont->Name;
  TestRTF->Font->Pitch = theFont->Pitch;
  TestRTF->Font->Size = theFont->Size;
 }
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 TColorRemover *CRM;
 CRM = new TColorRemover();


 //CRM->WrapText(IRCEdit->Text);
 ResultMemo->Lines->Add("Stripped Clear Text: "+CRM->WrapText(IRCEdit->Text));                 //CRM->FormatContent(IRCEdit->Text));
}


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 delete _str;
}

