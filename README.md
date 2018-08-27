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

