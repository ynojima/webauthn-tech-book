= WebAuthn

== 概要

//image[webauthn_overview][FIDO2 Overview]

@<img>{webauthn_overview} は Web Authentication API（以下WebAuthn） と Platform および、
External Authenticator の関係図です。

前章で解説したとおり、FIDO2.0 は WebAuthn と、 CTAP1/CTAP2 および Platform API を、
それぞれの OS,Browser ベンダーが実装して実現するプロジェクトです。

この図を見れば解るとおり、WebAuthn の裏側には、 Platform API や CTAP が存在することがわかります。

Platform API は、Platform、つまり PC や スマートフォンに登載された TPM や TEE といったセキュアチップと通信を行います。
PIN あるいはデバイスに登載された生体認証デバイスによって、セキュアチップ上で秘密鍵の生成や保存のための認証が行われます。

これらのAPIの裏側では、 Windows Hello や、Android Fingerprint Authentication などが動くことになるかと思われます。

== CTAP

一方 CTAP とは Client to Authenticator Protocol の略で、Client が Authenticator と通信するための仕様です。
CTAP には CTAP1 と CTAP2 が存在し、CTAP1 は U2F のプロトコルを指します。
一方 CTAP2 は CTAP1 を拡張した規格です。CTAP2 は下位互換があり U2F に対応したキーがそのまま利用できるます※。
また、U2F では実現できなかったパスワードレス認証や、PIN や 生体認証を利用したマルチファクター認証がスペックとして追加されています。

CTAP は各種 Web Browser 上で実装されています。
ただし Microsoft Edge に関しては、 CTAP も Platform API として、つまり Windows Hello 上に実装されています。

このように CTAP がどこに実装されるかは、各 Platform, ブラウザベンダーによって異なり一概にはいえませんが、
WebAuthn と CTAP というふたつの仕様を満たしている限り、
どのブラウザ・プラットフォームでもひとつの Authenticator を同一の認証情報として利用可能です。

====[column] CTAPの実装場所

少し説明が難しいのですが、CTAP2 では U2F の Authenticator を利用した場合においても CTAP1、つまり U2Fプロトコルとは一部パラメータ等が異なります。 
そのため、U2F で利用していた認証情報をそのまま、WebAuthn で利用することはできません。
具体的には U2F では AppID、WebAuthn では RP ID と呼ばれているパラメータが異なっており、、前者がプロトコル名 (https://) を含むのに対し、後者は origin 名しか含みません。
ただし、WebAuthn のスペックには、この差を埋めるための Extension が定義されており、
U2Fの認証サービスから WebAuthn への切り替えをスムーズにするための工夫がされています。

== Web Authentication API

Web Authentication API は W3C で策定が進められている API で、ウェブブラウザ上で実装されます。
このAPIですが、実は Credential Management API @<fn>{CDM} という認証情報を管理する API を拡張する形で実装されています。

@<strong>{Point: Web Authentication API は Credential Management API に実装されている。}

//footnote[CDM][Credential Management API : @<href>{https://www.w3.org/TR/credential-management-1/}]

WebAuthn の基本は FIDO の基本理念と同じく、公開鍵暗号を利用したチャレンジレスポンス認証です。
サーバーから送られたチャレンジに、最終的に Authenticator 内で署名し、サーバーに送り返します。

@<list>{webauthnAPI} は Web Authentication API の API です。

//listnum[webauthnAPI][Web Authentication][js]{

navigator.credentials.get({
    type: "public-key"
})

navigator.credentials.create({
    type: "public-key"
}))

//}

== まとめ

    1. Web Authentication API は 公開鍵暗号を利用したチャレンジレスポンス認証
    1. Web Authentication API は Credential Management API の拡張として定義
    1. API は credentials.create() と credentials.get() のふたつの認証API

== サンプル

かく

