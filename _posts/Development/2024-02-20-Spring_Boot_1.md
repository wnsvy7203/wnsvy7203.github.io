---
title: "[Spring Boot] Spring Boot 1. 실습 환경 구축"
date: 2024-02-20 00:31:00 +09:00
categories: [Development, Spring Boot]
tags: [Development, Windows, Java, Spring Boot, Web, Backend]
---
## **1. 시작하며**
***
개발자로의 취업을 위해 다양한 시도를 해 보고 있는데, Vue3를 활용해서 프론트엔드로도 프로젝트를 진행해 봤고, 유니티와 언리얼을 활용해서 게임 개발도 진행해봤다. 반면에 백엔드 경험은 Django를 프레임워크로 활용해 본 경험밖에 없기도 하고, 업무환경 특성상 Java를 기반으로 한 Spring Boot가 대체적으로 많이 활용되기 때문에 Spring Boot 학습이 필요하다고 생각하게 됐다.

또, 이번에 신세계 I&C에서 진행하는 스파로스 아카데미 4기에 백엔드로 지원해서 4개월 간 교육을 받게 됐는데, 실무 경험은커녕 Spring Boot로 프로젝트를 진행해 본 경험도 없기 때문에 프로젝트를 따라가고 1인분 혹은 그 이상을 해 내기 위해서, 또 배운 것을 바로바로 프로젝트에 적용하기 위해서라도 어느 정도 학습이 필요하다고 느꼈다.
<br>

## **2. JDK 설치 및 설정**
***
JDK는 자바 기반의 개발 환경에서 가장 기본이 되는 소프트웨어이다. 사용하고 있는 OS에 맞는 JDK를 설치하면 JVM(Java Virtual Machine)이 설치되고, 자바 언어로 개발한 애플리케이션을 실행할 수 있다.

자바 JDK는 Open JDK를 사용할 건데, 필요에 따라 다양한 Open JDK 중 하나를 선택적으로 사용할 수 있겠지만 일단은 학습을 위해 공식 사이트([https://openjdk.org/](https://openjdk.org/)) 에서 제공하는 JDK를 사용할 것이다. Oracle JDK가 더 이상 무료제공되지 않기도 하고, Open JDK 역시 자바 11 버전부터는 기존의 Oracle JDK와 성능이나 안정성 면에서 거의 비슷해졌다고 한다.

![Imgur](https://i.imgur.com/Brp2J2p.png)

![Imgur](https://i.imgur.com/yqXW9ca.png)

본인의 OS 환경에 맞는 Builds 중 한 버전을 선택해서 설치하면 된다. 설치된 파일은 압축 파일로, 적당한 디렉토리에 압축을 풀고 아래와 같이 환경 변수를 설정해준다.

- 우선 작업 표시줄의 검색 기능을 이용하여 **제어판의 고급 시스템 설정 보기**에 들어간다.

![Imgur](https://i.imgur.com/V5RpLn0.png)

- **고급** 탭의 **환경 변수**에 들어간다.

![Imgur](https://i.imgur.com/PCwWZDR.png)

- 시스템 변수 아래의 새로 만들기를 클릭하고, 변수 이름을 입력한 후, **변수 값**에는 **JDK가 설치된 디렉토리의 경로**를 입력한다.

![Imgur](https://i.imgur.com/2UkG5uY.png)

![Imgur](https://i.imgur.com/qAo4vzR.png)

- 시스템 변수의 **Path 변수**를 찾아 편집을 클릭한 후, `%변수 이름%\bin`을 입력해준다.

![Imgur](https://i.imgur.com/ZVPWD5K.png)

![Imgur](https://i.imgur.com/DXKQzhI.png)

- Path 설정 결과를 확인하려면 cmd 창에 `java -version`을 입력한다.

![Imgur](https://i.imgur.com/G7eTw5T.png)

## **3. Eclipse(STS) 설치**
***
Eclipse는 대표적인 자바 기반의 IDE(Integrated Development Environment, 통합 개발 환경)로, JetBrains 사의 IntelliJ와는 달리 100% 무료로 제공되고 있고, 다양한 플러그인을 활용하여 편리한 확장을 가능하게 한다는 장점이 있다. 

다만 이런 확실한 장점이 있음에도, 최근에는 많이 줄기는 했다지만 이클립스를 사용하다 보면 플러그인 간의 충돌이 일어날 가능성이 비교적 높다는 문제가 있다고 한다.

어쨌든 나는 여기서 이클립스 플러그인 STS(Spring Tool Suite)가 포함된 이클립스를 설치하려고 한다. STS가 포함된 이클립스는 스프링 홈페이지 ([https://spring.io/](https://spring.io/))에서 다운로드 할 수 있다.

![Imgur](https://i.imgur.com/KBCu9hg.png)

![Imgur](https://i.imgur.com/iClozPy.png)

Windows 버전을 다운로드하게 되면, `.jar` 파일이 하나 생성된다. 생성된 `.jar` 파일의 압축을 풀게 되면, 폴더 안에 다른 파일들과 `contents`라는 이름의 압축 파일을 하나 더 확인할 수 있다.

![Imgur](https://i.imgur.com/ZS2A8Te.png)

이 파일의 압축을 풀면 sts 해당 버전의 RELEASE 버전 디렉토리가 생성되는데, 이 디렉토리를 jdk 디렉토리와 같은 디렉토리로 이동시킨다.

![Imgur](https://i.imgur.com/Cmnt35B.png)

RELEASE 디렉토리에 들어가서 `SpringToolSuite4.exe` 파일을 실행시키면 workspace를 지정하라는 안내문이 나온다. 이 때, 이클립스의 구동을 위해서 workspace는 jdk와 sts가 설치된 디렉토리로 지정한다.

![Imgur](https://i.imgur.com/uocevy9.png)

![Imgur](https://i.imgur.com/4yUus4j.png)

스프링 부트 프로젝트를 생성하려면 아래 그림과 같이 `Spring Starter Project`를 사용해야 한다.

![Imgur](https://i.imgur.com/PCEsfqn.png)

## **4. 자주 쓰이는 단축키**
***
1. 코드 자동 완성: `Ctrl` + `Space bar`
2. 주석 처리
    - 단일 행 주석/주석 해제: `Ctrl` + `/`
    - 다중 행 주석: `Ctrl` + `Shift` + `/`
    - 다중 행 주석 해제: `Ctrl` + `Shift` + `\`
3. 파일 포맷 자동화: `Ctrl` + `Shift` + `F`
4. 클래스 `import` 자동화: `Ctrl` + `Shift` + `O`
5. 프로그램 실행: `Ctrl` + `F11`
6. 소스 생성: `Alt` + `Shift` + `S`
7. 클래스/변수/메소드 이름 변경: `Alt` + `Shift` + `T`
8. 폰트 크기 조절: `Ctrl` + `- or +`

## **5. 마치며**
***
기본적인 개발 환경을 구축하는 것은 끝났다. 나는 당연히 VSCode를 활용하는 것이 편하지만, 자바(스프링 부트를 포함해서)를 활용하는 수많은 기업들이 아마 대부분 이클립스, 또는 인텔리제이를 사용할 것이기 때문에 우선 배워놓고 나중에 기회가 되거나 원활하게 프로젝트를 진행할 수 있을 때 VSCode를 사용해서 스프링 부트 프로젝트를 진행해보려고 한다.

아마 다음 포스팅은 스프링 부트를 활용한 기초적인 프로젝트를 진행하는 내용이 주가 될 것 같다. 1인분 이상을 해 낼 수 있는 백엔드 개발자, 내지는 풀스택 개발자가 되는 그 날까지 화이팅..