// Function : FUN_400d885c
// Address  : 0x400d885c
// Size     : 1054 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d885c(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  char *pcVar5;
  undefined4 ****ppppuVar6;
  int *piVar7;
  undefined4 ****ppppuVar8;
  undefined8 uVar9;
  undefined1 auStack_118 [8];
  undefined1 auStack_110 [24];
  undefined1 auStack_f8 [16];
  undefined1 auStack_e8 [4];
  char cStack_e4;
  undefined4 ***local_64 [3];
  byte bStack_55;
  undefined4 ***local_54 [3];
  byte bStack_45;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  FUN_400d9b74(auStack_e8,*(undefined4 *)(param_1 + 8));
  puVar3 = (undefined1 *)0x3ffc5490;
  if (cStack_e4 == '\0') {
    if (*param_2 != 0) goto LAB_400d88b6;
    piVar7 = param_2 + 2;
    if ((*(byte *)((int)param_2 + 0x17) & 0x80) == 0) {
      piVar7 = (int *)param_2[2];
    }
    FUN_400f06a4(0x3ffc5490,"Exiting",param_2[1],piVar7);
    goto LAB_400d889c;
  }
  FUN_400f0be8(auStack_34,"GS %s)\n");
  FUN_400d70ac(local_44,param_1);
  uVar1 = FUN_400f10c0(auStack_34,local_44);
  FUN_400f0d4c(local_64,uVar1);
  FUN_400f0a50(local_44);
  FUN_400f0a50(auStack_34);
  FUN_400d7378(auStack_118,0x200,0);
  uVar1 = FUN_400d4db0(auStack_f8,"\n",auStack_110);
  FUN_400d6da8("urrency",uVar1);
  uVar1 = FUN_400d4db0(auStack_f8,"ncy",auStack_110);
  FUN_40183db8(local_64,uVar1,auStack_110);
  FUN_400f0be8(local_54,&DAT_3f42161d);
  if (*param_2 == 0) {
    uVar1 = FUN_400d4db0(auStack_f8,"tion_id",auStack_110);
    FUN_400d6da8("dev_btn_pulse",uVar1);
    uVar1 = FUN_400d4db0(auStack_f8,"ta.scan_method",auStack_110);
    FUN_400d6da8("on_mode",uVar1);
    iVar4 = param_2[1];
    piVar7 = (int *)FUN_400d4db0(auStack_f8,"de",auStack_110);
    if (piVar7 != (int *)0x0) {
      *(byte *)(piVar7 + 2) = *(byte *)(piVar7 + 2) & 0x80 | 8;
      *piVar7 = iVar4;
      piVar7[1] = 0;
    }
    uVar1 = FUN_400d4db0(auStack_f8,"e_count",auStack_110);
    FUN_40183db8(param_2 + 2,uVar1,auStack_110);
    FUN_400f0e0c(local_44,param_2[1],10);
    FUN_400f0d4c(auStack_34,local_44);
    uVar1 = FUN_400f10f0(auStack_34," Type");
    uVar1 = FUN_400f10c0(uVar1,param_2 + 2);
    uVar1 = FUN_400f10f0(uVar1,"se_type");
    FUN_400f0d18(local_54,uVar1);
  }
  else {
    uVar1 = FUN_400d4db0(auStack_f8,"tion_id",auStack_110);
    FUN_400d6da8("h_relay",uVar1);
    uVar1 = FUN_400d4db0(auStack_f8,"ta.scan_method",auStack_110);
    FUN_400d6da8("on_mode",uVar1);
    iVar4 = param_2[6];
    puVar2 = (undefined8 *)FUN_400d4db0(auStack_f8,"Invalid amount",auStack_110);
    if (puVar2 != (undefined8 *)0x0) {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) & 0x80 | 0xc;
      uVar9 = (*(code *)&SUB_40002c34)(iVar4);
      *puVar2 = uVar9;
    }
    uVar1 = FUN_400d4db0(auStack_f8," pulses",auStack_110);
    FUN_40183db8(param_2 + 7,uVar1,auStack_110);
    FUN_400f0e84(local_44,param_2[6],0);
    FUN_400f0d4c(auStack_34,local_44);
    uVar1 = FUN_400f10f0(auStack_34,"sh_type");
    uVar1 = FUN_400f10c0(uVar1,param_2 + 7);
    uVar1 = FUN_400f10f0(uVar1,") 0 ) ) )");
    FUN_400f0d18(local_54,uVar1);
  }
  FUN_400f0a50(auStack_34);
  FUN_400f0a50(local_44);
  FUN_400f0be8(local_44,&DAT_3f42161d);
  FUN_400d5948(auStack_f8,local_44);
  iVar4 = FUN_400da4f0(0x3ffc4218);
  if (iVar4 == 0) {
    FUN_400f06a4(0x3ffc5490,"nt: %s\n");
    ppppuVar6 = local_64;
    if ((bStack_55 & 0x80) == 0) {
      ppppuVar6 = (undefined4 ****)local_64[0];
    }
    FUN_400f06a4(0x3ffc5490,"nected\n",ppppuVar6);
    ppppuVar6 = local_54;
    if ((bStack_45 & 0x80) == 0) {
      ppppuVar6 = (undefined4 ****)local_54[0];
    }
    pcVar5 = "en: %s\n";
LAB_400d8c39:
    FUN_400f06a4(0x3ffc5490,pcVar5,ppppuVar6);
  }
  else {
    FUN_400f0be8(auStack_34,"");
    iVar4 = FUN_400db714(0x3ffc4218,auStack_34,local_44,0);
    FUN_400f0a50(auStack_34);
    if (iVar4 == 0) {
      ppppuVar6 = local_44;
      if ((bStack_35 & 0x80) == 0) {
        ppppuVar6 = (undefined4 ****)local_44[0];
      }
      pcVar5 = "D: %s)\n";
      goto LAB_400d8c39;
    }
    ppppuVar6 = local_54;
    if ((bStack_45 & 0x80) == 0) {
      ppppuVar6 = (undefined4 ****)local_54[0];
    }
    ppppuVar8 = local_64;
    if ((bStack_55 & 0x80) == 0) {
      ppppuVar8 = (undefined4 ****)local_64[0];
    }
    FUN_400f06a4(0x3ffc5490,"eceived",ppppuVar6,ppppuVar8);
  }
  FUN_400f0a50(local_44);
  FUN_400f0a50(local_54);
  FUN_400d73a8(auStack_118);
  FUN_400f0a50(local_64);
LAB_400d889c:
  while( true ) {
    param_2 = piStack_24;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    puVar3 = &DAT_3ffc5708;
LAB_400d88b6:
    uVar9 = (*(code *)&SUB_40002c34)(param_2[6]);
    piVar7 = param_2 + 7;
    if ((*(byte *)((int)param_2 + 0x2b) & 0x80) == 0) {
      piVar7 = (int *)param_2[7];
    }
    FUN_400f06a4(puVar3,"ulses)\n",(int)uVar9,(int)((ulonglong)uVar9 >> 0x20),piVar7);
  }
  return;
}

