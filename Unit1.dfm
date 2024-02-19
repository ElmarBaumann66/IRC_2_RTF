object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'IRC Check'
  ClientHeight = 397
  ClientWidth = 592
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  DesignSize = (
    592
    397)
  TextHeight = 13
  object Label1: TLabel
    Left = 15
    Top = 3
    Width = 172
    Height = 13
    Caption = 'Insert or edit an IRC coded Textline'
  end
  object Label2: TLabel
    Left = 16
    Top = 50
    Width = 42
    Height = 13
    Caption = 'RichText'
  end
  object Label3: TLabel
    Left = 16
    Top = 135
    Width = 42
    Height = 13
    Caption = 'InfoText'
  end
  object IRCEdit: TEdit
    Left = 15
    Top = 20
    Width = 560
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    PopupMenu = EditPopup
    TabOrder = 0
    ExplicitWidth = 558
  end
  object Button1: TButton
    Left = 419
    Top = 364
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Char'
    TabOrder = 1
    OnClick = Button1Click
    ExplicitLeft = 417
    ExplicitTop = 356
  end
  object ResultMemo: TMemo
    Left = 15
    Top = 154
    Width = 560
    Height = 204
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = clInactiveCaption
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = []
    Lines.Strings = (
      '********************************'
      '*  BSIRC Colorparser Tool 2021 *'
      '*  Baumann Software,  Germany  *'
      '********************************'
      ''
      'Instructions:'
      ''
      '- Button Char:'
      
        '  Check the 1st Char of a line or a single Char (Edit Field Text' +
        ')'
      ''
      '- Button Line:'
      
        '  Check a complete Line of IRC Color- or Stylecodes (Edit Field ' +
        'Text)'
      ''
      '- Button RemoveCodes'
      '  Remove all Format Codes from a Line (Edit Field Text)'
      ''
      
        'Do a Right-Click on the Edit Field to insert Color- or Stylecode' +
        's at the Cursor'
      
        'Do a Right-Click on the RTF Control to switch the Background-Col' +
        'or'
      
        'Set the AutoColor CheckBox to change White on a light BG or even' +
        ' Black on a dark BG')
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 2
    WordWrap = False
    StyleElements = [seBorder]
    ExplicitWidth = 558
    ExplicitHeight = 196
  end
  object TestRTF: TRichEdit
    Left = 16
    Top = 69
    Width = 559
    Height = 61
    Anchors = [akLeft, akTop, akRight]
    Font.Charset = 254
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI Symbol'
    Font.Style = []
    ParentFont = False
    PopupMenu = RTFPopup
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 3
    WordWrap = False
    StyleElements = [seBorder]
    ExplicitWidth = 557
  end
  object Button2: TButton
    Left = 500
    Top = 364
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Line'
    TabOrder = 4
    OnClick = Button2Click
    ExplicitLeft = 498
    ExplicitTop = 356
  end
  object ToggleCheck: TCheckBox
    Left = 16
    Top = 372
    Width = 137
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = 'AutoColor Background'
    TabOrder = 5
    OnClick = ToggleCheckClick
    ExplicitTop = 364
  end
  object Button3: TButton
    Left = 312
    Top = 364
    Width = 101
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'RemoveCodes'
    TabOrder = 6
    OnClick = Button3Click
    ExplicitLeft = 310
    ExplicitTop = 356
  end
  object RTFPopup: TPopupMenu
    Left = 104
    Top = 80
    object LightBackground1: TMenuItem
      Caption = 'Light Background'
      OnClick = LightBackground1Click
    end
    object DarkBackground1: TMenuItem
      Caption = 'Dark Background'
      OnClick = DarkBackground1Click
    end
    object Font1: TMenuItem
      Caption = 'Font'
      OnClick = Font1Click
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object Info1: TMenuItem
      Caption = 'Info'
      OnClick = Info1Click
    end
  end
  object EditPopup: TPopupMenu
    Left = 248
    Top = 80
    object Bold1: TMenuItem
      Caption = 'Bold'
      OnClick = Bold1Click
    end
    object Underline1: TMenuItem
      Caption = 'Underline'
      OnClick = Underline1Click
    end
    object Italic1: TMenuItem
      Caption = 'Italic'
      OnClick = Italic1Click
    end
    object Strikeout1: TMenuItem
      Caption = 'Strikeout'
      OnClick = Strikeout1Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object White1: TMenuItem
      Caption = '00 White'
      OnClick = White1Click
    end
    object Black1: TMenuItem
      Caption = '01 Black'
      OnClick = Black1Click
    end
    object Blau1: TMenuItem
      Caption = '02 Blue'
      OnClick = Blau1Click
    end
    object Green1: TMenuItem
      Caption = '03 Green'
      OnClick = Green1Click
    end
    object Red1: TMenuItem
      Caption = '04 Red'
      OnClick = Red1Click
    end
    object Brown1: TMenuItem
      Caption = '05 Brown'
      OnClick = Brown1Click
    end
    object Lila1: TMenuItem
      Caption = '06 Purple'
      OnClick = Lila1Click
    end
    object Orange1: TMenuItem
      Caption = '07 Orange'
      OnClick = Orange1Click
    end
    object Yellow1: TMenuItem
      Caption = '08 Yellow'
      OnClick = Yellow1Click
    end
    object Lightgreen1: TMenuItem
      Caption = '09 Light Green'
      OnClick = Lightgreen1Click
    end
    object Cyan1: TMenuItem
      Caption = '10 Cyan'
      OnClick = Cyan1Click
    end
    object LightCyan1: TMenuItem
      Caption = '11 Light Cyan'
      OnClick = LightCyan1Click
    end
    object LightBlue1: TMenuItem
      Caption = '12 Light Blue'
      OnClick = LightBlue1Click
    end
    object Pink1: TMenuItem
      Caption = '13 Pink'
      OnClick = Pink1Click
    end
    object Grey1: TMenuItem
      Caption = '14 Gray'
      OnClick = Grey1Click
    end
    object LightGray1: TMenuItem
      Caption = '15 Light Gray'
      OnClick = LightGray1Click
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object NoColor1: TMenuItem
      Caption = 'No Color'
      OnClick = NoColor1Click
    end
    object NoStyle1: TMenuItem
      Caption = 'No Style'
      OnClick = NoStyle1Click
    end
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Left = 320
    Top = 80
  end
end