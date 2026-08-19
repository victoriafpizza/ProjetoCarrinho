// Chassi Robô 4WD - versão 1
// Unidades: mm
// Modelo paramétrico original, inspirado no chassi 4WD de acrílico do projeto.

L = 250;
W = 150;
T = 4;
R = 12;
m3 = 3.4;

module rounded_rect(l, w, r) {
    hull() {
        for (x=[-l/2+r, l/2-r])
            for (y=[-w/2+r, w/2-r])
                translate([x,y]) circle(r=r, $fn=64);
    }
}

module slot(len, wid) {
    hull() {
        translate([-len/2+wid/2,0]) circle(d=wid, $fn=40);
        translate([ len/2-wid/2,0]) circle(d=wid, $fn=40);
    }
}

linear_extrude(height=T)
difference() {
    rounded_rect(L,W,R);

    // Furos de canto M3
    for (x=[-110,110])
        for (y=[-60,60])
            translate([x,y]) circle(d=m3,$fn=32);

    // Fixação universal para os quatro motores/suportes
    for (x=[-72,72])
        for (y=[-61,61]) {
            translate([x,y]) slot(24,4.2);
            translate([x-18,y]) circle(d=m3,$fn=32);
            translate([x+18,y]) circle(d=m3,$fn=32);
        }

    // Slots para bateria/abraçadeiras
    for (x=[-45,0,45])
        translate([x,0]) rotate(90) slot(34,5);

    // Malha universal para Arduino/Ponte H/eletrônica
    for (x=[-50,-25,0,25,50])
        for (y=[-30,30])
            translate([x,y]) circle(d=m3,$fn=32);

    // Sensor frontal
    for (y=[-20,20])
        translate([105,y]) circle(d=m3,$fn=32);

    // LEDs/suporte traseiro
    for (y=[-20,20])
        translate([-105,y]) circle(d=m3,$fn=32);
}
