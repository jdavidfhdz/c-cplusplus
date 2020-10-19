// Programa: RELOJ.CPP

#include <conio.h>
#include <stdio.h>
#include <iostream.h>  // Para el uso de cout
#include <dos.h>       // Para el uso de gettime
#include <time.h>      // Para el uso de difftime

void ESCONDER_CURSOR(void); // Procedimiento para desaparecer el cursor

void main(void)
{
  struct time hora;
  time_t hora_inicio, hora_final;
  struct date fecha;
  float segundos;

  clrscr();
  gotoxy(1,24); cout << "<<< Oprima cualquier tecla para continuar >>>";

  ESCONDER_CURSOR();

  hora_inicio=time(NULL);

  gettime(&hora);  // Obtiene la hora del sistema
  gotoxy(1,5); printf("Hora de inicio: %2d:%02d:%02d.%02d",hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);

  while(!kbhit())
  {
     gettime(&hora);  // Obtiene la hora del sistema
     gotoxy(1,12); printf("Hora actual: %2d:%02d:%02d.%02d",hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);


     getdate(&fecha); // Obtiene la fecha del sistema
     printf("\n\n\nFecha actual: %d/%d/%d", fecha.da_day,fecha.da_mon,fecha.da_year);
  }

  hora_final=time(NULL);  // Obtiene la hora del sistema
  segundos=difftime(hora_final,hora_inicio);

  gotoxy(1,19); printf("Duraci¢n: %f segundos", segundos);
  getch();getch();
  return;
}

void ESCONDER_CURSOR(void)
{
  union REGS regs;
  regs.h.ch=0x20;
  regs.h.ah=1;
  int86(0x10,&regs,&regs);
  return;
}
