// Function : FUN_400e90f4
// Address  : 0x400e90f4
// Size     : 752 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400e90f4(undefined4 param_1,char *param_2,char *param_3,undefined1 param_4,int param_5,
                uint param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined *puStack_15c;
  undefined4 uStack_158;
  undefined *puStack_154;
  undefined4 uStack_150;
  undefined *puStack_14c;
  undefined4 uStack_148;
  undefined *puStack_144;
  undefined4 uStack_140;
  undefined1 auStack_13c [32];
  undefined1 auStack_11c [64];
  undefined4 uStack_dc;
  undefined1 uStack_d8;
  undefined1 auStack_d7 [6];
  undefined1 uStack_d1;
  undefined4 uStack_cc;
  undefined1 uStack_c8;
  undefined4 uStack_c4;
  undefined1 uStack_c0;
  undefined1 auStack_b0 [140];
  int iStack_24;
  
  memw();
  puVar6 = (undefined1 *)(param_6 & 0xff);
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400e8448(&DAT_3ffc516c,1);
  if (iVar1 == 0) {
    uVar9 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1000,0);
    pcVar7 = "iled!\r\n";
    uVar8 = 0xe3;
  }
  else if (((param_2 == (char *)0x0) || (*param_2 == '\0')) ||
          (uVar4 = func_0x4008c024(param_2), 0x20 < uVar4)) {
    uVar9 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1000,0);
    uVar8 = 0xe8;
    pcVar7 = "iled!\r\n";
  }
  else if ((param_3 == (char *)0x0) || (uVar4 = func_0x4008c024(param_3), uVar4 < 0x41)) {
    func_0x4008b538(auStack_13c,0,0x8c);
    uVar2 = _DAT_3ffbdb90;
    uStack_c8 = 0x81;
    uStack_c0 = 1;
    uStack_dc = _DAT_3ffc51c8;
    uStack_cc = _DAT_3ffc51c4;
    uStack_d1 = param_4;
    func_0x4008b538(auStack_d7,0,6);
    FUN_400e9050(auStack_13c,param_2,0x20);
    if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
      uStack_c4 = uVar2;
      FUN_400e9050(auStack_11c,param_3,0x40);
    }
    if (param_5 != 0) {
      uStack_d8 = 1;
      func_0x4008b3d8(auStack_d7,param_5,6);
    }
    iVar1 = FUN_40146ec4(0,auStack_b0);
    if (iVar1 == 0) {
      iVar1 = func_0x4008b344(auStack_b0,auStack_13c,0x8c);
      if (iVar1 != 0) goto LAB_400e92ba;
      iVar1 = FUN_400e90d8();
      if (iVar1 == 3) goto LAB_400e92a3;
      iVar1 = FUN_40146e58(0,auStack_13c);
      if (iVar1 == 0) goto LAB_400e9369;
      uVar9 = func_0x40085c04();
      uVar2 = FUN_401847ec("face_ip");
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1000,0);
      uVar8 = 0x109;
      goto LAB_400e9326;
    }
    uVar9 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1000,0);
    uVar8 = 0xf8;
    pcVar7 = "long!\r\n";
  }
  else {
    uVar9 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1000,0);
    uVar8 = 0xed;
    pcVar7 = "sing!\r\n";
  }
LAB_400e9146:
  FUN_4012105c(pcVar7,uVar3,uVar2,uVar8,"t");
  iVar1 = 4;
LAB_400e92a3:
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return iVar1;
  }
  func_0x40082ecc();
  puVar6 = &DAT_3ffc5708;
LAB_400e92ba:
  iVar1 = FUN_40146a64();
  if (iVar1 == 0) {
    iVar1 = FUN_40146e58(0,auStack_13c);
    if (iVar1 == 0) {
LAB_400e9369:
      if (DAT_3ffc51cc == '\0') goto LAB_400e937c;
      goto LAB_400e9372;
    }
    uVar9 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1000,0);
    uVar8 = 0x102;
LAB_400e9326:
    pcVar7 = "iled!\r\n";
  }
  else {
    uVar9 = func_0x40085c04();
    uVar2 = FUN_401847ec("face_ip");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1000,0);
    uVar8 = 0xfd;
    pcVar7 = "iled!\r\n";
  }
  goto LAB_400e9146;
LAB_400e937c:
  uStack_158 = _DAT_3ffc54e0;
  uStack_150 = _DAT_3ffc54e0;
  uStack_148 = _DAT_3ffc54e0;
  uStack_140 = _DAT_3ffc54e0;
  puStack_15c = &DAT_3f40a508;
  puStack_154 = &DAT_3f40a508;
  puStack_14c = &DAT_3f40a508;
  puStack_144 = &DAT_3f40a508;
  iVar5 = FUN_400e852c(0,&puStack_15c,&puStack_154,&puStack_14c,&puStack_144);
  iVar1 = 4;
  if (iVar5 != 0) goto LAB_400e92a3;
LAB_400e9372:
  if ((puVar6 == (undefined1 *)0x0) || (iVar1 = FUN_40146a1c(), iVar1 == 0)) {
    iVar1 = FUN_400e90d8();
    goto LAB_400e92a3;
  }
  uVar9 = func_0x40085c04();
  uVar2 = FUN_401847ec("face_ip");
  uVar3 = (*(code *)&SUB_4000cff8)((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1000,0);
  uVar8 = 0x116;
  pcVar7 = "iled!\r\n";
  goto LAB_400e9146;
}

