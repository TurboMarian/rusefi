#!/bin/bash
# Odpowiednik Windowsowego .bat, ale dla Linux/Bash

echo "=== RusEFI: Autogeneracja konfiguracji ==="

# Przejście do głównego katalogu rusefi
cd ../../../ || { echo "Nie znaleziono katalogu ../../../"; exit 1; }

# Uruchamianie skryptów .sh (Linuxowych odpowiedników)
bash gen_config.sh
bash gen_config_board.sh
bash gen_config_common.sh
bash gen_config_default.sh
bash gen_default_everything.sh
bash gen_live_documentation.sh
bash gen_output_channels.sh
bash gen_signature.sh

# Skrypty *.bat w Linuxie nie działają – odpowiedniki są w .sh lub można je pominąć:
# gen_enum_to_string.bat → zastępuje gen_enum_to_string.sh (jeśli istnieje)
if [ -f gen_enum_to_string.sh ]; then
  bash gen_enum_to_string.sh
fi

# gen_ptrace_enums.bat – brak wersji .sh, więc pomijamy albo trzeba przerobić ręcznie
# generate_docs.bat → jeśli istnieje wersja .sh, to uruchamiamy:
if [ -f generate_docs.sh ]; then
  bash generate_docs.sh
fi

echo "=== Gotowe! ==="






