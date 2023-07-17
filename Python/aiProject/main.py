# import os
# import speech_recognition as sr

# def hear():
#     r = sr.Recognizer()
#     with sr.Microphone() as source:
#         r.adjust_for_ambient_noise(source)
#         print("Speak now...")
#         audio = r.listen(source)
#         try:
#             text = r.recognize_google(audio)
#             return text
#         except sr.UnknownValueError:
#             print("Could not understand audio.")
#         except sr.RequestError as e:
#             print("Could not request results from Google Speech Recognition service; {0}".format(e))


# text = hear()
# print(f"You said {text}")