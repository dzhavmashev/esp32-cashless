// Function : FUN_400d803c
// Address  : 0x400d803c
// Size     : 250 bytes


void FUN_400d803c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_400d6e3c(param_1,0x3ffc401c,500);
  if (iVar1 != 0) {
    FUN_400e7850(*(undefined4 *)(param_1 + 0x18));
  }
  FUN_400e6618(0x3ffc4d58);
  iVar1 = (*(code *)&LAB_4018425a_2)(0x3ffc4d58);
  if (iVar1 != 0) {
    return;
  }
  uVar2 = FUN_400f1a9c();
  if (uVar2 < *(uint *)(param_1 + 0x4c)) {
LAB_400d80e4:
    iVar1 = FUN_400d6e3c(param_1,0x3ffc4014,10000);
    if (iVar1 != 0) {
      FUN_400da35c(*(undefined4 *)(param_1 + 0xc));
      iVar1 = FUN_400da2bc(*(undefined4 *)(param_1 + 0xc));
      if (iVar1 == 0) {
        FUN_400f0780(0x3ffc5490,"NECTING");
        uVar3 = 1;
        goto LAB_400d8097;
      }
    }
    iVar1 = FUN_400d6e3c(param_1,0x3ffc4018,30000);
    if (iVar1 != 0) {
      FUN_400f06a4(0x3ffc5490,"g modem",(uVar2 - *(int *)(param_1 + 0x38)) / 1000,
                   *(undefined4 *)(param_1 + 0x48));
    }
  }
  else {
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
    FUN_400f06a4(0x3ffc5490,"NECTING");
    iVar1 = FUN_400daf88(0x3ffc4218);
    if (iVar1 == 0) {
      if (4 < *(uint *)(param_1 + 0x48)) {
        FUN_400f0780(0x3ffc5490,"ATIONAL");
        FUN_400f1ab4(1000);
        FUN_400efe2c(0x3ffc53f4);
      }
      if ((*(int *)(param_1 + 0x48) == 3) &&
         (iVar1 = (*(code *)&LAB_40183e8b_1)(*(undefined4 *)(param_1 + 8)), iVar1 == 1)) {
        FUN_400f0780(0x3ffc5490,"booting");
        FUN_400e65d0(0x3ffc4d58,10000);
      }
      *(uint *)(param_1 + 0x4c) = uVar2 + 30000;
      goto LAB_400d80e4;
    }
    FUN_400f0780(0x3ffc5490,"pt #%d\n");
    uVar3 = 4;
LAB_400d8097:
    FUN_400d7d34(param_1,uVar3);
  }
  return;
}

