object Form18: TForm18
  Left = 385
  Top = 176
  BorderStyle = bsSingle
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
  ClientHeight = 334
  ClientWidth = 398
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label4: TLabel
    Left = 8
    Top = 0
    Width = 180
    Height = 20
    Caption = #1042#1099#1073#1086#1088' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103':'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clPurple
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Button1: TButton
    Left = 166
    Top = 296
    Width = 75
    Height = 25
    Caption = 'OK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 246
    Top = 296
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object RadioButton1: TRadioButton
    Left = 7
    Top = 24
    Width = 113
    Height = 17
    Caption = 'COM '#1087#1086#1088#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 150
    Top = 24
    Width = 113
    Height = 17
    Caption = 'Ethernet'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    TabStop = True
    OnClick = z
  end
  object GroupBox1: TGroupBox
    Left = 152
    Top = 48
    Width = 169
    Height = 199
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' Ehternet'
    TabOrder = 4
    object Label1: TLabel
      Left = 9
      Top = 23
      Width = 43
      Height = 13
      Caption = 'IP-'#1072#1076#1088#1077#1089
    end
    object Label2: TLabel
      Left = 8
      Top = 72
      Width = 25
      Height = 13
      Caption = #1055#1086#1088#1090
    end
    object Label3: TLabel
      Left = 8
      Top = 130
      Width = 66
      Height = 13
      Caption = #1058#1072#1081#1084'-'#1072#1091#1090', '#1084#1089
    end
    object MaskEdit1: TMaskEdit
      Left = 8
      Top = 40
      Width = 149
      Height = 28
      EditMask = '000\.000\.000\.000;1;_'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 15
      ParentFont = False
      TabOrder = 0
      Text = '192.168.000.220'
    end
    object MaskEdit3: TMaskEdit
      Left = 8
      Top = 146
      Width = 58
      Height = 28
      EditMask = '0000;1;_'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 4
      ParentFont = False
      TabOrder = 1
      Text = '1200'
    end
    object Edit1: TEdit
      Left = 8
      Top = 88
      Width = 73
      Height = 28
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      MaxLength = 5
      ParentFont = False
      TabOrder = 2
      Text = '10001'
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 48
    Width = 137
    Height = 233
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' COM'
    TabOrder = 5
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 16
      Width = 121
      Height = 185
      Caption = #1042#1099#1073#1086#1088' '#1087#1086#1088#1090#1072
      ItemIndex = 1
      Items.Strings = (
        'COM1'
        'COM2'
        'COM3'
        'COM4'
        'COM5'
        'COM6'
        'COM7'
        'COM8'
        'COM9')
      TabOrder = 0
    end
    object CheckBox1: TCheckBox
      Left = 8
      Top = 208
      Width = 73
      Height = 17
      Hint = #1059#1074#1077#1083#1080#1095#1080#1090#1100' '#1090#1072#1081#1084'-'#1072#1091#1090#1099
      Caption = 'USB?'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
    end
  end
end
