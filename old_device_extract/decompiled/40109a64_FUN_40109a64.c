// Function : FUN_40109a64
// Address  : 0x40109a64
// Size     : 134 bytes


int FUN_40109a64(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  
  iVar2 = FUN_40108224(param_1);
  if (iVar2 == 0) {
    return -1;
  }
  if (param_4 == 0) {
    piVar3 = (int *)FUN_40173a8c();
    iVar4 = 0xe;
  }
  else {
    iStack_28 = 0;
    memw();
    uStack_3c = param_1;
    uStack_38 = param_2;
    uStack_34 = param_3;
    iStack_30 = param_4;
    uStack_2c = param_5;
    uStack_24 = FUN_4011b0b4();
    memw();
    cVar1 = FUN_40109d74(&DAT_40108874,&uStack_3c);
    if (cVar1 == '\0') {
      FUN_4011ade8(uStack_24);
      iVar4 = iStack_28;
      if (iStack_28 != 0) {
        piVar3 = (int *)FUN_40173a8c();
        *piVar3 = iVar4;
      }
      memw();
      FUN_40108194(iVar2);
      return -(uint)(iVar4 != 0);
    }
    iVar4 = FUN_4011d9e4((int)cVar1);
    if (iVar4 == 0) goto LAB_40109a7e;
    piVar3 = (int *)FUN_40173a8c();
  }
  *piVar3 = iVar4;
LAB_40109a7e:
  memw();
  FUN_40108194(iVar2);
  return -1;
}

