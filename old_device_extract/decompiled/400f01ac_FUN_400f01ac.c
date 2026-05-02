// Function : FUN_400f01ac
// Address  : 0x400f01ac
// Size     : 674 bytes


void FUN_400f01ac(int param_1,uint param_2,undefined4 param_3,char param_4,char param_5,
                 undefined1 param_6,uint param_7,undefined1 param_8)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  uint uVar11;
  undefined8 uVar12;
  
  if (2 < *(byte *)(param_1 + 0x10)) {
    uVar12 = func_0x40085c04();
    uVar3 = FUN_401847ec("nternal");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),1000,0);
    FUN_4012105c("ated!\r\n",uVar4,uVar3,0x109,"sible\r\n",2);
    return;
  }
  if (*(int *)(param_1 + 0x48) == 0) {
    uVar12 = func_0x40085c04();
    uVar3 = FUN_401847ec("nternal");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),1000,0);
    FUN_4012105c("to %u\r\n",uVar4,uVar3,0x10f,"sible\r\n");
    return;
  }
  do {
    iVar5 = func_0x40090018(*(undefined4 *)(param_1 + 0x48),0xffffffff);
  } while (iVar5 != 1);
  iVar5 = FUN_400f1e3c(*(undefined4 *)(param_1 + 0x14));
  if (iVar5 == 0) {
    cVar1 = FUN_400f1df4(*(undefined1 *)(param_1 + 0x10));
    cVar2 = FUN_400f1e08(*(undefined1 *)(param_1 + 0x10));
    cVar10 = *(char *)(param_1 + 0x10);
    if (cVar10 == '\x01') {
      if ((-1 < param_4) || (-1 < param_5)) goto LAB_400f025a;
      param_4 = '\t';
      if (-1 < cVar1) {
        param_4 = cVar1;
      }
      cVar10 = '\n';
    }
    else if (cVar10 == '\0') {
      if ((-1 < param_4) || (-1 < param_5)) goto LAB_400f025a;
      param_4 = '\x03';
      if (-1 < cVar1) {
        param_4 = cVar1;
      }
      cVar10 = '\x01';
    }
    else {
      if (((cVar10 != '\x02') || (-1 < param_4)) || (-1 < param_5)) goto LAB_400f025a;
      param_4 = '\x10';
      if (-1 < cVar1) {
        param_4 = cVar1;
      }
      cVar10 = '\x11';
    }
    param_5 = cVar2;
    if (cVar2 < '\0') {
      param_5 = cVar10;
    }
  }
LAB_400f025a:
  uVar11 = param_2;
  if (param_2 == 0) {
    uVar11 = 0x2580;
  }
  iVar8 = (int)param_4;
  iVar9 = (int)param_5;
  iVar5 = FUN_400f1e50(*(undefined1 *)(param_1 + 0x10),uVar11,param_3,iVar8,iVar9,
                       *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),param_6,
                       param_8);
  if (iVar5 != 0) {
    FUN_400f0198(param_1);
  }
  iVar5 = FUN_400f2928(*(undefined1 *)(param_1 + 0x10),uVar11,param_3,iVar8,iVar9,
                       *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),param_6,
                       param_8);
  *(int *)(param_1 + 0x14) = iVar5;
  if (iVar5 == 0) {
    uVar12 = func_0x40085c04();
    uVar3 = FUN_401847ec("nternal");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),1000,0);
    FUN_4012105c("egin.\r\n",uVar4,uVar3,0x147,"sible\r\n");
  }
  else {
    if (param_2 == 0) {
      FUN_400f2e88();
      iVar5 = FUN_400f1a9c();
      while (iVar6 = FUN_400f1a9c(), (uint)(iVar6 - iVar5) < param_7) {
        iVar6 = FUN_400f2ec0(*(undefined4 *)(param_1 + 0x14));
        if (iVar6 != 0) {
          FUN_400f1ab4(100);
          iVar5 = FUN_400f2928(*(undefined1 *)(param_1 + 0x10),iVar6,param_3,iVar8,iVar9,
                               *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
                               param_6,param_8);
          *(int *)(param_1 + 0x14) = iVar5;
          if (iVar5 != 0) goto LAB_400f03c8;
          goto LAB_400f03dd;
        }
        FUN_400f1a60();
      }
      uVar12 = func_0x40085c04();
      uVar3 = FUN_401847ec("nternal");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),1000,0);
      FUN_4012105c("logs.\r\n",uVar4,uVar3,0x15c,"sible\r\n");
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    else {
LAB_400f03c8:
      if (((*(int *)(param_1 + 0x28) != 0) || (*(int *)(param_1 + 0x38) != 0)) &&
         (*(int *)(param_1 + 0x44) == 0)) {
        FUN_400f013c(param_1,param_1);
      }
    }
LAB_400f03dd:
    FUN_400f1ea0(*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x41));
    if (*(char *)(param_1 + 0x42) == '\0') {
      uVar7 = 0x78;
      if (((param_2 < 0xe101) && (uVar7 = 1, *(int *)(param_1 + 0x28) != 0)) &&
         (*(char *)(param_1 + 0x40) != '\0')) {
        uVar7 = 0x78;
      }
      FUN_400f1ee0(*(undefined4 *)(param_1 + 0x14),uVar7);
      *(undefined1 *)(param_1 + 0x42) = uVar7;
    }
  }
  func_0x4008fac0(*(undefined4 *)(param_1 + 0x48),0,0,0);
  return;
}

