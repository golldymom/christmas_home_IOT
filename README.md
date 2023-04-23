# **스마트 크리스마스 홈 (Mini IoT Project)**

## **# 프로젝트 설명**

스마트 크리스마스 홈은 음성으로 크리스마스 노래, 크리스마스 무드 램프 등을 제어 할 수 있는 시스템이다.


## **# 사용한 기술스텍**
- 아두이노
- 파이썬
- 구글 클라우드
- Apple 홈프릿지 (subproject)


## **# 아두이노 초기 세팅**

### [1] 브레드보드 및 아두이노 연결 (Arduino Uno사용)
![arduino](https://user-images.githubusercontent.com/66628195/202376751-e70f49cf-52af-4477-a668-303f3033cff8.png)

### [2] Arduino IDE
- gspeech_test.ino 참고

## **# 파이썬 초기 세팅**

### **[1] 파일 구성**
```
-- gspeech_final_edit.py (메인코드)
-- uvc-iot-project-8492cf18698a.json (구글 API 인중키)
-- micstream.py (음성 입력 라이브러리)
```

### **[2] 설치 모듈/라이브러리**

```
pip install pyserial
pip install google-cloud-speech
pip install pyaudio
pip install --upgrade google-auth
pip install --upgrade google-api-python-client
```

### **[3] 메인 파이썬 파일 실행**
```
python gspeech_final_edit.py
```
