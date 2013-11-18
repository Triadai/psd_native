#ifndef PSD_NATIVE_COMPOSE
#define PSD_NATIVE_COMPOSE

typedef struct AlphaValues {
  int mix;
  int dst;
} AlphaValues;

#define BLEND_CHANNEL(b, f, a) ((((b) << 8) + ((f) - (b)) * (a)) >> 8)

VALUE psd_native_compose_normal(VALUE self, VALUE fg, VALUE bg, VALUE opts);
VALUE psd_native_compose_darken(VALUE self, VALUE fg, VALUE bg, VALUE opts);
VALUE psd_native_compose_multiply(VALUE self, VALUE fg, VALUE bg, VALUE opts);
VALUE psd_native_compose_color_burn(VALUE self, VALUE r_fg, VALUE r_bg, VALUE opts);
PIXEL color_burn_foreground(PIXEL b, PIXEL f);
VALUE psd_native_compose_linear_burn(VALUE self, VALUE r_fg, VALUE r_bg, VALUE opts);
VALUE psd_native_compose_lighten(VALUE self, VALUE r_fg, VALUE r_bg, VALUE opts);
VALUE psd_native_compose_screen(VALUE self, VALUE r_fg, VALUE r_bg, VALUE opts);
VALUE psd_native_compose_color_dodge(VALUE self, VALUE r_fg, VALUE r_bg, VALUE opts);
PIXEL color_dodge_foreground(PIXEL b, PIXEL f);
VALUE psd_native_compose_linear_dodge(VALUE self, VALUE r_fg, VALUE r_bg, VALUE opts);

void calculate_alphas(uint32_t fg, uint32_t bg, VALUE *opts);
uint32_t calculate_opacity(VALUE *opts);
uint32_t blend_channel(uint32_t bg, uint32_t fg, uint32_t a);

#endif