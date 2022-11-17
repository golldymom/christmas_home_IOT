import os
from google.cloud import speech
from micstream import MicrophoneStream
import serial
import time

# Connect to Google API using the Google credentials
os.environ["GOOGLE_APPLICATION_CREDENTIALS"] =\
    "uvc-iot-project-8492cf18698a.json"

# Aduino recording parameters
RATE = 44100
CHUNK = int(RATE / 10)  # 100ms

# Connect to Arduino using pySerial
try:
    ser = serial.Serial('COM4', 9600)
    print('arduino connected')
except:
    print('unable to connect to arduino')

# Main function


def listen_print_loop(responses):
    print(responses)
    isTranscript = False
    for response in responses:
        result = response.results[0]
        transcript = result.alternatives[0].transcript.lower()

        isTranscript = True
        print(transcript)

        if (isTranscript):
            if ser.readable():
                # val = transcript
                print('transcript is there?')

                # LED ON
                if ("light on" in transcript or "lumos" in transcript):
                    input_value = '1'
                    print(input_value)
                    ser.write(bytes(input_value, 'utf-8'))
                    print("LED TURNED ON")
                    time.sleep(0.5)

                # LED OFF
                elif ("off" in transcript or "too bright" in transcript):
                    input_value = '0'
                    print(input_value)
                    ser.write(bytes(input_value, 'utf-8'))
                    print("ALL TURNED OFF")
                    time.sleep(0.5)

                # SOUND OFF
                elif ("noisy" in transcript or "music off" in transcript):
                    input_value = '3'
                    print(input_value)
                    ser.write(bytes(input_value, 'utf-8'))
                    print("christmas carol off")
                    time.sleep(0.5)

                # SOUND ON
                elif ("sing" in transcript or "song" in transcript):
                    input_value = '2'
                    print(input_value)
                    ser.write(bytes(input_value, 'utf-8'))
                    print("christmas carol on")
                    time.sleep(0.5)

                # LED && SOUND TOGETHER
                elif ("merry christmas" in transcript):
                    input_value = '4'
                    print(input_value)
                    ser.write(bytes(input_value, 'utf-8'))
                    print("merry christmas!")
                    time.sleep(0.5)

                # Break from Loop
                elif ('go away' in transcript or "bye" in transcript):
                    print('Exiting...')
                    input_value = '0'
                    ser.write(bytes(input_value, 'utf-8'))
                    break


# Set language to be English
language_code = 'en-US'  # a BCP-47 language tag

client = speech.SpeechClient()
config = speech.RecognitionConfig(
    encoding=speech.RecognitionConfig.AudioEncoding.LINEAR16,
    sample_rate_hertz=RATE,
    language_code=language_code)
streaming_config = speech.StreamingRecognitionConfig(config=config)

# Uses the MicrophoneStream class to get audio from the Mic
# When sound(response) is detected, it goes through the listen_print_loop function
with MicrophoneStream(RATE, CHUNK) as stream:
    audio_generator = stream.generator()
    requests = (speech.StreamingRecognizeRequest(audio_content=content)
                for content in audio_generator)
    responses = client.streaming_recognize(streaming_config, requests)
    listen_print_loop(responses)
