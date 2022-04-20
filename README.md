										Agentie Imobiliara

Am creat 3 clase (Locuinta,Aparatament,Casa) prin mostenire (clasele Apartament si Casa sunt derivate din clasa de baza Locuinta).

Toate cele 3 clase au: functii set si get (pentru a seta sau returna variabile),constructori de initializare,parametrizati si de copiere,destructori,supraincarcarea operatorului = .
Constructorii parametrizati si constructorii de copiere ai claselor derivate transmit parametrii catre constrocturul de baza.

Clasa de baza contine o functie virtuala pura pentru a calculca chiria. Variabilele suprafata_utila si discount sunt protected,deoarece avem nevoie de acces la ele cand definim functia in clasele derivate.
Functiile afisare si citire sunt virtuale,deoarece folosim pointeri. Astfel citirea se va face corect pentru fiecare obiect.

Clasele Apartament si Casa contin cate o o variablia statica care creste cu unu la crearea unui obiect si o functie statica care o returneaza. Astfel putem numara cate obiecte am creat.

Meniu interactiv

Citim din fisierul input.txt un vector de pointeri la Locuinta pe care care il incarcam cu obiecte de tip Casa sau Apartament.(upcasting)

Prima Optiune: ajuta la alegerea unui apartament in functie de preferinte(daca acesta se afla in vector)
Se creeaza un vector cu obiecte Apartament pentru a lucra mai usor pe obiecte.Inainte de a face acest lucru efectuam downcasting pentru a avea pointerul de tipul Apartament.
Verificam daca downcastingul este efectuat corect folosind try-catch.
Se alege etajul dorit, iar daca acesta nu exista in vector se afiseaza un mesaj corespunzator.
Se alege daca apartamentul dorit va fi mare sau mic.
Se afiseaza datele despre apartamentul ales.

A Doua Optiune: ajuta la alegerea uneai case in functie de preferinte
Facem acelasi lucru ca la Prima Optiune, doar ca folosim clasa Casa si in loc de etaj se alege dimensiunea terenului.

A Treia Optiune: te scoate din meniul interactiv

A Patra Optiune: afiseaza lista cu locuintele din vector impreuna cu chiria

La iesire din meniu sunt cateva operatii simple care arata functionalitatea constructorilor.
