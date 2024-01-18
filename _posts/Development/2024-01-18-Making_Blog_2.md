---
title: "[Blog] Github 블로그 개설 2"
date: 2024-01-18 23:12:00 +09:00
categories: [Development, Github]
tags: [Development, Blog, Windows, Github, Ruby, Jekyll, jekyll-theme-chirpy]
---
## **1. 시작하며**
***
이번 포스팅에는 지난 포스팅에 이어 개설된 블로그에 테마를 적용하고 적용된 테마에 필요한 설정을 변경한 이후, 빌드 및 배포까지 진행해보려고 한다.

여러 마음에 드는 테마가 있었지만, chirpy 테마가 깔끔하기도 하고, 무엇보다도 대중적인 느낌이라 구글링으로 많은 도움을 받을 수 있겠다 싶어서 chirpy 테마를 사용해 블로그를 꾸며보기로 했다.
<br>

> <strong>이전 포스트</strong>
> <br>
>[Github 블로그 개설 1](https://wnsvy7203.github.io/posts/Making_Blog_1)

<br>

## **2. chirpy 테마 설치**
***
지난 포스팅까지 잘 따라왔다면, 아직 테마가 적용되기 전의, 날것의 jekyll 블로그 하나가 만들어졌을 것이다.

구글에 `jekyll theme chirpy`를 검색하면 첫 번째 게시물이 chirpy 테마 Github 레포지토리이다. Fork를 이용해도 되지만, 테마를 설치하다가 여러 차례의 실수가 있었기 때문에 그냥 **ZIP 파일**로 다운로드했다.

다운로드가 완료되면 압축을 풀어주고, 압축이 풀어진 디렉토리 내부의 파일/디렉토리를 모두 선택해서 내 jekyll 블로그 디렉토리 내부로 복사해주면 된다.

이 때, 같은 이름의 존재한다면 모두 다 덮어쓰면 된다.

### **(1) 사전 작업**
이제 설치를 통해 chirpy 테마가 빌드 가능하도록 만들어야 한다. README를 보면 기본적인 설명이 되어 있지만, Linux, Mac OS를 기반으로 테마가 제작되어 있기 때문에 Windows를 기반으로 설치를 하는 경우에는 수동으로 몇 가지 작업이 선행되어야 한다.

- Gemfile.lock 파일 삭제
- .travis.tml 파일 삭제
- _posts 디렉토리 내부 파일 모두 삭제
- docs 디렉토리 삭제
- .github/workflows 디렉토리 내부의 pages-deploy.yml.hook을 제외한 모든 파일을 삭제하고, pages-deploy.yml로 확장자 변경

만약 이 중 찾을 수 없는 파일이 있다면 그냥 진행하면 된다.

### **(2) 테마 설치**
```shell
$ bundle install
$ bundle exec jekyll serve
```
이제 블로그 디렉토리에서 커맨드 창을 열고, `bundle install`을 입력해서 테마를 설치해주면 된다.

설치한 후, 로컬 서버를 켜면 테마가 적용된 블로그의 모습을 확인할 수 있다.
<br>

![Imgur](https://i.imgur.com/sXxr5TG.png)
<br>

### **(3) 초기 설정**
설치가 완료되었으면, _config.yml 파일을 열어 초기 설정을 해 줄 수 있다.
<br>

|항목|값|설명|
|------|---|---|
|lang|en|_data/locales 디렉토리에서 다른 언어도 확인할 수 있다.<br>해당 디렉토리에 파일을 만들어서 custom 언어를 만들 수도 있다.|
|timezone|Asia/Seoul|기본값은 상하이, TimeZone을 맞춰주면 된다.|
|title|블로그 제목||
|tagline|타이틀 부연설명||
|description|블로그 설명||
|url|"https://username.github.io"||
|github|github id|본인의 github 아이디 입력|
|social.name|이름|블로그 맨 아래의 저작권 표시의 이름|
|social.email|이메일||
|social.links|링크||
|theme_mode|`[light|dark]`|원하는 테마 스킨 선택<br>기본값은 light|
|avatar|이미지 경로|블로그 왼쪽 상단에 표시되는 내 아바타 사진|
|toc|true|게시물의 오른쪽에 목차 표시|
|paginate|10|목록에 최대 몇 개의 글을 표시할 것인지를 선택|

<br>

## **3. 빌드 및 배포**
***
이 이후부터는 빌드와 배포를 진행해 나가면서 온갖 오류가 각자 다 다르게 나타나는데, 차차 해결해나가보도록 하겠다.

### **(1) github 업로드**
우선은 로컬 서버에서 테마가 적용된 것을 확인했으니, 첫 빌드와 배포를 진행해보도록 하겠다. 이 과정에서 우리가 할 일은 딱히 없고, Github에 add -> commit -> push의 과정을 한 번 진행해 주면 자동배포가 된다.

```shell
$ git config --global core.autocrlf true
$ git add .
$ git commit -m 'commit message'
$ git push
```

다만, 앞서도 언급했지만 Linux와 Mac OS 기반으로 만들어진 테마이기 때문에 모든 문서는 LF를 기준으로 맞춰져 있다. 따라서 `git config --global core.autocrlf true` 명령어를 먼저 실행해야 한다.

### **(2) 빌드 에러 1**
깔끔하게 빌드도 되지 않고 에러가 터졌다.
<br>

![Imgur](https://i.imgur.com/UFvHr12.png)
<br>

이 에러를 해결하기 위해서, 우선 github 레포지토리의 settings의 pages 탭으로 간다.
<br>

![Imgur](https://i.imgur.com/j7PHw1R.png)
<br>

해당 탭에서 Build and deployment => source 부분을 Github Actions로 바꿔준다.
<br>

![Imgur](https://i.imgur.com/AJQiJWl.png)
<br>

Configure를 클릭한 후,
<br>

![Imgur](https://i.imgur.com/prwT3x7.png)
<br>

별도 수정 없이 Commit changes를 2번 클릭하여 작업을 마무리한다.

### **(3) 빌드 에러 2**
곧바로 또 빌드 과정에서 에러가 터졌는데, 빌드 에러를 확인해보니 Setup Ruby 에서 다음과 같은 메시지를 확인할 수 있다.
<br>

![Imgur](https://i.imgur.com/tJS1XC7.png)
<br>

읽어내려오다보니, 아래 문구를 입력하고 다시 빌드 해 보라는 메시지가 있다.
```shell
$ bundle lock --add-platform x86_64-linux 
```

git push 하기 이전에, 앞서 빌드 및 배포 설정을 바꾸면서 Create jekyll.yml이라는 메시지로 Commit한 기록이 있다. 따라서 git pull 한 번 한 이후에 add -> commit -> push 해 주도록 한다.

### **(4) 빌드 에러 3**
아직 끝나지 않았다. 빌드 에러를 확인해보니 이번에는 Test site에서 Error 메시지를 출력하고 있는데, 특정 파일이 존재하지 않는다는 뜻인 것 같다.
<br>

![Imgur](https://i.imgur.com/uQ09p7C.png)
<br>

구글링해보니까 node.js 모듈을 설치하고 initialize 과정이 없으면 이 에러가 발생하는 것 같다. 혹시 node.js가 깔려 있지 않다면 설치([Node.js 설치](https://nodejs.org/en/download))해주고 커맨드 창에 다음과 같은 명령어를 입력해준다.

```shell
$ npm install -g win-node-env
$ npm install && npm run build
```
윗 줄의 명령어를 실행하지 않고 아랫 줄의 명령어를 실행하면 `'NODE_ENV'은(는) 내부 또는 외부 명령, 실행할 수 있는 프로그램, 또는 배치 파일이 아닙니다.`라는 에러 메시지를 확인할 수 있다. 따라서 아랫 줄의 명령어를 입력하고 다시 빌드한다.

이제 min.js 파일들이 잔뜩 설치된 것을 확인할 수 있다. 그리고 .gitignore 파일로 이동한다.

```
# Bundler cache
.bundle
vendor
Gemfile.lock

# Jekyll cache
.jekyll-cache
_site

# RubyGems
*.gem

# NPM dependencies
node_modules
package-lock.json

# IDE configurations
.idea
.vscode

# Misc
# assets/js/dist <- 이 부분 주석처리
```
앞서 설치된 min.js 파일들은 assets/js/dist안에 설치되어 github 원격 저장소에 저장되지 않는다. 따라서 assets/js/dist 부분을 주석처리하여 원격 저장소에 저장되도록 처리해준다.

이제 우리는 제대로 빌드된 블로그를 확인할 수 있다.
<br>

![Imgur](https://i.imgur.com/kFoJvnb.png)

<br>

## **4. 마치며**
이제 실제로 배포된 블로그를 만날 수 있다. 다음 포스팅은 게시물 작성 가이드와 기타 적용 가능한 팁들에 관해 작성해보려고 한다.