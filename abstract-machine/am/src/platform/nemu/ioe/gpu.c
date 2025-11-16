#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
// int i;
//  int w =400;  // TODO: get the correct width
 //int h = 300;  // TODO: get the correct height
  //uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
 //for (i = 0; i < w * h; i ++) fb[i] = i;
// outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t screen_info = inl(VGACTL_ADDR);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = screen_info >> 16, .height = screen_info & 0xffff,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
 // if (!ctl->pixels) return; // 没有像素数据则直接返回
  
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  int screen_width = 400;
  
  // 将像素数据复制到显存的正确位置
  uint32_t *pixels = (uint32_t *)ctl->pixels;
  
  for (int y = 0; y < ctl->h; y++) {
    for (int x = 0; x < ctl->w; x++) {
      // 计算显存中的目标位置
      int fb_x = ctl->x + x;
      int fb_y = ctl->y + y;
      
      // 确保不越界
      if (fb_x >= 0 && fb_x < screen_width && fb_y >= 0 && fb_y < 300) {
        // 计算显存中的索引
        int fb_index = fb_y * screen_width + fb_x;
        // 计算源像素数据中的索引
        int pixels_index = y * ctl->w + x;
        
        // 复制像素数据
        fb[fb_index] = pixels[pixels_index];
      }
    }
  }
  
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
