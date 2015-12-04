object FormMain: TFormMain
  Left = 370
  Top = 175
  Width = 949
  Height = 604
  Caption = #1057#1059#1056#1044
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 38
    Width = 941
    Height = 35
    ButtonHeight = 32
    Caption = 'ToolBar1'
    Color = clMoneyGreen
    ParentColor = False
    TabOrder = 0
    object Splitter6: TSplitter
      Left = 0
      Top = 2
      Width = 5
      Height = 32
      Cursor = crHSplit
    end
    object btn_BtAddDirection: TBitBtn
      Left = 5
      Top = 2
      Width = 35
      Height = 32
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1092#1072#1079#1091
      Caption = '+'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -32
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = btn_BtAddDirectionClick
      Style = bsWin31
    end
    object Splitter1: TSplitter
      Left = 40
      Top = 2
      Width = 9
      Height = 32
      Cursor = crHSplit
    end
    object btn_BtRemoveDirection: TBitBtn
      Left = 49
      Top = 2
      Width = 32
      Height = 32
      Hint = #1059#1084#1077#1085#1100#1096#1080#1090#1100' '#1082#1086#1083'-'#1074#1086' '#1092#1072#1079
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -43
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = btn_BtRemoveDirectionClick
    end
    object Splitter2: TSplitter
      Left = 81
      Top = 2
      Width = 31
      Height = 32
      Cursor = crHSplit
    end
    object btn_ZoomInc: TBitBtn
      Left = 112
      Top = 2
      Width = 32
      Height = 32
      Hint = #1059#1074#1077#1083#1080#1095#1080#1090#1100' '#1084#1072#1089#1096#1090#1072#1073
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = btn_ZoomIncClick
      Glyph.Data = {
        2E0A0000424D2E0A00000000000036000000280000001D0000001D0000000100
        180000000000F8090000C40E0000C40E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080000000FFFFFFFFFFFFFFFF
        FF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFF000000808080808080808080000000000000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000080808080
        808080808080808080808080808000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080808080808080808080808080
        808080000000FFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFF000000808080808080808080808080808080808080000000FFFFFFFFFF
        FF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000
        000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000008080808080
        80808080808080808080808080000000FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000FFFFFFFFFFFFFFFFFFFFFF
        FF000000000000000000FFFFFF00000080808080808080808080808080808080
        8080000000FFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFF0000
        00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF000000000000808080808080808080808080808080000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        000000808080808080808080000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000008080
        80000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFF000000FFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
        00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFF0000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00000000FFFFFF00000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFF000000FFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFF000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
        00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00}
    end
    object Splitter3: TSplitter
      Left = 144
      Top = 2
      Width = 9
      Height = 32
      Cursor = crHSplit
    end
    object btn_ZoomReduce: TBitBtn
      Left = 153
      Top = 2
      Width = 32
      Height = 32
      Hint = #1059#1084#1077#1085#1100#1096#1080#1090#1100' '#1084#1072#1089#1096#1090#1072#1073
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnClick = btn_ZoomReduceClick
      Glyph.Data = {
        2E0A0000424D2E0A00000000000036000000280000001D0000001D0000000100
        180000000000F8090000C40E0000C40E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080000000FFFFFFFFFFFFFFFF
        FF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFF000000808080808080808080000000000000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000080808080
        808080808080808080808080808000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080808080808080808080808080
        808080000000FFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFF000000808080808080808080808080808080808080000000FFFFFFFFFF
        FF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000
        000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000008080808080
        80808080808080808080808080000000FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF000000000000000000FFFFFFFFFFFFFFFFFFFFFF
        FF000000000000000000FFFFFF00000080808080808080808080808080808080
        8080000000FFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFF0000
        00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF000000000000808080808080808080808080808080000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        000000808080808080808080000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000008080
        80000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFF000000FFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
        00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFF0000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00000000FFFFFF00000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFF000000FFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFF000000FFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
        00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00}
    end
    object Splitter4: TSplitter
      Left = 185
      Top = 2
      Width = 31
      Height = 32
      Cursor = crHSplit
    end
    object Panel4: TPanel
      Left = 216
      Top = 2
      Width = 129
      Height = 32
      BevelOuter = bvNone
      Caption = #1057#1091#1090#1086#1095#1085#1099#1081' '#1087#1083#1072#1085'.'
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
    end
    object Splitter18: TSplitter
      Left = 345
      Top = 2
      Width = 7
      Height = 32
      Cursor = crHSplit
    end
    object btnPhaseOld: TButton
      Left = 352
      Top = 2
      Width = 42
      Height = 32
      Hint = #1055#1088#1077#1076#1099#1076#1091#1097#1072#1103' '#1087#1088#1086#1075#1088#1072#1084#1084#1072
      Caption = '<'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 7
      OnClick = btnPhaseOldClick
    end
    object cbbDayPlan: TComboBox
      Left = 394
      Top = 2
      Width = 82
      Height = 32
      Hint = #1055#1077#1088#1077#1081#1090#1080' '#1085#1072' '#1087#1088#1086#1075#1088#1072#1084#1084#1091
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemHeight = 24
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      OnChange = cbbDayPlanChange
    end
    object btnPhaseAdd: TButton
      Left = 476
      Top = 2
      Width = 41
      Height = 32
      Hint = #1057#1083#1077#1076#1091#1102#1097#1072#1103' '#1087#1088#1086#1075#1088#1072#1084#1084#1072
      Caption = '>'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      OnClick = btnPhaseAddClick
    end
    object Splitter5: TSplitter
      Left = 517
      Top = 2
      Width = 30
      Height = 32
      Cursor = crHSplit
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 531
    Width = 941
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 108
    Width = 941
    Height = 423
    Align = alClient
    BevelInner = bvSpace
    BevelOuter = bvRaised
    BevelKind = bkSoft
    Color = clTeal
    ParentColor = False
    TabOrder = 2
    object PanelEdit: TPanel
      Left = 88
      Top = 79
      Width = 329
      Height = 230
      BevelInner = bvLowered
      BevelOuter = bvSpace
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Visible = False
      OnMouseDown = PanelEditMouseDown
      OnMouseMove = PanelEditMouseMove
      OnMouseUp = PanelEditMouseUp
      object Splitter16: TSplitter
        Left = 2
        Top = 2
        Width = 325
        Height = 10
        Cursor = crVSplit
        Align = alTop
      end
      object Button2: TButton
        Left = 169
        Top = 199
        Width = 73
        Height = 22
        Caption = 'OK'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 249
        Top = 199
        Width = 73
        Height = 22
        Caption = #1054#1090#1084#1077#1085#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button3Click
      end
      object PageControl1: TPageControl
        Left = 2
        Top = 12
        Width = 325
        Height = 177
        ActivePage = TabSheet1
        Align = alTop
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabIndex = 0
        TabOrder = 2
        object TabSheet1: TTabSheet
          Caption = #1054#1057#1053#1054#1042#1053#1067#1045
          object Label7: TLabel
            Left = 8
            Top = 4
            Width = 43
            Height = 16
            Caption = #1053#1072#1087#1088'.'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label6: TLabel
            Left = 72
            Top = 4
            Width = 40
            Height = 16
            Caption = #1060#1072#1079#1072
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label8: TLabel
            Left = 168
            Top = 4
            Width = 106
            Height = 16
            Caption = #1064#1072#1073#1083#1086#1085' '#1060#1040#1047#1067
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label5: TLabel
            Left = 4
            Top = 72
            Width = 203
            Height = 16
            Caption = #1054#1089#1085#1086#1074#1085#1086#1077' '#1074#1088#1077#1084#1103' '#1058#1086#1089#1085', '#1084#1080#1085'.'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object PanelFazaNum: TPanel
            Left = 71
            Top = 24
            Width = 42
            Height = 32
            BevelInner = bvLowered
            Caption = '2'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 0
          end
          object PanelNaprNum: TPanel
            Left = 8
            Top = 24
            Width = 41
            Height = 32
            BevelInner = bvLowered
            Caption = '3'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 1
          end
          object ComboBoxNumFaza: TComboBox
            Left = 200
            Top = 24
            Width = 113
            Height = 32
            Style = csDropDownList
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 24
            ParentFont = False
            TabOrder = 2
          end
          object Edit1: TEdit
            Left = 248
            Top = 66
            Width = 65
            Height = 28
            Color = clScrollBar
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            ReadOnly = True
            TabOrder = 3
          end
        end
        object TabSheet2: TTabSheet
          Caption = #1055#1056#1054#1052
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ImageIndex = 1
          ParentFont = False
          object Label3: TLabel
            Left = 8
            Top = 64
            Width = 133
            Height = 20
            Caption = #1047#1077#1083#1077#1085#1099#1081' '#1076#1086#1087'. 2'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label1: TLabel
            Left = 8
            Top = 16
            Width = 133
            Height = 20
            Caption = #1047#1077#1083#1077#1085#1099#1081' '#1076#1086#1087'. 1'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label4: TLabel
            Left = 8
            Top = 106
            Width = 115
            Height = 20
            Caption = #1050#1088#1072#1089#1085#1099#1081' '#1076#1086#1087'.'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Edit2: TEdit
            Left = 177
            Top = 13
            Width = 65
            Height = 28
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 0
            Text = '11'
          end
          object Edit3: TEdit
            Left = 176
            Top = 56
            Width = 65
            Height = 28
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 1
            Text = '12'
          end
          object Edit6: TEdit
            Left = 175
            Top = 106
            Width = 66
            Height = 28
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -16
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 2
            Text = '5'
          end
        end
      end
    end
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 73
    Width = 941
    Height = 35
    ButtonHeight = 28
    Caption = 'ToolBar2'
    Color = clMoneyGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    TabOrder = 3
    object Splitter17: TSplitter
      Left = 0
      Top = 2
      Width = 5
      Height = 28
      Cursor = crHSplit
    end
    object Panel9: TPanel
      Left = 5
      Top = 2
      Width = 74
      Height = 28
      Hint = #1055#1086#1088#1103#1076#1082#1086#1074#1099#1081' '#1085#1086#1084#1077#1088' '#1092#1072#1079#1099' '#1074' '#1087#1088#1086#1077#1082#1090#1077
      BevelOuter = bvNone
      Caption = #8470' '#1060#1072#1079#1099
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
    end
    object pnlPhasa: TPanel
      Left = 79
      Top = 2
      Width = 35
      Height = 28
      Hint = #1055#1086#1088#1103#1076#1082#1086#1074#1099#1081' '#1085#1086#1084#1077#1088' '#1092#1072#1079#1099' '#1074' '#1087#1088#1086#1077#1082#1090#1077
      BevelOuter = bvNone
      Caption = '1'
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
    end
    object Panel8: TPanel
      Left = 114
      Top = 2
      Width = 140
      Height = 28
      Hint = #1055#1086#1088#1103#1076#1082#1086#1074#1099#1081' '#1085#1086#1084#1077#1088' '#1092#1072#1079#1099' '#1074' '#1087#1088#1086#1077#1082#1090#1077
      BevelOuter = bvNone
      Caption = #1053#1072#1095#1072#1083#1086' ('#1095#1072#1089':'#1084#1080#1085'.):'
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
    end
    object pnlTimeStart: TPanel
      Left = 254
      Top = 2
      Width = 100
      Height = 28
      Caption = '00:00'
      Color = clMoneyGreen
      TabOrder = 5
    end
    object Splitter8: TSplitter
      Left = 354
      Top = 2
      Width = 32
      Height = 28
      Cursor = crHSplit
    end
    object Panel1: TPanel
      Left = 386
      Top = 2
      Width = 125
      Height = 28
      BevelOuter = bvNone
      Caption = #1050#1086#1085#1077#1094' ('#1095#1072#1089':'#1084#1080#1085'):'
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object pnlTimeEnd: TPanel
      Left = 511
      Top = 2
      Width = 100
      Height = 28
      Caption = '00:00'
      Color = clMoneyGreen
      TabOrder = 4
    end
    object Splitter19: TSplitter
      Left = 611
      Top = 2
      Width = 32
      Height = 28
      Cursor = crHSplit
    end
  end
  object ToolBar3: TToolBar
    Left = 0
    Top = 0
    Width = 941
    Height = 38
    ButtonHeight = 32
    Caption = 'ToolBar3'
    Color = clMoneyGreen
    DockSite = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    TabOrder = 4
    object Splitter15: TSplitter
      Left = 0
      Top = 2
      Width = 5
      Height = 32
      Cursor = crHSplit
    end
    object btn_ButSetup: TBitBtn
      Left = 5
      Top = 2
      Width = 91
      Height = 32
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      TabOrder = 0
      OnClick = btn_ButSetupClick
    end
    object Splitter12: TSplitter
      Left = 96
      Top = 2
      Width = 15
      Height = 32
      Cursor = crHSplit
    end
    object btn_Direction: TBitBtn
      Left = 111
      Top = 2
      Width = 96
      Height = 32
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103
      TabOrder = 1
      OnClick = btn_DirectionClick
    end
    object Splitter14: TSplitter
      Left = 207
      Top = 2
      Width = 10
      Height = 32
      Cursor = crHSplit
    end
    object btnUDZ: TButton
      Left = 217
      Top = 2
      Width = 110
      Height = 32
      Caption = #1059#1044#1047#1057#1043
      TabOrder = 8
      OnClick = btnUDZClick
    end
    object Splitter11: TSplitter
      Left = 327
      Top = 2
      Width = 10
      Height = 32
      Cursor = crHSplit
    end
    object btn_Safety: TBitBtn
      Left = 337
      Top = 2
      Width = 110
      Height = 32
      Caption = #1041#1077#1079#1086#1087#1072#1089#1085#1086#1089#1090#1100
      TabOrder = 2
      OnClick = btn_SafetyClick
    end
    object spl1: TSplitter
      Left = 447
      Top = 2
      Width = 10
      Height = 32
      Cursor = crHSplit
    end
    object btnPhase: TBitBtn
      Left = 457
      Top = 2
      Width = 103
      Height = 32
      Caption = #1064#1072#1073#1083#1086#1085#1099' '#1092#1072#1079
      TabOrder = 7
      OnClick = btnPhaseClick
    end
    object Splitter7: TSplitter
      Left = 560
      Top = 2
      Width = 10
      Height = 32
      Cursor = crHSplit
    end
    object btnDayPlan: TBitBtn
      Left = 570
      Top = 2
      Width = 80
      Height = 32
      Caption = #1057#1091#1090'. '#1087#1083#1072#1085#1099
      TabOrder = 3
      OnClick = btnDayPlanClick
    end
    object Splitter9: TSplitter
      Left = 650
      Top = 2
      Width = 10
      Height = 32
      Cursor = crHSplit
    end
    object btnWeekPlan: TBitBtn
      Left = 660
      Top = 2
      Width = 84
      Height = 32
      Caption = #1053#1077#1076'. '#1087#1083#1072#1085#1099
      TabOrder = 4
      OnClick = btnWeekPlanClick
    end
    object Splitter10: TSplitter
      Left = 744
      Top = 2
      Width = 10
      Height = 32
      Cursor = crHSplit
    end
    object btnYear: TBitBtn
      Left = 754
      Top = 2
      Width = 86
      Height = 32
      Caption = #1043#1086#1076'. '#1087#1083#1072#1085
      TabOrder = 5
      OnClick = btnYearClick
    end
    object Splitter13: TSplitter
      Left = 840
      Top = 2
      Width = 10
      Height = 32
      Cursor = crHSplit
    end
    object btn_BtDk: TBitBtn
      Left = 850
      Top = 2
      Width = 75
      Height = 32
      Caption = #1044#1050
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = btn_BtDkClick
    end
  end
  object MainMenu1: TMainMenu
    Left = 32
    Top = 136
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object on_NewFile: TMenuItem
        Caption = #1053#1086#1074#1099#1081
        OnClick = on_NewFileClick
      end
      object on_OpenFile: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1087#1088#1086#1077#1082#1090
        OnClick = on_OpenFileClick
      end
      object on_SaveFile: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1087#1088#1086#1077#1082#1090
        OnClick = on_SaveFileClick
      end
    end
    object N2: TMenuItem
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      object on_SetupPrg: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
        OnClick = on_SetupPrgClick
      end
      object on_Direct: TMenuItem
        Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1103
        OnClick = on_DirectClick
      end
      object UDZCG: TMenuItem
        Caption = #1059#1044#1047#1057#1043
        OnClick = UDZCGClick
      end
      object on_Safety: TMenuItem
        Caption = #1041#1077#1079#1086#1087#1072#1089#1085#1086#1089#1090#1100
        OnClick = on_SafetyClick
      end
      object on_TemplatePhase: TMenuItem
        Caption = #1064#1072#1073#1083#1086#1085#1099' '#1092#1072#1079
        OnClick = on_TemplatePhaseClick
      end
      object on_DSA_Plans: TMenuItem
        Caption = 'C'#1091#1090#1086#1095#1085#1099#1077' '#1087#1083#1072#1085#1099
        OnClick = on_DSA_PlansClick
      end
      object on_WeeklyPlans: TMenuItem
        Caption = #1053#1077#1076#1077#1083#1100#1085#1099#1077' '#1087#1083#1072#1085#1099
        OnClick = on_WeeklyPlansClick
      end
      object on_AnnualPlan: TMenuItem
        Caption = #1043#1086#1076#1086#1074#1086#1081' '#1087#1083#1072#1085
        OnClick = on_AnnualPlanClick
      end
      object on_Dk: TMenuItem
        Caption = #1044#1050
        OnClick = on_DkClick
      end
    end
    object N10: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object on_About: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = on_AboutClick
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 64
    Top = 136
  end
  object SaveDialog1: TSaveDialog
    Left = 96
    Top = 136
  end
  object IdUDPServer: TIdUDPServer
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 11990
      end>
    DefaultPort = 11990
    OnUDPRead = IdUDPServerUDPRead
    Left = 168
    Top = 128
  end
  object IdUDPClient: TIdUDPClient
    Port = 0
    Left = 200
    Top = 128
  end
end
