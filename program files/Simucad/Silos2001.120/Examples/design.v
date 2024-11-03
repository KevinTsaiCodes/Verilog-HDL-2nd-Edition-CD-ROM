/**************************************************************************
1998 Copyright Actel Corporation
**************************************************************************/

`timescale 1 ns/100 ps


module drink_machine(coin,clock,resetn,coke,pepsi,soft_drink,vendcoke,
        vendpepsi,vendsoft_drink);
input [1:0] coin;
input clock, resetn, coke, pepsi, soft_drink;
output  vendcoke, vendpepsi, vendsoft_drink;

    wire present_stateZ0Z_0, present_stateZ0Z_1, 
        present_stateZ0Z_2, N_45, N_46, N_47, clock_y, resetn_y, 
        coin_y_0, coin_y_1, coke_y, pepsi_y, soft_drink_y, N_60, 
        N_38, N_49, N_55, N_67, N_35_i_0, G_30_1, 
        present_state_4_0_3_0, G_32_1, GNDZ0, VCCZ0, 
        present_state_4_0_1_n_2, N_62_n, N_55_n;
    
    CM8 G_29_2(.D0(GNDZ0), .D1(coin_y_0), .D2(GNDZ0), .D3(GNDZ0), 
        .S00(resetn_y), .S01(VCCZ0), .S10(present_stateZ0Z_0), 
        .S11(present_stateZ0Z_1), .Y(N_49));
    INBUF coin_pad_0(.PAD(coin[0]), .Y(coin_y_0));
    CM8 G_35_n(.D0(VCCZ0), .D1(present_stateZ0Z_2), .D2(GNDZ0), 
        .D3(GNDZ0), .S00(resetn_y), .S01(VCCZ0), .S10(GNDZ0), 
        .S11(GNDZ0), .Y(N_55_n));
    INBUF soft_drink_pad(.PAD(soft_drink), .Y(soft_drink_y));
    GND GND(.Y(GNDZ0));
    CM8 present_state_4_0_2_0(.D0(GNDZ0), .D1(GNDZ0), .D2(VCCZ0), 
        .D3(N_62_n), .S00(N_60), .S01(coin_y_1), .S10(N_38), .S11(
        N_55_n), .Y(present_state_4_0_3_0));
    CM8 G_51(.D0(GNDZ0), .D1(present_stateZ0Z_0), .D2(GNDZ0), .D3(
        GNDZ0), .S00(coin_y_0), .S01(VCCZ0), .S10(GNDZ0), .S11(
        GNDZ0), .Y(N_35_i_0));
    INBUF resetn_pad(.PAD(resetn), .Y(resetn_y));
    CM8 G_42_n(.D0(VCCZ0), .D1(present_stateZ0Z_0), .D2(GNDZ0), 
        .D3(GNDZ0), .S00(resetn_y), .S01(VCCZ0), .S10(GNDZ0), 
        .S11(GNDZ0), .Y(N_62_n));
    CM8 G_53(.D0(VCCZ0), .D1(GNDZ0), .D2(GNDZ0), .D3(GNDZ0), .S00(
        present_stateZ0Z_1), .S01(VCCZ0), .S10(coin_y_0), .S11(
        GNDZ0), .Y(N_67));
    CM8 G_25_4(.D0(GNDZ0), .D1(present_stateZ0Z_0), .D2(GNDZ0), 
        .D3(GNDZ0), .S00(coke_y), .S01(N_60), .S10(pepsi_y), .S11(
        soft_drink_y), .Y(N_45));
    CM8 G_32_0(.D0(GNDZ0), .D1(VCCZ0), .D2(GNDZ0), .D3(N_67), 
        .S00(N_55), .S01(VCCZ0), .S10(coin_y_1), .S11(GNDZ0), .Y(
        G_32_1));
    OUTBUF vendsoft_drink_pad(.PAD(vendsoft_drink), .D(N_47));
    DFM7A present_state_0(.D0(VCCZ0), .D1(G_30_1), .D2(VCCZ0), 
        .D3(N_49), .S0(present_state_4_0_3_0), .S10(N_55_n), .S11(
        N_49), .CLR(VCCZ0), .CLK(clock_y), .Q(present_stateZ0Z_0));
    INBUF pepsi_pad(.PAD(pepsi), .Y(pepsi_y));
    CM8 G_30_0(.D0(GNDZ0), .D1(coin_y_0), .D2(GNDZ0), .D3(GNDZ0), 
        .S00(coin_y_1), .S01(VCCZ0), .S10(GNDZ0), .S11(GNDZ0), .Y(
        G_30_1));
    CM8 G_26_2_0(.D0(GNDZ0), .D1(present_stateZ0Z_0), .D2(GNDZ0), 
        .D3(GNDZ0), .S00(pepsi_y), .S01(N_60), .S10(soft_drink_y)
        , .S11(coke_y), .Y(N_46));
    CM8 G_27_2(.D0(GNDZ0), .D1(present_stateZ0Z_0), .D2(GNDZ0), 
        .D3(GNDZ0), .S00(soft_drink_y), .S01(N_60), .S10(pepsi_y)
        , .S11(coke_y), .Y(N_47));
    CM8 G_40(.D0(present_stateZ0Z_2), .D1(GNDZ0), .D2(GNDZ0), .D3(
        GNDZ0), .S00(present_stateZ0Z_1), .S01(VCCZ0), .S10(GNDZ0)
        , .S11(GNDZ0), .Y(N_60));
    VCC VCC(.Y(VCCZ0));
    INBUF coin_pad_1(.PAD(coin[1]), .Y(coin_y_1));
    OUTBUF vendpepsi_pad(.PAD(vendpepsi), .D(N_46));
    DFM7A present_state_2(.D0(N_55), .D1(VCCZ0), .D2(GNDZ0), .D3(
        VCCZ0), .S0(present_state_4_0_1_n_2), .S10(G_32_1), .S11(
        GNDZ0), .CLR(VCCZ0), .CLK(clock_y), .Q(present_stateZ0Z_2)
        );
    OUTBUF vendcoke_pad(.PAD(vendcoke), .D(N_45));
    CM8 G_54(.D0(VCCZ0), .D1(GNDZ0), .D2(GNDZ0), .D3(VCCZ0), .S00(
        coin_y_0), .S01(VCCZ0), .S10(present_stateZ0Z_0), .S11(
        GNDZ0), .Y(N_38));
    CM8 present_state_4_0_0_n_2(.D0(N_60), .D1(N_55), .D2(GNDZ0), 
        .D3(N_55), .S00(N_35_i_0), .S01(present_stateZ0Z_1), .S10(
        N_62_n), .S11(GNDZ0), .Y(present_state_4_0_1_n_2));
    DFM7A present_state_1(.D0(GNDZ0), .D1(G_32_1), .D2(G_32_1), 
        .D3(GNDZ0), .S0(present_stateZ0Z_1), .S10(N_35_i_0), .S11(
        coin_y_1), .CLR(VCCZ0), .CLK(clock_y), .Q(
        present_stateZ0Z_1));
    INBUF coke_pad(.PAD(coke), .Y(coke_y));
    INBUF clock_pad(.PAD(clock), .Y(clock_y));
    CM8 G_35(.D0(resetn_y), .D1(GNDZ0), .D2(GNDZ0), .D3(GNDZ0), 
        .S00(present_stateZ0Z_2), .S01(VCCZ0), .S10(GNDZ0), .S11(
        GNDZ0), .Y(N_55));
    
endmodule
