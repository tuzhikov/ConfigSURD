object FormUDZG: TFormUDZG
  Left = 299
  Top = 160
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = #1059#1044#1047#1057#1043
  ClientHeight = 416
  ClientWidth = 847
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object bvlTop: TBevel
    Left = 0
    Top = 0
    Width = 847
    Height = 96
    Align = alTop
  end
  object lblText: TLabel
    Left = 194
    Top = 7
    Width = 459
    Height = 24
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1083#1086#1075#1080#1095#1077#1089#1082#1086#1075#1086' '#1074#1099#1074#1086#1076#1072' '#1059#1044#1047#1057#1043'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object btnPlus: TSpeedButton
    Left = 722
    Top = 34
    Width = 60
    Height = 60
    Caption = '+'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -35
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = btnPlusClick
  end
  object btnMinus: TSpeedButton
    Left = 784
    Top = 34
    Width = 60
    Height = 60
    Caption = '-'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -35
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = btnMinusClick
  end
  object lblrv: TLabel
    Left = 144
    Top = 40
    Width = 21
    Height = 48
    Caption = '='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -43
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object cbbOpr1: TComboBox
    Left = 309
    Top = 54
    Width = 65
    Height = 21
    BevelKind = bkTile
    Style = csDropDownList
    Color = clHighlightText
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
  end
  object cbbOpr2: TComboBox
    Left = 514
    Top = 54
    Width = 65
    Height = 21
    BevelKind = bkTile
    Style = csDropDownList
    Color = clHighlightText
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 1
  end
  object pnlbut: TPanel
    Left = 0
    Top = 360
    Width = 847
    Height = 56
    Align = alBottom
    Color = clMoneyGreen
    TabOrder = 2
    object btnOk: TButton
      Left = 12
      Top = 9
      Width = 100
      Height = 40
      Caption = #1057#1054#1061#1056#1040#1053#1048#1058#1068
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = btnokClick
    end
    object btnExit: TButton
      Left = 118
      Top = 9
      Width = 100
      Height = 40
      Caption = #1042#1067#1061#1054#1044
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = btnExitClick
    end
  end
  object lstOut: TListBox
    Left = 0
    Top = 96
    Width = 847
    Height = 264
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 24
    ParentFont = False
    TabOrder = 3
    OnClick = lstOutClick
  end
  object pnlresult: TPanel
    Left = 3
    Top = 34
    Width = 140
    Height = 60
    Color = clMoneyGreen
    TabOrder = 4
    object cbbResultSign: TComboBox
      Left = 95
      Top = 22
      Width = 40
      Height = 24
      BevelKind = bkTile
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ParentFont = False
      TabOrder = 0
      OnChange = cbColorChange
    end
    object cbbResult: TComboBox
      Left = 5
      Top = 22
      Width = 90
      Height = 24
      BevelKind = bkTile
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ItemIndex = 0
      ParentFont = False
      TabOrder = 1
      Text = '64 '#1059#1044#1047#1057#1043
      Items.Strings = (
        '64 '#1059#1044#1047#1057#1043
        #1057#1057#1043'2'
        #1057#1057#1043'3'
        #1059#1044#1047#1057#1043'1'
        #1059#1044#1047#1057#1043'2'
        #1059#1044#1047#1057#1043'3')
    end
    object chkResultInv: TCheckBox
      Left = 20
      Top = 5
      Width = 97
      Height = 17
      Caption = #1048#1085#1074#1077#1088#1089#1080#1103
      TabOrder = 2
    end
  end
  object pnl1: TPanel
    Left = 373
    Top = 34
    Width = 140
    Height = 60
    Color = clMoneyGreen
    TabOrder = 5
    object cbbBS: TComboBox
      Left = 95
      Top = 22
      Width = 40
      Height = 24
      BevelKind = bkTile
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = #1050
      OnChange = cbColorChange
      Items.Strings = (
        #1050
        #1046
        #1047
        #1060
        #1055
        #1053
        '1'
        '0')
    end
    object cbbB: TComboBox
      Left = 5
      Top = 22
      Width = 90
      Height = 24
      BevelKind = bkTile
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ItemIndex = 0
      ParentFont = False
      TabOrder = 1
      Text = #1057#1057#1043'1'
      OnChange = lstOutChange
      Items.Strings = (
        #1057#1057#1043'1'
        #1057#1057#1043'2'
        #1057#1057#1043'3'
        #1059#1044#1047#1057#1043'1'
        #1059#1044#1047#1057#1043'2'
        #1059#1044#1047#1057#1043'3')
    end
    object chkBInv: TCheckBox
      Left = 20
      Top = 5
      Width = 97
      Height = 17
      Caption = #1048#1085#1074#1077#1088#1089#1080#1103
      TabOrder = 2
    end
  end
  object Panel1: TPanel
    Left = 167
    Top = 34
    Width = 140
    Height = 60
    Color = clMoneyGreen
    TabOrder = 6
    object cbbAS: TComboBox
      Left = 94
      Top = 22
      Width = 40
      Height = 24
      BevelKind = bkTile
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = #1050
      OnChange = cbColorChange
      Items.Strings = (
        #1050
        #1046
        #1047
        #1060
        #1055
        #1053
        '1'
        '0')
    end
    object cbbA: TComboBox
      Left = 4
      Top = 22
      Width = 90
      Height = 24
      BevelKind = bkTile
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ItemIndex = 0
      ParentFont = False
      TabOrder = 1
      Text = #1057#1057#1043'1'
      OnChange = lstOutChange
      Items.Strings = (
        #1057#1057#1043'1'
        #1057#1057#1043'2'
        #1057#1057#1043'3'
        #1059#1044#1047#1057#1043'1'
        #1059#1044#1047#1057#1043'2'
        #1059#1044#1047#1057#1043'3')
    end
    object chkAInv: TCheckBox
      Left = 24
      Top = 5
      Width = 97
      Height = 17
      Caption = #1048#1085#1074#1077#1088#1089#1080#1103
      TabOrder = 2
    end
  end
  object Panel2: TPanel
    Left = 578
    Top = 34
    Width = 140
    Height = 60
    Color = clMoneyGreen
    TabOrder = 7
    object cbbCS: TComboBox
      Left = 95
      Top = 21
      Width = 40
      Height = 24
      BevelKind = bkTile
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = #1050
      OnChange = cbColorChange
      Items.Strings = (
        #1050
        #1046
        #1047
        #1060
        #1055
        #1053
        '1'
        '0')
    end
    object cbbC: TComboBox
      Left = 5
      Top = 21
      Width = 90
      Height = 24
      BevelKind = bkTile
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 16
      ItemIndex = 0
      ParentFont = False
      TabOrder = 1
      Text = #1057#1057#1043'1'
      OnChange = lstOutChange
      Items.Strings = (
        #1057#1057#1043'1'
        #1057#1057#1043'2'
        #1057#1057#1043'3'
        #1059#1044#1047#1057#1043'1'
        #1059#1044#1047#1057#1043'2'
        #1059#1044#1047#1057#1043'3')
    end
    object chkCInv: TCheckBox
      Left = 28
      Top = 4
      Width = 97
      Height = 17
      Caption = #1048#1085#1074#1077#1088#1089#1080#1103
      TabOrder = 2
    end
  end
end
