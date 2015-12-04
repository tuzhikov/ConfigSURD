object FormDk: TFormDk
  Left = 415
  Top = 174
  BorderStyle = bsSingle
  Caption = #1044#1050' '#1074' '#1075#1088#1091#1087#1087#1077'.'
  ClientHeight = 581
  ClientWidth = 871
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnHide = FormHide
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 540
    Width = 871
    Height = 41
    Align = alBottom
    TabOrder = 0
    object btnExit: TButton
      Left = 624
      Top = 8
      Width = 75
      Height = 25
      Caption = #1042#1067#1061#1054#1044
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = btnExitClick
    end
    object edtLog: TEdit
      Left = 7
      Top = 6
      Width = 586
      Height = 28
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 105
    Width = 871
    Height = 435
    ActivePage = TabSheet6
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Style = tsFlatButtons
    TabHeight = 50
    TabIndex = 5
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
      object Label11: TLabel
        Left = 384
        Top = 40
        Width = 72
        Height = 16
        Caption = #1050#1056#1040#1057#1053#1040#1071
      end
      object Label12: TLabel
        Left = 504
        Top = 40
        Width = 68
        Height = 16
        Caption = #1046#1045#1051#1058#1040#1071
      end
      object Label13: TLabel
        Left = 608
        Top = 40
        Width = 77
        Height = 16
        Caption = #1047#1045#1051#1045#1053#1040#1071
      end
      object Panel2: TPanel
        Left = 0
        Top = 41
        Width = 361
        Height = 334
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object Label1: TLabel
          Left = 12
          Top = 13
          Width = 113
          Height = 20
          Caption = #1056#1077#1078#1080#1084' '#1057#1059#1056#1044':'
        end
        object Label2: TLabel
          Left = 10
          Top = 53
          Width = 117
          Height = 20
          Caption = #1057#1090#1072#1090#1091#1089' '#1057#1059#1056#1044':'
        end
        object Label3: TLabel
          Left = 12
          Top = 174
          Width = 113
          Height = 20
          Caption = #1053#1086#1084#1077#1088' '#1092#1072#1079#1099':'
        end
        object Label15: TLabel
          Left = 5
          Top = 94
          Width = 126
          Height = 20
          Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1044#1050':'
        end
        object Label17: TLabel
          Left = 25
          Top = 254
          Width = 86
          Height = 20
          Caption = #1048#1089#1090#1086#1095#1085#1080#1082':'
        end
        object lblTime: TLabel
          Left = 12
          Top = 216
          Width = 112
          Height = 20
          Caption = #1042#1088#1077#1084#1103' '#1092#1072#1079#1099':'
        end
        object lblnet: TLabel
          Left = 9
          Top = 133
          Width = 118
          Height = 20
          Caption = #1057#1090#1072#1090#1091#1089' '#1089#1074#1103#1079#1080':'
        end
        object pnlmodesurd: TPanel
          Left = 136
          Top = 7
          Width = 220
          Height = 33
          TabOrder = 0
        end
        object pnlstsurd: TPanel
          Left = 136
          Top = 47
          Width = 220
          Height = 33
          TabOrder = 1
        end
        object pnlphase: TPanel
          Left = 136
          Top = 168
          Width = 220
          Height = 33
          TabOrder = 2
        end
        object pnlStat: TPanel
          Left = 136
          Top = 88
          Width = 220
          Height = 33
          TabOrder = 3
        end
        object pnlsource: TPanel
          Left = 136
          Top = 249
          Width = 220
          Height = 31
          TabOrder = 4
        end
        object pnlTime: TPanel
          Left = 136
          Top = 210
          Width = 220
          Height = 33
          TabOrder = 5
        end
        object pnlnet: TPanel
          Left = 136
          Top = 127
          Width = 220
          Height = 33
          TabOrder = 6
        end
      end
      object ToolBar1: TToolBar
        Left = 0
        Top = 0
        Width = 863
        Height = 41
        ButtonHeight = 24
        Caption = 'ToolBar1'
        EdgeInner = esNone
        EdgeOuter = esNone
        Flat = True
        TabOrder = 1
        object btnLook: TSpeedButton
          Left = 0
          Top = 0
          Width = 185
          Height = 24
          AllowAllUp = True
          Constraints.MaxWidth = 185
          Constraints.MinWidth = 185
          GroupIndex = 32
          Caption = #1057#1083#1077#1076#1080#1090#1100
          OnClick = btnLookClick
        end
        object Splitter1: TSplitter
          Left = 185
          Top = 0
          Width = 240
          Height = 24
          Cursor = crHSplit
          Constraints.MaxWidth = 240
          Constraints.MinWidth = 240
          ResizeStyle = rsNone
        end
        object Label10: TLabel
          Left = 425
          Top = 0
          Width = 200
          Height = 24
          Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1074#1099#1093#1086#1076#1086#1074
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
      object mmoRed: TMemo
        Left = 376
        Top = 64
        Width = 105
        Height = 281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Lines.Strings = (
          '')
        ParentFont = False
        TabOrder = 2
      end
      object mmoYellow: TMemo
        Left = 488
        Top = 64
        Width = 105
        Height = 281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Lines.Strings = (
          '')
        ParentFont = False
        TabOrder = 3
      end
      object mmoGreen: TMemo
        Left = 600
        Top = 64
        Width = 105
        Height = 281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Lines.Strings = (
          '')
        ParentFont = False
        TabOrder = 4
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1047#1072#1075#1088#1091#1079#1082#1072'/'#1042#1099#1075#1088#1091#1079#1082#1072
      ImageIndex = 1
      object Label4: TLabel
        Left = 80
        Top = 104
        Width = 151
        Height = 16
        Caption = #1057#1090#1072#1090#1091#1089' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '
      end
      object Label9: TLabel
        Left = 464
        Top = 16
        Width = 62
        Height = 16
        Caption = #1050#1086#1085#1089#1086#1083#1100
      end
      object btnUpLoad: TButton
        Left = 8
        Top = 56
        Width = 297
        Height = 41
        Caption = #1042#1099#1075#1088#1091#1079#1080#1090#1100' '#1087#1088#1086#1077#1082#1090' '#1080#1079' '#1044#1050
        TabOrder = 0
        OnClick = btnUpLoadClick
      end
      object btnLoad: TButton
        Left = 8
        Top = 8
        Width = 297
        Height = 41
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1087#1088#1086#1077#1082#1090' '#1074' '#1044#1050
        TabOrder = 1
        OnClick = btnLoadClick
      end
      object mmoConsole: TMemo
        Left = 320
        Top = 56
        Width = 369
        Height = 289
        TabOrder = 2
      end
      object Memo3: TMemo
        Left = 8
        Top = 128
        Width = 297
        Height = 217
        Lines.Strings = (
          '')
        TabOrder = 3
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ImageIndex = 2
      ParentFont = False
      object Label5: TLabel
        Left = 32
        Top = 16
        Width = 60
        Height = 20
        Caption = #1057#1090#1072#1090#1091#1089
      end
      object Label6: TLabel
        Left = 240
        Top = 16
        Width = 59
        Height = 20
        Caption = #1043#1088#1091#1087#1087#1072
      end
      object Label7: TLabel
        Left = 392
        Top = 16
        Width = 53
        Height = 20
        Caption = #1050#1072#1085#1072#1083
      end
      object Label8: TLabel
        Left = 528
        Top = 16
        Width = 102
        Height = 20
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
      end
      object btnTestOn: TSpeedButton
        Left = 16
        Top = 96
        Width = 185
        Height = 41
        AllowAllUp = True
        GroupIndex = 45
        Caption = #1042#1050#1051
        OnClick = btnTestOnClick
      end
      object Label14: TLabel
        Left = 56
        Top = 72
        Width = 104
        Height = 20
        Caption = #1058#1045#1057#1058' '#1088#1077#1078#1080#1084
      end
      object btnTestOff: TSpeedButton
        Left = 16
        Top = 144
        Width = 185
        Height = 41
        AllowAllUp = True
        GroupIndex = 45
        Down = True
        Caption = #1042#1067#1050#1051
        OnClick = btnTestOffClick
      end
      object Edit2: TEdit
        Left = 16
        Top = 40
        Width = 185
        Height = 28
        Enabled = False
        TabOrder = 0
      end
      object ListBox1: TListBox
        Left = 216
        Top = 40
        Width = 137
        Height = 281
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 29
        ParentFont = False
        TabOrder = 1
      end
      object ListBox2: TListBox
        Left = 368
        Top = 40
        Width = 97
        Height = 105
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 29
        Items.Strings = (
          #1050
          #1046
          #1047)
        ParentFont = False
        TabOrder = 2
      end
      object Memo2: TMemo
        Left = 488
        Top = 40
        Width = 193
        Height = 185
        TabOrder = 3
      end
      object btnChannelOn: TButton
        Left = 368
        Top = 176
        Width = 97
        Height = 65
        Caption = #1042#1050#1051
        TabOrder = 4
        OnClick = btnChannelOnClick
      end
      object btnChannelOff: TButton
        Left = 368
        Top = 248
        Width = 97
        Height = 57
        Caption = #1042#1067#1050#1051
        TabOrder = 5
        OnClick = btnChannelOffClick
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1046#1091#1088#1085#1072#1083
      ImageIndex = 3
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 185
        Height = 375
        Align = alLeft
        TabOrder = 0
        object Label18: TLabel
          Left = 56
          Top = 64
          Width = 56
          Height = 16
          Caption = #1063#1080#1090#1072#1077#1084
        end
        object Label19: TLabel
          Left = 16
          Top = 172
          Width = 62
          Height = 13
          Caption = #1057' '#1087#1086#1079#1080#1094#1080#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label20: TLabel
          Left = 64
          Top = 200
          Width = 19
          Height = 13
          Caption = #1087#1086' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object btnDump: TButton
          Left = 16
          Top = 128
          Width = 145
          Height = 33
          Caption = #1044#1040#1052#1055' '#1087#1072#1084#1103#1090#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = btnDumpClick
        end
        object btnClean: TButton
          Left = 16
          Top = 280
          Width = 145
          Height = 30
          Caption = #1054#1095#1080#1089#1090#1080#1090#1100
          TabOrder = 1
          OnClick = btnCleanClick
        end
        object btnReadJornal: TButton
          Left = 16
          Top = 13
          Width = 145
          Height = 41
          Caption = #1057#1095#1080#1090#1072#1090#1100' '#1078#1091#1088#1085#1072#1083
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = btnReadJornalClick
        end
        object btnExport: TButton
          Left = 16
          Top = 240
          Width = 145
          Height = 30
          Caption = #1069#1082#1089#1087#1086#1088#1090
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = btnExportClick
        end
        object ProgressBar1: TProgressBar
          Left = 14
          Top = 82
          Width = 150
          Height = 16
          Min = 0
          Max = 100
          TabOrder = 4
        end
        object btnStopReadJornal: TButton
          Left = 14
          Top = 102
          Width = 150
          Height = 20
          Caption = #1054#1089#1090#1072#1085#1086#1074#1080#1090#1100
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsItalic]
          ParentFont = False
          TabOrder = 5
          OnClick = btnStopReadJornalClick
        end
        object Edit4: TEdit
          Left = 96
          Top = 168
          Width = 65
          Height = 24
          TabOrder = 6
          Text = '1'
        end
        object Edit5: TEdit
          Left = 96
          Top = 194
          Width = 65
          Height = 24
          TabOrder = 7
          Text = '10'
        end
        object btnClearFlash: TButton
          Left = 16
          Top = 320
          Width = 145
          Height = 30
          Caption = #1057#1090#1077#1088#1077#1090#1100' FLASH'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 8
          OnClick = btnClearFlashClick
        end
      end
      object StringGridJor: TStringGrid
        Left = 185
        Top = 0
        Width = 678
        Height = 375
        Align = alClient
        ColCount = 2
        RowCount = 10
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
        ScrollBars = ssVertical
        TabOrder = 1
        ColWidths = (
          64
          456)
      end
    end
    object TabSheet5: TTabSheet
      Caption = #1042#1088#1077#1084#1103
      ImageIndex = 4
      object Edit3: TEdit
        Left = 24
        Top = 40
        Width = 337
        Height = 37
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
      object btnTimeSyn: TButton
        Left = 392
        Top = 27
        Width = 249
        Height = 49
        Caption = #1057#1080#1085#1093#1088#1086#1085#1080#1079#1086#1074#1072#1090#1100' '#1089' '#1055#1050
        TabOrder = 1
        OnClick = btnTimeSynClick
      end
      object btnSeeTime: TButton
        Left = 24
        Top = 88
        Width = 337
        Height = 49
        Caption = #1055#1086#1089#1084#1086#1090#1088#1077#1090#1100' '#1074#1088#1077#1084#1103
        TabOrder = 2
        OnClick = btnSeeTimeClick
      end
      object DateTimePicker1: TDateTimePicker
        Left = 32
        Top = 168
        Width = 329
        Height = 45
        CalAlignment = dtaLeft
        Date = 41836
        Time = 41836
        DateFormat = dfShort
        DateMode = dmComboBox
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -32
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Kind = dtkTime
        ParseInput = False
        ParentFont = False
        TabOrder = 3
      end
      object btnSetTime: TButton
        Left = 392
        Top = 168
        Width = 249
        Height = 49
        Caption = '<-----'#1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1086#1077
        TabOrder = 4
        OnClick = btnSetTimeClick
      end
      object btnMultiTime: TButton
        Left = 393
        Top = 231
        Width = 249
        Height = 49
        Caption = '<-----'#1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1085#1072' '#1074#1089#1077#1093' '#1044#1050' '
        TabOrder = 5
        OnClick = btnMultiTimeClick
      end
      object btnSyncAllDk: TButton
        Left = 392
        Top = 87
        Width = 249
        Height = 49
        Caption = #1057#1080#1085#1093#1088#1086#1085#1080#1079#1086#1074#1072#1090#1100' '#1089' '#1055#1050' '#1074#1089#1077' '#1044#1050
        TabOrder = 6
        OnClick = btnSyncAllDkClick
      end
    end
    object TabSheet6: TTabSheet
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103
      ImageIndex = 5
      object Memo4: TMemo
        Left = 0
        Top = 65
        Width = 863
        Height = 310
        Align = alClient
        BevelInner = bvNone
        BevelKind = bkFlat
        BevelOuter = bvNone
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object Panel11: TPanel
        Left = 0
        Top = 0
        Width = 863
        Height = 65
        Align = alTop
        TabOrder = 1
        object Splitter2: TSplitter
          Left = 1
          Top = 1
          Width = 100
          Height = 63
          Cursor = crHSplit
        end
        object btnSurd: TSpeedButton
          Left = 112
          Top = 8
          Width = 200
          Height = 45
          AllowAllUp = True
          GroupIndex = 1
          Caption = #1054#1073#1084#1077#1085' '#1087#1072#1082#1077#1090#1072#1084#1080' '#1057#1059#1056#1044
          OnClick = btnSurdClick
        end
        object btnInfoDk: TButton
          Left = 360
          Top = 8
          Width = 200
          Height = 45
          Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1044#1050
          TabOrder = 0
          OnClick = btnInfoDkClick
        end
        object btnConsol: TButton
          Left = 608
          Top = 8
          Width = 200
          Height = 45
          Caption = #1050#1086#1085#1089#1086#1083#1100
          TabOrder = 1
          OnClick = btnConsolClick
        end
      end
    end
  end
  object Panel8: TPanel
    Left = 0
    Top = 0
    Width = 871
    Height = 105
    Align = alTop
    TabOrder = 2
    object GroupBox1: TGroupBox
      Left = 530
      Top = 1
      Width = 340
      Height = 103
      Align = alLeft
      Caption = #1050#1086#1084#1072#1085#1076#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      object ButtonOS: TButton
        Left = 16
        Top = 24
        Width = 150
        Height = 25
        Caption = #1054#1057
        TabOrder = 0
        OnClick = ButtonOSClick
      end
      object ButtonOSUrg: TButton
        Left = 16
        Top = 64
        Width = 150
        Height = 25
        Caption = #1054#1057' '#1074#1089#1077
        TabOrder = 1
        OnClick = ButtonOSUrgClick
      end
      object ButtonRUN: TButton
        Left = 180
        Top = 24
        Width = 150
        Height = 25
        Caption = #1056#1040#1041#1054#1058#1040
        TabOrder = 2
        OnClick = ButtonRUNClick
      end
      object btnRestart: TButton
        Left = 180
        Top = 64
        Width = 150
        Height = 25
        Caption = #1056#1077#1089#1090#1072#1088#1090' '#1074#1089#1077
        TabOrder = 3
        OnClick = btnRestartClick
      end
    end
    object GroupBox2: TGroupBox
      Left = 1
      Top = 1
      Width = 529
      Height = 103
      Align = alLeft
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1079#1074#1103#1079#1080' c '#1044#1050
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      object Label16: TLabel
        Left = 22
        Top = 17
        Width = 39
        Height = 16
        Caption = 'ID '#1044#1050
      end
      object Label21: TLabel
        Left = 103
        Top = 17
        Width = 63
        Height = 16
        Caption = 'IP '#1072#1076#1088#1077#1089
      end
      object Label22: TLabel
        Left = 273
        Top = 17
        Width = 56
        Height = 16
        Caption = #1055#1072#1088#1086#1083#1100
      end
      object lblPort: TLabel
        Left = 210
        Top = 16
        Width = 38
        Height = 16
        Caption = #1055#1086#1088#1090
      end
      object medtIP: TMaskEdit
        Left = 72
        Top = 33
        Width = 123
        Height = 24
        Enabled = False
        TabOrder = 0
        Text = '169.254.016.001'
      end
      object edtPassword: TEdit
        Left = 271
        Top = 33
        Width = 65
        Height = 24
        Enabled = False
        MaxLength = 8
        TabOrder = 1
        Text = '999999'
      end
      object cbbDk: TComboBox
        Left = 16
        Top = 33
        Width = 52
        Height = 24
        Style = csDropDownList
        ItemHeight = 16
        ItemIndex = 0
        TabOrder = 2
        Text = '1'
        OnChange = cbbDkChange
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
          '16'
          '17'
          '18'
          '19'
          '20'
          '21'
          '22'
          '23'
          '24'
          '25'
          '26'
          '27'
          '28'
          '29'
          '30'
          '31'
          '32')
      end
      object btnDkDefault: TButton
        Left = 357
        Top = 30
        Width = 150
        Height = 25
        Caption = #1055#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
        Enabled = False
        TabOrder = 3
        OnClick = btnDkDefaultClick
      end
      object chkNet: TCheckBox
        Left = 17
        Top = 70
        Width = 316
        Height = 13
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1074#1103#1079#1080' '#1076#1083#1103' '#1090#1077#1089#1090#1086#1074
        TabOrder = 4
        OnClick = chkNetClick
      end
      object btnNet: TButton
        Left = 357
        Top = 64
        Width = 150
        Height = 25
        Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100'.'
        Enabled = False
        TabOrder = 5
        OnClick = btnNetClick
      end
      object edtPort: TEdit
        Left = 200
        Top = 33
        Width = 65
        Height = 24
        Enabled = False
        MaxLength = 5
        TabOrder = 6
        Text = '11990'
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 400
    OnTimer = Timer1Timer
    Left = 176
    Top = 216
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer2Timer
    Left = 208
    Top = 216
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 300
    OnTimer = Timer3Timer
    Left = 240
    Top = 216
  end
  object tmrSURD: TTimer
    Enabled = False
    Interval = 300
    OnTimer = tmrSURDTimer
    Left = 272
    Top = 216
  end
end
