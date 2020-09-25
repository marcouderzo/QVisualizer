# QVisualizer

[![Generic badge](https://img.shields.io/badge/Windows_Build-Passing-COLOR.svg)](https://shields.io/)
[![Generic badge](https://img.shields.io/badge/Linux_Build-Passing-COLOR.svg)](https://shields.io/)
[![Generic badge](https://img.shields.io/badge/Using-Qt-BLUE.svg)](https://shields.io/)
[![Generic badge](https://img.shields.io/badge/Using-OpenGL-BLUE.svg)](https://shields.io/)

![QVisualizerLogo](https://github.com/marcouderzo/QVisualizer/blob/masterbranch/resources/QVisualizer-white.jpg)

Repository del Progetto del corso di Programmazione ad Oggetti @ Università degli Studi di Padova. 

Sviluppato da:
- [Marco Uderzo](https://github.com/marcouderzo)
- [Samuel Kostadinov](https://github.com/Neskelogth)

## Introduction

QVisualizer is a desktop app for Real Time Music Visualization. It is written in C++ using Qt Library and OpenGL.

### Requirements
- Qt 5.13.0 or later 

### How To Compile
- Open Terminal
- Navigate to Folder
- Type `qmake QVisualizer.pro` and press Enter
- Type `make` and press Enter

### Notes
QVisualizer was developed to run natively in Ubuntu. Windows is also supported, but Qt's audio buffers have a quite strange behaviour in Windows: they randomly change size. That is dependent on the implementation that Qt developers decided to go with. To avoid any stability and compatibility issues, in this case QVisualizer will fetch the audio buffers from the soundcard. Thus, make sure you enable Stereo Mix.

## Updates

### Version 1.0
As it was submitted to the teacher.

### Version 1.1
- Improved compatibility on Windows: now using QAudioRecorder on Windows Implementation. Stereo Mix enabled is required.
- Added -Windows Only- Feature: audio is fetched from SoundCard, thus QVisualizer picks up the audio regardless of the app you are listening through.
- Improved User Experience: added QFileDialog for easier file selection.


## For UniPD Students (ITALIAN)

### Attenzione!
Abbiamo deciso di condividere liberamente e totalmente il nostro progetto in modo che i futuri studenti del corso di Programmazione ad Oggetti possano trarne ispirazione, qualora l'idea piacesse. Sconsigliamo, però, di copiarlo. Il Professor Ranzato controlla ogni progetto consegnato confrontandolo con i precedenti. 

### Per la Macchina di Laboratorio 
La macchina virtuale di laboratorio fornitaci era sprovvista di alcuni moduli Qt. Per installarli, lanciare da terminale il comando `sudo apt install qtmultimedia5-dev libqt5multimedia5-plugins`.
