// Function : FUN_40133e50
// Address  : 0x40133e50
// Size     : 278 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40133e50(int param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [48];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  iVar2 = -0x36;
  if ((param_3 < 0x401) && (iVar2 = -0x38, param_5 < 0x101)) {
    memw();
    (*(code *)&SUB_4008b530)(auStack_54,0,0x30);
    if ((*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x10)) || (*(int *)(param_1 + 0x14) != 0)) {
      iVar2 = FUN_40133db4(param_1,param_4,param_5);
      if (iVar2 != 0) goto LAB_40133ef9;
    }
    else if (param_5 != 0) {
      iVar2 = FUN_401339d4(auStack_54,param_4,param_5);
      if (iVar2 != 0) goto LAB_40133eea;
      iVar2 = FUN_40133bc0(param_1,auStack_54);
      if (iVar2 != 0) goto LAB_40133eea;
    }
    puVar3 = (undefined1 *)0x1;
    goto LAB_40133eac;
  }
LAB_40133ef9:
  do {
    param_3 = uStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return iVar2;
    }
    (*(code *)&SUB_40082ec4)();
    puVar3 = &DAT_3ffc5708;
    do {
      iVar2 = 0x10;
      do {
        iVar2 = iVar2 + -1;
        cVar1 = *(char *)(param_1 + iVar2) + '\x01';
        puVar5 = (undefined1 *)0x0;
        if (cVar1 == '\0') {
          puVar5 = puVar3;
        }
        *(char *)(param_1 + iVar2) = cVar1;
        memw();
        puVar4 = (undefined1 *)0x0;
        if (iVar2 != 0) {
          puVar4 = puVar3;
        }
      } while (((uint)puVar4 & (uint)puVar5) != 0);
      memw();
      iVar2 = FUN_4013cf6c(param_1 + 0x20,puVar3,param_1,auStack_64);
      if (iVar2 != 0) goto LAB_40133eea;
      iVar2 = (param_3 < 0x10) * param_3 + (uint)(param_3 >= 0x10) * 0x10;
      (*(code *)&SUB_4008b3d0)(param_2,auStack_64,iVar2);
      param_2 = param_2 + iVar2;
      param_3 = param_3 - iVar2;
LAB_40133eac:
    } while (param_3 != 0);
    iVar2 = FUN_40133bc0(param_1,auStack_54);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      memw();
    }
LAB_40133eea:
    FUN_4013ae54(auStack_54,0x30);
    FUN_4013ae54(auStack_64,0x10);
  } while( true );
}

