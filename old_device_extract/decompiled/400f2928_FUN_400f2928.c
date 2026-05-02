// Function : FUN_400f2928
// Address  : 0x400f2928
// Size     : 1236 bytes


int FUN_400f2928(uint param_1,int *param_2,uint param_3,byte param_4,byte param_5,uint param_6,
                uint param_7,char param_8,char param_9)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined4 uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  char cStack_28;
  undefined4 uStack_24;
  
  param_1 = param_1 & 0xff;
  if (2 < param_1) {
    uVar14 = func_0x40085c04();
    uVar3 = FUN_401847ec("t_intr)");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
    FUN_400f22b8("iled.\r\n",uVar4,uVar3,0x146,"uartEnd",2);
    return 0;
  }
  iVar10 = param_1 * 0x20;
  iVar7 = iVar10 + 0x3ffbdbd0;
  if (*(int *)(iVar10 + 0x3ffbdbd0) == 0) {
    iVar5 = func_0x4008fcd0(1);
    *(int *)(iVar10 + 0x3ffbdbd0) = iVar5;
    if (iVar5 == 0) {
      uVar14 = func_0x40085c04();
      uVar3 = FUN_401847ec("t_intr)");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
      FUN_400f22b8("to %u\r\n",uVar4,uVar3,0x150,"uartEnd");
      return 0;
    }
  }
  uVar6 = FUN_400f7cd0(param_1);
  if (uVar6 == 0) goto LAB_400f2a16;
  iVar5 = param_1 * 0x20;
  if ((((*(ushort *)(iVar5 + 0x3ffbdbe8) == param_6) && (*(ushort *)(iVar5 + 0x3ffbdbea) == param_7)
       ) && (*(char *)(iVar5 + 0x3ffbdbec) == param_8)) &&
     (*(char *)(iVar5 + 0x3ffbdbed) == param_9)) {
    if (*(int *)(iVar5 + 0x3ffbdbd0) != 0) {
      do {
        iVar12 = func_0x40090018(*(int *)(iVar5 + 0x3ffbdbd0),0xffffffff);
      } while (iVar12 != 1);
    }
    if (*(int **)(param_1 * 0x20 + 0x3ffbdbe0) == param_2) {
LAB_400f2b8c:
      if (((*(uint *)(param_1 * 0x20 + 0x3ffbdbe4) >> 2 & 3) != (param_3 >> 2 & 3)) &&
         (iVar5 = FUN_400f66d8(param_1), iVar5 != 0)) {
        uVar14 = (*(code *)&SUB_40085bfc)();
        uVar3 = FUN_401847ec("t_intr)");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        uVar13 = 0x16e;
        pcVar11 = "iled.\r\n";
        goto LAB_400f2b02;
      }
      if (((*(uint *)(param_1 * 0x20 + 0x3ffbdbe4) & 3) != (param_3 & 3)) &&
         (iVar5 = FUN_400f686c(param_1), iVar5 != 0)) {
        uVar14 = (*(code *)&SUB_40085bfc)();
        uVar3 = FUN_401847ec("t_intr)");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        uVar13 = 0x176;
        pcVar11 = "iled.\r\n";
        goto LAB_400f2b02;
      }
      if (((*(uint *)(param_1 * 0x20 + 0x3ffbdbe4) >> 4 & 0xc3) != (param_3 >> 4 & 3)) &&
         (iVar5 = FUN_400f6794(param_1), iVar5 != 0)) {
        uVar14 = (*(code *)&SUB_40085bfc)();
        uVar3 = FUN_401847ec("t_intr)");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        uVar13 = 0x17e;
        pcVar11 = "iled.\r\n";
        goto LAB_400f2b02;
      }
      *(uint *)(param_1 * 0x20 + 0x3ffbdbe4) = param_3;
    }
    else {
      iVar5 = FUN_400f6924(param_1,param_2);
      if (iVar5 == 0) {
        *(int **)(param_1 * 0x20 + 0x3ffbdbe0) = param_2;
        goto LAB_400f2b8c;
      }
      uVar14 = func_0x40085c04();
      uVar3 = FUN_401847ec("t_intr)");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
      pcVar11 = "rror.\r\n";
      uVar13 = 0x162;
LAB_400f2b02:
      FUN_400f22b8(pcVar11,uVar4,uVar3,uVar13,"uartEnd",param_1);
      uVar6 = 0;
    }
    iVar5 = (int)(char)param_4;
    uVar9 = uVar6 & (iVar5 >> 7) - (uint)param_4 >> 7 & 1;
    if ((uVar9 != 0) &&
       (iVar12 = (int)*(char *)(param_1 * 0x20 + 0x3ffbdbdc), uVar6 = uVar9, iVar12 != iVar5)) {
      bVar1 = FUN_400f22e0(param_1,iVar12,0xffffffff,0xffffffff);
      bVar2 = FUN_400f2488(param_1,iVar5,0xffffffff,0xffffffff);
      if ((bVar1 & bVar2) == 0) {
        uVar14 = (*(code *)&SUB_40085bfc)();
        uVar3 = FUN_401847ec("t_intr)");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        FUN_400f22b8("iled.\r\n",uVar4,uVar3,0x189,"uartEnd",param_1);
        uVar6 = 0;
      }
    }
    iVar5 = (int)(char)param_5;
    uVar9 = uVar6 & (iVar5 >> 7) - (uint)param_5 >> 7 & 1;
    if ((uVar9 != 0) &&
       (iVar12 = (int)*(char *)(param_1 * 0x20 + 0x3ffbdbdd), uVar6 = uVar9, iVar12 != iVar5)) {
      bVar1 = FUN_400f22e0(param_1,0xffffffff,iVar12,0xffffffff);
      bVar2 = FUN_400f2488(param_1,0xffffffff,iVar5,0xffffffff);
      if ((bVar1 & bVar2) == 0) {
        uVar14 = (*(code *)&SUB_40085bfc)();
        uVar3 = FUN_401847ec("t_intr)");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),1000,0);
        FUN_400f22b8("iled.\r\n",uVar4,uVar3,0x192,"uartEnd",param_1);
        uVar6 = 0;
      }
    }
    iVar5 = *(int *)(param_1 * 0x20 + 0x3ffbdbd0);
    if (iVar5 != 0) {
      func_0x4008fac0(iVar5,0,0);
    }
    if (uVar6 != 0) {
      return iVar7;
    }
  }
  FUN_400f2888(param_1);
LAB_400f2a16:
  uStack_38 = param_3 >> 2 & 3;
  uStack_34 = param_3 & 3;
  uStack_30 = param_3 >> 4 & 3;
  uStack_2c = 0;
  cStack_28 = param_9;
  uStack_24 = 0;
  uStack_3c = FUN_400f1e1c(param_2);
  uVar6 = 0x3ffbdbd0;
  if (*(int *)(param_1 * 0x20 + 0x3ffbdbd0) != 0) {
    do {
      iVar5 = (*(code *)&SUB_40090010)(*(undefined4 *)(param_1 * 0x20 + 0x3ffbdbd0),0xffffffff);
    } while (iVar5 != 1);
  }
  iVar10 = FUN_400f7a48(param_1,param_6,param_7,0x14,iVar10 + 0x3ffbdbd8,0);
  if (iVar10 != 0) goto LAB_400f2d3e;
  iVar10 = FUN_400f7124(param_1,&uStack_3c);
  if (iVar10 != 0) goto LAB_400f2d3e;
  if (param_8 == '\0') goto LAB_400f2d79;
  iVar10 = FUN_400f69d4(param_1,0x24);
  cVar8 = iVar10 == 0;
  while( true ) {
    if (cVar8 == '\0') {
LAB_400f2d3e:
      cVar8 = '\0';
    }
    else {
      uVar6 = uVar6 + param_1 * 0x20;
      *(int **)(uVar6 + 0x10) = param_2;
      *(char *)(uVar6 + 0x1d) = param_9;
      *(uint *)(uVar6 + 0x14) = param_3;
      *(short *)(uVar6 + 0x1a) = (short)param_7;
      *(char *)(uVar6 + 0x1c) = param_8;
      *(short *)(uVar6 + 0x18) = (short)param_6;
      *(undefined1 *)(uVar6 + 5) = 0;
      *(undefined1 *)(uVar6 + 6) = 0;
    }
    param_3 = param_1 * 0x20;
    param_2 = (int *)(param_3 + 0x3ffbdbd0);
    if (*param_2 != 0) {
      (*(code *)&SUB_4008fab8)(*param_2,0,0);
    }
    if ((cVar8 != '\0') &&
       (iVar10 = FUN_400f26ac(param_1,(int)(char)param_4,(int)(char)param_5,0xffffffff),
       uVar6 = (uint)param_5, iVar10 != 0)) break;
    FUN_400f2888(param_1);
    (*(code *)&SUB_40085bfc)();
    FUN_401847ec("t_intr)");
    memw();
    param_1 = (uint)DAT_00000004;
    breakpoint(0x1000,0x400f2d76,1,0xf);
LAB_400f2d79:
    iVar10 = FUN_400f69d4(param_1,param_8);
    cVar8 = '\x01';
    if (iVar10 != 0) {
      cVar8 = param_8;
    }
  }
  FUN_400f21ac(iVar7);
  return iVar7;
}

