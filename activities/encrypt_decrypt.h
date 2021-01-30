#ifndef ENCRYPT_DECRYPT_H_INCLUDED
#define ENCRYPT_DECRYPT_H_INCLUDED

void en_de_crypt(int ec_dc_f){
    char ch;
	FILE *fpts, *fptt;
	fpts=fopen(ed_name, "r");
	fptt=fopen("temp.txt", "w");
	if(fptt==NULL){
		fptt = fopen(ed_name, "w");
	}
	while(1){
		ch=fgetc(fpts);
		if(ch==EOF){
			break;
		}
		else{
		    if (ec_dc_f == 0) //decrypt
                ch=ch-100;
            else            //encrypt
                ch=ch+100;
			fputc(ch, fptt);
		}
	}
	fclose(fpts);
	fclose(fptt);
	fpts=fopen(ed_name, "w");
	fptt=fopen("temp.txt", "r");
	while(1){
		ch=fgetc(fptt);
		if(ch==EOF){
			break;
		}
		else{
			fputc(ch, fpts);
		}
	}
	fclose(fptt);
	fclose(fpts);

}

#endif // ENCRYPT_DECRYPT_H_INCLUDED
