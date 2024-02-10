# Library
以下ドキュメントは日本語です。ゆるして。

## Verify
テストはLibraryCheckerとかでやろうかと思ってます。WIP
verifyしたもののURLとりあえずはっつけようかな、みんなGitflowとかでやってそうでかっこいい
<br>
maspyさんのとこに書いてあったメモをとりあえずパクっとく
```
「online-judge-tools/verification-helper」を使う．
https://github.com/online-judge-tools/verification-helper/blob/master/README.ja.md を見て頑張ります．
公開テストケースをダウンロードして，出力が正しいかを判定してくれる
Library Checker の問題だと特殊ジャッジも対応可
Library Checker, yukicoder はかなり安定して使える
AOJ の問題はときどき上手くダウンロードできないようだが割と使える
AtCoder の問題は，dropbox (https://atcoder.jp/posts/20) にあれば割とできる？
```

## フォルダ構成の規則
- 第一階層はディレクトリのみ。
- 第二階層はディレクトリかファイル
- 第三階層はファイルのみ。
(トリガが長いとUltiSnipの挙動がバグるため)

第一階層を「`カテゴリ`」<br>
第二階層のフォルダを「`サブグループ`」<br>
第二階層、第三階層のファイルを「`スニペット`」<br>
と呼ぶことにする。

## スニペットについて
- 私の環境がMacBookM2<img src="https://img.shields.io/badge/-Vim-019733.svg?logo=vim&style=flat">`9.0` + [`UltiSnips`](https://github.com/SirVer/ultisnips) ([`coc.nvim`](https://github.com/neoclide/coc.nvim))なので、それに合わせてます
- `cpp.snippets`本体は別レポジトリ[dotfiles](https://github.com/serna37/dotfiles)で管理(vimやzsh、clangの設定もここ)
- `cpp.template.snippets`, `algo.snippets`も同様。<br>
(これらはライブラリではなく、タブストップなどをしっかり入れた純粋なスニペットのため。)<br>
→逆に、この3ファイル以外はここで管理。<br>
棲み分けの基準は`まるごとコピペかどうか`としてます

## スニペット自動作成
- `snippets.sh`をzshで実行。(glob使ってます)([`genact`](https://github.com/svenstaro/genact)や[`cmatrix`](https://github.com/abishekvashok/cmatrix)などおふざけコマンドいれてるので注意)
- 何かあれば`snippets.sh`をカスタムする
- スニペットトリガの命名規則
```
{prefix}_{カテゴリ}_{スニペット}
{prefix}_{カテゴリ}_{サブグループ}_{スニペット}
```
もちろん拡張子は含まない。<br>
例) `./struct/seg/segment_tree.hpp`の場合
```
ww_struct_seg_segment_tree
```
※オプションはすべて`b`です。
