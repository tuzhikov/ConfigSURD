object FormProject: TFormProject
  Left = 581
  Top = 216
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 450
  ClientWidth = 415
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 415
    Height = 409
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1054#1073#1097#1080#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      object Memo1: TMemo
        Left = 0
        Top = 89
        Width = 407
        Height = 289
        Align = alClient
        Lines.Strings = (
          #1054#1087#1080#1089#1072#1085#1080#1077' '#1087#1088#1086#1077#1082#1090#1072)
        MaxLength = 128
        TabOrder = 0
      end
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 407
        Height = 89
        Align = alTop
        BiDiMode = bdLeftToRight
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1044#1050' '#1074' '#1057#1059#1056#1044
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentBiDiMode = False
        ParentFont = False
        TabOrder = 1
        object Label1: TLabel
          Left = 120
          Top = 24
          Width = 55
          Height = 16
          Caption = #1044#1050' '#1084#1072#1082'.'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object ComboBoxDK: TComboBox
          Left = 185
          Top = 20
          Width = 65
          Height = 24
          ItemHeight = 16
          ItemIndex = 0
          TabOrder = 0
          Text = '1'
          OnChange = ComboBoxDKChange
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
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1057#1074#1103#1079#1100
      ImageIndex = 1
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 407
        Height = 105
        Align = alTop
        TabOrder = 0
        object grp1: TGroupBox
          Left = 7
          Top = 0
          Width = 393
          Height = 97
          TabOrder = 0
          object lbl2: TLabel
            Left = 9
            Top = 24
            Width = 100
            Height = 16
            Caption = #1058#1072#1081#1084'-'#1072#1091#1090', '#1084#1089':'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object lbl3: TLabel
            Left = 9
            Top = 63
            Width = 94
            Height = 16
            Caption = #1055#1086#1074#1090#1086#1088' '#1082#1086#1083'.:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object lblPORT: TLabel
            Left = 245
            Top = 24
            Width = 42
            Height = 16
            Caption = #1055#1086#1088#1090':'
          end
          object lblPass: TLabel
            Left = 236
            Top = 63
            Width = 60
            Height = 16
            Caption = #1055#1072#1088#1086#1083#1100':'
          end
          object edtTimeSt: TCSpinEdit
            Left = 116
            Top = 19
            Width = 70
            Height = 26
            MaxValue = 900
            MinValue = 10
            TabOrder = 0
            Value = 100
          end
          object edtTimeCN: TCSpinEdit
            Left = 116
            Top = 58
            Width = 70
            Height = 26
            MaxValue = 10
            MinValue = 1
            TabOrder = 1
            Value = 5
          end
          object EditPort: TEdit
            Left = 301
            Top = 20
            Width = 75
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            MaxLength = 5
            ParentFont = False
            TabOrder = 2
            Text = '11990'
          end
          object medtPass: TMaskEdit
            Left = 301
            Top = 59
            Width = 75
            Height = 24
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            MaxLength = 6
            ParentFont = False
            TabOrder = 3
            Text = '999999'
          end
        end
      end
      object StringGridDK: TStringGrid
        Left = 0
        Top = 105
        Width = 407
        Height = 273
        Align = alClient
        ColCount = 3
        DefaultColWidth = 50
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        TabOrder = 1
        ColWidths = (
          50
          127
          50)
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1046#1091#1088#1085#1072#1083
      ImageIndex = 2
      object GroupBox3: TGroupBox
        Left = 0
        Top = 0
        Width = 407
        Height = 378
        Align = alClient
        Caption = #1048#1089#1090#1086#1095#1085#1080#1082#1080' '#1079#1072#1087#1080#1089#1077#1081' '#1074' '#1078#1091#1088#1085#1072#1083
        TabOrder = 0
        object CheckBox1: TCheckBox
          Left = 16
          Top = 24
          Width = 273
          Height = 18
          Caption = #1042#1082#1083#1102#1095#1077#1085#1080#1077' '#1087#1080#1090#1072#1085#1080#1103
          TabOrder = 0
        end
        object CheckBox2: TCheckBox
          Left = 16
          Top = 93
          Width = 273
          Height = 17
          Caption = #1042#1099#1082#1083#1102#1095#1077#1085#1080#1077' '#1087#1080#1090#1072#1085#1080#1103
          TabOrder = 1
        end
        object CheckBox5: TCheckBox
          Left = 16
          Top = 47
          Width = 273
          Height = 17
          Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1060#1040#1047
          TabOrder = 2
        end
        object CheckBox6: TCheckBox
          Left = 16
          Top = 69
          Width = 273
          Height = 17
          Caption = #1040#1074#1072#1088#1080#1080
          TabOrder = 3
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'GPS'
      ImageIndex = 3
      object Label2: TLabel
        Left = 80
        Top = 24
        Width = 208
        Height = 16
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1089#1076#1074#1080#1075#1072' '#1074#1088#1077#1084#1077#1085#1080' '
      end
      object Label3: TLabel
        Left = 72
        Top = 120
        Width = 90
        Height = 37
        Caption = 'UTC+'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -32
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object bvl1: TBevel
        Left = 0
        Top = 195
        Width = 404
        Height = 3
      end
      object TrackBar1: TTrackBar
        Left = 24
        Top = 56
        Width = 329
        Height = 45
        Max = 12
        Min = -12
        Orientation = trHorizontal
        Frequency = 1
        Position = 4
        SelEnd = 0
        SelStart = 0
        TabOrder = 0
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = TrackBar1Change
      end
      object Panel2: TPanel
        Left = 184
        Top = 112
        Width = 145
        Height = 57
        Caption = 'Panel2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
      end
      object chkGPS: TCheckBox
        Left = 61
        Top = 231
        Width = 286
        Height = 17
        Caption = #1042#1082#1083#1102#1095#1080#1090#1100' '#1088#1077#1078#1080' '#1054#1057' '#1073#1077#1079' GPS '#1076#1072#1085#1085#1099#1093
        Checked = True
        ParentShowHint = False
        ShowHint = False
        State = cbChecked
        TabOrder = 2
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 409
    Width = 415
    Height = 41
    Align = alBottom
    TabOrder = 1
    object Button1: TButton
      Left = 159
      Top = 8
      Width = 115
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
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
      Left = 287
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
      OnClick = Button2Click
    end
  end
end
