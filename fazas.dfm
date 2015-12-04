object frPhaseTemplate: TfrPhaseTemplate
  Left = 504
  Top = 189
  Width = 541
  Height = 493
  Caption = #1064#1072#1073#1083#1086#1085#1099' '#1092#1072#1079
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
  object Panel1: TPanel
    Left = 0
    Top = 399
    Width = 533
    Height = 41
    Align = alBottom
    TabOrder = 0
    object btnClose: TButton
      Left = 120
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
      TabOrder = 0
      OnClick = btnCloseClick
    end
    object btnSave: TButton
      Left = 8
      Top = 8
      Width = 99
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = btnSaveClick
    end
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 29
    Width = 533
    Height = 370
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnDrawCell = StringGrid1DrawCell
    OnSelectCell = StringGrid1SelectCell
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 440
    Width = 533
    Height = 19
    Panels = <>
    SimplePanel = False
    SimpleText = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1086#1089#1090#1086#1103#1085#1080#1077' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1081' '#1074' '#1092#1072#1079#1072#1093
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 533
    Height = 29
    Caption = 'ToolBar1'
    TabOrder = 3
  end
end
