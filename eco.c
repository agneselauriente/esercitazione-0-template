#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Uso: %s TESTO INTERO REALE\n", argv[0]);
        return 2;
    }

    char *testo = argv[1];
    char *intero = argv[2];
    char *reale = argv[3];
    

    /* TODO: converti gli argomenti in tipi appropriati. Usa atoi o atof
    * prendi ispirazione da:
    * https://en.cppreference.com/c/string/byte/atoi e 
    * https://en.cppreference.com/c/string/byte/atof */

    /* Evita un warning finche' la variabiletesto non viene usato nella stampa. */
    (void)testo;
    
    printf("%s %i %g\n", testo, atoi(intero), atof(reale));

    /* TODO: scrivi una sola chiamata a printf che stampi testo, intero e reale,
     * separati da uno spazio e seguiti da un carattere di nuova riga. */

    return 0;
}
