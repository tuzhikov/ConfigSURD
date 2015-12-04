object Form4: TForm4
  Left = 548
  Top = 198
  BorderStyle = bsSingle
  Caption = #1053#1077#1076#1077#1083#1100#1085#1099#1077' '#1087#1083#1072#1085#1099
  ClientHeight = 482
  ClientWidth = 354
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 143
    Top = 150
    Width = 29
    Height = 24
    Caption = #1055#1053
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 143
    Top = 190
    Width = 27
    Height = 24
    Caption = #1042#1058
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 143
    Top = 230
    Width = 28
    Height = 24
    Caption = #1057#1056
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 143
    Top = 270
    Width = 26
    Height = 24
    Caption = #1063#1058
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 143
    Top = 310
    Width = 28
    Height = 24
    Caption = #1055#1058
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 143
    Top = 350
    Width = 29
    Height = 24
    Caption = #1057#1041
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 143
    Top = 102
    Width = 28
    Height = 24
    Caption = #1042#1057
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label8: TLabel
    Left = 126
    Top = 49
    Width = 204
    Height = 16
    Caption = #1055#1088#1080#1074#1103#1079#1082#1072' '#1089#1091#1090#1086#1095#1085#1099#1093' '#1087#1083#1072#1085#1086#1074
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label9: TLabel
    Left = 175
    Top = 65
    Width = 107
    Height = 16
    Caption = #1082' '#1076#1085#1103#1084' '#1085#1077#1076#1077#1083#1080
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 354
    Height = 29
    Caption = 'ToolBar1'
    TabOrder = 0
    object Panel2: TPanel
      Left = 0
      Top = 2
      Width = 121
      Height = 22
      Caption = #8470' '#1055#1083#1072#1085#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 441
    Width = 354
    Height = 41
    Align = alBottom
    TabOrder = 1
    object Button3: TButton
      Left = 136
      Top = 8
      Width = 107
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 264
      Top = 8
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = Button4Click
    end
  end
  object ListBox1: TListBox
    Left = 0
    Top = 29
    Width = 121
    Height = 412
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 24
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16')
    ParentFont = False
    TabOrder = 2
    OnClick = ListBox1Click
  end
  object ComboBox1: TComboBox
    Left = 184
    Top = 100
    Width = 89
    Height = 32
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 24
    ParentFont = False
    TabOrder = 3
    OnChange = ComboBox1Change
  end
  object ComboBox2: TComboBox
    Left = 184
    Top = 148
    Width = 89
    Height = 32
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 24
    ParentFont = False
    TabOrder = 4
    OnChange = ComboBox2Change
  end
  object ComboBox3: TComboBox
    Left = 184
    Top = 188
    Width = 89
    Height = 32
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 24
    ParentFont = False
    TabOrder = 5
    OnChange = ComboBox3Change
  end
  object ComboBox4: TComboBox
    Left = 184
    Top = 228
    Width = 89
    Height = 32
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 24
    ParentFont = False
    TabOrder = 6
    OnChange = ComboBox4Change
  end
  object ComboBox5: TComboBox
    Left = 184
    Top = 268
    Width = 89
    Height = 32
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 24
    ParentFont = False
    TabOrder = 7
    OnChange = ComboBox5Change
  end
  object ComboBox6: TComboBox
    Left = 184
    Top = 308
    Width = 89
    Height = 32
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 24
    ParentFont = False
    TabOrder = 8
    OnChange = ComboBox6Change
  end
  object ComboBox7: TComboBox
    Left = 184
    Top = 348
    Width = 89
    Height = 32
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 24
    ParentFont = False
    TabOrder = 9
    OnChange = ComboBox7Change
  end
end
