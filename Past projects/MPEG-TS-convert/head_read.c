#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "pes.h"
int main(int argc,char* argv[]){

	off_t file_size;		//total file size in bytes
	char *buffer;			//buffer for reading the file
	struct stat stbuf;		//stat for file
	int fd,fd2;					//input file
	int header_num=0;		//headers num
	int pes_size=188;		//PES size
	int z;					//inner counter
	int i;					//bytes read
	int range;				//range outside the buffer
	unsigned short int x;
	unsigned char section_number;
	unsigned char pid;
	unsigned char pat = 0xFF;
	unsigned char pmt_pid;
	unsigned char section;
	unsigned char pmt_section;
	unsigned char program_num;
	unsigned char program_info;
	unsigned char elem_pid;
	unsigned char stream_type;
	unsigned char pcr_pid;
	unsigned char es_info_length;
	unsigned char pmt_version;
	unsigned char pat_version;
	struct pes packet=new_pes();
	struct ad_field ad = new_ad();
	{
		/* data */
	};
	//0x47 sync byte (start of headers)
	unsigned char headers[]={0x47}; 
	
	
	fd = open(argv[1],O_RDWR);
	
	if (fd == -1) {
		printf("The file was not oppened correctly!\n");
		exit(-1);
	}
	
	fstat(fd, &stbuf);
	file_size = stbuf.st_size;
	
	
	
	buffer = (char*)malloc(sizeof(unsigned char)*4096);
	if (buffer == NULL) {
		printf("Error in allocating memory\n");
		exit(-1);
	}
	
	i=read(fd, buffer, sizeof(unsigned char)*4096);			
	z=0;
	while(i!=0){
		
		range=0;
		
		while(z<i){
			
			if((z+188)>4096){			//if the next header is in the next buffer
				range=(z+188)-4096;
				//printf("\n=%d=\n\n",header_num);
				break;
			}
			
			if(buffer[z]==headers[0] ){
				header_num++;
				//printf("-[%d]-\n",header_num);
				
				
					if(buffer[z+1] | pat){
						pid = ((buffer[z+1] & 0x1f) << 8) | buffer[z+2];
						if (buffer[z+1] & 0x80)
							continue;
						packet.pid=pid;
					
					}
					// printf("Header:\n");
					// printf("<0x%x>\n",buffer[z]);
					// printf("<0x%x>\n",buffer[z+1]);
					// printf("<0x%x>\n",buffer[z+2]);
					// printf("<0x%x>\n",buffer[z+3]);


					
					packet.t_error=((buffer[z+1] & __t_error_mask)>>7);
					packet.s_indicator=((buffer[z+1] & __s_indicator_mask)>>6);
					packet.t_priority=((buffer[z+1] & __t_priority_mask)>>5);
					
					packet.sc_control=((buffer[z+3] & __sc_control_mask)>>6);
					packet.af_control=((buffer[z+3] & __af_control_mask)>>4);
					packet.c_control=(buffer[z+3] & __c_control_mask);
						
					if(packet.af_control == 2 || packet.af_control == 3){
						ad.af_length = ((buffer[z+4] & __af_length_mask));
						ad.d_indicator = ((buffer[z+5] & __d_indicator_mask) >> 7);
						ad.ra_indicator= ((buffer[z+5] & __ra_indicator_mask) >> 6);
						ad.esp_indicator= ((buffer[z+5] & __esp_indicator_mask) >> 5);
						ad.pcr_flag = ((buffer[z+5] & __pcr_flag_mask ) >> 4);
						if(ad.pcr_flag == 1){

						}


					if(packet.pid == 0){
						printf("\n");
						printf("PACKET : %d\n", header_num);
						printf("\n");
						section = ((buffer[z+4+ad.af_length+3] & 0x03) << 8) | buffer[z+4+ad.af_length+4];
						printf("SECTION LENGTH: %d\n", section );


						pat_version = ((buffer[z+4+ad.af_length+7] & 0x3E) >> 1);
						printf("PAT Version Number: %d\n", pat_version);
						x = (buffer[z+4+ad.af_length+5]  << 8) | buffer[z+4+ad.af_length+6];
						printf("Transport stream ID: %x\n", x);

						x = (buffer[z+4+ad.af_length+10]  << 8) | buffer[z+4+ad.af_length+11];
						printf("PROGRAM NUMBER: %d\n", x);
						section_number = (buffer[z+4+ad.af_length+9] & 0xFF);
						printf("Section number: %d\n", section_number);
						int j = (section-9)/4;
						int k = 0;
						int l = 0;
						for(k = 0; k < j ;k++){
							pmt_pid = ((buffer[z+4+ad.af_length+12+l] & 0x1f) << 8) | buffer[z+4+ad.af_length+13+l];
							printf("PMT PID: %x\n", pmt_pid);
							printf("\n");
							l += 2;
						}
					}

					if(packet.pid == pmt_pid){

						pmt_section = ((buffer[z+4+ad.af_length+3] & 0x03) << 8) | buffer[z+4+ad.af_length+4];
						printf("Section length : %d\n", pmt_section );

						 pmt_version = ((buffer[z+4+ad.af_length+7] & 0x3E) >> 1);
						 printf("PMT Version Number: %d\n", pmt_version);

						pcr_pid = ((buffer[z+4+ad.af_length+10] & 0x1f) << 8) | buffer[z+4+ad.af_length+11];
						printf("PCRPID: %d\n", pcr_pid);

						program_info = ((buffer[z+4+ad.af_length+12] & 0x0f) << 8) | buffer[z+4+ad.af_length+13];
						printf("PROGRAM descriptors: %d\n", program_info);
						//program_info = program_info * 8;
						int j = pmt_section-13-program_info;
						int k = 0;
						int l = 0;
						
						
						do{
							stream_type = buffer[z+4+ad.af_length+13+program_info+1+l];
			
							printf("Stream type: %x\n", stream_type);
							elem_pid = ((buffer[z+4+ad.af_length+13+program_info+2+l] & 0x1F) <<8) | buffer[z+4+ad.af_length+13+program_info+3+l] ;
							printf("Elementary PID: %x\n", elem_pid);
							es_info_length= ((buffer[z+4+ad.af_length+13+program_info+4+l] & 0x03) <<8) | buffer[z+4+ad.af_length+13+program_info+5+l] ;
							l += 5+es_info_length;
							k++;
						}while( k < (j / (5+es_info_length)));
						
					}

						ad.opcr_flag = ((buffer[z+5] & __opcr_flag_mask ) >> 3);
						ad.s_point= ((buffer[z+5] & __s_point_flag ) >> 2);
						ad.tp_data= ((buffer[z+5] & __tp_data_mask ) >> 1);
						ad.af_extension= ((buffer[z+5] & __af_extension_mask ));
					}

				
				
			}else{
				printf("Error in sync byte\n");
				exit(1);	
			}
			
			
			z+=188;
		}
		
		int index=0;		//index from wich to copy
		int offset=0;		//if there needs to be offset in the buffer
		
		if(range!=0){
			index=188-range;
			index=4096-index;
			
			//printf("[%x]",buffer[index]);
			int index_start=0;
			for(;index<4096;index++){
				buffer[index_start]=buffer[index];
				index_start++;
			}
			offset=index_start;

		}
		
		
			//printf("[#(%x)#]\n",buffer[0]);
			//printf("[#(%x)#]\n",buffer[1]);
			//printf("[#(%x)#]\n",buffer[2]);
			//printf("[#(%x)#]\n",buffer[3]);
			
		
		i=read(fd, buffer+offset, (sizeof(unsigned char)*(4096-(offset*2))));
			//printf("[i = %d]\n",i);
			//printf("^^^[#(%x)#]\n",buffer[188+0]);
			//printf("^^^[#(%x)#]\n",buffer[188+1]);
			//printf("^^^[#(%x)#]\n",buffer[188+2]);
			//printf("^^^[#(%x)#]\n",buffer[188+3]);
			
		z=0;	//reset the counter
		
	}
	
	
	printf("header error = %x\n",packet.t_error);
	printf("header indicator = %x\n",packet.s_indicator);
	printf("header priority = %x\n",packet.t_priority);
	
	printf("header pid = %x\n",packet.pid);
	
	printf("header sc_control = %x\n",packet.sc_control);
	printf("header af_control = %x\n",packet.af_control);
	printf("header c_control = %x\n",packet.c_control);
	if(packet.af_control == 2 || packet.af_control == 3){
		printf("\n");
		printf("Adaptation field length = %d\n", ad.af_length);
		printf("Discontinuty counter = %x\n", ad.d_indicator);
		printf("Random access indicator = %x\n", ad.ra_indicator);
		printf("Elementary stream priority indicator = %x\n", ad.esp_indicator);
		printf("PCR flag = %x\n", ad.pcr_flag);
		printf("OPCR flag = %x\n", ad.opcr_flag);
		printf("Transport private data = %x\n", ad.tp_data);
		printf("Adaptation field extension = %x\n",ad.af_extension);
	}
	close(fd);
	
	return 0;
}
