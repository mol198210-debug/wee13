
#include <stdio.h>

int main() {
    float latitude;
    float longitude;
    int speed;
    int started = 0;

    FILE *fp = fopen("geo.json", "w");

    if (fp == NULL) {
        printf("파일 생성 실패\n");
        return 1;
    }

    fprintf(fp, "[\n");

    while (scanf("%f %f Speed = %d",
                 &latitude, &longitude, &speed) == 3) {

        if (started)
            fprintf(fp, ",\n");
        else
            started = 1;

        fprintf(fp,
            "{\"latitude\": %f, \"longitude\": %f, \"speed\": %d}",
            latitude, longitude, speed);
    }

    fprintf(fp, "\n]");
    fclose(fp);

    return 0;
}
