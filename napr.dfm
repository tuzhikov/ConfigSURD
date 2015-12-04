object frmDirection: TfrmDirection
  Left = 239
  Top = -1
  Width = 1202
  Height = 812
  Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 16
  object spl: TSplitter
    Left = 145
    Top = 41
    Width = 3
    Height = 677
    Cursor = crHSplit
  end
  object Panel1: TPanel
    Left = 0
    Top = 718
    Width = 1194
    Height = 41
    Align = alBottom
    TabOrder = 0
    object btnClose: TButton
      Left = 144
      Top = 8
      Width = 100
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = btnCloseClick
    end
    object btnOk: TButton
      Left = 16
      Top = 8
      Width = 100
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 1
      OnClick = btnOkClick
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1194
    Height = 41
    ButtonHeight = 31
    Caption = 'ToolBar1'
    TabOrder = 1
    object btnPlus: TBitBtn
      Left = 0
      Top = 2
      Width = 49
      Height = 31
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Caption = '+'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = btnPlusClick
    end
    object Splitter1: TSplitter
      Left = 49
      Top = 2
      Width = 16
      Height = 31
      Cursor = crHSplit
    end
    object BitBtn2: TBitBtn
      Left = 65
      Top = 2
      Width = 48
      Height = 31
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1087#1086#1089#1083#1077#1076#1085#1077#1077
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = BitBtn2Click
    end
    object Splitter2: TSplitter
      Left = 113
      Top = 2
      Width = 24
      Height = 31
      Cursor = crHSplit
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 759
    Width = 1194
    Height = 19
    Panels = <>
    SimplePanel = False
    SimpleText = 'qew'
  end
  object scrlbxDirection: TScrollBox
    Left = 148
    Top = 41
    Width = 1046
    Height = 677
    Align = alClient
    BevelInner = bvLowered
    BevelKind = bkTile
    Color = clMoneyGreen
    ParentColor = False
    TabOrder = 3
    object pnlR1: TPanel
      Left = 0
      Top = 8
      Width = 200
      Height = 80
      Hint = '80'
      TabOrder = 0
      object Label4: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR1: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR1: TLabel
        Left = 89
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR1: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
        OnChange = cbbChangePORT
      end
      object cbbCollorR1: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR1: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR1: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY1: TPanel
      Left = 205
      Top = 8
      Width = 200
      Height = 80
      TabOrder = 1
      object Label5: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY1: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY1: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY11: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY11: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY11: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY11: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG1: TPanel
      Left = 410
      Top = 8
      Width = 200
      Height = 80
      TabOrder = 2
      object Label7: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG1: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG1: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG11: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG11: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG11: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG11: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY11: TPanel
      Left = 828
      Top = 179
      Width = 200
      Height = 80
      TabOrder = 3
      object Label16: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY11: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY11: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY32: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY32: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY32: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY32: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR11: TPanel
      Left = 620
      Top = 179
      Width = 200
      Height = 80
      TabOrder = 4
      object Label17: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR11: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR11: TLabel
        Left = 91
        Top = 6
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR32: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR32: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR32: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR32: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG11: TPanel
      Left = 1037
      Top = 179
      Width = 200
      Height = 80
      TabOrder = 5
      object Label18: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG11: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG11: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG32: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG32: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG32: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG32: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY3: TPanel
      Left = 205
      Top = 179
      Width = 200
      Height = 80
      TabOrder = 6
      object Label19: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY3: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY3: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY31: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY31: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY31: TCheckBox
        Left = 26
        Top = 58
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY31: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR3: TPanel
      Left = 0
      Top = 179
      Width = 200
      Height = 80
      TabOrder = 7
      object Label20: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR3: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR3: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR3: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
        OnChange = cbbChangePORT
      end
      object cbbCollorR3: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR3: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR3: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG3: TPanel
      Left = 410
      Top = 179
      Width = 200
      Height = 80
      TabOrder = 8
      object Label21: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG3: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG3: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG31: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG31: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG31: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG31: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY12: TPanel
      Left = 828
      Top = 265
      Width = 200
      Height = 80
      TabOrder = 9
      object Label22: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY12: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY12: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY42: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY42: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY42: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY42: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR12: TPanel
      Left = 620
      Top = 265
      Width = 200
      Height = 80
      TabOrder = 10
      object Label23: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR12: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR12: TLabel
        Left = 90
        Top = 6
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR42: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR42: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR42: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR42: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG12: TPanel
      Left = 1037
      Top = 265
      Width = 200
      Height = 80
      TabOrder = 11
      object Label24: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG12: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG12: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG42: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG42: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG42: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG42: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY4: TPanel
      Left = 205
      Top = 265
      Width = 200
      Height = 80
      TabOrder = 12
      object Label25: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY4: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY4: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY41: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY41: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY41: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY41: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR4: TPanel
      Left = 0
      Top = 265
      Width = 200
      Height = 80
      TabOrder = 13
      object Label26: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR4: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR4: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR4: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
        OnChange = cbbChangePORT
      end
      object cbbCollorR4: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR4: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR4: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG4: TPanel
      Left = 410
      Top = 265
      Width = 200
      Height = 80
      TabOrder = 14
      object Label27: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG4: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG4: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG41: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG41: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG41: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG41: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY13: TPanel
      Left = 828
      Top = 352
      Width = 200
      Height = 80
      TabOrder = 15
      object Label28: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY13: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY13: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY52: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY52: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY52: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY52: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR13: TPanel
      Left = 620
      Top = 352
      Width = 200
      Height = 80
      TabOrder = 16
      object Label29: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR13: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR13: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR52: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR52: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR52: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR52: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG13: TPanel
      Left = 1037
      Top = 352
      Width = 200
      Height = 80
      TabOrder = 17
      object Label30: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG13: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG13: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG52: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG52: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG52: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG52: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY5: TPanel
      Left = 205
      Top = 352
      Width = 200
      Height = 80
      TabOrder = 18
      object Label31: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY5: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY5: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY51: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY51: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY51: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY51: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR5: TPanel
      Left = 0
      Top = 352
      Width = 200
      Height = 80
      TabOrder = 19
      object Label32: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR5: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR5: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR5: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
        OnChange = cbbChangePORT
      end
      object cbbCollorR5: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR5: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR5: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG5: TPanel
      Left = 410
      Top = 352
      Width = 200
      Height = 80
      TabOrder = 20
      object Label33: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG5: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG5: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG51: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG51: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG51: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG51: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY14: TPanel
      Left = 828
      Top = 440
      Width = 200
      Height = 80
      TabOrder = 21
      object Label34: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY14: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY14: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY62: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY62: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY62: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY62: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR14: TPanel
      Left = 620
      Top = 440
      Width = 200
      Height = 80
      TabOrder = 22
      object Label35: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR14: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR14: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR62: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR62: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR62: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR62: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG14: TPanel
      Left = 1037
      Top = 440
      Width = 200
      Height = 80
      TabOrder = 23
      object Label36: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG14: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG14: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG62: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG62: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG62: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG62: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY6: TPanel
      Left = 205
      Top = 440
      Width = 200
      Height = 80
      TabOrder = 24
      object Label37: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY6: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY6: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY61: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY61: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY61: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY61: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR6: TPanel
      Left = 0
      Top = 440
      Width = 200
      Height = 80
      TabOrder = 25
      object Label38: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR6: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR6: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR6: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR6: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR6: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR6: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG6: TPanel
      Left = 410
      Top = 440
      Width = 200
      Height = 80
      TabOrder = 26
      object Label39: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG6: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG6: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG61: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG61: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG61: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG61: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY15: TPanel
      Left = 828
      Top = 527
      Width = 200
      Height = 80
      TabOrder = 27
      object Label40: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY15: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY15: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY72: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY72: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY72: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY72: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR15: TPanel
      Left = 620
      Top = 527
      Width = 200
      Height = 80
      TabOrder = 28
      object Label41: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR15: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR15: TLabel
        Left = 91
        Top = 6
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR72: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR72: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR72: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR72: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG15: TPanel
      Left = 1037
      Top = 527
      Width = 200
      Height = 80
      TabOrder = 29
      object Label42: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG15: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG15: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG72: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG72: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG72: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG72: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY7: TPanel
      Left = 205
      Top = 527
      Width = 200
      Height = 80
      TabOrder = 30
      object Label43: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY7: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY7: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY71: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY71: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY71: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY71: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR7: TPanel
      Left = 0
      Top = 527
      Width = 200
      Height = 80
      TabOrder = 31
      object Label44: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR7: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR7: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR7: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR7: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR7: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR7: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG7: TPanel
      Left = 410
      Top = 527
      Width = 200
      Height = 80
      TabOrder = 32
      object Label45: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG7: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG7: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG71: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG71: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG71: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG71: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY16: TPanel
      Left = 828
      Top = 614
      Width = 200
      Height = 80
      TabOrder = 33
      object Label46: TLabel
        Left = 17
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY16: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY16: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY82: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY82: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY82: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY82: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR16: TPanel
      Left = 620
      Top = 614
      Width = 200
      Height = 80
      TabOrder = 34
      object Label47: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR16: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR16: TLabel
        Left = 91
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR82: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR82: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR82: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR82: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG16: TPanel
      Left = 1037
      Top = 614
      Width = 200
      Height = 80
      TabOrder = 35
      object Label48: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG16: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG16: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG82: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG82: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG82: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG82: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY8: TPanel
      Left = 205
      Top = 614
      Width = 200
      Height = 80
      TabOrder = 36
      object Label49: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY8: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY8: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY81: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY81: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY81: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY81: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR8: TPanel
      Left = 0
      Top = 614
      Width = 200
      Height = 80
      TabOrder = 37
      object Label50: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR8: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR8: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR8: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR8: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR8: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR8: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG8: TPanel
      Left = 410
      Top = 614
      Width = 200
      Height = 80
      TabOrder = 38
      object Label51: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG8: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG8: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG81: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG81: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG81: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG81: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY9: TPanel
      Left = 828
      Top = 8
      Width = 200
      Height = 80
      TabOrder = 39
      object Label1: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY9: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY9: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY12: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY12: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY12: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY12: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR9: TPanel
      Left = 620
      Top = 8
      Width = 200
      Height = 80
      TabOrder = 40
      object Label2: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR9: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR9: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR12: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR12: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR12: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR12: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG9: TPanel
      Left = 1037
      Top = 8
      Width = 200
      Height = 80
      TabOrder = 41
      object Label3: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG9: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG9: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG12: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG12: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG12: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG12: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY2: TPanel
      Left = 205
      Top = 93
      Width = 200
      Height = 80
      TabOrder = 42
      object Label6: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY2: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY2: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY21: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY21: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY21: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY21: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR2: TPanel
      Left = 0
      Top = 93
      Width = 200
      Height = 80
      TabOrder = 43
      object Label8: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR2: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR2: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR2: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
        OnChange = cbbChangePORT
      end
      object cbbCollorR2: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR2: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR2: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG2: TPanel
      Left = 410
      Top = 93
      Width = 200
      Height = 80
      TabOrder = 44
      object Label9: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG2: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG2: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG21: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG21: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG21: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG21: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlY10: TPanel
      Left = 828
      Top = 93
      Width = 200
      Height = 80
      TabOrder = 45
      object Label10: TLabel
        Left = 33
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpY10: TShape
        Left = 86
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clYellow
        Shape = stCircle
      end
      object lblY10: TLabel
        Left = 88
        Top = 8
        Width = 12
        Height = 16
        Caption = #1053
      end
      object cbbGroupY22: TComboBox
        Left = 6
        Top = 35
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorY22: TComboBox
        Left = 96
        Top = 35
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkY22: TCheckBox
        Left = 33
        Top = 56
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkY22: TComboBox
        Left = 146
        Top = 35
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlR10: TPanel
      Left = 620
      Top = 93
      Width = 200
      Height = 80
      TabOrder = 46
      object Label11: TLabel
        Left = 31
        Top = 24
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpR10: TShape
        Left = 88
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clRed
        Shape = stCircle
      end
      object lblR10: TLabel
        Left = 90
        Top = 7
        Width = 12
        Height = 16
        Caption = #1055
      end
      object cbbGroupR22: TComboBox
        Left = 6
        Top = 41
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorR22: TComboBox
        Left = 94
        Top = 41
        Width = 50
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkR22: TCheckBox
        Left = 30
        Top = 61
        Width = 145
        Height = 16
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkR22: TComboBox
        Left = 144
        Top = 41
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
    object pnlG10: TPanel
      Left = 1037
      Top = 93
      Width = 200
      Height = 80
      TabOrder = 47
      object Label12: TLabel
        Left = 29
        Top = 21
        Width = 149
        Height = 13
        Caption = #1043#1088#1091#1087#1087#1072'       '#1062#1074#1077#1090'    '#8470' '#1044#1050
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object shpG10: TShape
        Left = 89
        Top = 8
        Width = 15
        Height = 15
        Brush.Color = clGreen
        Shape = stCircle
      end
      object lblG10: TLabel
        Left = 91
        Top = 8
        Width = 13
        Height = 16
        Caption = #1060
      end
      object cbbGroupG22: TComboBox
        Left = 6
        Top = 34
        Width = 89
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 0
      end
      object cbbCollorG22: TComboBox
        Left = 94
        Top = 34
        Width = 49
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 1
      end
      object chkG22: TCheckBox
        Left = 33
        Top = 55
        Width = 145
        Height = 17
        Caption = #1042#1099#1082#1083'. '#1082#1086#1085#1090#1088#1086#1083#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object cbbDkG22: TComboBox
        Left = 142
        Top = 34
        Width = 50
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
    end
  end
  object lstOut: TListBox
    Left = 0
    Top = 41
    Width = 145
    Height = 677
    Align = alLeft
    ItemHeight = 16
    TabOrder = 4
    OnClick = lstOutClick
  end
  object pnlPlus: TPanel
    Left = 7
    Top = 46
    Width = 217
    Height = 209
    BorderWidth = 6
    Color = clSkyBlue
    TabOrder = 5
    Visible = False
    object Panel19: TPanel
      Left = 7
      Top = 7
      Width = 203
      Height = 24
      Align = alTop
      Caption = #1058#1080#1087' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103
      Color = clFuchsia
      TabOrder = 0
    end
    object lstPanelPlus: TListBox
      Left = 7
      Top = 31
      Width = 203
      Height = 135
      Align = alClient
      ItemHeight = 16
      TabOrder = 1
    end
    object Panel20: TPanel
      Left = 7
      Top = 166
      Width = 203
      Height = 36
      Align = alBottom
      TabOrder = 2
      object pnlPlusOk: TPanel
        Left = 6
        Top = 5
        Width = 89
        Height = 25
        Caption = 'OK'
        TabOrder = 0
        OnClick = Panel5Click
      end
      object pnlPlusExit: TPanel
        Left = 110
        Top = 6
        Width = 89
        Height = 25
        Caption = #1054#1090#1084#1077#1085#1072
        TabOrder = 1
        OnClick = Panel6Click
      end
    end
  end
end
