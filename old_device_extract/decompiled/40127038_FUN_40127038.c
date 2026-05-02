// Function : FUN_40127038
// Address  : 0x40127038
// Size     : 312 bytes


int FUN_40127038(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0x65;
  iVar2 = 0;
  do {
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      FUN_40128a7c(iVar2,1);
      return -1;
    }
    if (iVar2 != 0) {
      FUN_40128a7c(iVar2,1);
    }
    FUN_40128a7c(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x3c),1);
    iVar2 = *(int *)(param_1 + 0x48);
    uVar1 = FUN_40126f6c(param_1 + 0x48);
    *(undefined4 *)(iVar2 + 0x3c) = uVar1;
    if (*(int *)(*(int *)(param_1 + 0x48) + 0x3c) == 0) {
      return -1;
    }
    memw();
    iVar2 = FUN_40126f6c(param_1 + 0x48);
    if (iVar2 == 0) {
      return -1;
    }
    iVar3 = *(int *)(param_1 + 0x48);
    if (*(int *)(iVar3 + 0x20) == 0) {
      uVar1 = FUN_40128a18();
      *(undefined4 *)(iVar3 + 0x20) = uVar1;
      if (*(int *)(*(int *)(param_1 + 0x48) + 0x20) == 0) goto LAB_40127114;
    }
    FUN_40128ad8(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x3c),iVar2,
                 *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x20));
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x20);
    FUN_40128af0(uVar1,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x50),uVar1);
    iVar3 = FUN_40128c14(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x20));
  } while ((iVar3 != 0) ||
          (iVar3 = FUN_40128c2c(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x20)), iVar3 != 0));
  iVar4 = *(int *)(param_1 + 0x48);
  if (*(int *)(iVar4 + 0x40) == 0) {
LAB_401270ce:
    iVar3 = *(int *)(param_1 + 0x48);
    iVar4 = 0;
    if (*(int *)(iVar3 + 0x48) == 0) goto LAB_40127116;
    if (*(int *)(iVar3 + 0x24) == 0) {
      uVar1 = FUN_40128a18();
      iVar4 = *(int *)(param_1 + 0x48);
      *(undefined4 *)(iVar3 + 0x24) = uVar1;
      if (*(int *)(iVar4 + 0x24) == 0) {
        memw();
        goto LAB_40127114;
      }
    }
    iVar4 = *(int *)(param_1 + 0x48);
    iVar4 = FUN_40128b08(*(undefined4 *)(iVar4 + 0x38),iVar2,*(undefined4 *)(iVar4 + 0x4c),
                         *(undefined4 *)(iVar4 + 0x24));
    if (-1 < iVar4) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x24);
      iVar4 = FUN_40128b24(uVar1,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x4c),uVar1);
      iVar4 = iVar4 >> 0x1f;
      goto LAB_40127116;
    }
  }
  else if (*(int *)(iVar4 + 0x28) == 0) {
    uVar1 = FUN_40128d44();
    *(undefined4 *)(iVar4 + 0x28) = uVar1;
    if (*(int *)(*(int *)(param_1 + 0x48) + 0x28) != 0) goto LAB_4012712a;
    memw();
  }
  else {
LAB_4012712a:
    iVar4 = *(int *)(param_1 + 0x48);
    iVar4 = FUN_40128e70(*(undefined4 *)(iVar4 + 0x40),*(undefined4 *)(iVar4 + 0x34),iVar2,
                         *(undefined4 *)(iVar4 + 0x28));
    if ((-1 < iVar4) &&
       (iVar4 = FUN_40128ef0(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x40),
                             *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x28)), -1 < iVar4))
    goto LAB_401270ce;
  }
LAB_40127114:
  iVar4 = -1;
LAB_40127116:
  memw();
  FUN_40128a7c(iVar2,1);
  return iVar4;
}

