object FormGuard: TFormGuard
  Left = 481
  Top = 184
  BorderStyle = bsSingle
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1073#1077#1079#1086#1087#1072#1089#1085#1086#1089#1090#1080
  ClientHeight = 552
  ClientWidth = 646
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 511
    Width = 646
    Height = 41
    Align = alBottom
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object btnSave: TButton
      Left = 384
      Top = 8
      Width = 137
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = btnSaveClick
    end
    object btnClose: TButton
      Left = 536
      Top = 8
      Width = 91
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = btnCloseClick
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 646
    Height = 511
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabIndex = 0
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #1060#1083#1072#1075#1080' '#1084#1072#1090#1088#1080#1094#1099' '#1082#1086#1085#1092#1083#1080#1082#1090#1086#1074
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 638
        Height = 480
        Align = alClient
        TabOrder = 0
        OnDrawCell = StringGrid1DrawCell
        OnSelectCell = StringGrid1SelectCell
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1042#1088#1077#1084#1077#1085#1072' '#1084#1072#1090#1088#1080#1094#1099' '#1082#1086#1085#1092#1083#1080#1082#1090#1086#1074
      ImageIndex = 1
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 638
        Height = 480
        Align = alClient
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        TabOrder = 0
        OnDrawCell = StringGrid2DrawCell
        OnKeyPress = StringGrid2KeyPress
        OnSelectCell = StringGrid2SelectCell
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1042#1088#1077#1084#1103' '#1087#1088#1086#1084'.'
      ImageIndex = 2
      object Panel2: TPanel
        Left = 4
        Top = 8
        Width = 629
        Height = 425
        Align = alCustom
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object Label1: TLabel
          Left = 312
          Top = 200
          Width = 209
          Height = 16
          Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1072#1103' '#1076#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          Visible = False
        end
        object Label2: TLabel
          Left = 312
          Top = 216
          Width = 170
          Height = 16
          Caption = #1082#1088#1072#1089#1085#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072', '#1089#1077#1082'.'
          Visible = False
        end
        object Label3: TLabel
          Left = 312
          Top = 272
          Width = 163
          Height = 16
          Caption = #1078#1077#1083#1090#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072', '#1089#1077#1082'.'
          Visible = False
        end
        object Label6: TLabel
          Left = 696
          Top = 280
          Width = 105
          Height = 16
          Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
        end
        object Label7: TLabel
          Left = 696
          Top = 296
          Width = 173
          Height = 16
          Caption = #1079#1077#1083#1077#1085#1086#1075#1086'-'#1084#1080#1075#1072#1102#1097#1077#1075#1086', '#1089
        end
        object Label8: TLabel
          Left = 18
          Top = 13
          Width = 168
          Height = 16
          Caption = #1052#1080#1085'. '#1074#1088#1077#1084#1103' '#1092#1072#1079#1099', '#1084#1080#1085'.'
        end
        object Label18: TLabel
          Left = 16
          Top = 205
          Width = 191
          Height = 16
          Caption = #1088#1091#1095#1085#1086#1075#1086' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103' '#1084#1080#1085'.'
        end
        object Label19: TLabel
          Left = 312
          Top = 318
          Width = 232
          Height = 16
          Caption = #1048#1085#1090#1077#1088#1074#1072#1083' '#1086#1095#1080#1089#1090#1082#1080' '#1087#1086#1083#1086#1089#1099' '#1084#1080#1085'.'
          Visible = False
        end
        object Label4: TLabel
          Left = 312
          Top = 256
          Width = 209
          Height = 16
          Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1072#1103' '#1076#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
          Visible = False
        end
        object Label5: TLabel
          Left = 16
          Top = 189
          Width = 216
          Height = 16
          Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1076#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
        end
        object lbl1: TLabel
          Left = 355
          Top = 13
          Width = 192
          Height = 16
          Caption = #1047#1072#1087#1086#1083#1085#1077#1085#1080#1077' '#1087#1088#1086#1084'. '#1090#1072#1082#1090#1086#1074
        end
        object lbl2: TLabel
          Left = 16
          Top = 74
          Width = 216
          Height = 16
          Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1076#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
        end
        object lbl3: TLabel
          Left = 17
          Top = 90
          Width = 112
          Height = 16
          Caption = #1088#1077#1078#1080#1084#1072' '#1050#1050' '#1089#1077#1082'.'
        end
        object bvl1: TBevel
          Left = 260
          Top = 20
          Width = 3
          Height = 380
        end
        object bvl2: TBevel
          Left = 8
          Top = 180
          Width = 241
          Height = 3
        end
        object edtMinRed: TEdit
          Left = 312
          Top = 232
          Width = 121
          Height = 24
          BevelInner = bvNone
          TabOrder = 0
          Text = '2'
          Visible = False
        end
        object edtMinYellow: TEdit
          Left = 312
          Top = 290
          Width = 121
          Height = 24
          TabOrder = 1
          Text = '3'
          Visible = False
        end
        object Edit4: TEdit
          Left = 696
          Top = 320
          Width = 121
          Height = 24
          TabOrder = 2
          Text = '3'
        end
        object edtMinGreen: TEdit
          Left = 40
          Top = 36
          Width = 121
          Height = 24
          TabOrder = 3
          Text = '5'
        end
        object edtTimeClear: TEdit
          Left = 312
          Top = 342
          Width = 121
          Height = 24
          TabOrder = 4
          Text = '5'
          Visible = False
        end
        object cbbFilling: TComboBox
          Left = 395
          Top = 36
          Width = 100
          Height = 24
          ItemHeight = 16
          ItemIndex = 0
          TabOrder = 5
          Text = #1050#1088#1072#1089#1085#1099#1081
          Items.Strings = (
            #1050#1088#1072#1089#1085#1099#1081
            #1047#1077#1083#1077#1085#1099#1081)
        end
        object pnl1: TPanel
          Left = 288
          Top = 72
          Width = 329
          Height = 113
          BevelOuter = bvSpace
          BiDiMode = bdLeftToRight
          ParentBiDiMode = False
          TabOrder = 6
          object lbl4: TLabel
            Left = 35
            Top = 5
            Width = 242
            Height = 16
            Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1087#1088#1086#1084'. '#1090#1072#1082#1090#1072' ('#1084#1080#1085'.)'
          end
          object lbl5: TLabel
            Left = 96
            Top = 55
            Width = 120
            Height = 16
            Caption = #1058#1080#1087' '#1087#1088#1086#1084'. '#1090#1072#1082#1090#1072
          end
          object edtDelayTP: TEdit
            Left = 106
            Top = 26
            Width = 100
            Height = 24
            TabOrder = 0
            Text = '3'
          end
          object cbbTypeTP: TComboBox
            Left = 106
            Top = 76
            Width = 100
            Height = 24
            ItemHeight = 16
            TabOrder = 1
            Text = #1046
            Items.Strings = (
              #1046'\'#1047
              #1046)
          end
        end
        object edtKK: TEdit
          Left = 40
          Top = 121
          Width = 121
          Height = 24
          TabOrder = 7
          Text = '1'
        end
        object edtTimeStDelayVPU: TCSpinEdit
          Left = 40
          Top = 240
          Width = 121
          Height = 26
          MaxValue = 1440
          TabOrder = 8
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1040#1074#1072#1088#1080#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ImageIndex = 3
      ParentFont = False
      object Label13: TLabel
        Left = 16
        Top = 32
        Width = 242
        Height = 20
        Caption = #1048#1085#1090#1077#1088#1074#1072#1083' '#1087#1077#1088#1077#1079#1072#1087#1091#1089#1082#1072' '#1044#1050', '#1089
      end
      object Label16: TLabel
        Left = 16
        Top = 104
        Width = 245
        Height = 20
        Caption = #1050#1086#1083'-'#1074#1086' '#1087#1086#1087#1099#1090#1086#1082' '#1087#1077#1088#1077#1079#1072#1087#1091#1089#1082#1072
      end
      object Label17: TLabel
        Left = 16
        Top = 184
        Width = 253
        Height = 20
        Caption = #1042#1088#1077#1084#1103' '#1086#1095#1080#1089#1090#1082#1080' '#1072#1074#1072#1088#1080#1081', '#1084#1080#1085#1091#1090
      end
      object Edit8: TEdit
        Left = 16
        Top = 56
        Width = 121
        Height = 28
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        Text = '3'
      end
      object Edit9: TEdit
        Left = 16
        Top = 136
        Width = 121
        Height = 28
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        Text = '5'
      end
      object Edit10: TEdit
        Left = 16
        Top = 216
        Width = 121
        Height = 28
        TabOrder = 2
        Text = '1'
      end
    end
  end
end
