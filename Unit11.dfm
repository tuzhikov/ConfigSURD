object Form11: TForm11
  Left = 474
  Top = 220
  Width = 361
  Height = 414
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = #1055#1088#1086#1075#1088#1077#1089#1089' '#1079#1072#1075#1088#1091#1079#1082#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 130
    Top = 6
    Width = 80
    Height = 16
    Caption = #1047#1072#1075#1088#1091#1079#1095#1080#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 11
    Top = 71
    Width = 65
    Height = 20
    Caption = #1057#1090#1072#1090#1091#1089' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 3
    Top = 4
    Width = 345
    Height = 325
    Shape = bsFrame
  end
  object ProgressBar1: TProgressBar
    Left = 10
    Top = 26
    Width = 329
    Height = 33
    Min = 0
    Max = 100
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 83
    Top = 67
    Width = 257
    Height = 28
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    Text = #1048#1076#1077#1090' '#1079#1072#1075#1088#1091#1079#1082#1072
  end
  object Memo1: TMemo
    Left = 8
    Top = 97
    Width = 337
    Height = 224
    TabOrder = 2
  end
  object Button1: TButton
    Left = 175
    Top = 343
    Width = 75
    Height = 25
    Caption = 'OK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
  end
  object Button2: TButton
    Left = 264
    Top = 344
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = Button2Click
  end
end
