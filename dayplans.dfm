object FormPlansDay: TFormPlansDay
  Left = 510
  Top = 175
  BorderStyle = bsSingle
  Caption = #1044#1085#1077#1074#1085#1099#1077' '#1087#1083#1072#1085#1099
  ClientHeight = 472
  ClientWidth = 654
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
  object StringGrid: TStringGrid
    Left = 121
    Top = 49
    Width = 533
    Height = 382
    Align = alClient
    ColCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    ParentFont = False
    TabOrder = 0
    OnSelectCell = StringGridSelectCell
  end
  object pnlBut: TPanel
    Left = 0
    Top = 431
    Width = 654
    Height = 41
    Align = alBottom
    TabOrder = 1
    object btnOk: TButton
      Left = 456
      Top = 8
      Width = 91
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = btnOkClick
    end
    object btnExit: TButton
      Left = 568
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
      OnClick = btnExitClick
    end
  end
  object ListBox: TListBox
    Left = 0
    Top = 49
    Width = 121
    Height = 382
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
    OnClick = ListBoxClick
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 654
    Height = 49
    ButtonHeight = 31
    Caption = 'ToolBar2'
    TabOrder = 3
    object pnlPlan: TPanel
      Left = 0
      Top = 2
      Width = 121
      Height = 31
      Caption = #8470' '#1055#1083#1072#1085#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object Splitter4: TSplitter
      Left = 121
      Top = 2
      Width = 200
      Height = 31
      Cursor = crHSplit
    end
    object dtpDateTime: TDateTimePicker
      Left = 321
      Top = 2
      Width = 100
      Height = 31
      CalAlignment = dtaLeft
      Date = 41668
      Time = 41668
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = dtkTime
      ParseInput = False
      ParentFont = False
      TabOrder = 0
      OnChange = dtpDateTimeChange
    end
    object Label1: TLabel
      Left = 421
      Top = 2
      Width = 85
      Height = 31
      Caption = '   ('#1095#1072#1089':'#1084#1080#1085'.)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
end
