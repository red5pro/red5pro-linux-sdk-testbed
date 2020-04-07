
#ifndef R5PRO_DEVICE_H_
#define R5PRO_DEVICE_H_

#include "r5pro_api.h"

#include <stdio.h>
#include <stdlib.h>
#include <linux/ioctl.h>
#include <linux/types.h>
#include <linux/v4l2-common.h>
#include <linux/v4l2-controls.h>
#include <linux/videodev2.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <string.h>

struct vfl2_device_context
{
	int file_desc;
	struct v4l2_format imageFormat;
	struct v4l2_buffer bufferinfo;
	struct v4l2_buffer queryBuffer;
	char* buffer0;
	uint32_t buf0_len;
	char* buffer1;
	uint32_t buf1_len;
	uint64_t frame_count;
	struct timeval first_timestamp;
	r5config config;
}vfl2_device_context;

uint64_t get_timestamp_ms();
void copy_format(r5config *copy, r5config *config_in);
void get_format_vfl2(r5config *copy);
uint32_t fill_buffer_vfl2(media_sample* sample);
uint32_t free_buffer_vfl2(media_sample* sample);
uint32_t get_device_count_vfl2();
uint32_t open_device_vfl2(r5config * config);
uint32_t close_device_vfl2();
void make_vfl2_device(r5device* vfl2_device);

#endif /* R5PRO_DEVICE_H_ */
