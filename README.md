# WebAuthn Tech Book

技術書典5 2018 に出典予定の webAuthn 本のリポジトリです。

テンプレートは [TechBooster/ReVIEW-Template](https://github.com/TechBooster/ReVIEW-Template) を利用させていただきました。

## ビルド方法

Windows環境下でビルド環境整えるために、Latex の環境構築とかしたくないので vvakame さんの docker イメージをそのまま利用します。

docker build するときは改行コードが LF である必要があるので、適宜 `git config --global core.autocrlf false` 等設定してからプロジェクトのクローンをしてください。

```sh
docker run -t --rm -v "/c/path/to/project:/book" vvakame/review /bin/bash -ci "cd /book && ./setup.sh
&& npm run pdf"
```

## 紹介

パスワードレス時代がもうすぐ来る！

その中でも Microsoft や Google が採用し、 Chrome, Edge, Firefox  に実装されつつある Web Authentication API (WebAuthn)
本書では、WebAuthn の基本について、前半ではその概念、プロトコルのポイントを、後半には実際のAPIについてサンプルを交えつつ解説します。

電子書籍のみ ワンコイン(500円）です。

つーか、はたして完成するのか！？