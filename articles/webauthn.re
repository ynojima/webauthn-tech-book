= Web Authentication API

@<img>{webauthn_overview} は Web Authentication API と Platform および、 External Authenticator の関係図です。
前章で解説したとおり、FIDO2.0 は Web Authentication API と、 CTAP1/CTAP2 および Platform API を、それぞれの OS,Browser ベンダーが実装して実現するプロジェクトです。

この図を見れば解るとおり、Web Authentication API の裏側には、 Platform API や CTAP の実装が

//image[webauthn_overview][overview]


@<list>{webauthnAPI} は Web Authentication API の API です。

//listnum[webauthnAPI][Web Authentication][js]{

navigator.credentials.get({
    type: "public-key"
})

navigator.credentials.create()

//}

== Credential Management API

どっかに挟み込む

== サンプル

かく
