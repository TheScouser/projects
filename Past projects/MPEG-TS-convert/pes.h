
#define __af_length_mask 0xFF
#define __d_indicator_mask 0x80
#define __ra_indicator_mask 0x40
#define __esp_indicator_mask 0x20
#define __pcr_flag_mask 0x10
#define __opcr_flag_mask 0x08
#define __s_point_flag 0x04
#define __tp_data_mask 0x02
#define __af_extension_mask 0x01

#define __t_error_mask 0x80
#define __s_indicator_mask 0x40
#define __t_priority_mask 0x20
#define __sc_control_mask 0xC0
#define __af_control_mask 0x30
#define __c_control_mask 0x0f

struct ad_field{
	unsigned char af_length;
	unsigned char d_indicator;
	unsigned char ra_indicator;
	unsigned char esp_indicator;
	unsigned char pcr_flag;
	unsigned char opcr_flag;
	unsigned char s_point;
	unsigned char tp_data;
	unsigned char af_extension;



};

struct ad_field new_ad(){
	struct ad_field ad;
	ad.af_length;
	ad.d_indicator;
	ad.ra_indicator;
	ad.esp_indicator;
	ad.pcr_flag;
	ad.opcr_flag;
	ad.s_point;
	ad.tp_data;
	ad.af_extension;


	return ad;
}

struct pes{
	
	
	unsigned char t_error;
	unsigned char s_indicator;
	unsigned char t_priority;
	unsigned char pid;
	unsigned char sc_control;
	unsigned char af_control;
	unsigned char c_control;
};


struct pes new_pes(){
	
	struct pes packet;
	packet.t_error;
	packet.s_indicator;
	packet.t_priority;
	packet.sc_control;
	packet.af_control;
	packet.c_control;
	
	return packet;
}
