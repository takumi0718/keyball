# QMK MIDI キーコード一覧

このファイルは、QMK の MIDI 機能で使える主要キーコードを `my_midi` 向けに整理した参照メモです。

この keymap では、すでに以下が有効です。

- `rules.mk`: `MIDI_ENABLE = yes`
- `config.h`: `#define MIDI_ADVANCED`

## 1. 前提

QMK の MIDI 機能は、キー入力から MIDI ノートや各種コントロールを送るための機能です。

- 基本有効化: `MIDI_ENABLE = yes`
- 拡張機能有効化: `#define MIDI_ADVANCED`

`MIDI_ADVANCED` を有効にすると、オクターブ変更、トランスポーズ、ベロシティ変更、チャンネル変更などのキーコードが使えます。

## 2. 基本制御キーコード

| キーコード | 説明 |
| --- | --- |
| `MI_ON` | MIDI 機能を有効化する |
| `MI_OFF` | MIDI 機能を無効化する |
| `MI_TOGG` | MIDI 機能の ON/OFF をトグルする |
| `MI_AOFF` | 発音中の全ノートを停止する |

## 3. ノート入力キーコード

### 命名規則

ノート系キーコードは、音名とオクターブ番号の組み合わせで表現されます。

- オクターブ 0:
  `MI_C`, `MI_Cs`, `MI_Db`, `MI_D`, `MI_Ds`, `MI_Eb`, `MI_E`, `MI_F`, `MI_Fs`, `MI_Gb`, `MI_G`, `MI_Gs`, `MI_Ab`, `MI_A`, `MI_As`, `MI_Bb`, `MI_B`
- オクターブ 1 以降:
  末尾に数字が付きます。
  例: `MI_C1`, `MI_D1`, `MI_Fs3`, `MI_B4`, `MI_C5`

シャープとフラットには同義エイリアスがあります。

- `MI_Cs` = `MI_Db`
- `MI_Ds` = `MI_Eb`
- `MI_Fs` = `MI_Gb`
- `MI_Gs` = `MI_Ab`
- `MI_As` = `MI_Bb`

### 音名ごとの対応

| 音名 | 主なキーコード | 同義エイリアス |
| --- | --- | --- |
| C | `MI_C`, `MI_C1`, `MI_C2`, `MI_C3`, `MI_C4`, `MI_C5` | なし |
| C# / Db | `MI_Cs`, `MI_Cs1`, `MI_Cs2`, `MI_Cs3`, `MI_Cs4`, `MI_Cs5` | `MI_Db`, `MI_Db1`, `MI_Db2`, `MI_Db3`, `MI_Db4`, `MI_Db5` |
| D | `MI_D`, `MI_D1`, `MI_D2`, `MI_D3`, `MI_D4`, `MI_D5` | なし |
| D# / Eb | `MI_Ds`, `MI_Ds1`, `MI_Ds2`, `MI_Ds3`, `MI_Ds4`, `MI_Ds5` | `MI_Eb`, `MI_Eb1`, `MI_Eb2`, `MI_Eb3`, `MI_Eb4`, `MI_Eb5` |
| E | `MI_E`, `MI_E1`, `MI_E2`, `MI_E3`, `MI_E4`, `MI_E5` | なし |
| F | `MI_F`, `MI_F1`, `MI_F2`, `MI_F3`, `MI_F4`, `MI_F5` | なし |
| F# / Gb | `MI_Fs`, `MI_Fs1`, `MI_Fs2`, `MI_Fs3`, `MI_Fs4`, `MI_Fs5` | `MI_Gb`, `MI_Gb1`, `MI_Gb2`, `MI_Gb3`, `MI_Gb4`, `MI_Gb5` |
| G | `MI_G`, `MI_G1`, `MI_G2`, `MI_G3`, `MI_G4`, `MI_G5` | なし |
| G# / Ab | `MI_Gs`, `MI_Gs1`, `MI_Gs2`, `MI_Gs3`, `MI_Gs4`, `MI_Gs5` | `MI_Ab`, `MI_Ab1`, `MI_Ab2`, `MI_Ab3`, `MI_Ab4`, `MI_Ab5` |
| A | `MI_A`, `MI_A1`, `MI_A2`, `MI_A3`, `MI_A4`, `MI_A5` | なし |
| A# / Bb | `MI_As`, `MI_As1`, `MI_As2`, `MI_As3`, `MI_As4`, `MI_As5` | `MI_Bb`, `MI_Bb1`, `MI_Bb2`, `MI_Bb3`, `MI_Bb4`, `MI_Bb5` |
| B | `MI_B`, `MI_B1`, `MI_B2`, `MI_B3`, `MI_B4`, `MI_B5` | なし |

注記:

- `Context7` で確認できた範囲では、オクターブ 0 から 5 のノートキーコードが取得できました。
- 実際の配置は [keymap.c](/Users/yoshidatakumi/workspace/github.com/takumi0718/keyball/qmk_firmware/keyboards/keyball/keyball44/keymaps/my_midi/keymap.c) にある MIDI レイヤーも参照してください。

## 4. オクターブ制御キーコード

| キーコード | 説明 |
| --- | --- |
| `MI_OCN2` | オクターブを `-2` に設定 |
| `MI_OCN1` | オクターブを `-1` に設定 |
| `MI_OC0` | オクターブを `0` に設定 |
| `MI_OC1` | オクターブを `1` に設定 |
| `MI_OC2` | オクターブを `2` に設定 |
| `MI_OC3` | オクターブを `3` に設定 |
| `MI_OC4` | オクターブを `4` に設定 |
| `MI_OC5` | オクターブを `5` に設定 |
| `MI_OC6` | オクターブを `6` に設定 |
| `MI_OC7` | オクターブを `7` に設定 |
| `MI_OCTD` | オクターブを 1 つ下げる |
| `MI_OCTU` | オクターブを 1 つ上げる |

## 5. トランスポーズ制御キーコード

| キーコード | 説明 |
| --- | --- |
| `MI_TRN6` | 半音 `-6` に設定 |
| `MI_TRN5` | 半音 `-5` に設定 |
| `MI_TRN4` | 半音 `-4` に設定 |
| `MI_TRN3` | 半音 `-3` に設定 |
| `MI_TRN2` | 半音 `-2` に設定 |
| `MI_TRN1` | 半音 `-1` に設定 |
| `MI_TR0` | 半音 `0` に設定 |
| `MI_TR1` | 半音 `+1` に設定 |
| `MI_TR2` | 半音 `+2` に設定 |
| `MI_TR3` | 半音 `+3` に設定 |
| `MI_TR4` | 半音 `+4` に設定 |
| `MI_TR5` | 半音 `+5` に設定 |
| `MI_TR6` | 半音 `+6` に設定 |
| `MI_TRSD` | 半音を 1 つ下げる |
| `MI_TRSU` | 半音を 1 つ上げる |

## 6. ベロシティ制御キーコード

ベロシティは打鍵の強さに相当し、音量や音色変化に影響します。

| キーコード | 説明 |
| --- | --- |
| `MI_VL0` | ベロシティプリセット 0 |
| `MI_VL1` | ベロシティプリセット 1 |
| `MI_VL2` | ベロシティプリセット 2 |
| `MI_VL3` | ベロシティプリセット 3 |
| `MI_VL4` | ベロシティプリセット 4 |
| `MI_VL5` | ベロシティプリセット 5 |
| `MI_VL6` | ベロシティプリセット 6 |
| `MI_VL7` | ベロシティプリセット 7 |
| `MI_VL8` | ベロシティプリセット 8 |
| `MI_VL9` | ベロシティを `114` に設定 |
| `MI_VL10` | ベロシティを `127` に設定 |
| `MI_VELD` | ベロシティを下げる |
| `MI_VELU` | ベロシティを上げる |

注記:

- `MI_VL9` と `MI_VL10` の具体値は QMK ドキュメントで確認できました。
- `MI_VL0` から `MI_VL8` は段階プリセットとして documented されています。

## 7. チャンネル制御キーコード

| キーコード | 説明 |
| --- | --- |
| `MI_CH1` | MIDI チャンネル 1 に設定 |
| `MI_CH2` | MIDI チャンネル 2 に設定 |
| `MI_CH3` | MIDI チャンネル 3 に設定 |
| `MI_CH4` | MIDI チャンネル 4 に設定 |
| `MI_CH5` | MIDI チャンネル 5 に設定 |
| `MI_CH6` | MIDI チャンネル 6 に設定 |
| `MI_CH7` | MIDI チャンネル 7 に設定 |
| `MI_CH8` | MIDI チャンネル 8 に設定 |
| `MI_CH9` | MIDI チャンネル 9 に設定 |
| `MI_CH10` | MIDI チャンネル 10 に設定 |
| `MI_CH11` | MIDI チャンネル 11 に設定 |
| `MI_CH12` | MIDI チャンネル 12 に設定 |
| `MI_CH13` | MIDI チャンネル 13 に設定 |
| `MI_CH14` | MIDI チャンネル 14 に設定 |
| `MI_CH15` | MIDI チャンネル 15 に設定 |
| `MI_CH16` | MIDI チャンネル 16 に設定 |
| `MI_CHND` | チャンネルを 1 つ下げる |
| `MI_CHNU` | チャンネルを 1 つ上げる |

## 8. 演奏表現系キーコード

| キーコード | 説明 |
| --- | --- |
| `MI_SUST` | サステイン |
| `MI_PORT` | ポルタメント |
| `MI_SOST` | ソステヌート |
| `MI_SOFT` | ソフトペダル |
| `MI_LEG` | レガート |
| `MI_MOD` | モジュレーション |
| `MI_MODD` | モジュレーション速度を下げる |
| `MI_MODU` | モジュレーション速度を上げる |
| `MI_BNDD` | ピッチベンドを下げる |
| `MI_BNDU` | ピッチベンドを上げる |

## 9. DTM で役に立つキーコード表

DAW やソフトシンセの操作で特に有用なものをまとめると以下です。

| 用途 | おすすめキーコード | 役に立つ理由 |
| --- | --- | --- |
| 演奏の基本 | `MI_C` から `MI_B5` | ピアノロール入力やライブ入力の中心になる |
| 音域の切り替え | `MI_OCTD`, `MI_OCTU` | 同じ配列のままベース帯域とリード帯域を行き来できる |
| 基準音域の固定 | `MI_OC0` から `MI_OC7` | 曲ごとに狙った音域へ即座に戻せる |
| 移調 | `MI_TRSD`, `MI_TRSU` | フレーズ形を保ったままキー変更できる |
| 固定移調 | `MI_TRN2`, `MI_TRN3`, `MI_TRN5` など | 特定キー向けの専用レイアウトを作りやすい |
| 強弱の調整 | `MI_VELD`, `MI_VELU` | 打ち込み前提でもニュアンスを即変更できる |
| 強めの固定打鍵 | `MI_VL8`, `MI_VL9`, `MI_VL10` | ドラム入力やアタックを強く出したい場面に向く |
| 音源切り替え | `MI_CH1` から `MI_CH16` | 1 台のキーボードで複数トラックや音源を切り替えられる |
| サステイン操作 | `MI_SUST` | ピアノ系、パッド系、ストリングスで特に有効 |
| ピッチ表現 | `MI_BNDD`, `MI_BNDU` | シンセリードやベースの表現に向く |
| 揺れの付加 | `MI_MOD`, `MI_MODD`, `MI_MODU` | ビブラートやフィルター変化を手元で作れる |
| 緊急停止 | `MI_AOFF` | ノートが張り付き続けたときの保険になる |
| MIDI 有効化管理 | `MI_ON`, `MI_OFF`, `MI_TOGG` | 通常レイヤーと MIDI レイヤーを安全に共存しやすい |

## 10. `my_midi` での実用メモ

現在の [keymap.c](/Users/yoshidatakumi/workspace/github.com/takumi0718/keyball/qmk_firmware/keyboards/keyball/keyball44/keymaps/my_midi/keymap.c) では、レイヤー `4` に MIDI ノートが割り当てられています。

- 下段付近に `MI_C` から `MI_A`
- 中段に `MI_C3` から `MI_D4`
- 上段に `MI_F3` から `MI_Gs4`
- 親指側に `MI_OCTU`, `MI_OCTD`

また、`keyboard_post_init_user()` で初期オクターブを `MI_OC0` 相当に設定しています。

## 11. 参照元

- `Context7`: `/qmk/qmk_firmware`
- 主な出典:
  `docs/features/midi.md`
  `docs/keycodes.md`
