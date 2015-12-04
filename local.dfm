object Form6: TForm6
  Left = 298
  Top = 148
  Width = 672
  Height = 533
  Caption = #1055#1088#1080#1074#1103#1079#1082#1072' '#1089#1080#1083#1086#1074#1099#1093' '#1074#1099#1093#1086#1076#1086#1074
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
  object Label7: TLabel
    Left = 240
    Top = 8
    Width = 32
    Height = 13
    Caption = 'Label7'
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 664
    Height = 465
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1057#1080#1083#1086#1074#1099#1077' '#1074#1099#1093#1086#1076#1099
      object ListBox1: TListBox
        Left = 0
        Top = 49
        Width = 153
        Height = 381
        Hint = #1057#1087#1080#1089#1086#1082' '#1089#1074#1077#1090#1086#1092#1086#1088#1085#1099#1093' '#1086#1073#1098#1077#1082#1090#1086#1074
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -32
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 37
        Items.Strings = (
          '')
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = ListBox1Click
      end
      object Panel2: TPanel
        Left = 153
        Top = 49
        Width = 503
        Height = 381
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object Label1: TLabel
          Left = 96
          Top = 8
          Width = 86
          Height = 24
          Caption = #1050#1088#1072#1089#1085#1099#1081
          Color = clBtnFace
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
        object Label2: TLabel
          Left = 280
          Top = 48
          Width = 5
          Height = 16
        end
        object Label3: TLabel
          Left = 96
          Top = 136
          Width = 78
          Height = 24
          Caption = #1046#1077#1083#1090#1099#1081
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clYellow
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label5: TLabel
          Left = 96
          Top = 256
          Width = 88
          Height = 24
          Caption = #1047#1077#1083#1077#1085#1099#1081
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label6: TLabel
          Left = 280
          Top = 296
          Width = 102
          Height = 16
          Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
        end
        object Label9: TLabel
          Left = 280
          Top = 48
          Width = 102
          Height = 16
          Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
        end
        object Label4: TLabel
          Left = 280
          Top = 184
          Width = 102
          Height = 16
          Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
        end
        object Label10: TLabel
          Left = 288
          Top = 96
          Width = 49
          Height = 16
          Caption = '"'#1062#1074#1077#1090'"'
        end
        object Label11: TLabel
          Left = 280
          Top = 224
          Width = 49
          Height = 16
          Caption = '"'#1062#1074#1077#1090'"'
        end
        object Label12: TLabel
          Left = 280
          Top = 336
          Width = 49
          Height = 16
          Caption = '"'#1062#1074#1077#1090'"'
        end
        object ComboBox1: TComboBox
          Left = 16
          Top = 40
          Width = 257
          Height = 32
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 24
          ItemIndex = 0
          ParentFont = False
          TabOrder = 0
          Text = '1'
          OnChange = ComboBox1Change
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
        end
        object ComboBox2: TComboBox
          Left = 16
          Top = 88
          Width = 257
          Height = 32
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 24
          ItemIndex = 0
          ParentFont = False
          TabOrder = 1
          Text = '1'
          OnChange = ComboBox2Change
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
        end
        object ComboBox3: TComboBox
          Left = 16
          Top = 176
          Width = 257
          Height = 32
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 24
          ItemIndex = 0
          ParentFont = False
          TabOrder = 2
          Text = '1'
          OnChange = ComboBox3Change
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
        end
        object ComboBox4: TComboBox
          Left = 16
          Top = 216
          Width = 257
          Height = 32
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 24
          ItemIndex = 0
          ParentFont = False
          TabOrder = 3
          Text = '1'
          OnChange = ComboBox4Change
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
        end
        object ComboBox5: TComboBox
          Left = 24
          Top = 288
          Width = 249
          Height = 32
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 24
          ItemIndex = 0
          ParentFont = False
          TabOrder = 4
          Text = '1'
          OnChange = ComboBox5Change
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
        end
        object ComboBox6: TComboBox
          Left = 24
          Top = 328
          Width = 249
          Height = 32
          Style = csDropDownList
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 24
          ItemIndex = 0
          ParentFont = False
          TabOrder = 5
          Text = '1'
          OnChange = ComboBox6Change
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
        end
      end
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 656
        Height = 49
        Align = alTop
        TabOrder = 2
        object Panel6: TPanel
          Left = 1
          Top = 1
          Width = 152
          Height = 47
          Align = alLeft
          Caption = #1043#1088#1091#1087#1087#1099
          TabOrder = 0
        end
        object Panel8: TPanel
          Left = 153
          Top = 1
          Width = 502
          Height = 47
          Align = alClient
          Caption = #1042#1099#1093#1086#1076#1099' '#1075#1088#1091#1087#1087#1099
          TabOrder = 1
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1058#1088#1072#1084#1074#1072#1081#1085#1099#1077' '#1089#1074#1077#1090#1086#1092#1086#1088#1099
      ImageIndex = 1
      object Panel3: TPanel
        Left = 160
        Top = 48
        Width = 489
        Height = 353
        TabOrder = 0
        object Shape3: TShape
          Left = 136
          Top = 144
          Width = 81
          Height = 73
          Shape = stCircle
        end
        object Label13: TLabel
          Left = 104
          Top = 8
          Width = 56
          Height = 20
          Caption = #1051#1077#1074#1099#1081
        end
        object Label14: TLabel
          Left = 328
          Top = 8
          Width = 66
          Height = 20
          Caption = #1055#1088#1072#1074#1099#1081
        end
        object Label15: TLabel
          Left = 184
          Top = 72
          Width = 117
          Height = 20
          Caption = #1062#1077#1085#1090#1088#1072#1083#1100#1085#1099#1081
        end
        object Shape1: TShape
          Left = 216
          Top = 144
          Width = 81
          Height = 73
          Shape = stCircle
        end
        object Shape2: TShape
          Left = 296
          Top = 144
          Width = 81
          Height = 73
          Shape = stCircle
        end
        object Shape4: TShape
          Left = 216
          Top = 224
          Width = 81
          Height = 73
          Shape = stCircle
        end
        object Label8: TLabel
          Left = 24
          Top = 320
          Width = 422
          Height = 20
          Caption = #1055#1088#1080#1074#1103#1079#1082#1072' '#1090#1088#1072#1084#1074#1072#1081#1085#1099#1093' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1081'  '#1082' '#1089#1074#1077#1090#1086#1092#1086#1088#1091
        end
        object ComboBox7: TComboBox
          Left = 21
          Top = 30
          Width = 236
          Height = 28
          Style = csDropDownList
          ItemHeight = 20
          TabOrder = 0
          OnChange = ComboBox7Change
        end
        object ComboBox8: TComboBox
          Left = 149
          Top = 94
          Width = 188
          Height = 28
          Style = csDropDownList
          ItemHeight = 20
          TabOrder = 1
          OnChange = ComboBox8Change
        end
        object ComboBox9: TComboBox
          Left = 269
          Top = 30
          Width = 204
          Height = 28
          Style = csDropDownList
          ItemHeight = 20
          TabOrder = 2
          OnChange = ComboBox9Change
        end
      end
      object ListBox2: TListBox
        Left = 0
        Top = 33
        Width = 153
        Height = 397
        Align = alLeft
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -32
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 37
        ParentFont = False
        TabOrder = 1
        OnClick = ListBox2Click
      end
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 656
        Height = 33
        Align = alTop
        TabOrder = 2
        object Panel7: TPanel
          Left = 1
          Top = 1
          Width = 152
          Height = 31
          Align = alLeft
          Caption = #1057#1074#1077#1090#1086#1092#1086#1088#1099
          TabOrder = 0
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 465
    Width = 664
    Height = 41
    Align = alBottom
    TabOrder = 1
    object Button1: TButton
      Left = 456
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
      Left = 576
      Top = 8
      Width = 75
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1072
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
end
