# 스마트 크리스마스 홈
(Mini IoT Project)

## 아두이노 세팅
---
### [1] 브레드보드 및 아두이노 연결 (Arduino Uno사용)
![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/841325f1-0c8c-420a-8e5f-90d11d96258e/Untitled.png)

### [2] Arduino IDE
- gspeech_test.ino 참고

---

# # 파이썬

## [1] 파일 구성

<aside>
💡 + **gspeech_final_edit.py** : 메인 코드
+ [**micstream.py](http://micstream.py)** : 음성을 입력받기 위해 생성한 라이브러리
+ **uvc-iot-project-8492cf18698a.json** : 구글 API 인증키

</aside>

## [2] 설치 모듈/라이브러리

```powershell
pip install pyserial
pip install google-cloud-speech
pip install pyaudio
pip install --upgrade google-auth
pip install --upgrade google-api-python-client
```

## [3] 메인 파이썬 파일 실행
