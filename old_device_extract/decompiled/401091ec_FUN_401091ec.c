// Function : FUN_401091ec
// Address  : 0x401091ec
// Size     : 185 bytes


undefined4 FUN_401091ec(undefined4 param_1,uint param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined2 local_3a;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  char cStack_24;
  
  puVar3 = (undefined4 *)FUN_40108224(param_1);
  if (puVar3 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  bVar1 = *(byte *)(param_2 + 1);
  if (bVar1 == 0) {
    cVar2 = FUN_4011c1fc(*puVar3);
LAB_40109255:
    if (cVar2 == '\0') {
      FUN_40108194(puVar3);
      return 0;
    }
    iVar5 = (int)cVar2;
  }
  else {
    if (bVar1 == 2) {
      if ((*(uint *)*puVar3 & 8) == 0) {
LAB_4010920c:
        if ((((param_3 != 0x10) && (param_3 != 0x1c)) || ((bVar1 & 0xf7) != 2)) ||
           ((param_2 & 3) != 0)) {
          iVar5 = -0x10;
          goto LAB_40109235;
        }
        FUN_40107e98(param_2,&iStack_38,&local_3a);
        if (((cStack_24 == '\x06') && (iStack_38 == 0 && iStack_34 == 0)) && (iStack_30 == -0x10000)
           ) {
          cStack_24 = '\0';
          memw();
          iStack_38 = iStack_2c;
        }
        memw();
        cVar2 = FUN_4011c1cc(*puVar3,&iStack_38,local_3a);
        goto LAB_40109255;
      }
    }
    else if ((bVar1 == 10) && ((*(uint *)*puVar3 & 8) != 0)) goto LAB_4010920c;
    iVar5 = -6;
  }
LAB_40109235:
  iVar5 = FUN_4011d9e4(iVar5);
  if (iVar5 != 0) {
    piVar4 = (int *)FUN_40173a8c();
    *piVar4 = iVar5;
  }
  memw();
  FUN_40108194(puVar3);
  return 0xffffffff;
}

