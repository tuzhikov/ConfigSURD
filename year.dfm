object Form5: TForm5
  Left = 381
  Top = 185
  BorderStyle = bsSingle
  Caption = #1043#1086#1076#1086#1074#1086#1081' '#1087#1083#1072#1085
  ClientHeight = 423
  ClientWidth = 480
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
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 480
    Height = 33
    ButtonHeight = 24
    Caption = 'ToolBar1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object Panel2: TPanel
      Left = 0
      Top = 2
      Width = 41
      Height = 24
      Caption = #1057
      TabOrder = 0
    end
    object ComboBox1: TComboBox
      Left = 41
      Top = 2
      Width = 80
      Height = 24
      Style = csDropDownList
      ItemHeight = 16
      TabOrder = 1
    end
    object Panel3: TPanel
      Left = 121
      Top = 2
      Width = 40
      Height = 24
      Caption = #1087#1086
      TabOrder = 2
    end
    object ComboBox2: TComboBox
      Left = 161
      Top = 2
      Width = 72
      Height = 24
      Style = csDropDownList
      ItemHeight = 16
      TabOrder = 3
    end
    object Button3: TButton
      Left = 233
      Top = 2
      Width = 144
      Height = 24
      Caption = #1059#1057#1058#1040#1053#1054#1042#1048#1058#1068
      TabOrder = 5
      OnClick = Button3Click
    end
    object ComboBox3: TComboBox
      Left = 377
      Top = 2
      Width = 96
      Height = 24
      Style = csDropDownList
      ItemHeight = 16
      TabOrder = 4
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 382
    Width = 480
    Height = 41
    Align = alBottom
    TabOrder = 1
    object Button1: TButton
      Left = 272
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
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 392
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
      OnClick = Button2Click
    end
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 33
    Width = 480
    Height = 349
    Align = alClient
    RowCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    ParentFont = False
    TabOrder = 2
    OnSelectCell = StringGrid1SelectCell
  end
end
