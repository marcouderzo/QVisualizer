# QVisualizer

[![Generic badge](https://img.shields.io/badge/Windows Build-Passing-COLOR.svg)](https://shields.io/)


Repository del Progetto del corso di Programmazione ad Oggetti @ Università degli Studi di Padova. 

Sviluppato da:
- [Marco Uderzo](https://github.com/marcouderzo)
- [Samuel Kostadinov](https://github.com/Neskelogth)

## Introduction

QVisualizer is a desktop app for Real Time Music Visualization. It is written in C++ using the Qt Framework and its OpenGL library.

### Requirements
- Qt 5.13.0 or later

### Building in Windows
You might need to add to the .pro file the following line of code ` LIBS     += -lopengl32 -lglu32`.

### Notes
QVisualizer was developed to run natively in Ubuntu. Windows is also supported, but Qt's audio buffers have a quite strange behaviour in Windows: they randomly change size. Thus, it might not run smoothly or might not run at all. In a further update direct SoundCard input support will be added and that should fix it.

## For UniPD Students (ITALIAN)

### Attenzione!
Abbiamo deciso di condividere liberamente e totalmente il nostro progetto in modo che i futuri studenti del corso di Programmazione ad Oggetti possano trarne ispirazione, qualora l'idea piacesse. Sconsigliamo, però, di copiarlo. Il Professor Ranzato controlla ogni progetto consegnato confrontandolo con i precedenti. 

### Per la Macchina di Laboratorio 
La macchina virtuale di laboratorio fornitaci era sprovvista di alcuni moduli Qt. Per installarli, lanciare da terminale il comando `sudo apt install qtmultimedia5-dev libqt5multimedia5-plugins`.


