// Function : FUN_400e1b8c
// Address  : 0x400e1b8c
// Size     : 4750 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e1b8c(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  uint *puVar10;
  char *pcVar11;
  undefined4 ****ppppuVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined1 auStack_278 [8];
  undefined8 uStack_270;
  undefined8 uStack_268;
  undefined8 uStack_260;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined1 auStack_150 [8];
  undefined1 auStack_148 [40];
  undefined1 auStack_120 [8];
  undefined1 auStack_118 [40];
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 auStack_e8 [40];
  undefined1 auStack_c0 [16];
  undefined1 auStack_b0 [16];
  undefined1 auStack_a0 [16];
  undefined1 auStack_90 [16];
  undefined4 ***local_80 [3];
  byte bStack_71;
  undefined4 ***local_70 [3];
  byte bStack_61;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [4];
  undefined8 uStack_3c;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0be8(auStack_40,"e");
  *param_1 = 0;
  FUN_400f0d4c(param_1 + 1,auStack_40);
  param_1[5] = 0;
  FUN_400f0a50(auStack_40);
  FUN_400f0be8(auStack_40,"trieved");
  FUN_400e6d7c(auStack_50,0x3ffc4d78);
  FUN_400e15cc(param_1,auStack_40,auStack_50);
  FUN_400f0a50(auStack_50);
  FUN_400f0a50(auStack_40);
  FUN_400f0be8(auStack_40," failed");
  FUN_400e1680(param_1,auStack_40,"version");
  FUN_400f0a50(auStack_40);
  FUN_401845e4(auStack_278);
  FUN_400ec7a4(auStack_278," in SSL config",1,0);
  FUN_400d7378(auStack_150,0x1000,0);
  uVar13 = FUN_400e06e4(auStack_148);
  uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar5 = (undefined4)uVar13;
  uStack_270 = uVar13;
  iVar2 = FUN_400ecfa8(auStack_278,"IVE");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed024(auStack_278,"IVE",0);
    uVar4 = FUN_400dc9cc(uVar5,"IVE",uVar7);
    FUN_401840d4(uVar3,uVar4);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"nn_mode");
  if (iVar2 != 0) {
    FUN_400f0be8(auStack_40,&DAT_3f42161d);
    FUN_400ed090(auStack_c0,auStack_278,"nn_mode",auStack_40);
    uStack_f0 = FUN_400dc9cc(uVar5,"nn_mode",uVar7);
    uStack_ec = uVar7;
    FUN_40183db8(auStack_c0,uStack_f0,uVar7);
    FUN_400f0a50(auStack_c0);
    FUN_400f0a50(auStack_40);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"fi_ssid");
  if (iVar2 != 0) {
    FUN_400f0be8(auStack_40,&DAT_3f42161d);
    FUN_400ed090(auStack_b0,auStack_278,"fi_ssid",auStack_40);
    iVar2 = (*(code *)&LAB_40183a7b_1)(auStack_b0);
    pcVar11 = &DAT_3f42161d;
    if (iVar2 != 0) {
      pcVar11 = " update";
    }
    uVar3 = FUN_400dc9cc(uVar5,"fi_ssid",uVar7);
    FUN_400e0404(pcVar11,uVar3);
    FUN_400f0a50(auStack_b0);
    FUN_400f0a50(auStack_40);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"uration");
  if (iVar2 != 0) {
    FUN_400f0be8(auStack_40,&DAT_3f42161d);
    FUN_400ed090(auStack_a0,auStack_278,"uration",auStack_40);
    uStack_f0 = FUN_400dc9cc(uVar5,"uration",uVar7);
    uStack_ec = uVar7;
    FUN_40183db8(auStack_a0,uStack_f0,uVar7);
    FUN_400f0a50(auStack_a0);
    FUN_400f0a50(auStack_40);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"already activated");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed074(auStack_278,"already activated",0);
    uStack_258 = FUN_400dc9cc(uVar5,"already activated",uVar7);
    uStack_254 = uVar7;
    FUN_40183f38(uVar3,uStack_258,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"uration");
  if (iVar2 != 0) {
    FUN_400f0be8(auStack_40,&DAT_3f42161d);
    FUN_400ed090(auStack_90,auStack_278,"uration",auStack_40);
    uStack_f0 = FUN_400dc9cc(uVar5,"uration",uVar7);
    uStack_ec = uVar7;
    FUN_40183db8(auStack_90,uStack_f0,uVar7);
    FUN_400f0a50(auStack_90);
    FUN_400f0a50(auStack_40);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"efaults");
  if (iVar2 != 0) {
    FUN_400f0be8(auStack_40,&DAT_3f42161d);
    FUN_400ed090(local_80,auStack_278,"efaults",auStack_40);
    uStack_f0 = FUN_400dc9cc(uVar5,"efaults",uVar7);
    uStack_ec = uVar7;
    FUN_40183db8(local_80,uStack_f0,uVar7);
    FUN_400f0a50(local_80);
    FUN_400f0a50(auStack_40);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"_broker");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed024(auStack_278,"_broker",0x22b3);
    uVar4 = FUN_400dc9cc(uVar5,"_broker",uVar7);
    FUN_401840d4(uVar3,uVar4);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"tt_port");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed074(auStack_278,"tt_port",1);
    uStack_250 = FUN_400dc9cc(uVar5,"tt_port",uVar7);
    uStack_24c = uVar7;
    FUN_40183f38(uVar3,uStack_250,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"qtt_tls");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed024(auStack_278,"qtt_tls",0x3c);
    uVar4 = FUN_400dc9cc(uVar5,"qtt_tls",uVar7);
    FUN_401840d4(uVar3,uVar4);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"epalive");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed024(auStack_278,"epalive",300);
    uVar4 = FUN_400dc9cc(uVar5,"epalive",uVar7);
    FUN_401840d4(uVar3,uVar4);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"ver_url");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"ver_url",0);
    uStack_248 = FUN_400dc9cc(uVar5,"ver_url",uVar7);
    uStack_244 = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_248,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"ay_mode");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"ay_mode",0);
    uStack_240 = FUN_400dc9cc(uVar5,"ay_mode",uVar7);
    uStack_23c = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_240,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"ev_type");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"ev_type",0x20);
    uStack_238 = FUN_400dc9cc(uVar5,"ev_type",uVar7);
    uStack_234 = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_238,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"trl_pin");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed074(auStack_278,"trl_pin",1);
    uStack_230 = FUN_400dc9cc(uVar5,"trl_pin",uVar7);
    uStack_22c = uVar7;
    FUN_40183f38(uVar3,uStack_230,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"low_ext");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed074(auStack_278,"low_ext",1);
    uStack_228 = FUN_400dc9cc(uVar5,"low_ext",uVar7);
    uStack_224 = uVar7;
    FUN_40183f38(uVar3,uStack_228,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"pe: %d\n");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed300(auStack_278,"pe: %d\n",0x40000000);
    uVar4 = FUN_400dc9cc(uVar5,"pe: %d\n",uVar7);
    FUN_400e03bc(uVar3,uVar4);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"igured!");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"igured!",200);
    uStack_220 = FUN_400dc9cc(uVar5,"igured!",uVar7);
    uStack_21c = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_220,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"n_pulse");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed300(auStack_278,"n_pulse",0x40c00000);
    uVar4 = FUN_400dc9cc(uVar5,"n_pulse",uVar7);
    FUN_400e03bc(uVar3,uVar4);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"_credit");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed074(auStack_278,"_credit",0);
    uStack_218 = FUN_400dc9cc(uVar5,"_credit",uVar7);
    uStack_214 = uVar7;
    FUN_40183f38(uVar3,uStack_218,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"_act_en");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"_act_en",0xe);
    uStack_210 = FUN_400dc9cc(uVar5,"_act_en",uVar7);
    uStack_20c = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_210,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"act_pin");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"act_pin",3000);
    uStack_208 = FUN_400dc9cc(uVar5,"act_pin",uVar7);
    uStack_204 = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_208,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"t_estop");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"t_estop",2000);
    uStack_200 = FUN_400dc9cc(uVar5,"t_estop",uVar7);
    uStack_1fc = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_200,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"act_win");
  if (iVar2 != 0) {
    uVar3 = FUN_400ed074(auStack_278,"act_win",1);
    uStack_1f8 = FUN_400dc9cc(uVar5,"act_win",uVar7);
    uStack_1f4 = uVar7;
    FUN_40183f38(uVar3,uStack_1f8,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"ct_alow");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"ct_alow",10000);
    uStack_1f0 = FUN_400dc9cc(uVar5,"ct_alow",uVar7);
    uStack_1ec = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_1f0,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"f_grace");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"f_grace",5000);
    uStack_1e8 = FUN_400dc9cc(uVar5,"f_grace",uVar7);
    uStack_1e4 = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_1e8,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"enf_ack");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"enf_ack",20000);
    uStack_1e0 = FUN_400dc9cc(uVar5,"enf_ack",uVar7);
    uStack_1dc = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_1e0,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"nf_cool");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"nf_cool",3);
    uStack_1d8 = FUN_400dc9cc(uVar5,"nf_cool",uVar7);
    uStack_1d4 = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_1d8,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"lse_low");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"lse_low",0x32);
    uStack_1d0 = FUN_400dc9cc(uVar5,"lse_low",uVar7);
    uStack_1cc = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_1d0,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"edit_pp");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"edit_pp",0);
    uStack_1c8 = FUN_400dc9cc(uVar5,"edit_pp",uVar7);
    uStack_1c4 = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_1c8,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"se_high");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"se_high",0);
    uStack_1c0 = FUN_400dc9cc(uVar5,"se_high",uVar7);
    uStack_1bc = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_1c0,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"lse_dur");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"lse_dur",0);
    uStack_1b8 = FUN_400dc9cc(uVar5,"lse_dur",uVar7);
    uStack_1b4 = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_1b8,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"ty: %s\n");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"ty: %s\n",0);
    uStack_1b0 = FUN_400dc9cc(uVar5,"ty: %s\n",uVar7);
    uStack_1ac = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_1b0,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"max=%d\n");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"max=%d\n",0x1a);
    uStack_1a8 = FUN_400dc9cc(uVar5,"max=%d\n",uVar7);
    uStack_1a4 = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_1a8,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"_mdb_rx");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"_mdb_rx",0x1b);
    uStack_1a0 = FUN_400dc9cc(uVar5,"_mdb_rx",uVar7);
    uStack_19c = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_1a0,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"mdb_prx");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecfc4(auStack_278,"mdb_prx",0x10);
    uStack_198 = FUN_400dc9cc(uVar5,"mdb_prx",uVar7);
    uStack_194 = uVar7;
    (*(code *)&LAB_40183f5a_2)(uVar3,uStack_198,uVar7);
  }
  iVar2 = FUN_400ecfa8(auStack_278,"db_addr");
  if (iVar2 != 0) {
    uVar3 = FUN_400ecff4(auStack_278,"db_addr",0x3c);
    uStack_190 = FUN_400dc9cc(uVar5,"db_addr",uVar7);
    uStack_18c = uVar7;
    (*(code *)&LAB_401841eb_1)(uVar3,uStack_190,uVar7);
  }
  iVar2 = 0;
  do {
    FUN_400f0be8(auStack_40,"ce_size");
    FUN_400f0d90(auStack_50,iVar2,10);
    uVar5 = FUN_400f10c0(auStack_40,auStack_50);
    uVar5 = FUN_400f10f0(uVar5,"_price_");
    FUN_400f0d4c(local_80,uVar5);
    FUN_400f0a50(auStack_50);
    FUN_400f0a50(auStack_40);
    FUN_400f0be8(auStack_40,"ce_size");
    FUN_400f0d90(auStack_50,iVar2,10);
    uVar5 = FUN_400f10c0(auStack_40,auStack_50);
    uVar5 = FUN_400f10f0(uVar5,"ev_pulse_dur");
    FUN_400f0d4c(local_70,uVar5);
    FUN_400f0a50(auStack_50);
    FUN_400f0a50(auStack_40);
    ppppuVar12 = local_80;
    if ((bStack_71 & 0x80) == 0) {
      ppppuVar12 = (undefined4 ****)local_80[0];
    }
    iVar6 = FUN_400ecfa8(auStack_278,ppppuVar12);
    if (iVar6 != 0) {
      FUN_400f0d4c(auStack_60,local_80);
      uStack_3c = uVar13;
      FUN_400f0d4c(auStack_34,auStack_60);
      FUN_400f0a50(auStack_60);
      ppppuVar12 = local_80;
      if ((bStack_71 & 0x80) == 0) {
        ppppuVar12 = (undefined4 ****)local_80[0];
      }
      uVar7 = FUN_400ed300(auStack_278,ppppuVar12,0);
      uVar5 = (undefined4)uStack_3c;
      uVar14 = FUN_400e13a4(auStack_34);
      uStack_188 = uVar14;
      uStack_168 = uVar14;
      uVar5 = FUN_400e145c(uVar5,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uStack_3c._4_4_);
      FUN_400e03bc(uVar7,uVar5);
      FUN_400f0a50(auStack_34);
    }
    ppppuVar12 = local_70;
    if ((bStack_61 & 0x80) == 0) {
      ppppuVar12 = (undefined4 ****)local_70[0];
    }
    iVar6 = FUN_400ecfa8(auStack_278,ppppuVar12);
    if (iVar6 != 0) {
      FUN_400f0d4c(auStack_50,local_70);
      uStack_3c = uVar13;
      FUN_400f0d4c(auStack_34,auStack_50);
      FUN_400f0a50(auStack_50);
      ppppuVar12 = local_70;
      if ((bStack_61 & 0x80) == 0) {
        ppppuVar12 = (undefined4 ****)local_70[0];
      }
      uVar7 = FUN_400ed04c(auStack_278,ppppuVar12,0);
      uVar5 = (undefined4)uStack_3c;
      uVar14 = FUN_400e13a4(auStack_34);
      uStack_180 = uVar14;
      uStack_160 = uVar14;
      uVar5 = FUN_400e145c(uVar5,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uStack_3c._4_4_);
      FUN_401840f4(uVar7,uVar5);
      FUN_400f0a50(auStack_34);
    }
    FUN_400f0a50(local_70);
    iVar2 = iVar2 + 1;
    FUN_400f0a50(local_80);
  } while (iVar2 != 10);
  FUN_400ec888(auStack_278);
  FUN_400f0be8(auStack_40,"vice_id");
  FUN_400e1ad4(param_1,auStack_40,(undefined4)uStack_270,uStack_270._4_4_);
  FUN_400f0a50(auStack_40);
  FUN_400d7378(auStack_120,0x200,0);
  uStack_268 = FUN_400e06e4(auStack_118);
  uVar3 = (undefined4)((ulonglong)uStack_268 >> 0x20);
  uVar5 = (undefined4)uStack_268;
  uVar7 = FUN_400e966c(&DAT_3ffc516c);
  uStack_178 = FUN_400dc9cc(uVar5,"_config",uVar3);
  uStack_174 = uVar3;
  FUN_40183f38(uVar7,uStack_178,uVar3);
  iVar2 = FUN_400e966c(&DAT_3ffc516c);
  if (iVar2 != 0) {
    FUN_400e9690(&uStack_158,&DAT_3ffc516c);
    FUN_400f0598(local_70,&uStack_158);
    uStack_f0 = FUN_400dc9cc(uVar5,"nnected",uVar3);
    uStack_ec = uVar3;
    FUN_40183db8(local_70,uStack_f0,uVar3);
    FUN_400f0a50(local_70);
    cVar1 = FUN_400e979c(&DAT_3ffc516c);
    piVar8 = (int *)FUN_400dc9cc(uVar5,"wifi_ip",uVar3);
    if (piVar8 != (int *)0x0) {
      *piVar8 = (int)cVar1;
      *(byte *)(piVar8 + 2) = *(byte *)(piVar8 + 2) & 0x80 | 10;
      piVar8[1] = (int)cVar1 >> 0x1f;
    }
  }
  uVar7 = FUN_400da4f0(*param_2);
  uStack_170 = FUN_400dc9cc(uVar5,"fi_rssi",uVar3);
  uStack_16c = uVar3;
  FUN_40183f38(uVar7,uStack_170,uVar3);
  FUN_400f0be8(auStack_40,"nnected");
  FUN_400e1ad4(param_1,auStack_40,(undefined4)uStack_268,uStack_268._4_4_);
  FUN_400f0a50(auStack_40);
  FUN_400d7378(&uStack_f0,0x100,0);
  uStack_260 = FUN_400e06e4(auStack_e8);
  uVar7 = (undefined4)((ulonglong)uStack_260 >> 0x20);
  uVar5 = (undefined4)uStack_260;
  uVar9 = FUN_400f1a9c();
  puVar10 = (uint *)FUN_400dc9cc(uVar5,"_status",uVar7);
  if (puVar10 != (uint *)0x0) {
    *(byte *)(puVar10 + 2) = (byte)puVar10[2] & 0x80 | 8;
    *puVar10 = uVar9 / 1000;
    puVar10[1] = 0;
  }
  uVar3 = FUN_400efe4c(0x3ffc53f4);
  uVar4 = FUN_400dc9cc(uVar5,"ime",uVar7);
  FUN_401840f4(uVar3,uVar4);
  uVar3 = FUN_400efe5c(0x3ffc53f4);
  uVar4 = FUN_400dc9cc(uVar5,"",uVar7);
  FUN_401840f4(uVar3,uVar4);
  uVar13 = FUN_400efef4(0x3ffc53f4);
  uVar3 = (undefined4)((ulonglong)uVar13 >> 0x20);
  FUN_400f0f00(auStack_40,uVar3,(int)uVar13,uVar3,0x10);
  uStack_158 = FUN_400dc9cc(uVar5,"ee_heap",uVar7);
  uStack_154 = uVar7;
  FUN_40183db8(auStack_40,uStack_158,uVar7);
  FUN_400f0a50(auStack_40);
  uVar3 = FUN_400efe94(0x3ffc53f4);
  uVar5 = FUN_400dc9cc(uVar5,"chip_id",uVar7);
  FUN_400e0404(uVar3,uVar5);
  FUN_400f0be8(auStack_40,"ly file system");
  FUN_400e1ad4(param_1,auStack_40,(undefined4)uStack_260,uStack_260._4_4_);
  FUN_400f0a50(auStack_40);
  FUN_400d73a8(&uStack_f0);
  FUN_400d73a8(auStack_120);
  FUN_400d73a8(auStack_150);
  FUN_400ec8a0(auStack_278);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_40);
    do {
      thunk_FUN_401710d8(param_1);
      FUN_400f0a50(auStack_50);
      FUN_400f0a50(auStack_40);
      FUN_400e0700(param_1);
    } while( true );
  }
  return;
}

