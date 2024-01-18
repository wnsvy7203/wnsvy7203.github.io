---
title: "[Blog] Github 블로그 개설 1"
date: 2024-01-16 22:44:00 +09:00
categories: [Development, Github]
tags: [Development, Blog, Windows, Github, Ruby, Jekyll]
---
## **1. 시작하며**
***
빌드 에러와 어디서 잘못됐는지 모를 오류들을 해결하느라 몇 번을 갈아엎었는지 기억도 안 난다.. 그래도 성공했음에 뿌듯함을 느끼면서 Github 블로그를 개설하는 방법을 포스팅하고자 한다.

<br>

## **2. Ruby, Jekyll 설치**
***
Jekyll은 정적 사이트 생성기(Static Site Generator, SSG)로, 사용자가 Markdown으로 작성한 문서를 HTML로 변환하여 정적 웹사이트를 생성하는 역할을 한다.

Jekyll은 Ruby라는 언어를 사용해 만들어졌기 때문에, Jekyll을 사용하기 위해서는 Ruby도 함께 설치해야 한다.

### **(1) 루비 설치 방법**
[Ruby 다운로드 페이지](https://rubyinstaller.org/downloads/)
<br>

![Imgur](https://i.imgur.com/lty32pi.png)
<br>

어떤 버전을 설치해야 할 지 모르겠다면 위의 사진처럼 **추천하는 버전**을 설치하는 것이 좋을 것 같다. ~~다만, 구글링 결과 Jekyll이 32bit 아키텍처라고 해서 나는 32bit(x86) 버전을 설치했다.~~

> ChatGPT한테 물어보니까 Jekyll은 Ruby로 개발된 정적 웹사이트 생성기이며, Ruby는 32bit와 64bit 아키텍처를 모두 지원한다. ***따라서 Jekyll 자체가 32bit 혹은 64bit로 구현되지 않는다고 한다.*** 그렇다면 그냥 **추천하는 버전**을 설치하는 게 낫겠다.

Ruby 설치 과정에서 주어진 체크박스는 모두 체크한 채로 진행했다.

<br>

## **3. Jekyll 설치**
***
cmd, git bash 중 아무 커맨드 창을 열어서 다음의 커맨드를 입력하면 설치된다.

```shell
$ gem install jekyll
$ gem install bundler
```
 
함께 설치한 **bundler**는 Ruby 프로젝트의 의존성을 관리하는 도구라고 한다. Jekyll 설치 시 bundler를 사용하는 이유는 주로 프로젝트에 필요한 정확한 버전의 gem(라이브러리)를 관리하기 위한 것이라고 알아두는 정도에서 그쳐도 될 것 같다.

***설치 버전 확인***
```shell
$ jekyll -v   # jekyll 4.3.3
$ bundler -v  # Bundler version 2.5.4
```
<br>

## **4. Jekyll 사이트 생성**
***
설치가 끝났다면, Jekyll 사이트를 생성해준다. 다만, 그 과정에 앞서 Jekyll 사이트를 관리할 Github Repository를 먼저 만들어줘야 한다.

### **(1) Github Repository 생성**
![Imgur](https://i.imgur.com/hGQAGxV.png)
<br>

해당 박스에 `username.github.io`의 형식을 입력하고 레포지토리를 생성해준 후, 로컬 저장소에 해당 레포지토리를 clone하면 간단하게 준비는 끝난다. 이제, 클론한 레포지토리의 디렉토리에서 커맨드 창을 열고 새로운 jekyll 사이트를 생성하자.
<br>

> 레포지토리 생성 시, README 파일은 빼자.<br> 이미 파일이 있는 디렉토리에서 jekyll 사이트를 생성하면, 오류 메시지를 출력할 수 있다.

### **(2) Jekyll 사이트 생성**

```shell
$ jekyll new ./
$ jekyll new ./ --force
```
만약 README 파일 때문에 위의 커맨드가 먹히지 않는다면, 커맨드 뒤에 `--force`를 추가하면 강제로 설치된다.

jekyll 사이트가 설치되었다면, 다음의 파일들이 생성된다.
<br>

![Imgur](https://i.imgur.com/0gf3Cei.png)
<br>

이 중 `Gemfile`은 Ruby 프로젝트의 의존성을 관리하기 위한 설정 파일로, 프로젝트에 필요한 gem들과 버전 정보를 명시한다.

이제 아래의 명령어로 `Gemfile`에 명시된 의존성들을 설치하자. 이 과정을 통해 필요한 Ruby 라이브러리 혹은 패키지를 다운로드하고 프로젝트에 설치함으로써 로컬 개발 환경을 설정할 수 있다.

```shell
$ bundle install
```

설치가 완료됐다면 이제, 로컬에서 jekyll 사이트를 실행해보자.

```shell
$ bundle exec jekyll serve
$ jekyll serve
```

> 위의 두 가지 방법의 차이는 `bundle exec`을 통해 실행하는 것과 아닌 것의 환경이다. `bundle exec`을 사용하면 현재 프로젝트의 `Gemfile.lock`에 명시된 의존성 버전을 사용하여 jekyll을 실행한다. 즉, 로컬 환경에 설치된 다른 gem 버전과의 충돌을 방지할 수 있다. 반면, `bundle exec` 없이 jekyll 사이트를 실행하면 시스템 전역의 jekyll을 사용하게 된다. 따라서, 버전 충돌이 발생할 수 있다. 이왕이면 `bundle exec`을 사용하는 것이 좋다.

모든 과정이 완벽하게 됐다면, `http://localhost:4000` 혹은, `http://127.0.0.1:4000` 에 접속하여 다음과 같은 화면을 확인할 수 있다.
<br>

![Imgur](https://i.imgur.com/cST85Fd.png)
<br>

## **5. 마치며**
이제 기본적인 준비는 모두 끝났다. 다음 포스팅은, 테마를 적용하여 다른 사람들도 접근할 수 있도록 빌드 및 배포까지 진행해 보려고 한다.

> <strong>다음 포스트</strong>
> <br>
> [Github 블로그 개설 2](https://wnsvy7203.github.io/posts/Making_Blog_2/)