// Function : FUN_400e852c
// Address  : 0x400e852c
// Size     : 1777 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e852c(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 ****ppppuVar5;
  undefined4 ****ppppuVar6;
  int iVar7;
  undefined4 ****ppppuVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined4 uStack_80;
  undefined1 auStack_7c [8];
  undefined *puStack_74;
  undefined4 uStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  undefined1 auStack_60 [4];
  uint uStack_5c;
  uint uStack_58;
  undefined4 ***local_54 [3];
  byte bStack_45;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined4 ***local_34 [3];
  byte bStack_25;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_6c = *(uint *)(param_2 + 4);
  iVar7 = *(int *)(&DAT_3ffc51ac + param_1 * 4);
  uStack_64 = *(uint *)(param_3 + 4);
  uStack_80 = 0;
  uStack_68 = *(uint *)(param_4 + 4);
  if (param_1 == 1) {
    iVar2 = (*(code *)&LAB_40184e77_1)();
    if (iVar2 != 0) {
      uVar14 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
      uVar13 = 0x7e;
      pcVar12 = "x%04x\r\n";
      param_2 = iVar2;
      goto LAB_400e85aa;
    }
    iVar2 = FUN_401015ec(iVar7);
    if ((iVar2 != 0) && (iVar2 != 0x5005)) {
      uVar14 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
      uVar13 = 0x83;
      pcVar12 = "x%04x\r\n";
      param_2 = iVar2;
      goto LAB_400e85aa;
    }
    iVar2 = FUN_4010199c(iVar7,&uStack_6c);
    if (iVar2 == 0) {
      auStack_60[0] = 1;
      uStack_70 = *(undefined4 *)(param_4 + 4);
      puStack_74 = &DAT_3f40a508;
      cVar1 = FUN_401842e8(&puStack_74);
      if ((byte)(cVar1 - 0x18U) < 5) goto LAB_400e87fd;
      uVar14 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
      FUN_4012105c("x%04x\r\n",uVar4,uVar3,0x94,"noEvent");
      goto LAB_400e87dd;
    }
    uVar14 = func_0x40085c04();
    uVar3 = FUN_401847ec("02X%02X");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
    uVar13 = 0x88;
    param_2 = iVar2;
  }
  else {
    param_2 = FUN_40184e98(iVar7,&uStack_80);
    if (param_2 != 0) {
      uVar14 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
      pcVar12 = "or %s\r\n";
      uVar13 = 0x67;
      goto LAB_400e85aa;
    }
    param_2 = FUN_401015b0(iVar7);
    if ((param_2 != 0) && (param_2 != 0x5005)) {
      uVar14 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
      uVar13 = 0x6c;
      pcVar12 = "x%04x\r\n";
      goto LAB_400e85aa;
    }
    param_2 = FUN_4010199c(iVar7,&uStack_6c);
    if (param_2 == 0) {
      if (uStack_6c != 0) goto LAB_400e87e0;
      param_2 = FUN_401015c4(iVar7);
      if (param_2 == 0) goto LAB_400e87e0;
      uVar14 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
      uVar13 = 0x77;
      pcVar12 = "x%04x\r\n";
      goto LAB_400e85aa;
    }
    uVar14 = func_0x40085c04();
    uVar3 = FUN_401847ec("02X%02X");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
    uVar13 = 0x71;
  }
  pcVar12 = "x%04x\r\n";
LAB_400e85aa:
  do {
    FUN_4012105c(pcVar12,uVar4,uVar3,uVar13,"noEvent",param_2);
LAB_400e87e0:
    do {
      while( true ) {
        param_3 = iStack_24;
        iVar7 = _DAT_3ffc5708;
        memw();
        memw();
        if (iStack_24 == _DAT_3ffc5708) {
          return;
        }
        func_0x40082ecc();
LAB_400e87fd:
        uVar11 = uStack_68 >> 0x18 | uStack_68 << 0x18 | (uStack_68 & 0xff00) << 8 |
                 uStack_68 >> 8 & 0xff00;
        uVar9 = *(uint *)(param_5 + 4);
        uVar10 = uStack_6c >> 0x18 | uStack_6c << 0x18 | (uStack_6c & 0xff00) << 8 |
                 uStack_6c >> 8 & 0xff00;
        uVar9 = uVar9 >> 0x18 | uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00;
        if (uVar9 == 0) {
          uVar9 = uVar10 + 1;
        }
        uStack_58 = uVar9 + 10;
        uStack_5c = uVar9;
        if (((uVar9 ^ uVar10) & uVar11) == 0) break;
        uVar14 = func_0x40085c04();
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        uVar4 = FUN_401847ec("02X%02X");
        FUN_400f0598(local_44,param_2);
        ppppuVar8 = local_44;
        if ((bStack_35 & 0x80) == 0) {
          ppppuVar8 = (undefined4 ****)local_44[0];
        }
        FUN_400f058c(&puStack_74,
                     uVar9 >> 0x18 | uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00);
        FUN_400f0598(local_34,&puStack_74);
        ppppuVar5 = local_34;
        if ((bStack_25 & 0x80) == 0) {
          ppppuVar5 = (undefined4 ****)local_34[0];
        }
        FUN_4012105c(">240)\r\n",uVar3,uVar4,0xa3,"noEvent",ppppuVar8,ppppuVar5);
        FUN_400f0a50(local_34);
        ppppuVar8 = local_44;
LAB_400e8914:
        FUN_400f0a50(ppppuVar8);
LAB_400e87dd:
        param_2 = -1;
      }
      if (-uVar11 - 0xb <= ((uVar11 ^ 0xffffffff) & uVar9)) {
        uStack_5c = (uVar9 & uVar11) + 1;
        uStack_58 = (uVar9 & uVar11) + 0xb;
      }
      if ((uStack_5c <= uVar10) && (uVar10 <= uStack_58)) {
        uVar14 = func_0x40085c04();
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        uVar4 = FUN_401847ec("02X%02X");
        FUN_400f0598(local_54,param_2);
        ppppuVar8 = local_54;
        if ((bStack_45 & 0x80) == 0) {
          ppppuVar8 = (undefined4 ****)local_54[0];
        }
        FUN_400f058c(auStack_7c,
                     uStack_5c >> 0x18 | uStack_5c << 0x18 | (uStack_5c & 0xff00) << 8 |
                     uStack_5c >> 8 & 0xff00);
        FUN_400f0598(local_44,auStack_7c);
        ppppuVar5 = local_44;
        if ((bStack_35 & 0x80) == 0) {
          ppppuVar5 = (undefined4 ****)local_44[0];
        }
        FUN_400f058c(&puStack_74,
                     uStack_58 >> 0x18 | uStack_58 << 0x18 | (uStack_58 & 0xff00) << 8 |
                     uStack_58 >> 8 & 0xff00);
        FUN_400f0598(local_34,&puStack_74);
        ppppuVar6 = local_34;
        if ((bStack_25 & 0x80) == 0) {
          ppppuVar6 = (undefined4 ****)local_34[0];
        }
        FUN_4012105c("ubnet\r\n",uVar3,uVar4,0xb0,"noEvent",ppppuVar8,ppppuVar5,ppppuVar6);
LAB_400e8b38:
        FUN_400f0a50(local_34);
        FUN_400f0a50(local_44);
        ppppuVar8 = local_54;
        goto LAB_400e8914;
      }
      uVar9 = uStack_64 >> 0x18 | uStack_64 << 0x18 | (uStack_64 & 0xff00) << 8 |
              uStack_64 >> 8 & 0xff00;
      if (((((uVar10 ^ uVar9) & uVar11) == 0) && (uStack_5c <= uVar9)) && (uVar9 <= uStack_58)) {
        uVar14 = func_0x40085c04();
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        uVar4 = FUN_401847ec("02X%02X");
        FUN_400f0598(local_54,param_3);
        ppppuVar8 = local_54;
        if ((bStack_45 & 0x80) == 0) {
          ppppuVar8 = (undefined4 ****)local_54[0];
        }
        FUN_400f058c(auStack_7c,
                     uStack_5c >> 0x18 | uStack_5c << 0x18 | (uStack_5c & 0xff00) << 8 |
                     uStack_5c >> 8 & 0xff00);
        FUN_400f0598(local_44,auStack_7c);
        ppppuVar5 = local_44;
        if ((bStack_35 & 0x80) == 0) {
          ppppuVar5 = (undefined4 ****)local_44[0];
        }
        FUN_400f058c(&puStack_74,
                     uStack_58 >> 0x18 | uStack_58 << 0x18 | (uStack_58 & 0xff00) << 8 |
                     uStack_58 >> 8 & 0xff00);
        FUN_400f0598(local_34,&puStack_74);
        ppppuVar6 = local_34;
        if ((bStack_25 & 0x80) == 0) {
          ppppuVar6 = (undefined4 ****)local_34[0];
        }
        FUN_4012105c("- %s)\r\n",uVar3,uVar4,0xb8,"noEvent",ppppuVar8,ppppuVar5,ppppuVar6);
        goto LAB_400e8b38;
      }
      uStack_5c = uStack_5c >> 0x18 | uStack_5c << 0x18 | (uStack_5c & 0xff00) << 8 |
                  uStack_5c >> 8 & 0xff00;
      uStack_58 = uStack_58 >> 0x18 | uStack_58 << 0x18 | (uStack_58 & 0xff00) << 8 |
                  uStack_58 >> 8 & 0xff00;
      param_2 = FUN_401019b0(iVar7,1,0x32,auStack_60,0xc);
      if (param_2 != 0) {
        uVar14 = func_0x40085c04();
        uVar3 = FUN_401847ec("02X%02X");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        uVar13 = 0xd1;
        pcVar12 = "- %s)\r\n";
        goto LAB_400e85aa;
      }
      param_2 = FUN_401015d8(iVar7);
    } while (param_2 == 0);
    uVar14 = func_0x40085c04();
    uVar3 = FUN_401847ec("02X%02X");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
    uVar13 = 0xd6;
    pcVar12 = "x%04x\r\n";
  } while( true );
}

