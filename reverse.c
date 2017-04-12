void reverse(char *str) {
    char len = 0;
    while (str[len++] != '\0');

    char temp;
    char mid = (char) (--len / 2);
    for(int i = 0; i < mid; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
