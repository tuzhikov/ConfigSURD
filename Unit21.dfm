object Form21: TForm21
  Left = 441
  Top = 157
  BorderStyle = bsSingle
  Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1044#1050
  ClientHeight = 507
  ClientWidth = 711
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 7
    Top = 222
    Width = 154
    Height = 16
    Caption = #1057#1090#1072#1090#1091#1089' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 508
    Top = 24
    Width = 96
    Height = 16
    Caption = #1087#1088#1086#1075#1088'., '#1092#1072#1079#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 496
    Top = 6
    Width = 209
    Height = 87
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 509
    Top = 48
    Width = 37
    Height = 16
    Caption = #1044#1077#1085#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel2: TBevel
    Left = 4
    Top = 220
    Width = 701
    Height = 61
    Shape = bsFrame
  end
  object Label4: TLabel
    Left = 510
    Top = 68
    Width = 87
    Height = 16
    Caption = '0..6 ('#1042#1057'..'#1057#1041')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 508
    Top = 8
    Width = 49
    Height = 16
    Caption = #1053#1086#1084#1077#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object RadioGroup1: TRadioGroup
    Left = 4
    Top = 5
    Width = 485
    Height = 212
    Caption = ' '#1050#1086#1084#1072#1085#1076#1099' '#1076#1083#1103' '#1044#1050
    Color = clSilver
    Columns = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemIndex = 0
    Items.Strings = (
      '1. '#1046#1052
      '2. '#1054#1057
      '3. '#1054#1090#1084#1077#1085#1072' '#1087#1088#1080#1085#1091#1076#1080#1090#1077#1083#1100#1085#1099#1093
      '4. '#1057#1090#1072#1088#1090' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      '5. '#1057#1080#1085#1093#1088#1086#1085#1080#1079#1086#1074#1072#1090#1100' '#1074#1088#1077#1084#1103
      '6. '#1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1092#1072#1079#1091
      '7. '#1054#1087#1088#1086#1089#1080#1090#1100' '#1089#1086#1089#1090#1086#1103#1085#1080#1077
      '8. '#1055#1086#1089#1084#1086#1090#1088#1077#1090#1100' '#1090#1086#1082#1080)
    ParentColor = False
    ParentFont = False
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 9
    Top = 245
    Width = 688
    Height = 24
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object Button1: TButton
    Left = 496
    Top = 101
    Width = 209
    Height = 114
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 629
    Top = 475
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
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 612
    Top = 16
    Width = 49
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    Text = '1'
  end
  object UpDown1: TUpDown
    Left = 661
    Top = 16
    Width = 33
    Height = 28
    Associate = Edit2
    Min = 1
    Max = 33
    Position = 1
    TabOrder = 5
    Wrap = False
  end
  object Edit3: TEdit
    Left = 612
    Top = 54
    Width = 49
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    Text = '0'
  end
  object UpDown2: TUpDown
    Left = 661
    Top = 54
    Width = 34
    Height = 28
    Associate = Edit3
    Min = 0
    Max = 6
    Position = 0
    TabOrder = 7
    Wrap = False
  end
  object Memo1: TMemo
    Left = 7
    Top = 288
    Width = 695
    Height = 177
    Color = clInfoBk
    TabOrder = 8
  end
end
