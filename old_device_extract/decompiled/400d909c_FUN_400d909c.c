// Function : FUN_400d909c
// Address  : 0x400d909c
// Size     : 1899 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d909c(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 ****ppppuVar11;
  char *pcVar12;
  undefined *puVar13;
  undefined8 uVar14;
  undefined4 ***local_64 [3];
  byte bStack_55;
  undefined4 ***local_54 [3];
  byte bStack_45;
  undefined1 auStack_44 [16];
  undefined4 ***local_34 [3];
  byte bStack_25;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400ec7a4(param_1," in SSL config",1,0);
  iVar5 = FUN_400ed024(param_1,"IVE",0);
  *(int *)(param_1 + 8) = iVar5;
  if (iVar5 == 1) {
    FUN_400f0be8(auStack_44,&DAT_3f42161d);
    FUN_400ed090(local_34,param_1,"nn_mode",auStack_44);
    FUN_400f0d60(param_1 + 0xc,local_34);
    FUN_400f0a50(local_34);
    FUN_400f0a50(auStack_44);
    FUN_400f0be8(auStack_44,&DAT_3f42161d);
    FUN_400ed090(local_34,param_1,"fi_ssid",auStack_44);
    FUN_400f0d60(param_1 + 0x1c,local_34);
    FUN_400f0a50(local_34);
    FUN_400f0a50(auStack_44);
    pcVar10 = "fi_pass";
LAB_400d9155:
    FUN_400f0780(0x3ffc5490,pcVar10);
  }
  else if (iVar5 == 2) {
    FUN_400f0be8(auStack_44,&DAT_3f42161d);
    FUN_400ed090(local_34,param_1,"uration",auStack_44);
    FUN_400f0d60(param_1 + 0x2c,local_34);
    FUN_400f0a50(local_34);
    FUN_400f0a50(auStack_44);
    pcVar10 = "ell_apn";
    goto LAB_400d9155;
  }
  uVar3 = FUN_400ed074(param_1,"already activated",0);
  *(undefined1 *)(param_1 + 0x104) = uVar3;
  FUN_400f0be8(auStack_44,&DAT_3f42161d);
  FUN_400ed090(local_34,param_1,"uration",auStack_44);
  FUN_400f0d60(param_1 + 0xf4,local_34);
  FUN_400f0a50(local_34);
  FUN_400f0a50(auStack_44);
  uVar3 = FUN_400ecfc4(param_1,"ver_url",0);
  *(undefined1 *)(param_1 + 0x70) = uVar3;
  uVar3 = FUN_400ecfc4(param_1,"ay_mode",0);
  *(undefined1 *)(param_1 + 0x71) = uVar3;
  uVar3 = FUN_400ecfc4(param_1,"ev_type",0x1a);
  *(undefined1 *)(param_1 + 0x72) = uVar3;
  uVar3 = FUN_400ed074(param_1,"trl_pin",1);
  *(undefined1 *)(param_1 + 0x73) = uVar3;
  uVar3 = FUN_400ed074(param_1,"low_ext",1);
  bVar1 = *(byte *)(param_1 + 0x70);
  *(undefined1 *)(param_1 + 0x74) = uVar3;
  pcVar10 = "MULATOR";
  if (bVar1 != 2) {
    if (bVar1 < 3) {
      pcVar10 = "LAY";
      if ((bVar1 != 0) && (pcVar10 = "", bVar1 != 1)) {
LAB_400d9262:
        pcVar10 = "_OPTION_UNKNOWN";
      }
    }
    else {
      pcVar10 = "H_RELAY";
      if (((bVar1 != 4) && (pcVar10 = "N_TIMER", 3 < bVar1)) &&
         (pcVar10 = &DAT_3f403c27, bVar1 != 5)) goto LAB_400d9262;
    }
  }
  FUN_400f06a4(0x3ffc5490,"ash_evt",pcVar10,*(undefined1 *)(param_1 + 0x71));
  cVar2 = *(char *)(param_1 + 0x70);
  if (cVar2 == '\0') {
    uVar6 = FUN_400ed300(param_1,"pe: %d\n",0x40000000);
    *(undefined4 *)(param_1 + 0x78) = uVar6;
    iVar5 = FUN_400ecff4(param_1,"edit_pp",0);
    iVar7 = FUN_400ecff4(param_1,"se_high",0);
    if ((iVar5 == 0) || (iVar7 == 0)) {
LAB_400d961c:
      uVar4 = FUN_400ecff4(param_1,"lse_low",0x32);
      *(undefined2 *)(param_1 + 0x7c) = uVar4;
      *(undefined2 *)(param_1 + 0x7e) = uVar4;
      *(undefined2 *)(param_1 + 0x80) = uVar4;
    }
    else {
      *(short *)(param_1 + 0x7e) = (short)iVar5;
      *(short *)(param_1 + 0x80) = (short)iVar7;
      *(short *)(param_1 + 0x7c) = (short)iVar5;
    }
LAB_400d92d8:
    uVar3 = FUN_400ecfc4(param_1,"lse_dur",0);
    *(undefined1 *)(param_1 + 0x82) = uVar3;
    uVar14 = (*(code *)&SUB_40002c34)(*(undefined4 *)(param_1 + 0x78));
    FUN_400f06a4(0x3ffc5490,"lse_pol",(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
    FUN_400f06a4(0x3ffc5490,": %.2f\n",*(undefined2 *)(param_1 + 0x7e),
                 *(undefined2 *)(param_1 + 0x80));
    pcVar12 = "";
    if (*(char *)(param_1 + 0x82) != '\0') {
      pcVar12 = "_ACTIVE";
    }
    pcVar10 = " %d ms\n";
  }
  else {
    if (cVar2 == '\x01') {
      uVar3 = FUN_400ecfc4(param_1,"ty: %s\n",0);
      *(undefined1 *)(param_1 + 0xd4) = uVar3;
      puVar8 = (undefined4 *)(param_1 + 0x84);
      for (uVar9 = 0; (uVar9 & 0xff) < (uint)*(byte *)(param_1 + 0xd4); uVar9 = uVar9 + 1) {
        if (uVar9 == 10) goto LAB_400d9442;
        FUN_400f0be8(local_34,"ce_size");
        FUN_400f0d90(auStack_44,uVar9,10);
        uVar6 = FUN_400f10c0(local_34,auStack_44);
        uVar6 = FUN_400f10f0(uVar6,"_price_");
        FUN_400f0d4c(local_64,uVar6);
        FUN_400f0a50(auStack_44);
        FUN_400f0a50(local_34);
        FUN_400f0be8(local_34,"ce_size");
        FUN_400f0d90(auStack_44,uVar9,10);
        uVar6 = FUN_400f10c0(local_34,auStack_44);
        uVar6 = FUN_400f10f0(uVar6,"ev_pulse_dur");
        FUN_400f0d4c(local_54,uVar6);
        FUN_400f0a50(auStack_44);
        FUN_400f0a50(local_34);
        ppppuVar11 = local_64;
        if ((bStack_55 & 0x80) == 0) {
          ppppuVar11 = (undefined4 ****)local_64[0];
        }
        uVar6 = FUN_400ed300(param_1,ppppuVar11,0);
        *puVar8 = uVar6;
        ppppuVar11 = local_54;
        if ((bStack_45 & 0x80) == 0) {
          ppppuVar11 = (undefined4 ****)local_54[0];
        }
        uVar6 = FUN_400ed04c(param_1,ppppuVar11,0);
        puVar8[1] = uVar6;
        FUN_400f0a50(local_54);
        FUN_400f0a50(local_64);
        puVar8 = puVar8 + 2;
      }
      pcVar10 = "econds\n";
      if (*(byte *)(param_1 + 0xd4) != 0) {
LAB_400d9442:
        FUN_400f06a4(0x3ffc5490,"e_");
        for (uVar9 = 0; uVar9 < *(byte *)(param_1 + 0xd4); uVar9 = uVar9 + 1 & 0xff) {
          iVar5 = param_1 + uVar9 * 8;
          uVar14 = (*(code *)&SUB_40002c34)(*(undefined4 *)(iVar5 + 0x84));
          FUN_400f06a4(0x3ffc5490,"tries:\n",(int)uVar14,(int)((ulonglong)uVar14 >> 0x20),
                       *(undefined4 *)(iVar5 + 0x88));
        }
        goto LAB_400d95b4;
      }
LAB_400d9711:
      FUN_400f0780(0x3ffc5490,pcVar10);
      goto LAB_400d95b4;
    }
    if (cVar2 == '\x02') {
      uVar4 = FUN_400ecff4(param_1,"igured!",200);
      *(undefined2 *)(param_1 + 0xd6) = uVar4;
      uVar6 = FUN_400ed300(param_1,"n_pulse",0x40c00000);
      *(undefined4 *)(param_1 + 0xd8) = uVar6;
      uVar3 = FUN_400ed074(param_1,"_credit",0);
      *(undefined1 *)(param_1 + 0xdc) = uVar3;
      uVar3 = FUN_400ecfc4(param_1,"_act_en",0xe);
      *(undefined1 *)(param_1 + 0xdd) = uVar3;
      uVar4 = FUN_400ecff4(param_1,"act_pin",3000);
      *(undefined2 *)(param_1 + 0xde) = uVar4;
      uVar4 = FUN_400ecff4(param_1,"t_estop",2000);
      *(undefined2 *)(param_1 + 0xe0) = uVar4;
      uVar3 = FUN_400ed074(param_1,"act_win",1);
      *(undefined1 *)(param_1 + 0xe2) = uVar3;
      uVar4 = FUN_400ecff4(param_1,"ct_alow",10000);
      *(undefined2 *)(param_1 + 0xe4) = uVar4;
      uVar4 = FUN_400ecff4(param_1,"f_grace",5000);
      *(undefined2 *)(param_1 + 0xe6) = uVar4;
      uVar4 = FUN_400ecff4(param_1,"enf_ack",20000);
      *(undefined2 *)(param_1 + 0xe8) = uVar4;
      uVar3 = FUN_400ecfc4(param_1,"nf_cool",3);
      *(undefined1 *)(param_1 + 0xea) = uVar3;
      FUN_400f06a4(0x3ffc5490,"enf_max",*(undefined2 *)(param_1 + 0xd6));
      uVar14 = (*(code *)&SUB_40002c34)(*(undefined4 *)(param_1 + 0xd8));
      FUN_400f06a4(0x3ffc5490," %d ms\n",(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
      pcVar10 = "ID_VERSION";
      if (*(char *)(param_1 + 0xdc) == '\0') {
        pcVar10 = "_ACTIVE";
      }
      puVar13 = &DAT_3f401ac9;
      if (*(char *)(param_1 + 0xe2) == '\0') {
        puVar13 = &DAT_3f401ace;
      }
      FUN_400f06a4(0x3ffc5490,": %.2f\n",pcVar10,*(undefined1 *)(param_1 + 0xdd),puVar13);
      FUN_400f06a4(0x3ffc5490,"w: %s)\n",*(undefined2 *)(param_1 + 0xe0));
      FUN_400f06a4(0x3ffc5490," %d ms\n",*(undefined2 *)(param_1 + 0xe4),
                   *(undefined2 *)(param_1 + 0xe6),*(undefined2 *)(param_1 + 0xe8),
                   *(undefined1 *)(param_1 + 0xea));
      goto LAB_400d95b4;
    }
    if (cVar2 == '\x03') {
      uVar6 = FUN_400ed300(param_1,"pe: %d\n",0x40000000);
      *(undefined4 *)(param_1 + 0x78) = uVar6;
      iVar5 = FUN_400ecff4(param_1,"edit_pp",0);
      iVar7 = FUN_400ecff4(param_1,"se_high",0);
      if ((iVar5 == 0) || (iVar7 == 0)) goto LAB_400d961c;
      *(short *)(param_1 + 0x7e) = (short)iVar5;
      *(short *)(param_1 + 0x80) = (short)iVar7;
      *(short *)(param_1 + 0x7c) = (short)iVar5;
      goto LAB_400d92d8;
    }
    if (cVar2 == '\x04') {
      uVar3 = FUN_400ecfc4(param_1,"max=%d\n",0x1a);
      *(undefined1 *)(param_1 + 0xeb) = uVar3;
      uVar3 = FUN_400ecfc4(param_1,"_mdb_rx",0x1b);
      *(undefined1 *)(param_1 + 0xec) = uVar3;
      uVar3 = FUN_400ecfc4(param_1,"_mdb_tx",0xd);
      *(undefined1 *)(param_1 + 0xed) = uVar3;
      uVar3 = FUN_400ecfc4(param_1,"mdb_prx",0x10);
      *(undefined1 *)(param_1 + 0xee) = uVar3;
      uVar4 = FUN_400ecff4(param_1,"db_addr",0x3c);
      *(undefined2 *)(param_1 + 0xf0) = uVar4;
      FUN_400f06a4(0x3ffc5490,"db_tout",*(undefined1 *)(param_1 + 0xeb),
                   *(undefined1 *)(param_1 + 0xec),*(undefined1 *)(param_1 + 0xed));
      FUN_400f06a4(0x3ffc5490,"in: %d\n",*(undefined1 *)(param_1 + 0xee));
      pcVar12 = (char *)(uint)*(ushort *)(param_1 + 0xf0);
      pcVar10 = "0x%02X\n";
    }
    else {
      pcVar10 = "%d sec\n";
      if (cVar2 != '\x05') goto LAB_400d9711;
      uVar3 = FUN_400ecfc4(param_1,"max=%d\n",0x1a);
      *(undefined1 *)(param_1 + 0xeb) = uVar3;
      uVar3 = FUN_400ecfc4(param_1,"_mdb_rx",0x1b);
      *(undefined1 *)(param_1 + 0xec) = uVar3;
      uVar4 = FUN_400ecff4(param_1,"db_addr",0x3c);
      *(undefined2 *)(param_1 + 0xf0) = uVar4;
      FUN_400f06a4(0x3ffc5490,"%d sec\n",*(undefined1 *)(param_1 + 0xeb),
                   *(undefined1 *)(param_1 + 0xec));
      FUN_400f06a4(0x3ffc5490,"in: %d\n");
      pcVar12 = (char *)(uint)*(ushort *)(param_1 + 0xf0);
      pcVar10 = "fixed)\n";
    }
  }
  FUN_400f06a4(0x3ffc5490,pcVar10,pcVar12);
LAB_400d95b4:
  iVar5 = 0x3ffc5490;
  if (*(char *)(param_1 + 0x104) == '\0') goto LAB_400d97da;
  FUN_400f0be8(auStack_44,&DAT_3f42161d);
  FUN_400ed090(local_34,param_1,"efaults",auStack_44);
  FUN_400f0d60(param_1 + 0x3c,local_34);
  FUN_400f0a50(local_34);
  FUN_400f0a50(auStack_44);
  uVar6 = FUN_400ed024(param_1,"_broker",0x22b3);
  *(undefined4 *)(param_1 + 0x4c) = uVar6;
  uVar3 = FUN_400ed074(param_1,"tt_port",1);
  *(undefined1 *)(param_1 + 0x50) = uVar3;
  uVar6 = FUN_400ed024(param_1,"qtt_tls",0x3c);
  *(undefined4 *)(param_1 + 100) = uVar6;
  uVar6 = FUN_400ed024(param_1,"epalive",300);
  *(undefined4 *)(param_1 + 0x68) = uVar6;
  FUN_400f0780(0x3ffc5490,"artbeat");
  iVar7 = FUN_400e6a84(0x3ffc4d78);
  if (iVar7 == 0) goto LAB_400d97da;
  FUN_400e6d7c(local_34,0x3ffc4d78);
  iVar7 = (*(code *)&LAB_40183a7b_1)(local_34);
  if (iVar7 == 0) goto LAB_400d97fd;
  FUN_400f0d18(param_1 + 0x54,local_34);
  ppppuVar11 = local_34;
  if ((bStack_25 & 0x80) == 0) {
    ppppuVar11 = (undefined4 ****)local_34[0];
  }
  FUN_400f06a4(0x3ffc5490,"uration",ppppuVar11);
  while( true ) {
    FUN_400f0a50(local_34);
LAB_400d97da:
    FUN_400ec888(param_1);
    iVar5 = iStack_24;
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400d97fd:
    FUN_400f0780(iVar5,"te: %s\n");
  }
  return;
}

