# 📒 Gestion des Contacts

Ce projet est une application de gestion des contacts en langage C. Il permet d'ajouter, afficher, modifier, supprimer, et rechercher des contacts.

## 🌟 Fonctionnalités
- ➕ **Ajouter un contact** : Enregistre un nouveau contact avec un nom, un numéro de téléphone et une adresse e-mail.
- 📋 **Afficher les contacts** : Affiche tous les contacts enregistrés.
- ✏️ **Modifier un contact** : Permet de modifier les informations d'un contact existant.
- ❌ **Supprimer un contact** : Supprime un contact de la liste.
- 🔍 **Rechercher un contact** : Recherche un contact par nom.
- 🛠️ **Tri des Contacts** : Tri les contact par nom , email , Téléphone.
- 
## ⚙️ Prérequis
- 🛠️ **GCC installé** (compilateur C)
- 💻 Un environnement de terminal sous Windows, Linux ou macOS

## 🪟 Compilation et Exécution sous Windows
1. Téléchargez et installez `gcc`.
2. Clonez ce dépôt dans votre répertoire local.
3. Naviguez vers le dossier du projet via le terminal ou l'invite de commandes.
4. Utilisez le script suivant pour compiler et exécuter le projet :

### 📜 Script de compilation pour Windows (`compile.bat`)

```cmd
@echo off
echo Checking for existing executable...
if exist Gestion.exe (
    echo Deleting previous executable...
    del Gestion.exe
)

echo Compiling the C files...
gcc main.c Contacts.c -o Gestion

if %errorlevel% neq 0 (
    echo Compilation failed!
) else (
    echo Compilation successful!
    echo Executable created: Gestion
)
pause
``` 
### Double-cliquez sur le fichier compile.bat ou exécutez-le dans un terminal via la commande :

compile.bat
🏁 Une fois la compilation réussie, exécutez le fichier généré Gestion.exe pour démarrer l'application.

### 📜 Script de compilation pour macOS (compile_mac.sh) 

#!/bin/bash

echo "Checking for existing executable..."
if [ -f "Gestion" ]; then
    echo "Deleting previous executable..."
    rm Gestion
fi

echo "Compiling the C files..."
gcc main.c Contacts.c -o Gestion

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
else
    echo "Compilation successful!"
    echo "Executable created: Gestion"
fi

Rendez le script exécutable et exécutez-le :
chmod +x compile_mac.sh
./compile_mac.sh

🍏 Une fois la compilation réussie, exécutez le fichier généré :
./Gestion

