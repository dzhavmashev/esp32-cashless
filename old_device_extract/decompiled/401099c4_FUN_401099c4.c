// Function : FUN_401099c4
// Address  : 0x401099c4
// Size     : 156 bytes


int FUN_401099c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                undefined4 *param_5)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  iVar3 = FUN_40108224(param_1);
  if (iVar3 == 0) {
    return -1;
  }
  if ((param_4 == 0) || ((param_5 == (undefined4 *)0x0) != 0)) {
    piVar4 = (int *)FUN_40173a8c();
    iVar5 = 0xe;
  }
  else {
    uStack_2c = *param_5;
    memw();
    uStack_3c = param_1;
    uStack_38 = param_2;
    uStack_34 = param_3;
    iStack_30 = param_4;
    uStack_28 = (uint)(param_5 == (undefined4 *)0x0);
    uStack_24 = FUN_4011b0b4();
    memw();
    cVar2 = FUN_40109d74(&LAB_4010843c,&uStack_3c);
    if (cVar2 == '\0') {
      FUN_4011ade8(uStack_24);
      uVar1 = uStack_28;
      *param_5 = uStack_2c;
      if (uStack_28 != 0) {
        memw();
        puVar6 = (uint *)FUN_40173a8c();
        *puVar6 = uVar1;
      }
      memw();
      FUN_40108194(iVar3);
      return -(uint)(uVar1 != 0);
    }
    iVar5 = FUN_4011d9e4((int)cVar2);
    if (iVar5 == 0) goto LAB_401099ee;
    piVar4 = (int *)FUN_40173a8c();
  }
  *piVar4 = iVar5;
LAB_401099ee:
  memw();
  FUN_40108194(iVar3);
  return -1;
}

