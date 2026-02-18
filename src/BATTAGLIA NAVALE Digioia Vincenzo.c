#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void SetColor(unsigned short color);
void salva (int matGioc [][10], int matComp[][10], int prova[][10], int matAtt[][10]);
void Visualizza_campo_battaglia_Giocatore(int matGioc [][10]);
void Visualizza_Campo_Attacchi_Giocatore (int matAtt [][10]);
int Implementare_Campo (int matGioc[][10], int matComp[][10], int prova[][10],int matAtt[][10]);
    void Caricare_Campo_Giocatore (int matGioc[][10], int matComp[][10], int prova[][10], int matAtt[][10]);
	void Creare_Campo_Giocatore (int dim,int matGioc[][10]);
	void Creare_Campo_Salvataggio_Attacchi_Giocatore (int dim,int matAtt[][10]);
	void Creare_Campo_Computer (int dim,int matComp[][10]);
	void Creare_Campo_Salvataggio_Attacchi (int dim,int prova[][10]);
void Posizionare_Navi (int matGioc [][10], int matComp [][10], int scelta);
	void Turno_Navi_Giocatore (int matGioc [][10]);
		void Nave_Giocatore_1Posto (int matGioc [][10]);
		void Nave_Giocatore_2Posti (int matGioc [][10]);
		void Nave_Giocatore_3Posti (int matGioc [][10]);
		void Nave_Giocatore_4Posti (int matGioc [][10]);
	void Turno_Navi_Computer (int matComp [][10]);
		void Nave_Computer_1Posto (int matComp [][10]);
		void Nave_Computer_2Posti (int matComp [][10]);
		void Nave_Computer_3Posti (int matComp [][10]);
		void Nave_Computer_4Posti (int matComp [][10]);
int Giocare_Partita (int matGioc [][10], int matComp [][10], int prova [][10], int matAtt[][10]);
	int Controllare_Giocatore (int i);
	int Attaccare (int turno, int matGioc [][10], int matComp [][10], int prova [][10], int i, int matAtt[][10]);
		int Attacco_Giocatore (int matComp [][10],int matGioc [][10], int i, int matAtt[][10]);
		int Attacco_Computer (int matGioc [][10], int prova [][10], int i);
	    int Aggiornare_Punteggio (int esito, int turno, int matComp [][10],int matGioc [][10]);
void Decretare_Vincitore(int esito);
int trasformazione (char c);


main(){
	int matGioc [10][10], matComp [10][10],prova [10][10],matAtt [10][10],esito, scelta;
    scelta= Implementare_Campo(matGioc, matComp, prova, matAtt);
	Posizionare_Navi(matGioc, matComp, scelta);
	esito= Giocare_Partita(matGioc, matComp, prova, matAtt);
	Decretare_Vincitore(esito);
	system ("PAUSE");
	return 0;
}


void SetColor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}


void salva (int matGioc [][10], int matComp [][10], int prova [][10], int matAtt[][10]){
	int i,j,dim;
	FILE *fd;
	fd=fopen ("Salva.txt", "w");
	fprintf (fd,"1");
	fprintf (fd,"\n");
	i=0;
	dim=10;
		while (i<dim){
			j=0;
			while(j<dim){
				 fprintf (fd," %d ",matGioc[j][i]);
				j=j+1;
			}
			i=i+1;
			fprintf (fd,"\n");
		}
		fprintf (fd,"\n");
		i=0;
	    dim=10;
		while (i<dim){
			j=0;
			while(j<dim){
				 fprintf (fd," %d ",matComp[j][i]);
				j=j+1;
			}
			i=i+1;
			fprintf (fd,"\n");
		}
		fprintf (fd,"\n");
		i=0;
	    dim=10;
		while (i<dim){
			j=0;
			while(j<dim){
				 fprintf (fd," %d ",prova[j][i]);
				j=j+1;
			}
			i=i+1;
			fprintf (fd,"\n");
		}
		fprintf (fd,"\n");
		i=0;
	    dim=10;
		while (i<dim){
			j=0;
			while(j<dim){
				 fprintf (fd," %d ",matAtt[j][i]);
				j=j+1;
			}
			i=i+1;
			fprintf (fd,"\n");
		}
		fprintf (fd,"\n");
    fclose (fd);
}


void Visualizza_Campo_Attacchi_Giocatore (int matAtt [][10]){
	int i,j,dim;
	i=0;
	dim=10;
	printf ("\n");
	printf ("-----------------------CAMPO BATTAGLIA ATTACCHI GIOCATORE----------------------- \n");
	printf ("\n");
	printf (" LEGGENDA:  ");
	SetColor(4);
	printf ("0= ATTACCO FALLITO   ");
	SetColor(2);
	printf ("1= NAVE/PARTE NAVE COLPITA  ");
	SetColor(15);
	printf ("NULL= DISPONIBILI\n");
	printf ("-------------------------------------------------------------------------------- \n");
		printf ("    A   B   C   D   E   F   G   H   I   L \n");
		while (i<dim){
			j=0;
			printf ("  ----------------------------------------- \n");
			printf ("%d |",i);
			while(j<dim){
				if (matAtt [j][i]==1)
				{
					SetColor(2);
					printf (" %d ",matAtt[j][i]);
					SetColor(15);
					printf ("|",matAtt[j][i]);
				}
				else
				{
					if (matAtt [j][i]==3)
					{
						SetColor(0);
						printf (" %d ",matAtt[j][i]);
						SetColor(15);
						printf ("|",matAtt[j][i]);
					}
					else
					{
						SetColor(4);
						printf (" %d ",matAtt[j][i]);
						SetColor(15);
						printf ("|",matAtt[j][i]);
					}
				}
				j=j+1;
			}
			i=i+1;
			printf ("\n");
		}
		printf ("\n");
		printf ("\n");
}


void Visualizza_campo_battaglia_Giocatore(int matGioc [][10]){
	int i,j,dim;
	i=0;
	dim=10;
	printf ("\n");
	printf ("----------------------------CAMPO BATTAGLIA GIOCATORE--------------------------- \n");
	printf ("\n");
	printf (" LEGGENDA:    ");
	SetColor(3);
	printf ("0= MARE       ");
	SetColor(4);
	printf ("1= NAVE/PARTE DI NAVE     ");
	SetColor(15);
	printf ("NULL= CONTORNO NAVE\n");
	printf ("-------------------------------------------------------------------------------- \n");
		printf ("    A   B   C   D   E   F   G   H   I   L \n");
		while (i<dim){
			j=0;
			printf ("  ----------------------------------------- \n");
			printf ("%d |",i);
			while(j<dim){
				if (matGioc[j][i]==1)
				{
					SetColor(4);
					printf (" %d ",matGioc[j][i]);
					SetColor(15);
					printf ("|",matGioc[j][i]);
				}
				else
				{
					if (matGioc[j][i]==3)
					{
						SetColor(0);
						printf (" %d ",matGioc[j][i]);
						SetColor(15);
						printf ("|",matGioc[j][i]);
					}
					else
					{
						SetColor(3);
						printf (" %d ",matGioc[j][i]);
						SetColor(15);
						printf ("|",matGioc[j][i]);
					}
				}
				j=j+1;
			}
			i=i+1;
			printf ("\n");
		}
		printf ("\n");
		printf ("\n");
}




int Implementare_Campo (int matGioc[][10], int matComp[][10], int prova[][10], int matAtt[][10]){
	int dim,scelta,ok,esito;
	dim=10;
	ok=0;
	FILE *fd;
	fd=fopen ("Salva.txt", "r");
	fscanf (fd,"%d", &esito);
	if (esito==1)
	{
		printf("\n VUOI CONTINUARE LA PARTITA PRECEDENTEMENTE SOSPESA IN FASE DI ATTACCO? \n");
		while (ok==0)
		{
			printf("\n");
			printf("                            SI--> 1      NO--> 0  ");
			scanf("%d", &scelta);
			if (scelta>1 || scelta<0)
			{
				SetColor(4);
				printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
				SetColor(15);
				ok=0;
			}
			else
			{
				ok=1;
			}
		}
		if (scelta==1)
		{
			Caricare_Campo_Giocatore (matGioc, matComp, prova, matAtt);
		}
		else
		{
			Creare_Campo_Computer(dim, matComp);
			Creare_Campo_Giocatore(dim, matGioc);
			Creare_Campo_Salvataggio_Attacchi (dim, prova);
			Creare_Campo_Salvataggio_Attacchi_Giocatore (dim,matAtt);
	    }
	}
	else
		{
			Creare_Campo_Computer(dim, matComp);
			Creare_Campo_Giocatore(dim, matGioc);
			Creare_Campo_Salvataggio_Attacchi (dim, prova);
			Creare_Campo_Salvataggio_Attacchi_Giocatore (dim,matAtt);
			scelta=0;
	    }
    return scelta;
}


void Caricare_Campo_Giocatore (int matGioc[][10], int matComp[][10], int prova[][10], int matAtt[][10]){
	int i,j,dim,scelta;
	FILE *fd;
	fd=fopen ("Salva.txt", "r");
	fscanf (fd,"%d", &scelta);
	if (scelta==1)
	{
		i=0;
		dim=10;
			while (i<dim){
				j=0;
				while(j<dim){
					 fscanf (fd,"%d", &matGioc[j][i]);
					 j=j+1;
				}
				i=i+1;
			}
		i=0;
		dim=10;
			while (i<dim){
				j=0;
				while(j<dim){
					 fscanf (fd,"%d", &matComp[j][i]);
					 j=j+1;
				}
				i=i+1;
		    }
		i=0;
		dim=10;
			while (i<dim){
				j=0;
				while(j<dim){
					 fscanf (fd,"%d", &matAtt[j][i]);
					 j=j+1;
				}
				i=i+1;
		    }
		i=0;
		dim=10;
			while (i<dim){
				j=0;
				while(j<dim){
					 fscanf (fd,"%d", &prova[j][i]);
					 j=j+1;
				}
				i=i+1;
	    }

    printf ("\n");
	printf("\n CAMPO BATTAGLIA GIOCATORE CARICATO \n");
	printf("\n CAMPO BATTAGLIA COMPUTER CARICATO \n");
	printf ("\n");
	}
	else
	{
		SetColor(4);
		printf("\n ATTENZIONE: NESSUN SALVATAGGIO EFFETTUATO \n");
		SetColor(15);
	}
	fclose (fd);
}


void Creare_Campo_Giocatore (int dim, int matGioc[][10]){
	int i,j;
	i=0;
	while (i<dim){
		j=0;
		while(j<dim){
			matGioc [j][i]=0;
			j=j+1;
		}
		i=i+1;
	}

	printf("\n CAMPO BATTAGLIA GIOCATORE CREATO \n");
	printf ("\n");
}


void Creare_Campo_Salvataggio_Attacchi_Giocatore (int dim,int matAtt[][10]){
	int i,j;
	i=0;
	while (i<dim){
		j=0;
		while(j<dim){
			matAtt [j][i]=3;
			j=j+1;
		}
		i=i+1;
	}
}


void Creare_Campo_Computer (int dim, int matComp[][10]){
	int i,j;
	i=0;
	while (i<dim){
		j=0;
		while(j<dim){
			matComp [j][i]=0;
			j=j+1;
		}
		i=i+1;
	}
	printf("\n CAMPO BATTAGLIA COMPUTER CREATO \n");
}


void Creare_Campo_Salvataggio_Attacchi (int dim, int prova [][10]){
	int i,j;
	i=0;
	while (i<dim){
		j=0;
		while(j<dim){
			prova [j][i]=0;
			j=j+1;
		}
		i=i+1;
	}
}


void Posizionare_Navi (int matGioc [][10], int matComp [][10], int scelta){
	if (scelta==0)
	{
		Turno_Navi_Giocatore (matGioc);
	    Turno_Navi_Computer (matComp);
	}
}

void Turno_Navi_Giocatore (int matGioc [][10]){
	int i,scelta,ok;
	printf ("\n");
	printf ("-------------------------INSERIMENTO NAVI GIOCATORE--------------------------- \n");
	printf ("\n");
	scelta=0;
	i=0;
	printf("\n PRIMA DI INSERIRE LE NAVI AD 1 POSTO VUOI VISUALIZZARE IL TUO CAMPO? \n");
	ok=0;
	while (ok==0)
	{
		printf("\n");
		printf("                            SI--> 1      NO--> 0  ");
		scanf("%d", &scelta);
		if (scelta>1 || scelta<0)
		{
			SetColor(4);
			printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
			SetColor(15);
			ok=0;
		}
		else
		{
			ok=1;
		}
	}
	if (scelta==1)
	{
		Visualizza_campo_battaglia_Giocatore (matGioc);
	}
	while (i<4)
	{
		Nave_Giocatore_1Posto (matGioc);
		i=i+1;
	}
	printf ("-------------------------------------------------------------------------------- \n");
	i=0;
	scelta=0;
	printf("\n PRIMA DI INSERIRE LE NAVI A 2 POSTI VUOI VISUALIZZARE IL TUO CAMPO? \n");
	ok=0;
	while (ok==0)
	{
		printf("\n");
		printf("                            SI--> 1      NO--> 0  ");
		scanf("%d", &scelta);
		if (scelta>1 || scelta<0)
		{
			SetColor(4);
			printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
			SetColor(15);
			ok=0;
		}
		else
		{
			ok=1;
		}
	}
	if (scelta==1)
	{
		Visualizza_campo_battaglia_Giocatore (matGioc);
	}
	while (i<3)
	{
		Nave_Giocatore_2Posti (matGioc);
		i=i+1;
	}
	printf ("-------------------------------------------------------------------------------- \n");
	i=0;
	scelta=0;
	printf("\n PRIMA DI INSERIRE LE NAVI A 3 POSTI VUOI VISUALIZZARE IL TUO CAMPO? \n");
    ok=0;
	while (ok==0)
	{
		printf("\n");
		printf("                            SI--> 1      NO--> 0  ");
		scanf("%d", &scelta);
		if (scelta>1 || scelta<0)
		{
			SetColor(4);
			printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
			SetColor(15);
			ok=0;
		}
		else
		{
			ok=1;
		}
	}
	if (scelta==1)
	{
		Visualizza_campo_battaglia_Giocatore (matGioc);
	}
	while (i<2)
	{
		Nave_Giocatore_3Posti (matGioc);
		i=i+1;
	}
	scelta=0;
	printf("\n PRIMA DI INSERIRE LE NAVI A 4 POSTI VUOI VISUALIZZARE IL TUO CAMPO? \n");
	ok=0;
	while (ok==0)
	{
		printf("\n");
		printf("                            SI--> 1      NO--> 0  ");
		scanf("%d", &scelta);
		if (scelta>1 || scelta<0)
		{
			SetColor(4);
			printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
			SetColor(15);
			ok=0;
		}
		else
		{
			ok=1;
		}
	}
	if (scelta==1)
	{
		Visualizza_campo_battaglia_Giocatore (matGioc);
	}
	Nave_Giocatore_4Posti (matGioc);
	printf ("\n");
	Visualizza_campo_battaglia_Giocatore (matGioc);
}


int trasformazione (char c){
	int a;
	if (c=='a' || c=='A')
			{
				a=0;
			}
			else
			{
				if (c=='b' || c=='B')
			    {
					a=1;
			    }
			    else
			    {
			    	if (c=='c' || c=='C')
					{
						a=2;
					}
					else
					{
						if (c=='d' || c=='D')
						{
							a=3;
						}
						else
						{
							if (c=='e' || c=='E')
							{
								a=4;
							}
							else
							{
								if (c=='f' || c=='F')
								{
									a=5;
								}
								else
								{
									if (c=='g' || c=='G')
									{
										a=6;
									}
									else
									{
										if (c=='h' || c=='H')
										{
											a=7;
										}
										else
										{
											if (c=='i' || c=='I')
											{
												a=8;
											}
											else
											{
												if (c=='l' || c=='L')
												{
													a=9;
												}
												else
												{
													a=10;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			return a;
}


void Nave_Giocatore_1Posto (int matGioc [][10]){
	int trovato,a,b,ok;
	char c,cestino;
	printf ("\n BARCA A 1 POSTO \n");
    printf (" VALORI DA 0 A 9 \n");
    trovato=0;
    while (trovato==0){
    	ok=0;
    	while (ok==0)
    	{
    		scanf ("%c",&cestino);
    		printf (" INSERIRE CORDINATE COLONNA: ");
			scanf ("%c",&c);
			printf (" INSERIRE COORDINATE RIGA: ");
			scanf ("%d",&b);
			a= trasformazione(c);
			if (a<0 || a>9 || b<0 || b>9)
			{
				printf ("\n");
				SetColor(4);
				printf ("\n ATTENZIONE: INSERIRE VAOLORI COMPRESI TRA 'A' e 'L' PER LE COLONNE E TRA 0 e 9 PER LE RIGHE  \n");
				SetColor(15);
				ok=0;
			}
			else
			{
				ok=1;
			}
		}
			printf ("\n");
			if (matGioc [a][b]==0)
		      {
		      		matGioc [a][b]=1;
	                b=b+1;
	                if (b<=9)
	                {
	                	matGioc [a][b]=3;
	                    b=b-1;
					}
	                else
	                {
	                	b=b-1;
					}
	                a=a+1;
	                if (a<=9)
	                {
		                matGioc [a][b]=3;
		                a=a-1;
					}
	                else
	                {
	                	a=a-1;
					}
	                b=b-1;
	                if (b>=0)
	                {
	                	matGioc [a][b]=3;
	                    b=b+1;
					}
	                else
	                {
	                	b=b+1;
					}
	                a=a-1;
	                if (a>=0)
	                {
	                	matGioc [a][b]=3;
	                    a=a+1;
					}
	                else
	                {
	                	a=a+1;
					}
			        trovato=1;
			  }
		    else
		      {
		      	   SetColor(4);
			       printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
			       SetColor(15);
			       trovato=0;
			  }
   }
}


void Nave_Giocatore_2Posti (int matGioc [][10]){
	int succ,a,b,cont,trov,trovato,x,dim,ok;
	char c,cestino;
    dim=10;
	printf ("\n BARCA A 2 POSTI \n");
    printf (" VALORI DA 0 A 9 \n");
    trov=0;
    while (trov==0)
    {
    trovato=0;
    while (trovato==0){
    	ok=0;
    	while (ok==0)
    	{
    		scanf ("%c",&cestino);
    		printf (" INSERIRE CORDINATE COLONNA: ");
			scanf ("%c",&c);
			printf (" INSERIRE COORDINATE RIGA: ");
			scanf ("%d",&b);
			a= trasformazione(c);
			if (a<0 || a>9 || b<0 || b>9)
			{
				printf ("\n");
				SetColor(4);
				printf ("\n ATTENZIONE: INSERIRE VAOLORI COMPRESI TRA 'A' e 'L' PER LE COLONNE E TRA 0 e 9 PER LE RIGHE  \n");
				SetColor(15);
				ok=0;
			}
			else
			{
				ok=1;
			}
		}
			printf ("\n");
			printf ("                  INSERIRE VERSO DELLA NAVE \n");
		    ok=0;
			while (ok==0)
			{
				printf("\n");
				printf("           ORIZZONTALE--> 0      VERTICALE--> 1  ");
				scanf("%d", &succ);
				if (succ>1 || succ<0)
				{
					SetColor(4);
					printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
					SetColor(15);
					ok=0;
				}
				else
				{
					ok=1;
				}
			}
			if (succ==0)
			{
			  if (matGioc [a][b]==0)
		      {
		      	if (b==0)
		      	{
		      		matGioc [a][b]=1;
	                b=b+1;
	                matGioc [a][b]=3;
	                b=b-1;
			        trovato=1;
			    }
			    else
				{
					if(b==9)
					{
						matGioc [a][b]=1;
	                    b=b-1;
	                    matGioc [a][b]=3;
	                    b=b+1;
			            trovato=1;
					}
					else
					{
						b=b+1;
		                matGioc [a][b]=3;
		                b=b-1;
			            matGioc [a][b]=1;
			            b=b-1;
			            matGioc [a][b]=3;
			            b=b+1;
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       SetColor(4);
		       printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		       SetColor(15);
		       trovato=0;
			  }
			}
			else
			{
				if (matGioc [a][b]==0)
		      {
		      	if (a==0)
		      	{
		      		matGioc [a][b]=1;
	                a=a+1;
	                matGioc [a][b]=3;
	                a=a-1;
			        trovato=1;
			    }
			    else
			    {
			    	if(a==9)
					{
						matGioc [a][b]=1;
	                    a=a-1;
	                    matGioc [a][b]=3;
	                    a=a+1;
			            trovato=1;
					}
					else
					{
						a=a+1;
		                matGioc [a][b]=3;
		                a=a-1;
			            matGioc [a][b]=1;
			            a=a-1;
			            matGioc [a][b]=3;
			            a=a+1;
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       SetColor(4);
		       printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		       SetColor(15);
		       trovato=0;
			  }
			}
	}
      cont=1;
      x=0;
	  printf ("\n");
	  srand(time(NULL));
      if (succ==0)
      {
      	if (a==9)
      	{
      	  x=a-1;
      	  if (matGioc [x][b]==0)
      	  {
      	    a=a+1;
      	    if (a<=9)
      	    {
      	    	matGioc [a][b]=3;
                a=a-1;
			}
            else{
                a=a-1;
                }
	      	  while (cont<2){
	      	    a=a-1;
	      	    if (matGioc [a][b]==0)
	            {
	              if (b==0)
	              {
		      		matGioc [a][b]=1;
	                b=b+1;
	                matGioc [a][b]=3;
	                b=b-1;
			        trovato=1;
			      }
			      else
			      {
			        if(b==9)
						{
							matGioc [a][b]=1;
		                    b=b-1;
		                    matGioc [a][b]=3;
		                    b=b+1;
				            trovato=1;
						}
						else
						{
						  b=b+1;
	                      matGioc [a][b]=3;
		                  b=b-1;
				          matGioc [a][b]=1;
				          b=b-1;
			              matGioc [a][b]=3;
			              b=b+1;
						}

				  }

	            }
	            cont++;
	          }
	          a=a-1;
              matGioc [a][b]=3;
	        trov=1;
          }
          else
          {
          	SetColor(4);
          	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
          	SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		  }
		}
		else
		{
		  x=a+1;
      	  if (matGioc [x][b]==0)
      	  {
      	  	a=a-1;
			matGioc [a][b]=3;
			a=a+1;
			  while (cont<2){
			    a=a+1;
	      	    if (matGioc [a][b]==0)
	            {
	              if (b==0)
			      	{
			      		matGioc [a][b]=1;
		                b=b+1;
		                matGioc [a][b]=3;
		                b=b-1;
				        trovato=1;
				    }
				    else
				    {
				      if(b==9)
						{
							matGioc [a][b]=1;
		                    b=b-1;
		                    matGioc [a][b]=3;
		                    b=b+1;
				            trovato=1;
						}
					  else
						{
					      b=b+1;
		                  matGioc [a][b]=3;
		                  b=b-1;
				          matGioc [a][b]=1;
				          b=b-1;
			              matGioc [a][b]=3;
			              b=b+1;
						}
				    }
	    	    }
	    	    cont++;
	          }
	        a=a+1;
	        if (a<=9)
	        {
	        	matGioc [a][b]=3;
	        	a=a-1;
			}
            a=a-1;
            trov=1;
		  }
		  else
		  {
		  	SetColor(4);
		  	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		  	SetColor(15);
		  	matGioc [a][b]=0;
          	trov=0;
		  }
	  }
     }
	  else
     {
	    if (b==9)
      	{
      	  x=b-1;
      	  if (matGioc [a][x]==0)
      	  {
      	  b=b+1;
      	  if (b<=9)
      	  {
      	  	matGioc [a][b]=3;
      	    b=b-1;
		  }
		  else
		  {
		  	b=b-1;
		  }
      	  while (cont<2){
      	    b=b-1;
      	    if (matGioc [a][b]==0)
            {
	           if (a==0)
	              {
		      		matGioc [a][b]=1;
	                a=a+1;
	                matGioc [a][b]=3;
	                a=a-1;
			        trovato=1;
			      }
			      else
			      {
			      	if(a==9)
						{
							matGioc [a][b]=1;
		                    a=a-1;
		                    matGioc [a][b]=3;
		                    a=a+1;
				            trovato=1;
						}
					 else
					 {
					 	  a=a+1;
		                  matGioc [a][b]=3;
		                  a=a-1;
				          matGioc [a][b]=1;
				          a=a-1;
			              matGioc [a][b]=3;
			              a=a+1;
					 }

				  }
            }
            cont++;
            }
            b=b-1;
            matGioc [a][b]=3;
	        trov=1;
		  }
		  else
		  {
		  	SetColor(4);
		  	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		  	SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		  }
	    }
		else
		{
		  x=b+1;
      	  if (matGioc [a][x]==0)
      	  {
      	  b=b-1;
      	  if (b>=0)
      	  {
      	  	matGioc [a][b]=3;
		    b=b+1;
		  }
		  else
		  {
		  	b=b+1;
		  }
		  while (cont<2){
		    b=b+1;
      	    if (matGioc [a][b]==0)
            {
	          if (a==0)
			      	{
			      		matGioc [a][b]=1;
		                a=a+1;
		                matGioc [a][b]=3;
		                a=a-1;
				        trovato=1;
				    }
				    else
				    {
				      if(a==9)
						{
							matGioc [a][b]=1;
		                    a=a-1;
		                    matGioc [a][b]=3;
		                    a=a+1;
				            trovato=1;
						}
					  else
						{
					      a=a+1;
		                  matGioc [a][b]=3;
		                  a=a-1;
				          matGioc [a][b]=1;
				          a=a-1;
			              matGioc [a][b]=3;
			              a=a+1;
						}
				    }
    	    }
    	    cont++;
    	  }
    	  b=b+1;
    	  if (b<=9)
    	  {
    	  	matGioc [a][b]=3;
    	  	b=b-1;
		  }
          b=b-1;
	      trov=1;
		}
		else
		{
			SetColor(4);
		    printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		    SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		}
      }
  }
}
}


void Nave_Giocatore_3Posti (int matGioc [][10]){
	int succ,esito,a,b,cont,trov,trovato,z,x,dim,ok;
	char c,cestino;
    dim=10;
	printf ("\n BARCA A 3 POSTI \n");
    printf (" VALORI DA 0 A 9 \n");
    trov=0;
    while (trov==0)
    {
    trovato=0;
    while (trovato==0){
    	ok=0;
    	while (ok==0)
    	{
    		scanf ("%c",&cestino);
    		printf (" INSERIRE CORDINATE COLONNA: ");
			scanf ("%c",&c);
			printf (" INSERIRE COORDINATE RIGA: ");
			scanf ("%d",&b);
			a= trasformazione(c);
			if (a<0 || a>9 || b<0 || b>9)
			{
				printf ("\n");
				SetColor(4);
				printf ("\n ATTENZIONE: INSERIRE VAOLORI COMPRESI TRA 'A' e 'L' PER LE COLONNE E TRA 0 e 9 PER LE RIGHE  \n");
				SetColor(15);
				ok=0;
			}
			else
			{
				ok=1;
			}
		}
			printf ("\n");
			printf ("                  INSERIRE VERSO DELLA NAVE \n");
			ok=0;
			while (ok==0)
			{
				printf("\n");
				printf("           ORIZZONTALE--> 0      VERTICALE--> 1  ");
				scanf("%d", &succ);
				if (succ>1 || succ<0)
				{
					SetColor(4);
					printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
					SetColor(15);
					ok=0;
				}
				else
				{
					ok=1;
				}
			}
			if (succ==0)
			{
			  if (matGioc [a][b]==0)
		      {
		      	if (b==0)
		      	{
		      		matGioc [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
				{
					if(b==9)
					{
						matGioc [a][b]=1; //stampo valore originale;
	                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                    b=b+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                b=b-1;  //decremento la riga per farla tornare al punto originale
			            matGioc [a][b]=1; //stampo valore originale;
			            b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			            b=b+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       SetColor(4);
		       printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		       SetColor(15);
		       trovato=0;
			  }
			}
			else
			{
				if (matGioc [a][b]==0)
		      {
		      	if (a==0)
		      	{
		      		matGioc [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
			    {
			    	if(a==9)
					{
						matGioc [a][b]=1; //stampo valore originale;
	                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                    a=a+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                a=a-1;  //decremento la riga per farla tornare al punto originale
			            matGioc [a][b]=1; //stampo valore originale;
			            a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			            a=a+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       SetColor(4);
		       printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		       SetColor(15);
		       trovato=0;
			  }
			}
	}
      cont=1;
      x=0;
      z=0;
	  printf ("\n");
	  srand(time(NULL));
      if (succ==0)
      {
      	if (a>=8 && a<=9)
      	{
      	  x=a-1;
      	  z=a-2;
      	  if (matGioc [x][b]==0 && matGioc [z][b]==0)
      	  {
      	  	a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
            a=a-1;  //decremento la riga per farla tornare al punto originale */
	      	  while (cont<3){
	      	    a=a-1;
	      	    if (matGioc [a][b]==0)
	            {
	              if (b==0)
	              {
		      		matGioc [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			        if(b==9)
						{
							matGioc [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
						else
						{
						  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
	                      matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matGioc [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}

				  }

	            }
	            cont++;
	          }
	          a=a-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
              matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
          }
          else
          {
          	SetColor(4);
          	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
          	SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		  }
		}
		else
		{
		  x=a+1;
      	  z=a+2;
      	  if (matGioc [x][b]==0 && matGioc [z][b]==0)
      	  {
      	  	a=a-1;  //decremento la riga per farla tornare al punto originale
			matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
			a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
			  while (cont<3){
			    a=a+1;
	      	    if (matGioc [a][b]==0)
	            {
	              if (b==0)
			      	{
			      		matGioc [a][b]=1; //stampo valore originale;
		                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                b=b-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(b==9)
						{
							matGioc [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matGioc [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
	    	    }
	    	    cont++;
	          }
	        a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
            trov=1;
		  }
		  else
		  {
		  	SetColor(4);
		  	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		  	SetColor(15);
		  	matGioc [a][b]=0;
          	trov=0;
		  }
	  }
     }
	  else
     {
	    if (b>=8 && b<=9)
      	{
      	  x=b-1;
      	  z=b-2;
      	  if (matGioc [a][x]==0 && matGioc [a][z]==0)
      	  {
      	  b=b+1;
      	  if (b<=9)
      	  {
      	  	  matGioc [a][b]=3;
      	      b=b-1;
		  }
      	  else
      	  {
      	  	  b=b-1;
		  }
      	  while (cont<3){
      	    b=b-1;
      	    if (matGioc [a][b]==0)
            {
	           if (a==0)
	              {
		      		matGioc [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			      	if(a==9)
						{
							matGioc [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					 else
					 {
					 	  a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matGioc [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
					 }

				  }
            }
            cont++;
            }
            b=b-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
		  }
		  else
		  {
		  	SetColor(4);
		  	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		  	SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		  }
	    }
		else
		{
		  x=b+1;
      	  z=b+2;
      	  if (matGioc [a][x]==0 && matGioc [a][z]==0)
      	  {
      	  b=b-1;  //decremento la riga per farla tornare al punto originale
      	  if (b>=0)
      	  {
      	  	  matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		      b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		  }
		  else
		  {
		      b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
	      }
		  while (cont<3){
		    b=b+1;
      	    if (matGioc [a][b]==0)
            {
	          if (a==0)
			      	{
			      		matGioc [a][b]=1; //stampo valore originale;
		                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                a=a-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(a==9)
						{
							matGioc [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matGioc [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
    	    }
    	    cont++;
    	  }
    	  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
          matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
	      trov=1;
		}
		else
		{
			SetColor(4);
		    printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		    SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		}
      }
  }
}
}


void Nave_Giocatore_4Posti (int matGioc [][10]){
	int succ,esito,a,b,cont,trov,trovato,z,x,y,dim,ok;
	char c,cestino;
    dim=10;
	printf ("\n BARCA A 4 POSTI \n");
    printf (" VALORI DA 0 A 9 \n");
    trov=0;
    while (trov==0)
    {
    trovato=0;
    while (trovato==0){
    	ok=0;
    	while (ok==0)
    	{
    		scanf ("%c",&cestino);
    		printf (" INSERIRE CORDINATE COLONNA: ");
			scanf ("%c",&c);
			printf (" INSERIRE COORDINATE RIGA: ");
			scanf ("%d",&b);
			a= trasformazione(c);
			if (a<0 || a>9 || b<0 || b>9)
			{
				printf ("\n");
				SetColor(4);
				printf ("\n ATTENZIONE: INSERIRE VAOLORI COMPRESI TRA 'A' e 'L' PER LE COLONNE E TRA 0 e 9 PER LE RIGHE  \n");
				SetColor(15);
				ok=0;
			}
			else
			{
				ok=1;
			}
		}
			printf ("\n");
			printf ("                  INSERIRE VERSO DELLA NAVE \n");
			ok=0;
			while (ok==0)
			{
				printf("\n");
				printf("           ORIZZONTALE--> 0      VERTICALE--> 1  ");
				scanf("%d", &succ);
				if (succ>1 || succ<0)
				{
					SetColor(4);
					printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
					SetColor(15);
					ok=0;
				}
				else
				{
					ok=1;
				}
			}
			if (succ==0)
			{
			  if (matGioc [a][b]==0)
		      {
		      	if (b==0)
		      	{
		      		matGioc [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
				{
					if(b==9)
					{
						matGioc [a][b]=1; //stampo valore originale;
	                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                    b=b+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                b=b-1;  //decremento la riga per farla tornare al punto originale
			            matGioc [a][b]=1; //stampo valore originale;
			            b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			            b=b+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       SetColor(4);
		       printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		       SetColor(15);
		       trovato=0;
			  }
			}
			else
			{
				if (matGioc [a][b]==0)
		      {
		      	if (a==0)
		      	{
		      		matGioc [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
			    {
			    	if(a==9)
					{
						matGioc [a][b]=1; //stampo valore originale;
	                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                    a=a+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                a=a-1;  //decremento la riga per farla tornare al punto originale
			            matGioc [a][b]=1; //stampo valore originale;
			            a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			            a=a+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       SetColor(4);
		       printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		       SetColor(15);
		       trovato=0;
			  }
			}
	}
      cont=1;
      y=0;
      x=0;
      z=0;
	  printf ("\n");
	  srand(time(NULL));
      if (succ==0)
      {
      	if (a>=7 && a<=9)
      	{
      	  x=a-1;
      	  z=a-2;
      	  y=a-3;
      	  if (matGioc [x][b]==0 && matGioc [z][b]==0 && matGioc [y][b]==0)
      	  {
      	  	a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
            a=a-1;  //decremento la riga per farla tornare al punto originale */
	      	  while (cont<4){
	      	    a=a-1;
	      	    if (matGioc [a][b]==0)
	            {
	              if (b==0)
	              {
		      		matGioc [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			        if(b==9)
						{
							matGioc [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
						else
						{
						  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
	                      matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matGioc [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}

				  }

	            }
	            cont++;
	          }
	          a=a-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
              matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
          }
          else
          {
          	SetColor(4);
          	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
          	SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		  }
		}
		else
		{
		  x=a+1;
      	  z=a+2;
      	  y=a+3;
      	  if (matGioc [x][b]==0 && matGioc [z][b]==0 && matGioc [y][b]==0)
      	  {
      	  	a=a-1;  //decremento la riga per farla tornare al punto originale
			matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
			a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
			  while (cont<4){
			    a=a+1;
	      	    if (matGioc [a][b]==0)
	            {
	              if (b==0)
			      	{
			      		matGioc [a][b]=1; //stampo valore originale;
		                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                b=b-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(b==9)
						{
							matGioc [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matGioc [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
	    	    }
	    	    cont++;
	          }
	        a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
            trov=1;
		  }
		  else
		  {
		  	SetColor(4);
		  	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		  	SetColor(15);
		  	matGioc [a][b]=0;
          	trov=0;
		  }
	  }
     }
	  else
     {
	    if (b>=7 && b<=9)
      	{
      	  x=b-1;
      	  z=b-2;
      	  y=b-3;
      	  if (matGioc [a][x]==0 && matGioc [a][z]==0 && matGioc [a][y]==0)
      	  {
      	  b=b+1;
      	  if (b<=9)
      	  {
      	  	  matGioc [a][b]=3;
      	      b=b-1;
	      }
      	  else
      	  {
      	  	b=b-1;
		  }
      	  while (cont<4){
      	    b=b-1;
      	    if (matGioc [a][b]==0)
            {
	           if (a==0)
	              {
		      		matGioc [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			      	if(a==9)
						{
							matGioc [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					 else
					 {
					 	  a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matGioc [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
					 }

				  }
            }
            cont++;
            }
            b=b-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
		  }
		  else
		  {
		  	SetColor(4);
		  	printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		  	SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		  }
	    }
		else
		{
		  x=b+1;
      	  z=b+2;
      	  y=b+3;
      	  if (matGioc [a][x]==0 && matGioc [a][z]==0 && matGioc [a][y]==0)
      	  {
      	  b=b-1;  //decremento la riga per farla tornare al punto originale
      	  if (b>=0)
      	  {
      	  	  matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		      b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		  }
		  else
		  {
		  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
      	  }
		  while (cont<4){
		    b=b+1;
      	    if (matGioc [a][b]==0)
            {
	          if (a==0)
			      	{
			      		matGioc [a][b]=1; //stampo valore originale;
		                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                a=a-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(a==9)
						{
							matGioc [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matGioc [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matGioc [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
    	    }
    	    cont++;
    	  }
    	  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
          matGioc [a][b]=3; //aggiungo sopra al primo valore il 3
	      trov=1;
		}
		else
		{
			SetColor(4);
		    printf("\n ATTENZIONE: COORDINATA OCCUPATA! \n");
		    SetColor(15);
          	matGioc [a][b]=0;
          	trov=0;
		}
      }
  }
}
}


void Turno_Navi_Computer (int matComp [][10]){
	printf ("-------------------------INSERIMENTO NAVI COMPUTER--------------------------- \n");
	int i;
	Nave_Computer_4Posti (matComp);
	i=0;
	while (i<3)
	{
		Nave_Computer_2Posti (matComp);
		i=i+1;
	}
	i=0;
	while (i<2)
	{
		Nave_Computer_3Posti (matComp);
		i=i+1;
    }
   	i=0;
	while (i<4)
	{
		Nave_Computer_1Posto (matComp);
		i=i+1;
	}
    printf("\n");
	printf("\n                        INSERIMENTO NAVI COMPUTER COMPLETATO \n");
	printf("\n");
}


void Nave_Computer_1Posto (int matComp [][10]){
	int trovato,a,b;
	printf ("\n BARCA A 1 POSTO INSERITA\n");
    trovato=0;
    srand(time(NULL));
    while (trovato==0){
		    a=rand()%10;
            b=rand()%10;
			if (matComp [a][b]==0)
		      {
		      		matComp [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                if (b<=9)
	                {
	                	matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                    b=b-1;  //decremento la riga per farla ritornare al punto originale
					}
	                else
	                {
	                	b=b-1;
					}
	                a=a+1;
	                matComp [a][b]=3;
	                a=a-1;
	                b=b-1;
	                if (b>=0)
	                {
	                	matComp [a][b]=3;
	                    b=b+1;
					}
	                else
	                {
	                	b=b+1;
					}
	                a=a-1;
	                matComp [a][b]=3;
	                a=a+1;
			        trovato=1;
			  }
		    else
		      {
			       trovato=0;
			  }
   }
}


void Nave_Computer_2Posti (int matComp [][10]){
	int succ,esito,a,b,cont,trov,trovato,z,dim;
    dim=10;
	printf ("\n BARCA A DUE POSTI INSERITA \n");
    trov=0;
    srand(time(NULL));
    while (trov==0)
    {
    trovato=0;
    while (trovato==0){
	    	a=rand()%10;
	        b=rand()%10;
	        succ=rand()%2;
			if (succ==0)
			{
			  if (matComp [a][b]==0)
		      {
		      	if (b==0)
		      	{
		      		matComp [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
				{
					if(b==9)
					{
						matComp [a][b]=1; //stampo valore originale;
	                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                    b=b+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                b=b-1;  //decremento la riga per farla tornare al punto originale
			            matComp [a][b]=1; //stampo valore originale;
			            b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			            b=b+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       trovato=0;
			  }
			}
			else
			{
				if (matComp [a][b]==0)
		      {
		      	if (a==0)
		      	{
		      		matComp [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
			    {
			    	if(a==9)
					{
						matComp [a][b]=1; //stampo valore originale;
	                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                    a=a+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                a=a-1;  //decremento la riga per farla tornare al punto originale
			            matComp [a][b]=1; //stampo valore originale;
			            a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			            a=a+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       trovato=0;
			  }
			}
	}
      cont=1;
      z=0;
	  srand(time(NULL));
      if (succ==0)
      {
      	if (a<=9)
      	{
      	  z=a-1;
      	  if (matComp [z][b]==0)
      	  {
      	  	a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
      	  	if (a<=9)
      	    {
      	    	matComp [a][b]=3; //aggiungo sopra al primo valore il 3
                a=a-1;  //decremento la riga per farla tornare al punto originale */
			}
            else
			{
                a=a-1;  //decremento la riga per farla tornare al punto originale */
            }
	      	  while (cont<2){
	      	    a=a-1;
	      	    if (matComp [a][b]==0)
	            {
	              if (b==0)
	              {
		      		matComp [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			        if(b==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
						else
						{
						  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
	                      matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}

				  }

	            }
	            cont++;
	          }
	          a=a-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
              matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
          }
          else
          {
          	matComp [a][b]=0;
          	trov=0;
		  }
		}
		else
		{
      	  z=a+1;
      	  if (matComp [z][b]==0)
      	  {
      	  	a=a-1;  //decremento la riga per farla tornare al punto originale
			matComp [a][b]=3; //aggiungo sopra al primo valore il 3
			a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
			  while (cont<2){
			    a=a+1;
	      	    if (matComp [a][b]==0)
	            {
	              if (b==0)
			      	{
			      		matComp [a][b]=1; //stampo valore originale;
		                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                b=b-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(b==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
	    	    }
	    	    cont++;
	          }
	        a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matComp [a][b]=3; //aggiungo sopra al primo valore il 3
            trov=1;
		  }
		  else
		  {
		  	matComp [a][b]=0;
          	trov=0;
		  }
	  }
     }
	  else
     {
	    if (b<=9)
      	{
      	  z=b-1;
      	  if (matComp [a][z]==0)
      	  {
      	  b=b+1;
      	  if (b<=9)
      	  {
      	  	matComp [a][b]=3;
      	    b=b-1;
		  }
		  else
		  {
		  	b=b-1;
		  }
      	  while (cont<2){
      	    b=b-1;
      	    if (matComp [a][b]==0)
            {
	           if (a==0)
	              {
		      		matComp [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			      	if(a==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					 else
					 {
					 	  a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
					 }

				  }
            }
            cont++;
            }
            b=b-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
		  }
		  else
		  {
          	matComp [a][b]=0;
          	trov=0;
		  }
	    }
		else
		{
      	  z=b+1;
      	  if (matComp [a][z]==0)
      	  {
      	  b=b-1;  //decremento la riga per farla tornare al punto originale
		  if (b>=0)
      	  {
      	  	matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		    b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		  }
		  else
		  {
		  	b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		  }
		  while (cont<2){
		    b=b+1;
      	    if (matComp [a][b]==0)
            {
	          if (a==0)
			      	{
			      		matComp [a][b]=1; //stampo valore originale;
		                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                a=a-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(a==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
    	    }
    	    cont++;
    	  }
    	  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
          matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	      trov=1;
		}
		else
		{
          	matComp [a][b]=0;
          	trov=0;
		}
      }
  }
}
}


void Nave_Computer_3Posti (int matComp [][10]){
	int succ,esito,a,b,cont,trov,trovato,z,x,dim;
    dim=10;
	printf ("\n BARCA A 3 POSTI INSERITA \n");
    trov=0;
    srand(time(NULL));
    while (trov==0)
    {
    trovato=0;
    while (trovato==0){
		    a=rand()%10;
	        b=rand()%10;
	        succ=rand()%2;
			if (succ==0)
			{
			  if (matComp [a][b]==0)
		      {
		      	if (b==0)
		      	{
		      		matComp [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
				{
					if(b==9)
					{
						matComp [a][b]=1; //stampo valore originale;
	                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                    b=b+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                b=b-1;  //decremento la riga per farla tornare al punto originale
			            matComp [a][b]=1; //stampo valore originale;
			            b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			            b=b+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       trovato=0;
			  }
			}
			else
			{
				if (matComp [a][b]==0)
		      {
		      	if (a==0)
		      	{
		      		matComp [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
			    {
			    	if(a==9)
					{
						matComp [a][b]=1; //stampo valore originale;
	                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                    a=a+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                a=a-1;  //decremento la riga per farla tornare al punto originale
			            matComp [a][b]=1; //stampo valore originale;
			            a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			            a=a+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       trovato=0;
			  }
			}
	}
      cont=1;
      x=0;
      z=0;
	  srand(time(NULL));
      if (succ==0)
      {
      	if (a>=8 && a<=9)
      	{
      	  x=a-1;
      	  z=a-2;
      	  if (matComp [x][b]==0 && matComp [z][b]==0)
      	  {
      	  	a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            if (a<=9)
      	    {
      	    	matComp [a][b]=3; //aggiungo sopra al primo valore il 3
                a=a-1;  //decremento la riga per farla tornare al punto originale */
			}
            else
			{
                a=a-1;  //decremento la riga per farla tornare al punto originale */
            }
	      	  while (cont<3){
	      	    a=a-1;
	      	    if (matComp [a][b]==0)
	            {
	              if (b==0)
	              {
		      		matComp [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			        if(b==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
						else
						{
						  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
	                      matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}

				  }

	            }
	            cont++;
	          }
	          a=a-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
              matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
          }
          else
          {
          	matComp [a][b]=0;
          	trov=0;
		  }
		}
		else
		{
		  x=a+1;
      	  z=a+2;
      	  if (matComp [x][b]==0 && matComp [z][b]==0)
      	  {
      	  	a=a-1;  //decremento la riga per farla tornare al punto originale
			matComp [a][b]=3; //aggiungo sopra al primo valore il 3
			a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
			  while (cont<3){
			    a=a+1;
	      	    if (matComp [a][b]==0)
	            {
	              if (b==0)
			      	{
			      		matComp [a][b]=1; //stampo valore originale;
		                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                b=b-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(b==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
	    	    }
	    	    cont++;
	          }
	        a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matComp [a][b]=3; //aggiungo sopra al primo valore il 3
            trov=1;
		  }
		  else
		  {
		  	matComp [a][b]=0;
          	trov=0;
		  }
	  }
     }
	  else
     {
	    if (b>=8 && b<=9)
      	{
      	  x=b-1;
      	  z=b-2;
      	  if (matComp [a][x]==0 && matComp [a][z]==0)
      	  {
      	  b=b+1;
      	  if (b<=9)
      	  {
      	  	matComp [a][b]=3;
      	    b=b-1;
		  }
		  else
		  {
		  	b=b-1;
		  }
      	  while (cont<3){
      	    b=b-1;
      	    if (matComp [a][b]==0)
            {
	           if (a==0)
	              {
		      		matComp [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			      	if(a==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					 else
					 {
					 	  a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
					 }

				  }
            }
            cont++;
            }
            b=b-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
		  }
		  else
		  {
          	matComp [a][b]=0;
          	trov=0;
		  }
	    }
		else
		{
		  x=b+1;
      	  z=b+2;
      	  if (matComp [a][x]==0 && matComp [a][z]==0)
      	  {
      	  b=b-1;  //decremento la riga per farla tornare al punto originale
		  if (b>=0)
      	  {
      	  	matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		    b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		  }
		  else
		  {
		  	b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		  }
		  while (cont<3){
		    b=b+1;
      	    if (matComp [a][b]==0)
            {
	          if (a==0)
			      	{
			      		matComp [a][b]=1; //stampo valore originale;
		                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                a=a-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(a==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
    	    }
    	    cont++;
    	  }
    	  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
          matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	      trov=1;
		}
		else
		{
          	matComp [a][b]=0;
          	trov=0;
		}
      }
  }
}
}


void Nave_Computer_4Posti (int matComp [][10]){
	int succ,esito,a,b,cont,trov,trovato,z,x,y,dim;
    dim=10;
	printf ("\n BARCA A 4 POSTI INSERITA\n");
    trov=0;
    srand(time(NULL));
    while (trov==0)
    {
    trovato=0;
    while (trovato==0){
		    a=rand()%10;
	        b=rand()%10;
	        succ=rand()%2;
			if (succ==0)
			{
			  if (matComp [a][b]==0)
		      {
		      	if (b==0)
		      	{
		      		matComp [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
				{
					if(b==9)
					{
						matComp [a][b]=1; //stampo valore originale;
	                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                    b=b+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                b=b-1;  //decremento la riga per farla tornare al punto originale
			            matComp [a][b]=1; //stampo valore originale;
			            b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			            b=b+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       trovato=0;
			  }
			}
			else
			{
				if (matComp [a][b]==0)
		      {
		      	if (a==0)
		      	{
		      		matComp [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			    }
			    else
			    {
			    	if(a==9)
					{
						matComp [a][b]=1; //stampo valore originale;
	                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                    a=a+1;  //decremento la riga per farla ritornare al punto originale
			            trovato=1;
					}
					else
					{
						a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                a=a-1;  //decremento la riga per farla tornare al punto originale
			            matComp [a][b]=1; //stampo valore originale;
			            a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			            matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			            a=a+1;  //decremento la riga per farla ritornare al punto originale
					    trovato=1;
					}
				}
		      }
		      else
		      {
		       trovato=0;
			  }
			}
	}
      cont=1;
      y=0;
      x=0;
      z=0;
	  srand(time(NULL));
      if (succ==0)
      {
      	if (a>=7 && a<=9)
      	{
      	  x=a-1;
      	  z=a-2;
      	  y=a-3;
      	  if (matComp [x][b]==0 && matComp [z][b]==0 && matComp [y][b]==0)
      	  {
      	  	a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            if (a<=9)
      	    {
      	    	matComp [a][b]=3; //aggiungo sopra al primo valore il 3
                a=a-1;  //decremento la riga per farla tornare al punto originale */
			}
            else
			{
                a=a-1;  //decremento la riga per farla tornare al punto originale */
            }
	      	  while (cont<4){
	      	    a=a-1;
	      	    if (matComp [a][b]==0)
	            {
	              if (b==0)
	              {
		      		matComp [a][b]=1; //stampo valore originale;
	                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                b=b-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			        if(b==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
						else
						{
						  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
	                      matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}

				  }

	            }
	            cont++;
	          }
	          a=a-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
              matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
          }
          else
          {
          	matComp [a][b]=0;
          	trov=0;
		  }
		}
		else
		{
		  x=a+1;
      	  z=a+2;
      	  y=a+3;
      	  if (matComp [x][b]==0 && matComp [z][b]==0 && matComp [y][b]==0)
      	  {
      	  	a=a-1;  //decremento la riga per farla tornare al punto originale
			matComp [a][b]=3; //aggiungo sopra al primo valore il 3
			a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
			  while (cont<4){
			    a=a+1;
	      	    if (matComp [a][b]==0)
	            {
	              if (b==0)
			      	{
			      		matComp [a][b]=1; //stampo valore originale;
		                b=b+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                b=b-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(b==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    b=b+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  b=b-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          b=b-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              b=b+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
	    	    }
	    	    cont++;
	          }
	        a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matComp [a][b]=3; //aggiungo sopra al primo valore il 3
            trov=1;
		  }
		  else
		  {
		  	matComp [a][b]=0;
          	trov=0;
		  }
	  }
     }
	  else
     {
	    if (b>=7 && b<=9)
      	{
      	  x=b-1;
      	  z=b-2;
      	  y=b-3;
      	  if (matComp [a][x]==0 && matComp [a][z]==0 && matComp [a][y]==0)
      	  {
      	  b=b+1;
      	  if (b<=9)
      	  {
      	  	matComp [a][b]=3;
      	    b=b-1;
		  }
		  else
		  {
		  	b=b-1;
		  }
      	  while (cont<4){
      	    b=b-1;
      	    if (matComp [a][b]==0)
            {
	           if (a==0)
	              {
		      		matComp [a][b]=1; //stampo valore originale;
	                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
	                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
	                a=a-1;  //decremento la riga per farla ritornare al punto originale
			        trovato=1;
			      }
			      else
			      {
			      	if(a==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					 else
					 {
					 	  a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
					 }

				  }
            }
            cont++;
            }
            b=b-1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
            matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	        trov=1;
		  }
		  else
		  {
          	matComp [a][b]=0;
          	trov=0;
		  }
	    }
		else
		{
		  x=b+1;
      	  z=b+2;
      	  y=b+3;
      	  if (matComp [a][x]==0 && matComp [a][z]==0 && matComp [a][y]==0)
      	  {
      	  b=b-1;  //decremento la riga per farla tornare al punto originale
		  if (b>=0)
      	  {
      	  	matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		    b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		  }
		  else
		  {
		  	b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		  }
		  while (cont<4){
		    b=b+1;
      	    if (matComp [a][b]==0)
            {
	          if (a==0)
			      	{
			      		matComp [a][b]=1; //stampo valore originale;
		                a=a+1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                a=a-1;  //decremento la riga per farla ritornare al punto originale
				        trovato=1;
				    }
				    else
				    {
				      if(a==9)
						{
							matComp [a][b]=1; //stampo valore originale;
		                    a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
		                    matComp [a][b]=3; //aggiungo sotto al primo valore il 3
		                    a=a+1;  //decremento la riga per farla ritornare al punto originale
				            trovato=1;
						}
					  else
						{
					      a=a+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
		                  matComp [a][b]=3; //aggiungo sopra al primo valore il 3
		                  a=a-1;  //decremento la riga per farla tornare al punto originale
				          matComp [a][b]=1;
				          a=a-1;  //decremento ancora per aggiunger sotto al primo numero un valore di scudo
			              matComp [a][b]=3; //aggiungo sotto al primo valore il 3
			              a=a+1;  //decremento la riga per farla ritornare al punto originale
						}
				    }
    	    }
    	    cont++;
    	  }
    	  b=b+1; //incremento la riga per aggiungere sopra al primo numero un valore di scudo
          matComp [a][b]=3; //aggiungo sopra al primo valore il 3
	      trov=1;
		}
		else
		{
          	matComp [a][b]=0;
          	trov=0;
		}
      }
  }
}
}


int Giocare_Partita (int matGioc [][10], int matComp [][10], int prova [][10], int matAtt[][10]){
	int i,turno,esito,punti;
	punti=0;
	i=1;
	while (punti==0)
	{
		turno= Controllare_Giocatore (i);
		esito= Attaccare (turno,matGioc,matComp,prova,i,matAtt);
		punti= Aggiornare_Punteggio (esito,turno,matGioc, matComp);
		i=i+1;
	}
	return punti;
}


int Controllare_Giocatore (int i){
	int resto;
	resto=i;
	while (resto>=2)
	{
		resto=resto-2;
	}
	return resto;
}


int Attaccare (int turno, int matGioc [][10], int matComp [][10], int prova [][10], int i, int matAtt [][10]){
	int risultato,scelta,ok;
	if (turno==1)
	{
		risultato= Attacco_Giocatore (matComp,matGioc,i, matAtt);
	}
	else
	{
		risultato= Attacco_Computer (matGioc, prova,i);
		printf("\n Vuoi salvare? \n");
	    ok=0;
		while (ok==0)
		{
			printf("\n");
			printf("                            SI--> 1      NO--> 0  ");
			scanf("%d", &scelta);
			if (scelta>1 || scelta<0)
			{
				SetColor(4);
				printf("\n ATTENZIONE: INSERIRE SOLO VALORI 1 o 0 \n");
				SetColor(15);
				ok=0;
			}
			else
			{
				ok=1;
			}
		}
	    if (scelta==1)
		{
			salva (matGioc, matComp, matAtt, prova);
		}
	}
	return risultato;
}


int Attacco_Giocatore (int matComp [][10],int matGioc [][10], int i, int matAtt[][10]){
	printf ("\n");
	printf ("---------------------------TURNO %d ATTACCO GIOCATORE--------------------------- \n",i);
	printf ("\n");
	int a,b,esito,scelta,ok;
	char c,cestino;
	printf ("\n");
	printf ("\n              VUOI VISUALIZZARE I TUOI ATTACCHI E IL TUO CAMPO? \n");
	ok=0;
	while (ok==0)
	{
		printf("\n");
		printf("                            SI--> 1      NO--> 0  ");
		scanf("%d", &scelta);
		if (scelta>1 || scelta<0)
		{
			SetColor(4);
			printf("\n ATTENZIONE: INSERIRE VAOLORI COMPRESI TRA  0 e 1  \n");
			SetColor(15);
			ok=0;
		}
		else
		{
			ok=1;
		}
	}
	if (scelta==1)
	{
		Visualizza_campo_battaglia_Giocatore (matGioc);
		Visualizza_Campo_Attacchi_Giocatore (matAtt);
	}
      ok=0;
    	while (ok==0)
    	{
    		scanf ("%c",&cestino);
    		printf (" INSERIRE CORDINATE COLONNA: ");
			scanf ("%c",&c);
			printf (" INSERIRE COORDINATE RIGA: ");
			scanf ("%d",&b);
			a= trasformazione(c);
			if (a<0 || a>9 || b<0 || b>9)
			{
				printf ("\n");
				SetColor(4);
				printf("\n ATTENZIONE: INSERIRE VAOLORI COMPRESI TRA 'A' e 'L' PER LE COLONNE E TRA 0 e 9 PER LE RIGHE  \n");
				SetColor(15);
				ok=0;
			}
			else
			{
				ok=1;
			}
		}
	  printf ("\n");
	  if (matComp [a][b]==1)
	  {
	  	esito=1;
	    printf("\n ATTACCO GIOCATORE RIUSCITO \n");
	    printf ("\n");
	    matAtt [a][b]=1;
	    matComp [a][b]=0;
	  }
	  else
	  {
	    esito=0;
	    printf ("\n ATTACCO GIOCATORE FALLITO \n");
	    matAtt [a][b]=0;
	    printf ("\n");
      }
    return esito;
}


int Attacco_Computer (int matGioc [][10], int prova [][10],int i){
	int a,b,trovato,esito;
	printf ("\n");
	printf ("---------------------------TURNO %d ATTACCO COMPUTER--------------------------- \n",i);
	printf ("\n");
	trovato=0;
	srand(time(NULL));
      while (trovato==0)
      {
        a=rand()%10;
        b=rand()%10;
 	    printf ("\n");
	    if (prova [a][b]==0)
	    {
	      prova [a][b]=1;
	      trovato=1;
	    }
	    else
	    {
	      trovato=0;
        }
      }
      if (matGioc [a][b]==1)
      {
      	esito=1;
      	printf ("\n ATTACCO COMPUTER RIUSCITO \n");
      	printf ("\n");
      	matGioc [a][b]=0;
	  }
	  else
	  {
	  	esito=0;
	  	printf ("\n ATTACCO COMPUTER FALLITO \n");
	  	printf ("\n");
	  }
	  return esito;
}


int Aggiornare_Punteggio (int esito, int turno, int matComp [][10],int matGioc [][10]){
	int risultato,trovato;
	risultato=0;
	int i,j,dim;
	i=0;
	dim=10;
	if (turno==1)
	{
		trovato=1;
		while (i<dim){
			j=0;
			while(j<dim  && trovato==1){
				if (matGioc[j][i]==1)
				{
					risultato=0;
					trovato=0;
				}
				else
				{
					risultato=1;
				}
				j=j+1;
			}
			i=i+1;
		}
	}
	else
	{
		trovato=1;
		while (i<dim){
			j=0;
			while(j<dim  && trovato==1){
				if (matComp[j][i]==1)
				{
					risultato=0;
					trovato=0;
				}
				else
				{
					risultato=2;
				}
				j=j+1;
			}
			i=i+1;
		}
	}
	return risultato;
}


void Decretare_Vincitore(int esito){
	printf ("\n");
	printf ("-------------------------DECRETARE VINCITORE--------------------------- \n");
	printf ("\n");
	if (esito==1)
	{
		printf ("\n IL VINCIORE E' IL GIOCATORE \n ");
	}
	else
	{
		printf ("\n IL VINCIORE E' IL COMPUTER \n");
	}
}
