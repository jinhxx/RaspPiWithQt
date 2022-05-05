#ifndef STARWARSPITCHS_H
#define STARWARSPITCHS_H
#define cL 129
#define cLS 139
#define dL 146
#define dLS 156
#define eL 163
#define fL 173
#define fLS 185
#define gL 194
#define gLS 207
#define aL 219
#define aLS 228
#define bL 232

#define c 261
#define cS 277
#define d 294
#define dS 311
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466

#define cH 523
#define cHS 554
#define dH 587
#define dHS 622
#define eH 659
#define fH 698
#define fHS 740
#define gH 784
#define gHS 830
#define aH 880
#define aHS 910
#define bH 933

#define mute 0

int starwars_note[] = {
    a, a, f, cH,
    a, f, cH, a, eH,
    eH, eH, fH, cH, gS,
    f, cH, a, aH, a,
    a, aH, gHS, gH, fHS,
    fH, fHS,
    mute,
    aS, dHS, dH,cHS,cH,
    b, cH,
    mute,
    f, gS, f, a, cH,
    a, cH, eH, aH, a,
    a, aH, gHS, gH, fHS,
    fH, fHS,
    mute,
    aS, dHS, dH, cHS,cH,
    b, cH,
    mute,
    f, gS, f, cH, a,
    f, c, a
};
int starwars_duration[] = {
    500, 500, 350, 150,
    500, 350, 150, 1000, 500,
    500, 500, 350, 150, 500,
    350, 150, 1000, 500, 350,
    150, 500, 250, 250, 125,
    125, 250,
    250,
    250, 500, 250, 250, 125,
    125, 250,
    250,
    125, 500, 375, 125, 500,
    375, 125, 1000, 500, 350,
    150, 500, 250, 250, 125,
    125, 250,
    250,
    250, 500, 250, 250, 125,
    125, 125,
    250,
    250, 500, 375, 125, 500,
    375, 125, 1000
};
#endif // STARWARSPITCHS_H
