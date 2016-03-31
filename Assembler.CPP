//--------------------------------------------------------------------------//
//     One pass assembler for vector processor based on VHDL-FPGA           //
//to produce HEX file which contains program code and vectors data elements.//
//--------------------------------------------------------------------------//

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<CONIO.H>
#include<stdlib.h>
#define MaxData 20

 unsigned long St2Lint( char *st) {

 char c;  unsigned long cd=0;

 for( int i=0 ; i < strlen(st)  ;i++ ) {
  c = st[i] ;
  if (c>=97 && c<=102) c-= 87 ;
  else  c-= 48 ;
  cd|= c ;
  cd<<= 4 ;
 }
 cd>>= 4 ;
 return (cd) ;
}


struct Data{
 char Name[16] ;
 int  Type ;  //1,DB   2,DW     4,DD
 int  Add ;
 int  N   ;
 unsigned int  A[64];
}D[MaxData];
unsigned long Code[85];
int CodeCount = 0 ;
int DataCount = 0 ;


void main(){
FILE *fp;   clrscr();
char OneLine[160],*Err,inst[10],reg[10];
int i,j=0,ind=0,flag=0; unsigned long shift=0,dis=0;
 clrscr();
 fp = fopen("EX1.txt","rt");  if(fp==NULL) printf("file failed");
 for(;;){
    Err = fgets(OneLine,160,fp);
    if( Err == NULL )break;
    if( isdigit( OneLine[0] )){
       ++Err;
      // code
      //extract the instructions
      for (i=4;OneLine[i]!=' ';i++) inst[i-4]=OneLine[i]; inst[i-4]=0;

       //VECTOR INSTRUCTIONS
	  if(!strcmp(inst,"vadd")) { Code[j]|=0x004eb000;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000400;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000008;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000010;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

			  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;
			  }


	       else if(!strcmp(inst,"vmov")) { Code[j]|=0x004e2000;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000400;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000008;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000010;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

			  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;
			  }

	       else if(!strcmp(inst,"vsub")) {  Code[j]|=0x004e4000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000400;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000008;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000010;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

			  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;
			  }


	       else if(!strcmp(inst,"vmul")) { Code[j]|=0x004e5400;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000400;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000008;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000010;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

			  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;
			  }

	       else if(!strcmp(inst,"vdot")) { Code[j]|=0x004e5000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000400;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000008;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000010;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

			  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;
			  }

	       else if(!strcmp(inst,"vsum")) { Code[j]|=0x004e7000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000400;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

			  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;
			  }

	       else if(!strcmp(inst,"vshl")) { Code[j]|=0x004e8000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		 while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg); shift<<=6;
			  Code[j]|=shift;
			  }

	       else if(!strcmp(inst,"vshr")) { Code[j]|=0x004e8800;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){

			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		 while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg); shift<<=6;
			  Code[j]|=shift;
			  }

	       else if(!strcmp(inst,"vrol")) { Code[j]|=0x004e9000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg); shift<<=6;
			  Code[j]|=shift;
			  }

	       else if(!strcmp(inst,"vror")) { Code[j]|=0x004e9800;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;
		      while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg); shift<<=6;
			  Code[j]|=shift;
			  }

	       else if(!strcmp(inst,"vload")) { Code[j]|=0x004e0000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		 while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000200;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
			  Code[j]|=dis;
			  dis=0;
		      }

	       else if(!strcmp(inst,"vstor")) { Code[j]|=0x004e1000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
	       while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg); shift<<=9;
			  Code[j]|=shift;


	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
	       while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;

		    }

	       else if(!strcmp(inst,"vdiv")) { Code[j]|=0x004ea000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000400;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000008;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000010;

		while(OneLine[i]==' '|| OneLine[i]==',') i++;

			  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"vreg1")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"vreg2")) Code[j]|=0x00000001;
			  else if(!strcmp(reg,"rreg")) Code[j]|=0x00000002;
			  }

	       else if(!strcmp(inst,"hlt"))  Code[j]|=0x00400000;

      //SCALOR INSTRUCTIONS /

	       else if(!strcmp(inst,"maskwork")) { Code[j]|=0x001f0000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0; shift=1;
			    shift=St2Lint(reg);
			    Code[j]|=shift;
		}
	       else if(!strcmp(inst,"mask")) { Code[j]|=0x001e0000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			    shift=St2Lint(reg);
			    Code[j]|=shift;
		}
	       else if(!strcmp(inst,"mesh"))  Code[j]|=0x00422000;
	       else if(!strcmp(inst,"star"))  Code[j]|=0x00433000;
	       else if(!strcmp(inst,"sstar")) Code[j]|=0xf0133000; ///????
	       else if(!strcmp(inst,"bus"))  Code[j]|=0x00411000;
	       else if(!strcmp(inst,"vsums"))  Code[j]|=0x00444000;
	       else if(!strcmp(inst,"ring"))  Code[j]|=0x00455000;

      //SCALOR INSTRUCTIONS / jump

	       else if(!strcmp(inst,"jmp")) { Code[j]|=0x00190000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }


	       else if(!strcmp(inst,"jz")) { Code[j]|=0x00191000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }
	       else if(!strcmp(inst,"jnz")) { Code[j]|=0x00192000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }
	       else if(!strcmp(inst,"jc")) { Code[j]|=0x00193000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }
	       else if(!strcmp(inst,"jnc")) { Code[j]|=0x00194000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }
	       else if(!strcmp(inst,"js")) { Code[j]|=0x00195000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }
	       else if(!strcmp(inst,"jns")) { Code[j]|=0x00196000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }
	       else if(!strcmp(inst,"jov")) { Code[j]|=0x00197000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }
	       else if(!strcmp(inst,"jnov")) { Code[j]|=0x00198000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }
	       else if(!strcmp(inst,"loop")) { Code[j]|=0x00199000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;
		  while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg);
			  Code[j]|=shift;
		    }


      //SCALOR INSTRUCTIONS / OTHER

	       else if(!strcmp(inst,"inc")) { Code[j]|=0x00100000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"sreg0")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"sreg1")) Code[j]|=0x00000100;
			  else if(!strcmp(reg,"sreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"sreg3")) Code[j]|=0x00000300;
			  else if(!strcmp(reg,"sreg4")) Code[j]|=0x00000400;
			  else if(!strcmp(reg,"sreg5")) Code[j]|=0x00000500;
			  else if(!strcmp(reg,"sreg6")) Code[j]|=0x00000600;
			  else if(!strcmp(reg,"sreg7")) Code[j]|=0x00000700;

		}
	       else if(!strcmp(inst,"dec")) { Code[j]|=0x00109000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"sreg0")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"sreg1")) Code[j]|=0x00000100;
			  else if(!strcmp(reg,"sreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"sreg3")) Code[j]|=0x00000300;
			  else if(!strcmp(reg,"sreg4")) Code[j]|=0x00000400;
			  else if(!strcmp(reg,"sreg5")) Code[j]|=0x00000500;
			  else if(!strcmp(reg,"sreg6")) Code[j]|=0x00000600;
			  else if(!strcmp(reg,"sreg7")) Code[j]|=0x00000700;
		}
	       else if(!strcmp(inst,"clr")) { Code[j]|=0x00112000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"sreg0")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"sreg1")) Code[j]|=0x00000100;
			  else if(!strcmp(reg,"sreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"sreg3")) Code[j]|=0x00000300;
			  else if(!strcmp(reg,"sreg4")) Code[j]|=0x00000400;
			  else if(!strcmp(reg,"sreg5")) Code[j]|=0x00000500;
			  else if(!strcmp(reg,"sreg6")) Code[j]|=0x00000600;
			  else if(!strcmp(reg,"sreg7")) Code[j]|=0x00000700;
		}
	       else if(!strcmp(inst,"not")) { Code[j]|=0x00118000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"sreg0")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"sreg1")) Code[j]|=0x00000100;
			  else if(!strcmp(reg,"sreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"sreg3")) Code[j]|=0x00000300;
			  else if(!strcmp(reg,"sreg4")) Code[j]|=0x00000400;
			  else if(!strcmp(reg,"sreg5")) Code[j]|=0x00000500;
			  else if(!strcmp(reg,"sreg6")) Code[j]|=0x00000600;
			  else if(!strcmp(reg,"sreg7")) Code[j]|=0x00000700;

		}

	       else if(!strcmp(inst,"add")) { Code[j]|=0x00121000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"sreg0")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"sreg1")) Code[j]|=0x00000100;
			  else if(!strcmp(reg,"sreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"sreg3")) Code[j]|=0x00000300;
			  else if(!strcmp(reg,"sreg4")) Code[j]|=0x00000400;
			  else if(!strcmp(reg,"sreg5")) Code[j]|=0x00000500;
			  else if(!strcmp(reg,"sreg6")) Code[j]|=0x00000600;
			  else if(!strcmp(reg,"sreg7")) Code[j]|=0x00000700;


	      while(OneLine[i]==' '|| OneLine[i]==',') i++;
	      while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=atol(reg); Code[j]|=shift;
	      }
	       else if(!strcmp(inst,"sub")) { Code[j]|=0x00129000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"sreg0")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"sreg1")) Code[j]|=0x00000100;
			  else if(!strcmp(reg,"sreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"sreg3")) Code[j]|=0x00000300;
			  else if(!strcmp(reg,"sreg4")) Code[j]|=0x00000400;
			  else if(!strcmp(reg,"sreg5")) Code[j]|=0x00000500;
			  else if(!strcmp(reg,"sreg6")) Code[j]|=0x00000600;
			  else if(!strcmp(reg,"sreg7")) Code[j]|=0x00000700;


	      while(OneLine[i]==' '|| OneLine[i]==',') i++;
	      while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=atol(reg); Code[j]|=shift;
	      }
	       else if(!strcmp(inst,"mov")) { Code[j]|=0x00133000;

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"sreg0")) Code[j]|=0x00000000;
			  else if(!strcmp(reg,"sreg1")) Code[j]|=0x00000100;
			  else if(!strcmp(reg,"sreg2")) Code[j]|=0x00000200;
			  else if(!strcmp(reg,"sreg3")) Code[j]|=0x00000300;
			  else if(!strcmp(reg,"sreg4")) Code[j]|=0x00000400;
			  else if(!strcmp(reg,"sreg5")) Code[j]|=0x00000500;
			  else if(!strcmp(reg,"sreg6")) Code[j]|=0x00000600;
			  else if(!strcmp(reg,"sreg7")) Code[j]|=0x00000700;

	      while(OneLine[i]==' '|| OneLine[i]==',') i++;
	      while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=atol(reg); Code[j]|=shift;
	      }
	     else if(!strcmp(inst,"inci")) {

	       while(OneLine[i]==' '|| OneLine[i]==',') i++;

		while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  if(!strcmp(reg,"index0")) {Code[j]|=0x001f8000; flag++;}
			  else if(!strcmp(reg,"index1")) Code[j]|=0x001c0000;
			  else if(!strcmp(reg,"index2")) Code[j]|=0x001c0000;
			  else if(!strcmp(reg,"index3")) Code[j]|=0x001c0000;
			  else if(!strcmp(reg,"index4")) Code[j]|=0x001c0000;
			  else if(!strcmp(reg,"index5")) Code[j]|=0x001c0000;
			  else if(!strcmp(reg,"index6")) Code[j]|=0x001c0000;
			  else if(!strcmp(reg,"index7")) Code[j]|=0x001c0000;

	      while(OneLine[i]==' '|| OneLine[i]==',') i++;
	      while(OneLine[i]!=' '){
			  reg[ind]=OneLine[i];
			  i++; ind++;
			  } reg[ind]=0;   ind=0;
			  shift=St2Lint(reg); Code[j]|=shift;
			  if(flag==1) {
			  dis+=shift;
			  flag--; }
	      }
	  j++;
    }
//------------------------------------------------------------
    else {
      //data
      if( OneLine[0] == ' ' || OneLine[0] == '\n')continue;
      for( i = 0; OneLine[i] != ' ' ; ++i)
	 D[DataCount].Name[i]=OneLine[i];
      D[DataCount].Name[i]=0;
      //switch
      switch(OneLine[15]){
	case 'b' : case 'B' :
		  D[DataCount].Type = 1 ; break ;
	case 'w' : case 'W' :
		  D[DataCount].Type = 2 ; break ;
	case 'd' : case 'D' :
		  D[DataCount].Type = 4 ; break ;
	default :;// error
      }
      char *T=OneLine+17 ,Temp;

      D[DataCount].N =0 ;
      if(DataCount==0)D[DataCount].Add=0;
      else            D[DataCount].Add=D[DataCount-1].Add+D[DataCount-1].Type*
				       D[DataCount-1].N;
	    for( i = 0 ;  ; ++i){
		int x ;
		 sscanf(T,"%x",&x) ;T+=4;

		 D[DataCount].A[i] = x ;
		 ++D[DataCount].N ;
		 sscanf(T,"%c",&Temp) ;T+=1;
		 if( Temp == ';' )break ;
		 if( Temp != ',' ){
		   printf(" Error 5 ");
		   break ;
		 }
      }
      ++DataCount;
    }
//---------------------------------------------------------
 } for(i=0;i<j;i++) {Code[i]|=0xf0000000;
		     printf("%lx \n",Code[i]);}
 fclose(fp);
 //Creating The Hex File-------------------------

    //converting data from 16-bit to 12-bit.
    unsigned int temp;
      for (i=0;i<DataCount;i++)
       for(int k=0;k<D[i].N-1;k+=2) {

	D[i].A[k]&=0x0fff;
	temp=D[i].A[k+1]<<12;
	D[i].A[k]|=temp;
	D[i].A[k+1]&=0x0ff0;
	D[i].A[k+1]>>=4;
       }
     //-------------------------------------------
    unsigned int *p,n;
    unsigned CEND1=0xf045,CEND2=0x0000,DEND1=0xefff,DEND2=0xffff;
    FILE *FH=fopen("VP.hex","w");
    if(FH==NULL) printf("VP HEX FAIL");
    //writing Code
    p=(unsigned int *) Code;
    for (i=0;i<j*2;i++)
     fprintf(FH,"0%04x\n",*p++);
     fprintf(FH,"0%04x\n",CEND2);
     fprintf(FH,"0%04x\n",CEND1);

    //writing data
    for (i=0;i<DataCount;i++)
     for(int k=0;k<D[i].N;k++){
	fprintf(FH,"0%04x\n",D[i].A[k]);
     }
    fprintf(FH,"0%04x\n",DEND2);
    fprintf(FH,"0%04x\n",DEND1);
   fclose(FH);
 //----------------------------------------------
 getch();
 // genrat .hex  .bin
}
